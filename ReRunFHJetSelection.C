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

#include "interface/utils.C"
#include "interface/ReRunFHJetSelection.h"
#include "interface/AngularVariables.cpp"

#include "interface/flashgg_Data.h"
#include "interface/flashgg_MC.h"

#include "interface/output.h"

#include <chrono>
#include "progressbar.hpp"
#include <time.h>

void ReRunFHJetSelection( /* bool isMC = true, */
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          TString OutPutPath = "./", // Signal, Backgrounds, Data
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
            // std::cout << "=======================" << std::endl;
            // if(jentry>10) break;  // For debug purpose

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
                                flashggReader.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                b_dis.push_back(flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                b_dis.push_back(flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                b_dis.push_back(flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                                flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                                flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[0]>0.7221) continue;
                // if (b_dis[1]>0.7221) continue;
                // if (b_dis[2]>0.7221) continue;
                // if (b_dis[3]>0.7221) continue;
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
                                flashggReader.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[4]>0.7221) continue;
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
                                flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[5]>0.7221) continue;
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
                                flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[6]>0.7221) continue;
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
                                flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[7]>0.7221) continue;
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
                                flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[8]>0.7221) continue;
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
                                flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb
                                );
                // if (b_dis[9]>0.7221) continue;
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_9_px,
                                       flashggReader.goodJets_9_py,
                                       flashggReader.goodJets_9_pz,
                                       flashggReader.goodJets_9_E
                                       );
            }

            TLorentzVector LV_LeadingPho, LV_SubLeadPho, LV_Hgg;
            LV_LeadingPho.SetPtEtaPhiE(flashggReader.Leading_Photon_pt,flashggReader.Leading_Photon_eta,flashggReader.Leading_Photon_phi,flashggReader.Leading_Photon_E);
            LV_SubLeadPho.SetPtEtaPhiE(flashggReader.Subleading_Photon_pt,flashggReader.Subleading_Photon_eta,flashggReader.Subleading_Photon_phi,flashggReader.Subleading_Photon_E);
            LV_Hgg = LV_LeadingPho + LV_SubLeadPho;

            /**
             * Get two leading Jets and save its topology
             */
            outputVars.New_TwoLeadJets_pT = (Jets[0]+Jets[1]).Pt();
            outputVars.New_TwoLeadJets_eta = (Jets[0]+Jets[1]).Eta();
            outputVars.New_TwoLeadJets_phi = (Jets[0]+Jets[1]).Phi();
            outputVars.New_TwoLeadJets_mass = (Jets[0]+Jets[1]).M();
            outputVars.New_TwoLeadJets_SumBScore = (b_dis[0]+b_dis[1]);

            TLorentzVector LV_pTBasedSel_W1 = Jets[0]+Jets[1];
            TLorentzVector LV_pTBasedSel_W2 = Jets[2]+Jets[3];

            outputVars.New_pTBasedSel_W1_pT = (LV_pTBasedSel_W1).Pt();
            outputVars.New_pTBasedSel_W1_eta = (LV_pTBasedSel_W1).Eta();
            outputVars.New_pTBasedSel_W1_phi = (LV_pTBasedSel_W1).Phi();
            outputVars.New_pTBasedSel_W1_mass = (LV_pTBasedSel_W1).M();
            outputVars.New_pTBasedSel_W1_SumBScore = (b_dis[0]+b_dis[1]);

            outputVars.New_pTBasedSel_W2_pT = (LV_pTBasedSel_W2).Pt();
            outputVars.New_pTBasedSel_W2_eta = (LV_pTBasedSel_W2).Eta();
            outputVars.New_pTBasedSel_W2_phi = (LV_pTBasedSel_W2).Phi();
            outputVars.New_pTBasedSel_W2_mass = (LV_pTBasedSel_W2).M();
            outputVars.New_pTBasedSel_W2_SumBScore = (b_dis[2]+b_dis[3]);

            outputVars.New_pTBasedSel_WW_pT = (LV_pTBasedSel_W1+LV_pTBasedSel_W2).Pt();
            outputVars.New_pTBasedSel_WW_eta = (LV_pTBasedSel_W1+LV_pTBasedSel_W2).Eta();
            outputVars.New_pTBasedSel_WW_phi = (LV_pTBasedSel_W1+LV_pTBasedSel_W2).Phi();
            outputVars.New_pTBasedSel_WW_mass = (LV_pTBasedSel_W1+LV_pTBasedSel_W2).M();
            outputVars.New_pTBasedSel_WW_SumBScore = (b_dis[0]+b_dis[1]+b_dis[2]+b_dis[3]);

            outputVars.New_pTBasedSel_dR_Hgg_Jet1    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), Jets[0].Eta(), Jets[0].Phi());
            outputVars.New_pTBasedSel_dR_Hgg_Jet2    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), Jets[1].Eta(), Jets[1].Phi());
            outputVars.New_pTBasedSel_dR_Hgg_Jet3    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), Jets[2].Eta(), Jets[2].Phi());
            outputVars.New_pTBasedSel_dR_Hgg_Jet4    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), Jets[3].Eta(), Jets[3].Phi());

            outputVars.New_pTBasedSel_dPhi_Hgg_Jet1    = DeltaPhi(LV_Hgg.Phi(), Jets[0].Phi());
            outputVars.New_pTBasedSel_dPhi_Hgg_Jet2    = DeltaPhi(LV_Hgg.Phi(), Jets[1].Phi());
            outputVars.New_pTBasedSel_dPhi_Hgg_Jet3    = DeltaPhi(LV_Hgg.Phi(), Jets[2].Phi());
            outputVars.New_pTBasedSel_dPhi_Hgg_Jet4    = DeltaPhi(LV_Hgg.Phi(), Jets[3].Phi());
            outputVars.New_pTBasedSel_minDeltaR_gg4j  = DeltaRmin(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi,
                                                  flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi,
                                                  Jets[0].Eta(), Jets[0].Phi(),
                                                  Jets[1].Eta(), Jets[1].Phi(),
                                                  Jets[2].Eta(), Jets[2].Phi(),
                                                  Jets[3].Eta(), Jets[3].Phi());
            outputVars.New_pTBasedSel_maxDeltaR_gg4j  = DeltaRmax(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi,
                                                  flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi,
                                                  Jets[0].Eta(), Jets[0].Phi(),
                                                  Jets[1].Eta(), Jets[1].Phi(),
                                                  Jets[2].Eta(), Jets[2].Phi(),
                                                  Jets[3].Eta(), Jets[3].Phi());
            outputVars.New_pTBasedSel_minDeltaR_4j  = DeltaRmin4Particle(
                                                  Jets[0].Eta(), Jets[0].Phi(),
                                                  Jets[1].Eta(), Jets[1].Phi(),
                                                  Jets[2].Eta(), Jets[2].Phi(),
                                                  Jets[3].Eta(), Jets[3].Phi());
            outputVars.New_pTBasedSel_maxDeltaR_4j  = DeltaRmax4Particle(
                                                  Jets[0].Eta(), Jets[0].Phi(),
                                                  Jets[1].Eta(), Jets[1].Phi(),
                                                  Jets[2].Eta(), Jets[2].Phi(),
                                                  Jets[3].Eta(), Jets[3].Phi());



            outputVars.New_pTBasedSel_DPhi_HH = DeltaPhi((LV_pTBasedSel_W1+LV_pTBasedSel_W2).Phi(), flashggReader.HGGCandidate_phi);
            outputVars.New_pTBasedSel_DR_HH = DeltaR((LV_pTBasedSel_W1+LV_pTBasedSel_W2).Eta(), (LV_pTBasedSel_W1+LV_pTBasedSel_W2).Phi(), flashggReader.HGGCandidate_eta, flashggReader.HGGCandidate_phi);

            double New_pTBasedSel_a_costheta1, New_pTBasedSel_a_costheta2, New_pTBasedSel_a_costhetastar, New_pTBasedSel_a_Phi, New_pTBasedSel_a_Phi1;
            AngularVariables New_pTBasedSel_Angles1(LV_Hgg + (LV_pTBasedSel_W1+LV_pTBasedSel_W2), LV_Hgg, LV_LeadingPho, LV_SubLeadPho, (LV_pTBasedSel_W1+LV_pTBasedSel_W2), LV_pTBasedSel_W1, LV_pTBasedSel_W2);
            New_pTBasedSel_Angles1.computeAngles(New_pTBasedSel_a_costheta1, New_pTBasedSel_a_costheta2, New_pTBasedSel_a_Phi, New_pTBasedSel_a_costhetastar, New_pTBasedSel_a_Phi1);

            outputVars.New_pTBasedSel_a_costheta1    = New_pTBasedSel_a_costheta1;
            outputVars.New_pTBasedSel_a_costheta2    = New_pTBasedSel_a_costheta2;
            outputVars.New_pTBasedSel_a_costhetastar = New_pTBasedSel_a_costhetastar;
            outputVars.New_pTBasedSel_a_Phi          = New_pTBasedSel_a_Phi;
            outputVars.New_pTBasedSel_a_Phi1         = New_pTBasedSel_a_Phi1;
            outputVars.New_pTBasedSel_CosThetaStar_CS = New_pTBasedSel_Angles1.getCosThetaStar_CS();
            outputVars.New_pTBasedSel_CosThetaStar_CS_old = New_pTBasedSel_Angles1.getCosThetaStar_CS_old(7500);
            outputVars.New_pTBasedSel_HelicityCostheta1 =  New_pTBasedSel_Angles1.CosThetaAngles()[0];
            outputVars.New_pTBasedSel_HelicityCostheta2 =  New_pTBasedSel_Angles1.CosThetaAngles()[1];


            // std::cout << "===========================================" << std::endl;
            // for (std::vector<float>::iterator bdiscriminator = b_dis.begin(); bdiscriminator != b_dis.end(); ++bdiscriminator)
            // {
              // std::cout << "bdiscriminator = " << *bdiscriminator << std::endl;
            // }
            // std::cout << "===========================================" << std::endl;

            std::vector<TLorentzVector> SelectedGoodJets; // Fill the FH selected jets
            std::vector<Float_t> Selectedb_dis; // Fill the b-discriminator value for FH selected jets
            GetFHminWHJets(Jets, b_dis, SelectedGoodJets, Selectedb_dis, 0);
            TLorentzVector JetWithMaxBScore; // Fill the FH selected jets
            Float_t JetWithMaxBScore_BScore = 0.0; // Fill the FH selected jets
            GetBScoreMaxJets(Jets, b_dis, JetWithMaxBScore, JetWithMaxBScore_BScore, 0);
            Float_t Sum_of_Two_Highest_BScores = 0.0;
            // std::cout << "=========================== L#275" << std::endl;
            SumOfHighestTwoBScores(b_dis, Sum_of_Two_Highest_BScores, 0);
            // std::cout << "=========================== L#277" << std::endl;
            TLorentzVector SumofTwoJetWithMaxBScore; // Fill the FH selected jets
            Float_t SumofTwoJetWithMaxBScore_BScore = 0.0; // Fill the FH selected jets
            GetBScoreMaxTwoJets(Jets, b_dis, SumofTwoJetWithMaxBScore, SumofTwoJetWithMaxBScore_BScore, 0);
            TLorentzVector MaxBScore_MaxPt; // Fill the FH selected jets
            Float_t MaxBScore_MaxPt_BScore = 0.0; // Fill the FH selected jets
            HighBScore_ThenLeadJet(Jets, b_dis, MaxBScore_MaxPt, MaxBScore_MaxPt_BScore, 0);
            // std::cout << "=========================== L#279" << std::endl;

            outputVars.New_SumTwoMaxBScore = Sum_of_Two_Highest_BScores;

            outputVars.New_MaxBScore = JetWithMaxBScore_BScore;
            outputVars.New_MaxBScore_Jet_pt = JetWithMaxBScore.Pt();
            outputVars.New_MaxBScore_Jet_eta = JetWithMaxBScore.Eta();
            outputVars.New_MaxBScore_Jet_phi = JetWithMaxBScore.Phi();
            outputVars.New_MaxBScore_Jet_mass = JetWithMaxBScore.M();

            outputVars.SumTwoMaxBjets = SumofTwoJetWithMaxBScore_BScore;
            outputVars.SumTwoMaxBjets_Jet_pt = SumofTwoJetWithMaxBScore.Pt();
            outputVars.SumTwoMaxBjets_Jet_eta = SumofTwoJetWithMaxBScore.Eta();
            outputVars.SumTwoMaxBjets_Jet_phi = SumofTwoJetWithMaxBScore.Phi();
            outputVars.SumTwoMaxBjets_Jet_mass = SumofTwoJetWithMaxBScore.M();

            outputVars.MaxBScore_MaxPt_BScore = MaxBScore_MaxPt_BScore;
            outputVars.MaxBScore_MaxPt_Jet_pt = MaxBScore_MaxPt.Pt();
            outputVars.MaxBScore_MaxPt_Jet_eta = MaxBScore_MaxPt.Eta();
            outputVars.MaxBScore_MaxPt_Jet_phi = MaxBScore_MaxPt.Phi();
            outputVars.MaxBScore_MaxPt_Jet_mass = MaxBScore_MaxPt.M();
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

            outputVars.New_DPhi_gg = DeltaPhi(flashggReader.Leading_Photon_phi, flashggReader.Subleading_Photon_phi);
            outputVars.New_DR_gg = DeltaR(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi, flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi);

            TLorentzVector LV_HiggsFromJets = SelectedGoodJets[0]+ SelectedGoodJets[1]+ SelectedGoodJets[2]+ SelectedGoodJets[3];
            outputVars.New_DPhi_HH = DeltaPhi(LV_HiggsFromJets.Phi(), flashggReader.HGGCandidate_phi);
            outputVars.New_DR_HH = DeltaR(LV_HiggsFromJets.Eta(), LV_HiggsFromJets.Phi(), flashggReader.HGGCandidate_eta, flashggReader.HGGCandidate_phi);

            outputVars.PhotonID_min = (flashggReader.Leading_Photon_MVA > flashggReader.Subleading_Photon_MVA) ? flashggReader.Subleading_Photon_MVA : flashggReader.Leading_Photon_MVA;
            outputVars.PhotonID_max = (flashggReader.Leading_Photon_MVA > flashggReader.Subleading_Photon_MVA) ? flashggReader.Leading_Photon_MVA : flashggReader.Subleading_Photon_MVA;

            double a_costheta1, a_costheta2, a_costhetastar, a_Phi, a_Phi1;
            // TLorentzVector LV_LeadingPho, LV_SubLeadPho, LV_Hgg;
            // LV_LeadingPho.SetPtEtaPhiE(flashggReader.Leading_Photon_pt,flashggReader.Leading_Photon_eta,flashggReader.Leading_Photon_phi,flashggReader.Leading_Photon_E);
            // LV_SubLeadPho.SetPtEtaPhiE(flashggReader.Subleading_Photon_pt,flashggReader.Subleading_Photon_eta,flashggReader.Subleading_Photon_phi,flashggReader.Subleading_Photon_E);
            // LV_Hgg = LV_LeadingPho + LV_SubLeadPho;
            AngularVariables Angles1(LV_Hgg + LV_HiggsFromJets, LV_Hgg, LV_LeadingPho, LV_SubLeadPho, LV_HiggsFromJets, SelectedGoodJets[0]+ SelectedGoodJets[1], SelectedGoodJets[2]+ SelectedGoodJets[3]);
            Angles1.computeAngles(a_costheta1, a_costheta2, a_Phi, a_costhetastar, a_Phi1);

            outputVars.a_costheta1    = a_costheta1;
            outputVars.a_costheta2    = a_costheta2;
            outputVars.a_costhetastar = a_costhetastar;
            outputVars.a_Phi          = a_Phi;
            outputVars.a_Phi1         = a_Phi1;
            outputVars.CosThetaStar_CS = Angles1.getCosThetaStar_CS();
            outputVars.CosThetaStar_CS_old = Angles1.getCosThetaStar_CS_old(7500);
            outputVars.HelicityCostheta1 =  Angles1.CosThetaAngles()[0];
            outputVars.HelicityCostheta2 =  Angles1.CosThetaAngles()[1];

            outputVars.New_OnShellW_E     = (SelectedGoodJets[0] + SelectedGoodJets[1]).E();
            outputVars.New_OnShellW_Mass     = (SelectedGoodJets[0] + SelectedGoodJets[1]).M();
            outputVars.New_OnShellW_pt    = (SelectedGoodJets[0] + SelectedGoodJets[1]).Pt();
            outputVars.New_OnShellW_px    = (SelectedGoodJets[0] + SelectedGoodJets[1]).Px();
            outputVars.New_OnShellW_py    = (SelectedGoodJets[0] + SelectedGoodJets[1]).Py();
            outputVars.New_OnShellW_pz    = (SelectedGoodJets[0] + SelectedGoodJets[1]).Py();
            outputVars.New_OnShellW_eta   = (SelectedGoodJets[0] + SelectedGoodJets[1]).Pz();
            outputVars.New_OnShellW_phi   = (SelectedGoodJets[0] + SelectedGoodJets[1]).Phi();
            outputVars.New_OffShellW_E    = (SelectedGoodJets[2] + SelectedGoodJets[3]).E();
            outputVars.New_OffShellW_Mass    = (SelectedGoodJets[2] + SelectedGoodJets[3]).M();
            outputVars.New_OffShellW_pt   = (SelectedGoodJets[2] + SelectedGoodJets[3]).Pt();
            outputVars.New_OffShellW_px   = (SelectedGoodJets[2] + SelectedGoodJets[3]).Px();
            outputVars.New_OffShellW_py   = (SelectedGoodJets[2] + SelectedGoodJets[3]).Py();
            outputVars.New_OffShellW_pz   = (SelectedGoodJets[2] + SelectedGoodJets[3]).Py();
            outputVars.New_OffShellW_eta  = (SelectedGoodJets[2] + SelectedGoodJets[3]).Pz();
            outputVars.New_OffShellW_phi  = (SelectedGoodJets[2] + SelectedGoodJets[3]).Phi();
            outputVars.New_HWW_E    = LV_HiggsFromJets.E();
            outputVars.New_HWW_Mass    = LV_HiggsFromJets.M();
            outputVars.New_HWW_pt   = LV_HiggsFromJets.Pt();
            outputVars.New_HWW_px   = LV_HiggsFromJets.Px();
            outputVars.New_HWW_py   = LV_HiggsFromJets.Py();
            outputVars.New_HWW_pz   = LV_HiggsFromJets.Py();
            outputVars.New_HWW_eta  = LV_HiggsFromJets.Pz();
            outputVars.New_HWW_phi  = LV_HiggsFromJets.Phi();
            outputVars.New_dR_Hgg_Jet1    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), SelectedGoodJets[0].Eta(), SelectedGoodJets[0].Phi());
            outputVars.New_dR_Hgg_Jet2    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), SelectedGoodJets[1].Eta(), SelectedGoodJets[1].Phi());
            outputVars.New_dR_Hgg_Jet3    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), SelectedGoodJets[2].Eta(), SelectedGoodJets[2].Phi());
            outputVars.New_dR_Hgg_Jet4    = DeltaR(LV_Hgg.Eta(), LV_Hgg.Phi(), SelectedGoodJets[3].Eta(), SelectedGoodJets[3].Phi());

            outputVars.New_dPhi_Hgg_Jet1    = DeltaPhi(LV_Hgg.Phi(), SelectedGoodJets[0].Phi());
            outputVars.New_dPhi_Hgg_Jet2    = DeltaPhi(LV_Hgg.Phi(), SelectedGoodJets[1].Phi());
            outputVars.New_dPhi_Hgg_Jet3    = DeltaPhi(LV_Hgg.Phi(), SelectedGoodJets[2].Phi());
            outputVars.New_dPhi_Hgg_Jet4    = DeltaPhi(LV_Hgg.Phi(), SelectedGoodJets[3].Phi());
            outputVars.New_minDeltaR_gg4j  = DeltaRmin(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi,
                                                  flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi,
                                                  SelectedGoodJets[0].Eta(), SelectedGoodJets[0].Phi(),
                                                  SelectedGoodJets[1].Eta(), SelectedGoodJets[1].Phi(),
                                                  SelectedGoodJets[2].Eta(), SelectedGoodJets[2].Phi(),
                                                  SelectedGoodJets[3].Eta(), SelectedGoodJets[3].Phi());
            outputVars.New_maxDeltaR_gg4j  = DeltaRmax(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi,
                                                  flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi,
                                                  SelectedGoodJets[0].Eta(), SelectedGoodJets[0].Phi(),
                                                  SelectedGoodJets[1].Eta(), SelectedGoodJets[1].Phi(),
                                                  SelectedGoodJets[2].Eta(), SelectedGoodJets[2].Phi(),
                                                  SelectedGoodJets[3].Eta(), SelectedGoodJets[3].Phi());
            outputVars.New_minDeltaR_4j  = DeltaRmin4Particle(
                                                  SelectedGoodJets[0].Eta(), SelectedGoodJets[0].Phi(),
                                                  SelectedGoodJets[1].Eta(), SelectedGoodJets[1].Phi(),
                                                  SelectedGoodJets[2].Eta(), SelectedGoodJets[2].Phi(),
                                                  SelectedGoodJets[3].Eta(), SelectedGoodJets[3].Phi());
            outputVars.New_maxDeltaR_4j  = DeltaRmax4Particle(
                                                  SelectedGoodJets[0].Eta(), SelectedGoodJets[0].Phi(),
                                                  SelectedGoodJets[1].Eta(), SelectedGoodJets[1].Phi(),
                                                  SelectedGoodJets[2].Eta(), SelectedGoodJets[2].Phi(),
                                                  SelectedGoodJets[3].Eta(), SelectedGoodJets[3].Phi());

            /*************************************************************************************/
            /*      Get FH jets based on DeltaR                                                  */
            /*************************************************************************************/
            std::vector<TLorentzVector> SelectedGoodJets_dRBased; // Fill the FH selected jets
            std::vector<Float_t> Selectedb_dis_dRBased; // Fill the b-discriminator value for FH selected jets
            GetFHJetUsingDR(LV_Hgg, Jets, b_dis, SelectedGoodJets_dRBased, Selectedb_dis_dRBased, 0);

            outputVars.New_DRBased_Leading_Jet_E  = SelectedGoodJets_dRBased[0].E();
            outputVars.New_DRBased_Leading_Jet_pt = SelectedGoodJets_dRBased[0].Pt();
            outputVars.New_DRBased_Leading_Jet_px = SelectedGoodJets_dRBased[0].Px();
            outputVars.New_DRBased_Leading_Jet_py = SelectedGoodJets_dRBased[0].Py();
            outputVars.New_DRBased_Leading_Jet_pz = SelectedGoodJets_dRBased[0].Pz();
            outputVars.New_DRBased_Leading_Jet_eta  = SelectedGoodJets_dRBased[0].Eta();
            outputVars.New_DRBased_Leading_Jet_phi  = SelectedGoodJets_dRBased[0].Phi();
            outputVars.New_DRBased_Subleading_Jet_E = SelectedGoodJets_dRBased[1].E();
            outputVars.New_DRBased_Subleading_Jet_pt  = SelectedGoodJets_dRBased[1].Pt();
            outputVars.New_DRBased_Subleading_Jet_px  = SelectedGoodJets_dRBased[1].Px();
            outputVars.New_DRBased_Subleading_Jet_py  = SelectedGoodJets_dRBased[1].Py();
            outputVars.New_DRBased_Subleading_Jet_pz  = SelectedGoodJets_dRBased[1].Pz();
            outputVars.New_DRBased_Subleading_Jet_eta = SelectedGoodJets_dRBased[1].Eta();
            outputVars.New_DRBased_Subleading_Jet_phi = SelectedGoodJets_dRBased[1].Phi();
            outputVars.New_DRBased_Sub2leading_Jet_E  = SelectedGoodJets_dRBased[2].E();
            outputVars.New_DRBased_Sub2leading_Jet_pt = SelectedGoodJets_dRBased[2].Pt();
            outputVars.New_DRBased_Sub2leading_Jet_px = SelectedGoodJets_dRBased[2].Px();
            outputVars.New_DRBased_Sub2leading_Jet_py = SelectedGoodJets_dRBased[2].Py();
            outputVars.New_DRBased_Sub2leading_Jet_pz = SelectedGoodJets_dRBased[2].Pz();
            outputVars.New_DRBased_Sub2leading_Jet_eta  = SelectedGoodJets_dRBased[2].Eta();
            outputVars.New_DRBased_Sub2leading_Jet_phi  = SelectedGoodJets_dRBased[2].Phi();
            outputVars.New_DRBased_Sub3leading_Jet_E  = SelectedGoodJets_dRBased[3].E();
            outputVars.New_DRBased_Sub3leading_Jet_pt = SelectedGoodJets_dRBased[3].Pt();
            outputVars.New_DRBased_Sub3leading_Jet_px = SelectedGoodJets_dRBased[3].Px();
            outputVars.New_DRBased_Sub3leading_Jet_py = SelectedGoodJets_dRBased[3].Py();
            outputVars.New_DRBased_Sub3leading_Jet_pz = SelectedGoodJets_dRBased[3].Pz();
            outputVars.New_DRBased_Sub3leading_Jet_eta  = SelectedGoodJets_dRBased[3].Eta();
            outputVars.New_DRBased_Sub3leading_Jet_phi  = SelectedGoodJets_dRBased[3].Phi();
            outputVars.New_DRBased_OnShellW_LeadingJet_bDis  = Selectedb_dis[0];
            outputVars.New_DRBased_OnShellW_SubLeadingJet_bDis  = Selectedb_dis[1];
            outputVars.New_DRBased_OffShellW_LeadingJet_bDis  = Selectedb_dis[2];
            outputVars.New_DRBased_OffShellW_SubLeadingJet_bDis  = Selectedb_dis[3];

            outputVars.New_DRBased_DPhi_gg = DeltaPhi(flashggReader.Leading_Photon_phi, flashggReader.Subleading_Photon_phi);
            outputVars.New_DRBased_DR_gg = DeltaR(flashggReader.Leading_Photon_eta, flashggReader.Leading_Photon_phi, flashggReader.Subleading_Photon_eta, flashggReader.Subleading_Photon_phi);

            TLorentzVector LV_HiggsFromJets_DRBased = SelectedGoodJets_dRBased[0]+ SelectedGoodJets_dRBased[1]+ SelectedGoodJets_dRBased[2]+ SelectedGoodJets_dRBased[3];
            outputVars.New_DRBased_DPhi_HH = DeltaPhi(LV_HiggsFromJets_DRBased.Phi(), flashggReader.HGGCandidate_phi);
            outputVars.New_DRBased_DR_HH = DeltaR(LV_HiggsFromJets_DRBased.Eta(), LV_HiggsFromJets_DRBased.Phi(), flashggReader.HGGCandidate_eta, flashggReader.HGGCandidate_phi);

            // outputVars.PhotonID_min = (flashggReader.Leading_Photon_MVA > flashggReader.Subleading_Photon_MVA) ? flashggReader.Subleading_Photon_MVA : flashggReader.Leading_Photon_MVA;
            // outputVars.PhotonID_max = (flashggReader.Leading_Photon_MVA > flashggReader.Subleading_Photon_MVA) ? flashggReader.Leading_Photon_MVA : flashggReader.Subleading_Photon_MVA;

            double DRBased_a_costheta1, DRBased_a_costheta2, DRBased_a_costhetastar, DRBased_a_Phi, DRBased_a_Phi1;
            TLorentzVector LV_LeadingPho_DRBased, LV_SubLeadPho_DRBased, LV_Hgg_DRBased;
            LV_LeadingPho_DRBased.SetPtEtaPhiE(flashggReader.Leading_Photon_pt,flashggReader.Leading_Photon_eta,flashggReader.Leading_Photon_phi,flashggReader.Leading_Photon_E);
            LV_SubLeadPho_DRBased.SetPtEtaPhiE(flashggReader.Subleading_Photon_pt,flashggReader.Subleading_Photon_eta,flashggReader.Subleading_Photon_phi,flashggReader.Subleading_Photon_E);
            LV_Hgg_DRBased = LV_LeadingPho_DRBased + LV_SubLeadPho_DRBased;
            AngularVariables Angles2(LV_Hgg_DRBased + LV_HiggsFromJets_DRBased, LV_Hgg_DRBased, LV_LeadingPho_DRBased, LV_SubLeadPho_DRBased, LV_HiggsFromJets_DRBased, SelectedGoodJets_dRBased[0]+ SelectedGoodJets_dRBased[1], SelectedGoodJets_dRBased[2]+ SelectedGoodJets_dRBased[3]);
            Angles2.computeAngles(DRBased_a_costheta1, DRBased_a_costheta2, DRBased_a_Phi, DRBased_a_costhetastar, DRBased_a_Phi1);

            outputVars.DRBased_a_costheta1    = DRBased_a_costheta1;
            outputVars.DRBased_a_costheta2    = DRBased_a_costheta2;
            outputVars.DRBased_a_costhetastar = DRBased_a_costhetastar;
            outputVars.DRBased_a_Phi          = DRBased_a_Phi;
            outputVars.DRBased_a_Phi1         = DRBased_a_Phi1;

            outputVars.New_DRBased_OnShellW_E     = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).E();
            outputVars.New_DRBased_OnShellW_Mass     = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).M();
            outputVars.New_DRBased_OnShellW_pt    = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).Pt();
            outputVars.New_DRBased_OnShellW_px    = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).Px();
            outputVars.New_DRBased_OnShellW_py    = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).Py();
            outputVars.New_DRBased_OnShellW_pz    = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).Py();
            outputVars.New_DRBased_OnShellW_eta   = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).Pz();
            outputVars.New_DRBased_OnShellW_phi   = (SelectedGoodJets_dRBased[0] + SelectedGoodJets_dRBased[1]).Phi();
            outputVars.New_DRBased_OffShellW_E    = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).E();
            outputVars.New_DRBased_OffShellW_Mass    = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).M();
            outputVars.New_DRBased_OffShellW_pt   = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).Pt();
            outputVars.New_DRBased_OffShellW_px   = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).Px();
            outputVars.New_DRBased_OffShellW_py   = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).Py();
            outputVars.New_DRBased_OffShellW_pz   = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).Py();
            outputVars.New_DRBased_OffShellW_eta  = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).Pz();
            outputVars.New_DRBased_OffShellW_phi  = (SelectedGoodJets_dRBased[2] + SelectedGoodJets_dRBased[3]).Phi();
            outputVars.New_DRBased_HWW_E    = LV_HiggsFromJets_DRBased.E();
            outputVars.New_DRBased_HWW_Mass    = LV_HiggsFromJets_DRBased.M();
            outputVars.New_DRBased_HWW_pt   = LV_HiggsFromJets_DRBased.Pt();
            outputVars.New_DRBased_HWW_px   = LV_HiggsFromJets_DRBased.Px();
            outputVars.New_DRBased_HWW_py   = LV_HiggsFromJets_DRBased.Py();
            outputVars.New_DRBased_HWW_pz   = LV_HiggsFromJets_DRBased.Py();
            outputVars.New_DRBased_HWW_eta  = LV_HiggsFromJets_DRBased.Pz();
            outputVars.New_DRBased_HWW_phi  = LV_HiggsFromJets_DRBased.Phi();
            outputVars.New_DRBased_dR_Hgg_Jet1    = DeltaR(LV_Hgg_DRBased.Eta(), LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[0].Eta(), SelectedGoodJets_dRBased[0].Phi());
            outputVars.New_DRBased_dR_Hgg_Jet2    = DeltaR(LV_Hgg_DRBased.Eta(), LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[1].Eta(), SelectedGoodJets_dRBased[1].Phi());
            outputVars.New_DRBased_dR_Hgg_Jet3    = DeltaR(LV_Hgg_DRBased.Eta(), LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[2].Eta(), SelectedGoodJets_dRBased[2].Phi());
            outputVars.New_DRBased_dR_Hgg_Jet4    = DeltaR(LV_Hgg_DRBased.Eta(), LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[3].Eta(), SelectedGoodJets_dRBased[3].Phi());

            outputVars.New_DRBased_dPhi_Hgg_Jet1    = DeltaPhi(LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[0].Phi());
            outputVars.New_DRBased_dPhi_Hgg_Jet2    = DeltaPhi(LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[1].Phi());
            outputVars.New_DRBased_dPhi_Hgg_Jet3    = DeltaPhi(LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[2].Phi());
            outputVars.New_DRBased_dPhi_Hgg_Jet4    = DeltaPhi(LV_Hgg_DRBased.Phi(), SelectedGoodJets_dRBased[3].Phi());
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
