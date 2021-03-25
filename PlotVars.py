# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-03-25 01:08:04
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-03-25 18:08:43

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
|| CMS_hgg_mass>135)*(Leading_Photon_MVA<-0.7)*(Subleading_Photon_MVA<-0.7))")
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


RootFileName = "GluGluToHHTo2G4Q_node_cHHH1_2017"
TreeName = "GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1"

AdditionalString = "Photon_MVA_lt0p7"

# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Signal/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.png')  
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.png')  
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = f.get_histogram_fromTree('weight',25,-1,1,"weight")
    # hist.Draw()
    # canvas.SaveAs(RootFileName+'_'+AdditionalString+'_weight.png')      
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    

RootFileName = "DiPhotonJetsBox_MGG-80toInf_13TeV"
TreeName = "DiPhotonJetsBox_MGG_80toInf_13TeV_Sherpa_13TeV_HHWWggTag_1"



# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()       
    

RootFileName = "TTGG_0Jets_TuneCP5_13TeV"
TreeName = "TTGG_0Jets_TuneCP5_13TeV_amcatnlo_madspin_pythia8_13TeV_HHWWggTag_1"


# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    
    # 
RootFileName = "TTGJets_TuneCP5_13TeV"
TreeName = "TTGJets_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8_13TeV_HHWWggTag_1"


# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    

RootFileName = "ttHJetToGG_M125_13TeV"
TreeName = "tth_125_13TeV_HHWWggTag_1"


# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    


RootFileName = "VBFHToGG_M125_13TeV"
TreeName = "vbf_125_13TeV_HHWWggTag_1"


# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    


RootFileName = "GluGluHToGG_M125_TuneCP5_13TeV"
TreeName = "ggh_125_13TeV_HHWWggTag_1"


# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    


RootFileName = "VHToGG_M125_13TeV"
TreeName = "wzh_125_13TeV_HHWWggTag_1"    


# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()    

RootFileName = "GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf"
TreeName = "GJet_Pt_40toInf_DoubleEMEnriched_MGG_80toInf_TuneCP5_13TeV_Pythia8_13TeV_HHWWggTag_1"

# with HistogramFile('GluGluToHHTo2G4Q_node_cHHH1_2017.root','tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1') as f,canvas('canvas', 'test.pdf', '', 500, 500):
with HistogramFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/"+RootFileName+'.root',TreeName) as f:
    canvas = ROOT.TCanvas('canvas', '', 500, 500)
    hist = f.get_histogram_fromTree('PhotonID_min',25,-1,1,"PhotonID_min")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_min.root')  

    hist = f.get_histogram_fromTree('PhotonID_max',25,-1,1,"PhotonID_max")
    hist.Draw()
    canvas.SaveAs(RootFileName+'_'+AdditionalString+'_PhotonID_max.root')  
    # hist = dataset.get_histogram('electron_momentum')
    # hist.Draw()   



# import ROOT as root
# import numpy as np

# f = root.TFile("GluGluToHHTo2G4Q_node_cHHH1_2017.root")
# myTree = f.Get("tagsDumper/trees/")

# # myTree.Print()

# myTree.Draw("New_DR_HH")



