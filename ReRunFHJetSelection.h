/*
 * =====================================================================================
 *
 *       Filename:  ReRunFHJetSelection.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/22/21 00:25:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */


TString GetTreeName(TFile *f, TString (&RootFileDirStructure)[3], bool DEBUG=0);
void GetFHminWHJets(bool DEBUG, std::vector<TLorentzVector> &AllGoodJets, std::vector<TLorentzVector> &SelectedJets);


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


// vector<Ptr<flashgg::Jet> > HHWWggTagProducer::GetFHminWHJets(bool doHHWWggDebug, std::vector<edm::Ptr<Jet> > AllGoodJets)
void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<TLorentzVector> &SelectedJets, bool DEBUG = 0)
{
    // get 4 jets for FH final state with minWH vals
    SelectedJets.clear();
    double TempMinWMass = 999999.0;
    double TempMinHMass = 999999.0;
    
    int OnShellW_LeadingJetIndex = -1;
    int OnShellW_SubLeadingJetIndex = -1;
    int OffShellW_LeadingJetIndex = -1;
    int OffShellW_SubLeadingJetIndex = -1;
    
    TLorentzVector jet11;
    TLorentzVector jet12;
    TLorentzVector jet1;
    TLorentzVector jet2;
    TLorentzVector jet3;
    TLorentzVector jet4;
    
    int nTagJets = AllGoodJets.size();
    
    // Select 2 jets whose mass closest to W-boson mass
    for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
        for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
            if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
            jet11 = AllGoodJets[CountJet1];
            jet12 = AllGoodJets[CountJet2];
            
            double deltaMass =  abs((jet11 + jet12).M() - 80.0);
            if (DEBUG) std::cout << "deltaMass = " << deltaMass << "\t TempMinWMass = " << TempMinWMass << std::endl;
            if ( deltaMass < TempMinWMass)
            {
                if  (jet11.Pt() > jet12.Pt()) {
                    OnShellW_LeadingJetIndex = CountJet1;
                    OnShellW_SubLeadingJetIndex = CountJet2;
                } else {
                    OnShellW_LeadingJetIndex = CountJet2;
                    OnShellW_SubLeadingJetIndex = CountJet1;
                }
                TempMinWMass = deltaMass;
                if (DEBUG) std::cout << "==> (CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
            }
        }
    }
    if (DEBUG) std::cout << "[INFO] Print Jet Index (After W-Selection): " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;
    
    for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
        if (CountJet1 == OnShellW_LeadingJetIndex || CountJet1 == OnShellW_SubLeadingJetIndex) continue;
        for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
            if (CountJet2 == OnShellW_LeadingJetIndex || CountJet2 == OnShellW_SubLeadingJetIndex) continue;
            if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
            jet11 = AllGoodJets[CountJet1];
            jet12 = AllGoodJets[CountJet2];
            
            double deltaMass =  abs((jet11 + jet12 + AllGoodJets[OnShellW_LeadingJetIndex] + AllGoodJets[OnShellW_SubLeadingJetIndex] ).M() - 125.0);
            if (DEBUG) std::cout << "deltaMass = " << deltaMass << "\t TempMinHMass = " << TempMinHMass << std::endl;
            if ( deltaMass < TempMinHMass)
            {
                if  (jet11.Pt() > jet12.Pt()) {
                    OffShellW_LeadingJetIndex = CountJet1;
                    OffShellW_SubLeadingJetIndex = CountJet2;
                } else {
                    OffShellW_LeadingJetIndex = CountJet2;
                    OffShellW_SubLeadingJetIndex = CountJet1;
                }
                TempMinHMass = deltaMass;
                if (DEBUG) std::cout << "==> (CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
            }
        }
    }
    jet1 = AllGoodJets[OnShellW_LeadingJetIndex];
    jet2 = AllGoodJets[OnShellW_SubLeadingJetIndex];
    jet3 = AllGoodJets[OffShellW_LeadingJetIndex];
    jet4 = AllGoodJets[OffShellW_SubLeadingJetIndex];
    
    if (DEBUG) std::cout << "[INFO] Print pt of 4 selected jets: " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;
    if (DEBUG) std::cout << "[INFO] jet1 pT = " << jet1.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet2 pT = " << jet2.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet3 pT = " << jet3.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet4 pT = " << jet4.Pt() << std::endl;
    
    SelectedJets.push_back(jet1);
    SelectedJets.push_back(jet2);
    SelectedJets.push_back(jet3);
    SelectedJets.push_back(jet4);
    
}
