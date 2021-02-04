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
#include "interface/utils.C"
#include <chrono>
#include "progressbar.hpp"
#include <time.h>

void ReRunFHJetSelection( bool isMC = true,
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          TString OutPutPath = "./",
                          TString PrefixOutPutRootFileName = "",
                          bool WithSyst = false,
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

    std::vector<TString> Vec_ListOfAllTrees;
    getallTrees(OldRootFile,"/",Vec_ListOfAllTrees, "Tag_1");
    int Size_Vec_ListOfAllTrees = Vec_ListOfAllTrees.size();
    std::cout << "Number of Trees: " << Size_Vec_ListOfAllTrees << std::endl;

    vector<string> fields;
    Tokenize(std::string(Vec_ListOfAllTrees[0]),fields, "/");
    TString DirectoryName = "";

    // TH1F *h1 = new TH1F("h1","",14,0, 14);
    // h1->GetXaxis()->SetBinLabel(1,"Total Event");
    // h1->GetXaxis()->SetBinLabel(2,"passPhotonSels");
    // h1->GetXaxis()->SetBinLabel(3,"dipho_MVA>0.9");
    // h1->GetXaxis()->SetBinLabel(4,"diPhoPt>50");
    // h1->GetXaxis()->SetBinLabel(5,"diPhoPt>100");
    // h1->GetXaxis()->SetBinLabel(6,"diPhoPt>110");
    // h1->GetXaxis()->SetBinLabel(7,"diPhoPt>120");
    // h1->GetXaxis()->SetBinLabel(8,"diPhoPt>130");
    // h1->GetXaxis()->SetBinLabel(9,"diPhoPt>140");
    // h1->GetXaxis()->SetBinLabel(10,"diPhoPt>150");
    // h1->GetXaxis()->SetBinLabel(11,"diPhoPt>160");
    // h1->GetXaxis()->SetBinLabel(12,"diPhoPt>190");
    // h1->GetXaxis()->SetBinLabel(13,"Any b-jet");
    // h1->GetXaxis()->SetBinLabel(14,"FH Jet Sel");

    // TH1F *h1_weight = new TH1F("h1_weight","",14,0,14);
    // h1_weight->GetXaxis()->SetBinLabel(1,"Total Event");
    // h1_weight->GetXaxis()->SetBinLabel(2,"passPhotonSels");
    // h1_weight->GetXaxis()->SetBinLabel(3,"dipho_MVA>0.9");
    // h1_weight->GetXaxis()->SetBinLabel(4,"diPhoPt>50");
    // h1_weight->GetXaxis()->SetBinLabel(5,"diPhoPt>100");
    // h1_weight->GetXaxis()->SetBinLabel(6,"diPhoPt>110");
    // h1_weight->GetXaxis()->SetBinLabel(7,"diPhoPt>120");
    // h1_weight->GetXaxis()->SetBinLabel(8,"diPhoPt>130");
    // h1_weight->GetXaxis()->SetBinLabel(9,"diPhoPt>140");
    // h1_weight->GetXaxis()->SetBinLabel(10,"diPhoPt>150");
    // h1_weight->GetXaxis()->SetBinLabel(11,"diPhoPt>160");
    // h1_weight->GetXaxis()->SetBinLabel(12,"diPhoPt>190");
    // h1_weight->GetXaxis()->SetBinLabel(13,"Any b-jet");
    // h1_weight->GetXaxis()->SetBinLabel(14,"FH Jet Sel");

    for (std::vector<string>::iterator DirName = fields.begin(); DirName != (fields.end()-1); ++DirName)
    {
        DirectoryName += *DirName + "/";
    }
    std::cout << "DirectoryName: " << DirectoryName << std::endl;

    TString NewRootFileName = GetLastString(string(inputFile1), "/");
    TString OutPutRootFileName = OutPutPath+"/"+PrefixOutPutRootFileName+NewRootFileName;
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    newfile->mkdir(DirectoryName);

    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        if (!WithSyst) {
          if (TreesCount>=2) break;
        }
        std::cout << "Reading Tree: " << *OldTreeName << std::endl;

        TTree *OldTree = (TTree*)OldRootFile->Get(TString(*OldTreeName));

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
        std::vector<int> passMediumJetID;
        std::vector<int> passTightJetID;

        int temp_percentage_done = 0;

        progressbar bar(20);
        for (Long64_t jentry=0; jentry<nentries;jentry++) {
            flashggReader.GetEntry(jentry);
            // if (jentry%1000 == 1) newtree->AutoSave("SaveSelf");
            // if(jentry>1000) break;  // For debug purpose
            // h1->Fill(0);
            // h1_weight->Fill(0.,flashggReader.weight);

            // if (int(flashggReader.passPhotonSels) == 1) {
            //   h1->Fill(1);
            //   h1_weight->Fill(1.,flashggReader.weight);
            // }
            if (int(flashggReader.passPhotonSels) != 1) continue;
            if (flashggReader.dipho_MVA < 0.9) continue;
            if (flashggReader.HGGCandidate_pt < 140 ) continue;
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9) {
            //   h1->Fill(2);
            //   h1_weight->Fill(2.,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 50 ) {
            //   h1->Fill(3);
            //   h1_weight->Fill(3.,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 100 ) {
            //     h1->Fill(4);
            //     h1_weight->Fill(4,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 110 ) {
            //     h1->Fill(5);
            //     h1_weight->Fill(5,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 120 ) {
            //     h1->Fill(6);
            //     h1_weight->Fill(6,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 130 ) {
            //     h1->Fill(7);
            //     h1_weight->Fill(7,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 140 ) {
            //   h1->Fill(8);
            //   h1_weight->Fill(8.,flashggReader.weight);
            // }
            // // if (flashggReader.HGGCandidate_pt < 160 ) continue;
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 150 ) {
            //     h1->Fill(9);
            //     h1_weight->Fill(9,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 160 ) {
            //     h1->Fill(10);
            //     h1_weight->Fill(10,flashggReader.weight);
            // }
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 190 ) {
            //     h1->Fill(11);
            //     h1_weight->Fill(11,flashggReader.weight);
            // }

            Jets.clear();
            b_dis.clear();
            passMediumJetID.clear();
            passTightJetID.clear();

            int percentage_done = (int)(((float)jentry/(float)nentries)*100);
            if (percentage_done % 5 == 0) {
                if (percentage_done != temp_percentage_done) {
                    bar.update();
                    temp_percentage_done = percentage_done;
                }
            }
            bool isBjets = false;

            if (flashggReader.N_goodJets >= 4) {
              if (flashggReader.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
              if (flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
              if (flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
              if (flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }
            if (flashggReader.N_goodJets == 4) {
              if (flashggReader.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                flashggReader.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                flashggReader.allJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }
            if (flashggReader.N_goodJets == 5) {
              if (flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }
            if (flashggReader.N_goodJets == 6) {
              if (flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }
            if (flashggReader.N_goodJets == 7) {
              if (flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }
            if (flashggReader.N_goodJets == 8) {
              if (flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }
            if (flashggReader.N_goodJets == 9) {
              if (flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb +
                  flashggReader.goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb +
                  flashggReader.allJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb > 0.7221) isBjets = true;
            }

          // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 140  && !(isBjets)) {
          //   // continue;
          //     h1->Fill(12);
          //     h1_weight->Fill(12.,flashggReader.weight);
          // }
          if (isBjets) continue;

            if (flashggReader.N_goodJets>=4)
            {
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
                passMediumJetID.push_back( flashggReader.goodJets_0_PassMediumJetPUID );
                passMediumJetID.push_back( flashggReader.goodJets_1_PassMediumJetPUID );
                passMediumJetID.push_back( flashggReader.goodJets_2_PassMediumJetPUID );
                passMediumJetID.push_back( flashggReader.goodJets_3_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_0_PassTightJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_1_PassTightJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_2_PassTightJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_3_PassTightJetPUID );

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
                passMediumJetID.push_back( flashggReader.goodJets_4_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_4_PassTightJetPUID );
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
                passMediumJetID.push_back( flashggReader.goodJets_5_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_5_PassTightJetPUID );
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
                passMediumJetID.push_back( flashggReader.goodJets_6_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_6_PassTightJetPUID );
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
                passMediumJetID.push_back( flashggReader.goodJets_7_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_7_PassTightJetPUID );
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
                passMediumJetID.push_back( flashggReader.goodJets_8_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_8_PassTightJetPUID );
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
                passMediumJetID.push_back( flashggReader.goodJets_9_PassMediumJetPUID );
                passTightJetID.push_back( flashggReader.goodJets_9_PassTightJetPUID );
                Jets.push_back(TLorentzVector(0,0,0,0));
                Jets.back().SetPxPyPzE(
                                       flashggReader.goodJets_9_px,
                                       flashggReader.goodJets_9_py,
                                       flashggReader.goodJets_9_pz,
                                       flashggReader.goodJets_9_E
                                       );
            }

            std::vector<TLorentzVector> SelectedGoodJets; // Fill the FH selected jets
            std::vector<Float_t> Selectedb_dis; // Fill the b-discriminator value for FH selected jets
            GetFHminWHJets(Jets, b_dis, passMediumJetID, passTightJetID, SelectedGoodJets, Selectedb_dis, 0);

            // std::cout << "Jets size = " << Jets.size() << std::endl;
            // if (int(flashggReader.passPhotonSels) == 1 && flashggReader.dipho_MVA > 0.9 && flashggReader.HGGCandidate_pt > 140  && !(isBjets) && !(Selectedb_dis[0]<-1 || Selectedb_dis[1]<-1 || Selectedb_dis[2]<-1 || Selectedb_dis[3]<-1)) {
            //   // continue;
            //   h1->Fill(13);
            //   h1_weight->Fill(13.,flashggReader.weight);
            // }
            if (Selectedb_dis[0]<-1 || Selectedb_dis[1]<-1 || Selectedb_dis[2]<-1 || Selectedb_dis[3]<-1)
              continue;

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
        std::cout << "\n" << std::endl;

        newtree->Write("",TObject::kOverwrite);
        // h1->Write();
        // h1_weight->Write();
        newfile->Write();
        delete OldTree;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    newfile->Close();
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
