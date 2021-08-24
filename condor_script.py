# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-04-19
# @Last Modified by:   Ram Krishna Sharma
# @Last Modified time: 2021-07-05
import subprocess
import os
import sys

# Year = 2016
# ExtraStringCondorJobFileName = "PetrEFTNode_"

import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-y', '--Year', dest='Year', help='Year to run', default="2016", type=int)
parser.add_argument('-s', '--ExtraString', dest='ExtraString', help='Extra string to be added in the condor file name', default="", type=str)

args = parser.parse_args()

Year = args.Year
ExtraStringCondorJobFileName = args.ExtraString

OutputPath_2016 = "/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2016"
OutputPath_2017 = "/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2017"
# OutputPath_2017 = "/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2017_BScoreBugFix/"
OutputPath_2018 = "/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2018"
OutputPath_2019 = "/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/SignalValidation"

# Get CMSSW directory path and name
cmsswDirPath = os.environ['CMSSW_BASE']
CMSSWRel = cmsswDirPath.split("/")[-1]


paths_2016= [
        # "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_LO_2016_noPdfWeight_Hadded/", # LO_WW_Signal_2016
        # "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHZZ_LO_2016_noPdfWeight_Hadded/", # LO_ZZ_Signal_2016
        # "/eos/user/p/pmandrik/HHWWgg_central/January_2021_Production_v2/2016/Signal/FHWW_LO_2016_noPdfWeight_Hadded/",
        # "/eos/user/p/pmandrik/HHWWgg_central/January_2021_Production_v2/2016/Signal/FHZZ_LO_2016_noPdfWeight_Hadded/",
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_NLO_2016_HaddedNew/", # NLO_WW_Signal_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHZZ_NLO_2016_HaddedNew/", # NLO_ZZ_Signal_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Single_H_2016_Hadded/", # SingleHiggs_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Data_Trees_2016_Hadded_Combined/", # Data_2016
            ]

paths_2018= [
        # "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHWW_LO_2018_Hadded/", # LO_WW_Signal_2018
        # "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHZZ_LO_2018_Hadded/", # LO_ZZ_Signal_2018
        # "/eos/user/p/pmandrik/HHWWgg_central/January_2021_Production_v2/2018/Signal/FHWW_LO_2018_Hadded/",
        # "/eos/user/p/pmandrik/HHWWgg_central/January_2021_Production_v2/2018/Signal/FHZZ_LO_2018_Hadded/",
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHWW_NLO_2018_Hadded/", # NLO_WW_Signal_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHZZ_NLO_2018_Hadded/", # NLO_ZZ_Signal_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Single_H_2018Fixed_Hadded/", # SingleHiggs_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Data_Trees_2018_Hadded_Combined/", # Data_2018
            ]

paths_2017= [
        # "/eos/user/l/lipe/ntuple/2017/Signal/FH_LO_2017_Hadded/",
        # "/eos/user/l/lipe/ntuple/2017/Signal/FHZZ_LO_2017_Hadded_April/",
        # "/eos/user/p/pmandrik/HHWWgg_central/January_2021_Production_v2/2017/Signal/FH_LO_2017_Hadded/",
        # "/eos/user/p/pmandrik/HHWWgg_central/January_2021_Production_v2/2017/Signal/FHZZ_LO_2017_Hadded/",
        "/eos/user/l/lipe/ntuple/2017/Signal/FH_NLO_2017_Hadded_March/",
        "/eos/user/l/lipe/ntuple/2017/Signal/FHZZ_NLO_2017_Hadded_March/",
        "/eos/user/l/lipe/ntuple/2017/Single_H/Single_H_2017_Hadded_3_23/",
        "/eos/user/l/lipe/ntuple/2017/Data/Data_2017_Hadded_Combined/", # Data
        # "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2017/UsedBkgFH", # Backgrounds
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2017/Signal/FHWW_bbgg_NLO_2017"
]

AbeSignalValidation = [
'/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/WWZ_SignalTopology_Checks/2017/SingleElectron_Data_2017_hadded/SingleElectron_Data_2017.root',
'/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/WWZ_SignalTopology_Checks/2017/Zee_hadded/Zee_v14-v1_hadded_MoreVars.root',
'/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/WWZ_SignalTopology_Checks/2017/WWZ_2017_hadded/WWZ.root',
'/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/WWZ_SignalTopology_Checks/2017/All_Backgrounds/',
]

CurrentInputPath = paths_2016
CurrentOutputPath = OutputPath_2016
CondorJobFileName = "CondorJobs_"+str(ExtraStringCondorJobFileName)+str(Year)
if Year==2016:
    CurrentInputPath = paths_2016
    CurrentOutputPath = OutputPath_2016
elif Year==2017:
    CurrentInputPath = paths_2017
    CurrentOutputPath = OutputPath_2017
elif Year==2018:
    CurrentInputPath = paths_2018
    CurrentOutputPath = OutputPath_2018
elif Year==2019:
    CurrentInputPath = AbeSignalValidation
    CurrentOutputPath = OutputPath_2019
else:
    print("Invalid year...")
    exit()

def check_dir(dir):
    if not os.path.exists(dir):
        print('mkdir: ', dir)
        os.makedirs(dir)

check_dir(CurrentOutputPath)
check_dir("output_log")

from os import walk

AllFiles = []
for paths in CurrentInputPath:
    print "===> ",paths
    if paths.endswith('.root'):
        print("paths: {}".format(paths))
        AllFiles.append(paths)
    else:
        for (dirpath, dirnames, filenames) in walk(paths):
            print "dirpath: ",dirpath
            # print "dirnames: ",dirnames
            # print "filenames: ",filenames
            for files in filenames:
                # print os.path.join(dirpath,files)
                AllFiles.append(os.path.join(dirpath,files))

print("AllFiles: {}".format(AllFiles))
# create tarball of present working CMSSW base directory
os.system('rm -f CMSSW*.tgz')
import makeTarFile
makeTarFile.make_tarfile(cmsswDirPath, CMSSWRel+".tgz")
print "copying the "+CMSSWRel+".tgz  file to eos path: "+CurrentOutputPath+"\n"
os.system('cp ' + CMSSWRel+".tgz" + '  '+CurrentOutputPath)

condorSHFile="""#!/bin/bash
echo "Starting job on " `date`
echo "Running on: `uname -a`"
echo "System software: `cat /etc/redhat-release`"
source /cvmfs/cms.cern.ch/cmsset_default.sh
echo "copy cmssw tar file from store area"
cp  %s/CMSSW_10_6_8.tgz  .
tar -xf CMSSW_10_6_8.tgz
rm CMSSW_10_6_8.tgz
cd CMSSW_10_6_8/src/WWZZ_Signal_Addition
rm *.root
scramv1 b ProjectRename
eval `scram runtime -sh`
echo "Input ROOT file name with path: $1"
echo "Output path: $2"
# root -l -b -q ReRunFHJetSelection.C\\(\\"${1}\\",\\"${2}\\"\\)
root -l -b -q ReRunFHJetSelection.C\\(\\"${1}\\"\\)
RootFileName=$(basename "${1}" .root)
echo "Size of root file: ${RootFileName}.root"
ls -ltrh ${RootFileName}.root
hadd ${RootFileName}_hadd.root ${RootFileName}.root
echo "Size of root file: ${RootFileName}_hadd.root"
ls -ltrh ${RootFileName}_hadd.root
hadd ${RootFileName}_hadd2.root ${RootFileName}_hadd.root
echo "Size of root file: ${RootFileName}_hadd2.root"
ls -ltrh ${RootFileName}_hadd2.root
mv ${RootFileName}_hadd2.root ${2}/
"""

with open("%s.sh"%CondorJobFileName,"w") as args:
    args.write(condorSHFile%(CurrentOutputPath))

# longlunch
# espresso
# workday
condorJDLFile_header="""+JobFlavour   = "workday"
Executable = %s.sh
Universe = vanilla
Notification = ERROR
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
x509userproxy = $ENV(X509_USER_PROXY)
"""

condorJDLFile_loop="""Output = output_log/outputLog_$(ClusterId)_$(Process).stdout
Error  = output_log/outputLog_$(ClusterId)_$(Process).stdout
Log  = output_log/outputLog_$(ClusterId)_$(Process).log
Arguments = %s %s
Queue
"""
with open("%s.jdl"%CondorJobFileName,"w") as args:
    args.write(condorJDLFile_header%CondorJobFileName)
    for files in AllFiles:
        args.write(condorJDLFile_loop%(files,CurrentOutputPath))

print('For running condor jobs do following:')
print('1. set up proxy:')
print('\tvoms-proxy-init --voms cms --valid 168:00')
print('\tcp /tmp/x509up_<PROXY> ~/')
print('\texport X509_USER_PROXY=~/x509up_<PROXY>')
print('2. Submit the condor jobs:')
print('\tcondor_submit %s.jdl'%CondorJobFileName)
