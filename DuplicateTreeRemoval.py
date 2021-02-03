# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-02-03 12:49:29
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-02-03 14:14:32

# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-01-29 01:24:33
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-01-29 02:56:28

from ROOT import TFile
import os
import argparse

parser = argparse.ArgumentParser(description="""
    This script is going check root file and remove the duplicate trees.
    """)
parser.add_argument("--InFile", default="", help="Name of Employee")
parser.add_argument("--InPath", default="", help="Job Title of Employee")
parser.add_argument("--OutPath", default="", help="Address of Employee")

args = parser.parse_args()

if args.InFile == "":
    InputRootFile = "GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_2016.root"
else:
    InputRootFile = args.InFile

if args.InPath == "":
    InputRootFilePath = "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/ReRunFHJetSelection_January_2021_Production/AllBVetoJets/BTagFix_2016"
else:
    InputRootFilePath = args.InPath

if args.OutPath == "":
    # OutputRootFilePath = "/tmp/rasharma"
    OutputRootFilePath = InputRootFilePath+os.sep+"hadd"
    os.system("mkdir "+OutputRootFilePath)
else:
    OutputRootFilePath = args.OutPath

IfDryRun = False

print "Input Root file: ",InputRootFilePath,InputRootFile
print "OutputRootFilePath: ",OutputRootFilePath


def getallTrees(d, basepath="/", verbose=False):
    "Recurse through a ROOT file/dir and generate (path, obj) pairs"
    for key in d.GetListOfKeys():
        kname = key.GetName()
        if key.IsFolder() and (not ("Tag_1" in kname)):
            for i in getallTrees(d.Get(kname), basepath+kname+"/"):
                yield i
        else:
            yield basepath+kname, d.Get(kname)

contains_duplicates = True

InputFileWithPath = InputRootFilePath+os.sep+InputRootFile

while contains_duplicates:
    file = TFile.Open(InputFileWithPath)
    rootobjects_raw =  list(getallTrees(file))

    OnlyTreesNames = [item[0] for item in rootobjects_raw]

    NoDuplicates_TreesNames = set(OnlyTreesNames)

    contains_duplicates = len(OnlyTreesNames) != len(NoDuplicates_TreesNames)

    # print("contains_duplicates: ",contains_duplicates)
    OutputRootFileWithPath = ""
    if contains_duplicates:
        print("Found duplicate trees. So, running the hadd command to remove duplicate trees.")
        OutputRootFileWithPath = "/tmp/rasharma"+os.sep+InputRootFile
        hadd_command = "hadd -f "+OutputRootFileWithPath+" "+InputFileWithPath
        print("===> "+hadd_command)
        if not IfDryRun: os.system(hadd_command)
    else:
        print("No duplicate trees found...")
        contains_duplicates = False
        os.system("mv "+InputFileWithPath+ " " + OutputRootFilePath+os.sep)
    InputFileWithPath = OutputRootFileWithPath
