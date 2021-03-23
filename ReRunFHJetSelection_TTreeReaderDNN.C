/*
 * =====================================================================================
 *
 *       Filename:  ReRunFHJetSelection_TTreeReader.C
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

void ReRunFHJetSelection_TTreeReaderDNN( 
    TString inputFile1 = "/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHWW_NLO_2016_Hadded_2/GluGluToHHTo2G4Q_node_cHHH0_2016.root",
    TString OutPutPath = "./",
    TString PrefixOutPutRootFileName = "",
    bool ifDNN = false,
    TString SearchString = "HHWWggTag_1",
    TString ReplaceString = "HHWWggTag_FH_1"    
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
    // OldRootFile->Close();

    int Size_Vec_ListOfAllTrees = Vec_ListOfAllTrees.size();
    std::cout << "Number of Trees: " << Size_Vec_ListOfAllTrees << std::endl;

    vector<string> fields;
    Tokenize(std::string(Vec_ListOfAllTrees[0]),fields, "/");
    TString DirectoryName = "";

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
    newfile->cd(DirectoryName);
    // newfile->Close();

    int TreesCount = 0;

    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {   
        TreesCount++; 
        // Save only nominal branch for DNN studies
        if (ifDNN == true && TreesCount>1) continue;
        TTree *OldTree = (TTree*)OldRootFile->Get(*OldTreeName);
        std::cout << "Reading Tree: (" << TreesCount << "/"<< Size_Vec_ListOfAllTrees << "): " << *OldTreeName << std::endl;
        std::cout << "\tTotal entries before selection: " << OldTree->GetEntries() << std::endl;

        TString N_goodJets = "N_goodJets >= 4";
        TString DiPhotonCut = "HGGCandidate_pt > 140";
        TString passPhotonSels = "passPhotonSels == 1";
        TString dipho_MVA = "dipho_MVA > 0.9";
        TString bDiscriminator_mini_pfDeepFlavor =  "";

        // int bTagDisToCheck = (TString(*OldTreeName).Contains("sigma")) ? bTagDisToCheck = 5 : bTagDisToCheck = 10;

        int bTagDisToCheck = -1;
        if (TString(*OldTreeName).Contains("sigma"))  
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
            if (i==0) bDiscriminator_mini_pfDeepFlavor = bDisCut;
            else bDiscriminator_mini_pfDeepFlavor += " && " + bDisCut;
        }
        // std::cout << bDiscriminator_mini_pfDeepFlavor << std::endl;
        TString CutsToApply = N_goodJets + " && " + DiPhotonCut + " && " + passPhotonSels + " && " + dipho_MVA + " && " + bDiscriminator_mini_pfDeepFlavor;

        // Clone old Tree
        //if (ifDNN = true)
            auto NewTree = OldTree->CopyTree("");
        //else
        //    auto NewTree = OldTree->CopyTree(CutsToApply);
        // Uncomment and set the search and replace string to appropriate values
        // NewTree->SetName(((TString)OldTree->GetName()).ReplaceAll(SearchString, ReplaceString));
        std::cout << "\tTotal entries after selection: " << NewTree->GetEntries() << std::endl;
        newfile->Write();
        delete OldTree;
        delete NewTree;
    }
    newfile->Close();
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
