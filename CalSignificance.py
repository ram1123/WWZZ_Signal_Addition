# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-02-12 16:10:59
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-02-16 10:08:14
import ROOT
from ROOT import TFile
ROOT.gROOT.SetBatch(True)
import math 
IfDryRun = False

fileSignal = TFile.Open("GluGluToHHTo2G4Q_node_cHHH1_2016.root","READ")
fileData = TFile.Open("allData.root","READ")
fileGluGluH = TFile.Open("GluGluHToGG_M125.root","READ")
fileVBFh = TFile.Open("VBFHToGG_M125.root","READ")
fileVH = TFile.Open("VHToGG_M125.root","READ")
filettH = TFile.Open("ttHJetToGG_M125.root","READ")


HistSignal = fileSignal.Get("h1_weight")
HistData = fileData.Get("h1_weight")
HistGluGluH = fileGluGluH.Get("h1_weight")
HistVBFh = fileVBFh.Get("h1_weight")
HistVH = fileVH.Get("h1_weight")
HistttH = filettH.Get("h1_weight")

# HistSignal.Print("all")

# print HistSignal.GetNbinsX()
# print HistData.GetNbinsX()
# print HistGluGluH.GetNbinsX()
# print HistVBFh.GetNbinsX()
# print HistVH.GetNbinsX()
# print HistttH.GetNbinsX()

Label=[]
Label.append("Total Event")
Label.append("passPhotonSels")
for x in xrange(0,20):
    Label.append("dipho_MVA>"+str((x+1)*0.05))
for x in xrange(1,20):
    Label.append("dipho_pT>"+str((x*10.)+50.0))
for x in xrange(1,20):
    Label.append("bDis<"+str((x+1)*0.05))

print Label
print len(Label)
for x in xrange(1,HistSignal.GetNbinsX()-3):
    TotalBkg = HistData.GetBinContent(x) + HistGluGluH.GetBinContent(x) +HistVBFh.GetBinContent(x) +HistVH.GetBinContent(x) +HistttH.GetBinContent(x)
    Signal = HistSignal.GetBinContent(x)
    if (math.sqrt(TotalBkg) != 0):
        Significance1 = HistSignal.GetBinContent(x)/(math.sqrt(TotalBkg))
        # e = 2.718281
        Significance2 = math.sqrt(2*(Signal+TotalBkg)*math.log(1+Signal/TotalBkg)-2*Signal)
    else:
        Significance = 0.0
    print x,"\t",Label[x-1],"\t",Significance1,Significance2
    # print x,"\t",Label[x-1],"\t",Significance

