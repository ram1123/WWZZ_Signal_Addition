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
#include "progressbar.hpp"
#include <time.h>
#include "interface/utils.C"

void ReRunFHJetSelection( bool isMC = true,
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          TString OutPutPath = "./",
                          TString PrefixOutPutRootFileName = "",
                          bool WithSyst = true,
                          bool ifDNN = false
                        )
{
    clock_t tStart = clock();
    TFile *OldRootFile = new TFile(inputFile1,"READ");

    if (OldRootFile->IsZombie()) {

        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }
    std::cout << "Reading file ==> " << inputFile1 << std::endl;

    std::vector<TString> Vec_RootFileDirStructure;
    std::vector<TString> Vec_ListOfAllTrees;
    TString DirectoryName = GetTreeName(OldRootFile, Vec_RootFileDirStructure, Vec_ListOfAllTrees, 0);
    std::cout << "DirectoryName: " << DirectoryName << std::endl;
    int Size_Vec_ListOfAllTrees = Vec_ListOfAllTrees.size();
    std::cout << "Number of Trees: " << Size_Vec_ListOfAllTrees << std::endl;

    TString NewRootFileName = GetLastString(string(inputFile1), "/");
    TString OutPutRootFileName = OutPutPath+"/"+PrefixOutPutRootFileName+NewRootFileName;
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    newfile->mkdir(DirectoryName);

    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        std::cout << "Reading Tree: " << *OldTreeName << std::endl;
        if (!WithSyst) {
          if (TreesCount>=2) break;
        }

        TTree *OldTree = (TTree*)OldRootFile->Get(DirectoryName+"/"+TString(*OldTreeName));

        // if (isMC) {
        flashgg_MC flashggReader(OldTree);
        // } else {
        // flashgg_Data flashggReader(OldTree);
        // }

        newfile->cd(DirectoryName);

        // Clone the old tree
        auto newtree = OldTree->CloneTree(0);
        output outputVars = output(newtree);

        Long64_t nentries = OldTree->GetEntries();
        std::cout << "Files: " << TreesCount << "/" << Size_Vec_ListOfAllTrees <<  ",  nentries = " << nentries << std::endl;
        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

        std::vector<TLorentzVector> Jets;
        std::vector<Float_t> b_dis;

        int temp_percentage_done = 0;

        progressbar bar(20);
        for (Long64_t jentry=0; jentry<nentries;jentry++) {
            flashggReader.GetEntry(jentry);
            // if (jentry%1000 == 1) newtree->AutoSave("SaveSelf");
            // if(jentry>1000) break;  // For debug purpose
            //
            //
            // if (flashggReader.HGGCandidate_pt < 160 && (!ifDNN)) continue;

            Jets.clear();
            b_dis.clear();

            int percentage_done = (int)(((float)jentry/(float)nentries)*100);
            if (percentage_done % 5 == 0) {
                if (percentage_done != temp_percentage_done) {
                    bar.update();
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
                if (b_dis[0]>0.7221) continue;
                if (b_dis[1]>0.7221) continue;
                if (b_dis[2]>0.7221) continue;
                if (b_dis[3]>0.7221) continue;
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
                if (b_dis[4]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_4_px,
                                       flashggReader.goodJets_4_py,
                                       flashggReader.goodJets_4_pz,
                                       flashggReader.goodJets_4_E
                                       );
            }
            if (flashggReader.N_goodJets>=6){
                b_dis.push_back(flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                if (b_dis[5]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_5_px,
                                       flashggReader.goodJets_5_py,
                                       flashggReader.goodJets_5_pz,
                                       flashggReader.goodJets_5_E
                                       );
            }
            if (flashggReader.N_goodJets>=7){
                b_dis.push_back(flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                if (b_dis[6]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_6_px,
                                       flashggReader.goodJets_6_py,
                                       flashggReader.goodJets_6_pz,
                                       flashggReader.goodJets_6_E
                                       );
            }
            if (flashggReader.N_goodJets>=8){
                b_dis.push_back(flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                if (b_dis[7]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_7_px,
                                       flashggReader.goodJets_7_py,
                                       flashggReader.goodJets_7_pz,
                                       flashggReader.goodJets_7_E
                                       );
            }
            if (flashggReader.N_goodJets>=9) {
                b_dis.push_back(flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                if (b_dis[8]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_8_px,
                                       flashggReader.goodJets_8_py,
                                       flashggReader.goodJets_8_pz,
                                       flashggReader.goodJets_8_E
                                       );
            }
            if (flashggReader.N_goodJets>=10){
                b_dis.push_back(flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                if (b_dis[9]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_9_px,
                                       flashggReader.goodJets_9_py,
                                       flashggReader.goodJets_9_pz,
                                       flashggReader.goodJets_9_E
                                       );
            }
            // std::cout << "===========================================" << std::endl;
            // for (std::vector<float>::iterator bdiscriminator = b_dis.begin(); bdiscriminator != b_dis.end(); ++bdiscriminator)
            // {
              // std::cout << "bdiscriminator = " << *bdiscriminator << std::endl;
            // }
            // std::cout << "===========================================" << std::endl;

            std::vector<TLorentzVector> SelectedGoodJets; // Fill the FH selected jets
            std::vector<Float_t> Selectedb_dis; // Fill the b-discriminator value for FH selected jets
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
            outputVars.New_OnShellW_LeadingJet_bDis  = Selectedb_dis[0];
            outputVars.New_OnShellW_SubLeadingJet_bDis  = Selectedb_dis[1];
            outputVars.New_OffShellW_LeadingJet_bDis  = Selectedb_dis[2];
            outputVars.New_OffShellW_SubLeadingJet_bDis  = Selectedb_dis[3];

            outputVars.New_DPhi_gg = deltaPhi(flashggReader.Leading_Photon_phi, flashggReader.Subleading_Photon_phi);
            outputVars.New_DR_gg = deltaR(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi, flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi);

            TLorentzVector HiggsFromJets = SelectedGoodJets[0]+ SelectedGoodJets[1]+ SelectedGoodJets[2]+ SelectedGoodJets[3];
            outputVars.New_DPhi_HH = deltaPhi(HiggsFromJets.Phi(), flashggReader.HGGCandidate_phi);
            outputVars.New_DR_HH = deltaR(HiggsFromJets.Eta(), HiggsFromJets.Phi(), flashggReader.HGGCandidate_eta, flashggReader.HGGCandidate_phi);

            outputVars.PhotonID_min = (flashggReader.Leading_Photon_MVA > flashggReader.Subleading_Photon_MVA) ? flashggReader.Subleading_Photon_MVA : flashggReader.Leading_Photon_MVA;
            outputVars.PhotonID_max = (flashggReader.Leading_Photon_MVA > flashggReader.Subleading_Photon_MVA) ? flashggReader.Leading_Photon_MVA : flashggReader.Subleading_Photon_MVA;

            newtree->Fill();
        }
        std::cout << "\n" << std::endl;

        newtree->Write("",TObject::kOverwrite);
        newfile->Write();
        delete OldTree;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    newfile->Close();
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
