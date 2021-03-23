/*
 * =====================================================================================
 *
 *       Filename:  ReRunFHJetSelection_TTreeReader_1_v1.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/21 16:22:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */

#include <time.h>
#include "interface/utils.C"
#include "interface/ReRunFHJetSelection.h"

void ReRunFHJetSelection_TTreeReader_1_v1( 
    TString inputFile1 = "",
    TString OutPutPath = "./",
    TString DirectoryName = "",
    TString OldTreeName = "",
    TString NewRootFileName = ""
    )
{    
    clock_t tStart = clock();

    TFile *OldRootFile = new TFile(inputFile1,"READ");
    if (OldRootFile->IsZombie()) {
        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }
    std::cout << "Reading file ==> " << inputFile1 << std::endl;
    TString OutPutRootFileName = OutPutPath+"/"+NewRootFileName;
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    std::cout << "DirectoryName: " << DirectoryName << std::endl;
    newfile->mkdir(DirectoryName);
    newfile->cd(DirectoryName);
    // newfile->Close();


    // for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    // {   
        std::cout << "Reading Tree: " << OldTreeName << std::endl;
        TTree *OldTree = (TTree*)OldRootFile->Get(DirectoryName+"/"+OldTreeName);
        std::cout << "Total entries before selection: " << OldTree->GetEntries() << std::endl;

        // Create a new file
        // TFile *newfile = new TFile("outNameFile.root","recreate");
        // newfile->mkdir(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);
        // newfile->cd(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);

        TString DiPhotonCut = "HGGCandidate_pt < 140";
        TString passPhotonSels = "passPhotonSels == 1";
        TString dipho_MVA = "dipho_MVA > 0.9";
        TString bDis =  "";

        int bTagDisToCheck = -1;
        if (TString(OldTreeName).Contains("sigma"))  
            bTagDisToCheck = 5;
        else
            bTagDisToCheck = 10;
        for (int i = 0; i < bTagDisToCheck; ++i)
        {
            TString CountJet; CountJet.Form("%i",i);
            TString probb = "goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_probb";
            TString probbb = "goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_probbb";
            TString problepb = "goodJets_"+CountJet+"_bDiscriminator_mini_pfDeepFlavourJetTags_problepb";

            TString bDisCut = " ("+probb + " + " + probbb + " + " + problepb + " < 0.7221) ";
            if (i==0) bDis = bDisCut;
            else bDis += " && " + bDisCut;
        }

        // std::cout << bDis << std::endl;

        TString CutsToApply = DiPhotonCut + " && " + passPhotonSels + " && " + dipho_MVA + " && " + bDis;

        // Clone old Tree
        auto NewTree = OldTree->CopyTree(CutsToApply);

        std::cout << "Total entries after selection: " << NewTree->GetEntries() << std::endl;
        newfile->Write();
    // }
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
