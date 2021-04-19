# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-04-19
# @Last Modified by:   Ram Krishna Sharma
# @Last Modified time: 2021-04-19
import subprocess
import os
import sys


OutputPath_2016 = "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2016/"

# Get CMSSW directory path and name
cmsswDirPath = os.environ['CMSSW_BASE']
CMSSWRel = cmsswDirPath.split("/")[-1]


paths_2016= [
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_LO_2016_noPdfWeight_Hadded/", # LO_WW_Signal_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHZZ_LO_2016_noPdfWeight_Hadded/", # LO_ZZ_Signal_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_NLO_2016_HaddedNew/", # NLO_WW_Signal_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHZZ_NLO_2016_HaddedNew/", # NLO_ZZ_Signal_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Single_H_2016_Hadded/", # SingleHiggs_2016
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Data_Trees_2016_Hadded_Combined/", # Data_2016
            ]

paths_2018= [
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHWW_LO_2018_Hadded/", # LO_WW_Signal_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHZZ_LO_2018_Hadded/", # LO_ZZ_Signal_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHWW_NLO_2018_Hadded/", # NLO_WW_Signal_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Signal/FHZZ_NLO_2018_Hadded/", # NLO_ZZ_Signal_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Single_H_2018Fixed_Hadded/", # SingleHiggs_2018
        "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2018/Data_Trees_2018_Hadded_Combined/", # Data_2018
            ]

paths_2017= [
        "/eos/user/l/lipe/ntuple/2017/Signal/FH_LO_2017_Hadded/",
        "/eos/user/l/lipe/ntuple/2017/Signal/FHZZ_LO_2017_Hadded_April/",
        "/eos/user/l/lipe/ntuple/2017/Signal/FH_NLO_2017_Hadded_March/",
        "/eos/user/l/lipe/ntuple/2017/Signal/FHZZ_NLO_2017_Hadded_March/",
        "/eos/user/l/lipe/ntuple/2017/Single_H/Single_H_2017_Hadded_3_23/",
        "/eos/user/l/lipe/ntuple/2017/Data/Data_2017_Hadded_Combined/"
]
from os import walk

AllFiles = []
for paths in paths_2016:
    print "===> ",paths
    for (dirpath, dirnames, filenames) in walk(paths):
        # print "dirpath: ",dirpath
        # print "dirnames: ",dirnames
        # print "filenames: ",filenames
        for files in filenames:
            # print os.path.join(dirpath,files)
            AllFiles.append(os.path.join(dirpath,files))

# create tarball of present working CMSSW base directory
os.system('rm -f CMSSW*.tgz')
import makeTarFile
makeTarFile.make_tarfile(cmsswDirPath, CMSSWRel+".tgz")
print "copying the "+CMSSWRel+".tgz  file to eos path: \n"
os.system('cp ' + CMSSWRel+".tgz" + '  '+OutputPath_2016)

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
root -l -b -q ReRunFHJetSelection.C\\(\\"$1\\",\\"$2\\"\\)
"""

with open("condor_sh_file.sh","w") as args:
    args.write(condorSHFile%(OutputPath_2016))

condorJDLFile_header="""+JobFlavour   = "longlunch"
Executable = condor_sh_file.sh
Universe = vanilla
Notification = ERROR
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
x509userproxy = $ENV(X509_USER_PROXY)
"""

condorJDLFile_loop="""Output = outputLog_$(ClusterId)_$(Process).stdout
Error  = outputLog_$(ClusterId)_$(Process).stdout
Log  = outputLog_$(ClusterId)_$(Process).log
Arguments = %s %s
Queue
"""
with open("condor_jdl_file.jdl","w") as args:
    args.write(condorJDLFile_header)
    for files in AllFiles:
        args.write(condorJDLFile_loop%(files,OutputPath_2016))

print('For running condor jobs do following:')
print('1. set up proxy:')
print('\tvoms-proxy-init --voms cms --valid 168:00')
print('\tcp /tmp/x509up_<PROXY> ~/')
print('\texport X509_USER_PROXY=~/x509up_<PROXY>')
print('2. Submit the condor jobs:')
print('\tcondor_submit condor_jdl_file.jdl')