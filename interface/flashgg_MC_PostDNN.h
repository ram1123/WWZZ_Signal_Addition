//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jun 24 09:44:34 2021 by ROOT version 6.14/09
// from TTree GluGluToHHTo2B2G_node_cHHH1_13TeV_HHWWggTag_1/GluGluToHHTo2B2G_node_cHHH1_13TeV_HHWWggTag_1
// found on file: /eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNNEval_15May_WithoutSH/2017/GluGluToHHTo2B2G_node_cHHH1_2017.root
//////////////////////////////////////////////////////////

#ifndef flashgg_MC_PostDNN_h
#define flashgg_MC_PostDNN_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class flashgg_MC_PostDNN {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           candidate_id;
   Float_t         weight;
   Float_t         CMS_hgg_mass;
   Float_t         sigmaMoM_decorr;
   Float_t         dZ;
   Float_t         centralObjectWeight;
   Float_t         LooseMvaSFUp01sigma;
   Float_t         PreselSFUp01sigma;
   Float_t         electronVetoSFUp01sigma;
   Float_t         TriggerWeightUp01sigma;
   Float_t         FracRVWeightUp01sigma;
   Float_t         MuonIDWeightUp01sigma;
   Float_t         ElectronIDWeightUp01sigma;
   Float_t         ElectronRecoWeightUp01sigma;
   Float_t         MuonIsoWeightUp01sigma;
   Float_t         JetBTagCutWeightUp01sigma;
   Float_t         JetBTagReshapeWeightUp01sigma;
   Float_t         prefireWeightUp01sigma;
   Float_t         LooseMvaSFDown01sigma;
   Float_t         PreselSFDown01sigma;
   Float_t         electronVetoSFDown01sigma;
   Float_t         TriggerWeightDown01sigma;
   Float_t         FracRVWeightDown01sigma;
   Float_t         MuonIDWeightDown01sigma;
   Float_t         ElectronIDWeightDown01sigma;
   Float_t         ElectronRecoWeightDown01sigma;
   Float_t         MuonIsoWeightDown01sigma;
   Float_t         JetBTagCutWeightDown01sigma;
   Float_t         JetBTagReshapeWeightDown01sigma;
   Float_t         prefireWeightDown01sigma;
   Float_t         passPS;
   Float_t         passPhotonSels;
   Float_t         mW1_40To160;
   Float_t         mW1_65To105;
   Float_t         mW2_0To160;
   Float_t         mH_105To160;
   Float_t         mH_40To210;
   Float_t         FL_Lep_Flavor;
   Float_t         LooseMvaSFCentral;
   Float_t         PreselSFCentral;
   Float_t         TriggerWeightCentral;
   Float_t         electronVetoSFCentral;
   Float_t         ElectronIDWeightCentral;
   Float_t         ElectronRecoWeightCentral;
   Float_t         JetBTagCutWeightCentral;
   Float_t         JetBTagReshapeWeightCentral;
   Float_t         MuonIDWeightCentral;
   Float_t         MuonIsoWeightCentral;
   Float_t         prefireWeightCentral;
   Float_t         DiphoCentralWeight;
   Float_t         GenVtx_z;
   Float_t         HggVtx_z;
   Float_t         ZeroVtx_z;
   Float_t         Leading_GEN_Higgs_pt;
   Float_t         Subleading_GEN_Higgs_pt;
   Float_t         Leading_GEN_Higgs_eta;
   Float_t         Subleading_GEN_Higgs_eta;
   Float_t         Leading_GEN_Higgs_phi;
   Float_t         Subleading_GEN_Higgs_phi;
   Float_t         Leading_GEN_Higgs_E;
   Float_t         Subleading_GEN_Higgs_E;
   Float_t         Leading_GEN_Higgs_M;
   Float_t         Subleading_GEN_Higgs_M;
   Float_t         Leading_GEN_W_pt;
   Float_t         Subleading_GEN_W_pt;
   Float_t         Leading_GEN_W_eta;
   Float_t         Subleading_GEN_W_eta;
   Float_t         Leading_GEN_W_phi;
   Float_t         Subleading_GEN_W_phi;
   Float_t         Leading_GEN_W_E;
   Float_t         Subleading_GEN_W_E;
   Float_t         Leading_GEN_W_M;
   Float_t         Subleading_GEN_W_M;
   Float_t         Leading_GEN_Photon_pt;
   Float_t         Subleading_GEN_Photon_pt;
   Float_t         Leading_GEN_Photon_eta;
   Float_t         Subleading_GEN_Photon_eta;
   Float_t         Leading_GEN_Photon_phi;
   Float_t         Subleading_GEN_Photon_phi;
   Float_t         Leading_GEN_Photon_E;
   Float_t         Subleading_GEN_Photon_E;
   Float_t         Leading_GEN_Photon_M;
   Float_t         Subleading_GEN_Photon_M;
   Float_t         GEN_Quark_0_pt;
   Float_t         GEN_Quark_0_eta;
   Float_t         GEN_Quark_0_phi;
   Float_t         GEN_Quark_0_E;
   Float_t         GEN_Quark_0_M;
   Float_t         GEN_Quark_0_pdgId;
   Float_t         GEN_Quark_1_pt;
   Float_t         GEN_Quark_1_eta;
   Float_t         GEN_Quark_1_phi;
   Float_t         GEN_Quark_1_E;
   Float_t         GEN_Quark_1_M;
   Float_t         GEN_Quark_1_pdgId;
   Float_t         GEN_Quark_2_pt;
   Float_t         GEN_Quark_2_eta;
   Float_t         GEN_Quark_2_phi;
   Float_t         GEN_Quark_2_E;
   Float_t         GEN_Quark_2_M;
   Float_t         GEN_Quark_2_pdgId;
   Float_t         GEN_Quark_3_pt;
   Float_t         GEN_Quark_3_eta;
   Float_t         GEN_Quark_3_phi;
   Float_t         GEN_Quark_3_E;
   Float_t         GEN_Quark_3_M;
   Float_t         GEN_Quark_3_pdgId;
   Float_t         GEN_Lepton_0_pt;
   Float_t         GEN_Lepton_0_eta;
   Float_t         GEN_Lepton_0_phi;
   Float_t         GEN_Lepton_0_E;
   Float_t         GEN_Lepton_0_M;
   Float_t         GEN_Lepton_0_pdgId;
   Float_t         GEN_Lepton_1_pt;
   Float_t         GEN_Lepton_1_eta;
   Float_t         GEN_Lepton_1_phi;
   Float_t         GEN_Lepton_1_E;
   Float_t         GEN_Lepton_1_M;
   Float_t         GEN_Lepton_1_pdgId;
   Float_t         GEN_Neutrino_0_pt;
   Float_t         GEN_Neutrino_0_eta;
   Float_t         GEN_Neutrino_0_phi;
   Float_t         GEN_Neutrino_0_E;
   Float_t         GEN_Neutrino_0_M;
   Float_t         GEN_Neutrino_0_pdgId;
   Float_t         GEN_Neutrino_1_pt;
   Float_t         GEN_Neutrino_1_eta;
   Float_t         GEN_Neutrino_1_phi;
   Float_t         GEN_Neutrino_1_E;
   Float_t         GEN_Neutrino_1_M;
   Float_t         GEN_Neutrino_1_pdgId;
   Float_t         genMhh;
   Float_t         genCosThetaStar_CS;
   Float_t         genAbsCosThetaStar_CS;
   Float_t         Leading_Photon_MVA;
   Float_t         Subleading_Photon_MVA;
   Float_t         Leading_Photon_SC_eta;
   Float_t         Leading_Photon_initE;
   Float_t         Leading_Photon_r9;
   Float_t         Leading_Photon_full5x5_r9;
   Float_t         Leading_Photon_Hgg_MVA;
   Float_t         Leading_Photon_passElectronVeto;
   Float_t         Leading_Photon_hasPixelSeed;
   Float_t         Subleading_Photon_SC_eta;
   Float_t         Subleading_Photon_r9;
   Float_t         Subleading_Photon_full5x5_r9;
   Float_t         Subleading_Photon_passElectronVeto;
   Float_t         Subleading_Photon_hasPixelSeed;
   Float_t         Leading_Photon_E;
   Float_t         Leading_Photon_pt;
   Float_t         Leading_Photon_px;
   Float_t         Leading_Photon_py;
   Float_t         Leading_Photon_pz;
   Float_t         Leading_Photon_eta;
   Float_t         Leading_Photon_phi;
   Float_t         Subleading_Photon_E;
   Float_t         Subleading_Photon_pt;
   Float_t         Subleading_Photon_px;
   Float_t         Subleading_Photon_py;
   Float_t         Subleading_Photon_pz;
   Float_t         Subleading_Photon_eta;
   Float_t         Subleading_Photon_phi;
   Float_t         Electron_E;
   Float_t         Electron_pt;
   Float_t         Electron_px;
   Float_t         Electron_py;
   Float_t         Electron_pz;
   Float_t         Electron_eta;
   Float_t         Electron_phi;
   Float_t         Muon_E;
   Float_t         Muon_pt;
   Float_t         Muon_px;
   Float_t         Muon_py;
   Float_t         Muon_pz;
   Float_t         Muon_eta;
   Float_t         Muon_phi;
   Float_t         MET_E;
   Float_t         MET_pt;
   Float_t         MET_px;
   Float_t         MET_py;
   Float_t         MET_pz;
   Float_t         MET_eta;
   Float_t         MET_phi;
   Float_t         Leading_Jet_E;
   Float_t         Leading_Jet_pt;
   Float_t         Leading_Jet_px;
   Float_t         Leading_Jet_py;
   Float_t         Leading_Jet_pz;
   Float_t         Leading_Jet_eta;
   Float_t         Leading_Jet_phi;
   Float_t         Subleading_Jet_E;
   Float_t         Subleading_Jet_pt;
   Float_t         Subleading_Jet_px;
   Float_t         Subleading_Jet_py;
   Float_t         Subleading_Jet_pz;
   Float_t         Subleading_Jet_eta;
   Float_t         Subleading_Jet_phi;
   Float_t         Sub2leading_Jet_E;
   Float_t         Sub2leading_Jet_pt;
   Float_t         Sub2leading_Jet_px;
   Float_t         Sub2leading_Jet_py;
   Float_t         Sub2leading_Jet_pz;
   Float_t         Sub2leading_Jet_eta;
   Float_t         Sub2leading_Jet_phi;
   Float_t         Sub3leading_Jet_E;
   Float_t         Sub3leading_Jet_pt;
   Float_t         Sub3leading_Jet_px;
   Float_t         Sub3leading_Jet_py;
   Float_t         Sub3leading_Jet_pz;
   Float_t         Sub3leading_Jet_eta;
   Float_t         Sub3leading_Jet_phi;
   Float_t         N_allElectrons;
   Float_t         allElectrons_0_E;
   Float_t         allElectrons_1_E;
   Float_t         allElectrons_2_E;
   Float_t         allElectrons_3_E;
   Float_t         allElectrons_4_E;
   Float_t         allElectrons_0_pt;
   Float_t         allElectrons_1_pt;
   Float_t         allElectrons_2_pt;
   Float_t         allElectrons_3_pt;
   Float_t         allElectrons_4_pt;
   Float_t         allElectrons_0_px;
   Float_t         allElectrons_1_px;
   Float_t         allElectrons_2_px;
   Float_t         allElectrons_3_px;
   Float_t         allElectrons_4_px;
   Float_t         allElectrons_0_py;
   Float_t         allElectrons_1_py;
   Float_t         allElectrons_2_py;
   Float_t         allElectrons_3_py;
   Float_t         allElectrons_4_py;
   Float_t         allElectrons_0_pz;
   Float_t         allElectrons_1_pz;
   Float_t         allElectrons_2_pz;
   Float_t         allElectrons_3_pz;
   Float_t         allElectrons_4_pz;
   Float_t         allElectrons_0_eta;
   Float_t         allElectrons_1_eta;
   Float_t         allElectrons_2_eta;
   Float_t         allElectrons_3_eta;
   Float_t         allElectrons_4_eta;
   Float_t         allElectrons_0_phi;
   Float_t         allElectrons_1_phi;
   Float_t         allElectrons_2_phi;
   Float_t         allElectrons_3_phi;
   Float_t         allElectrons_4_phi;
   Float_t         allElectrons_0_passLooseId;
   Float_t         allElectrons_1_passLooseId;
   Float_t         allElectrons_2_passLooseId;
   Float_t         allElectrons_3_passLooseId;
   Float_t         allElectrons_4_passLooseId;
   Float_t         allElectrons_0_passMediumId;
   Float_t         allElectrons_1_passMediumId;
   Float_t         allElectrons_2_passMediumId;
   Float_t         allElectrons_3_passMediumId;
   Float_t         allElectrons_4_passMediumId;
   Float_t         allElectrons_0_passTightId;
   Float_t         allElectrons_1_passTightId;
   Float_t         allElectrons_2_passTightId;
   Float_t         allElectrons_3_passTightId;
   Float_t         allElectrons_4_passTightId;
   Float_t         allElectrons_0_passMVALooseId;
   Float_t         allElectrons_1_passMVALooseId;
   Float_t         allElectrons_2_passMVALooseId;
   Float_t         allElectrons_3_passMVALooseId;
   Float_t         allElectrons_4_passMVALooseId;
   Float_t         allElectrons_0_passMVAMediumId;
   Float_t         allElectrons_1_passMVAMediumId;
   Float_t         allElectrons_2_passMVAMediumId;
   Float_t         allElectrons_3_passMVAMediumId;
   Float_t         allElectrons_4_passMVAMediumId;
   Float_t         allElectrons_0_passMVATightId;
   Float_t         allElectrons_1_passMVATightId;
   Float_t         allElectrons_2_passMVATightId;
   Float_t         allElectrons_3_passMVATightId;
   Float_t         allElectrons_4_passMVATightId;
   Float_t         N_allMuons;
   Float_t         allMuons_0_E;
   Float_t         allMuons_1_E;
   Float_t         allMuons_2_E;
   Float_t         allMuons_3_E;
   Float_t         allMuons_4_E;
   Float_t         allMuons_0_pt;
   Float_t         allMuons_1_pt;
   Float_t         allMuons_2_pt;
   Float_t         allMuons_3_pt;
   Float_t         allMuons_4_pt;
   Float_t         allMuons_0_px;
   Float_t         allMuons_1_px;
   Float_t         allMuons_2_px;
   Float_t         allMuons_3_px;
   Float_t         allMuons_4_px;
   Float_t         allMuons_0_py;
   Float_t         allMuons_1_py;
   Float_t         allMuons_2_py;
   Float_t         allMuons_3_py;
   Float_t         allMuons_4_py;
   Float_t         allMuons_0_pz;
   Float_t         allMuons_1_pz;
   Float_t         allMuons_2_pz;
   Float_t         allMuons_3_pz;
   Float_t         allMuons_4_pz;
   Float_t         allMuons_0_eta;
   Float_t         allMuons_1_eta;
   Float_t         allMuons_2_eta;
   Float_t         allMuons_3_eta;
   Float_t         allMuons_4_eta;
   Float_t         allMuons_0_phi;
   Float_t         allMuons_1_phi;
   Float_t         allMuons_2_phi;
   Float_t         allMuons_3_phi;
   Float_t         allMuons_4_phi;
   Float_t         N_allJets;
   Float_t         allJets_0_E;
   Float_t         allJets_1_E;
   Float_t         allJets_2_E;
   Float_t         allJets_3_E;
   Float_t         allJets_4_E;
   Float_t         allJets_5_E;
   Float_t         allJets_6_E;
   Float_t         allJets_7_E;
   Float_t         allJets_8_E;
   Float_t         allJets_9_E;
   Float_t         allJets_0_pt;
   Float_t         allJets_1_pt;
   Float_t         allJets_2_pt;
   Float_t         allJets_3_pt;
   Float_t         allJets_4_pt;
   Float_t         allJets_5_pt;
   Float_t         allJets_6_pt;
   Float_t         allJets_7_pt;
   Float_t         allJets_8_pt;
   Float_t         allJets_9_pt;
   Float_t         allJets_0_px;
   Float_t         allJets_1_px;
   Float_t         allJets_2_px;
   Float_t         allJets_3_px;
   Float_t         allJets_4_px;
   Float_t         allJets_5_px;
   Float_t         allJets_6_px;
   Float_t         allJets_7_px;
   Float_t         allJets_8_px;
   Float_t         allJets_9_px;
   Float_t         allJets_0_py;
   Float_t         allJets_1_py;
   Float_t         allJets_2_py;
   Float_t         allJets_3_py;
   Float_t         allJets_4_py;
   Float_t         allJets_5_py;
   Float_t         allJets_6_py;
   Float_t         allJets_7_py;
   Float_t         allJets_8_py;
   Float_t         allJets_9_py;
   Float_t         allJets_0_pz;
   Float_t         allJets_1_pz;
   Float_t         allJets_2_pz;
   Float_t         allJets_3_pz;
   Float_t         allJets_4_pz;
   Float_t         allJets_5_pz;
   Float_t         allJets_6_pz;
   Float_t         allJets_7_pz;
   Float_t         allJets_8_pz;
   Float_t         allJets_9_pz;
   Float_t         allJets_0_eta;
   Float_t         allJets_1_eta;
   Float_t         allJets_2_eta;
   Float_t         allJets_3_eta;
   Float_t         allJets_4_eta;
   Float_t         allJets_5_eta;
   Float_t         allJets_6_eta;
   Float_t         allJets_7_eta;
   Float_t         allJets_8_eta;
   Float_t         allJets_9_eta;
   Float_t         allJets_0_phi;
   Float_t         allJets_1_phi;
   Float_t         allJets_2_phi;
   Float_t         allJets_3_phi;
   Float_t         allJets_4_phi;
   Float_t         allJets_5_phi;
   Float_t         allJets_6_phi;
   Float_t         allJets_7_phi;
   Float_t         allJets_8_phi;
   Float_t         allJets_9_phi;
   Float_t         allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         allJets_0_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_1_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_2_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_3_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_4_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_5_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_6_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_7_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_8_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_9_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         allJets_0_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_1_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_2_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_3_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_4_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_5_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_6_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_7_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_8_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_9_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         N_goodElectrons;
   Float_t         goodElectrons_0_E;
   Float_t         goodElectrons_1_E;
   Float_t         goodElectrons_2_E;
   Float_t         goodElectrons_3_E;
   Float_t         goodElectrons_4_E;
   Float_t         goodElectrons_5_E;
   Float_t         goodElectrons_6_E;
   Float_t         goodElectrons_7_E;
   Float_t         goodElectrons_8_E;
   Float_t         goodElectrons_9_E;
   Float_t         goodElectrons_0_pt;
   Float_t         goodElectrons_1_pt;
   Float_t         goodElectrons_2_pt;
   Float_t         goodElectrons_3_pt;
   Float_t         goodElectrons_4_pt;
   Float_t         goodElectrons_5_pt;
   Float_t         goodElectrons_6_pt;
   Float_t         goodElectrons_7_pt;
   Float_t         goodElectrons_8_pt;
   Float_t         goodElectrons_9_pt;
   Float_t         goodElectrons_0_px;
   Float_t         goodElectrons_1_px;
   Float_t         goodElectrons_2_px;
   Float_t         goodElectrons_3_px;
   Float_t         goodElectrons_4_px;
   Float_t         goodElectrons_5_px;
   Float_t         goodElectrons_6_px;
   Float_t         goodElectrons_7_px;
   Float_t         goodElectrons_8_px;
   Float_t         goodElectrons_9_px;
   Float_t         goodElectrons_0_py;
   Float_t         goodElectrons_1_py;
   Float_t         goodElectrons_2_py;
   Float_t         goodElectrons_3_py;
   Float_t         goodElectrons_4_py;
   Float_t         goodElectrons_5_py;
   Float_t         goodElectrons_6_py;
   Float_t         goodElectrons_7_py;
   Float_t         goodElectrons_8_py;
   Float_t         goodElectrons_9_py;
   Float_t         goodElectrons_0_pz;
   Float_t         goodElectrons_1_pz;
   Float_t         goodElectrons_2_pz;
   Float_t         goodElectrons_3_pz;
   Float_t         goodElectrons_4_pz;
   Float_t         goodElectrons_5_pz;
   Float_t         goodElectrons_6_pz;
   Float_t         goodElectrons_7_pz;
   Float_t         goodElectrons_8_pz;
   Float_t         goodElectrons_9_pz;
   Float_t         goodElectrons_0_eta;
   Float_t         goodElectrons_1_eta;
   Float_t         goodElectrons_2_eta;
   Float_t         goodElectrons_3_eta;
   Float_t         goodElectrons_4_eta;
   Float_t         goodElectrons_5_eta;
   Float_t         goodElectrons_6_eta;
   Float_t         goodElectrons_7_eta;
   Float_t         goodElectrons_8_eta;
   Float_t         goodElectrons_9_eta;
   Float_t         goodElectrons_0_phi;
   Float_t         goodElectrons_1_phi;
   Float_t         goodElectrons_2_phi;
   Float_t         goodElectrons_3_phi;
   Float_t         goodElectrons_4_phi;
   Float_t         goodElectrons_5_phi;
   Float_t         goodElectrons_6_phi;
   Float_t         goodElectrons_7_phi;
   Float_t         goodElectrons_8_phi;
   Float_t         goodElectrons_9_phi;
   Float_t         goodElectrons_0_passLooseId;
   Float_t         goodElectrons_1_passLooseId;
   Float_t         goodElectrons_2_passLooseId;
   Float_t         goodElectrons_3_passLooseId;
   Float_t         goodElectrons_4_passLooseId;
   Float_t         goodElectrons_5_passLooseId;
   Float_t         goodElectrons_6_passLooseId;
   Float_t         goodElectrons_7_passLooseId;
   Float_t         goodElectrons_8_passLooseId;
   Float_t         goodElectrons_9_passLooseId;
   Float_t         goodElectrons_0_passMediumId;
   Float_t         goodElectrons_1_passMediumId;
   Float_t         goodElectrons_2_passMediumId;
   Float_t         goodElectrons_3_passMediumId;
   Float_t         goodElectrons_4_passMediumId;
   Float_t         goodElectrons_5_passMediumId;
   Float_t         goodElectrons_6_passMediumId;
   Float_t         goodElectrons_7_passMediumId;
   Float_t         goodElectrons_8_passMediumId;
   Float_t         goodElectrons_9_passMediumId;
   Float_t         goodElectrons_0_passTightId;
   Float_t         goodElectrons_1_passTightId;
   Float_t         goodElectrons_2_passTightId;
   Float_t         goodElectrons_3_passTightId;
   Float_t         goodElectrons_4_passTightId;
   Float_t         goodElectrons_5_passTightId;
   Float_t         goodElectrons_6_passTightId;
   Float_t         goodElectrons_7_passTightId;
   Float_t         goodElectrons_8_passTightId;
   Float_t         goodElectrons_9_passTightId;
   Float_t         goodElectrons_0_passMVALooseId;
   Float_t         goodElectrons_1_passMVALooseId;
   Float_t         goodElectrons_2_passMVALooseId;
   Float_t         goodElectrons_3_passMVALooseId;
   Float_t         goodElectrons_4_passMVALooseId;
   Float_t         goodElectrons_5_passMVALooseId;
   Float_t         goodElectrons_6_passMVALooseId;
   Float_t         goodElectrons_7_passMVALooseId;
   Float_t         goodElectrons_8_passMVALooseId;
   Float_t         goodElectrons_9_passMVALooseId;
   Float_t         goodElectrons_0_passMVAMediumId;
   Float_t         goodElectrons_1_passMVAMediumId;
   Float_t         goodElectrons_2_passMVAMediumId;
   Float_t         goodElectrons_3_passMVAMediumId;
   Float_t         goodElectrons_4_passMVAMediumId;
   Float_t         goodElectrons_5_passMVAMediumId;
   Float_t         goodElectrons_6_passMVAMediumId;
   Float_t         goodElectrons_7_passMVAMediumId;
   Float_t         goodElectrons_8_passMVAMediumId;
   Float_t         goodElectrons_9_passMVAMediumId;
   Float_t         goodElectrons_0_passMVATightId;
   Float_t         goodElectrons_1_passMVATightId;
   Float_t         goodElectrons_2_passMVATightId;
   Float_t         goodElectrons_3_passMVATightId;
   Float_t         goodElectrons_4_passMVATightId;
   Float_t         goodElectrons_5_passMVATightId;
   Float_t         goodElectrons_6_passMVATightId;
   Float_t         goodElectrons_7_passMVATightId;
   Float_t         goodElectrons_8_passMVATightId;
   Float_t         goodElectrons_9_passMVATightId;
   Float_t         N_goodMuons;
   Float_t         goodMuons_0_E;
   Float_t         goodMuons_1_E;
   Float_t         goodMuons_2_E;
   Float_t         goodMuons_3_E;
   Float_t         goodMuons_4_E;
   Float_t         goodMuons_5_E;
   Float_t         goodMuons_6_E;
   Float_t         goodMuons_7_E;
   Float_t         goodMuons_8_E;
   Float_t         goodMuons_9_E;
   Float_t         goodMuons_0_pt;
   Float_t         goodMuons_1_pt;
   Float_t         goodMuons_2_pt;
   Float_t         goodMuons_3_pt;
   Float_t         goodMuons_4_pt;
   Float_t         goodMuons_5_pt;
   Float_t         goodMuons_6_pt;
   Float_t         goodMuons_7_pt;
   Float_t         goodMuons_8_pt;
   Float_t         goodMuons_9_pt;
   Float_t         goodMuons_0_px;
   Float_t         goodMuons_1_px;
   Float_t         goodMuons_2_px;
   Float_t         goodMuons_3_px;
   Float_t         goodMuons_4_px;
   Float_t         goodMuons_5_px;
   Float_t         goodMuons_6_px;
   Float_t         goodMuons_7_px;
   Float_t         goodMuons_8_px;
   Float_t         goodMuons_9_px;
   Float_t         goodMuons_0_py;
   Float_t         goodMuons_1_py;
   Float_t         goodMuons_2_py;
   Float_t         goodMuons_3_py;
   Float_t         goodMuons_4_py;
   Float_t         goodMuons_5_py;
   Float_t         goodMuons_6_py;
   Float_t         goodMuons_7_py;
   Float_t         goodMuons_8_py;
   Float_t         goodMuons_9_py;
   Float_t         goodMuons_0_pz;
   Float_t         goodMuons_1_pz;
   Float_t         goodMuons_2_pz;
   Float_t         goodMuons_3_pz;
   Float_t         goodMuons_4_pz;
   Float_t         goodMuons_5_pz;
   Float_t         goodMuons_6_pz;
   Float_t         goodMuons_7_pz;
   Float_t         goodMuons_8_pz;
   Float_t         goodMuons_9_pz;
   Float_t         goodMuons_0_eta;
   Float_t         goodMuons_1_eta;
   Float_t         goodMuons_2_eta;
   Float_t         goodMuons_3_eta;
   Float_t         goodMuons_4_eta;
   Float_t         goodMuons_5_eta;
   Float_t         goodMuons_6_eta;
   Float_t         goodMuons_7_eta;
   Float_t         goodMuons_8_eta;
   Float_t         goodMuons_9_eta;
   Float_t         goodMuons_0_phi;
   Float_t         goodMuons_1_phi;
   Float_t         goodMuons_2_phi;
   Float_t         goodMuons_3_phi;
   Float_t         goodMuons_4_phi;
   Float_t         goodMuons_5_phi;
   Float_t         goodMuons_6_phi;
   Float_t         goodMuons_7_phi;
   Float_t         goodMuons_8_phi;
   Float_t         goodMuons_9_phi;
   Float_t         N_goodJets;
   Float_t         goodJets_0_E;
   Float_t         goodJets_1_E;
   Float_t         goodJets_2_E;
   Float_t         goodJets_3_E;
   Float_t         goodJets_4_E;
   Float_t         goodJets_5_E;
   Float_t         goodJets_6_E;
   Float_t         goodJets_7_E;
   Float_t         goodJets_8_E;
   Float_t         goodJets_9_E;
   Float_t         goodJets_0_pt;
   Float_t         goodJets_1_pt;
   Float_t         goodJets_2_pt;
   Float_t         goodJets_3_pt;
   Float_t         goodJets_4_pt;
   Float_t         goodJets_5_pt;
   Float_t         goodJets_6_pt;
   Float_t         goodJets_7_pt;
   Float_t         goodJets_8_pt;
   Float_t         goodJets_9_pt;
   Float_t         goodJets_0_px;
   Float_t         goodJets_1_px;
   Float_t         goodJets_2_px;
   Float_t         goodJets_3_px;
   Float_t         goodJets_4_px;
   Float_t         goodJets_5_px;
   Float_t         goodJets_6_px;
   Float_t         goodJets_7_px;
   Float_t         goodJets_8_px;
   Float_t         goodJets_9_px;
   Float_t         goodJets_0_py;
   Float_t         goodJets_1_py;
   Float_t         goodJets_2_py;
   Float_t         goodJets_3_py;
   Float_t         goodJets_4_py;
   Float_t         goodJets_5_py;
   Float_t         goodJets_6_py;
   Float_t         goodJets_7_py;
   Float_t         goodJets_8_py;
   Float_t         goodJets_9_py;
   Float_t         goodJets_0_pz;
   Float_t         goodJets_1_pz;
   Float_t         goodJets_2_pz;
   Float_t         goodJets_3_pz;
   Float_t         goodJets_4_pz;
   Float_t         goodJets_5_pz;
   Float_t         goodJets_6_pz;
   Float_t         goodJets_7_pz;
   Float_t         goodJets_8_pz;
   Float_t         goodJets_9_pz;
   Float_t         goodJets_0_eta;
   Float_t         goodJets_1_eta;
   Float_t         goodJets_2_eta;
   Float_t         goodJets_3_eta;
   Float_t         goodJets_4_eta;
   Float_t         goodJets_5_eta;
   Float_t         goodJets_6_eta;
   Float_t         goodJets_7_eta;
   Float_t         goodJets_8_eta;
   Float_t         goodJets_9_eta;
   Float_t         goodJets_0_phi;
   Float_t         goodJets_1_phi;
   Float_t         goodJets_2_phi;
   Float_t         goodJets_3_phi;
   Float_t         goodJets_4_phi;
   Float_t         goodJets_5_phi;
   Float_t         goodJets_6_phi;
   Float_t         goodJets_7_phi;
   Float_t         goodJets_8_phi;
   Float_t         goodJets_9_phi;
   Float_t         goodJets_0_PassLooseJetPUID;
   Float_t         goodJets_0_PassMediumJetPUID;
   Float_t         goodJets_0_PassTightJetPUID;
   Float_t         goodJets_1_PassLooseJetPUID;
   Float_t         goodJets_1_PassMediumJetPUID;
   Float_t         goodJets_1_PassTightJetPUID;
   Float_t         goodJets_2_PassLooseJetPUID;
   Float_t         goodJets_2_PassMediumJetPUID;
   Float_t         goodJets_2_PassTightJetPUID;
   Float_t         goodJets_3_PassLooseJetPUID;
   Float_t         goodJets_3_PassMediumJetPUID;
   Float_t         goodJets_3_PassTightJetPUID;
   Float_t         goodJets_4_PassLooseJetPUID;
   Float_t         goodJets_4_PassMediumJetPUID;
   Float_t         goodJets_4_PassTightJetPUID;
   Float_t         goodJets_5_PassLooseJetPUID;
   Float_t         goodJets_5_PassMediumJetPUID;
   Float_t         goodJets_5_PassTightJetPUID;
   Float_t         goodJets_6_PassLooseJetPUID;
   Float_t         goodJets_6_PassMediumJetPUID;
   Float_t         goodJets_6_PassTightJetPUID;
   Float_t         goodJets_7_PassLooseJetPUID;
   Float_t         goodJets_7_PassMediumJetPUID;
   Float_t         goodJets_7_PassTightJetPUID;
   Float_t         goodJets_8_PassLooseJetPUID;
   Float_t         goodJets_8_PassMediumJetPUID;
   Float_t         goodJets_8_PassTightJetPUID;
   Float_t         goodJets_9_PassLooseJetPUID;
   Float_t         goodJets_9_PassMediumJetPUID;
   Float_t         goodJets_9_PassTightJetPUID;
   Float_t         goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
   Float_t         goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb;
   Float_t         goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
   Float_t         goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb;
   Float_t         goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
   Float_t         Leading_Photon_genMatchType;
   Float_t         Subleading_Photon_genMatchType;
   Float_t         dipho_MVA;
   Float_t         dipho_pt;
   Float_t         allMuons_0_isLooseMuon;
   Float_t         allMuons_0_isMediumMuon;
   Float_t         allMuons_0_isTightMuon;
   Float_t         allMuons_0_isSoftMuon;
   Float_t         allMuons_0_isHighPtMuon;
   Float_t         allMuons_0_muonIso;
   Float_t         allMuons_1_isLooseMuon;
   Float_t         allMuons_1_isMediumMuon;
   Float_t         allMuons_1_isTightMuon;
   Float_t         allMuons_1_isSoftMuon;
   Float_t         allMuons_1_isHighPtMuon;
   Float_t         allMuons_1_muonIso;
   Float_t         allMuons_2_isLooseMuon;
   Float_t         allMuons_2_isMediumMuon;
   Float_t         allMuons_2_isTightMuon;
   Float_t         allMuons_2_isSoftMuon;
   Float_t         allMuons_2_isHighPtMuon;
   Float_t         allMuons_2_muonIso;
   Float_t         allMuons_3_isLooseMuon;
   Float_t         allMuons_3_isMediumMuon;
   Float_t         allMuons_3_isTightMuon;
   Float_t         allMuons_3_isSoftMuon;
   Float_t         allMuons_3_isHighPtMuon;
   Float_t         allMuons_3_muonIso;
   Float_t         allMuons_4_isLooseMuon;
   Float_t         allMuons_4_isMediumMuon;
   Float_t         allMuons_4_isTightMuon;
   Float_t         allMuons_4_isSoftMuon;
   Float_t         allMuons_4_isHighPtMuon;
   Float_t         allMuons_4_muonIso;
   Float_t         allJets_0_passLoose;
   Float_t         allJets_0_passTight;
   Float_t         allJets_0_passTight2017;
   Float_t         allJets_0_passTight2018;
   Float_t         allJets_1_passLoose;
   Float_t         allJets_1_passTight;
   Float_t         allJets_1_passTight2017;
   Float_t         allJets_1_passTight2018;
   Float_t         allJets_2_passLoose;
   Float_t         allJets_2_passTight;
   Float_t         allJets_2_passTight2017;
   Float_t         allJets_2_passTight2018;
   Float_t         allJets_3_passLoose;
   Float_t         allJets_3_passTight;
   Float_t         allJets_3_passTight2017;
   Float_t         allJets_3_passTight2018;
   Float_t         allJets_4_passLoose;
   Float_t         allJets_4_passTight;
   Float_t         allJets_4_passTight2017;
   Float_t         allJets_4_passTight2018;
   Float_t         W1Candidate_E;
   Float_t         W1Candidate_M;
   Float_t         W1Candidate_pt;
   Float_t         W1Candidate_px;
   Float_t         W1Candidate_py;
   Float_t         W1Candidate_pz;
   Float_t         W1Candidate_eta;
   Float_t         W1Candidate_phi;
   Float_t         W2Candidate_E;
   Float_t         W2Candidate_M;
   Float_t         W2Candidate_pt;
   Float_t         W2Candidate_px;
   Float_t         W2Candidate_py;
   Float_t         W2Candidate_pz;
   Float_t         W2Candidate_eta;
   Float_t         W2Candidate_phi;
   Float_t         HWWCandidate_E;
   Float_t         HWWCandidate_M;
   Float_t         HWWCandidate_pt;
   Float_t         HWWCandidate_px;
   Float_t         HWWCandidate_py;
   Float_t         HWWCandidate_pz;
   Float_t         HWWCandidate_eta;
   Float_t         HWWCandidate_phi;
   Float_t         HGGCandidate_E;
   Float_t         HGGCandidate_M;
   Float_t         HGGCandidate_pt;
   Float_t         HGGCandidate_px;
   Float_t         HGGCandidate_py;
   Float_t         HGGCandidate_pz;
   Float_t         HGGCandidate_eta;
   Float_t         HGGCandidate_phi;
   Float_t         HHCandidate_E;
   Float_t         HHCandidate_M;
   Float_t         HHCandidate_pt;
   Float_t         HHCandidate_px;
   Float_t         HHCandidate_py;
   Float_t         HHCandidate_pz;
   Float_t         HHCandidate_eta;
   Float_t         HHCandidate_phi;
   Float_t         DeltaEta_HH;
   Float_t         DeltaPhi_HH;
   Float_t         DeltaR_HH;
   Float_t         cosThetaHH;
   Float_t         cosThetaWW;
   Float_t         rho;
   Int_t           nvtx;
   ULong64_t       event;
   UInt_t          lumi;
   Int_t           processIndex;
   UInt_t          run;
   Float_t         npu;
   Float_t         puweight;
   Float_t         weight_NLO_SM;
   Float_t         PhotonID_min;
   Float_t         PhotonID_max;
   Float_t         New_Leading_Jet_E;
   Float_t         New_Leading_Jet_pt;
   Float_t         New_Leading_Jet_px;
   Float_t         New_Leading_Jet_py;
   Float_t         New_Leading_Jet_pz;
   Float_t         New_Leading_Jet_eta;
   Float_t         New_Leading_Jet_phi;
   Float_t         New_Subleading_Jet_E;
   Float_t         New_Subleading_Jet_pt;
   Float_t         New_Subleading_Jet_px;
   Float_t         New_Subleading_Jet_py;
   Float_t         New_Subleading_Jet_pz;
   Float_t         New_Subleading_Jet_eta;
   Float_t         New_Subleading_Jet_phi;
   Float_t         New_Sub2leading_Jet_E;
   Float_t         New_Sub2leading_Jet_pt;
   Float_t         New_Sub2leading_Jet_px;
   Float_t         New_Sub2leading_Jet_py;
   Float_t         New_Sub2leading_Jet_pz;
   Float_t         New_Sub2leading_Jet_eta;
   Float_t         New_Sub2leading_Jet_phi;
   Float_t         New_Sub3leading_Jet_E;
   Float_t         New_Sub3leading_Jet_pt;
   Float_t         New_Sub3leading_Jet_px;
   Float_t         New_Sub3leading_Jet_py;
   Float_t         New_Sub3leading_Jet_pz;
   Float_t         New_Sub3leading_Jet_eta;
   Float_t         New_Sub3leading_Jet_phi;
   Float_t         New_OnShellW_LeadingJet_bDis;
   Float_t         New_OnShellW_SubLeadingJet_bDis;
   Float_t         New_OffShellW_LeadingJet_bDis;
   Float_t         New_OffShellW_SubLeadingJet_bDis;
   Float_t         New_OnShellW_E;
   Float_t         New_OnShellW_Mass;
   Float_t         New_OnShellW_pt;
   Float_t         New_OnShellW_px;
   Float_t         New_OnShellW_py;
   Float_t         New_OnShellW_pz;
   Float_t         New_OnShellW_eta;
   Float_t         New_OnShellW_phi;
   Float_t         New_OffShellW_E;
   Float_t         New_OffShellW_Mass;
   Float_t         New_OffShellW_pt;
   Float_t         New_OffShellW_px;
   Float_t         New_OffShellW_py;
   Float_t         New_OffShellW_pz;
   Float_t         New_OffShellW_eta;
   Float_t         New_OffShellW_phi;
   Float_t         New_HWW_E;
   Float_t         New_HWW_Mass;
   Float_t         New_HWW_pt;
   Float_t         New_HWW_px;
   Float_t         New_HWW_py;
   Float_t         New_HWW_pz;
   Float_t         New_HWW_eta;
   Float_t         New_HWW_phi;
   Float_t         New_dR_Hgg_Jet1;
   Float_t         New_dR_Hgg_Jet2;
   Float_t         New_dR_Hgg_Jet3;
   Float_t         New_dR_Hgg_Jet4;
   Float_t         New_dPhi_Hgg_Jet1;
   Float_t         New_dPhi_Hgg_Jet2;
   Float_t         New_dPhi_Hgg_Jet3;
   Float_t         New_dPhi_Hgg_Jet4;
   Float_t         New_DPhi_gg;
   Float_t         New_DR_gg;
   Float_t         New_DPhi_HH;
   Float_t         New_DR_HH;
   Float_t         New_minDeltaR_gg4j;
   Float_t         New_maxDeltaR_gg4j;
   Float_t         New_minDeltaR_4j;
   Float_t         New_maxDeltaR_4j;
   Float_t         a_costheta1;
   Float_t         a_costheta2;
   Float_t         a_costhetastar;
   Float_t         a_Phi;
   Float_t         a_Phi1;
   Float_t         CosThetaStar_CS;
   Float_t         CosThetaStar_CS_old;
   Float_t         HelicityCostheta1;
   Float_t         HelicityCostheta2;
   Float_t         New_DRBased_Leading_Jet_E;
   Float_t         New_DRBased_Leading_Jet_pt;
   Float_t         New_DRBased_Leading_Jet_px;
   Float_t         New_DRBased_Leading_Jet_py;
   Float_t         New_DRBased_Leading_Jet_pz;
   Float_t         New_DRBased_Leading_Jet_eta;
   Float_t         New_DRBased_Leading_Jet_phi;
   Float_t         New_DRBased_Subleading_Jet_E;
   Float_t         New_DRBased_Subleading_Jet_pt;
   Float_t         New_DRBased_Subleading_Jet_px;
   Float_t         New_DRBased_Subleading_Jet_py;
   Float_t         New_DRBased_Subleading_Jet_pz;
   Float_t         New_DRBased_Subleading_Jet_eta;
   Float_t         New_DRBased_Subleading_Jet_phi;
   Float_t         New_DRBased_Sub2leading_Jet_E;
   Float_t         New_DRBased_Sub2leading_Jet_pt;
   Float_t         New_DRBased_Sub2leading_Jet_px;
   Float_t         New_DRBased_Sub2leading_Jet_py;
   Float_t         New_DRBased_Sub2leading_Jet_pz;
   Float_t         New_DRBased_Sub2leading_Jet_eta;
   Float_t         New_DRBased_Sub2leading_Jet_phi;
   Float_t         New_DRBased_Sub3leading_Jet_E;
   Float_t         New_DRBased_Sub3leading_Jet_pt;
   Float_t         New_DRBased_Sub3leading_Jet_px;
   Float_t         New_DRBased_Sub3leading_Jet_py;
   Float_t         New_DRBased_Sub3leading_Jet_pz;
   Float_t         New_DRBased_Sub3leading_Jet_eta;
   Float_t         New_DRBased_Sub3leading_Jet_phi;
   Float_t         New_DRBased_OnShellW_LeadingJet_bDis;
   Float_t         New_DRBased_OnShellW_SubLeadingJet_bDis;
   Float_t         New_DRBased_OffShellW_LeadingJet_bDis;
   Float_t         New_DRBased_OffShellW_SubLeadingJet_bDis;
   Float_t         New_DRBased_OnShellW_E;
   Float_t         New_DRBased_OnShellW_Mass;
   Float_t         New_DRBased_OnShellW_pt;
   Float_t         New_DRBased_OnShellW_px;
   Float_t         New_DRBased_OnShellW_py;
   Float_t         New_DRBased_OnShellW_pz;
   Float_t         New_DRBased_OnShellW_eta;
   Float_t         New_DRBased_OnShellW_phi;
   Float_t         New_DRBased_OffShellW_Mass;
   Float_t         New_DRBased_OffShellW_pt;
   Float_t         New_DRBased_OffShellW_px;
   Float_t         New_DRBased_OffShellW_py;
   Float_t         New_DRBased_OffShellW_pz;
   Float_t         New_DRBased_OffShellW_eta;
   Float_t         New_DRBased_OffShellW_phi;
   Float_t         New_DRBased_HWW_Mass;
   Float_t         New_DRBased_HWW_pt;
   Float_t         New_DRBased_HWW_px;
   Float_t         New_DRBased_HWW_py;
   Float_t         New_DRBased_HWW_pz;
   Float_t         New_DRBased_HWW_eta;
   Float_t         New_DRBased_HWW_phi;
   Float_t         New_DRBased_dR_Hgg_Jet1;
   Float_t         New_DRBased_dR_Hgg_Jet2;
   Float_t         New_DRBased_dR_Hgg_Jet3;
   Float_t         New_DRBased_dR_Hgg_Jet4;
   Float_t         New_DRBased_dPhi_Hgg_Jet1;
   Float_t         New_DRBased_dPhi_Hgg_Jet2;
   Float_t         New_DRBased_dPhi_Hgg_Jet3;
   Float_t         New_DRBased_dPhi_Hgg_Jet4;
   Float_t         New_DRBased_DPhi_gg;
   Float_t         New_DRBased_DR_gg;
   Float_t         New_DRBased_DPhi_HH;
   Float_t         New_DRBased_DR_HH;
   Float_t         DRBased_a_costheta1;
   Float_t         DRBased_a_costheta2;
   Float_t         DRBased_a_costhetastar;
   Float_t         DRBased_a_Phi;
   Float_t         DRBased_a_Phi1;
   Float_t         evalDNN;

   // List of branches
   TBranch        *b_candidate_id;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_CMS_hgg_mass;   //!
   TBranch        *b_sigmaMoM_decorr;   //!
   TBranch        *b_dZ;   //!
   TBranch        *b_centralObjectWeight;   //!
   TBranch        *b_LooseMvaSFUp01sigma;   //!
   TBranch        *b_PreselSFUp01sigma;   //!
   TBranch        *b_electronVetoSFUp01sigma;   //!
   TBranch        *b_TriggerWeightUp01sigma;   //!
   TBranch        *b_FracRVWeightUp01sigma;   //!
   TBranch        *b_MuonIDWeightUp01sigma;   //!
   TBranch        *b_ElectronIDWeightUp01sigma;   //!
   TBranch        *b_ElectronRecoWeightUp01sigma;   //!
   TBranch        *b_MuonIsoWeightUp01sigma;   //!
   TBranch        *b_JetBTagCutWeightUp01sigma;   //!
   TBranch        *b_JetBTagReshapeWeightUp01sigma;   //!
   TBranch        *b_prefireWeightUp01sigma;   //!
   TBranch        *b_LooseMvaSFDown01sigma;   //!
   TBranch        *b_PreselSFDown01sigma;   //!
   TBranch        *b_electronVetoSFDown01sigma;   //!
   TBranch        *b_TriggerWeightDown01sigma;   //!
   TBranch        *b_FracRVWeightDown01sigma;   //!
   TBranch        *b_MuonIDWeightDown01sigma;   //!
   TBranch        *b_ElectronIDWeightDown01sigma;   //!
   TBranch        *b_ElectronRecoWeightDown01sigma;   //!
   TBranch        *b_MuonIsoWeightDown01sigma;   //!
   TBranch        *b_JetBTagCutWeightDown01sigma;   //!
   TBranch        *b_JetBTagReshapeWeightDown01sigma;   //!
   TBranch        *b_prefireWeightDown01sigma;   //!
   TBranch        *b_passPS;   //!
   TBranch        *b_passPhotonSels;   //!
   TBranch        *b_mW1_40To160;   //!
   TBranch        *b_mW1_65To105;   //!
   TBranch        *b_mW2_0To160;   //!
   TBranch        *b_mH_105To160;   //!
   TBranch        *b_mH_40To210;   //!
   TBranch        *b_FL_Lep_Flavor;   //!
   TBranch        *b_LooseMvaSFCentral;   //!
   TBranch        *b_PreselSFCentral;   //!
   TBranch        *b_TriggerWeightCentral;   //!
   TBranch        *b_electronVetoSFCentral;   //!
   TBranch        *b_ElectronIDWeightCentral;   //!
   TBranch        *b_ElectronRecoWeightCentral;   //!
   TBranch        *b_JetBTagCutWeightCentral;   //!
   TBranch        *b_JetBTagReshapeWeightCentral;   //!
   TBranch        *b_MuonIDWeightCentral;   //!
   TBranch        *b_MuonIsoWeightCentral;   //!
   TBranch        *b_prefireWeightCentral;   //!
   TBranch        *b_DiphoCentralWeight;   //!
   TBranch        *b_GenVtx_z;   //!
   TBranch        *b_HggVtx_z;   //!
   TBranch        *b_ZeroVtx_z;   //!
   TBranch        *b_Leading_GEN_Higgs_pt;   //!
   TBranch        *b_Subleading_GEN_Higgs_pt;   //!
   TBranch        *b_Leading_GEN_Higgs_eta;   //!
   TBranch        *b_Subleading_GEN_Higgs_eta;   //!
   TBranch        *b_Leading_GEN_Higgs_phi;   //!
   TBranch        *b_Subleading_GEN_Higgs_phi;   //!
   TBranch        *b_Leading_GEN_Higgs_E;   //!
   TBranch        *b_Subleading_GEN_Higgs_E;   //!
   TBranch        *b_Leading_GEN_Higgs_M;   //!
   TBranch        *b_Subleading_GEN_Higgs_M;   //!
   TBranch        *b_Leading_GEN_W_pt;   //!
   TBranch        *b_Subleading_GEN_W_pt;   //!
   TBranch        *b_Leading_GEN_W_eta;   //!
   TBranch        *b_Subleading_GEN_W_eta;   //!
   TBranch        *b_Leading_GEN_W_phi;   //!
   TBranch        *b_Subleading_GEN_W_phi;   //!
   TBranch        *b_Leading_GEN_W_E;   //!
   TBranch        *b_Subleading_GEN_W_E;   //!
   TBranch        *b_Leading_GEN_W_M;   //!
   TBranch        *b_Subleading_GEN_W_M;   //!
   TBranch        *b_Leading_GEN_Photon_pt;   //!
   TBranch        *b_Subleading_GEN_Photon_pt;   //!
   TBranch        *b_Leading_GEN_Photon_eta;   //!
   TBranch        *b_Subleading_GEN_Photon_eta;   //!
   TBranch        *b_Leading_GEN_Photon_phi;   //!
   TBranch        *b_Subleading_GEN_Photon_phi;   //!
   TBranch        *b_Leading_GEN_Photon_E;   //!
   TBranch        *b_Subleading_GEN_Photon_E;   //!
   TBranch        *b_Leading_GEN_Photon_M;   //!
   TBranch        *b_Subleading_GEN_Photon_M;   //!
   TBranch        *b_GEN_Quark_0_pt;   //!
   TBranch        *b_GEN_Quark_0_eta;   //!
   TBranch        *b_GEN_Quark_0_phi;   //!
   TBranch        *b_GEN_Quark_0_E;   //!
   TBranch        *b_GEN_Quark_0_M;   //!
   TBranch        *b_GEN_Quark_0_pdgId;   //!
   TBranch        *b_GEN_Quark_1_pt;   //!
   TBranch        *b_GEN_Quark_1_eta;   //!
   TBranch        *b_GEN_Quark_1_phi;   //!
   TBranch        *b_GEN_Quark_1_E;   //!
   TBranch        *b_GEN_Quark_1_M;   //!
   TBranch        *b_GEN_Quark_1_pdgId;   //!
   TBranch        *b_GEN_Quark_2_pt;   //!
   TBranch        *b_GEN_Quark_2_eta;   //!
   TBranch        *b_GEN_Quark_2_phi;   //!
   TBranch        *b_GEN_Quark_2_E;   //!
   TBranch        *b_GEN_Quark_2_M;   //!
   TBranch        *b_GEN_Quark_2_pdgId;   //!
   TBranch        *b_GEN_Quark_3_pt;   //!
   TBranch        *b_GEN_Quark_3_eta;   //!
   TBranch        *b_GEN_Quark_3_phi;   //!
   TBranch        *b_GEN_Quark_3_E;   //!
   TBranch        *b_GEN_Quark_3_M;   //!
   TBranch        *b_GEN_Quark_3_pdgId;   //!
   TBranch        *b_GEN_Lepton_0_pt;   //!
   TBranch        *b_GEN_Lepton_0_eta;   //!
   TBranch        *b_GEN_Lepton_0_phi;   //!
   TBranch        *b_GEN_Lepton_0_E;   //!
   TBranch        *b_GEN_Lepton_0_M;   //!
   TBranch        *b_GEN_Lepton_0_pdgId;   //!
   TBranch        *b_GEN_Lepton_1_pt;   //!
   TBranch        *b_GEN_Lepton_1_eta;   //!
   TBranch        *b_GEN_Lepton_1_phi;   //!
   TBranch        *b_GEN_Lepton_1_E;   //!
   TBranch        *b_GEN_Lepton_1_M;   //!
   TBranch        *b_GEN_Lepton_1_pdgId;   //!
   TBranch        *b_GEN_Neutrino_0_pt;   //!
   TBranch        *b_GEN_Neutrino_0_eta;   //!
   TBranch        *b_GEN_Neutrino_0_phi;   //!
   TBranch        *b_GEN_Neutrino_0_E;   //!
   TBranch        *b_GEN_Neutrino_0_M;   //!
   TBranch        *b_GEN_Neutrino_0_pdgId;   //!
   TBranch        *b_GEN_Neutrino_1_pt;   //!
   TBranch        *b_GEN_Neutrino_1_eta;   //!
   TBranch        *b_GEN_Neutrino_1_phi;   //!
   TBranch        *b_GEN_Neutrino_1_E;   //!
   TBranch        *b_GEN_Neutrino_1_M;   //!
   TBranch        *b_GEN_Neutrino_1_pdgId;   //!
   TBranch        *b_genMhh;   //!
   TBranch        *b_genCosThetaStar_CS;   //!
   TBranch        *b_genAbsCosThetaStar_CS;   //!
   TBranch        *b_Leading_Photon_MVA;   //!
   TBranch        *b_Subleading_Photon_MVA;   //!
   TBranch        *b_Leading_Photon_SC_eta;   //!
   TBranch        *b_Leading_Photon_initE;   //!
   TBranch        *b_Leading_Photon_r9;   //!
   TBranch        *b_Leading_Photon_full5x5_r9;   //!
   TBranch        *b_Leading_Photon_Hgg_MVA;   //!
   TBranch        *b_Leading_Photon_passElectronVeto;   //!
   TBranch        *b_Leading_Photon_hasPixelSeed;   //!
   TBranch        *b_Subleading_Photon_SC_eta;   //!
   TBranch        *b_Subleading_Photon_r9;   //!
   TBranch        *b_Subleading_Photon_full5x5_r9;   //!
   TBranch        *b_Subleading_Photon_passElectronVeto;   //!
   TBranch        *b_Subleading_Photon_hasPixelSeed;   //!
   TBranch        *b_Leading_Photon_E;   //!
   TBranch        *b_Leading_Photon_pt;   //!
   TBranch        *b_Leading_Photon_px;   //!
   TBranch        *b_Leading_Photon_py;   //!
   TBranch        *b_Leading_Photon_pz;   //!
   TBranch        *b_Leading_Photon_eta;   //!
   TBranch        *b_Leading_Photon_phi;   //!
   TBranch        *b_Subleading_Photon_E;   //!
   TBranch        *b_Subleading_Photon_pt;   //!
   TBranch        *b_Subleading_Photon_px;   //!
   TBranch        *b_Subleading_Photon_py;   //!
   TBranch        *b_Subleading_Photon_pz;   //!
   TBranch        *b_Subleading_Photon_eta;   //!
   TBranch        *b_Subleading_Photon_phi;   //!
   TBranch        *b_Electron_E;   //!
   TBranch        *b_Electron_pt;   //!
   TBranch        *b_Electron_px;   //!
   TBranch        *b_Electron_py;   //!
   TBranch        *b_Electron_pz;   //!
   TBranch        *b_Electron_eta;   //!
   TBranch        *b_Electron_phi;   //!
   TBranch        *b_Muon_E;   //!
   TBranch        *b_Muon_pt;   //!
   TBranch        *b_Muon_px;   //!
   TBranch        *b_Muon_py;   //!
   TBranch        *b_Muon_pz;   //!
   TBranch        *b_Muon_eta;   //!
   TBranch        *b_Muon_phi;   //!
   TBranch        *b_MET_E;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_px;   //!
   TBranch        *b_MET_py;   //!
   TBranch        *b_MET_pz;   //!
   TBranch        *b_MET_eta;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_Leading_Jet_E;   //!
   TBranch        *b_Leading_Jet_pt;   //!
   TBranch        *b_Leading_Jet_px;   //!
   TBranch        *b_Leading_Jet_py;   //!
   TBranch        *b_Leading_Jet_pz;   //!
   TBranch        *b_Leading_Jet_eta;   //!
   TBranch        *b_Leading_Jet_phi;   //!
   TBranch        *b_Subleading_Jet_E;   //!
   TBranch        *b_Subleading_Jet_pt;   //!
   TBranch        *b_Subleading_Jet_px;   //!
   TBranch        *b_Subleading_Jet_py;   //!
   TBranch        *b_Subleading_Jet_pz;   //!
   TBranch        *b_Subleading_Jet_eta;   //!
   TBranch        *b_Subleading_Jet_phi;   //!
   TBranch        *b_Sub2leading_Jet_E;   //!
   TBranch        *b_Sub2leading_Jet_pt;   //!
   TBranch        *b_Sub2leading_Jet_px;   //!
   TBranch        *b_Sub2leading_Jet_py;   //!
   TBranch        *b_Sub2leading_Jet_pz;   //!
   TBranch        *b_Sub2leading_Jet_eta;   //!
   TBranch        *b_Sub2leading_Jet_phi;   //!
   TBranch        *b_Sub3leading_Jet_E;   //!
   TBranch        *b_Sub3leading_Jet_pt;   //!
   TBranch        *b_Sub3leading_Jet_px;   //!
   TBranch        *b_Sub3leading_Jet_py;   //!
   TBranch        *b_Sub3leading_Jet_pz;   //!
   TBranch        *b_Sub3leading_Jet_eta;   //!
   TBranch        *b_Sub3leading_Jet_phi;   //!
   TBranch        *b_N_allElectrons;   //!
   TBranch        *b_allElectrons_0_E;   //!
   TBranch        *b_allElectrons_1_E;   //!
   TBranch        *b_allElectrons_2_E;   //!
   TBranch        *b_allElectrons_3_E;   //!
   TBranch        *b_allElectrons_4_E;   //!
   TBranch        *b_allElectrons_0_pt;   //!
   TBranch        *b_allElectrons_1_pt;   //!
   TBranch        *b_allElectrons_2_pt;   //!
   TBranch        *b_allElectrons_3_pt;   //!
   TBranch        *b_allElectrons_4_pt;   //!
   TBranch        *b_allElectrons_0_px;   //!
   TBranch        *b_allElectrons_1_px;   //!
   TBranch        *b_allElectrons_2_px;   //!
   TBranch        *b_allElectrons_3_px;   //!
   TBranch        *b_allElectrons_4_px;   //!
   TBranch        *b_allElectrons_0_py;   //!
   TBranch        *b_allElectrons_1_py;   //!
   TBranch        *b_allElectrons_2_py;   //!
   TBranch        *b_allElectrons_3_py;   //!
   TBranch        *b_allElectrons_4_py;   //!
   TBranch        *b_allElectrons_0_pz;   //!
   TBranch        *b_allElectrons_1_pz;   //!
   TBranch        *b_allElectrons_2_pz;   //!
   TBranch        *b_allElectrons_3_pz;   //!
   TBranch        *b_allElectrons_4_pz;   //!
   TBranch        *b_allElectrons_0_eta;   //!
   TBranch        *b_allElectrons_1_eta;   //!
   TBranch        *b_allElectrons_2_eta;   //!
   TBranch        *b_allElectrons_3_eta;   //!
   TBranch        *b_allElectrons_4_eta;   //!
   TBranch        *b_allElectrons_0_phi;   //!
   TBranch        *b_allElectrons_1_phi;   //!
   TBranch        *b_allElectrons_2_phi;   //!
   TBranch        *b_allElectrons_3_phi;   //!
   TBranch        *b_allElectrons_4_phi;   //!
   TBranch        *b_allElectrons_0_passLooseId;   //!
   TBranch        *b_allElectrons_1_passLooseId;   //!
   TBranch        *b_allElectrons_2_passLooseId;   //!
   TBranch        *b_allElectrons_3_passLooseId;   //!
   TBranch        *b_allElectrons_4_passLooseId;   //!
   TBranch        *b_allElectrons_0_passMediumId;   //!
   TBranch        *b_allElectrons_1_passMediumId;   //!
   TBranch        *b_allElectrons_2_passMediumId;   //!
   TBranch        *b_allElectrons_3_passMediumId;   //!
   TBranch        *b_allElectrons_4_passMediumId;   //!
   TBranch        *b_allElectrons_0_passTightId;   //!
   TBranch        *b_allElectrons_1_passTightId;   //!
   TBranch        *b_allElectrons_2_passTightId;   //!
   TBranch        *b_allElectrons_3_passTightId;   //!
   TBranch        *b_allElectrons_4_passTightId;   //!
   TBranch        *b_allElectrons_0_passMVALooseId;   //!
   TBranch        *b_allElectrons_1_passMVALooseId;   //!
   TBranch        *b_allElectrons_2_passMVALooseId;   //!
   TBranch        *b_allElectrons_3_passMVALooseId;   //!
   TBranch        *b_allElectrons_4_passMVALooseId;   //!
   TBranch        *b_allElectrons_0_passMVAMediumId;   //!
   TBranch        *b_allElectrons_1_passMVAMediumId;   //!
   TBranch        *b_allElectrons_2_passMVAMediumId;   //!
   TBranch        *b_allElectrons_3_passMVAMediumId;   //!
   TBranch        *b_allElectrons_4_passMVAMediumId;   //!
   TBranch        *b_allElectrons_0_passMVATightId;   //!
   TBranch        *b_allElectrons_1_passMVATightId;   //!
   TBranch        *b_allElectrons_2_passMVATightId;   //!
   TBranch        *b_allElectrons_3_passMVATightId;   //!
   TBranch        *b_allElectrons_4_passMVATightId;   //!
   TBranch        *b_N_allMuons;   //!
   TBranch        *b_allMuons_0_E;   //!
   TBranch        *b_allMuons_1_E;   //!
   TBranch        *b_allMuons_2_E;   //!
   TBranch        *b_allMuons_3_E;   //!
   TBranch        *b_allMuons_4_E;   //!
   TBranch        *b_allMuons_0_pt;   //!
   TBranch        *b_allMuons_1_pt;   //!
   TBranch        *b_allMuons_2_pt;   //!
   TBranch        *b_allMuons_3_pt;   //!
   TBranch        *b_allMuons_4_pt;   //!
   TBranch        *b_allMuons_0_px;   //!
   TBranch        *b_allMuons_1_px;   //!
   TBranch        *b_allMuons_2_px;   //!
   TBranch        *b_allMuons_3_px;   //!
   TBranch        *b_allMuons_4_px;   //!
   TBranch        *b_allMuons_0_py;   //!
   TBranch        *b_allMuons_1_py;   //!
   TBranch        *b_allMuons_2_py;   //!
   TBranch        *b_allMuons_3_py;   //!
   TBranch        *b_allMuons_4_py;   //!
   TBranch        *b_allMuons_0_pz;   //!
   TBranch        *b_allMuons_1_pz;   //!
   TBranch        *b_allMuons_2_pz;   //!
   TBranch        *b_allMuons_3_pz;   //!
   TBranch        *b_allMuons_4_pz;   //!
   TBranch        *b_allMuons_0_eta;   //!
   TBranch        *b_allMuons_1_eta;   //!
   TBranch        *b_allMuons_2_eta;   //!
   TBranch        *b_allMuons_3_eta;   //!
   TBranch        *b_allMuons_4_eta;   //!
   TBranch        *b_allMuons_0_phi;   //!
   TBranch        *b_allMuons_1_phi;   //!
   TBranch        *b_allMuons_2_phi;   //!
   TBranch        *b_allMuons_3_phi;   //!
   TBranch        *b_allMuons_4_phi;   //!
   TBranch        *b_N_allJets;   //!
   TBranch        *b_allJets_0_E;   //!
   TBranch        *b_allJets_1_E;   //!
   TBranch        *b_allJets_2_E;   //!
   TBranch        *b_allJets_3_E;   //!
   TBranch        *b_allJets_4_E;   //!
   TBranch        *b_allJets_5_E;   //!
   TBranch        *b_allJets_6_E;   //!
   TBranch        *b_allJets_7_E;   //!
   TBranch        *b_allJets_8_E;   //!
   TBranch        *b_allJets_9_E;   //!
   TBranch        *b_allJets_0_pt;   //!
   TBranch        *b_allJets_1_pt;   //!
   TBranch        *b_allJets_2_pt;   //!
   TBranch        *b_allJets_3_pt;   //!
   TBranch        *b_allJets_4_pt;   //!
   TBranch        *b_allJets_5_pt;   //!
   TBranch        *b_allJets_6_pt;   //!
   TBranch        *b_allJets_7_pt;   //!
   TBranch        *b_allJets_8_pt;   //!
   TBranch        *b_allJets_9_pt;   //!
   TBranch        *b_allJets_0_px;   //!
   TBranch        *b_allJets_1_px;   //!
   TBranch        *b_allJets_2_px;   //!
   TBranch        *b_allJets_3_px;   //!
   TBranch        *b_allJets_4_px;   //!
   TBranch        *b_allJets_5_px;   //!
   TBranch        *b_allJets_6_px;   //!
   TBranch        *b_allJets_7_px;   //!
   TBranch        *b_allJets_8_px;   //!
   TBranch        *b_allJets_9_px;   //!
   TBranch        *b_allJets_0_py;   //!
   TBranch        *b_allJets_1_py;   //!
   TBranch        *b_allJets_2_py;   //!
   TBranch        *b_allJets_3_py;   //!
   TBranch        *b_allJets_4_py;   //!
   TBranch        *b_allJets_5_py;   //!
   TBranch        *b_allJets_6_py;   //!
   TBranch        *b_allJets_7_py;   //!
   TBranch        *b_allJets_8_py;   //!
   TBranch        *b_allJets_9_py;   //!
   TBranch        *b_allJets_0_pz;   //!
   TBranch        *b_allJets_1_pz;   //!
   TBranch        *b_allJets_2_pz;   //!
   TBranch        *b_allJets_3_pz;   //!
   TBranch        *b_allJets_4_pz;   //!
   TBranch        *b_allJets_5_pz;   //!
   TBranch        *b_allJets_6_pz;   //!
   TBranch        *b_allJets_7_pz;   //!
   TBranch        *b_allJets_8_pz;   //!
   TBranch        *b_allJets_9_pz;   //!
   TBranch        *b_allJets_0_eta;   //!
   TBranch        *b_allJets_1_eta;   //!
   TBranch        *b_allJets_2_eta;   //!
   TBranch        *b_allJets_3_eta;   //!
   TBranch        *b_allJets_4_eta;   //!
   TBranch        *b_allJets_5_eta;   //!
   TBranch        *b_allJets_6_eta;   //!
   TBranch        *b_allJets_7_eta;   //!
   TBranch        *b_allJets_8_eta;   //!
   TBranch        *b_allJets_9_eta;   //!
   TBranch        *b_allJets_0_phi;   //!
   TBranch        *b_allJets_1_phi;   //!
   TBranch        *b_allJets_2_phi;   //!
   TBranch        *b_allJets_3_phi;   //!
   TBranch        *b_allJets_4_phi;   //!
   TBranch        *b_allJets_5_phi;   //!
   TBranch        *b_allJets_6_phi;   //!
   TBranch        *b_allJets_7_phi;   //!
   TBranch        *b_allJets_8_phi;   //!
   TBranch        *b_allJets_9_phi;   //!
   TBranch        *b_allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_allJets_0_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_1_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_2_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_3_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_4_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_5_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_6_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_7_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_8_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_9_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_allJets_0_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_1_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_2_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_3_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_4_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_5_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_6_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_7_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_8_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_9_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_N_goodElectrons;   //!
   TBranch        *b_goodElectrons_0_E;   //!
   TBranch        *b_goodElectrons_1_E;   //!
   TBranch        *b_goodElectrons_2_E;   //!
   TBranch        *b_goodElectrons_3_E;   //!
   TBranch        *b_goodElectrons_4_E;   //!
   TBranch        *b_goodElectrons_5_E;   //!
   TBranch        *b_goodElectrons_6_E;   //!
   TBranch        *b_goodElectrons_7_E;   //!
   TBranch        *b_goodElectrons_8_E;   //!
   TBranch        *b_goodElectrons_9_E;   //!
   TBranch        *b_goodElectrons_0_pt;   //!
   TBranch        *b_goodElectrons_1_pt;   //!
   TBranch        *b_goodElectrons_2_pt;   //!
   TBranch        *b_goodElectrons_3_pt;   //!
   TBranch        *b_goodElectrons_4_pt;   //!
   TBranch        *b_goodElectrons_5_pt;   //!
   TBranch        *b_goodElectrons_6_pt;   //!
   TBranch        *b_goodElectrons_7_pt;   //!
   TBranch        *b_goodElectrons_8_pt;   //!
   TBranch        *b_goodElectrons_9_pt;   //!
   TBranch        *b_goodElectrons_0_px;   //!
   TBranch        *b_goodElectrons_1_px;   //!
   TBranch        *b_goodElectrons_2_px;   //!
   TBranch        *b_goodElectrons_3_px;   //!
   TBranch        *b_goodElectrons_4_px;   //!
   TBranch        *b_goodElectrons_5_px;   //!
   TBranch        *b_goodElectrons_6_px;   //!
   TBranch        *b_goodElectrons_7_px;   //!
   TBranch        *b_goodElectrons_8_px;   //!
   TBranch        *b_goodElectrons_9_px;   //!
   TBranch        *b_goodElectrons_0_py;   //!
   TBranch        *b_goodElectrons_1_py;   //!
   TBranch        *b_goodElectrons_2_py;   //!
   TBranch        *b_goodElectrons_3_py;   //!
   TBranch        *b_goodElectrons_4_py;   //!
   TBranch        *b_goodElectrons_5_py;   //!
   TBranch        *b_goodElectrons_6_py;   //!
   TBranch        *b_goodElectrons_7_py;   //!
   TBranch        *b_goodElectrons_8_py;   //!
   TBranch        *b_goodElectrons_9_py;   //!
   TBranch        *b_goodElectrons_0_pz;   //!
   TBranch        *b_goodElectrons_1_pz;   //!
   TBranch        *b_goodElectrons_2_pz;   //!
   TBranch        *b_goodElectrons_3_pz;   //!
   TBranch        *b_goodElectrons_4_pz;   //!
   TBranch        *b_goodElectrons_5_pz;   //!
   TBranch        *b_goodElectrons_6_pz;   //!
   TBranch        *b_goodElectrons_7_pz;   //!
   TBranch        *b_goodElectrons_8_pz;   //!
   TBranch        *b_goodElectrons_9_pz;   //!
   TBranch        *b_goodElectrons_0_eta;   //!
   TBranch        *b_goodElectrons_1_eta;   //!
   TBranch        *b_goodElectrons_2_eta;   //!
   TBranch        *b_goodElectrons_3_eta;   //!
   TBranch        *b_goodElectrons_4_eta;   //!
   TBranch        *b_goodElectrons_5_eta;   //!
   TBranch        *b_goodElectrons_6_eta;   //!
   TBranch        *b_goodElectrons_7_eta;   //!
   TBranch        *b_goodElectrons_8_eta;   //!
   TBranch        *b_goodElectrons_9_eta;   //!
   TBranch        *b_goodElectrons_0_phi;   //!
   TBranch        *b_goodElectrons_1_phi;   //!
   TBranch        *b_goodElectrons_2_phi;   //!
   TBranch        *b_goodElectrons_3_phi;   //!
   TBranch        *b_goodElectrons_4_phi;   //!
   TBranch        *b_goodElectrons_5_phi;   //!
   TBranch        *b_goodElectrons_6_phi;   //!
   TBranch        *b_goodElectrons_7_phi;   //!
   TBranch        *b_goodElectrons_8_phi;   //!
   TBranch        *b_goodElectrons_9_phi;   //!
   TBranch        *b_goodElectrons_0_passLooseId;   //!
   TBranch        *b_goodElectrons_1_passLooseId;   //!
   TBranch        *b_goodElectrons_2_passLooseId;   //!
   TBranch        *b_goodElectrons_3_passLooseId;   //!
   TBranch        *b_goodElectrons_4_passLooseId;   //!
   TBranch        *b_goodElectrons_5_passLooseId;   //!
   TBranch        *b_goodElectrons_6_passLooseId;   //!
   TBranch        *b_goodElectrons_7_passLooseId;   //!
   TBranch        *b_goodElectrons_8_passLooseId;   //!
   TBranch        *b_goodElectrons_9_passLooseId;   //!
   TBranch        *b_goodElectrons_0_passMediumId;   //!
   TBranch        *b_goodElectrons_1_passMediumId;   //!
   TBranch        *b_goodElectrons_2_passMediumId;   //!
   TBranch        *b_goodElectrons_3_passMediumId;   //!
   TBranch        *b_goodElectrons_4_passMediumId;   //!
   TBranch        *b_goodElectrons_5_passMediumId;   //!
   TBranch        *b_goodElectrons_6_passMediumId;   //!
   TBranch        *b_goodElectrons_7_passMediumId;   //!
   TBranch        *b_goodElectrons_8_passMediumId;   //!
   TBranch        *b_goodElectrons_9_passMediumId;   //!
   TBranch        *b_goodElectrons_0_passTightId;   //!
   TBranch        *b_goodElectrons_1_passTightId;   //!
   TBranch        *b_goodElectrons_2_passTightId;   //!
   TBranch        *b_goodElectrons_3_passTightId;   //!
   TBranch        *b_goodElectrons_4_passTightId;   //!
   TBranch        *b_goodElectrons_5_passTightId;   //!
   TBranch        *b_goodElectrons_6_passTightId;   //!
   TBranch        *b_goodElectrons_7_passTightId;   //!
   TBranch        *b_goodElectrons_8_passTightId;   //!
   TBranch        *b_goodElectrons_9_passTightId;   //!
   TBranch        *b_goodElectrons_0_passMVALooseId;   //!
   TBranch        *b_goodElectrons_1_passMVALooseId;   //!
   TBranch        *b_goodElectrons_2_passMVALooseId;   //!
   TBranch        *b_goodElectrons_3_passMVALooseId;   //!
   TBranch        *b_goodElectrons_4_passMVALooseId;   //!
   TBranch        *b_goodElectrons_5_passMVALooseId;   //!
   TBranch        *b_goodElectrons_6_passMVALooseId;   //!
   TBranch        *b_goodElectrons_7_passMVALooseId;   //!
   TBranch        *b_goodElectrons_8_passMVALooseId;   //!
   TBranch        *b_goodElectrons_9_passMVALooseId;   //!
   TBranch        *b_goodElectrons_0_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_1_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_2_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_3_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_4_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_5_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_6_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_7_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_8_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_9_passMVAMediumId;   //!
   TBranch        *b_goodElectrons_0_passMVATightId;   //!
   TBranch        *b_goodElectrons_1_passMVATightId;   //!
   TBranch        *b_goodElectrons_2_passMVATightId;   //!
   TBranch        *b_goodElectrons_3_passMVATightId;   //!
   TBranch        *b_goodElectrons_4_passMVATightId;   //!
   TBranch        *b_goodElectrons_5_passMVATightId;   //!
   TBranch        *b_goodElectrons_6_passMVATightId;   //!
   TBranch        *b_goodElectrons_7_passMVATightId;   //!
   TBranch        *b_goodElectrons_8_passMVATightId;   //!
   TBranch        *b_goodElectrons_9_passMVATightId;   //!
   TBranch        *b_N_goodMuons;   //!
   TBranch        *b_goodMuons_0_E;   //!
   TBranch        *b_goodMuons_1_E;   //!
   TBranch        *b_goodMuons_2_E;   //!
   TBranch        *b_goodMuons_3_E;   //!
   TBranch        *b_goodMuons_4_E;   //!
   TBranch        *b_goodMuons_5_E;   //!
   TBranch        *b_goodMuons_6_E;   //!
   TBranch        *b_goodMuons_7_E;   //!
   TBranch        *b_goodMuons_8_E;   //!
   TBranch        *b_goodMuons_9_E;   //!
   TBranch        *b_goodMuons_0_pt;   //!
   TBranch        *b_goodMuons_1_pt;   //!
   TBranch        *b_goodMuons_2_pt;   //!
   TBranch        *b_goodMuons_3_pt;   //!
   TBranch        *b_goodMuons_4_pt;   //!
   TBranch        *b_goodMuons_5_pt;   //!
   TBranch        *b_goodMuons_6_pt;   //!
   TBranch        *b_goodMuons_7_pt;   //!
   TBranch        *b_goodMuons_8_pt;   //!
   TBranch        *b_goodMuons_9_pt;   //!
   TBranch        *b_goodMuons_0_px;   //!
   TBranch        *b_goodMuons_1_px;   //!
   TBranch        *b_goodMuons_2_px;   //!
   TBranch        *b_goodMuons_3_px;   //!
   TBranch        *b_goodMuons_4_px;   //!
   TBranch        *b_goodMuons_5_px;   //!
   TBranch        *b_goodMuons_6_px;   //!
   TBranch        *b_goodMuons_7_px;   //!
   TBranch        *b_goodMuons_8_px;   //!
   TBranch        *b_goodMuons_9_px;   //!
   TBranch        *b_goodMuons_0_py;   //!
   TBranch        *b_goodMuons_1_py;   //!
   TBranch        *b_goodMuons_2_py;   //!
   TBranch        *b_goodMuons_3_py;   //!
   TBranch        *b_goodMuons_4_py;   //!
   TBranch        *b_goodMuons_5_py;   //!
   TBranch        *b_goodMuons_6_py;   //!
   TBranch        *b_goodMuons_7_py;   //!
   TBranch        *b_goodMuons_8_py;   //!
   TBranch        *b_goodMuons_9_py;   //!
   TBranch        *b_goodMuons_0_pz;   //!
   TBranch        *b_goodMuons_1_pz;   //!
   TBranch        *b_goodMuons_2_pz;   //!
   TBranch        *b_goodMuons_3_pz;   //!
   TBranch        *b_goodMuons_4_pz;   //!
   TBranch        *b_goodMuons_5_pz;   //!
   TBranch        *b_goodMuons_6_pz;   //!
   TBranch        *b_goodMuons_7_pz;   //!
   TBranch        *b_goodMuons_8_pz;   //!
   TBranch        *b_goodMuons_9_pz;   //!
   TBranch        *b_goodMuons_0_eta;   //!
   TBranch        *b_goodMuons_1_eta;   //!
   TBranch        *b_goodMuons_2_eta;   //!
   TBranch        *b_goodMuons_3_eta;   //!
   TBranch        *b_goodMuons_4_eta;   //!
   TBranch        *b_goodMuons_5_eta;   //!
   TBranch        *b_goodMuons_6_eta;   //!
   TBranch        *b_goodMuons_7_eta;   //!
   TBranch        *b_goodMuons_8_eta;   //!
   TBranch        *b_goodMuons_9_eta;   //!
   TBranch        *b_goodMuons_0_phi;   //!
   TBranch        *b_goodMuons_1_phi;   //!
   TBranch        *b_goodMuons_2_phi;   //!
   TBranch        *b_goodMuons_3_phi;   //!
   TBranch        *b_goodMuons_4_phi;   //!
   TBranch        *b_goodMuons_5_phi;   //!
   TBranch        *b_goodMuons_6_phi;   //!
   TBranch        *b_goodMuons_7_phi;   //!
   TBranch        *b_goodMuons_8_phi;   //!
   TBranch        *b_goodMuons_9_phi;   //!
   TBranch        *b_N_goodJets;   //!
   TBranch        *b_goodJets_0_E;   //!
   TBranch        *b_goodJets_1_E;   //!
   TBranch        *b_goodJets_2_E;   //!
   TBranch        *b_goodJets_3_E;   //!
   TBranch        *b_goodJets_4_E;   //!
   TBranch        *b_goodJets_5_E;   //!
   TBranch        *b_goodJets_6_E;   //!
   TBranch        *b_goodJets_7_E;   //!
   TBranch        *b_goodJets_8_E;   //!
   TBranch        *b_goodJets_9_E;   //!
   TBranch        *b_goodJets_0_pt;   //!
   TBranch        *b_goodJets_1_pt;   //!
   TBranch        *b_goodJets_2_pt;   //!
   TBranch        *b_goodJets_3_pt;   //!
   TBranch        *b_goodJets_4_pt;   //!
   TBranch        *b_goodJets_5_pt;   //!
   TBranch        *b_goodJets_6_pt;   //!
   TBranch        *b_goodJets_7_pt;   //!
   TBranch        *b_goodJets_8_pt;   //!
   TBranch        *b_goodJets_9_pt;   //!
   TBranch        *b_goodJets_0_px;   //!
   TBranch        *b_goodJets_1_px;   //!
   TBranch        *b_goodJets_2_px;   //!
   TBranch        *b_goodJets_3_px;   //!
   TBranch        *b_goodJets_4_px;   //!
   TBranch        *b_goodJets_5_px;   //!
   TBranch        *b_goodJets_6_px;   //!
   TBranch        *b_goodJets_7_px;   //!
   TBranch        *b_goodJets_8_px;   //!
   TBranch        *b_goodJets_9_px;   //!
   TBranch        *b_goodJets_0_py;   //!
   TBranch        *b_goodJets_1_py;   //!
   TBranch        *b_goodJets_2_py;   //!
   TBranch        *b_goodJets_3_py;   //!
   TBranch        *b_goodJets_4_py;   //!
   TBranch        *b_goodJets_5_py;   //!
   TBranch        *b_goodJets_6_py;   //!
   TBranch        *b_goodJets_7_py;   //!
   TBranch        *b_goodJets_8_py;   //!
   TBranch        *b_goodJets_9_py;   //!
   TBranch        *b_goodJets_0_pz;   //!
   TBranch        *b_goodJets_1_pz;   //!
   TBranch        *b_goodJets_2_pz;   //!
   TBranch        *b_goodJets_3_pz;   //!
   TBranch        *b_goodJets_4_pz;   //!
   TBranch        *b_goodJets_5_pz;   //!
   TBranch        *b_goodJets_6_pz;   //!
   TBranch        *b_goodJets_7_pz;   //!
   TBranch        *b_goodJets_8_pz;   //!
   TBranch        *b_goodJets_9_pz;   //!
   TBranch        *b_goodJets_0_eta;   //!
   TBranch        *b_goodJets_1_eta;   //!
   TBranch        *b_goodJets_2_eta;   //!
   TBranch        *b_goodJets_3_eta;   //!
   TBranch        *b_goodJets_4_eta;   //!
   TBranch        *b_goodJets_5_eta;   //!
   TBranch        *b_goodJets_6_eta;   //!
   TBranch        *b_goodJets_7_eta;   //!
   TBranch        *b_goodJets_8_eta;   //!
   TBranch        *b_goodJets_9_eta;   //!
   TBranch        *b_goodJets_0_phi;   //!
   TBranch        *b_goodJets_1_phi;   //!
   TBranch        *b_goodJets_2_phi;   //!
   TBranch        *b_goodJets_3_phi;   //!
   TBranch        *b_goodJets_4_phi;   //!
   TBranch        *b_goodJets_5_phi;   //!
   TBranch        *b_goodJets_6_phi;   //!
   TBranch        *b_goodJets_7_phi;   //!
   TBranch        *b_goodJets_8_phi;   //!
   TBranch        *b_goodJets_9_phi;   //!
   TBranch        *b_goodJets_0_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_0_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_0_PassTightJetPUID;   //!
   TBranch        *b_goodJets_1_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_1_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_1_PassTightJetPUID;   //!
   TBranch        *b_goodJets_2_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_2_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_2_PassTightJetPUID;   //!
   TBranch        *b_goodJets_3_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_3_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_3_PassTightJetPUID;   //!
   TBranch        *b_goodJets_4_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_4_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_4_PassTightJetPUID;   //!
   TBranch        *b_goodJets_5_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_5_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_5_PassTightJetPUID;   //!
   TBranch        *b_goodJets_6_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_6_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_6_PassTightJetPUID;   //!
   TBranch        *b_goodJets_7_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_7_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_7_PassTightJetPUID;   //!
   TBranch        *b_goodJets_8_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_8_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_8_PassTightJetPUID;   //!
   TBranch        *b_goodJets_9_PassLooseJetPUID;   //!
   TBranch        *b_goodJets_9_PassMediumJetPUID;   //!
   TBranch        *b_goodJets_9_PassTightJetPUID;   //!
   TBranch        *b_goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb;   //!
   TBranch        *b_goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb;   //!
   TBranch        *b_goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;   //!
   TBranch        *b_goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb;   //!
   TBranch        *b_goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;   //!
   TBranch        *b_Leading_Photon_genMatchType;   //!
   TBranch        *b_Subleading_Photon_genMatchType;   //!
   TBranch        *b_dipho_MVA;   //!
   TBranch        *b_dipho_pt;   //!
   TBranch        *b_allMuons_0_isLooseMuon;   //!
   TBranch        *b_allMuons_0_isMediumMuon;   //!
   TBranch        *b_allMuons_0_isTightMuon;   //!
   TBranch        *b_allMuons_0_isSoftMuon;   //!
   TBranch        *b_allMuons_0_isHighPtMuon;   //!
   TBranch        *b_allMuons_0_muonIso;   //!
   TBranch        *b_allMuons_1_isLooseMuon;   //!
   TBranch        *b_allMuons_1_isMediumMuon;   //!
   TBranch        *b_allMuons_1_isTightMuon;   //!
   TBranch        *b_allMuons_1_isSoftMuon;   //!
   TBranch        *b_allMuons_1_isHighPtMuon;   //!
   TBranch        *b_allMuons_1_muonIso;   //!
   TBranch        *b_allMuons_2_isLooseMuon;   //!
   TBranch        *b_allMuons_2_isMediumMuon;   //!
   TBranch        *b_allMuons_2_isTightMuon;   //!
   TBranch        *b_allMuons_2_isSoftMuon;   //!
   TBranch        *b_allMuons_2_isHighPtMuon;   //!
   TBranch        *b_allMuons_2_muonIso;   //!
   TBranch        *b_allMuons_3_isLooseMuon;   //!
   TBranch        *b_allMuons_3_isMediumMuon;   //!
   TBranch        *b_allMuons_3_isTightMuon;   //!
   TBranch        *b_allMuons_3_isSoftMuon;   //!
   TBranch        *b_allMuons_3_isHighPtMuon;   //!
   TBranch        *b_allMuons_3_muonIso;   //!
   TBranch        *b_allMuons_4_isLooseMuon;   //!
   TBranch        *b_allMuons_4_isMediumMuon;   //!
   TBranch        *b_allMuons_4_isTightMuon;   //!
   TBranch        *b_allMuons_4_isSoftMuon;   //!
   TBranch        *b_allMuons_4_isHighPtMuon;   //!
   TBranch        *b_allMuons_4_muonIso;   //!
   TBranch        *b_allJets_0_passLoose;   //!
   TBranch        *b_allJets_0_passTight;   //!
   TBranch        *b_allJets_0_passTight2017;   //!
   TBranch        *b_allJets_0_passTight2018;   //!
   TBranch        *b_allJets_1_passLoose;   //!
   TBranch        *b_allJets_1_passTight;   //!
   TBranch        *b_allJets_1_passTight2017;   //!
   TBranch        *b_allJets_1_passTight2018;   //!
   TBranch        *b_allJets_2_passLoose;   //!
   TBranch        *b_allJets_2_passTight;   //!
   TBranch        *b_allJets_2_passTight2017;   //!
   TBranch        *b_allJets_2_passTight2018;   //!
   TBranch        *b_allJets_3_passLoose;   //!
   TBranch        *b_allJets_3_passTight;   //!
   TBranch        *b_allJets_3_passTight2017;   //!
   TBranch        *b_allJets_3_passTight2018;   //!
   TBranch        *b_allJets_4_passLoose;   //!
   TBranch        *b_allJets_4_passTight;   //!
   TBranch        *b_allJets_4_passTight2017;   //!
   TBranch        *b_allJets_4_passTight2018;   //!
   TBranch        *b_W1Candidate_E;   //!
   TBranch        *b_W1Candidate_M;   //!
   TBranch        *b_W1Candidate_pt;   //!
   TBranch        *b_W1Candidate_px;   //!
   TBranch        *b_W1Candidate_py;   //!
   TBranch        *b_W1Candidate_pz;   //!
   TBranch        *b_W1Candidate_eta;   //!
   TBranch        *b_W1Candidate_phi;   //!
   TBranch        *b_W2Candidate_E;   //!
   TBranch        *b_W2Candidate_M;   //!
   TBranch        *b_W2Candidate_pt;   //!
   TBranch        *b_W2Candidate_px;   //!
   TBranch        *b_W2Candidate_py;   //!
   TBranch        *b_W2Candidate_pz;   //!
   TBranch        *b_W2Candidate_eta;   //!
   TBranch        *b_W2Candidate_phi;   //!
   TBranch        *b_HWWCandidate_E;   //!
   TBranch        *b_HWWCandidate_M;   //!
   TBranch        *b_HWWCandidate_pt;   //!
   TBranch        *b_HWWCandidate_px;   //!
   TBranch        *b_HWWCandidate_py;   //!
   TBranch        *b_HWWCandidate_pz;   //!
   TBranch        *b_HWWCandidate_eta;   //!
   TBranch        *b_HWWCandidate_phi;   //!
   TBranch        *b_HGGCandidate_E;   //!
   TBranch        *b_HGGCandidate_M;   //!
   TBranch        *b_HGGCandidate_pt;   //!
   TBranch        *b_HGGCandidate_px;   //!
   TBranch        *b_HGGCandidate_py;   //!
   TBranch        *b_HGGCandidate_pz;   //!
   TBranch        *b_HGGCandidate_eta;   //!
   TBranch        *b_HGGCandidate_phi;   //!
   TBranch        *b_HHCandidate_E;   //!
   TBranch        *b_HHCandidate_M;   //!
   TBranch        *b_HHCandidate_pt;   //!
   TBranch        *b_HHCandidate_px;   //!
   TBranch        *b_HHCandidate_py;   //!
   TBranch        *b_HHCandidate_pz;   //!
   TBranch        *b_HHCandidate_eta;   //!
   TBranch        *b_HHCandidate_phi;   //!
   TBranch        *b_DeltaEta_HH;   //!
   TBranch        *b_DeltaPhi_HH;   //!
   TBranch        *b_DeltaR_HH;   //!
   TBranch        *b_cosThetaHH;   //!
   TBranch        *b_cosThetaWW;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_processIndex;   //!
   TBranch        *b_run;   //!
   // TBranch        *b_nvtx;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_puweight;   //!
   TBranch        *b_weight_NLO_SM;   //!
   TBranch        *b_PhotonID_min;   //!
   TBranch        *b_PhotonID_max;   //!
   TBranch        *b_New_Leading_Jet_E;   //!
   TBranch        *b_New_Leading_Jet_pt;   //!
   TBranch        *b_New_Leading_Jet_px;   //!
   TBranch        *b_New_Leading_Jet_py;   //!
   TBranch        *b_New_Leading_Jet_pz;   //!
   TBranch        *b_New_Leading_Jet_eta;   //!
   TBranch        *b_New_Leading_Jet_phi;   //!
   TBranch        *b_New_Subleading_Jet_E;   //!
   TBranch        *b_New_Subleading_Jet_pt;   //!
   TBranch        *b_New_Subleading_Jet_px;   //!
   TBranch        *b_New_Subleading_Jet_py;   //!
   TBranch        *b_New_Subleading_Jet_pz;   //!
   TBranch        *b_New_Subleading_Jet_eta;   //!
   TBranch        *b_New_Subleading_Jet_phi;   //!
   TBranch        *b_New_Sub2leading_Jet_E;   //!
   TBranch        *b_New_Sub2leading_Jet_pt;   //!
   TBranch        *b_New_Sub2leading_Jet_px;   //!
   TBranch        *b_New_Sub2leading_Jet_py;   //!
   TBranch        *b_New_Sub2leading_Jet_pz;   //!
   TBranch        *b_New_Sub2leading_Jet_eta;   //!
   TBranch        *b_New_Sub2leading_Jet_phi;   //!
   TBranch        *b_New_Sub3leading_Jet_E;   //!
   TBranch        *b_New_Sub3leading_Jet_pt;   //!
   TBranch        *b_New_Sub3leading_Jet_px;   //!
   TBranch        *b_New_Sub3leading_Jet_py;   //!
   TBranch        *b_New_Sub3leading_Jet_pz;   //!
   TBranch        *b_New_Sub3leading_Jet_eta;   //!
   TBranch        *b_New_Sub3leading_Jet_phi;   //!
   TBranch        *b_New_OnShellW_LeadingJet_bDis;   //!
   TBranch        *b_New_OnShellW_SubLeadingJet_bDis;   //!
   TBranch        *b_New_OffShellW_LeadingJet_bDis;   //!
   TBranch        *b_New_OffShellW_SubLeadingJet_bDis;   //!
   TBranch        *b_New_OnShellW_E;   //!
   TBranch        *b_New_OnShellW_Mass;   //!
   TBranch        *b_New_OnShellW_pt;   //!
   TBranch        *b_New_OnShellW_px;   //!
   TBranch        *b_New_OnShellW_py;   //!
   TBranch        *b_New_OnShellW_pz;   //!
   TBranch        *b_New_OnShellW_eta;   //!
   TBranch        *b_New_OnShellW_phi;   //!
   TBranch        *b_New_OffShellW_E;   //!
   TBranch        *b_New_OffShellW_Mass;   //!
   TBranch        *b_New_OffShellW_pt;   //!
   TBranch        *b_New_OffShellW_px;   //!
   TBranch        *b_New_OffShellW_py;   //!
   TBranch        *b_New_OffShellW_pz;   //!
   TBranch        *b_New_OffShellW_eta;   //!
   TBranch        *b_New_OffShellW_phi;   //!
   TBranch        *b_New_HWW_E;   //!
   TBranch        *b_New_HWW_Mass;   //!
   TBranch        *b_New_HWW_pt;   //!
   TBranch        *b_New_HWW_px;   //!
   TBranch        *b_New_HWW_py;   //!
   TBranch        *b_New_HWW_pz;   //!
   TBranch        *b_New_HWW_eta;   //!
   TBranch        *b_New_HWW_phi;   //!
   TBranch        *b_New_dR_Hgg_Jet1;   //!
   TBranch        *b_New_dR_Hgg_Jet2;   //!
   TBranch        *b_New_dR_Hgg_Jet3;   //!
   TBranch        *b_New_dR_Hgg_Jet4;   //!
   TBranch        *b_New_dPhi_Hgg_Jet1;   //!
   TBranch        *b_New_dPhi_Hgg_Jet2;   //!
   TBranch        *b_New_dPhi_Hgg_Jet3;   //!
   TBranch        *b_New_dPhi_Hgg_Jet4;   //!
   TBranch        *b_New_DPhi_gg;   //!
   TBranch        *b_New_DR_gg;   //!
   TBranch        *b_New_DPhi_HH;   //!
   TBranch        *b_New_DR_HH;   //!
   TBranch        *b_New_minDeltaR_gg4j;   //!
   TBranch        *b_New_maxDeltaR_gg4j;   //!
   TBranch        *b_New_minDeltaR_4j;   //!
   TBranch        *b_New_maxDeltaR_4j;   //!
   TBranch        *b_a_costheta1;   //!
   TBranch        *b_a_costheta2;   //!
   TBranch        *b_a_costhetastar;   //!
   TBranch        *b_a_Phi;   //!
   TBranch        *b_a_Phi1;   //!
   TBranch        *b_CosThetaStar_CS;   //!
   TBranch        *b_CosThetaStar_CS_old;   //!
   TBranch        *b_HelicityCostheta1;   //!
   TBranch        *b_HelicityCostheta2;   //!
   TBranch        *b_New_DRBased_Leading_Jet_E;   //!
   TBranch        *b_New_DRBased_Leading_Jet_pt;   //!
   TBranch        *b_New_DRBased_Leading_Jet_px;   //!
   TBranch        *b_New_DRBased_Leading_Jet_py;   //!
   TBranch        *b_New_DRBased_Leading_Jet_pz;   //!
   TBranch        *b_New_DRBased_Leading_Jet_eta;   //!
   TBranch        *b_New_DRBased_Leading_Jet_phi;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_E;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_pt;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_px;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_py;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_pz;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_eta;   //!
   TBranch        *b_New_DRBased_Subleading_Jet_phi;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_E;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_pt;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_px;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_py;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_pz;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_eta;   //!
   TBranch        *b_New_DRBased_Sub2leading_Jet_phi;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_E;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_pt;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_px;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_py;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_pz;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_eta;   //!
   TBranch        *b_New_DRBased_Sub3leading_Jet_phi;   //!
   TBranch        *b_New_DRBased_OnShellW_LeadingJet_bDis;   //!
   TBranch        *b_New_DRBased_OnShellW_SubLeadingJet_bDis;   //!
   TBranch        *b_New_DRBased_OffShellW_LeadingJet_bDis;   //!
   TBranch        *b_New_DRBased_OffShellW_SubLeadingJet_bDis;   //!
   TBranch        *b_New_DRBased_OnShellW_E;   //!
   TBranch        *b_New_DRBased_OnShellW_Mass;   //!
   TBranch        *b_New_DRBased_OnShellW_pt;   //!
   TBranch        *b_New_DRBased_OnShellW_px;   //!
   TBranch        *b_New_DRBased_OnShellW_py;   //!
   TBranch        *b_New_DRBased_OnShellW_pz;   //!
   TBranch        *b_New_DRBased_OnShellW_eta;   //!
   TBranch        *b_New_DRBased_OnShellW_phi;   //!
   TBranch        *b_New_DRBased_OffShellW_Mass;   //!
   TBranch        *b_New_DRBased_OffShellW_pt;   //!
   TBranch        *b_New_DRBased_OffShellW_px;   //!
   TBranch        *b_New_DRBased_OffShellW_py;   //!
   TBranch        *b_New_DRBased_OffShellW_pz;   //!
   TBranch        *b_New_DRBased_OffShellW_eta;   //!
   TBranch        *b_New_DRBased_OffShellW_phi;   //!
   TBranch        *b_New_DRBased_HWW_Mass;   //!
   TBranch        *b_New_DRBased_HWW_pt;   //!
   TBranch        *b_New_DRBased_HWW_px;   //!
   TBranch        *b_New_DRBased_HWW_py;   //!
   TBranch        *b_New_DRBased_HWW_pz;   //!
   TBranch        *b_New_DRBased_HWW_eta;   //!
   TBranch        *b_New_DRBased_HWW_phi;   //!
   TBranch        *b_New_DRBased_dR_Hgg_Jet1;   //!
   TBranch        *b_New_DRBased_dR_Hgg_Jet2;   //!
   TBranch        *b_New_DRBased_dR_Hgg_Jet3;   //!
   TBranch        *b_New_DRBased_dR_Hgg_Jet4;   //!
   TBranch        *b_New_DRBased_dPhi_Hgg_Jet1;   //!
   TBranch        *b_New_DRBased_dPhi_Hgg_Jet2;   //!
   TBranch        *b_New_DRBased_dPhi_Hgg_Jet3;   //!
   TBranch        *b_New_DRBased_dPhi_Hgg_Jet4;   //!
   TBranch        *b_New_DRBased_DPhi_gg;   //!
   TBranch        *b_New_DRBased_DR_gg;   //!
   TBranch        *b_New_DRBased_DPhi_HH;   //!
   TBranch        *b_New_DRBased_DR_HH;   //!
   TBranch        *b_DRBased_a_costheta1;   //!
   TBranch        *b_DRBased_a_costheta2;   //!
   TBranch        *b_DRBased_a_costhetastar;   //!
   TBranch        *b_DRBased_a_Phi;   //!
   TBranch        *b_DRBased_a_Phi1;   //!
   TBranch        *b_evalDNN;   //!

   flashgg_MC_PostDNN(TTree *tree=0)
   {
   // if parameter tree is not specified (or zero), connect the file
   // used to generate this class and read the Tree.
      if (tree == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNNEval_15May_WithoutSH/2017/GluGluToHHTo2B2G_node_cHHH1_2017.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNNEval_15May_WithoutSH/2017/GluGluToHHTo2B2G_node_cHHH1_2017.root");
         }
         f->GetObject("GluGluToHHTo2B2G_node_cHHH1_13TeV_HHWWggTag_1",tree);

      }
      Init(tree);
   };
   virtual ~flashgg_MC_PostDNN(){};
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
};

#endif


Int_t flashgg_MC_PostDNN::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t flashgg_MC_PostDNN::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void flashgg_MC_PostDNN::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("candidate_id", &candidate_id, &b_candidate_id);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass, &b_CMS_hgg_mass);
   fChain->SetBranchAddress("sigmaMoM_decorr", &sigmaMoM_decorr, &b_sigmaMoM_decorr);
   fChain->SetBranchAddress("dZ", &dZ, &b_dZ);
   fChain->SetBranchAddress("centralObjectWeight", &centralObjectWeight, &b_centralObjectWeight);
   fChain->SetBranchAddress("LooseMvaSFUp01sigma", &LooseMvaSFUp01sigma, &b_LooseMvaSFUp01sigma);
   fChain->SetBranchAddress("PreselSFUp01sigma", &PreselSFUp01sigma, &b_PreselSFUp01sigma);
   fChain->SetBranchAddress("electronVetoSFUp01sigma", &electronVetoSFUp01sigma, &b_electronVetoSFUp01sigma);
   fChain->SetBranchAddress("TriggerWeightUp01sigma", &TriggerWeightUp01sigma, &b_TriggerWeightUp01sigma);
   fChain->SetBranchAddress("FracRVWeightUp01sigma", &FracRVWeightUp01sigma, &b_FracRVWeightUp01sigma);
   fChain->SetBranchAddress("MuonIDWeightUp01sigma", &MuonIDWeightUp01sigma, &b_MuonIDWeightUp01sigma);
   fChain->SetBranchAddress("ElectronIDWeightUp01sigma", &ElectronIDWeightUp01sigma, &b_ElectronIDWeightUp01sigma);
   fChain->SetBranchAddress("ElectronRecoWeightUp01sigma", &ElectronRecoWeightUp01sigma, &b_ElectronRecoWeightUp01sigma);
   fChain->SetBranchAddress("MuonIsoWeightUp01sigma", &MuonIsoWeightUp01sigma, &b_MuonIsoWeightUp01sigma);
   fChain->SetBranchAddress("JetBTagCutWeightUp01sigma", &JetBTagCutWeightUp01sigma, &b_JetBTagCutWeightUp01sigma);
   fChain->SetBranchAddress("JetBTagReshapeWeightUp01sigma", &JetBTagReshapeWeightUp01sigma, &b_JetBTagReshapeWeightUp01sigma);
   fChain->SetBranchAddress("prefireWeightUp01sigma", &prefireWeightUp01sigma, &b_prefireWeightUp01sigma);
   fChain->SetBranchAddress("LooseMvaSFDown01sigma", &LooseMvaSFDown01sigma, &b_LooseMvaSFDown01sigma);
   fChain->SetBranchAddress("PreselSFDown01sigma", &PreselSFDown01sigma, &b_PreselSFDown01sigma);
   fChain->SetBranchAddress("electronVetoSFDown01sigma", &electronVetoSFDown01sigma, &b_electronVetoSFDown01sigma);
   fChain->SetBranchAddress("TriggerWeightDown01sigma", &TriggerWeightDown01sigma, &b_TriggerWeightDown01sigma);
   fChain->SetBranchAddress("FracRVWeightDown01sigma", &FracRVWeightDown01sigma, &b_FracRVWeightDown01sigma);
   fChain->SetBranchAddress("MuonIDWeightDown01sigma", &MuonIDWeightDown01sigma, &b_MuonIDWeightDown01sigma);
   fChain->SetBranchAddress("ElectronIDWeightDown01sigma", &ElectronIDWeightDown01sigma, &b_ElectronIDWeightDown01sigma);
   fChain->SetBranchAddress("ElectronRecoWeightDown01sigma", &ElectronRecoWeightDown01sigma, &b_ElectronRecoWeightDown01sigma);
   fChain->SetBranchAddress("MuonIsoWeightDown01sigma", &MuonIsoWeightDown01sigma, &b_MuonIsoWeightDown01sigma);
   fChain->SetBranchAddress("JetBTagCutWeightDown01sigma", &JetBTagCutWeightDown01sigma, &b_JetBTagCutWeightDown01sigma);
   fChain->SetBranchAddress("JetBTagReshapeWeightDown01sigma", &JetBTagReshapeWeightDown01sigma, &b_JetBTagReshapeWeightDown01sigma);
   fChain->SetBranchAddress("prefireWeightDown01sigma", &prefireWeightDown01sigma, &b_prefireWeightDown01sigma);
   fChain->SetBranchAddress("passPS", &passPS, &b_passPS);
   fChain->SetBranchAddress("passPhotonSels", &passPhotonSels, &b_passPhotonSels);
   fChain->SetBranchAddress("mW1_40To160", &mW1_40To160, &b_mW1_40To160);
   fChain->SetBranchAddress("mW1_65To105", &mW1_65To105, &b_mW1_65To105);
   fChain->SetBranchAddress("mW2_0To160", &mW2_0To160, &b_mW2_0To160);
   fChain->SetBranchAddress("mH_105To160", &mH_105To160, &b_mH_105To160);
   fChain->SetBranchAddress("mH_40To210", &mH_40To210, &b_mH_40To210);
   fChain->SetBranchAddress("FL_Lep_Flavor", &FL_Lep_Flavor, &b_FL_Lep_Flavor);
   fChain->SetBranchAddress("LooseMvaSFCentral", &LooseMvaSFCentral, &b_LooseMvaSFCentral);
   fChain->SetBranchAddress("PreselSFCentral", &PreselSFCentral, &b_PreselSFCentral);
   fChain->SetBranchAddress("TriggerWeightCentral", &TriggerWeightCentral, &b_TriggerWeightCentral);
   fChain->SetBranchAddress("electronVetoSFCentral", &electronVetoSFCentral, &b_electronVetoSFCentral);
   fChain->SetBranchAddress("ElectronIDWeightCentral", &ElectronIDWeightCentral, &b_ElectronIDWeightCentral);
   fChain->SetBranchAddress("ElectronRecoWeightCentral", &ElectronRecoWeightCentral, &b_ElectronRecoWeightCentral);
   fChain->SetBranchAddress("JetBTagCutWeightCentral", &JetBTagCutWeightCentral, &b_JetBTagCutWeightCentral);
   fChain->SetBranchAddress("JetBTagReshapeWeightCentral", &JetBTagReshapeWeightCentral, &b_JetBTagReshapeWeightCentral);
   fChain->SetBranchAddress("MuonIDWeightCentral", &MuonIDWeightCentral, &b_MuonIDWeightCentral);
   fChain->SetBranchAddress("MuonIsoWeightCentral", &MuonIsoWeightCentral, &b_MuonIsoWeightCentral);
   fChain->SetBranchAddress("prefireWeightCentral", &prefireWeightCentral, &b_prefireWeightCentral);
   fChain->SetBranchAddress("DiphoCentralWeight", &DiphoCentralWeight, &b_DiphoCentralWeight);
   fChain->SetBranchAddress("GenVtx_z", &GenVtx_z, &b_GenVtx_z);
   fChain->SetBranchAddress("HggVtx_z", &HggVtx_z, &b_HggVtx_z);
   fChain->SetBranchAddress("ZeroVtx_z", &ZeroVtx_z, &b_ZeroVtx_z);
   fChain->SetBranchAddress("Leading_GEN_Higgs_pt", &Leading_GEN_Higgs_pt, &b_Leading_GEN_Higgs_pt);
   fChain->SetBranchAddress("Subleading_GEN_Higgs_pt", &Subleading_GEN_Higgs_pt, &b_Subleading_GEN_Higgs_pt);
   fChain->SetBranchAddress("Leading_GEN_Higgs_eta", &Leading_GEN_Higgs_eta, &b_Leading_GEN_Higgs_eta);
   fChain->SetBranchAddress("Subleading_GEN_Higgs_eta", &Subleading_GEN_Higgs_eta, &b_Subleading_GEN_Higgs_eta);
   fChain->SetBranchAddress("Leading_GEN_Higgs_phi", &Leading_GEN_Higgs_phi, &b_Leading_GEN_Higgs_phi);
   fChain->SetBranchAddress("Subleading_GEN_Higgs_phi", &Subleading_GEN_Higgs_phi, &b_Subleading_GEN_Higgs_phi);
   fChain->SetBranchAddress("Leading_GEN_Higgs_E", &Leading_GEN_Higgs_E, &b_Leading_GEN_Higgs_E);
   fChain->SetBranchAddress("Subleading_GEN_Higgs_E", &Subleading_GEN_Higgs_E, &b_Subleading_GEN_Higgs_E);
   fChain->SetBranchAddress("Leading_GEN_Higgs_M", &Leading_GEN_Higgs_M, &b_Leading_GEN_Higgs_M);
   fChain->SetBranchAddress("Subleading_GEN_Higgs_M", &Subleading_GEN_Higgs_M, &b_Subleading_GEN_Higgs_M);
   fChain->SetBranchAddress("Leading_GEN_W_pt", &Leading_GEN_W_pt, &b_Leading_GEN_W_pt);
   fChain->SetBranchAddress("Subleading_GEN_W_pt", &Subleading_GEN_W_pt, &b_Subleading_GEN_W_pt);
   fChain->SetBranchAddress("Leading_GEN_W_eta", &Leading_GEN_W_eta, &b_Leading_GEN_W_eta);
   fChain->SetBranchAddress("Subleading_GEN_W_eta", &Subleading_GEN_W_eta, &b_Subleading_GEN_W_eta);
   fChain->SetBranchAddress("Leading_GEN_W_phi", &Leading_GEN_W_phi, &b_Leading_GEN_W_phi);
   fChain->SetBranchAddress("Subleading_GEN_W_phi", &Subleading_GEN_W_phi, &b_Subleading_GEN_W_phi);
   fChain->SetBranchAddress("Leading_GEN_W_E", &Leading_GEN_W_E, &b_Leading_GEN_W_E);
   fChain->SetBranchAddress("Subleading_GEN_W_E", &Subleading_GEN_W_E, &b_Subleading_GEN_W_E);
   fChain->SetBranchAddress("Leading_GEN_W_M", &Leading_GEN_W_M, &b_Leading_GEN_W_M);
   fChain->SetBranchAddress("Subleading_GEN_W_M", &Subleading_GEN_W_M, &b_Subleading_GEN_W_M);
   fChain->SetBranchAddress("Leading_GEN_Photon_pt", &Leading_GEN_Photon_pt, &b_Leading_GEN_Photon_pt);
   fChain->SetBranchAddress("Subleading_GEN_Photon_pt", &Subleading_GEN_Photon_pt, &b_Subleading_GEN_Photon_pt);
   fChain->SetBranchAddress("Leading_GEN_Photon_eta", &Leading_GEN_Photon_eta, &b_Leading_GEN_Photon_eta);
   fChain->SetBranchAddress("Subleading_GEN_Photon_eta", &Subleading_GEN_Photon_eta, &b_Subleading_GEN_Photon_eta);
   fChain->SetBranchAddress("Leading_GEN_Photon_phi", &Leading_GEN_Photon_phi, &b_Leading_GEN_Photon_phi);
   fChain->SetBranchAddress("Subleading_GEN_Photon_phi", &Subleading_GEN_Photon_phi, &b_Subleading_GEN_Photon_phi);
   fChain->SetBranchAddress("Leading_GEN_Photon_E", &Leading_GEN_Photon_E, &b_Leading_GEN_Photon_E);
   fChain->SetBranchAddress("Subleading_GEN_Photon_E", &Subleading_GEN_Photon_E, &b_Subleading_GEN_Photon_E);
   fChain->SetBranchAddress("Leading_GEN_Photon_M", &Leading_GEN_Photon_M, &b_Leading_GEN_Photon_M);
   fChain->SetBranchAddress("Subleading_GEN_Photon_M", &Subleading_GEN_Photon_M, &b_Subleading_GEN_Photon_M);
   fChain->SetBranchAddress("GEN_Quark_0_pt", &GEN_Quark_0_pt, &b_GEN_Quark_0_pt);
   fChain->SetBranchAddress("GEN_Quark_0_eta", &GEN_Quark_0_eta, &b_GEN_Quark_0_eta);
   fChain->SetBranchAddress("GEN_Quark_0_phi", &GEN_Quark_0_phi, &b_GEN_Quark_0_phi);
   fChain->SetBranchAddress("GEN_Quark_0_E", &GEN_Quark_0_E, &b_GEN_Quark_0_E);
   fChain->SetBranchAddress("GEN_Quark_0_M", &GEN_Quark_0_M, &b_GEN_Quark_0_M);
   fChain->SetBranchAddress("GEN_Quark_0_pdgId", &GEN_Quark_0_pdgId, &b_GEN_Quark_0_pdgId);
   fChain->SetBranchAddress("GEN_Quark_1_pt", &GEN_Quark_1_pt, &b_GEN_Quark_1_pt);
   fChain->SetBranchAddress("GEN_Quark_1_eta", &GEN_Quark_1_eta, &b_GEN_Quark_1_eta);
   fChain->SetBranchAddress("GEN_Quark_1_phi", &GEN_Quark_1_phi, &b_GEN_Quark_1_phi);
   fChain->SetBranchAddress("GEN_Quark_1_E", &GEN_Quark_1_E, &b_GEN_Quark_1_E);
   fChain->SetBranchAddress("GEN_Quark_1_M", &GEN_Quark_1_M, &b_GEN_Quark_1_M);
   fChain->SetBranchAddress("GEN_Quark_1_pdgId", &GEN_Quark_1_pdgId, &b_GEN_Quark_1_pdgId);
   fChain->SetBranchAddress("GEN_Quark_2_pt", &GEN_Quark_2_pt, &b_GEN_Quark_2_pt);
   fChain->SetBranchAddress("GEN_Quark_2_eta", &GEN_Quark_2_eta, &b_GEN_Quark_2_eta);
   fChain->SetBranchAddress("GEN_Quark_2_phi", &GEN_Quark_2_phi, &b_GEN_Quark_2_phi);
   fChain->SetBranchAddress("GEN_Quark_2_E", &GEN_Quark_2_E, &b_GEN_Quark_2_E);
   fChain->SetBranchAddress("GEN_Quark_2_M", &GEN_Quark_2_M, &b_GEN_Quark_2_M);
   fChain->SetBranchAddress("GEN_Quark_2_pdgId", &GEN_Quark_2_pdgId, &b_GEN_Quark_2_pdgId);
   fChain->SetBranchAddress("GEN_Quark_3_pt", &GEN_Quark_3_pt, &b_GEN_Quark_3_pt);
   fChain->SetBranchAddress("GEN_Quark_3_eta", &GEN_Quark_3_eta, &b_GEN_Quark_3_eta);
   fChain->SetBranchAddress("GEN_Quark_3_phi", &GEN_Quark_3_phi, &b_GEN_Quark_3_phi);
   fChain->SetBranchAddress("GEN_Quark_3_E", &GEN_Quark_3_E, &b_GEN_Quark_3_E);
   fChain->SetBranchAddress("GEN_Quark_3_M", &GEN_Quark_3_M, &b_GEN_Quark_3_M);
   fChain->SetBranchAddress("GEN_Quark_3_pdgId", &GEN_Quark_3_pdgId, &b_GEN_Quark_3_pdgId);
   fChain->SetBranchAddress("GEN_Lepton_0_pt", &GEN_Lepton_0_pt, &b_GEN_Lepton_0_pt);
   fChain->SetBranchAddress("GEN_Lepton_0_eta", &GEN_Lepton_0_eta, &b_GEN_Lepton_0_eta);
   fChain->SetBranchAddress("GEN_Lepton_0_phi", &GEN_Lepton_0_phi, &b_GEN_Lepton_0_phi);
   fChain->SetBranchAddress("GEN_Lepton_0_E", &GEN_Lepton_0_E, &b_GEN_Lepton_0_E);
   fChain->SetBranchAddress("GEN_Lepton_0_M", &GEN_Lepton_0_M, &b_GEN_Lepton_0_M);
   fChain->SetBranchAddress("GEN_Lepton_0_pdgId", &GEN_Lepton_0_pdgId, &b_GEN_Lepton_0_pdgId);
   fChain->SetBranchAddress("GEN_Lepton_1_pt", &GEN_Lepton_1_pt, &b_GEN_Lepton_1_pt);
   fChain->SetBranchAddress("GEN_Lepton_1_eta", &GEN_Lepton_1_eta, &b_GEN_Lepton_1_eta);
   fChain->SetBranchAddress("GEN_Lepton_1_phi", &GEN_Lepton_1_phi, &b_GEN_Lepton_1_phi);
   fChain->SetBranchAddress("GEN_Lepton_1_E", &GEN_Lepton_1_E, &b_GEN_Lepton_1_E);
   fChain->SetBranchAddress("GEN_Lepton_1_M", &GEN_Lepton_1_M, &b_GEN_Lepton_1_M);
   fChain->SetBranchAddress("GEN_Lepton_1_pdgId", &GEN_Lepton_1_pdgId, &b_GEN_Lepton_1_pdgId);
   fChain->SetBranchAddress("GEN_Neutrino_0_pt", &GEN_Neutrino_0_pt, &b_GEN_Neutrino_0_pt);
   fChain->SetBranchAddress("GEN_Neutrino_0_eta", &GEN_Neutrino_0_eta, &b_GEN_Neutrino_0_eta);
   fChain->SetBranchAddress("GEN_Neutrino_0_phi", &GEN_Neutrino_0_phi, &b_GEN_Neutrino_0_phi);
   fChain->SetBranchAddress("GEN_Neutrino_0_E", &GEN_Neutrino_0_E, &b_GEN_Neutrino_0_E);
   fChain->SetBranchAddress("GEN_Neutrino_0_M", &GEN_Neutrino_0_M, &b_GEN_Neutrino_0_M);
   fChain->SetBranchAddress("GEN_Neutrino_0_pdgId", &GEN_Neutrino_0_pdgId, &b_GEN_Neutrino_0_pdgId);
   fChain->SetBranchAddress("GEN_Neutrino_1_pt", &GEN_Neutrino_1_pt, &b_GEN_Neutrino_1_pt);
   fChain->SetBranchAddress("GEN_Neutrino_1_eta", &GEN_Neutrino_1_eta, &b_GEN_Neutrino_1_eta);
   fChain->SetBranchAddress("GEN_Neutrino_1_phi", &GEN_Neutrino_1_phi, &b_GEN_Neutrino_1_phi);
   fChain->SetBranchAddress("GEN_Neutrino_1_E", &GEN_Neutrino_1_E, &b_GEN_Neutrino_1_E);
   fChain->SetBranchAddress("GEN_Neutrino_1_M", &GEN_Neutrino_1_M, &b_GEN_Neutrino_1_M);
   fChain->SetBranchAddress("GEN_Neutrino_1_pdgId", &GEN_Neutrino_1_pdgId, &b_GEN_Neutrino_1_pdgId);
   fChain->SetBranchAddress("genMhh", &genMhh, &b_genMhh);
   fChain->SetBranchAddress("genCosThetaStar_CS", &genCosThetaStar_CS, &b_genCosThetaStar_CS);
   fChain->SetBranchAddress("genAbsCosThetaStar_CS", &genAbsCosThetaStar_CS, &b_genAbsCosThetaStar_CS);
   fChain->SetBranchAddress("Leading_Photon_MVA", &Leading_Photon_MVA, &b_Leading_Photon_MVA);
   fChain->SetBranchAddress("Subleading_Photon_MVA", &Subleading_Photon_MVA, &b_Subleading_Photon_MVA);
   fChain->SetBranchAddress("Leading_Photon_SC_eta", &Leading_Photon_SC_eta, &b_Leading_Photon_SC_eta);
   fChain->SetBranchAddress("Leading_Photon_initE", &Leading_Photon_initE, &b_Leading_Photon_initE);
   fChain->SetBranchAddress("Leading_Photon_r9", &Leading_Photon_r9, &b_Leading_Photon_r9);
   fChain->SetBranchAddress("Leading_Photon_full5x5_r9", &Leading_Photon_full5x5_r9, &b_Leading_Photon_full5x5_r9);
   fChain->SetBranchAddress("Leading_Photon_Hgg_MVA", &Leading_Photon_Hgg_MVA, &b_Leading_Photon_Hgg_MVA);
   fChain->SetBranchAddress("Leading_Photon_passElectronVeto", &Leading_Photon_passElectronVeto, &b_Leading_Photon_passElectronVeto);
   fChain->SetBranchAddress("Leading_Photon_hasPixelSeed", &Leading_Photon_hasPixelSeed, &b_Leading_Photon_hasPixelSeed);
   fChain->SetBranchAddress("Subleading_Photon_SC_eta", &Subleading_Photon_SC_eta, &b_Subleading_Photon_SC_eta);
   fChain->SetBranchAddress("Subleading_Photon_r9", &Subleading_Photon_r9, &b_Subleading_Photon_r9);
   fChain->SetBranchAddress("Subleading_Photon_full5x5_r9", &Subleading_Photon_full5x5_r9, &b_Subleading_Photon_full5x5_r9);
   fChain->SetBranchAddress("Subleading_Photon_passElectronVeto", &Subleading_Photon_passElectronVeto, &b_Subleading_Photon_passElectronVeto);
   fChain->SetBranchAddress("Subleading_Photon_hasPixelSeed", &Subleading_Photon_hasPixelSeed, &b_Subleading_Photon_hasPixelSeed);
   fChain->SetBranchAddress("Leading_Photon_E", &Leading_Photon_E, &b_Leading_Photon_E);
   fChain->SetBranchAddress("Leading_Photon_pt", &Leading_Photon_pt, &b_Leading_Photon_pt);
   fChain->SetBranchAddress("Leading_Photon_px", &Leading_Photon_px, &b_Leading_Photon_px);
   fChain->SetBranchAddress("Leading_Photon_py", &Leading_Photon_py, &b_Leading_Photon_py);
   fChain->SetBranchAddress("Leading_Photon_pz", &Leading_Photon_pz, &b_Leading_Photon_pz);
   fChain->SetBranchAddress("Leading_Photon_eta", &Leading_Photon_eta, &b_Leading_Photon_eta);
   fChain->SetBranchAddress("Leading_Photon_phi", &Leading_Photon_phi, &b_Leading_Photon_phi);
   fChain->SetBranchAddress("Subleading_Photon_E", &Subleading_Photon_E, &b_Subleading_Photon_E);
   fChain->SetBranchAddress("Subleading_Photon_pt", &Subleading_Photon_pt, &b_Subleading_Photon_pt);
   fChain->SetBranchAddress("Subleading_Photon_px", &Subleading_Photon_px, &b_Subleading_Photon_px);
   fChain->SetBranchAddress("Subleading_Photon_py", &Subleading_Photon_py, &b_Subleading_Photon_py);
   fChain->SetBranchAddress("Subleading_Photon_pz", &Subleading_Photon_pz, &b_Subleading_Photon_pz);
   fChain->SetBranchAddress("Subleading_Photon_eta", &Subleading_Photon_eta, &b_Subleading_Photon_eta);
   fChain->SetBranchAddress("Subleading_Photon_phi", &Subleading_Photon_phi, &b_Subleading_Photon_phi);
   fChain->SetBranchAddress("Electron_E", &Electron_E, &b_Electron_E);
   fChain->SetBranchAddress("Electron_pt", &Electron_pt, &b_Electron_pt);
   fChain->SetBranchAddress("Electron_px", &Electron_px, &b_Electron_px);
   fChain->SetBranchAddress("Electron_py", &Electron_py, &b_Electron_py);
   fChain->SetBranchAddress("Electron_pz", &Electron_pz, &b_Electron_pz);
   fChain->SetBranchAddress("Electron_eta", &Electron_eta, &b_Electron_eta);
   fChain->SetBranchAddress("Electron_phi", &Electron_phi, &b_Electron_phi);
   fChain->SetBranchAddress("Muon_E", &Muon_E, &b_Muon_E);
   fChain->SetBranchAddress("Muon_pt", &Muon_pt, &b_Muon_pt);
   fChain->SetBranchAddress("Muon_px", &Muon_px, &b_Muon_px);
   fChain->SetBranchAddress("Muon_py", &Muon_py, &b_Muon_py);
   fChain->SetBranchAddress("Muon_pz", &Muon_pz, &b_Muon_pz);
   fChain->SetBranchAddress("Muon_eta", &Muon_eta, &b_Muon_eta);
   fChain->SetBranchAddress("Muon_phi", &Muon_phi, &b_Muon_phi);
   fChain->SetBranchAddress("MET_E", &MET_E, &b_MET_E);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   fChain->SetBranchAddress("MET_px", &MET_px, &b_MET_px);
   fChain->SetBranchAddress("MET_py", &MET_py, &b_MET_py);
   fChain->SetBranchAddress("MET_pz", &MET_pz, &b_MET_pz);
   fChain->SetBranchAddress("MET_eta", &MET_eta, &b_MET_eta);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("Leading_Jet_E", &Leading_Jet_E, &b_Leading_Jet_E);
   fChain->SetBranchAddress("Leading_Jet_pt", &Leading_Jet_pt, &b_Leading_Jet_pt);
   fChain->SetBranchAddress("Leading_Jet_px", &Leading_Jet_px, &b_Leading_Jet_px);
   fChain->SetBranchAddress("Leading_Jet_py", &Leading_Jet_py, &b_Leading_Jet_py);
   fChain->SetBranchAddress("Leading_Jet_pz", &Leading_Jet_pz, &b_Leading_Jet_pz);
   fChain->SetBranchAddress("Leading_Jet_eta", &Leading_Jet_eta, &b_Leading_Jet_eta);
   fChain->SetBranchAddress("Leading_Jet_phi", &Leading_Jet_phi, &b_Leading_Jet_phi);
   fChain->SetBranchAddress("Subleading_Jet_E", &Subleading_Jet_E, &b_Subleading_Jet_E);
   fChain->SetBranchAddress("Subleading_Jet_pt", &Subleading_Jet_pt, &b_Subleading_Jet_pt);
   fChain->SetBranchAddress("Subleading_Jet_px", &Subleading_Jet_px, &b_Subleading_Jet_px);
   fChain->SetBranchAddress("Subleading_Jet_py", &Subleading_Jet_py, &b_Subleading_Jet_py);
   fChain->SetBranchAddress("Subleading_Jet_pz", &Subleading_Jet_pz, &b_Subleading_Jet_pz);
   fChain->SetBranchAddress("Subleading_Jet_eta", &Subleading_Jet_eta, &b_Subleading_Jet_eta);
   fChain->SetBranchAddress("Subleading_Jet_phi", &Subleading_Jet_phi, &b_Subleading_Jet_phi);
   fChain->SetBranchAddress("Sub2leading_Jet_E", &Sub2leading_Jet_E, &b_Sub2leading_Jet_E);
   fChain->SetBranchAddress("Sub2leading_Jet_pt", &Sub2leading_Jet_pt, &b_Sub2leading_Jet_pt);
   fChain->SetBranchAddress("Sub2leading_Jet_px", &Sub2leading_Jet_px, &b_Sub2leading_Jet_px);
   fChain->SetBranchAddress("Sub2leading_Jet_py", &Sub2leading_Jet_py, &b_Sub2leading_Jet_py);
   fChain->SetBranchAddress("Sub2leading_Jet_pz", &Sub2leading_Jet_pz, &b_Sub2leading_Jet_pz);
   fChain->SetBranchAddress("Sub2leading_Jet_eta", &Sub2leading_Jet_eta, &b_Sub2leading_Jet_eta);
   fChain->SetBranchAddress("Sub2leading_Jet_phi", &Sub2leading_Jet_phi, &b_Sub2leading_Jet_phi);
   fChain->SetBranchAddress("Sub3leading_Jet_E", &Sub3leading_Jet_E, &b_Sub3leading_Jet_E);
   fChain->SetBranchAddress("Sub3leading_Jet_pt", &Sub3leading_Jet_pt, &b_Sub3leading_Jet_pt);
   fChain->SetBranchAddress("Sub3leading_Jet_px", &Sub3leading_Jet_px, &b_Sub3leading_Jet_px);
   fChain->SetBranchAddress("Sub3leading_Jet_py", &Sub3leading_Jet_py, &b_Sub3leading_Jet_py);
   fChain->SetBranchAddress("Sub3leading_Jet_pz", &Sub3leading_Jet_pz, &b_Sub3leading_Jet_pz);
   fChain->SetBranchAddress("Sub3leading_Jet_eta", &Sub3leading_Jet_eta, &b_Sub3leading_Jet_eta);
   fChain->SetBranchAddress("Sub3leading_Jet_phi", &Sub3leading_Jet_phi, &b_Sub3leading_Jet_phi);
   fChain->SetBranchAddress("N_allElectrons", &N_allElectrons, &b_N_allElectrons);
   fChain->SetBranchAddress("allElectrons_0_E", &allElectrons_0_E, &b_allElectrons_0_E);
   fChain->SetBranchAddress("allElectrons_1_E", &allElectrons_1_E, &b_allElectrons_1_E);
   fChain->SetBranchAddress("allElectrons_2_E", &allElectrons_2_E, &b_allElectrons_2_E);
   fChain->SetBranchAddress("allElectrons_3_E", &allElectrons_3_E, &b_allElectrons_3_E);
   fChain->SetBranchAddress("allElectrons_4_E", &allElectrons_4_E, &b_allElectrons_4_E);
   fChain->SetBranchAddress("allElectrons_0_pt", &allElectrons_0_pt, &b_allElectrons_0_pt);
   fChain->SetBranchAddress("allElectrons_1_pt", &allElectrons_1_pt, &b_allElectrons_1_pt);
   fChain->SetBranchAddress("allElectrons_2_pt", &allElectrons_2_pt, &b_allElectrons_2_pt);
   fChain->SetBranchAddress("allElectrons_3_pt", &allElectrons_3_pt, &b_allElectrons_3_pt);
   fChain->SetBranchAddress("allElectrons_4_pt", &allElectrons_4_pt, &b_allElectrons_4_pt);
   fChain->SetBranchAddress("allElectrons_0_px", &allElectrons_0_px, &b_allElectrons_0_px);
   fChain->SetBranchAddress("allElectrons_1_px", &allElectrons_1_px, &b_allElectrons_1_px);
   fChain->SetBranchAddress("allElectrons_2_px", &allElectrons_2_px, &b_allElectrons_2_px);
   fChain->SetBranchAddress("allElectrons_3_px", &allElectrons_3_px, &b_allElectrons_3_px);
   fChain->SetBranchAddress("allElectrons_4_px", &allElectrons_4_px, &b_allElectrons_4_px);
   fChain->SetBranchAddress("allElectrons_0_py", &allElectrons_0_py, &b_allElectrons_0_py);
   fChain->SetBranchAddress("allElectrons_1_py", &allElectrons_1_py, &b_allElectrons_1_py);
   fChain->SetBranchAddress("allElectrons_2_py", &allElectrons_2_py, &b_allElectrons_2_py);
   fChain->SetBranchAddress("allElectrons_3_py", &allElectrons_3_py, &b_allElectrons_3_py);
   fChain->SetBranchAddress("allElectrons_4_py", &allElectrons_4_py, &b_allElectrons_4_py);
   fChain->SetBranchAddress("allElectrons_0_pz", &allElectrons_0_pz, &b_allElectrons_0_pz);
   fChain->SetBranchAddress("allElectrons_1_pz", &allElectrons_1_pz, &b_allElectrons_1_pz);
   fChain->SetBranchAddress("allElectrons_2_pz", &allElectrons_2_pz, &b_allElectrons_2_pz);
   fChain->SetBranchAddress("allElectrons_3_pz", &allElectrons_3_pz, &b_allElectrons_3_pz);
   fChain->SetBranchAddress("allElectrons_4_pz", &allElectrons_4_pz, &b_allElectrons_4_pz);
   fChain->SetBranchAddress("allElectrons_0_eta", &allElectrons_0_eta, &b_allElectrons_0_eta);
   fChain->SetBranchAddress("allElectrons_1_eta", &allElectrons_1_eta, &b_allElectrons_1_eta);
   fChain->SetBranchAddress("allElectrons_2_eta", &allElectrons_2_eta, &b_allElectrons_2_eta);
   fChain->SetBranchAddress("allElectrons_3_eta", &allElectrons_3_eta, &b_allElectrons_3_eta);
   fChain->SetBranchAddress("allElectrons_4_eta", &allElectrons_4_eta, &b_allElectrons_4_eta);
   fChain->SetBranchAddress("allElectrons_0_phi", &allElectrons_0_phi, &b_allElectrons_0_phi);
   fChain->SetBranchAddress("allElectrons_1_phi", &allElectrons_1_phi, &b_allElectrons_1_phi);
   fChain->SetBranchAddress("allElectrons_2_phi", &allElectrons_2_phi, &b_allElectrons_2_phi);
   fChain->SetBranchAddress("allElectrons_3_phi", &allElectrons_3_phi, &b_allElectrons_3_phi);
   fChain->SetBranchAddress("allElectrons_4_phi", &allElectrons_4_phi, &b_allElectrons_4_phi);
   fChain->SetBranchAddress("allElectrons_0_passLooseId", &allElectrons_0_passLooseId, &b_allElectrons_0_passLooseId);
   fChain->SetBranchAddress("allElectrons_1_passLooseId", &allElectrons_1_passLooseId, &b_allElectrons_1_passLooseId);
   fChain->SetBranchAddress("allElectrons_2_passLooseId", &allElectrons_2_passLooseId, &b_allElectrons_2_passLooseId);
   fChain->SetBranchAddress("allElectrons_3_passLooseId", &allElectrons_3_passLooseId, &b_allElectrons_3_passLooseId);
   fChain->SetBranchAddress("allElectrons_4_passLooseId", &allElectrons_4_passLooseId, &b_allElectrons_4_passLooseId);
   fChain->SetBranchAddress("allElectrons_0_passMediumId", &allElectrons_0_passMediumId, &b_allElectrons_0_passMediumId);
   fChain->SetBranchAddress("allElectrons_1_passMediumId", &allElectrons_1_passMediumId, &b_allElectrons_1_passMediumId);
   fChain->SetBranchAddress("allElectrons_2_passMediumId", &allElectrons_2_passMediumId, &b_allElectrons_2_passMediumId);
   fChain->SetBranchAddress("allElectrons_3_passMediumId", &allElectrons_3_passMediumId, &b_allElectrons_3_passMediumId);
   fChain->SetBranchAddress("allElectrons_4_passMediumId", &allElectrons_4_passMediumId, &b_allElectrons_4_passMediumId);
   fChain->SetBranchAddress("allElectrons_0_passTightId", &allElectrons_0_passTightId, &b_allElectrons_0_passTightId);
   fChain->SetBranchAddress("allElectrons_1_passTightId", &allElectrons_1_passTightId, &b_allElectrons_1_passTightId);
   fChain->SetBranchAddress("allElectrons_2_passTightId", &allElectrons_2_passTightId, &b_allElectrons_2_passTightId);
   fChain->SetBranchAddress("allElectrons_3_passTightId", &allElectrons_3_passTightId, &b_allElectrons_3_passTightId);
   fChain->SetBranchAddress("allElectrons_4_passTightId", &allElectrons_4_passTightId, &b_allElectrons_4_passTightId);
   fChain->SetBranchAddress("allElectrons_0_passMVALooseId", &allElectrons_0_passMVALooseId, &b_allElectrons_0_passMVALooseId);
   fChain->SetBranchAddress("allElectrons_1_passMVALooseId", &allElectrons_1_passMVALooseId, &b_allElectrons_1_passMVALooseId);
   fChain->SetBranchAddress("allElectrons_2_passMVALooseId", &allElectrons_2_passMVALooseId, &b_allElectrons_2_passMVALooseId);
   fChain->SetBranchAddress("allElectrons_3_passMVALooseId", &allElectrons_3_passMVALooseId, &b_allElectrons_3_passMVALooseId);
   fChain->SetBranchAddress("allElectrons_4_passMVALooseId", &allElectrons_4_passMVALooseId, &b_allElectrons_4_passMVALooseId);
   fChain->SetBranchAddress("allElectrons_0_passMVAMediumId", &allElectrons_0_passMVAMediumId, &b_allElectrons_0_passMVAMediumId);
   fChain->SetBranchAddress("allElectrons_1_passMVAMediumId", &allElectrons_1_passMVAMediumId, &b_allElectrons_1_passMVAMediumId);
   fChain->SetBranchAddress("allElectrons_2_passMVAMediumId", &allElectrons_2_passMVAMediumId, &b_allElectrons_2_passMVAMediumId);
   fChain->SetBranchAddress("allElectrons_3_passMVAMediumId", &allElectrons_3_passMVAMediumId, &b_allElectrons_3_passMVAMediumId);
   fChain->SetBranchAddress("allElectrons_4_passMVAMediumId", &allElectrons_4_passMVAMediumId, &b_allElectrons_4_passMVAMediumId);
   fChain->SetBranchAddress("allElectrons_0_passMVATightId", &allElectrons_0_passMVATightId, &b_allElectrons_0_passMVATightId);
   fChain->SetBranchAddress("allElectrons_1_passMVATightId", &allElectrons_1_passMVATightId, &b_allElectrons_1_passMVATightId);
   fChain->SetBranchAddress("allElectrons_2_passMVATightId", &allElectrons_2_passMVATightId, &b_allElectrons_2_passMVATightId);
   fChain->SetBranchAddress("allElectrons_3_passMVATightId", &allElectrons_3_passMVATightId, &b_allElectrons_3_passMVATightId);
   fChain->SetBranchAddress("allElectrons_4_passMVATightId", &allElectrons_4_passMVATightId, &b_allElectrons_4_passMVATightId);
   fChain->SetBranchAddress("N_allMuons", &N_allMuons, &b_N_allMuons);
   fChain->SetBranchAddress("allMuons_0_E", &allMuons_0_E, &b_allMuons_0_E);
   fChain->SetBranchAddress("allMuons_1_E", &allMuons_1_E, &b_allMuons_1_E);
   fChain->SetBranchAddress("allMuons_2_E", &allMuons_2_E, &b_allMuons_2_E);
   fChain->SetBranchAddress("allMuons_3_E", &allMuons_3_E, &b_allMuons_3_E);
   fChain->SetBranchAddress("allMuons_4_E", &allMuons_4_E, &b_allMuons_4_E);
   fChain->SetBranchAddress("allMuons_0_pt", &allMuons_0_pt, &b_allMuons_0_pt);
   fChain->SetBranchAddress("allMuons_1_pt", &allMuons_1_pt, &b_allMuons_1_pt);
   fChain->SetBranchAddress("allMuons_2_pt", &allMuons_2_pt, &b_allMuons_2_pt);
   fChain->SetBranchAddress("allMuons_3_pt", &allMuons_3_pt, &b_allMuons_3_pt);
   fChain->SetBranchAddress("allMuons_4_pt", &allMuons_4_pt, &b_allMuons_4_pt);
   fChain->SetBranchAddress("allMuons_0_px", &allMuons_0_px, &b_allMuons_0_px);
   fChain->SetBranchAddress("allMuons_1_px", &allMuons_1_px, &b_allMuons_1_px);
   fChain->SetBranchAddress("allMuons_2_px", &allMuons_2_px, &b_allMuons_2_px);
   fChain->SetBranchAddress("allMuons_3_px", &allMuons_3_px, &b_allMuons_3_px);
   fChain->SetBranchAddress("allMuons_4_px", &allMuons_4_px, &b_allMuons_4_px);
   fChain->SetBranchAddress("allMuons_0_py", &allMuons_0_py, &b_allMuons_0_py);
   fChain->SetBranchAddress("allMuons_1_py", &allMuons_1_py, &b_allMuons_1_py);
   fChain->SetBranchAddress("allMuons_2_py", &allMuons_2_py, &b_allMuons_2_py);
   fChain->SetBranchAddress("allMuons_3_py", &allMuons_3_py, &b_allMuons_3_py);
   fChain->SetBranchAddress("allMuons_4_py", &allMuons_4_py, &b_allMuons_4_py);
   fChain->SetBranchAddress("allMuons_0_pz", &allMuons_0_pz, &b_allMuons_0_pz);
   fChain->SetBranchAddress("allMuons_1_pz", &allMuons_1_pz, &b_allMuons_1_pz);
   fChain->SetBranchAddress("allMuons_2_pz", &allMuons_2_pz, &b_allMuons_2_pz);
   fChain->SetBranchAddress("allMuons_3_pz", &allMuons_3_pz, &b_allMuons_3_pz);
   fChain->SetBranchAddress("allMuons_4_pz", &allMuons_4_pz, &b_allMuons_4_pz);
   fChain->SetBranchAddress("allMuons_0_eta", &allMuons_0_eta, &b_allMuons_0_eta);
   fChain->SetBranchAddress("allMuons_1_eta", &allMuons_1_eta, &b_allMuons_1_eta);
   fChain->SetBranchAddress("allMuons_2_eta", &allMuons_2_eta, &b_allMuons_2_eta);
   fChain->SetBranchAddress("allMuons_3_eta", &allMuons_3_eta, &b_allMuons_3_eta);
   fChain->SetBranchAddress("allMuons_4_eta", &allMuons_4_eta, &b_allMuons_4_eta);
   fChain->SetBranchAddress("allMuons_0_phi", &allMuons_0_phi, &b_allMuons_0_phi);
   fChain->SetBranchAddress("allMuons_1_phi", &allMuons_1_phi, &b_allMuons_1_phi);
   fChain->SetBranchAddress("allMuons_2_phi", &allMuons_2_phi, &b_allMuons_2_phi);
   fChain->SetBranchAddress("allMuons_3_phi", &allMuons_3_phi, &b_allMuons_3_phi);
   fChain->SetBranchAddress("allMuons_4_phi", &allMuons_4_phi, &b_allMuons_4_phi);
   fChain->SetBranchAddress("N_allJets", &N_allJets, &b_N_allJets);
   fChain->SetBranchAddress("allJets_0_E", &allJets_0_E, &b_allJets_0_E);
   fChain->SetBranchAddress("allJets_1_E", &allJets_1_E, &b_allJets_1_E);
   fChain->SetBranchAddress("allJets_2_E", &allJets_2_E, &b_allJets_2_E);
   fChain->SetBranchAddress("allJets_3_E", &allJets_3_E, &b_allJets_3_E);
   fChain->SetBranchAddress("allJets_4_E", &allJets_4_E, &b_allJets_4_E);
   fChain->SetBranchAddress("allJets_5_E", &allJets_5_E, &b_allJets_5_E);
   fChain->SetBranchAddress("allJets_6_E", &allJets_6_E, &b_allJets_6_E);
   fChain->SetBranchAddress("allJets_7_E", &allJets_7_E, &b_allJets_7_E);
   fChain->SetBranchAddress("allJets_8_E", &allJets_8_E, &b_allJets_8_E);
   fChain->SetBranchAddress("allJets_9_E", &allJets_9_E, &b_allJets_9_E);
   fChain->SetBranchAddress("allJets_0_pt", &allJets_0_pt, &b_allJets_0_pt);
   fChain->SetBranchAddress("allJets_1_pt", &allJets_1_pt, &b_allJets_1_pt);
   fChain->SetBranchAddress("allJets_2_pt", &allJets_2_pt, &b_allJets_2_pt);
   fChain->SetBranchAddress("allJets_3_pt", &allJets_3_pt, &b_allJets_3_pt);
   fChain->SetBranchAddress("allJets_4_pt", &allJets_4_pt, &b_allJets_4_pt);
   fChain->SetBranchAddress("allJets_5_pt", &allJets_5_pt, &b_allJets_5_pt);
   fChain->SetBranchAddress("allJets_6_pt", &allJets_6_pt, &b_allJets_6_pt);
   fChain->SetBranchAddress("allJets_7_pt", &allJets_7_pt, &b_allJets_7_pt);
   fChain->SetBranchAddress("allJets_8_pt", &allJets_8_pt, &b_allJets_8_pt);
   fChain->SetBranchAddress("allJets_9_pt", &allJets_9_pt, &b_allJets_9_pt);
   fChain->SetBranchAddress("allJets_0_px", &allJets_0_px, &b_allJets_0_px);
   fChain->SetBranchAddress("allJets_1_px", &allJets_1_px, &b_allJets_1_px);
   fChain->SetBranchAddress("allJets_2_px", &allJets_2_px, &b_allJets_2_px);
   fChain->SetBranchAddress("allJets_3_px", &allJets_3_px, &b_allJets_3_px);
   fChain->SetBranchAddress("allJets_4_px", &allJets_4_px, &b_allJets_4_px);
   fChain->SetBranchAddress("allJets_5_px", &allJets_5_px, &b_allJets_5_px);
   fChain->SetBranchAddress("allJets_6_px", &allJets_6_px, &b_allJets_6_px);
   fChain->SetBranchAddress("allJets_7_px", &allJets_7_px, &b_allJets_7_px);
   fChain->SetBranchAddress("allJets_8_px", &allJets_8_px, &b_allJets_8_px);
   fChain->SetBranchAddress("allJets_9_px", &allJets_9_px, &b_allJets_9_px);
   fChain->SetBranchAddress("allJets_0_py", &allJets_0_py, &b_allJets_0_py);
   fChain->SetBranchAddress("allJets_1_py", &allJets_1_py, &b_allJets_1_py);
   fChain->SetBranchAddress("allJets_2_py", &allJets_2_py, &b_allJets_2_py);
   fChain->SetBranchAddress("allJets_3_py", &allJets_3_py, &b_allJets_3_py);
   fChain->SetBranchAddress("allJets_4_py", &allJets_4_py, &b_allJets_4_py);
   fChain->SetBranchAddress("allJets_5_py", &allJets_5_py, &b_allJets_5_py);
   fChain->SetBranchAddress("allJets_6_py", &allJets_6_py, &b_allJets_6_py);
   fChain->SetBranchAddress("allJets_7_py", &allJets_7_py, &b_allJets_7_py);
   fChain->SetBranchAddress("allJets_8_py", &allJets_8_py, &b_allJets_8_py);
   fChain->SetBranchAddress("allJets_9_py", &allJets_9_py, &b_allJets_9_py);
   fChain->SetBranchAddress("allJets_0_pz", &allJets_0_pz, &b_allJets_0_pz);
   fChain->SetBranchAddress("allJets_1_pz", &allJets_1_pz, &b_allJets_1_pz);
   fChain->SetBranchAddress("allJets_2_pz", &allJets_2_pz, &b_allJets_2_pz);
   fChain->SetBranchAddress("allJets_3_pz", &allJets_3_pz, &b_allJets_3_pz);
   fChain->SetBranchAddress("allJets_4_pz", &allJets_4_pz, &b_allJets_4_pz);
   fChain->SetBranchAddress("allJets_5_pz", &allJets_5_pz, &b_allJets_5_pz);
   fChain->SetBranchAddress("allJets_6_pz", &allJets_6_pz, &b_allJets_6_pz);
   fChain->SetBranchAddress("allJets_7_pz", &allJets_7_pz, &b_allJets_7_pz);
   fChain->SetBranchAddress("allJets_8_pz", &allJets_8_pz, &b_allJets_8_pz);
   fChain->SetBranchAddress("allJets_9_pz", &allJets_9_pz, &b_allJets_9_pz);
   fChain->SetBranchAddress("allJets_0_eta", &allJets_0_eta, &b_allJets_0_eta);
   fChain->SetBranchAddress("allJets_1_eta", &allJets_1_eta, &b_allJets_1_eta);
   fChain->SetBranchAddress("allJets_2_eta", &allJets_2_eta, &b_allJets_2_eta);
   fChain->SetBranchAddress("allJets_3_eta", &allJets_3_eta, &b_allJets_3_eta);
   fChain->SetBranchAddress("allJets_4_eta", &allJets_4_eta, &b_allJets_4_eta);
   fChain->SetBranchAddress("allJets_5_eta", &allJets_5_eta, &b_allJets_5_eta);
   fChain->SetBranchAddress("allJets_6_eta", &allJets_6_eta, &b_allJets_6_eta);
   fChain->SetBranchAddress("allJets_7_eta", &allJets_7_eta, &b_allJets_7_eta);
   fChain->SetBranchAddress("allJets_8_eta", &allJets_8_eta, &b_allJets_8_eta);
   fChain->SetBranchAddress("allJets_9_eta", &allJets_9_eta, &b_allJets_9_eta);
   fChain->SetBranchAddress("allJets_0_phi", &allJets_0_phi, &b_allJets_0_phi);
   fChain->SetBranchAddress("allJets_1_phi", &allJets_1_phi, &b_allJets_1_phi);
   fChain->SetBranchAddress("allJets_2_phi", &allJets_2_phi, &b_allJets_2_phi);
   fChain->SetBranchAddress("allJets_3_phi", &allJets_3_phi, &b_allJets_3_phi);
   fChain->SetBranchAddress("allJets_4_phi", &allJets_4_phi, &b_allJets_4_phi);
   fChain->SetBranchAddress("allJets_5_phi", &allJets_5_phi, &b_allJets_5_phi);
   fChain->SetBranchAddress("allJets_6_phi", &allJets_6_phi, &b_allJets_6_phi);
   fChain->SetBranchAddress("allJets_7_phi", &allJets_7_phi, &b_allJets_7_phi);
   fChain->SetBranchAddress("allJets_8_phi", &allJets_8_phi, &b_allJets_8_phi);
   fChain->SetBranchAddress("allJets_9_phi", &allJets_9_phi, &b_allJets_9_phi);
   fChain->SetBranchAddress("allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("allJets_0_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_0_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_0_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_1_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_1_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_1_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_2_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_2_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_2_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_3_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_3_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_3_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_4_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_4_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_4_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_5_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_5_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_5_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_6_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_6_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_6_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_7_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_7_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_7_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_8_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_8_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_8_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_9_bDiscriminator_pfDeepCSVJetTags_probb", &allJets_9_bDiscriminator_pfDeepCSVJetTags_probb, &b_allJets_9_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("allJets_0_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_0_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_0_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_1_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_1_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_1_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_2_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_2_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_2_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_3_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_3_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_3_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_4_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_4_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_4_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_5_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_5_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_5_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_6_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_6_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_6_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_7_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_7_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_7_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_8_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_8_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_8_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_9_bDiscriminator_pfDeepCSVJetTags_probbb", &allJets_9_bDiscriminator_pfDeepCSVJetTags_probbb, &b_allJets_9_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("N_goodElectrons", &N_goodElectrons, &b_N_goodElectrons);
   fChain->SetBranchAddress("goodElectrons_0_E", &goodElectrons_0_E, &b_goodElectrons_0_E);
   fChain->SetBranchAddress("goodElectrons_1_E", &goodElectrons_1_E, &b_goodElectrons_1_E);
   fChain->SetBranchAddress("goodElectrons_2_E", &goodElectrons_2_E, &b_goodElectrons_2_E);
   fChain->SetBranchAddress("goodElectrons_3_E", &goodElectrons_3_E, &b_goodElectrons_3_E);
   fChain->SetBranchAddress("goodElectrons_4_E", &goodElectrons_4_E, &b_goodElectrons_4_E);
   fChain->SetBranchAddress("goodElectrons_5_E", &goodElectrons_5_E, &b_goodElectrons_5_E);
   fChain->SetBranchAddress("goodElectrons_6_E", &goodElectrons_6_E, &b_goodElectrons_6_E);
   fChain->SetBranchAddress("goodElectrons_7_E", &goodElectrons_7_E, &b_goodElectrons_7_E);
   fChain->SetBranchAddress("goodElectrons_8_E", &goodElectrons_8_E, &b_goodElectrons_8_E);
   fChain->SetBranchAddress("goodElectrons_9_E", &goodElectrons_9_E, &b_goodElectrons_9_E);
   fChain->SetBranchAddress("goodElectrons_0_pt", &goodElectrons_0_pt, &b_goodElectrons_0_pt);
   fChain->SetBranchAddress("goodElectrons_1_pt", &goodElectrons_1_pt, &b_goodElectrons_1_pt);
   fChain->SetBranchAddress("goodElectrons_2_pt", &goodElectrons_2_pt, &b_goodElectrons_2_pt);
   fChain->SetBranchAddress("goodElectrons_3_pt", &goodElectrons_3_pt, &b_goodElectrons_3_pt);
   fChain->SetBranchAddress("goodElectrons_4_pt", &goodElectrons_4_pt, &b_goodElectrons_4_pt);
   fChain->SetBranchAddress("goodElectrons_5_pt", &goodElectrons_5_pt, &b_goodElectrons_5_pt);
   fChain->SetBranchAddress("goodElectrons_6_pt", &goodElectrons_6_pt, &b_goodElectrons_6_pt);
   fChain->SetBranchAddress("goodElectrons_7_pt", &goodElectrons_7_pt, &b_goodElectrons_7_pt);
   fChain->SetBranchAddress("goodElectrons_8_pt", &goodElectrons_8_pt, &b_goodElectrons_8_pt);
   fChain->SetBranchAddress("goodElectrons_9_pt", &goodElectrons_9_pt, &b_goodElectrons_9_pt);
   fChain->SetBranchAddress("goodElectrons_0_px", &goodElectrons_0_px, &b_goodElectrons_0_px);
   fChain->SetBranchAddress("goodElectrons_1_px", &goodElectrons_1_px, &b_goodElectrons_1_px);
   fChain->SetBranchAddress("goodElectrons_2_px", &goodElectrons_2_px, &b_goodElectrons_2_px);
   fChain->SetBranchAddress("goodElectrons_3_px", &goodElectrons_3_px, &b_goodElectrons_3_px);
   fChain->SetBranchAddress("goodElectrons_4_px", &goodElectrons_4_px, &b_goodElectrons_4_px);
   fChain->SetBranchAddress("goodElectrons_5_px", &goodElectrons_5_px, &b_goodElectrons_5_px);
   fChain->SetBranchAddress("goodElectrons_6_px", &goodElectrons_6_px, &b_goodElectrons_6_px);
   fChain->SetBranchAddress("goodElectrons_7_px", &goodElectrons_7_px, &b_goodElectrons_7_px);
   fChain->SetBranchAddress("goodElectrons_8_px", &goodElectrons_8_px, &b_goodElectrons_8_px);
   fChain->SetBranchAddress("goodElectrons_9_px", &goodElectrons_9_px, &b_goodElectrons_9_px);
   fChain->SetBranchAddress("goodElectrons_0_py", &goodElectrons_0_py, &b_goodElectrons_0_py);
   fChain->SetBranchAddress("goodElectrons_1_py", &goodElectrons_1_py, &b_goodElectrons_1_py);
   fChain->SetBranchAddress("goodElectrons_2_py", &goodElectrons_2_py, &b_goodElectrons_2_py);
   fChain->SetBranchAddress("goodElectrons_3_py", &goodElectrons_3_py, &b_goodElectrons_3_py);
   fChain->SetBranchAddress("goodElectrons_4_py", &goodElectrons_4_py, &b_goodElectrons_4_py);
   fChain->SetBranchAddress("goodElectrons_5_py", &goodElectrons_5_py, &b_goodElectrons_5_py);
   fChain->SetBranchAddress("goodElectrons_6_py", &goodElectrons_6_py, &b_goodElectrons_6_py);
   fChain->SetBranchAddress("goodElectrons_7_py", &goodElectrons_7_py, &b_goodElectrons_7_py);
   fChain->SetBranchAddress("goodElectrons_8_py", &goodElectrons_8_py, &b_goodElectrons_8_py);
   fChain->SetBranchAddress("goodElectrons_9_py", &goodElectrons_9_py, &b_goodElectrons_9_py);
   fChain->SetBranchAddress("goodElectrons_0_pz", &goodElectrons_0_pz, &b_goodElectrons_0_pz);
   fChain->SetBranchAddress("goodElectrons_1_pz", &goodElectrons_1_pz, &b_goodElectrons_1_pz);
   fChain->SetBranchAddress("goodElectrons_2_pz", &goodElectrons_2_pz, &b_goodElectrons_2_pz);
   fChain->SetBranchAddress("goodElectrons_3_pz", &goodElectrons_3_pz, &b_goodElectrons_3_pz);
   fChain->SetBranchAddress("goodElectrons_4_pz", &goodElectrons_4_pz, &b_goodElectrons_4_pz);
   fChain->SetBranchAddress("goodElectrons_5_pz", &goodElectrons_5_pz, &b_goodElectrons_5_pz);
   fChain->SetBranchAddress("goodElectrons_6_pz", &goodElectrons_6_pz, &b_goodElectrons_6_pz);
   fChain->SetBranchAddress("goodElectrons_7_pz", &goodElectrons_7_pz, &b_goodElectrons_7_pz);
   fChain->SetBranchAddress("goodElectrons_8_pz", &goodElectrons_8_pz, &b_goodElectrons_8_pz);
   fChain->SetBranchAddress("goodElectrons_9_pz", &goodElectrons_9_pz, &b_goodElectrons_9_pz);
   fChain->SetBranchAddress("goodElectrons_0_eta", &goodElectrons_0_eta, &b_goodElectrons_0_eta);
   fChain->SetBranchAddress("goodElectrons_1_eta", &goodElectrons_1_eta, &b_goodElectrons_1_eta);
   fChain->SetBranchAddress("goodElectrons_2_eta", &goodElectrons_2_eta, &b_goodElectrons_2_eta);
   fChain->SetBranchAddress("goodElectrons_3_eta", &goodElectrons_3_eta, &b_goodElectrons_3_eta);
   fChain->SetBranchAddress("goodElectrons_4_eta", &goodElectrons_4_eta, &b_goodElectrons_4_eta);
   fChain->SetBranchAddress("goodElectrons_5_eta", &goodElectrons_5_eta, &b_goodElectrons_5_eta);
   fChain->SetBranchAddress("goodElectrons_6_eta", &goodElectrons_6_eta, &b_goodElectrons_6_eta);
   fChain->SetBranchAddress("goodElectrons_7_eta", &goodElectrons_7_eta, &b_goodElectrons_7_eta);
   fChain->SetBranchAddress("goodElectrons_8_eta", &goodElectrons_8_eta, &b_goodElectrons_8_eta);
   fChain->SetBranchAddress("goodElectrons_9_eta", &goodElectrons_9_eta, &b_goodElectrons_9_eta);
   fChain->SetBranchAddress("goodElectrons_0_phi", &goodElectrons_0_phi, &b_goodElectrons_0_phi);
   fChain->SetBranchAddress("goodElectrons_1_phi", &goodElectrons_1_phi, &b_goodElectrons_1_phi);
   fChain->SetBranchAddress("goodElectrons_2_phi", &goodElectrons_2_phi, &b_goodElectrons_2_phi);
   fChain->SetBranchAddress("goodElectrons_3_phi", &goodElectrons_3_phi, &b_goodElectrons_3_phi);
   fChain->SetBranchAddress("goodElectrons_4_phi", &goodElectrons_4_phi, &b_goodElectrons_4_phi);
   fChain->SetBranchAddress("goodElectrons_5_phi", &goodElectrons_5_phi, &b_goodElectrons_5_phi);
   fChain->SetBranchAddress("goodElectrons_6_phi", &goodElectrons_6_phi, &b_goodElectrons_6_phi);
   fChain->SetBranchAddress("goodElectrons_7_phi", &goodElectrons_7_phi, &b_goodElectrons_7_phi);
   fChain->SetBranchAddress("goodElectrons_8_phi", &goodElectrons_8_phi, &b_goodElectrons_8_phi);
   fChain->SetBranchAddress("goodElectrons_9_phi", &goodElectrons_9_phi, &b_goodElectrons_9_phi);
   fChain->SetBranchAddress("goodElectrons_0_passLooseId", &goodElectrons_0_passLooseId, &b_goodElectrons_0_passLooseId);
   fChain->SetBranchAddress("goodElectrons_1_passLooseId", &goodElectrons_1_passLooseId, &b_goodElectrons_1_passLooseId);
   fChain->SetBranchAddress("goodElectrons_2_passLooseId", &goodElectrons_2_passLooseId, &b_goodElectrons_2_passLooseId);
   fChain->SetBranchAddress("goodElectrons_3_passLooseId", &goodElectrons_3_passLooseId, &b_goodElectrons_3_passLooseId);
   fChain->SetBranchAddress("goodElectrons_4_passLooseId", &goodElectrons_4_passLooseId, &b_goodElectrons_4_passLooseId);
   fChain->SetBranchAddress("goodElectrons_5_passLooseId", &goodElectrons_5_passLooseId, &b_goodElectrons_5_passLooseId);
   fChain->SetBranchAddress("goodElectrons_6_passLooseId", &goodElectrons_6_passLooseId, &b_goodElectrons_6_passLooseId);
   fChain->SetBranchAddress("goodElectrons_7_passLooseId", &goodElectrons_7_passLooseId, &b_goodElectrons_7_passLooseId);
   fChain->SetBranchAddress("goodElectrons_8_passLooseId", &goodElectrons_8_passLooseId, &b_goodElectrons_8_passLooseId);
   fChain->SetBranchAddress("goodElectrons_9_passLooseId", &goodElectrons_9_passLooseId, &b_goodElectrons_9_passLooseId);
   fChain->SetBranchAddress("goodElectrons_0_passMediumId", &goodElectrons_0_passMediumId, &b_goodElectrons_0_passMediumId);
   fChain->SetBranchAddress("goodElectrons_1_passMediumId", &goodElectrons_1_passMediumId, &b_goodElectrons_1_passMediumId);
   fChain->SetBranchAddress("goodElectrons_2_passMediumId", &goodElectrons_2_passMediumId, &b_goodElectrons_2_passMediumId);
   fChain->SetBranchAddress("goodElectrons_3_passMediumId", &goodElectrons_3_passMediumId, &b_goodElectrons_3_passMediumId);
   fChain->SetBranchAddress("goodElectrons_4_passMediumId", &goodElectrons_4_passMediumId, &b_goodElectrons_4_passMediumId);
   fChain->SetBranchAddress("goodElectrons_5_passMediumId", &goodElectrons_5_passMediumId, &b_goodElectrons_5_passMediumId);
   fChain->SetBranchAddress("goodElectrons_6_passMediumId", &goodElectrons_6_passMediumId, &b_goodElectrons_6_passMediumId);
   fChain->SetBranchAddress("goodElectrons_7_passMediumId", &goodElectrons_7_passMediumId, &b_goodElectrons_7_passMediumId);
   fChain->SetBranchAddress("goodElectrons_8_passMediumId", &goodElectrons_8_passMediumId, &b_goodElectrons_8_passMediumId);
   fChain->SetBranchAddress("goodElectrons_9_passMediumId", &goodElectrons_9_passMediumId, &b_goodElectrons_9_passMediumId);
   fChain->SetBranchAddress("goodElectrons_0_passTightId", &goodElectrons_0_passTightId, &b_goodElectrons_0_passTightId);
   fChain->SetBranchAddress("goodElectrons_1_passTightId", &goodElectrons_1_passTightId, &b_goodElectrons_1_passTightId);
   fChain->SetBranchAddress("goodElectrons_2_passTightId", &goodElectrons_2_passTightId, &b_goodElectrons_2_passTightId);
   fChain->SetBranchAddress("goodElectrons_3_passTightId", &goodElectrons_3_passTightId, &b_goodElectrons_3_passTightId);
   fChain->SetBranchAddress("goodElectrons_4_passTightId", &goodElectrons_4_passTightId, &b_goodElectrons_4_passTightId);
   fChain->SetBranchAddress("goodElectrons_5_passTightId", &goodElectrons_5_passTightId, &b_goodElectrons_5_passTightId);
   fChain->SetBranchAddress("goodElectrons_6_passTightId", &goodElectrons_6_passTightId, &b_goodElectrons_6_passTightId);
   fChain->SetBranchAddress("goodElectrons_7_passTightId", &goodElectrons_7_passTightId, &b_goodElectrons_7_passTightId);
   fChain->SetBranchAddress("goodElectrons_8_passTightId", &goodElectrons_8_passTightId, &b_goodElectrons_8_passTightId);
   fChain->SetBranchAddress("goodElectrons_9_passTightId", &goodElectrons_9_passTightId, &b_goodElectrons_9_passTightId);
   fChain->SetBranchAddress("goodElectrons_0_passMVALooseId", &goodElectrons_0_passMVALooseId, &b_goodElectrons_0_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_1_passMVALooseId", &goodElectrons_1_passMVALooseId, &b_goodElectrons_1_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_2_passMVALooseId", &goodElectrons_2_passMVALooseId, &b_goodElectrons_2_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_3_passMVALooseId", &goodElectrons_3_passMVALooseId, &b_goodElectrons_3_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_4_passMVALooseId", &goodElectrons_4_passMVALooseId, &b_goodElectrons_4_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_5_passMVALooseId", &goodElectrons_5_passMVALooseId, &b_goodElectrons_5_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_6_passMVALooseId", &goodElectrons_6_passMVALooseId, &b_goodElectrons_6_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_7_passMVALooseId", &goodElectrons_7_passMVALooseId, &b_goodElectrons_7_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_8_passMVALooseId", &goodElectrons_8_passMVALooseId, &b_goodElectrons_8_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_9_passMVALooseId", &goodElectrons_9_passMVALooseId, &b_goodElectrons_9_passMVALooseId);
   fChain->SetBranchAddress("goodElectrons_0_passMVAMediumId", &goodElectrons_0_passMVAMediumId, &b_goodElectrons_0_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_1_passMVAMediumId", &goodElectrons_1_passMVAMediumId, &b_goodElectrons_1_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_2_passMVAMediumId", &goodElectrons_2_passMVAMediumId, &b_goodElectrons_2_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_3_passMVAMediumId", &goodElectrons_3_passMVAMediumId, &b_goodElectrons_3_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_4_passMVAMediumId", &goodElectrons_4_passMVAMediumId, &b_goodElectrons_4_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_5_passMVAMediumId", &goodElectrons_5_passMVAMediumId, &b_goodElectrons_5_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_6_passMVAMediumId", &goodElectrons_6_passMVAMediumId, &b_goodElectrons_6_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_7_passMVAMediumId", &goodElectrons_7_passMVAMediumId, &b_goodElectrons_7_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_8_passMVAMediumId", &goodElectrons_8_passMVAMediumId, &b_goodElectrons_8_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_9_passMVAMediumId", &goodElectrons_9_passMVAMediumId, &b_goodElectrons_9_passMVAMediumId);
   fChain->SetBranchAddress("goodElectrons_0_passMVATightId", &goodElectrons_0_passMVATightId, &b_goodElectrons_0_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_1_passMVATightId", &goodElectrons_1_passMVATightId, &b_goodElectrons_1_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_2_passMVATightId", &goodElectrons_2_passMVATightId, &b_goodElectrons_2_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_3_passMVATightId", &goodElectrons_3_passMVATightId, &b_goodElectrons_3_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_4_passMVATightId", &goodElectrons_4_passMVATightId, &b_goodElectrons_4_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_5_passMVATightId", &goodElectrons_5_passMVATightId, &b_goodElectrons_5_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_6_passMVATightId", &goodElectrons_6_passMVATightId, &b_goodElectrons_6_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_7_passMVATightId", &goodElectrons_7_passMVATightId, &b_goodElectrons_7_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_8_passMVATightId", &goodElectrons_8_passMVATightId, &b_goodElectrons_8_passMVATightId);
   fChain->SetBranchAddress("goodElectrons_9_passMVATightId", &goodElectrons_9_passMVATightId, &b_goodElectrons_9_passMVATightId);
   fChain->SetBranchAddress("N_goodMuons", &N_goodMuons, &b_N_goodMuons);
   fChain->SetBranchAddress("goodMuons_0_E", &goodMuons_0_E, &b_goodMuons_0_E);
   fChain->SetBranchAddress("goodMuons_1_E", &goodMuons_1_E, &b_goodMuons_1_E);
   fChain->SetBranchAddress("goodMuons_2_E", &goodMuons_2_E, &b_goodMuons_2_E);
   fChain->SetBranchAddress("goodMuons_3_E", &goodMuons_3_E, &b_goodMuons_3_E);
   fChain->SetBranchAddress("goodMuons_4_E", &goodMuons_4_E, &b_goodMuons_4_E);
   fChain->SetBranchAddress("goodMuons_5_E", &goodMuons_5_E, &b_goodMuons_5_E);
   fChain->SetBranchAddress("goodMuons_6_E", &goodMuons_6_E, &b_goodMuons_6_E);
   fChain->SetBranchAddress("goodMuons_7_E", &goodMuons_7_E, &b_goodMuons_7_E);
   fChain->SetBranchAddress("goodMuons_8_E", &goodMuons_8_E, &b_goodMuons_8_E);
   fChain->SetBranchAddress("goodMuons_9_E", &goodMuons_9_E, &b_goodMuons_9_E);
   fChain->SetBranchAddress("goodMuons_0_pt", &goodMuons_0_pt, &b_goodMuons_0_pt);
   fChain->SetBranchAddress("goodMuons_1_pt", &goodMuons_1_pt, &b_goodMuons_1_pt);
   fChain->SetBranchAddress("goodMuons_2_pt", &goodMuons_2_pt, &b_goodMuons_2_pt);
   fChain->SetBranchAddress("goodMuons_3_pt", &goodMuons_3_pt, &b_goodMuons_3_pt);
   fChain->SetBranchAddress("goodMuons_4_pt", &goodMuons_4_pt, &b_goodMuons_4_pt);
   fChain->SetBranchAddress("goodMuons_5_pt", &goodMuons_5_pt, &b_goodMuons_5_pt);
   fChain->SetBranchAddress("goodMuons_6_pt", &goodMuons_6_pt, &b_goodMuons_6_pt);
   fChain->SetBranchAddress("goodMuons_7_pt", &goodMuons_7_pt, &b_goodMuons_7_pt);
   fChain->SetBranchAddress("goodMuons_8_pt", &goodMuons_8_pt, &b_goodMuons_8_pt);
   fChain->SetBranchAddress("goodMuons_9_pt", &goodMuons_9_pt, &b_goodMuons_9_pt);
   fChain->SetBranchAddress("goodMuons_0_px", &goodMuons_0_px, &b_goodMuons_0_px);
   fChain->SetBranchAddress("goodMuons_1_px", &goodMuons_1_px, &b_goodMuons_1_px);
   fChain->SetBranchAddress("goodMuons_2_px", &goodMuons_2_px, &b_goodMuons_2_px);
   fChain->SetBranchAddress("goodMuons_3_px", &goodMuons_3_px, &b_goodMuons_3_px);
   fChain->SetBranchAddress("goodMuons_4_px", &goodMuons_4_px, &b_goodMuons_4_px);
   fChain->SetBranchAddress("goodMuons_5_px", &goodMuons_5_px, &b_goodMuons_5_px);
   fChain->SetBranchAddress("goodMuons_6_px", &goodMuons_6_px, &b_goodMuons_6_px);
   fChain->SetBranchAddress("goodMuons_7_px", &goodMuons_7_px, &b_goodMuons_7_px);
   fChain->SetBranchAddress("goodMuons_8_px", &goodMuons_8_px, &b_goodMuons_8_px);
   fChain->SetBranchAddress("goodMuons_9_px", &goodMuons_9_px, &b_goodMuons_9_px);
   fChain->SetBranchAddress("goodMuons_0_py", &goodMuons_0_py, &b_goodMuons_0_py);
   fChain->SetBranchAddress("goodMuons_1_py", &goodMuons_1_py, &b_goodMuons_1_py);
   fChain->SetBranchAddress("goodMuons_2_py", &goodMuons_2_py, &b_goodMuons_2_py);
   fChain->SetBranchAddress("goodMuons_3_py", &goodMuons_3_py, &b_goodMuons_3_py);
   fChain->SetBranchAddress("goodMuons_4_py", &goodMuons_4_py, &b_goodMuons_4_py);
   fChain->SetBranchAddress("goodMuons_5_py", &goodMuons_5_py, &b_goodMuons_5_py);
   fChain->SetBranchAddress("goodMuons_6_py", &goodMuons_6_py, &b_goodMuons_6_py);
   fChain->SetBranchAddress("goodMuons_7_py", &goodMuons_7_py, &b_goodMuons_7_py);
   fChain->SetBranchAddress("goodMuons_8_py", &goodMuons_8_py, &b_goodMuons_8_py);
   fChain->SetBranchAddress("goodMuons_9_py", &goodMuons_9_py, &b_goodMuons_9_py);
   fChain->SetBranchAddress("goodMuons_0_pz", &goodMuons_0_pz, &b_goodMuons_0_pz);
   fChain->SetBranchAddress("goodMuons_1_pz", &goodMuons_1_pz, &b_goodMuons_1_pz);
   fChain->SetBranchAddress("goodMuons_2_pz", &goodMuons_2_pz, &b_goodMuons_2_pz);
   fChain->SetBranchAddress("goodMuons_3_pz", &goodMuons_3_pz, &b_goodMuons_3_pz);
   fChain->SetBranchAddress("goodMuons_4_pz", &goodMuons_4_pz, &b_goodMuons_4_pz);
   fChain->SetBranchAddress("goodMuons_5_pz", &goodMuons_5_pz, &b_goodMuons_5_pz);
   fChain->SetBranchAddress("goodMuons_6_pz", &goodMuons_6_pz, &b_goodMuons_6_pz);
   fChain->SetBranchAddress("goodMuons_7_pz", &goodMuons_7_pz, &b_goodMuons_7_pz);
   fChain->SetBranchAddress("goodMuons_8_pz", &goodMuons_8_pz, &b_goodMuons_8_pz);
   fChain->SetBranchAddress("goodMuons_9_pz", &goodMuons_9_pz, &b_goodMuons_9_pz);
   fChain->SetBranchAddress("goodMuons_0_eta", &goodMuons_0_eta, &b_goodMuons_0_eta);
   fChain->SetBranchAddress("goodMuons_1_eta", &goodMuons_1_eta, &b_goodMuons_1_eta);
   fChain->SetBranchAddress("goodMuons_2_eta", &goodMuons_2_eta, &b_goodMuons_2_eta);
   fChain->SetBranchAddress("goodMuons_3_eta", &goodMuons_3_eta, &b_goodMuons_3_eta);
   fChain->SetBranchAddress("goodMuons_4_eta", &goodMuons_4_eta, &b_goodMuons_4_eta);
   fChain->SetBranchAddress("goodMuons_5_eta", &goodMuons_5_eta, &b_goodMuons_5_eta);
   fChain->SetBranchAddress("goodMuons_6_eta", &goodMuons_6_eta, &b_goodMuons_6_eta);
   fChain->SetBranchAddress("goodMuons_7_eta", &goodMuons_7_eta, &b_goodMuons_7_eta);
   fChain->SetBranchAddress("goodMuons_8_eta", &goodMuons_8_eta, &b_goodMuons_8_eta);
   fChain->SetBranchAddress("goodMuons_9_eta", &goodMuons_9_eta, &b_goodMuons_9_eta);
   fChain->SetBranchAddress("goodMuons_0_phi", &goodMuons_0_phi, &b_goodMuons_0_phi);
   fChain->SetBranchAddress("goodMuons_1_phi", &goodMuons_1_phi, &b_goodMuons_1_phi);
   fChain->SetBranchAddress("goodMuons_2_phi", &goodMuons_2_phi, &b_goodMuons_2_phi);
   fChain->SetBranchAddress("goodMuons_3_phi", &goodMuons_3_phi, &b_goodMuons_3_phi);
   fChain->SetBranchAddress("goodMuons_4_phi", &goodMuons_4_phi, &b_goodMuons_4_phi);
   fChain->SetBranchAddress("goodMuons_5_phi", &goodMuons_5_phi, &b_goodMuons_5_phi);
   fChain->SetBranchAddress("goodMuons_6_phi", &goodMuons_6_phi, &b_goodMuons_6_phi);
   fChain->SetBranchAddress("goodMuons_7_phi", &goodMuons_7_phi, &b_goodMuons_7_phi);
   fChain->SetBranchAddress("goodMuons_8_phi", &goodMuons_8_phi, &b_goodMuons_8_phi);
   fChain->SetBranchAddress("goodMuons_9_phi", &goodMuons_9_phi, &b_goodMuons_9_phi);
   fChain->SetBranchAddress("N_goodJets", &N_goodJets, &b_N_goodJets);
   fChain->SetBranchAddress("goodJets_0_E", &goodJets_0_E, &b_goodJets_0_E);
   fChain->SetBranchAddress("goodJets_1_E", &goodJets_1_E, &b_goodJets_1_E);
   fChain->SetBranchAddress("goodJets_2_E", &goodJets_2_E, &b_goodJets_2_E);
   fChain->SetBranchAddress("goodJets_3_E", &goodJets_3_E, &b_goodJets_3_E);
   fChain->SetBranchAddress("goodJets_4_E", &goodJets_4_E, &b_goodJets_4_E);
   fChain->SetBranchAddress("goodJets_5_E", &goodJets_5_E, &b_goodJets_5_E);
   fChain->SetBranchAddress("goodJets_6_E", &goodJets_6_E, &b_goodJets_6_E);
   fChain->SetBranchAddress("goodJets_7_E", &goodJets_7_E, &b_goodJets_7_E);
   fChain->SetBranchAddress("goodJets_8_E", &goodJets_8_E, &b_goodJets_8_E);
   fChain->SetBranchAddress("goodJets_9_E", &goodJets_9_E, &b_goodJets_9_E);
   fChain->SetBranchAddress("goodJets_0_pt", &goodJets_0_pt, &b_goodJets_0_pt);
   fChain->SetBranchAddress("goodJets_1_pt", &goodJets_1_pt, &b_goodJets_1_pt);
   fChain->SetBranchAddress("goodJets_2_pt", &goodJets_2_pt, &b_goodJets_2_pt);
   fChain->SetBranchAddress("goodJets_3_pt", &goodJets_3_pt, &b_goodJets_3_pt);
   fChain->SetBranchAddress("goodJets_4_pt", &goodJets_4_pt, &b_goodJets_4_pt);
   fChain->SetBranchAddress("goodJets_5_pt", &goodJets_5_pt, &b_goodJets_5_pt);
   fChain->SetBranchAddress("goodJets_6_pt", &goodJets_6_pt, &b_goodJets_6_pt);
   fChain->SetBranchAddress("goodJets_7_pt", &goodJets_7_pt, &b_goodJets_7_pt);
   fChain->SetBranchAddress("goodJets_8_pt", &goodJets_8_pt, &b_goodJets_8_pt);
   fChain->SetBranchAddress("goodJets_9_pt", &goodJets_9_pt, &b_goodJets_9_pt);
   fChain->SetBranchAddress("goodJets_0_px", &goodJets_0_px, &b_goodJets_0_px);
   fChain->SetBranchAddress("goodJets_1_px", &goodJets_1_px, &b_goodJets_1_px);
   fChain->SetBranchAddress("goodJets_2_px", &goodJets_2_px, &b_goodJets_2_px);
   fChain->SetBranchAddress("goodJets_3_px", &goodJets_3_px, &b_goodJets_3_px);
   fChain->SetBranchAddress("goodJets_4_px", &goodJets_4_px, &b_goodJets_4_px);
   fChain->SetBranchAddress("goodJets_5_px", &goodJets_5_px, &b_goodJets_5_px);
   fChain->SetBranchAddress("goodJets_6_px", &goodJets_6_px, &b_goodJets_6_px);
   fChain->SetBranchAddress("goodJets_7_px", &goodJets_7_px, &b_goodJets_7_px);
   fChain->SetBranchAddress("goodJets_8_px", &goodJets_8_px, &b_goodJets_8_px);
   fChain->SetBranchAddress("goodJets_9_px", &goodJets_9_px, &b_goodJets_9_px);
   fChain->SetBranchAddress("goodJets_0_py", &goodJets_0_py, &b_goodJets_0_py);
   fChain->SetBranchAddress("goodJets_1_py", &goodJets_1_py, &b_goodJets_1_py);
   fChain->SetBranchAddress("goodJets_2_py", &goodJets_2_py, &b_goodJets_2_py);
   fChain->SetBranchAddress("goodJets_3_py", &goodJets_3_py, &b_goodJets_3_py);
   fChain->SetBranchAddress("goodJets_4_py", &goodJets_4_py, &b_goodJets_4_py);
   fChain->SetBranchAddress("goodJets_5_py", &goodJets_5_py, &b_goodJets_5_py);
   fChain->SetBranchAddress("goodJets_6_py", &goodJets_6_py, &b_goodJets_6_py);
   fChain->SetBranchAddress("goodJets_7_py", &goodJets_7_py, &b_goodJets_7_py);
   fChain->SetBranchAddress("goodJets_8_py", &goodJets_8_py, &b_goodJets_8_py);
   fChain->SetBranchAddress("goodJets_9_py", &goodJets_9_py, &b_goodJets_9_py);
   fChain->SetBranchAddress("goodJets_0_pz", &goodJets_0_pz, &b_goodJets_0_pz);
   fChain->SetBranchAddress("goodJets_1_pz", &goodJets_1_pz, &b_goodJets_1_pz);
   fChain->SetBranchAddress("goodJets_2_pz", &goodJets_2_pz, &b_goodJets_2_pz);
   fChain->SetBranchAddress("goodJets_3_pz", &goodJets_3_pz, &b_goodJets_3_pz);
   fChain->SetBranchAddress("goodJets_4_pz", &goodJets_4_pz, &b_goodJets_4_pz);
   fChain->SetBranchAddress("goodJets_5_pz", &goodJets_5_pz, &b_goodJets_5_pz);
   fChain->SetBranchAddress("goodJets_6_pz", &goodJets_6_pz, &b_goodJets_6_pz);
   fChain->SetBranchAddress("goodJets_7_pz", &goodJets_7_pz, &b_goodJets_7_pz);
   fChain->SetBranchAddress("goodJets_8_pz", &goodJets_8_pz, &b_goodJets_8_pz);
   fChain->SetBranchAddress("goodJets_9_pz", &goodJets_9_pz, &b_goodJets_9_pz);
   fChain->SetBranchAddress("goodJets_0_eta", &goodJets_0_eta, &b_goodJets_0_eta);
   fChain->SetBranchAddress("goodJets_1_eta", &goodJets_1_eta, &b_goodJets_1_eta);
   fChain->SetBranchAddress("goodJets_2_eta", &goodJets_2_eta, &b_goodJets_2_eta);
   fChain->SetBranchAddress("goodJets_3_eta", &goodJets_3_eta, &b_goodJets_3_eta);
   fChain->SetBranchAddress("goodJets_4_eta", &goodJets_4_eta, &b_goodJets_4_eta);
   fChain->SetBranchAddress("goodJets_5_eta", &goodJets_5_eta, &b_goodJets_5_eta);
   fChain->SetBranchAddress("goodJets_6_eta", &goodJets_6_eta, &b_goodJets_6_eta);
   fChain->SetBranchAddress("goodJets_7_eta", &goodJets_7_eta, &b_goodJets_7_eta);
   fChain->SetBranchAddress("goodJets_8_eta", &goodJets_8_eta, &b_goodJets_8_eta);
   fChain->SetBranchAddress("goodJets_9_eta", &goodJets_9_eta, &b_goodJets_9_eta);
   fChain->SetBranchAddress("goodJets_0_phi", &goodJets_0_phi, &b_goodJets_0_phi);
   fChain->SetBranchAddress("goodJets_1_phi", &goodJets_1_phi, &b_goodJets_1_phi);
   fChain->SetBranchAddress("goodJets_2_phi", &goodJets_2_phi, &b_goodJets_2_phi);
   fChain->SetBranchAddress("goodJets_3_phi", &goodJets_3_phi, &b_goodJets_3_phi);
   fChain->SetBranchAddress("goodJets_4_phi", &goodJets_4_phi, &b_goodJets_4_phi);
   fChain->SetBranchAddress("goodJets_5_phi", &goodJets_5_phi, &b_goodJets_5_phi);
   fChain->SetBranchAddress("goodJets_6_phi", &goodJets_6_phi, &b_goodJets_6_phi);
   fChain->SetBranchAddress("goodJets_7_phi", &goodJets_7_phi, &b_goodJets_7_phi);
   fChain->SetBranchAddress("goodJets_8_phi", &goodJets_8_phi, &b_goodJets_8_phi);
   fChain->SetBranchAddress("goodJets_9_phi", &goodJets_9_phi, &b_goodJets_9_phi);
   fChain->SetBranchAddress("goodJets_0_PassLooseJetPUID", &goodJets_0_PassLooseJetPUID, &b_goodJets_0_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_0_PassMediumJetPUID", &goodJets_0_PassMediumJetPUID, &b_goodJets_0_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_0_PassTightJetPUID", &goodJets_0_PassTightJetPUID, &b_goodJets_0_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_1_PassLooseJetPUID", &goodJets_1_PassLooseJetPUID, &b_goodJets_1_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_1_PassMediumJetPUID", &goodJets_1_PassMediumJetPUID, &b_goodJets_1_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_1_PassTightJetPUID", &goodJets_1_PassTightJetPUID, &b_goodJets_1_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_2_PassLooseJetPUID", &goodJets_2_PassLooseJetPUID, &b_goodJets_2_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_2_PassMediumJetPUID", &goodJets_2_PassMediumJetPUID, &b_goodJets_2_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_2_PassTightJetPUID", &goodJets_2_PassTightJetPUID, &b_goodJets_2_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_3_PassLooseJetPUID", &goodJets_3_PassLooseJetPUID, &b_goodJets_3_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_3_PassMediumJetPUID", &goodJets_3_PassMediumJetPUID, &b_goodJets_3_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_3_PassTightJetPUID", &goodJets_3_PassTightJetPUID, &b_goodJets_3_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_4_PassLooseJetPUID", &goodJets_4_PassLooseJetPUID, &b_goodJets_4_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_4_PassMediumJetPUID", &goodJets_4_PassMediumJetPUID, &b_goodJets_4_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_4_PassTightJetPUID", &goodJets_4_PassTightJetPUID, &b_goodJets_4_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_5_PassLooseJetPUID", &goodJets_5_PassLooseJetPUID, &b_goodJets_5_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_5_PassMediumJetPUID", &goodJets_5_PassMediumJetPUID, &b_goodJets_5_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_5_PassTightJetPUID", &goodJets_5_PassTightJetPUID, &b_goodJets_5_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_6_PassLooseJetPUID", &goodJets_6_PassLooseJetPUID, &b_goodJets_6_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_6_PassMediumJetPUID", &goodJets_6_PassMediumJetPUID, &b_goodJets_6_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_6_PassTightJetPUID", &goodJets_6_PassTightJetPUID, &b_goodJets_6_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_7_PassLooseJetPUID", &goodJets_7_PassLooseJetPUID, &b_goodJets_7_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_7_PassMediumJetPUID", &goodJets_7_PassMediumJetPUID, &b_goodJets_7_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_7_PassTightJetPUID", &goodJets_7_PassTightJetPUID, &b_goodJets_7_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_8_PassLooseJetPUID", &goodJets_8_PassLooseJetPUID, &b_goodJets_8_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_8_PassMediumJetPUID", &goodJets_8_PassMediumJetPUID, &b_goodJets_8_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_8_PassTightJetPUID", &goodJets_8_PassTightJetPUID, &b_goodJets_8_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_9_PassLooseJetPUID", &goodJets_9_PassLooseJetPUID, &b_goodJets_9_PassLooseJetPUID);
   fChain->SetBranchAddress("goodJets_9_PassMediumJetPUID", &goodJets_9_PassMediumJetPUID, &b_goodJets_9_PassMediumJetPUID);
   fChain->SetBranchAddress("goodJets_9_PassTightJetPUID", &goodJets_9_PassTightJetPUID, &b_goodJets_9_PassTightJetPUID);
   fChain->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb, &b_goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
   fChain->SetBranchAddress("goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb", &goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb, &b_goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb);
   fChain->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb, &b_goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
   fChain->SetBranchAddress("goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb", &goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb, &b_goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb);
   fChain->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb, &b_goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
   fChain->SetBranchAddress("Leading_Photon_genMatchType", &Leading_Photon_genMatchType, &b_Leading_Photon_genMatchType);
   fChain->SetBranchAddress("Subleading_Photon_genMatchType", &Subleading_Photon_genMatchType, &b_Subleading_Photon_genMatchType);
   fChain->SetBranchAddress("dipho_MVA", &dipho_MVA, &b_dipho_MVA);
   fChain->SetBranchAddress("dipho_pt", &dipho_pt, &b_dipho_pt);
   fChain->SetBranchAddress("allMuons_0_isLooseMuon", &allMuons_0_isLooseMuon, &b_allMuons_0_isLooseMuon);
   fChain->SetBranchAddress("allMuons_0_isMediumMuon", &allMuons_0_isMediumMuon, &b_allMuons_0_isMediumMuon);
   fChain->SetBranchAddress("allMuons_0_isTightMuon", &allMuons_0_isTightMuon, &b_allMuons_0_isTightMuon);
   fChain->SetBranchAddress("allMuons_0_isSoftMuon", &allMuons_0_isSoftMuon, &b_allMuons_0_isSoftMuon);
   fChain->SetBranchAddress("allMuons_0_isHighPtMuon", &allMuons_0_isHighPtMuon, &b_allMuons_0_isHighPtMuon);
   fChain->SetBranchAddress("allMuons_0_muonIso", &allMuons_0_muonIso, &b_allMuons_0_muonIso);
   fChain->SetBranchAddress("allMuons_1_isLooseMuon", &allMuons_1_isLooseMuon, &b_allMuons_1_isLooseMuon);
   fChain->SetBranchAddress("allMuons_1_isMediumMuon", &allMuons_1_isMediumMuon, &b_allMuons_1_isMediumMuon);
   fChain->SetBranchAddress("allMuons_1_isTightMuon", &allMuons_1_isTightMuon, &b_allMuons_1_isTightMuon);
   fChain->SetBranchAddress("allMuons_1_isSoftMuon", &allMuons_1_isSoftMuon, &b_allMuons_1_isSoftMuon);
   fChain->SetBranchAddress("allMuons_1_isHighPtMuon", &allMuons_1_isHighPtMuon, &b_allMuons_1_isHighPtMuon);
   fChain->SetBranchAddress("allMuons_1_muonIso", &allMuons_1_muonIso, &b_allMuons_1_muonIso);
   fChain->SetBranchAddress("allMuons_2_isLooseMuon", &allMuons_2_isLooseMuon, &b_allMuons_2_isLooseMuon);
   fChain->SetBranchAddress("allMuons_2_isMediumMuon", &allMuons_2_isMediumMuon, &b_allMuons_2_isMediumMuon);
   fChain->SetBranchAddress("allMuons_2_isTightMuon", &allMuons_2_isTightMuon, &b_allMuons_2_isTightMuon);
   fChain->SetBranchAddress("allMuons_2_isSoftMuon", &allMuons_2_isSoftMuon, &b_allMuons_2_isSoftMuon);
   fChain->SetBranchAddress("allMuons_2_isHighPtMuon", &allMuons_2_isHighPtMuon, &b_allMuons_2_isHighPtMuon);
   fChain->SetBranchAddress("allMuons_2_muonIso", &allMuons_2_muonIso, &b_allMuons_2_muonIso);
   fChain->SetBranchAddress("allMuons_3_isLooseMuon", &allMuons_3_isLooseMuon, &b_allMuons_3_isLooseMuon);
   fChain->SetBranchAddress("allMuons_3_isMediumMuon", &allMuons_3_isMediumMuon, &b_allMuons_3_isMediumMuon);
   fChain->SetBranchAddress("allMuons_3_isTightMuon", &allMuons_3_isTightMuon, &b_allMuons_3_isTightMuon);
   fChain->SetBranchAddress("allMuons_3_isSoftMuon", &allMuons_3_isSoftMuon, &b_allMuons_3_isSoftMuon);
   fChain->SetBranchAddress("allMuons_3_isHighPtMuon", &allMuons_3_isHighPtMuon, &b_allMuons_3_isHighPtMuon);
   fChain->SetBranchAddress("allMuons_3_muonIso", &allMuons_3_muonIso, &b_allMuons_3_muonIso);
   fChain->SetBranchAddress("allMuons_4_isLooseMuon", &allMuons_4_isLooseMuon, &b_allMuons_4_isLooseMuon);
   fChain->SetBranchAddress("allMuons_4_isMediumMuon", &allMuons_4_isMediumMuon, &b_allMuons_4_isMediumMuon);
   fChain->SetBranchAddress("allMuons_4_isTightMuon", &allMuons_4_isTightMuon, &b_allMuons_4_isTightMuon);
   fChain->SetBranchAddress("allMuons_4_isSoftMuon", &allMuons_4_isSoftMuon, &b_allMuons_4_isSoftMuon);
   fChain->SetBranchAddress("allMuons_4_isHighPtMuon", &allMuons_4_isHighPtMuon, &b_allMuons_4_isHighPtMuon);
   fChain->SetBranchAddress("allMuons_4_muonIso", &allMuons_4_muonIso, &b_allMuons_4_muonIso);
   fChain->SetBranchAddress("allJets_0_passLoose", &allJets_0_passLoose, &b_allJets_0_passLoose);
   fChain->SetBranchAddress("allJets_0_passTight", &allJets_0_passTight, &b_allJets_0_passTight);
   fChain->SetBranchAddress("allJets_0_passTight2017", &allJets_0_passTight2017, &b_allJets_0_passTight2017);
   fChain->SetBranchAddress("allJets_0_passTight2018", &allJets_0_passTight2018, &b_allJets_0_passTight2018);
   fChain->SetBranchAddress("allJets_1_passLoose", &allJets_1_passLoose, &b_allJets_1_passLoose);
   fChain->SetBranchAddress("allJets_1_passTight", &allJets_1_passTight, &b_allJets_1_passTight);
   fChain->SetBranchAddress("allJets_1_passTight2017", &allJets_1_passTight2017, &b_allJets_1_passTight2017);
   fChain->SetBranchAddress("allJets_1_passTight2018", &allJets_1_passTight2018, &b_allJets_1_passTight2018);
   fChain->SetBranchAddress("allJets_2_passLoose", &allJets_2_passLoose, &b_allJets_2_passLoose);
   fChain->SetBranchAddress("allJets_2_passTight", &allJets_2_passTight, &b_allJets_2_passTight);
   fChain->SetBranchAddress("allJets_2_passTight2017", &allJets_2_passTight2017, &b_allJets_2_passTight2017);
   fChain->SetBranchAddress("allJets_2_passTight2018", &allJets_2_passTight2018, &b_allJets_2_passTight2018);
   fChain->SetBranchAddress("allJets_3_passLoose", &allJets_3_passLoose, &b_allJets_3_passLoose);
   fChain->SetBranchAddress("allJets_3_passTight", &allJets_3_passTight, &b_allJets_3_passTight);
   fChain->SetBranchAddress("allJets_3_passTight2017", &allJets_3_passTight2017, &b_allJets_3_passTight2017);
   fChain->SetBranchAddress("allJets_3_passTight2018", &allJets_3_passTight2018, &b_allJets_3_passTight2018);
   fChain->SetBranchAddress("allJets_4_passLoose", &allJets_4_passLoose, &b_allJets_4_passLoose);
   fChain->SetBranchAddress("allJets_4_passTight", &allJets_4_passTight, &b_allJets_4_passTight);
   fChain->SetBranchAddress("allJets_4_passTight2017", &allJets_4_passTight2017, &b_allJets_4_passTight2017);
   fChain->SetBranchAddress("allJets_4_passTight2018", &allJets_4_passTight2018, &b_allJets_4_passTight2018);
   fChain->SetBranchAddress("W1Candidate_E", &W1Candidate_E, &b_W1Candidate_E);
   fChain->SetBranchAddress("W1Candidate_M", &W1Candidate_M, &b_W1Candidate_M);
   fChain->SetBranchAddress("W1Candidate_pt", &W1Candidate_pt, &b_W1Candidate_pt);
   fChain->SetBranchAddress("W1Candidate_px", &W1Candidate_px, &b_W1Candidate_px);
   fChain->SetBranchAddress("W1Candidate_py", &W1Candidate_py, &b_W1Candidate_py);
   fChain->SetBranchAddress("W1Candidate_pz", &W1Candidate_pz, &b_W1Candidate_pz);
   fChain->SetBranchAddress("W1Candidate_eta", &W1Candidate_eta, &b_W1Candidate_eta);
   fChain->SetBranchAddress("W1Candidate_phi", &W1Candidate_phi, &b_W1Candidate_phi);
   fChain->SetBranchAddress("W2Candidate_E", &W2Candidate_E, &b_W2Candidate_E);
   fChain->SetBranchAddress("W2Candidate_M", &W2Candidate_M, &b_W2Candidate_M);
   fChain->SetBranchAddress("W2Candidate_pt", &W2Candidate_pt, &b_W2Candidate_pt);
   fChain->SetBranchAddress("W2Candidate_px", &W2Candidate_px, &b_W2Candidate_px);
   fChain->SetBranchAddress("W2Candidate_py", &W2Candidate_py, &b_W2Candidate_py);
   fChain->SetBranchAddress("W2Candidate_pz", &W2Candidate_pz, &b_W2Candidate_pz);
   fChain->SetBranchAddress("W2Candidate_eta", &W2Candidate_eta, &b_W2Candidate_eta);
   fChain->SetBranchAddress("W2Candidate_phi", &W2Candidate_phi, &b_W2Candidate_phi);
   fChain->SetBranchAddress("HWWCandidate_E", &HWWCandidate_E, &b_HWWCandidate_E);
   fChain->SetBranchAddress("HWWCandidate_M", &HWWCandidate_M, &b_HWWCandidate_M);
   fChain->SetBranchAddress("HWWCandidate_pt", &HWWCandidate_pt, &b_HWWCandidate_pt);
   fChain->SetBranchAddress("HWWCandidate_px", &HWWCandidate_px, &b_HWWCandidate_px);
   fChain->SetBranchAddress("HWWCandidate_py", &HWWCandidate_py, &b_HWWCandidate_py);
   fChain->SetBranchAddress("HWWCandidate_pz", &HWWCandidate_pz, &b_HWWCandidate_pz);
   fChain->SetBranchAddress("HWWCandidate_eta", &HWWCandidate_eta, &b_HWWCandidate_eta);
   fChain->SetBranchAddress("HWWCandidate_phi", &HWWCandidate_phi, &b_HWWCandidate_phi);
   fChain->SetBranchAddress("HGGCandidate_E", &HGGCandidate_E, &b_HGGCandidate_E);
   fChain->SetBranchAddress("HGGCandidate_M", &HGGCandidate_M, &b_HGGCandidate_M);
   fChain->SetBranchAddress("HGGCandidate_pt", &HGGCandidate_pt, &b_HGGCandidate_pt);
   fChain->SetBranchAddress("HGGCandidate_px", &HGGCandidate_px, &b_HGGCandidate_px);
   fChain->SetBranchAddress("HGGCandidate_py", &HGGCandidate_py, &b_HGGCandidate_py);
   fChain->SetBranchAddress("HGGCandidate_pz", &HGGCandidate_pz, &b_HGGCandidate_pz);
   fChain->SetBranchAddress("HGGCandidate_eta", &HGGCandidate_eta, &b_HGGCandidate_eta);
   fChain->SetBranchAddress("HGGCandidate_phi", &HGGCandidate_phi, &b_HGGCandidate_phi);
   fChain->SetBranchAddress("HHCandidate_E", &HHCandidate_E, &b_HHCandidate_E);
   fChain->SetBranchAddress("HHCandidate_M", &HHCandidate_M, &b_HHCandidate_M);
   fChain->SetBranchAddress("HHCandidate_pt", &HHCandidate_pt, &b_HHCandidate_pt);
   fChain->SetBranchAddress("HHCandidate_px", &HHCandidate_px, &b_HHCandidate_px);
   fChain->SetBranchAddress("HHCandidate_py", &HHCandidate_py, &b_HHCandidate_py);
   fChain->SetBranchAddress("HHCandidate_pz", &HHCandidate_pz, &b_HHCandidate_pz);
   fChain->SetBranchAddress("HHCandidate_eta", &HHCandidate_eta, &b_HHCandidate_eta);
   fChain->SetBranchAddress("HHCandidate_phi", &HHCandidate_phi, &b_HHCandidate_phi);
   fChain->SetBranchAddress("DeltaEta_HH", &DeltaEta_HH, &b_DeltaEta_HH);
   fChain->SetBranchAddress("DeltaPhi_HH", &DeltaPhi_HH, &b_DeltaPhi_HH);
   fChain->SetBranchAddress("DeltaR_HH", &DeltaR_HH, &b_DeltaR_HH);
   fChain->SetBranchAddress("cosThetaHH", &cosThetaHH, &b_cosThetaHH);
   fChain->SetBranchAddress("cosThetaWW", &cosThetaWW, &b_cosThetaWW);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("processIndex", &processIndex, &b_processIndex);
   fChain->SetBranchAddress("run", &run, &b_run);
//    fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("npu", &npu, &b_npu);
   fChain->SetBranchAddress("puweight", &puweight, &b_puweight);
   fChain->SetBranchAddress("weight_NLO_SM", &weight_NLO_SM, &b_weight_NLO_SM);
   fChain->SetBranchAddress("PhotonID_min", &PhotonID_min, &b_PhotonID_min);
   fChain->SetBranchAddress("PhotonID_max", &PhotonID_max, &b_PhotonID_max);
   fChain->SetBranchAddress("New_Leading_Jet_E", &New_Leading_Jet_E, &b_New_Leading_Jet_E);
   fChain->SetBranchAddress("New_Leading_Jet_pt", &New_Leading_Jet_pt, &b_New_Leading_Jet_pt);
   fChain->SetBranchAddress("New_Leading_Jet_px", &New_Leading_Jet_px, &b_New_Leading_Jet_px);
   fChain->SetBranchAddress("New_Leading_Jet_py", &New_Leading_Jet_py, &b_New_Leading_Jet_py);
   fChain->SetBranchAddress("New_Leading_Jet_pz", &New_Leading_Jet_pz, &b_New_Leading_Jet_pz);
   fChain->SetBranchAddress("New_Leading_Jet_eta", &New_Leading_Jet_eta, &b_New_Leading_Jet_eta);
   fChain->SetBranchAddress("New_Leading_Jet_phi", &New_Leading_Jet_phi, &b_New_Leading_Jet_phi);
   fChain->SetBranchAddress("New_Subleading_Jet_E", &New_Subleading_Jet_E, &b_New_Subleading_Jet_E);
   fChain->SetBranchAddress("New_Subleading_Jet_pt", &New_Subleading_Jet_pt, &b_New_Subleading_Jet_pt);
   fChain->SetBranchAddress("New_Subleading_Jet_px", &New_Subleading_Jet_px, &b_New_Subleading_Jet_px);
   fChain->SetBranchAddress("New_Subleading_Jet_py", &New_Subleading_Jet_py, &b_New_Subleading_Jet_py);
   fChain->SetBranchAddress("New_Subleading_Jet_pz", &New_Subleading_Jet_pz, &b_New_Subleading_Jet_pz);
   fChain->SetBranchAddress("New_Subleading_Jet_eta", &New_Subleading_Jet_eta, &b_New_Subleading_Jet_eta);
   fChain->SetBranchAddress("New_Subleading_Jet_phi", &New_Subleading_Jet_phi, &b_New_Subleading_Jet_phi);
   fChain->SetBranchAddress("New_Sub2leading_Jet_E", &New_Sub2leading_Jet_E, &b_New_Sub2leading_Jet_E);
   fChain->SetBranchAddress("New_Sub2leading_Jet_pt", &New_Sub2leading_Jet_pt, &b_New_Sub2leading_Jet_pt);
   fChain->SetBranchAddress("New_Sub2leading_Jet_px", &New_Sub2leading_Jet_px, &b_New_Sub2leading_Jet_px);
   fChain->SetBranchAddress("New_Sub2leading_Jet_py", &New_Sub2leading_Jet_py, &b_New_Sub2leading_Jet_py);
   fChain->SetBranchAddress("New_Sub2leading_Jet_pz", &New_Sub2leading_Jet_pz, &b_New_Sub2leading_Jet_pz);
   fChain->SetBranchAddress("New_Sub2leading_Jet_eta", &New_Sub2leading_Jet_eta, &b_New_Sub2leading_Jet_eta);
   fChain->SetBranchAddress("New_Sub2leading_Jet_phi", &New_Sub2leading_Jet_phi, &b_New_Sub2leading_Jet_phi);
   fChain->SetBranchAddress("New_Sub3leading_Jet_E", &New_Sub3leading_Jet_E, &b_New_Sub3leading_Jet_E);
   fChain->SetBranchAddress("New_Sub3leading_Jet_pt", &New_Sub3leading_Jet_pt, &b_New_Sub3leading_Jet_pt);
   fChain->SetBranchAddress("New_Sub3leading_Jet_px", &New_Sub3leading_Jet_px, &b_New_Sub3leading_Jet_px);
   fChain->SetBranchAddress("New_Sub3leading_Jet_py", &New_Sub3leading_Jet_py, &b_New_Sub3leading_Jet_py);
   fChain->SetBranchAddress("New_Sub3leading_Jet_pz", &New_Sub3leading_Jet_pz, &b_New_Sub3leading_Jet_pz);
   fChain->SetBranchAddress("New_Sub3leading_Jet_eta", &New_Sub3leading_Jet_eta, &b_New_Sub3leading_Jet_eta);
   fChain->SetBranchAddress("New_Sub3leading_Jet_phi", &New_Sub3leading_Jet_phi, &b_New_Sub3leading_Jet_phi);
   fChain->SetBranchAddress("New_OnShellW_LeadingJet_bDis", &New_OnShellW_LeadingJet_bDis, &b_New_OnShellW_LeadingJet_bDis);
   fChain->SetBranchAddress("New_OnShellW_SubLeadingJet_bDis", &New_OnShellW_SubLeadingJet_bDis, &b_New_OnShellW_SubLeadingJet_bDis);
   fChain->SetBranchAddress("New_OffShellW_LeadingJet_bDis", &New_OffShellW_LeadingJet_bDis, &b_New_OffShellW_LeadingJet_bDis);
   fChain->SetBranchAddress("New_OffShellW_SubLeadingJet_bDis", &New_OffShellW_SubLeadingJet_bDis, &b_New_OffShellW_SubLeadingJet_bDis);
   fChain->SetBranchAddress("New_OnShellW_E", &New_OnShellW_E, &b_New_OnShellW_E);
   fChain->SetBranchAddress("New_OnShellW_Mass", &New_OnShellW_Mass, &b_New_OnShellW_Mass);
   fChain->SetBranchAddress("New_OnShellW_pt", &New_OnShellW_pt, &b_New_OnShellW_pt);
   fChain->SetBranchAddress("New_OnShellW_px", &New_OnShellW_px, &b_New_OnShellW_px);
   fChain->SetBranchAddress("New_OnShellW_py", &New_OnShellW_py, &b_New_OnShellW_py);
   fChain->SetBranchAddress("New_OnShellW_pz", &New_OnShellW_pz, &b_New_OnShellW_pz);
   fChain->SetBranchAddress("New_OnShellW_eta", &New_OnShellW_eta, &b_New_OnShellW_eta);
   fChain->SetBranchAddress("New_OnShellW_phi", &New_OnShellW_phi, &b_New_OnShellW_phi);
   fChain->SetBranchAddress("New_OffShellW_E", &New_OffShellW_E, &b_New_OffShellW_E);
   fChain->SetBranchAddress("New_OffShellW_Mass", &New_OffShellW_Mass, &b_New_OffShellW_Mass);
   fChain->SetBranchAddress("New_OffShellW_pt", &New_OffShellW_pt, &b_New_OffShellW_pt);
   fChain->SetBranchAddress("New_OffShellW_px", &New_OffShellW_px, &b_New_OffShellW_px);
   fChain->SetBranchAddress("New_OffShellW_py", &New_OffShellW_py, &b_New_OffShellW_py);
   fChain->SetBranchAddress("New_OffShellW_pz", &New_OffShellW_pz, &b_New_OffShellW_pz);
   fChain->SetBranchAddress("New_OffShellW_eta", &New_OffShellW_eta, &b_New_OffShellW_eta);
   fChain->SetBranchAddress("New_OffShellW_phi", &New_OffShellW_phi, &b_New_OffShellW_phi);
   fChain->SetBranchAddress("New_HWW_E", &New_HWW_E, &b_New_HWW_E);
   fChain->SetBranchAddress("New_HWW_Mass", &New_HWW_Mass, &b_New_HWW_Mass);
   fChain->SetBranchAddress("New_HWW_pt", &New_HWW_pt, &b_New_HWW_pt);
   fChain->SetBranchAddress("New_HWW_px", &New_HWW_px, &b_New_HWW_px);
   fChain->SetBranchAddress("New_HWW_py", &New_HWW_py, &b_New_HWW_py);
   fChain->SetBranchAddress("New_HWW_pz", &New_HWW_pz, &b_New_HWW_pz);
   fChain->SetBranchAddress("New_HWW_eta", &New_HWW_eta, &b_New_HWW_eta);
   fChain->SetBranchAddress("New_HWW_phi", &New_HWW_phi, &b_New_HWW_phi);
   fChain->SetBranchAddress("New_dR_Hgg_Jet1", &New_dR_Hgg_Jet1, &b_New_dR_Hgg_Jet1);
   fChain->SetBranchAddress("New_dR_Hgg_Jet2", &New_dR_Hgg_Jet2, &b_New_dR_Hgg_Jet2);
   fChain->SetBranchAddress("New_dR_Hgg_Jet3", &New_dR_Hgg_Jet3, &b_New_dR_Hgg_Jet3);
   fChain->SetBranchAddress("New_dR_Hgg_Jet4", &New_dR_Hgg_Jet4, &b_New_dR_Hgg_Jet4);
   fChain->SetBranchAddress("New_dPhi_Hgg_Jet1", &New_dPhi_Hgg_Jet1, &b_New_dPhi_Hgg_Jet1);
   fChain->SetBranchAddress("New_dPhi_Hgg_Jet2", &New_dPhi_Hgg_Jet2, &b_New_dPhi_Hgg_Jet2);
   fChain->SetBranchAddress("New_dPhi_Hgg_Jet3", &New_dPhi_Hgg_Jet3, &b_New_dPhi_Hgg_Jet3);
   fChain->SetBranchAddress("New_dPhi_Hgg_Jet4", &New_dPhi_Hgg_Jet4, &b_New_dPhi_Hgg_Jet4);
   fChain->SetBranchAddress("New_DPhi_gg", &New_DPhi_gg, &b_New_DPhi_gg);
   fChain->SetBranchAddress("New_DR_gg", &New_DR_gg, &b_New_DR_gg);
   fChain->SetBranchAddress("New_DPhi_HH", &New_DPhi_HH, &b_New_DPhi_HH);
   fChain->SetBranchAddress("New_DR_HH", &New_DR_HH, &b_New_DR_HH);
   fChain->SetBranchAddress("New_minDeltaR_gg4j", &New_minDeltaR_gg4j, &b_New_minDeltaR_gg4j);
   fChain->SetBranchAddress("New_maxDeltaR_gg4j", &New_maxDeltaR_gg4j, &b_New_maxDeltaR_gg4j);
   fChain->SetBranchAddress("New_minDeltaR_4j", &New_minDeltaR_4j, &b_New_minDeltaR_4j);
   fChain->SetBranchAddress("New_maxDeltaR_4j", &New_maxDeltaR_4j, &b_New_maxDeltaR_4j);
   fChain->SetBranchAddress("a_costheta1", &a_costheta1, &b_a_costheta1);
   fChain->SetBranchAddress("a_costheta2", &a_costheta2, &b_a_costheta2);
   fChain->SetBranchAddress("a_costhetastar", &a_costhetastar, &b_a_costhetastar);
   fChain->SetBranchAddress("a_Phi", &a_Phi, &b_a_Phi);
   fChain->SetBranchAddress("a_Phi1", &a_Phi1, &b_a_Phi1);
   fChain->SetBranchAddress("CosThetaStar_CS", &CosThetaStar_CS, &b_CosThetaStar_CS);
   fChain->SetBranchAddress("CosThetaStar_CS_old", &CosThetaStar_CS_old, &b_CosThetaStar_CS_old);
   fChain->SetBranchAddress("HelicityCostheta1", &HelicityCostheta1, &b_HelicityCostheta1);
   fChain->SetBranchAddress("HelicityCostheta2", &HelicityCostheta2, &b_HelicityCostheta2);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_E", &New_DRBased_Leading_Jet_E, &b_New_DRBased_Leading_Jet_E);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_pt", &New_DRBased_Leading_Jet_pt, &b_New_DRBased_Leading_Jet_pt);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_px", &New_DRBased_Leading_Jet_px, &b_New_DRBased_Leading_Jet_px);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_py", &New_DRBased_Leading_Jet_py, &b_New_DRBased_Leading_Jet_py);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_pz", &New_DRBased_Leading_Jet_pz, &b_New_DRBased_Leading_Jet_pz);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_eta", &New_DRBased_Leading_Jet_eta, &b_New_DRBased_Leading_Jet_eta);
   fChain->SetBranchAddress("New_DRBased_Leading_Jet_phi", &New_DRBased_Leading_Jet_phi, &b_New_DRBased_Leading_Jet_phi);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_E", &New_DRBased_Subleading_Jet_E, &b_New_DRBased_Subleading_Jet_E);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_pt", &New_DRBased_Subleading_Jet_pt, &b_New_DRBased_Subleading_Jet_pt);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_px", &New_DRBased_Subleading_Jet_px, &b_New_DRBased_Subleading_Jet_px);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_py", &New_DRBased_Subleading_Jet_py, &b_New_DRBased_Subleading_Jet_py);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_pz", &New_DRBased_Subleading_Jet_pz, &b_New_DRBased_Subleading_Jet_pz);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_eta", &New_DRBased_Subleading_Jet_eta, &b_New_DRBased_Subleading_Jet_eta);
   fChain->SetBranchAddress("New_DRBased_Subleading_Jet_phi", &New_DRBased_Subleading_Jet_phi, &b_New_DRBased_Subleading_Jet_phi);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_E", &New_DRBased_Sub2leading_Jet_E, &b_New_DRBased_Sub2leading_Jet_E);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_pt", &New_DRBased_Sub2leading_Jet_pt, &b_New_DRBased_Sub2leading_Jet_pt);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_px", &New_DRBased_Sub2leading_Jet_px, &b_New_DRBased_Sub2leading_Jet_px);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_py", &New_DRBased_Sub2leading_Jet_py, &b_New_DRBased_Sub2leading_Jet_py);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_pz", &New_DRBased_Sub2leading_Jet_pz, &b_New_DRBased_Sub2leading_Jet_pz);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_eta", &New_DRBased_Sub2leading_Jet_eta, &b_New_DRBased_Sub2leading_Jet_eta);
   fChain->SetBranchAddress("New_DRBased_Sub2leading_Jet_phi", &New_DRBased_Sub2leading_Jet_phi, &b_New_DRBased_Sub2leading_Jet_phi);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_E", &New_DRBased_Sub3leading_Jet_E, &b_New_DRBased_Sub3leading_Jet_E);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_pt", &New_DRBased_Sub3leading_Jet_pt, &b_New_DRBased_Sub3leading_Jet_pt);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_px", &New_DRBased_Sub3leading_Jet_px, &b_New_DRBased_Sub3leading_Jet_px);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_py", &New_DRBased_Sub3leading_Jet_py, &b_New_DRBased_Sub3leading_Jet_py);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_pz", &New_DRBased_Sub3leading_Jet_pz, &b_New_DRBased_Sub3leading_Jet_pz);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_eta", &New_DRBased_Sub3leading_Jet_eta, &b_New_DRBased_Sub3leading_Jet_eta);
   fChain->SetBranchAddress("New_DRBased_Sub3leading_Jet_phi", &New_DRBased_Sub3leading_Jet_phi, &b_New_DRBased_Sub3leading_Jet_phi);
   fChain->SetBranchAddress("New_DRBased_OnShellW_LeadingJet_bDis", &New_DRBased_OnShellW_LeadingJet_bDis, &b_New_DRBased_OnShellW_LeadingJet_bDis);
   fChain->SetBranchAddress("New_DRBased_OnShellW_SubLeadingJet_bDis", &New_DRBased_OnShellW_SubLeadingJet_bDis, &b_New_DRBased_OnShellW_SubLeadingJet_bDis);
   fChain->SetBranchAddress("New_DRBased_OffShellW_LeadingJet_bDis", &New_DRBased_OffShellW_LeadingJet_bDis, &b_New_DRBased_OffShellW_LeadingJet_bDis);
   fChain->SetBranchAddress("New_DRBased_OffShellW_SubLeadingJet_bDis", &New_DRBased_OffShellW_SubLeadingJet_bDis, &b_New_DRBased_OffShellW_SubLeadingJet_bDis);
   fChain->SetBranchAddress("New_DRBased_OnShellW_E", &New_DRBased_OnShellW_E, &b_New_DRBased_OnShellW_E);
   fChain->SetBranchAddress("New_DRBased_OnShellW_Mass", &New_DRBased_OnShellW_Mass, &b_New_DRBased_OnShellW_Mass);
   fChain->SetBranchAddress("New_DRBased_OnShellW_pt", &New_DRBased_OnShellW_pt, &b_New_DRBased_OnShellW_pt);
   fChain->SetBranchAddress("New_DRBased_OnShellW_px", &New_DRBased_OnShellW_px, &b_New_DRBased_OnShellW_px);
   fChain->SetBranchAddress("New_DRBased_OnShellW_py", &New_DRBased_OnShellW_py, &b_New_DRBased_OnShellW_py);
   fChain->SetBranchAddress("New_DRBased_OnShellW_pz", &New_DRBased_OnShellW_pz, &b_New_DRBased_OnShellW_pz);
   fChain->SetBranchAddress("New_DRBased_OnShellW_eta", &New_DRBased_OnShellW_eta, &b_New_DRBased_OnShellW_eta);
   fChain->SetBranchAddress("New_DRBased_OnShellW_phi", &New_DRBased_OnShellW_phi, &b_New_DRBased_OnShellW_phi);
   fChain->SetBranchAddress("New_DRBased_OffShellW_Mass", &New_DRBased_OffShellW_Mass, &b_New_DRBased_OffShellW_Mass);
   fChain->SetBranchAddress("New_DRBased_OffShellW_pt", &New_DRBased_OffShellW_pt, &b_New_DRBased_OffShellW_pt);
   fChain->SetBranchAddress("New_DRBased_OffShellW_px", &New_DRBased_OffShellW_px, &b_New_DRBased_OffShellW_px);
   fChain->SetBranchAddress("New_DRBased_OffShellW_py", &New_DRBased_OffShellW_py, &b_New_DRBased_OffShellW_py);
   fChain->SetBranchAddress("New_DRBased_OffShellW_pz", &New_DRBased_OffShellW_pz, &b_New_DRBased_OffShellW_pz);
   fChain->SetBranchAddress("New_DRBased_OffShellW_eta", &New_DRBased_OffShellW_eta, &b_New_DRBased_OffShellW_eta);
   fChain->SetBranchAddress("New_DRBased_OffShellW_phi", &New_DRBased_OffShellW_phi, &b_New_DRBased_OffShellW_phi);
   fChain->SetBranchAddress("New_DRBased_HWW_Mass", &New_DRBased_HWW_Mass, &b_New_DRBased_HWW_Mass);
   fChain->SetBranchAddress("New_DRBased_HWW_pt", &New_DRBased_HWW_pt, &b_New_DRBased_HWW_pt);
   fChain->SetBranchAddress("New_DRBased_HWW_px", &New_DRBased_HWW_px, &b_New_DRBased_HWW_px);
   fChain->SetBranchAddress("New_DRBased_HWW_py", &New_DRBased_HWW_py, &b_New_DRBased_HWW_py);
   fChain->SetBranchAddress("New_DRBased_HWW_pz", &New_DRBased_HWW_pz, &b_New_DRBased_HWW_pz);
   fChain->SetBranchAddress("New_DRBased_HWW_eta", &New_DRBased_HWW_eta, &b_New_DRBased_HWW_eta);
   fChain->SetBranchAddress("New_DRBased_HWW_phi", &New_DRBased_HWW_phi, &b_New_DRBased_HWW_phi);
   fChain->SetBranchAddress("New_DRBased_dR_Hgg_Jet1", &New_DRBased_dR_Hgg_Jet1, &b_New_DRBased_dR_Hgg_Jet1);
   fChain->SetBranchAddress("New_DRBased_dR_Hgg_Jet2", &New_DRBased_dR_Hgg_Jet2, &b_New_DRBased_dR_Hgg_Jet2);
   fChain->SetBranchAddress("New_DRBased_dR_Hgg_Jet3", &New_DRBased_dR_Hgg_Jet3, &b_New_DRBased_dR_Hgg_Jet3);
   fChain->SetBranchAddress("New_DRBased_dR_Hgg_Jet4", &New_DRBased_dR_Hgg_Jet4, &b_New_DRBased_dR_Hgg_Jet4);
   fChain->SetBranchAddress("New_DRBased_dPhi_Hgg_Jet1", &New_DRBased_dPhi_Hgg_Jet1, &b_New_DRBased_dPhi_Hgg_Jet1);
   fChain->SetBranchAddress("New_DRBased_dPhi_Hgg_Jet2", &New_DRBased_dPhi_Hgg_Jet2, &b_New_DRBased_dPhi_Hgg_Jet2);
   fChain->SetBranchAddress("New_DRBased_dPhi_Hgg_Jet3", &New_DRBased_dPhi_Hgg_Jet3, &b_New_DRBased_dPhi_Hgg_Jet3);
   fChain->SetBranchAddress("New_DRBased_dPhi_Hgg_Jet4", &New_DRBased_dPhi_Hgg_Jet4, &b_New_DRBased_dPhi_Hgg_Jet4);
   fChain->SetBranchAddress("New_DRBased_DPhi_gg", &New_DRBased_DPhi_gg, &b_New_DRBased_DPhi_gg);
   fChain->SetBranchAddress("New_DRBased_DR_gg", &New_DRBased_DR_gg, &b_New_DRBased_DR_gg);
   fChain->SetBranchAddress("New_DRBased_DPhi_HH", &New_DRBased_DPhi_HH, &b_New_DRBased_DPhi_HH);
   fChain->SetBranchAddress("New_DRBased_DR_HH", &New_DRBased_DR_HH, &b_New_DRBased_DR_HH);
   fChain->SetBranchAddress("DRBased_a_costheta1", &DRBased_a_costheta1, &b_DRBased_a_costheta1);
   fChain->SetBranchAddress("DRBased_a_costheta2", &DRBased_a_costheta2, &b_DRBased_a_costheta2);
   fChain->SetBranchAddress("DRBased_a_costhetastar", &DRBased_a_costhetastar, &b_DRBased_a_costhetastar);
   fChain->SetBranchAddress("DRBased_a_Phi", &DRBased_a_Phi, &b_DRBased_a_Phi);
   fChain->SetBranchAddress("DRBased_a_Phi1", &DRBased_a_Phi1, &b_DRBased_a_Phi1);
   fChain->SetBranchAddress("evalDNN", &evalDNN, &b_evalDNN);
}
