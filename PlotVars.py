# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-03-25 01:08:04
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-03-25 18:40:49

import ROOT
ROOT.gROOT.SetBatch(True)

class HistogramFile(object):

    def __init__(self, filename, treeName):
        self.filename = filename
        self.treeName = treeName

    def __enter__(self):
        self.file = ROOT.TFile.Open(self.filename, 'read')
        if self.treeName != "": self.tree = self.file.Get("tagsDumper/trees/"+self.treeName)
        return self

    def __exit__(self, exception_type, exception_value, traceback):
        self.file.Close()

    def get_histogram(self, name):
        """Return the histogram identified by name from the file.
        """
        # The TFile::Get() method returns a pointer to an object stored in a ROOT file.
        hist = self.file.Get(name)
        if hist:
            return hist
        else:
            raise RuntimeError('Unable to retrieve histogram named {0} from {1}'.format(name, self.filename))
    def get_histogram_fromTree(self, name, nbin, minX, maxX, title = ""):
        """Return the histogram identified by name from the file.
        """
        # The TFile::Get() method returns a pointer to an object stored in a ROOT file.
        # tree = self.file.Get(tree)
        if title == "":
            hist = ROOT.TH1F("hist",name,nbin, minX, maxX)
        else:
            hist = ROOT.TH1F("hist",title,nbin, minX, maxX)
        # hist = tree.Draw(name)
        self.tree.Draw(name+" >> hist","weight*((Leading_Photon_pt/CMS_hgg_mass>0.35)*(Subleading_Photon_pt/CMS_hgg_mass>0.25)*(passPhotonSels==1)*(CMS_hgg_mass<115 \
|| CMS_hgg_mass>135)*(Leading_Photon_MVA>-0.7)*(Subleading_Photon_MVA>-0.7))")
        # print tree
        # print tree.GetEntries()
        # if hist:
        return hist
        # else:
            # raise RuntimeError('Unable to retrieve histogram named {0} from {1}'.format(name, self.filename))  

# import contextlib2

# @contextmanager
# def canvas(name, filename, idunno, width, height):
#     canvas = ROOT.TCanvas(name, idunno, width, height)
#     yield canvas
#     canvas.SaveAs(filename)          


AdditionalString = "Photon_MVA_gt0p7"



RootFileDict = {
    "Signal/GluGluToHHTo2G4Q_node_cHHH1_2017": "GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1",

    "Backgrounds/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf": "GJet_Pt_40toInf_DoubleEMEnriched_MGG_80toInf_TuneCP5_13TeV_Pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/GJet_Pt-20to40_DoubleEMEnriched_MGG-80toInf_TuneCP5_13TeV": "GJet_Pt_20to40_DoubleEMEnriched_MGG_80toInf_TuneCP5_13TeV_Pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/GJet_Pt-20toInf_DoubleEMEnriched_MGG-40to80_TuneCP5_13TeV": "GJet_Pt_20toInf_DoubleEMEnriched_MGG_40to80_TuneCP5_13TeV_Pythia8_13TeV_HHWWggTag_1",

    "Backgrounds/VHToGG_M125_13TeV": "wzh_125_13TeV_HHWWggTag_1",
    "Backgrounds/GluGluHToGG_M125_TuneCP5_13TeV": "ggh_125_13TeV_HHWWggTag_1",
    "Backgrounds/VBFHToGG_M125_13TeV": "vbf_125_13TeV_HHWWggTag_1",
    "Backgrounds/ttHJetToGG_M125_13TeV": "tth_125_13TeV_HHWWggTag_1",
    
    "Backgrounds/TTGJets_TuneCP5_13TeV": "TTGJets_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/TTGG_0Jets_TuneCP5_13TeV": "TTGG_0Jets_TuneCP5_13TeV_amcatnlo_madspin_pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/TTJets_TuneCP5_13TeV": "TTJets_TuneCP5_13TeV_amcatnloFXFX_pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/TTToHadronic_TuneCP5_13TeV-powheg-pythia8": "TTToHadronic_TuneCP5_13TeV_powheg_pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/ttWJets_TuneCP5_13TeV_madgraphMLM_pythia8": "ttWJets_TuneCP5_13TeV_madgraphMLM_pythia8_13TeV_HHWWggTag_1",

    "Backgrounds/DYJetsToLL_M-50_TuneCP5_13TeV": "DYJetsToLL_M_50_TuneCP5_13TeV_amcatnloFXFX_pythia8_13TeV_HHWWggTag_1",

    "Backgrounds/DiPhotonJetsBox_MGG-80toInf_13TeV": "DiPhotonJetsBox_MGG_80toInf_13TeV_Sherpa_13TeV_HHWWggTag_1",
    "Backgrounds/DiPhotonJetsBox_M40_80": "DiPhotonJetsBox_M40_80_Sherpa_13TeV_HHWWggTag_1",

    "Backgrounds/WGGJets_TuneCP5_13TeV_madgraphMLM_pythia8": "WGGJets_TuneCP5_13TeV_madgraphMLM_pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/WGJJToLNu_EWK_QCD_TuneCP5_13TeV-madgraph-pythia8": "WGJJToLNu_EWK_QCD_TuneCP5_13TeV_madgraph_pythia8_13TeV_HHWWggTag_1",
    "Backgrounds/WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8": "WWTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8_13TeV_HHWWggTag_1"
}

for RootFileName in RootFileDict:
    print ("="*51,"\n")
    TreeName = RootFileDict[RootFileName]
    print ("RootFileName: ",RootFileName)
    print ("TreeName: ",TreeName)

    with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/"+RootFileName+'.root',TreeName) as f:
        canvas = ROOT.TCanvas('canvas', '', 500, 500)
        hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
        hist.Draw()
        canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.png')  
        canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

        hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
        hist.Draw()
        canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.png')  
        canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  


# import ROOT as root
# import numpy as np

# f = root.TFile("GluGluToHHTo2G4Q_node_cHHH1_2017.root")
# myTree = f.Get("tagsDumper/trees/")

# # myTree.Print()

# myTree.Draw("New_DR_HH")



