/*
 * =====================================================================================
 *
 *       Filename:  ReStructureTTree.C
 *
 *    Description:  Restructure hadded ZZ Root file from "GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1"
 *                  to "tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1".
 *
 *                  The hadded ZZ root file we get from command:
 *
 *                  ```bash
 *                  rooteventselector -s "rand()/2147483647 <= 0.12269939" nodecHHH1_GluGluToHHTo2G2ZTo2G4Q_1.root:tagsDumper/trees/GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1 nodecHHH1_GluGluToHHTo2G2ZTo2G4Q_trimmed.root
 *                  ```
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
#include "interface/flashgg_ZZMC.h"

TString GetTreeName(TFile *f, std::vector<TString> &RootFileDirStructure, std::vector<TString> &ListOfAllTrees, bool DEBUG=0);
TString GetLastString(string s, string delimiter, bool DEBUG=0);


void ReStructureTTree()
{
    TString inputFile1 = "/tmp/rasharma/RemovedDuplicates_GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_2016_Trimmed.root";
    TString PrefixOutPutRootFileName = "TEMP_";

    TFile *OldRootFile = new TFile(inputFile1);
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

    DirectoryName = "tagsDumper/trees";

    TString NewRootFileName = GetLastString(string(inputFile1), "/");
    TString OutPutRootFileName = PrefixOutPutRootFileName+NewRootFileName;
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    // TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE");
    newfile->mkdir(DirectoryName);
    newfile->cd(DirectoryName);


    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        std::cout << "Reading Tree: " << *OldTreeName << std::endl;

        TTree *OldTree = (TTree*)OldRootFile->Get(TString(*OldTreeName));

        flashgg_ZZMC flashggReader(OldTree);

        // Clone the old tree
        auto NewTree = OldTree->CloneTree();
        delete OldTree;
    }
    newfile->Write();
    newfile->Close();
}

TString GetTreeName(TFile *f, std::vector<TString> &RootFileDirStructure, std::vector<TString> &ListOfAllTrees, bool DEBUG)
{
    TString DirName = "";

    TIter next(f->GetListOfKeys());
    TKey *key;
    while ( (key = (TKey*)next())) {
        if (DEBUG) std::cout << "key name: " << key->GetName() << "\tClass: " << key->GetClassName() << std::endl;
        ListOfAllTrees.push_back(TString(key->GetName()));
    }
    return DirName;
}

/**
 * @brief      Get the root file name. Its the last string when
 *             we split is using "/" deliminator.
 *
 * @param[in]  s          Input string
 * @param[in]  delimiter  The delimiter to be used for seperation.
 * @param[in]  DEBUG      The debug
 *
 * @return     It returns the root file name.
 */
TString GetLastString(string s, string delimiter, bool DEBUG)
{
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if (DEBUG) std::cout << "\t==> " << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << "[INFO] ReRunFHJetSelection.h#186: Last string: " << s << std::endl;

    return TString(s);
}

