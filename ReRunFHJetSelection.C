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


TString GetTreeName(TFile *f, TString (&RootFileDirStructure)[3], bool DEBUG=0);

void ReRunFHJetSelection() 
{
    auto c1 = new TCanvas("c1");

    TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root";

    TFile *OldRootFile = new TFile(inputFile1);

    if (OldRootFile->IsZombie()) {
        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }

    std::cout << "Reading file ==> " << inputFile1 << std::endl;

    TString RootFileDirStructure[3];

    TString OldTreeName = GetTreeName(OldRootFile, RootFileDirStructure);

    std::cout << "Tree name: " << OldTreeName << std::endl;

    TTree *OldTree;
    OldRootFile->GetObject(OldTreeName, OldTree);

    // Deactivate all branches
    OldTree->SetBranchStatus("*", 1);

    // Create a new file + a clone of old tree in new file
    TFile newfile("small.root", "recreate");
    newfile.mkdir(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);
    newfile.cd(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);
    auto newtree = OldTree->CloneTree();

    newtree->Print();
    newfile.Write();
}


//===========================================================================

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
        if (key->IsFolder()) {
            f->cd(key->GetName());
            treeName += key->GetName();
            RootFileDirStructure[0] = TString(key->GetName());
            TDirectory *subdir = gDirectory;
            TIter next(subdir->GetListOfKeys());
            TKey *key2;
            while ( (key2 = (TKey*)next())) {
                if (DEBUG) std::cout << "key2 name: " << key2->GetName() << std::endl;
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
                        }
                    }
                }
            }            
        }
    }
    return treeName;    
}
