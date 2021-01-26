/*
 * =====================================================================================
 *
 *       Filename:  ReRunFHJetSelection.C
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/21/21 13:11:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */

#include "interface/ReRunFHJetSelection.h"
#include "interface/flashgg_Data.h"
#include "interface/flashgg_MC.h"
#include "interface/output.h"
#include <chrono> 


// void ReRunFHJetSelection(bool isMC = true, TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root")
void ReRunFHJetSelection(TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root", int isMC=0)
{
    TFile *OldRootFile = new TFile(inputFile1);
    
    if (OldRootFile->IsZombie()) {

        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }
    
    std::cout << "Reading file ==> " << inputFile1 << std::endl;

    TString RootFileName = GetLastString(string(inputFile1), "/");

    TString RootFileDirStructure[3];
    TString OldTreeName = GetTreeName(OldRootFile, RootFileDirStructure);
    std::cout << "Tree name: " << OldTreeName << std::endl;
    
    TTree *OldTree = (TTree*)OldRootFile->Get(OldTreeName);

    // flashgg_MC flashggReader = flashgg_MC(OldTree); 
    // flashgg_Data flashggReader = flashgg_Data(OldTree);

    // if (isMC) {
        flashgg_MC flashggReader(OldTree);
    // } else {
        // flashgg_Data flashggReader(OldTree);
    // }

    // Create a new file
    TFile *newfile = new TFile(RootFileName, "recreate");
    newfile->mkdir(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);
    newfile->cd(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);
    
    // Clone the old tree
    auto newtree = OldTree->CloneTree(0);
    output outputVars = output(newtree);
    
    Long64_t nentries = OldTree->GetEntries();
    std::cout << "nentries = " << nentries << std::endl;
    
    std::vector<TLorentzVector> Jets;
    std::vector<Float_t> b_dis;

    int temp_percentage_done = 0;
    
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        flashggReader.GetEntry(jentry);  
        // if(jentry>10) break;  // For debug purpose

        Jets.clear();
        b_dis.clear();
        
        
        int percentage_done = (int)(((float)jentry/(float)nentries)*100);
        if (percentage_done % 10 == 0) {
          if (percentage_done != temp_percentage_done) {
            std::cout << percentage_done  << "%"<< std::endl;
            temp_percentage_done = percentage_done;
          }
        }
        
        if (flashggReader.N_goodJets>=4){        
            b_dis.push_back(flashggReader.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb + 
                            flashggReader.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                            flashggReader.allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                            );
            b_dis.push_back(flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb + 
                            flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                            flashggReader.allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                            );
            b_dis.push_back(flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb + 
                            flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                            flashggReader.allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                            );
            b_dis.push_back(flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb + 
                            flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                            flashggReader.allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                            );
            Jets.push_back(TLorentzVector(0,0,0,0));
            Jets.back().SetPxPyPzE(
                                  flashggReader.goodJets_0_px,
                                  flashggReader.goodJets_0_py,
                                  flashggReader.goodJets_0_pz,
                                  flashggReader.goodJets_0_E
                                );
            Jets.push_back(TLorentzVector(0,0,0,0));
            Jets.back().SetPxPyPzE(
                                  flashggReader.goodJets_1_px,
                                  flashggReader.goodJets_1_py,
                                  flashggReader.goodJets_1_pz,
                                  flashggReader.goodJets_1_E
                                );
            Jets.push_back(TLorentzVector(0,0,0,0));
            Jets.back().SetPxPyPzE(
                                  flashggReader.goodJets_2_px,
                                  flashggReader.goodJets_2_py,
                                  flashggReader.goodJets_2_pz,
                                  flashggReader.goodJets_2_E
                                );
            Jets.push_back(TLorentzVector(0,0,0,0));
            Jets.back().SetPxPyPzE(
                                  flashggReader.goodJets_3_px,
                                  flashggReader.goodJets_3_py,
                                  flashggReader.goodJets_3_pz,
                                  flashggReader.goodJets_3_E
                                );
        }
        if (flashggReader.N_goodJets>=5){        
            b_dis.push_back(flashggReader.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                            flashggReader.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                            flashggReader.allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb                
                            );
            Jets.push_back(TLorentzVector(0,0,0,0));
            Jets.back().SetPxPyPzE(
                                  flashggReader.goodJets_4_px,
                                  flashggReader.goodJets_4_py,
                                  flashggReader.goodJets_4_pz,
                                  flashggReader.goodJets_4_E
                                );
        }
        // if (flashggReader.N_goodJets>=6){        
            // b_dis.push_back(flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
            //                 flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
            //                 flashggReader.allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb                
            //                 );
        //   Jets.push_back(TLorentzVector(0,0,0,0));
        //   Jets.back().SetPxPyPzE(
        //                           flashggReader.goodJets_5_px,
        //                           flashggReader.goodJets_5_py,
        //                           flashggReader.goodJets_5_pz,
        //                           flashggReader.goodJets_5_E
        //                         );
        // }
        // if (flashggReader.N_goodJets>=7){
            // b_dis.push_back(flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
            //                 flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
            //                 flashggReader.allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb                
            //                 );
        //   Jets.push_back(TLorentzVector(0,0,0,0));
        //   Jets.back().SetPxPyPzE(
        //                           flashggReader.goodJets_6_px,
        //                           flashggReader.goodJets_6_py,
        //                           flashggReader.goodJets_6_pz,
        //                           flashggReader.goodJets_6_E
        //                         );
        // }
        // if (flashggReader.N_goodJets>=8){
            // b_dis.push_back(flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
            //                 flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
            //                 flashggReader.allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb                
            //                 );
        //   Jets.push_back(TLorentzVector(0,0,0,0));
        //   Jets.back().SetPxPyPzE(
        //                           flashggReader.goodJets_7_px,
        //                           flashggReader.goodJets_7_py,
        //                           flashggReader.goodJets_7_pz,
        //                           flashggReader.goodJets_7_E
        //                         );
        // }
        // if (flashggReader.N_goodJets>=9) {        
            // b_dis.push_back(flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
            //                 flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
            //                 flashggReader.allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb                
            //                 );
        //   Jets.push_back(TLorentzVector(0,0,0,0));
        //   Jets.back().SetPxPyPzE(
        //                           flashggReader.goodJets_8_px,
        //                           flashggReader.goodJets_8_py,
        //                           flashggReader.goodJets_8_pz,
        //                           flashggReader.goodJets_8_E
        //                         );
        // }
        // if (flashggReader.N_goodJets>=10){        
            // b_dis.push_back(flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
            //                 flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
            //                 flashggReader.allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb                
            //                 );
        //   Jets.push_back(TLorentzVector(0,0,0,0));
        //   Jets.back().SetPxPyPzE(
        //                           flashggReader.goodJets_9_px,
        //                           flashggReader.goodJets_9_py,
        //                           flashggReader.goodJets_9_pz,
        //                           flashggReader.goodJets_9_E
        //                         );
        // }
        std::vector<TLorentzVector> SelectedGoodJets;
        std::vector<Float_t> Selectedb_dis;
        GetFHminWHJets(Jets, b_dis, SelectedGoodJets, Selectedb_dis, 0);

        // std::cout << "Jets size = " << Jets.size() << std::endl;

        outputVars.New_Leading_Jet_E  = SelectedGoodJets[0].E();
        outputVars.New_Leading_Jet_pt = SelectedGoodJets[0].Pt();
        outputVars.New_Leading_Jet_px = SelectedGoodJets[0].Px();
        outputVars.New_Leading_Jet_py = SelectedGoodJets[0].Py();
        outputVars.New_Leading_Jet_pz = SelectedGoodJets[0].Pz();
        outputVars.New_Leading_Jet_eta  = SelectedGoodJets[0].Eta();
        outputVars.New_Leading_Jet_phi  = SelectedGoodJets[0].Phi();
        outputVars.New_Subleading_Jet_E = SelectedGoodJets[1].E();
        outputVars.New_Subleading_Jet_pt  = SelectedGoodJets[1].Pt();
        outputVars.New_Subleading_Jet_px  = SelectedGoodJets[1].Px();
        outputVars.New_Subleading_Jet_py  = SelectedGoodJets[1].Py();
        outputVars.New_Subleading_Jet_pz  = SelectedGoodJets[1].Pz();
        outputVars.New_Subleading_Jet_eta = SelectedGoodJets[1].Eta();
        outputVars.New_Subleading_Jet_phi = SelectedGoodJets[1].Phi();
        outputVars.New_Sub2leading_Jet_E  = SelectedGoodJets[2].E();
        outputVars.New_Sub2leading_Jet_pt = SelectedGoodJets[2].Pt();
        outputVars.New_Sub2leading_Jet_px = SelectedGoodJets[2].Px();
        outputVars.New_Sub2leading_Jet_py = SelectedGoodJets[2].Py();
        outputVars.New_Sub2leading_Jet_pz = SelectedGoodJets[2].Pz();
        outputVars.New_Sub2leading_Jet_eta  = SelectedGoodJets[2].Eta();
        outputVars.New_Sub2leading_Jet_phi  = SelectedGoodJets[2].Phi();
        outputVars.New_Sub3leading_Jet_E  = SelectedGoodJets[3].E();
        outputVars.New_Sub3leading_Jet_pt = SelectedGoodJets[3].Pt();
        outputVars.New_Sub3leading_Jet_px = SelectedGoodJets[3].Px();
        outputVars.New_Sub3leading_Jet_py = SelectedGoodJets[3].Py();
        outputVars.New_Sub3leading_Jet_pz = SelectedGoodJets[3].Pz();
        outputVars.New_Sub3leading_Jet_eta  = SelectedGoodJets[3].Eta();
        outputVars.New_Sub3leading_Jet_phi  = SelectedGoodJets[3].Phi();
        outputVars.New_OnShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb  = Selectedb_dis[0];
        outputVars.New_OnShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb  = Selectedb_dis[1];
        outputVars.New_OffShellW_LeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb  = Selectedb_dis[2];
        outputVars.New_OffShellW_SubLeadingJet_bDiscriminator_mini_pfDeepFlavourJetTags_probb  = Selectedb_dis[3];

        newtree->Fill();
    }
    
    newtree->Write();
    newfile->Write();
}
