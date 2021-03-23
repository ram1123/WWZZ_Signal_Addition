# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-02-09 22:20:32
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-02-09 23:04:58

import os
import sys
import argparse
from os import listdir
from os.path import isfile, join
import time
import datetime
import getpass

# store starting time
begin = time.time()

parser = argparse.ArgumentParser(description="""
                    This script is going check root file and remove the duplicate trees.
                    """)
parser.add_argument("--InFile",
                    default="",
                    help="Name of input root file",
                    required=False)
parser.add_argument("--InPath",
                    default="",
                    required=True,
                    help="Path where input files are present")
parser.add_argument("--OutPath",
                    default="",
                    help="""
                        Path where output file will be stored.
                        In case no output path specified it creates a directory
                        named "hadd" in in the input file path and sends hadd-ed
                        file there.
                        """)
parser.add_argument("--IsMany",
                    default=1,
                    type=int,
                    choices=[0,1],
                    help="Need to hadd only one file or all files in the input directory?")
parser.add_argument("--IsData",
                    default=0,
                    type=int,
                    choices=[0,1],
                    required=True,
                    help="If running over data make this True, else False")
args = parser.parse_args()

"""
[ISSUE] If we import ROOT before argparse then ROOT loads its own help message instead of the
python message that  we would like to print. So, always load ROOT after the argparse.
"""
import ROOT
from ROOT import TFile, TDirectory, TTree, gDirectory

ROOT.gROOT.SetBatch(True)

IfDryRun = True

if args.IsData:
    print "Copying the MC c++ code to Data code., args.IsData: ",args.IsData,type(args.IsData)
    copy_command = 'cp parallel_ReRunFHJetSelection.C parallel_ReRunFHJetSelection_Data.C'
    sed_command1 = "sed 's/parallel_ReRunFHJetSelection/parallel_ReRunFHJetSelection_Data/' parallel_ReRunFHJetSelection.C > parallel_ReRunFHJetSelection_Data.C"
    sed_command2 = "sed -i 's/flashgg_MC/flashgg_Data/' parallel_ReRunFHJetSelection_Data.C"
    os.system(sed_command1)
    os.system(sed_command2)

InputRootFile = args.InFile
if InputRootFile == "":
    args.IsMany = True
InputRootFilePath = args.InPath
if args.OutPath == "":
    # OutputRootFilePath = "/tmp/rasharma"
    OutputRootFilePath = (InputRootFilePath+os.sep+"FH_JetSelUpdated").replace("//","/")
    if not IfDryRun: os.system("mkdir "+OutputRootFilePath)
else:
    OutputRootFilePath = args.OutPath
    os.system("mkdir -p "+OutputRootFilePath)


print "Input Path: ",InputRootFilePath
print "Input Root file: ",InputRootFile
print "OutputRootFilePath: ",OutputRootFilePath

def getallTrees(d, basepath="/", SearchString="Tag_1", verbose=False):
    "Recurse through a ROOT file/dir and generate (path, obj) pairs"
    for key in d.GetListOfKeys():
        kname = key.GetName()
        obj = key.ReadObj();
        if obj.IsA().InheritsFrom(TDirectory.Class()):
            print kname
            d.cd(key.GetName());
            subdir = gDirectory;
            for i in getallTrees(subdir, basepath+kname+"/", SearchString):
                yield i
        elif (obj.IsA().InheritsFrom(TTree.Class()) and (kname.find(SearchString) != -1)):
            yield basepath+kname

import multiprocessing
from multiprocessing import Pool, TimeoutError

InputFileWithPath = InputRootFilePath+os.sep+InputRootFile

TEMP_OutputRootFilePath = "/tmp/"+getpass.getuser()+"/RootFiles_"+datetime.datetime.now().strftime('%Y_%m_%d_%Hh%Mm%Ss')
os.system("mkdir -p "+TEMP_OutputRootFilePath)

def GetEntries(file, TreeName):
    Tfile = TFile.Open(file)
    treeIn = Tfile.Get(TreeName)
    return treeIn.GetEntries()

def function(x):
    # print "\n\n"
    created = multiprocessing.Process()
    current = multiprocessing.current_process()
    # print 'running:', current.name, current._identity
    # print 'created:', created.name, created._identity
    # print 'created:', created._identity[1]
    TEMP_OutputRootFileName = "TempRootFile_"+str(created._identity[0])+"_"+str(created._identity[1])+".root"
    DirectoryName = str(x.split("/")[1]+"/"+x.split("/")[2])
    TreeName = str(x.split("/")[3])
    if args.IsData:
        command = 'root -l -b -q "parallel_ReRunFHJetSelection_Data.C(true, \\"'+InputFileWithPath+'\\",\\"'+TEMP_OutputRootFilePath+'\\",\\"'+DirectoryName+'\\",\\"'+TreeName+'\\",\\"'+TEMP_OutputRootFileName+'\\")"'
    else:
        command = 'root -l -b -q      "ReRunFHJetSelection_TTreeReader_1_v1.C(\\"'+InputFileWithPath+'\\",\\"'+TEMP_OutputRootFilePath+'\\",\\"'+DirectoryName+'\\",\\"'+TreeName+'\\",\\"'+TEMP_OutputRootFileName+'\\")"'
    print command
    os.system(command)

    entries = GetEntries(str(TEMP_OutputRootFilePath)+"/"+str(TEMP_OutputRootFileName), TreeName)

    print "ENtries: ",entries,"\t",type(entries)

    # return entries
    # return str(TreeName), int(GetEntries(TEMP_OutputRootFilePath+os.sys+TEMP_OutputRootFileName, TreeName))
    # return TEMP_OutputRootFilePath+os.sys+TEMP_OutputRootFileName, TreeName

# Reference: https://stackoverflow.com/a/10192611/2302094

if __name__ == '__main__':
    pool = Pool(processes=int((multiprocessing.cpu_count())))
    # pool = Pool(processes=int((multiprocessing.cpu_count())/2))
    # pool = Pool(processes=1)

    print "File ",InputFileWithPath
    file = TFile.Open(InputFileWithPath)

    rootobjects_raw =  list(getallTrees(file))

    OnlyTreesNames = [item for item in rootobjects_raw]

    print "Number of trees: ",len(OnlyTreesNames)
    print "Number of CPUs: ",multiprocessing.cpu_count()

    # EntriesDetails = pool.map(function, OnlyTreesNames)
    pool.map(function, OnlyTreesNames)

    # from prettytable import PrettyTable

    # t = PrettyTable(['Entries', 'Tree-Name'])
    # for entries in EntriesDetails:
        # t.add_row([entries[1],entries[0].replace("/tagsDumper/trees/","")])
    # print(t)

    # total time taken
    print "Total runtime of the python program is ",time.time() - begin
    hadd_command = 'hadd -f '+OutputRootFilePath+os.sep+InputFileWithPath.split('/')[-1]+' '+TEMP_OutputRootFilePath+"/*.root"
    os.system(hadd_command)
    print "Total runtime of the python program is ",time.time() - begin
