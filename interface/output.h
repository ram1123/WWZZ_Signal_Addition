#ifndef OUTPUT_HH
#define OUTPUT_HH

#include "TTree.h"

class output{

public:

  output(TTree *t) {
    fTree = t;
    init(fTree);
  };

  ~output() {
    delete fTree;
  };

  void clearVars();
  virtual void init(TTree *tree);

  TTree *fTree;

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  Float_t   PhotonID_min = -999.0;
  Float_t   PhotonID_max = -999.0;

  Float_t   New_Leading_Jet_E = -999.0;
  Float_t   New_Leading_Jet_pt = -999.0;
  Float_t   New_Leading_Jet_px = -999.0;
  Float_t   New_Leading_Jet_py = -999.0;
  Float_t   New_Leading_Jet_pz = -999.0;
  Float_t   New_Leading_Jet_eta = -999.0;
  Float_t   New_Leading_Jet_phi = -999.0;
  Float_t   New_Subleading_Jet_E = -999.0;
  Float_t   New_Subleading_Jet_pt = -999.0;
  Float_t   New_Subleading_Jet_px = -999.0;
  Float_t   New_Subleading_Jet_py = -999.0;
  Float_t   New_Subleading_Jet_pz = -999.0;
  Float_t   New_Subleading_Jet_eta = -999.0;
  Float_t   New_Subleading_Jet_phi = -999.0;
  Float_t   New_Sub2leading_Jet_E = -999.0;
  Float_t   New_Sub2leading_Jet_pt = -999.0;
  Float_t   New_Sub2leading_Jet_px = -999.0;
  Float_t   New_Sub2leading_Jet_py = -999.0;
  Float_t   New_Sub2leading_Jet_pz = -999.0;
  Float_t   New_Sub2leading_Jet_eta = -999.0;
  Float_t   New_Sub2leading_Jet_phi = -999.0;
  Float_t   New_Sub3leading_Jet_E = -999.0;
  Float_t   New_Sub3leading_Jet_pt = -999.0;
  Float_t   New_Sub3leading_Jet_px = -999.0;
  Float_t   New_Sub3leading_Jet_py = -999.0;
  Float_t   New_Sub3leading_Jet_pz = -999.0;
  Float_t   New_Sub3leading_Jet_eta = -999.0;
  Float_t   New_Sub3leading_Jet_phi = -999.0;
  Float_t   New_OnShellW_LeadingJet_bDis = -999.0;
  Float_t   New_OnShellW_SubLeadingJet_bDis = -999.0;
  Float_t   New_OffShellW_LeadingJet_bDis = -999.0;
  Float_t   New_OffShellW_SubLeadingJet_bDis = -999.0;
  Float_t   New_OnShellW_E = -999.0;
  Float_t   New_OnShellW_Mass = -999.0;
  Float_t   New_OnShellW_pt = -999.0;
  Float_t   New_OnShellW_px = -999.0;
  Float_t   New_OnShellW_py = -999.0;
  Float_t   New_OnShellW_pz = -999.0;
  Float_t   New_OnShellW_eta = -999.0;
  Float_t   New_OnShellW_phi = -999.0;
  Float_t   New_OffShellW_E = -999.0;
  Float_t   New_OffShellW_Mass = -999.0;
  Float_t   New_OffShellW_pt = -999.0;
  Float_t   New_OffShellW_px = -999.0;
  Float_t   New_OffShellW_py = -999.0;
  Float_t   New_OffShellW_pz = -999.0;
  Float_t   New_OffShellW_eta = -999.0;
  Float_t   New_OffShellW_phi = -999.0;
  Float_t   New_HWW_E = -999.0;
  Float_t   New_HWW_Mass = -999.0;
  Float_t   New_HWW_pt = -999.0;
  Float_t   New_HWW_px = -999.0;
  Float_t   New_HWW_py = -999.0;
  Float_t   New_HWW_pz = -999.0;
  Float_t   New_HWW_eta = -999.0;
  Float_t   New_HWW_phi = -999.0;
  Float_t   New_dR_Hgg_Jet1 = -999.0;
  Float_t   New_dR_Hgg_Jet2 = -999.0;
  Float_t   New_dR_Hgg_Jet3 = -999.0;
  Float_t   New_dR_Hgg_Jet4 = -999.0;
  Float_t   New_dPhi_Hgg_Jet1 = -999.0;
  Float_t   New_dPhi_Hgg_Jet2 = -999.0;
  Float_t   New_dPhi_Hgg_Jet3 = -999.0;
  Float_t   New_dPhi_Hgg_Jet4 = -999.0;
  Float_t   New_DPhi_gg = -999.0;
  Float_t   New_DR_gg = -999.0;
  Float_t   New_DPhi_HH = -999.0;
  Float_t   New_DR_HH = -999.0;
  Float_t   New_minDeltaR_gg4j = -999.0;
  Float_t   New_maxDeltaR_gg4j = -999.0;
  Float_t   New_minDeltaR_4j = -999.0;
  Float_t   New_maxDeltaR_4j = -999.0;
  Float_t   a_costheta1 = -999.0;
  Float_t   a_costheta2 = -999.0;
  Float_t   a_costhetastar = -999.0;
  Float_t   a_Phi = -999.0;
  Float_t   a_Phi1 = -999.0;
  Float_t   CosThetaStar_CS = -999.0;
  Float_t   CosThetaStar_CS_old = -999.0;
  Float_t   HelicityCostheta1 = -999.0;
  Float_t   HelicityCostheta2 = -999.0;

  Float_t   New_DRBased_Leading_Jet_E = -999.0;
  Float_t   New_DRBased_Leading_Jet_pt = -999.0;
  Float_t   New_DRBased_Leading_Jet_px = -999.0;
  Float_t   New_DRBased_Leading_Jet_py = -999.0;
  Float_t   New_DRBased_Leading_Jet_pz = -999.0;
  Float_t   New_DRBased_Leading_Jet_eta = -999.0;
  Float_t   New_DRBased_Leading_Jet_phi = -999.0;
  Float_t   New_DRBased_Subleading_Jet_E = -999.0;
  Float_t   New_DRBased_Subleading_Jet_pt = -999.0;
  Float_t   New_DRBased_Subleading_Jet_px = -999.0;
  Float_t   New_DRBased_Subleading_Jet_py = -999.0;
  Float_t   New_DRBased_Subleading_Jet_pz = -999.0;
  Float_t   New_DRBased_Subleading_Jet_eta = -999.0;
  Float_t   New_DRBased_Subleading_Jet_phi = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_E = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_pt = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_px = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_py = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_pz = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_eta = -999.0;
  Float_t   New_DRBased_Sub2leading_Jet_phi = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_E = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_pt = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_px = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_py = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_pz = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_eta = -999.0;
  Float_t   New_DRBased_Sub3leading_Jet_phi = -999.0;
  Float_t   New_DRBased_OnShellW_LeadingJet_bDis = -999.0;
  Float_t   New_DRBased_OnShellW_SubLeadingJet_bDis = -999.0;
  Float_t   New_DRBased_OffShellW_LeadingJet_bDis = -999.0;
  Float_t   New_DRBased_OffShellW_SubLeadingJet_bDis = -999.0;
  Float_t   New_DRBased_OnShellW_E = -999.0;
  Float_t   New_DRBased_OnShellW_Mass = -999.0;
  Float_t   New_DRBased_OnShellW_pt = -999.0;
  Float_t   New_DRBased_OnShellW_px = -999.0;
  Float_t   New_DRBased_OnShellW_py = -999.0;
  Float_t   New_DRBased_OnShellW_pz = -999.0;
  Float_t   New_DRBased_OnShellW_eta = -999.0;
  Float_t   New_DRBased_OnShellW_phi = -999.0;
  Float_t   New_DRBased_OffShellW_E = -999.0;
  Float_t   New_DRBased_OffShellW_Mass = -999.0;
  Float_t   New_DRBased_OffShellW_pt = -999.0;
  Float_t   New_DRBased_OffShellW_px = -999.0;
  Float_t   New_DRBased_OffShellW_py = -999.0;
  Float_t   New_DRBased_OffShellW_pz = -999.0;
  Float_t   New_DRBased_OffShellW_eta = -999.0;
  Float_t   New_DRBased_OffShellW_phi = -999.0;
  Float_t   New_DRBased_HWW_E = -999.0;
  Float_t   New_DRBased_HWW_Mass = -999.0;
  Float_t   New_DRBased_HWW_pt = -999.0;
  Float_t   New_DRBased_HWW_px = -999.0;
  Float_t   New_DRBased_HWW_py = -999.0;
  Float_t   New_DRBased_HWW_pz = -999.0;
  Float_t   New_DRBased_HWW_eta = -999.0;
  Float_t   New_DRBased_HWW_phi = -999.0;
  Float_t   New_DRBased_dR_Hgg_Jet1 = -999.0;
  Float_t   New_DRBased_dR_Hgg_Jet2 = -999.0;
  Float_t   New_DRBased_dR_Hgg_Jet3 = -999.0;
  Float_t   New_DRBased_dR_Hgg_Jet4 = -999.0;
  Float_t   New_DRBased_dPhi_Hgg_Jet1 = -999.0;
  Float_t   New_DRBased_dPhi_Hgg_Jet2 = -999.0;
  Float_t   New_DRBased_dPhi_Hgg_Jet3 = -999.0;
  Float_t   New_DRBased_dPhi_Hgg_Jet4 = -999.0;
  Float_t   New_DRBased_DPhi_gg = -999.0;
  Float_t   New_DRBased_DR_gg = -999.0;
  Float_t   New_DRBased_DPhi_HH = -999.0;
  Float_t   New_DRBased_DR_HH = -999.0;
  Float_t   DRBased_a_costheta1 = -999.0;
  Float_t   DRBased_a_costheta2 = -999.0;
  Float_t   DRBased_a_costhetastar = -999.0;
  Float_t   DRBased_a_Phi = -999.0;
  Float_t   DRBased_a_Phi1 = -999.0;
};

#endif

void output::init(TTree* tree) {

  fTree = tree;

  fTree->Branch("PhotonID_min", &PhotonID_min,  "PhotonID_min/F");
  fTree->Branch("PhotonID_max", &PhotonID_max,  "PhotonID_max/F");

  fTree->Branch("New_Leading_Jet_E", &New_Leading_Jet_E, "New_Leading_Jet_E/F");
  fTree->Branch("New_Leading_Jet_pt", &New_Leading_Jet_pt, "New_Leading_Jet_pt/F");
  fTree->Branch("New_Leading_Jet_px", &New_Leading_Jet_px, "New_Leading_Jet_px/F");
  fTree->Branch("New_Leading_Jet_py", &New_Leading_Jet_py, "New_Leading_Jet_py/F");
  fTree->Branch("New_Leading_Jet_pz", &New_Leading_Jet_pz, "New_Leading_Jet_pz/F");
  fTree->Branch("New_Leading_Jet_eta", &New_Leading_Jet_eta, "New_Leading_Jet_eta/F");
  fTree->Branch("New_Leading_Jet_phi", &New_Leading_Jet_phi, "New_Leading_Jet_phi/F");
  fTree->Branch("New_Subleading_Jet_E", &New_Subleading_Jet_E, "New_Subleading_Jet_E/F");
  fTree->Branch("New_Subleading_Jet_pt", &New_Subleading_Jet_pt, "New_Subleading_Jet_pt/F");
  fTree->Branch("New_Subleading_Jet_px", &New_Subleading_Jet_px, "New_Subleading_Jet_px/F");
  fTree->Branch("New_Subleading_Jet_py", &New_Subleading_Jet_py, "New_Subleading_Jet_py/F");
  fTree->Branch("New_Subleading_Jet_pz", &New_Subleading_Jet_pz, "New_Subleading_Jet_pz/F");
  fTree->Branch("New_Subleading_Jet_eta", &New_Subleading_Jet_eta, "New_Subleading_Jet_eta/F");
  fTree->Branch("New_Subleading_Jet_phi", &New_Subleading_Jet_phi, "New_Subleading_Jet_phi/F");
  fTree->Branch("New_Sub2leading_Jet_E", &New_Sub2leading_Jet_E, "New_Sub2leading_Jet_E/F");
  fTree->Branch("New_Sub2leading_Jet_pt", &New_Sub2leading_Jet_pt, "New_Sub2leading_Jet_pt/F");
  fTree->Branch("New_Sub2leading_Jet_px", &New_Sub2leading_Jet_px, "New_Sub2leading_Jet_px/F");
  fTree->Branch("New_Sub2leading_Jet_py", &New_Sub2leading_Jet_py, "New_Sub2leading_Jet_py/F");
  fTree->Branch("New_Sub2leading_Jet_pz", &New_Sub2leading_Jet_pz, "New_Sub2leading_Jet_pz/F");
  fTree->Branch("New_Sub2leading_Jet_eta", &New_Sub2leading_Jet_eta, "New_Sub2leading_Jet_eta/F");
  fTree->Branch("New_Sub2leading_Jet_phi", &New_Sub2leading_Jet_phi, "New_Sub2leading_Jet_phi/F");
  fTree->Branch("New_Sub3leading_Jet_E", &New_Sub3leading_Jet_E, "New_Sub3leading_Jet_E/F");
  fTree->Branch("New_Sub3leading_Jet_pt", &New_Sub3leading_Jet_pt, "New_Sub3leading_Jet_pt/F");
  fTree->Branch("New_Sub3leading_Jet_px", &New_Sub3leading_Jet_px, "New_Sub3leading_Jet_px/F");
  fTree->Branch("New_Sub3leading_Jet_py", &New_Sub3leading_Jet_py, "New_Sub3leading_Jet_py/F");
  fTree->Branch("New_Sub3leading_Jet_pz", &New_Sub3leading_Jet_pz, "New_Sub3leading_Jet_pz/F");
  fTree->Branch("New_Sub3leading_Jet_eta", &New_Sub3leading_Jet_eta, "New_Sub3leading_Jet_eta/F");
  fTree->Branch("New_Sub3leading_Jet_phi", &New_Sub3leading_Jet_phi, "New_Sub3leading_Jet_phi/F");
  fTree->Branch("New_OnShellW_LeadingJet_bDis", &New_OnShellW_LeadingJet_bDis, "New_OnShellW_LeadingJet_bDis/F");
  fTree->Branch("New_OnShellW_SubLeadingJet_bDis", &New_OnShellW_SubLeadingJet_bDis, "New_OnShellW_SubLeadingJet_bDis/F");
  fTree->Branch("New_OffShellW_LeadingJet_bDis", &New_OffShellW_LeadingJet_bDis, "New_OffShellW_LeadingJet_bDis/F");
  fTree->Branch("New_OffShellW_SubLeadingJet_bDis", &New_OffShellW_SubLeadingJet_bDis, "New_OffShellW_SubLeadingJet_bDis/F");
  fTree->Branch("New_OnShellW_E", &New_OnShellW_E, "New_OnShellW_E/F");
  fTree->Branch("New_OnShellW_Mass", &New_OnShellW_Mass, "New_OnShellW_Mass/F");
  fTree->Branch("New_OnShellW_pt", &New_OnShellW_pt, "New_OnShellW_pt/F");
  fTree->Branch("New_OnShellW_px", &New_OnShellW_px, "New_OnShellW_px/F");
  fTree->Branch("New_OnShellW_py", &New_OnShellW_py, "New_OnShellW_py/F");
  fTree->Branch("New_OnShellW_pz", &New_OnShellW_pz, "New_OnShellW_pz/F");
  fTree->Branch("New_OnShellW_eta", &New_OnShellW_eta, "New_OnShellW_eta/F");
  fTree->Branch("New_OnShellW_phi", &New_OnShellW_phi, "New_OnShellW_phi/F");
  fTree->Branch("New_OffShellW_E", &New_OffShellW_E, "New_OffShellW_E/F");
  fTree->Branch("New_OffShellW_Mass", &New_OffShellW_Mass, "New_OffShellW_Mass/F");
  fTree->Branch("New_OffShellW_pt", &New_OffShellW_pt, "New_OffShellW_pt/F");
  fTree->Branch("New_OffShellW_px", &New_OffShellW_px, "New_OffShellW_px/F");
  fTree->Branch("New_OffShellW_py", &New_OffShellW_py, "New_OffShellW_py/F");
  fTree->Branch("New_OffShellW_pz", &New_OffShellW_pz, "New_OffShellW_pz/F");
  fTree->Branch("New_OffShellW_eta", &New_OffShellW_eta, "New_OffShellW_eta/F");
  fTree->Branch("New_OffShellW_phi", &New_OffShellW_phi, "New_OffShellW_phi/F");
  fTree->Branch("New_HWW_E", &New_HWW_E, "New_HWW_E/F");
  fTree->Branch("New_HWW_Mass", &New_HWW_Mass, "New_HWW_Mass/F");
  fTree->Branch("New_HWW_pt", &New_HWW_pt, "New_HWW_pt/F");
  fTree->Branch("New_HWW_px", &New_HWW_px, "New_HWW_px/F");
  fTree->Branch("New_HWW_py", &New_HWW_py, "New_HWW_py/F");
  fTree->Branch("New_HWW_pz", &New_HWW_pz, "New_HWW_pz/F");
  fTree->Branch("New_HWW_eta", &New_HWW_eta, "New_HWW_eta/F");
  fTree->Branch("New_HWW_phi", &New_HWW_phi, "New_HWW_phi/F");
  fTree->Branch("New_dR_Hgg_Jet1", &New_dR_Hgg_Jet1, "New_dR_Hgg_Jet1/F");
  fTree->Branch("New_dR_Hgg_Jet2", &New_dR_Hgg_Jet2, "New_dR_Hgg_Jet2/F");
  fTree->Branch("New_dR_Hgg_Jet3", &New_dR_Hgg_Jet3, "New_dR_Hgg_Jet3/F");
  fTree->Branch("New_dR_Hgg_Jet4", &New_dR_Hgg_Jet4, "New_dR_Hgg_Jet4/F");
  fTree->Branch("New_dPhi_Hgg_Jet1", &New_dPhi_Hgg_Jet1, "New_dPhi_Hgg_Jet1/F");
  fTree->Branch("New_dPhi_Hgg_Jet2", &New_dPhi_Hgg_Jet2, "New_dPhi_Hgg_Jet2/F");
  fTree->Branch("New_dPhi_Hgg_Jet3", &New_dPhi_Hgg_Jet3, "New_dPhi_Hgg_Jet3/F");
  fTree->Branch("New_dPhi_Hgg_Jet4", &New_dPhi_Hgg_Jet4, "New_dPhi_Hgg_Jet4/F");
  fTree->Branch("New_DPhi_gg",  &New_DPhi_gg,   "New_DPhi_gg/F");
  fTree->Branch("New_DR_gg",    &New_DR_gg,     "New_DR_gg/F");
  fTree->Branch("New_DPhi_HH",  &New_DPhi_HH,   "New_DPhi_HH/F");
  fTree->Branch("New_DR_HH",    &New_DR_HH,     "New_DR_HH/F");
  fTree->Branch("New_minDeltaR_gg4j",    &New_minDeltaR_gg4j,     "New_minDeltaR_gg4j/F");
  fTree->Branch("New_maxDeltaR_gg4j",    &New_maxDeltaR_gg4j,     "New_maxDeltaR_gg4j/F");
  fTree->Branch("New_minDeltaR_4j",    &New_minDeltaR_4j,     "New_minDeltaR_4j/F");
  fTree->Branch("New_maxDeltaR_4j",    &New_maxDeltaR_4j,     "New_maxDeltaR_4j/F");
  fTree->Branch("a_costheta1",    &a_costheta1,   "a_costheta1/F");
  fTree->Branch("a_costheta2",    &a_costheta2,   "a_costheta2/F");
  fTree->Branch("a_costhetastar", &a_costhetastar,"a_costhetastar/F");
  fTree->Branch("a_Phi",          &a_Phi,         "a_Phi/F");
  fTree->Branch("a_Phi1",         &a_Phi1,        "a_Phi1/F");
  fTree->Branch("CosThetaStar_CS",  &CosThetaStar_CS, "CosThetaStar_CS/F");
  fTree->Branch("CosThetaStar_CS_old",  &CosThetaStar_CS_old, "CosThetaStar_CS_old/F");
  fTree->Branch("HelicityCostheta1",  &HelicityCostheta1, "HelicityCostheta1/F");
  fTree->Branch("HelicityCostheta2",  &HelicityCostheta2, "HelicityCostheta2/F");


  fTree->Branch("New_DRBased_Leading_Jet_E", &New_DRBased_Leading_Jet_E, "New_DRBased_Leading_Jet_E/F");
  fTree->Branch("New_DRBased_Leading_Jet_pt", &New_DRBased_Leading_Jet_pt, "New_DRBased_Leading_Jet_pt/F");
  fTree->Branch("New_DRBased_Leading_Jet_px", &New_DRBased_Leading_Jet_px, "New_DRBased_Leading_Jet_px/F");
  fTree->Branch("New_DRBased_Leading_Jet_py", &New_DRBased_Leading_Jet_py, "New_DRBased_Leading_Jet_py/F");
  fTree->Branch("New_DRBased_Leading_Jet_pz", &New_DRBased_Leading_Jet_pz, "New_DRBased_Leading_Jet_pz/F");
  fTree->Branch("New_DRBased_Leading_Jet_eta", &New_DRBased_Leading_Jet_eta, "New_DRBased_Leading_Jet_eta/F");
  fTree->Branch("New_DRBased_Leading_Jet_phi", &New_DRBased_Leading_Jet_phi, "New_DRBased_Leading_Jet_phi/F");
  fTree->Branch("New_DRBased_Subleading_Jet_E", &New_DRBased_Subleading_Jet_E, "New_DRBased_Subleading_Jet_E/F");
  fTree->Branch("New_DRBased_Subleading_Jet_pt", &New_DRBased_Subleading_Jet_pt, "New_DRBased_Subleading_Jet_pt/F");
  fTree->Branch("New_DRBased_Subleading_Jet_px", &New_DRBased_Subleading_Jet_px, "New_DRBased_Subleading_Jet_px/F");
  fTree->Branch("New_DRBased_Subleading_Jet_py", &New_DRBased_Subleading_Jet_py, "New_DRBased_Subleading_Jet_py/F");
  fTree->Branch("New_DRBased_Subleading_Jet_pz", &New_DRBased_Subleading_Jet_pz, "New_DRBased_Subleading_Jet_pz/F");
  fTree->Branch("New_DRBased_Subleading_Jet_eta", &New_DRBased_Subleading_Jet_eta, "New_DRBased_Subleading_Jet_eta/F");
  fTree->Branch("New_DRBased_Subleading_Jet_phi", &New_DRBased_Subleading_Jet_phi, "New_DRBased_Subleading_Jet_phi/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_E", &New_DRBased_Sub2leading_Jet_E, "New_DRBased_Sub2leading_Jet_E/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_pt", &New_DRBased_Sub2leading_Jet_pt, "New_DRBased_Sub2leading_Jet_pt/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_px", &New_DRBased_Sub2leading_Jet_px, "New_DRBased_Sub2leading_Jet_px/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_py", &New_DRBased_Sub2leading_Jet_py, "New_DRBased_Sub2leading_Jet_py/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_pz", &New_DRBased_Sub2leading_Jet_pz, "New_DRBased_Sub2leading_Jet_pz/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_eta", &New_DRBased_Sub2leading_Jet_eta, "New_DRBased_Sub2leading_Jet_eta/F");
  fTree->Branch("New_DRBased_Sub2leading_Jet_phi", &New_DRBased_Sub2leading_Jet_phi, "New_DRBased_Sub2leading_Jet_phi/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_E", &New_DRBased_Sub3leading_Jet_E, "New_DRBased_Sub3leading_Jet_E/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_pt", &New_DRBased_Sub3leading_Jet_pt, "New_DRBased_Sub3leading_Jet_pt/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_px", &New_DRBased_Sub3leading_Jet_px, "New_DRBased_Sub3leading_Jet_px/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_py", &New_DRBased_Sub3leading_Jet_py, "New_DRBased_Sub3leading_Jet_py/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_pz", &New_DRBased_Sub3leading_Jet_pz, "New_DRBased_Sub3leading_Jet_pz/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_eta", &New_DRBased_Sub3leading_Jet_eta, "New_DRBased_Sub3leading_Jet_eta/F");
  fTree->Branch("New_DRBased_Sub3leading_Jet_phi", &New_DRBased_Sub3leading_Jet_phi, "New_DRBased_Sub3leading_Jet_phi/F");
  fTree->Branch("New_DRBased_OnShellW_LeadingJet_bDis", &New_DRBased_OnShellW_LeadingJet_bDis, "New_DRBased_OnShellW_LeadingJet_bDis/F");
  fTree->Branch("New_DRBased_OnShellW_SubLeadingJet_bDis", &New_DRBased_OnShellW_SubLeadingJet_bDis, "New_DRBased_OnShellW_SubLeadingJet_bDis/F");
  fTree->Branch("New_DRBased_OffShellW_LeadingJet_bDis", &New_DRBased_OffShellW_LeadingJet_bDis, "New_DRBased_OffShellW_LeadingJet_bDis/F");
  fTree->Branch("New_DRBased_OffShellW_SubLeadingJet_bDis", &New_DRBased_OffShellW_SubLeadingJet_bDis, "New_DRBased_OffShellW_SubLeadingJet_bDis/F");
  fTree->Branch("New_DRBased_OnShellW_E", &New_DRBased_OnShellW_E, "New_DRBased_OnShellW_E/F");
  fTree->Branch("New_DRBased_OnShellW_Mass", &New_DRBased_OnShellW_Mass, "New_DRBased_OnShellW_Mass/F");
  fTree->Branch("New_DRBased_OnShellW_pt", &New_DRBased_OnShellW_pt, "New_DRBased_OnShellW_pt/F");
  fTree->Branch("New_DRBased_OnShellW_px", &New_DRBased_OnShellW_px, "New_DRBased_OnShellW_px/F");
  fTree->Branch("New_DRBased_OnShellW_py", &New_DRBased_OnShellW_py, "New_DRBased_OnShellW_py/F");
  fTree->Branch("New_DRBased_OnShellW_pz", &New_DRBased_OnShellW_pz, "New_DRBased_OnShellW_pz/F");
  fTree->Branch("New_DRBased_OnShellW_eta", &New_DRBased_OnShellW_eta, "New_DRBased_OnShellW_eta/F");
  fTree->Branch("New_DRBased_OnShellW_phi", &New_DRBased_OnShellW_phi, "New_DRBased_OnShellW_phi/F");
  fTree->Branch("New_DRBased_OffShellW_Mass", &New_DRBased_OffShellW_Mass, "New_DRBased_OffShellW_Mass/F");
  fTree->Branch("New_DRBased_OffShellW_pt", &New_DRBased_OffShellW_pt, "New_DRBased_OffShellW_pt/F");
  fTree->Branch("New_DRBased_OffShellW_px", &New_DRBased_OffShellW_px, "New_DRBased_OffShellW_px/F");
  fTree->Branch("New_DRBased_OffShellW_py", &New_DRBased_OffShellW_py, "New_DRBased_OffShellW_py/F");
  fTree->Branch("New_DRBased_OffShellW_pz", &New_DRBased_OffShellW_pz, "New_DRBased_OffShellW_pz/F");
  fTree->Branch("New_DRBased_OffShellW_eta", &New_DRBased_OffShellW_eta, "New_DRBased_OffShellW_eta/F");
  fTree->Branch("New_DRBased_OffShellW_phi", &New_DRBased_OffShellW_phi, "New_DRBased_OffShellW_phi/F");
  fTree->Branch("New_DRBased_HWW_Mass", &New_DRBased_HWW_Mass, "New_DRBased_HWW_Mass/F");
  fTree->Branch("New_DRBased_HWW_pt", &New_DRBased_HWW_pt, "New_DRBased_HWW_pt/F");
  fTree->Branch("New_DRBased_HWW_px", &New_DRBased_HWW_px, "New_DRBased_HWW_px/F");
  fTree->Branch("New_DRBased_HWW_py", &New_DRBased_HWW_py, "New_DRBased_HWW_py/F");
  fTree->Branch("New_DRBased_HWW_pz", &New_DRBased_HWW_pz, "New_DRBased_HWW_pz/F");
  fTree->Branch("New_DRBased_HWW_eta", &New_DRBased_HWW_eta, "New_DRBased_HWW_eta/F");
  fTree->Branch("New_DRBased_HWW_phi", &New_DRBased_HWW_phi, "New_DRBased_HWW_phi/F");
  fTree->Branch("New_DRBased_dR_Hgg_Jet1", &New_DRBased_dR_Hgg_Jet1, "New_DRBased_dR_Hgg_Jet1/F");
  fTree->Branch("New_DRBased_dR_Hgg_Jet2", &New_DRBased_dR_Hgg_Jet2, "New_DRBased_dR_Hgg_Jet2/F");
  fTree->Branch("New_DRBased_dR_Hgg_Jet3", &New_DRBased_dR_Hgg_Jet3, "New_DRBased_dR_Hgg_Jet3/F");
  fTree->Branch("New_DRBased_dR_Hgg_Jet4", &New_DRBased_dR_Hgg_Jet4, "New_DRBased_dR_Hgg_Jet4/F");
  fTree->Branch("New_DRBased_dPhi_Hgg_Jet1", &New_DRBased_dPhi_Hgg_Jet1, "New_DRBased_dPhi_Hgg_Jet1/F");
  fTree->Branch("New_DRBased_dPhi_Hgg_Jet2", &New_DRBased_dPhi_Hgg_Jet2, "New_DRBased_dPhi_Hgg_Jet2/F");
  fTree->Branch("New_DRBased_dPhi_Hgg_Jet3", &New_DRBased_dPhi_Hgg_Jet3, "New_DRBased_dPhi_Hgg_Jet3/F");
  fTree->Branch("New_DRBased_dPhi_Hgg_Jet4", &New_DRBased_dPhi_Hgg_Jet4, "New_DRBased_dPhi_Hgg_Jet4/F");
  fTree->Branch("New_DRBased_DPhi_gg",  &New_DRBased_DPhi_gg,   "New_DRBased_DPhi_gg/F");
  fTree->Branch("New_DRBased_DR_gg",    &New_DRBased_DR_gg,     "New_DRBased_DR_gg/F");
  fTree->Branch("New_DRBased_DPhi_HH",  &New_DRBased_DPhi_HH,   "New_DRBased_DPhi_HH/F");
  fTree->Branch("New_DRBased_DR_HH",    &New_DRBased_DR_HH,     "New_DRBased_DR_HH/F");
  fTree->Branch("DRBased_a_costheta1",    &DRBased_a_costheta1,   "DRBased_a_costheta1/F");
  fTree->Branch("DRBased_a_costheta2",    &DRBased_a_costheta2,   "DRBased_a_costheta2/F");
  fTree->Branch("DRBased_a_costhetastar", &DRBased_a_costhetastar,"DRBased_a_costhetastar/F");
  fTree->Branch("DRBased_a_Phi",          &DRBased_a_Phi,         "DRBased_a_Phi/F");
  fTree->Branch("DRBased_a_Phi1",         &DRBased_a_Phi1,        "DRBased_a_Phi1/F");

}
