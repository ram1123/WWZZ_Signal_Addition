# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-02-03 12:49:29
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-02-04 00:55:57

import os
import sys
import argparse
from os import listdir
from os.path import isfile, join

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
                    default=False,
                    help="Need to hadd only one file or all files in the input directory?")
args = parser.parse_args()

"""
[ISSUE] If we import ROOT before argparse then ROOT loads its own help message instead of the
python message that  we would like to print. So, always load ROOT after the argparse.
"""
from ROOT import TFile

IfDryRun = False


InputRootFile = args.InFile
if InputRootFile == "":
    args.IsMany = True
InputRootFilePath = args.InPath
if args.OutPath == "":
    # OutputRootFilePath = "/tmp/rasharma"
    OutputRootFilePath = (InputRootFilePath+os.sep+"hadd").replace("//","/")
    if not IfDryRun: os.system("mkdir "+OutputRootFilePath)
else:
    OutputRootFilePath = args.OutPath


print "Input Path: ",InputRootFilePath
print "Input Root file: ",InputRootFile
print "OutputRootFilePath: ",OutputRootFilePath

if args.IsMany:
    onlyfiles = [f for f in listdir(InputRootFilePath) if isfile(join(InputRootFilePath, f))]
else:
    onlyfiles = [InputRootFile]


def getallTrees(d, basepath="/", verbose=False):
    "Recurse through a ROOT file/dir and generate (path, obj) pairs"
    for key in d.GetListOfKeys():
        kname = key.GetName()
        if key.IsFolder() and (not ("Tag_1" in kname)):
            for i in getallTrees(d.Get(kname), basepath+kname+"/"):
                yield i
        else:
            yield basepath+kname, d.Get(kname)


print "onlyfiles:"
print onlyfiles
for count, InputRootFile in enumerate(onlyfiles):
    print "\n\n"
    contains_duplicates = True
    InputFileWithPath = InputRootFilePath+os.sep+InputRootFile
    print "File (",str(count)+"/"+str(len(onlyfiles)),"): ",InputFileWithPath
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
            move_command = "mv "+InputFileWithPath+ " " + OutputRootFilePath+os.sep
            print "Running command:\n\t",move_command
            if not IfDryRun: os.system(move_command)
        InputFileWithPath = OutputRootFileWithPath
        if IfDryRun: contains_duplicates = False
        print "contains_duplicates: ",contains_duplicates
