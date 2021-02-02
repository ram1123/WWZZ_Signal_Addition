/*
 * =====================================================================================
 *
 *       Filename:  ReNameTree.C
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/02/21 15:14:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */
#include <chrono>
#include <time.h>

TString GetTreeName(TFile *f, TString (&RootFileDirStructure)[3], bool DEBUG=0);
TString GetTreeName(TFile *f, std::vector<TString> &RootFileDirStructure, std::vector<TString> &ListOfAllTrees, bool DEBUG=0);
TString GetLastString(string s, string delimiter, bool DEBUG=0);


void ReNameTree( bool isMC = true,
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          TString OutPutRootFileName = "",
                          TString OutPutPath = "/tmp/rasharma/",
                          TString PrefixOutPutRootFileName = "Test_ReName_",
                          bool WithSyst = true,
                          TString ToReplace = "HHWWggTag_1",
                          TString ReplaceWith = "HHWWggTag_FH_1"
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
    if (OutPutRootFileName == "") {
        OutPutRootFileName = OutPutPath+"/"+PrefixOutPutRootFileName+NewRootFileName;
    } else {
        OutPutRootFileName = OutPutPath+"/"+OutPutRootFileName;
    }
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    newfile->mkdir(DirectoryName);
    newfile->cd(DirectoryName);

    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        if (!WithSyst) {
          if (TreesCount>=2) break;
        }
        std::cout << "Reading Tree: " << TreesCount << "/" << Size_Vec_ListOfAllTrees << ": " << *OldTreeName << std::endl;

        TTree *OldTree = (TTree*)OldRootFile->Get(DirectoryName+"/"+TString(*OldTreeName));

        // Clone the old tree
        auto newtree = OldTree->CloneTree();

        newtree->SetName((*OldTreeName).ReplaceAll(ToReplace, ReplaceWith));

        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

        delete OldTree;
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    newfile->Write();
    newfile->Close();
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}



/**
 * @brief      This function takes a input root file and returns the directory
 *             structure along with its tree name.
 *
 * @param      f                     Input root file
 * @param      RootFileDirStructure  This has a size of three where the first
 *                                   two elements contains the two directory
 *                                   name and the third element contains the
 *                                   tree name.
 * @param[in]  DEBUG                 it can take values 0 or 1. If its 1 then
 *                                   it prints several couts which helps us in
 *                                   debug the code.
 *
 * @return     It returns the full directory structure along with the tree name.
 */
TString GetTreeName(TFile *f, TString (&RootFileDirStructure)[3], bool DEBUG) {
    TString treeName = "";

    TIter next(f->GetListOfKeys());
    TKey *key;
    while ( (key = (TKey*)next())) {
        if (DEBUG) std::cout << "key name: " << key->GetName() << std::endl;
        if (string(key->GetName()).find("Tag_1") != std::string::npos)
        {
            if (DEBUG) std::cout << "Found key name: " << key->GetName() << std::endl;
            RootFileDirStructure[0] = key->GetName();
            treeName += key->GetName();
            break;
        }
        if (key->IsFolder()) {
            f->cd(key->GetName());
            treeName += key->GetName();
            RootFileDirStructure[0] = TString(key->GetName());
            TDirectory *subdir = gDirectory;
            TIter next(subdir->GetListOfKeys());
            TKey *key2;
            while ( (key2 = (TKey*)next())) {
                if (DEBUG) std::cout << "key2 name: " << key2->GetName() << std::endl;
                if (string(key2->GetName()).find("Tag_1") != std::string::npos)
                {
                    if (DEBUG) std::cout << "Found key2 name: " << key2->GetName() << std::endl;
                    RootFileDirStructure[1] = key2->GetName();
                    treeName += "/";
                    treeName += key2->GetName();
                    break;
                }
                if (key->IsFolder()){
                    treeName += "/";
                    treeName += key2->GetName();
                    RootFileDirStructure[1] = key2->GetName();
                    subdir->cd(key2->GetName());
                    TDirectory *subdir = gDirectory;
                    TIter next(subdir->GetListOfKeys());
                    TKey *key3;
                    while ( (key3 = (TKey*)next())) {
                        if (DEBUG) std::cout << "key3 name: " << key3->GetName() << std::endl;
                        if (string(key3->GetName()).find("Tag_1") != std::string::npos)
                        {
                            if (DEBUG) std::cout << "Found key3 name: " << key3->GetName() << std::endl;
                            RootFileDirStructure[2] = key3->GetName();
                            treeName += "/";
                            treeName += key3->GetName();
                            break;
                        }
                    }
                }
            }
        }
    }
    return treeName;
}


TString GetTreeName(TFile *f, std::vector<TString> &RootFileDirStructure, std::vector<TString> &ListOfAllTrees, bool DEBUG)
{
    TString DirName = "";

    TIter next(f->GetListOfKeys());
    TKey *key;
    while ( (key = (TKey*)next())) {
        if (DEBUG) std::cout << "key name: " << key->GetName() << "\tClass: " << key->GetClassName() << std::endl;
        // if (key->GetClassName() == "TDirectoryFile") std::cout << "Ram" << std::endl;
        // if (strstr(key->GetClassName(),"TDirectoryFile"))
        // {
        //     RootFileDirStructure.push_back(TString(key->GetName()));
        // }
        if (key->IsFolder()) {
            f->cd(key->GetName());
            DirName += key->GetName();
            RootFileDirStructure.push_back(TString(key->GetName()));
            TDirectory *subdir = gDirectory;
            TIter next(subdir->GetListOfKeys());
            TKey *key2;
            while ( (key2 = (TKey*)next())) {
                if (DEBUG) std::cout << "key2 name: " << key2->GetName() << "\tClass: " << key2->GetClassName() << std::endl;
                if (key->IsFolder()){
                    DirName += "/";
                    DirName += key2->GetName();
                    RootFileDirStructure.push_back(TString(key2->GetName()));
                    subdir->cd(key2->GetName());
                    TDirectory *subdir = gDirectory;
                    TIter next(subdir->GetListOfKeys());
                    TKey *key3;
                    while ( (key3 = (TKey*)next())) {
                        if (string(key3->GetName()).find("Tag_1") != std::string::npos)
                        {
                            if (DEBUG) std::cout << "key3 name: " << key3->GetName() << "\tClass: " << key3->GetClassName() << std::endl;
                            // RootFileDirStructure.push_back(TString(key3->GetName()));
                            // DirName += "/";
                            // DirName += key3->GetName();
                            ListOfAllTrees.push_back(TString(key3->GetName()));
                        }
                    }
                }
            }
        }
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

