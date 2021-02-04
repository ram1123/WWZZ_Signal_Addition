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


void getallTrees(TDirectory *f,
                TString basepath,
                std::vector<TString> &TreeNames,
                TString SearchString,
                bool DEBUG=false
                );
void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets,
                    std::vector<Float_t> &b_dis,
                    std::vector<int> &passMediumJetID,
                    std::vector<int> &passTightJetID,
                    std::vector<TLorentzVector> &SelectedJets,
                    std::vector<Float_t> &Selectedb_dis,
                    bool DEBUG = 0
                    );
TString GetLastString(string s,
                      string delimiter,
                      bool DEBUG=0
                      );


void getallTrees(TDirectory *f, TString basepath, std::vector<TString> &TreeNames, TString SearchString, bool DEBUG)
{
    if (DEBUG) std::cout << "Starting!!!" << std::endl;
    if (DEBUG) std::cout << "basepath: " << basepath << std::endl;

    TIter next(f->GetListOfKeys());
    TKey *key;
    while ( (key = (TKey*)next())) {
        TString kname = key->GetName();
        TObject *obj = key->ReadObj();
        if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
            if (DEBUG) std::cout << "kname: " <<  kname << std::endl;
            f->cd(key->GetName());
            TDirectory *subdir = gDirectory;
            getallTrees(subdir, basepath+kname+"/", TreeNames, SearchString);
        } else if(obj->IsA()->InheritsFrom(TTree::Class()) && kname.Contains(SearchString)) {
            if (DEBUG) std::cout << "basepath: " << basepath+kname << std::endl;
            TreeNames.push_back(basepath+kname);
        }
    }
}


/**
 * @brief      Select 4 jets for FH selection that satisfies W-mass and H-mass constraints
 *
 * @param      AllGoodJets      All good jets satisfying the jets pre-selection
 * @param      b_dis            b-discriminator branches for all good jets
 * @param      passMediumJetID  pass medium jet ID branch for all good jets
 * @param      passTightJetID   pass tight jet ID branch for all good jets
 * @param      SelectedJets     Four selected jets that satisfying FH selection.
 * @param      Selectedb_dis    b-discriminator for the 4-selected jets.
 * @param[in]  DEBUG            If its 1 then print more info that helps for debug
 */
void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets,
                    std::vector<Float_t> &b_dis,
                    std::vector<int> &passMediumJetID,
                    std::vector<int> &passTightJetID,
                    std::vector<TLorentzVector> &SelectedJets,
                    std::vector<Float_t> &Selectedb_dis,
                    bool DEBUG
                    )
{
    // get 4 jets for FH final state with minWH vals
    SelectedJets.clear();
    Selectedb_dis.clear();
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
    Float_t jet1b;
    Float_t jet2b;
    Float_t jet3b;
    Float_t jet4b;

    int nTagJets = AllGoodJets.size();

    // Select 2 jets whose mass closest to W-boson mass
    for (int CountJet1 = 0; CountJet1 < nTagJets-1; CountJet1++) {
        for (int CountJet2 = CountJet1+1; CountJet2 < nTagJets; CountJet2++) {
            if (DEBUG) std::cout << "(CountJet1,CountJet2) = (" << CountJet1 << "," << CountJet2 << ")" << std::endl;
            jet11 = AllGoodJets[CountJet1];
            jet12 = AllGoodJets[CountJet2];
            // if (b_dis[CountJet1] > 0.7221) continue;
            // if (b_dis[CountJet2] > 0.7221) continue;
            // if (int(passTightJetID[CountJet1]) == 1) continue;
            // if (int(passTightJetID[CountJet2]) == 1) continue;

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
    jet1b = b_dis[OnShellW_LeadingJetIndex];
    jet2b = b_dis[OnShellW_SubLeadingJetIndex];
    jet3b = b_dis[OffShellW_LeadingJetIndex];
    jet4b = b_dis[OffShellW_SubLeadingJetIndex];

    if (DEBUG) std::cout << "[INFO] Print pt of 4 selected jets: " << OnShellW_LeadingJetIndex << "\t" << OnShellW_SubLeadingJetIndex << "\t" << OffShellW_LeadingJetIndex << "\t" << OffShellW_SubLeadingJetIndex  << std::endl;
    if (DEBUG) std::cout << "[INFO] jet1 pT = " << jet1.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet2 pT = " << jet2.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet3 pT = " << jet3.Pt() << std::endl;
    if (DEBUG) std::cout << "[INFO] jet4 pT = " << jet4.Pt() << std::endl;

    if (OnShellW_LeadingJetIndex== -1 || OnShellW_SubLeadingJetIndex==-1 || OffShellW_LeadingJetIndex == -1 || OffShellW_SubLeadingJetIndex==-1)
    {
        SelectedJets.push_back(TLorentzVector(0,0,0,0));
        SelectedJets.push_back(TLorentzVector(0,0,0,0));
        SelectedJets.push_back(TLorentzVector(0,0,0,0));
        SelectedJets.push_back(TLorentzVector(0,0,0,0));
        Selectedb_dis.push_back(-999.0);
        Selectedb_dis.push_back(-999.0);
        Selectedb_dis.push_back(-999.0);
        Selectedb_dis.push_back(-999.0);
        /* code */
    } else {
        SelectedJets.push_back(jet1);
        SelectedJets.push_back(jet2);
        SelectedJets.push_back(jet3);
        SelectedJets.push_back(jet4);
        Selectedb_dis.push_back(jet1b);
        Selectedb_dis.push_back(jet2b);
        Selectedb_dis.push_back(jet3b);
        Selectedb_dis.push_back(jet4b);
    }
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

