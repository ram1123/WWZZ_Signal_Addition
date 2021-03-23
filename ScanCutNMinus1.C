/*
 * =====================================================================================
 *
 *       Filename:  ScanCutNMinus1.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/16/21 10:14:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */


#include <time.h>
#include "interface/NanoReader.h"
#include "interface/utils.C"
#include "interface/ReRunFHJetSelection.h"

void ScanCutNMinus1(
    // TString inputFile1 = "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_NLO_2016_Hadded_2/GluGluToHHTo2G4Q_node_cHHH1_2016.root",
    TString inputFile1 = "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_NLO_2016_Hadded_2/GluGluToHHTo2G4Q_node_cHHH1_2016.root",
    TString OutPutPath = "./",
    TString PrefixOutPutRootFileName = "",
    bool ifDNN = false,
    TString SearchString = "HHWWggTag_1",
    TString ReplaceString = "HHWWggTag_FH_1"
    )
{
    clock_t tStart = clock();

//         int bTagDisToCheck = -1;
//             bTagDisToCheck = 5;
//         TString bDiscriminator_mini_pfDeepFlavor = "";
//         for (int i = 0; i < bTagDisToCheck; ++i)
//         {
//             TString CountJet; CountJet.Form("%i",i);
//             TString probb = "*nr.goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_probb";
//             TString probbb = "*nr.goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_probbb";
//             TString problepb = "*nr.goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_problepb";

//             TString bDisCut = " ("+probb + " + " + probbb + " + " + problepb + " < 0.7221) ";
//             if (i==0) bDiscriminator_mini_pfDeepFlavor = bDisCut;
//             else bDiscriminator_mini_pfDeepFlavor += " && \n" + bDisCut;
//         }
//         std::cout << bDiscriminator_mini_pfDeepFlavor << std::endl;

// std::cout << "\n\n=========\n\n" << std::endl;
//             bTagDisToCheck = 10;
//          bDiscriminator_mini_pfDeepFlavor = "";
//         for (int i = 0; i < bTagDisToCheck; ++i)
//         {
//             TString CountJet; CountJet.Form("%i",i);
//             TString probb = "*nr.goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_probb";
//             TString probbb = "*nr.goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_probbb";
//             TString problepb = "*nr.goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_problepb";

//             TString bDisCut = " ("+probb + " + " + probbb + " + " + problepb + " < 0.7221) ";
//             if (i==0) bDiscriminator_mini_pfDeepFlavor = bDisCut;
//             else bDiscriminator_mini_pfDeepFlavor += " && \n" + bDisCut;
//         }
//         std::cout << bDiscriminator_mini_pfDeepFlavor << std::endl;

    TFile *OldRootFile = new TFile(inputFile1,"READ");
    if (OldRootFile->IsZombie()) {
        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }
    std::cout << "Reading file ==> " << inputFile1 << std::endl;

    std::vector<TString> Vec_ListOfAllTrees;
    getallTrees(OldRootFile,"/",Vec_ListOfAllTrees, "Tag_1");

    TString OldTreeName = Vec_ListOfAllTrees[0];

    TTree *OldTree = (TTree*)OldRootFile->Get(OldTreeName);
    NanoReader nr = NanoReader(OldTree);

    std::cout << "Reading Tree: " << OldTreeName << std::endl;
    std::cout << "\tTotal entries before selection: " << OldTree->GetEntries() << std::endl;

    TH1F *h1 = new TH1F("h1",OldTreeName,25,0,25);
    h1->GetXaxis()->SetBinLabel(1,"Total Event");
    h1->GetXaxis()->SetBinLabel(2,"passPhotonSels");
    h1->GetXaxis()->SetBinLabel(3,"dipho_MVA");
    h1->GetXaxis()->SetBinLabel(4,"dipho_pT");
    h1->GetXaxis()->SetBinLabel(5,"bDis");
    for (int i = 0; i < 20; ++i)
    {
        TString CutValue; CutValue.Form("%.2f",(i+1)*0.05);
        h1->GetXaxis()->SetBinLabel(i+5,"dipho_MVA>"+CutValue);
    }
    // for (int i = 0; i < 20; ++i)
    // {
    //     TString CutValue; CutValue.Form("%.2f",(i*10.)+50.0);
    //     h1->GetXaxis()->SetBinLabel(i+23,"dipho_pT>"+CutValue);
    // }
    // for (int i = 0; i < 20; ++i)
    // {
    //     TString CutValue; CutValue.Form("%.2f",(i+1)*0.05);
    //     h1->GetXaxis()->SetBinLabel(i+43,"bDis>"+CutValue);
    // }        
    // h1->GetXaxis()->SetBinLabel(13,"Any b-jet");
    // h1->GetXaxis()->SetBinLabel(14,"FH Jet Sel");

    TH1F *h1_weight = new TH1F("h1_weight",OldTreeName+"_weight",25,0,25);
    h1_weight->GetXaxis()->SetBinLabel(1,"Total Event");
    h1_weight->GetXaxis()->SetBinLabel(2,"passPhotonSels");
    h1_weight->GetXaxis()->SetBinLabel(3,"dipho_MVA");
    h1_weight->GetXaxis()->SetBinLabel(4,"dipho_pT");
    h1_weight->GetXaxis()->SetBinLabel(5,"bDis");
    // for (int i = 0; i < 20; ++i)
    // {
    //     TString CutValue; CutValue.Form("%.2f",(i+1)*0.05);
    //     h1_weight->GetXaxis()->SetBinLabel(i+5,"dipho_MVA>"+CutValue);
    // } 
    for (int i = 0; i < 20; ++i)
    {
        TString CutValue; CutValue.Form("%.2f",(i*10.)+50.0);
        h1_weight->GetXaxis()->SetBinLabel(i+23,"dipho_pT>"+CutValue);
    }   
    // for (int i = 0; i < 20; ++i)
    // {
    //     TString CutValue; CutValue.Form("%.2f",(i+1)*0.05);
    //     h1_weight->GetXaxis()->SetBinLabel(i+43,"bDis>"+CutValue);
    // }             
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

    for (int i = 0; i < OldTree->GetEntries(); ++i)
    {
        nr.GetEntry(i);
        if (i%10000==0) std::cout <<"event " << i << std::endl;

        h1->Fill(0.0);
        h1_weight->Fill(0.0,*nr.weight);

        if (*nr.passPhotonSels != 1) continue;
        h1->Fill(1);
        h1_weight->Fill(1,*nr.weight);

        if (*nr.dipho_MVA < 0.9) continue;
        h1->Fill(2);
        h1_weight->Fill(2,*nr.weight);        
        // for (int i = 0; i < 20; ++i)
        // {
        //     if ( *nr.dipho_MVA > (i+1)*0.05)
        //     {
        //         h1->Fill(i+5);
        //         h1_weight->Fill(i+5,*nr.weight);                
        //     }
        // }

        // if (*nr.HGGCandidate_pt < 170) continue;
        // h1->Fill(3);
        // h1_weight->Fill(3,*nr.weight);           
        for (int i = 0; i < 20; ++i)
        {
            if ( *nr.HGGCandidate_pt > (i*10)+50)
            {
                h1->Fill(i+5);
                h1_weight->Fill(i+5,*nr.weight);                
            }

        }        

        if (
            (*nr.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < 0.7221)  && 
            (*nr.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < 0.7221)  && 
            (*nr.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < 0.7221)  && 
            (*nr.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < 0.7221)  && 
            (*nr.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < 0.7221) 
            ) continue;
        h1->Fill(4);
        h1_weight->Fill(4,*nr.weight);   
//         for (int i = 0; i < 20; ++i)
//         {
//             // if ( *nr.dipho_MVA > (i+1)*0.05)
//                 if (
//  (*nr.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < (i+1)*0.05)  && 
//  (*nr.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < (i+1)*0.05)  && 
//  (*nr.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < (i+1)*0.05)  && 
//  (*nr.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < (i+1)*0.05)  && 
//  (*nr.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb + *nr.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb + *nr.goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb < (i+1)*0.05) 
// )
//             {
//                 h1->Fill(i+42);
//                 h1_weight->Fill(i+42,*nr.weight);                
//             }

//         }


    }
    // h1->Print("all");
    // h1_weight->Print("all");
    gStyle->SetOptStat(0);
    TFile *f1 = new TFile();
    TString NewRootFileName = GetLastString(string(inputFile1), "/");
    TString OutPutRootFileName = OutPutPath+"/"+PrefixOutPutRootFileName+NewRootFileName;
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    TCanvas * c1 = new TCanvas("c1","c1",8000, 4000);
    c1->SetBottomMargin(1400);
    h1->Draw("TEXThist");
    c1->SaveAs("hist_"+OutPutRootFileName.ReplaceAll("//","").ReplaceAll(".root","").ReplaceAll("_.","")+".pdf");
    h1_weight->Draw("TEXThist");
    c1->SaveAs("hist_weight_"+OutPutRootFileName.ReplaceAll("//","").ReplaceAll(".root","").ReplaceAll("_.","")+".pdf");
    h1->Write();
    h1_weight->Write();
    newfile->Close();

    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}    
