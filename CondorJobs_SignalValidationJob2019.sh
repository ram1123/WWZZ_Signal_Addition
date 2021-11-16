#!/bin/bash
echo "Starting job on " `date`
echo "Running on: `uname -a`"
echo "System software: `cat /etc/redhat-release`"
source /cvmfs/cms.cern.ch/cmsset_default.sh
echo "copy cmssw tar file from store area"
cp  /eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/SignalValidation/CMSSW_10_6_8.tgz  .
tar -xf CMSSW_10_6_8.tgz
rm CMSSW_10_6_8.tgz
cd CMSSW_10_6_8/src/WWZZ_Signal_Addition
rm *.root
scramv1 b ProjectRename
eval `scram runtime -sh`
echo "Input ROOT file name with path: $1"
echo "Output path: $2"
# root -l -b -q ReRunFHJetSelection.C\(\"${1}\",\"${2}\"\)
root -l -b -q ReRunFHJetSelection.C\(\"${1}\"\)
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
