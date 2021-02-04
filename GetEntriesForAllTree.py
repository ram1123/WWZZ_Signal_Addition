# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-02-04 10:01:07
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-02-04 15:16:44

import os
import sys
import argparse
from os import listdir
from os.path import isfile, join
import time
import datetime
import getpass
import multiprocessing
from multiprocessing import Pool, TimeoutError

# store starting time
begin = time.time()

parser = argparse.ArgumentParser(description="""
                    This script is going check root file and remove the duplicate trees.
                    """)
parser.add_argument("--InFile",
                    default="",
                    help="Name of input root file",
                    required=False)
args = parser.parse_args()

"""
[ISSUE] If we import ROOT before argparse then ROOT loads its own help message instead of the
python message that  we would like to print. So, always load ROOT after the argparse.
"""
import ROOT
from ROOT import TFile, TDirectory, TTree, gDirectory

ROOT.gROOT.SetBatch(True)

IfDryRun = True

InputFileWithPath = args.InFile

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

def function(TreeName):
    file = TFile.Open(InputFileWithPath)
    treeIn = file.Get(TreeName)
    return TreeName,treeIn.GetEntries()

# Reference: https://stackoverflow.com/a/10192611/2302094
if __name__ == '__main__':
    pool = Pool(processes=multiprocessing.cpu_count())

    file = TFile.Open(InputFileWithPath)
    rootobjects_raw =  list(getallTrees(file,"/","Tag_1"))
    OnlyTreesNames = [item for item in rootobjects_raw]

    print "Number of trees: ",len(OnlyTreesNames)
    print "Number of CPUs: ",multiprocessing.cpu_count()

    EntriesDetails = pool.map(function, OnlyTreesNames)

    from prettytable import PrettyTable

    t = PrettyTable(['Entries', 'Tree-Name'])
    for entries in EntriesDetails:
        t.add_row([entries[1],entries[0].replace("/tagsDumper/trees/","")])
    print(t)

    print "Total runtime of the python program is ",time.time() - begin

