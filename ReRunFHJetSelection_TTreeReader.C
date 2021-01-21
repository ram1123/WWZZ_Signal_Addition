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


TString GetTreeName(TFile *f, TString (&RootFileDirStructure)[3], bool DEBUG=0);

void ReRunFHJetSelection_TTreeReader() 
{
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

    TTree *OldTree = (TTree*)OldRootFile->Get(OldTreeName);
    TTreeReader newreader( OldTreeName, OldRootFile );

   TTreeReaderValue<Float_t> N_goodJets = {newreader, "N_goodJets"};
   TTreeReaderValue<Float_t> goodJets_0_E = {newreader, "goodJets_0_E"};
   TTreeReaderValue<Float_t> goodJets_1_E = {newreader, "goodJets_1_E"};
   TTreeReaderValue<Float_t> goodJets_2_E = {newreader, "goodJets_2_E"};
   TTreeReaderValue<Float_t> goodJets_3_E = {newreader, "goodJets_3_E"};
   TTreeReaderValue<Float_t> goodJets_4_E = {newreader, "goodJets_4_E"};
   TTreeReaderValue<Float_t> goodJets_0_pt = {newreader, "goodJets_0_pt"};
   TTreeReaderValue<Float_t> goodJets_1_pt = {newreader, "goodJets_1_pt"};
   TTreeReaderValue<Float_t> goodJets_2_pt = {newreader, "goodJets_2_pt"};
   TTreeReaderValue<Float_t> goodJets_3_pt = {newreader, "goodJets_3_pt"};
   TTreeReaderValue<Float_t> goodJets_4_pt = {newreader, "goodJets_4_pt"};
   TTreeReaderValue<Float_t> goodJets_0_px = {newreader, "goodJets_0_px"};
   TTreeReaderValue<Float_t> goodJets_1_px = {newreader, "goodJets_1_px"};
   TTreeReaderValue<Float_t> goodJets_2_px = {newreader, "goodJets_2_px"};
   TTreeReaderValue<Float_t> goodJets_3_px = {newreader, "goodJets_3_px"};
   TTreeReaderValue<Float_t> goodJets_4_px = {newreader, "goodJets_4_px"};
   TTreeReaderValue<Float_t> goodJets_0_py = {newreader, "goodJets_0_py"};
   TTreeReaderValue<Float_t> goodJets_1_py = {newreader, "goodJets_1_py"};
   TTreeReaderValue<Float_t> goodJets_2_py = {newreader, "goodJets_2_py"};
   TTreeReaderValue<Float_t> goodJets_3_py = {newreader, "goodJets_3_py"};
   TTreeReaderValue<Float_t> goodJets_4_py = {newreader, "goodJets_4_py"};
   TTreeReaderValue<Float_t> goodJets_0_pz = {newreader, "goodJets_0_pz"};
   TTreeReaderValue<Float_t> goodJets_1_pz = {newreader, "goodJets_1_pz"};
   TTreeReaderValue<Float_t> goodJets_2_pz = {newreader, "goodJets_2_pz"};
   TTreeReaderValue<Float_t> goodJets_3_pz = {newreader, "goodJets_3_pz"};
   TTreeReaderValue<Float_t> goodJets_4_pz = {newreader, "goodJets_4_pz"};
   TTreeReaderValue<Float_t> goodJets_0_eta = {newreader, "goodJets_0_eta"};
   TTreeReaderValue<Float_t> goodJets_1_eta = {newreader, "goodJets_1_eta"};
   TTreeReaderValue<Float_t> goodJets_2_eta = {newreader, "goodJets_2_eta"};
   TTreeReaderValue<Float_t> goodJets_3_eta = {newreader, "goodJets_3_eta"};
   TTreeReaderValue<Float_t> goodJets_4_eta = {newreader, "goodJets_4_eta"};
   TTreeReaderValue<Float_t> goodJets_0_phi = {newreader, "goodJets_0_phi"};
   TTreeReaderValue<Float_t> goodJets_1_phi = {newreader, "goodJets_1_phi"};
   TTreeReaderValue<Float_t> goodJets_2_phi = {newreader, "goodJets_2_phi"};
   TTreeReaderValue<Float_t> goodJets_3_phi = {newreader, "goodJets_3_phi"};
   TTreeReaderValue<Float_t> goodJets_4_phi = {newreader, "goodJets_4_phi"};
   TTreeReaderValue<Float_t> goodJets_0_PassLooseJetPUID = {newreader, "goodJets_0_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_0_PassMediumJetPUID = {newreader, "goodJets_0_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_0_PassTightJetPUID = {newreader, "goodJets_0_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_1_PassLooseJetPUID = {newreader, "goodJets_1_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_1_PassMediumJetPUID = {newreader, "goodJets_1_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_1_PassTightJetPUID = {newreader, "goodJets_1_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_2_PassLooseJetPUID = {newreader, "goodJets_2_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_2_PassMediumJetPUID = {newreader, "goodJets_2_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_2_PassTightJetPUID = {newreader, "goodJets_2_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_3_PassLooseJetPUID = {newreader, "goodJets_3_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_3_PassMediumJetPUID = {newreader, "goodJets_3_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_3_PassTightJetPUID = {newreader, "goodJets_3_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_4_PassLooseJetPUID = {newreader, "goodJets_4_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_4_PassMediumJetPUID = {newreader, "goodJets_4_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_4_PassTightJetPUID = {newreader, "goodJets_4_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_5_PassLooseJetPUID = {newreader, "goodJets_5_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_5_PassMediumJetPUID = {newreader, "goodJets_5_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_5_PassTightJetPUID = {newreader, "goodJets_5_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_6_PassLooseJetPUID = {newreader, "goodJets_6_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_6_PassMediumJetPUID = {newreader, "goodJets_6_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_6_PassTightJetPUID = {newreader, "goodJets_6_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_7_PassLooseJetPUID = {newreader, "goodJets_7_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_7_PassMediumJetPUID = {newreader, "goodJets_7_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_7_PassTightJetPUID = {newreader, "goodJets_7_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_8_PassLooseJetPUID = {newreader, "goodJets_8_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_8_PassMediumJetPUID = {newreader, "goodJets_8_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_8_PassTightJetPUID = {newreader, "goodJets_8_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_9_PassLooseJetPUID = {newreader, "goodJets_9_PassLooseJetPUID"};
   TTreeReaderValue<Float_t> goodJets_9_PassMediumJetPUID = {newreader, "goodJets_9_PassMediumJetPUID"};
   TTreeReaderValue<Float_t> goodJets_9_PassTightJetPUID = {newreader, "goodJets_9_PassTightJetPUID"};
   TTreeReaderValue<Float_t> goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb = {newreader, "goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_0_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_1_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_2_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_3_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_4_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_5_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_6_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_7_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_8_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb = {newreader, "goodJets_9_bDiscriminator_pfDeepCSVJetTags_probb"};
   TTreeReaderValue<Float_t> goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb = {newreader, "goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_0_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_1_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_2_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_3_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_4_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_5_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_6_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_7_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_8_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb = {newreader, "goodJets_9_bDiscriminator_pfDeepCSVJetTags_probbb"};
   TTreeReaderValue<Float_t> goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};
   TTreeReaderValue<Float_t> goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb = {newreader, "goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb"};

    // Create a new file
    TFile *newfile = new TFile("outNameFile.root","recreate");
    newfile->mkdir(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);
    newfile->cd(RootFileDirStructure[0]+"/"+RootFileDirStructure[1]);

    // Clone old Tree
    auto newtree = OldTree->CloneTree();
    // auto newtree = OldTree->CloneTree(0);
    // newtree->SetName(RootFileDirStructure[2]);

    // newtree->SetBranchStatus('*',1);
    // TTreeReaderValue<Float_t> ramkrishna = {newreader, "ramkrishna"};
    double ramkrishna;
    newtree->Branch("ramkrishna", &ramkrishna, "ramkrishna/F");

    while(newreader.Next()) {
        // std::cout << "N_goodJets = " << *N_goodJets << std::endl;
        ramkrishna = *N_goodJets;
        newtree->Fill();
    }

    newfile->Write();
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

