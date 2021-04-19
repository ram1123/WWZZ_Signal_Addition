/*
 * =====================================================================================
 *
 *       Filename:  GetEntriesForAllTree.C
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
// #include "interface/AngularVariables.cpp"
#include "interface/ReRunFHJetSelection.h"

// #include "interface/flashgg_Data.h"
// #include "interface/flashgg_MC.h"

// #include "interface/output.h"

#include <chrono>
#include "progressbar.hpp"
#include <time.h>

void GetEntriesForAllTree( /* bool isMC = true, */
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          TString inputFile2 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root"
                                                // Signal, Backgrounds, Data
                        )
{
    clock_t tStart = clock();
    TFile *OldRootFile = new TFile(inputFile1,"READ");
    TFile *OldRootFile2 = new TFile(inputFile2,"READ");

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

    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        // std::cout << "Reading Tree: " << *OldTreeName << std::endl;

        TTree *OldTree = (TTree*)OldRootFile->Get(DirectoryName+"/"+TString(*OldTreeName));
        TTree *OldTree2 = (TTree*)OldRootFile2->Get(DirectoryName+"/"+TString(*OldTreeName));

        // if (isMC) {
        // flashgg_MC flashggReader(OldTree);
        // } else {
        // flashgg_Data flashggReader(OldTree);
        // }

        // newfile->cd(DirectoryName);

        // Clone the old tree
        // auto newtree = OldTree->CloneTree(0);
        // output outputVars = output(newtree);

        Long64_t nentries = OldTree->GetEntries();
        Long64_t nentries2 = OldTree2->GetEntries();
        std::cout << "Files: " << TreesCount << "/" << Size_Vec_ListOfAllTrees<<  "\tnentries = " << nentries << "\t" << nentries2 << "\t" << nentries-nentries2 <<"\t"<<*OldTreeName << std::endl;
        // printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

        // std::cout << "\n" << std::endl;

        delete OldTree;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
