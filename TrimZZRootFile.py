# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-01-29 01:24:33
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-01-29 02:56:28

from ROOT import TFile
import os

InputRootFile = "GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_2016.root"

InputRootFilePath = "/afs/cern.ch/user/r/rasharma/work/public/doubleHiggs/ntuples"
OutputRootFilePath = "/tmp/rasharma"

IfDryRun = False

file = TFile.Open(InputRootFilePath+os.sep+InputRootFile)

def getallTrees(d, basepath="/", verbose=False):
    "Recurse through a ROOT file/dir and generate (path, obj) pairs"
    for key in d.GetListOfKeys():
        kname = key.GetName()
        if key.IsFolder() and (not ("Tag_1" in kname)):
            for i in getallTrees(d.Get(kname), basepath+kname+"/"):
                yield i
        else:
            yield basepath+kname, d.Get(kname)


rootobjects_raw =  list(getallTrees(file))

OnlyTreesNames = [item[0] for item in rootobjects_raw]

NoDuplicates_TreesNames = set(OnlyTreesNames)

contains_duplicates = len(OnlyTreesNames) != len(NoDuplicates_TreesNames)

if contains_duplicates:
    print("Found duplicate trees. So, running the hadd command to remove duplicate trees.")
    hadd_command = "hadd "+OutputRootFilePath+os.sep+"RemovedDuplicates_"+InputRootFile+" "+InputRootFilePath+os.sep+InputRootFile
    print("===> "+hadd_command)
    if not IfDryRun: os.system(hadd_command)
    InputRootFilePath = OutputRootFilePath
    InputRootFile = "RemovedDuplicates_"+InputRootFile
print(" ")

count = 1
for x in NoDuplicates_TreesNames:
    print("\nReading tree {}/{}: {}".format(count,len(NoDuplicates_TreesNames),x))
    command = "rooteventselector -s \"rand()/2147483647 <= 0.12269939\" "+InputRootFilePath+os.sep+InputRootFile+":"+x+ "   "+OutputRootFilePath+os.sep+"/Trimmed_"+str(count)+".root"
    print("===> "+command)
    if not IfDryRun: os.system(command)
    count+=1

hadd_command = "hadd "+OutputRootFilePath+os.sep+InputRootFile.replace(".root","_Trimmed.root")+"  "+OutputRootFilePath+os.sep+"/Trimmed_*.root"
print("===> "+hadd_command)
if not IfDryRun: os.system(hadd_command)