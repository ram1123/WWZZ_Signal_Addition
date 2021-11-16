# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Author Email: ram.krishna.sharma@cern.ch
# @Date:   2021-08-03
# @Last Modified by:   Ram Krishna Sharma
# @Last Modified time: 2021-08-03
import uproot
import os
import sys

FileList = [
# '/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_Evaluate_July02_Model5_E700_LR10em5_B100_ELU_DR0p1_Nadam_CW_NoSHv2_DefaultVar/2016/CategorizeRootFile/GluGluToHHTo2G4Q_node_cHHH1_2017.root',
# '/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_Evaluate_July02_Model5_E700_LR10em5_B100_ELU_DR0p1_Nadam_CW_NoSHv2_DefaultVar/2016/CategorizeRootFile/GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_2017.root',
'/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_Evaluate_July02_Model5_E700_LR10em5_B100_ELU_DR0p1_Nadam_CW_NoSHv2_DefaultVar/2016/CategorizeRootFile/GluGluToHHTo2B2G_node_cHHH1_2017.root'
# '/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_Evaluate_July02_Model5_E700_LR10em5_B100_ELU_DR0p1_Nadam_CW_NoSHv2_DefaultVar/2016/CategorizeRootFile/Data_2017.root'
]

for count,file in enumerate(FileList):
    print("\n================================")
    print(count,file)
    path, filename = os.path.split(file)
    # print("filename:",filename)
    # print("getPath:",path)
    RootFile = uproot.open(file)
    # print(RootFile.keys())
    key = RootFile.keys()
    TreeName = key[0].split(';')[0]

    tree = RootFile[str(TreeName)]
    arrays = tree.arrays(['run','event','lumi'],"(New_SumTwoMaxBScore>0.5) & (New_TwoLeadJets_mass<100.0) & (evalDNN>0.983421052632)", library="pd")
    # print(arrays)
    arrays.to_csv(filename.replace('.root','_MaxSumBScore0p5_Mjj100_Cat1.log'))