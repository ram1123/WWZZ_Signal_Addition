/*
 * =====================================================================================
 *
 *       Filename:  AppendEFTNodeNumber.C
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

// #include "interface/output.h"
#include "interface/node_num.h"

#include <chrono>
#include "progressbar.hpp"
#include <time.h>

void AppendEFTNodeNumber( /* bool isMC = true, */
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          int NodeNumber = 1,
                          TString PrefixOutPutRootFileName = "",
                          TString OutPutPath = "./", // Signal, Backgrounds, Data
                          bool WithSyst = false,
                          bool ifDNN = false,
                          bool ifDirExists = true
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
    TString DirectoryName = "";
    if (ifDirExists)
        DirectoryName = GetTreeName(OldRootFile, Vec_RootFileDirStructure, Vec_ListOfAllTrees, 1);
    else
        DirectoryName = GetTreeName(OldRootFile, Vec_ListOfAllTrees, 1);
    std::cout << "DirectoryName: " << DirectoryName << std::endl;
    int Size_Vec_ListOfAllTrees = -1;
    if (WithSyst) Size_Vec_ListOfAllTrees = Vec_ListOfAllTrees.size();
    else Size_Vec_ListOfAllTrees = 1;
    std::cout << "Number of Trees: " << Size_Vec_ListOfAllTrees << std::endl;
    std::cout << "Name of first Trees: " << Vec_ListOfAllTrees[0] << std::endl;

    TString NewRootFileName = GetLastString(string(inputFile1), "/");
    TString OutPutRootFileName = OutPutPath+"/"+PrefixOutPutRootFileName+"_"+NewRootFileName;
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    if (ifDirExists) newfile->mkdir(DirectoryName);

    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        std::cout << "Reading Tree: " << *OldTreeName << std::endl;
        if (!WithSyst) {
          if (TreesCount>=2) break;
        }

        TTree *OldTree = NULL;

        if (ifDirExists) OldTree = (TTree*)OldRootFile->Get(DirectoryName+"/"+TString(*OldTreeName));
        else OldTree = (TTree*)OldRootFile->Get(TString(*OldTreeName));

        // if (isMC) {
        flashgg_MC flashggReader(OldTree);
        // } else {
        // flashgg_Data flashggReader(OldTree);
        // }

        if (ifDirExists) newfile->cd(DirectoryName);

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

            // outputVars.weightnew = flashggReader.weight*(1.027);

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

            if (NodeNumber == 1)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_1;
                outputVars.Node_Number  = 1.0;
            }
            if (NodeNumber == 2)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_2;
                outputVars.Node_Number  = 2.0;
            }
            if (NodeNumber == 3)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_3;
                outputVars.Node_Number  = 3.0;
            }
            if (NodeNumber == 4)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_4;
                outputVars.Node_Number  = 4.0;
            }
            if (NodeNumber == 5)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_5;
                outputVars.Node_Number  = 5.0;
            }
            if (NodeNumber == 6)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_6;
                outputVars.Node_Number  = 6.0;
            }
            if (NodeNumber == 7)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_7;
                outputVars.Node_Number  = 7.0;
            }
            if (NodeNumber == 8)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_8;
                outputVars.Node_Number  = 8.0;
            }
            if (NodeNumber == 9)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_9;
                outputVars.Node_Number  = 9.0;
            }
            if (NodeNumber == 10)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_10;
                outputVars.Node_Number  = 10.0;
            }
            if (NodeNumber == 11)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_11;
                outputVars.Node_Number  = 11.0;
            }
            if (NodeNumber == 12)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_12;
                outputVars.Node_Number  = 12.0;
            }
            if (NodeNumber == 13)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_8a;
                outputVars.Node_Number  = 13.0;
            }
            if (NodeNumber == 14)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_1b;
                outputVars.Node_Number  = 14.0;
            }
            if (NodeNumber == 15)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_2b;
                outputVars.Node_Number  = 15.0;
            }
            if (NodeNumber == 16)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_3b;
                outputVars.Node_Number  = 16.0;
            }
            if (NodeNumber == 17)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_4b;
                outputVars.Node_Number  = 17.0;
            }
            if (NodeNumber == 18)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_5b;
                outputVars.Node_Number  = 18.0;
            }
            if (NodeNumber == 19)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_6b;
                outputVars.Node_Number  = 19.0;
            }
            if (NodeNumber == 20)
            {
                outputVars.NewWeight    = flashggReader.weight * flashggReader.weight_NLO_7b;
                outputVars.Node_Number  = 20.0;
            }

            if (NodeNumber == 51)   // For backgrounds
            {
                outputVars.NewWeight    = flashggReader.weight;
                outputVars.Node_Number  = 1 + ( std::rand() % ( 20 ) );
            }

            newtree->Fill();
        }
        newtree->AutoSave();
        std::cout << "\n" << std::endl;

        newtree->Write("",TObject::kOverwrite);
        newfile->Write();
        delete OldTree;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    newfile->Close();
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
