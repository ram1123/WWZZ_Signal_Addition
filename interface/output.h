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

   Float_t         New_Leading_Jet_E = -999.0;
   Float_t         New_Leading_Jet_pt = -999.0;
   Float_t         New_Leading_Jet_px = -999.0;
   Float_t         New_Leading_Jet_py = -999.0;
   Float_t         New_Leading_Jet_pz = -999.0;
   Float_t         New_Leading_Jet_eta = -999.0;
   Float_t         New_Leading_Jet_phi = -999.0;
   Float_t         New_Subleading_Jet_E = -999.0;
   Float_t         New_Subleading_Jet_pt = -999.0;
   Float_t         New_Subleading_Jet_px = -999.0;
   Float_t         New_Subleading_Jet_py = -999.0;
   Float_t         New_Subleading_Jet_pz = -999.0;
   Float_t         New_Subleading_Jet_eta = -999.0;
   Float_t         New_Subleading_Jet_phi = -999.0;
   Float_t         New_Sub2leading_Jet_E = -999.0;
   Float_t         New_Sub2leading_Jet_pt = -999.0;
   Float_t         New_Sub2leading_Jet_px = -999.0;
   Float_t         New_Sub2leading_Jet_py = -999.0;
   Float_t         New_Sub2leading_Jet_pz = -999.0;
   Float_t         New_Sub2leading_Jet_eta = -999.0;
   Float_t         New_Sub2leading_Jet_phi = -999.0;
   Float_t         New_Sub3leading_Jet_E = -999.0;
   Float_t         New_Sub3leading_Jet_pt = -999.0;
   Float_t         New_Sub3leading_Jet_px = -999.0;
   Float_t         New_Sub3leading_Jet_py = -999.0;
   Float_t         New_Sub3leading_Jet_pz = -999.0;
   Float_t         New_Sub3leading_Jet_eta = -999.0;
   Float_t         New_Sub3leading_Jet_phi = -999.0;
   Float_t         New_OnShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb = -999.0;
   Float_t         New_OnShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb = -999.0;
   Float_t         New_OffShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb = -999.0;
   Float_t         New_OffShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb = -999.0;




};

#endif

void output::init(TTree* tree) {

  fTree = tree;

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
   fTree->Branch("New_OnShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &New_OnShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb, "New_OnShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb/F");
   fTree->Branch("New_OnShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &New_OnShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb, "New_OnShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb/F");
   fTree->Branch("New_OffShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &New_OffShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb, "New_OffShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb/F");
   fTree->Branch("New_OffShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &New_OffShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb, "New_OffShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb/F");
   
   

}
