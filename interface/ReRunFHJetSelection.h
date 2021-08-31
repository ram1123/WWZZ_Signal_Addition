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
// #include "utils.C"

TString GetTreeName(TFile *f, TString (&RootFileDirStructure)[3], bool DEBUG=0);
TString GetTreeName(TFile *f, std::vector<TString> &RootFileDirStructure, std::vector<TString> &ListOfAllTrees, bool DEBUG=0);
TString GetTreeName(TFile *f, std::vector<TString> &ListOfAllTrees, bool DEBUG=0);
void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG );
void GetFHJetUsingDR(TLorentzVector &Hgg, std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG );
TString GetLastString(string s, string delimiter, bool DEBUG=0);
void GetBScoreMaxJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, TLorentzVector &SelectedJets, Float_t &Selectedb_dis, bool DEBUG );
void GetBScoreMaxTwoJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, TLorentzVector &SelectedJets, Float_t &Selectedb_dis, bool DEBUG );
void HighBScore_ThenLeadJet(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, TLorentzVector &SelectedJets, Float_t &Selectedb_dis, bool DEBUG );
void SumOfHighestTwoBScores(std::vector<Float_t> &b_dis, Float_t &SumBScore, bool DEBUG );


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

TString GetTreeName(TFile *f, std::vector<TString> &ListOfAllTrees, bool DEBUG)
{
    TString DirName = "";

    TIter next(f->GetListOfKeys());
    TKey *key;
    while ( (key = (TKey*)next())) {
        if (DEBUG) std::cout << "key name: " << key->GetName() << "\tClass: " << key->GetClassName() << std::endl;
        if (string(key->GetName()).find("Tag_1") != std::string::npos)
            ListOfAllTrees.push_back(TString(key->GetName()));

        // if (key->IsFolder()) {
        //     f->cd(key->GetName());
        //     DirName += key->GetName();
        //     TDirectory *subdir = gDirectory;
        //     TIter next(subdir->GetListOfKeys());
        //     TKey *key2;
        //     while ( (key2 = (TKey*)next())) {
        //         if (DEBUG) std::cout << "key2 name: " << key2->GetName() << "\tClass: " << key2->GetClassName() << std::endl;
        //         if (key->IsFolder()){
        //             DirName += "/";
        //             DirName += key2->GetName();
        //             subdir->cd(key2->GetName());
        //             TDirectory *subdir = gDirectory;
        //             TIter next(subdir->GetListOfKeys());
        //             TKey *key3;
        //             while ( (key3 = (TKey*)next())) {
        //                 if (string(key3->GetName()).find("Tag_1") != std::string::npos)
        //                 {
        //                     if (DEBUG) std::cout << "key3 name: " << key3->GetName() << "\tClass: " << key3->GetClassName() << std::endl;
        //                     ListOfAllTrees.push_back(TString(key3->GetName()));
        //                 }
        //             }
        //         }
        //     }
        // }
    }
    return "TEST";
}

/**
 * @brief      Select 4 jets for FH selection that satisfies W-mass and H-mass constraints.
 *
 * @param      AllGoodJets    All good jets satisfying the jets pre-selection.
 * @param      b_dis          b-discriminator branches fro all good jets.
 * @param      SelectedJets   Four selected jets that satisfying FH selection.
 * @param      Selectedb_dis  b-discriminator for the 4-selected jets.
 * @param[in]  DEBUG          If its 1 then print more info that helps for debug.
 */
void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG)
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

    SelectedJets.push_back(jet1);
    SelectedJets.push_back(jet2);
    SelectedJets.push_back(jet3);
    SelectedJets.push_back(jet4);
    Selectedb_dis.push_back(jet1b);
    Selectedb_dis.push_back(jet2b);
    Selectedb_dis.push_back(jet3b);
    Selectedb_dis.push_back(jet4b);

}

void GetFHJetUsingDR(TLorentzVector &Hgg, std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG = 0)
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
    TLorentzVector jet21;
    TLorentzVector jet22;
    TLorentzVector jet1;
    TLorentzVector jet2;
    TLorentzVector jet3;
    TLorentzVector jet4;
    Float_t jet1b;
    Float_t jet2b;
    Float_t jet3b;
    Float_t jet4b;

    int nTagJets = AllGoodJets.size();
    std::vector<int> PosOfGoodJets;

    for (int i = 0; i < nTagJets; ++i)
    {
        PosOfGoodJets.push_back(i);
    }

    std::vector<std::vector<int>> CombinationsOf4Jets = getAllCombinations(PosOfGoodJets, 4);

    if (DEBUG) std::cout << "Size of vector output: " << CombinationsOf4Jets.size() << std::endl;

    float minDR = 0.0;

    for (int i = 0; i < CombinationsOf4Jets.size(); ++i)
    {
        if (DEBUG) std::cout << "Combination: " << i << ": ";
        for (int j = 0; j < CombinationsOf4Jets[i].size(); ++j)
        {
            if (DEBUG) std::cout << CombinationsOf4Jets[i][j] << "\t";
        }
        TLorentzVector HWW = AllGoodJets[CombinationsOf4Jets[i][0]] + AllGoodJets[CombinationsOf4Jets[i][1]] + AllGoodJets[CombinationsOf4Jets[i][2]] + AllGoodJets[CombinationsOf4Jets[i][3]];
        float temp_dR = DeltaR(Hgg.Eta(), Hgg.Phi(), HWW.Eta(), HWW.Phi());

        if (temp_dR > minDR)
        {
            /* code */
            minDR = temp_dR;

            std::vector<std::vector<int>> CombinationsOf2Jets = getAllCombinations(CombinationsOf4Jets[i], 2);

            float minDMass = 100.0;

            for (int WMassIndex = 0; WMassIndex < CombinationsOf2Jets.size(); ++WMassIndex)
            {
                TLorentzVector W1 = AllGoodJets[CombinationsOf2Jets[WMassIndex][0]] + AllGoodJets[CombinationsOf2Jets[WMassIndex][1]];
                float temp_Mass = abs(W1.M() - 80.0);
                if (temp_Mass < minDMass)
                {
                    minDMass = temp_Mass;
                    OnShellW_LeadingJetIndex = CombinationsOf2Jets[WMassIndex][0];
                    OnShellW_SubLeadingJetIndex = CombinationsOf2Jets[WMassIndex][1];
                }
            }

            int countOffShellJets = 0;
            for (int IndexOffShellW = 0; IndexOffShellW < CombinationsOf4Jets[i].size(); ++IndexOffShellW)
            {
                if (CombinationsOf4Jets[i][IndexOffShellW] == OnShellW_LeadingJetIndex) continue;
                if (CombinationsOf4Jets[i][IndexOffShellW] == OnShellW_SubLeadingJetIndex) continue;
                countOffShellJets++;
                if (countOffShellJets==1) OffShellW_LeadingJetIndex = CombinationsOf4Jets[i][IndexOffShellW];
                if (countOffShellJets==2) OffShellW_SubLeadingJetIndex = CombinationsOf4Jets[i][IndexOffShellW];
            }

        }

        if (DEBUG) std::cout << "\n" << std::endl;
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

    SelectedJets.push_back(jet1);
    SelectedJets.push_back(jet2);
    SelectedJets.push_back(jet3);
    SelectedJets.push_back(jet4);
    Selectedb_dis.push_back(jet1b);
    Selectedb_dis.push_back(jet2b);
    Selectedb_dis.push_back(jet3b);
    Selectedb_dis.push_back(jet4b);
}


void GetBScoreMaxJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, TLorentzVector &SelectedJets, Float_t &Selectedb_dis, bool DEBUG )
{
    // get 4 jets for FH final state with minWH vals
    double tempBScore = -999.0;

    int nTagJets = AllGoodJets.size();

    // Select 2 jets whose mass closest to W-boson mass
    for (int CountJet1 = 0; CountJet1 < nTagJets; CountJet1++)
    {
        if (b_dis[CountJet1] > tempBScore)
        {
            Selectedb_dis = b_dis[CountJet1];
            SelectedJets = AllGoodJets[CountJet1];
            tempBScore = b_dis[CountJet1];
        }
    }
}

void GetBScoreMaxTwoJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, TLorentzVector &SelectedJets, Float_t &Selectedb_dis, bool DEBUG )
{
    // get 4 jets for FH final state with minWH vals
    double tempBScore1 = -999.0;
    double tempBScore2 = -999.0;
    double index1 = -999.0;
    double index2 = -999.0;

    TLorentzVector Jet1;
    TLorentzVector Jet2;

    int nTagJets = AllGoodJets.size();

    // Select 2 jets whose mass closest to W-boson mass
    for (int CountJet1 = 0; CountJet1 < nTagJets; CountJet1++)
    {
        if (DEBUG) std::cout << CountJet1 << ": " << b_dis[CountJet1]<< std::endl;
        if (b_dis[CountJet1] > tempBScore1)
        {
            tempBScore2 = tempBScore1;
            tempBScore1 = b_dis[CountJet1];
            Jet2 = Jet1;
            Jet1 = AllGoodJets[CountJet1];
            index2 = index1;
            index1 = CountJet1;
        } else {
            if (b_dis[CountJet1] > tempBScore2)
            {
                tempBScore2 = b_dis[CountJet1];
                Jet2 = AllGoodJets[CountJet1];
                index2 = CountJet1;
            }
        }
    }
    if (DEBUG) std::cout << "Two selected b-scores: " << tempBScore1 << "("<< index1 << "),\t" << tempBScore2 <<"(" << index2 << ")"  << std::endl;
    SelectedJets = Jet1 + Jet2;
    Selectedb_dis = tempBScore1 + tempBScore2;
}

void HighBScore_ThenLeadJet(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, TLorentzVector &SelectedJets, Float_t &Selectedb_dis, bool DEBUG )
{
    // get 4 jets for FH final state with minWH vals
    double tempBScore1 = -999.0;
    double tempBScore2 = -999.0;
    double tempPt = -999.0;
    double index1 = -999.0;
    double index2 = -999.0;

    TLorentzVector Jet1;
    TLorentzVector Jet2;

    int nTagJets = AllGoodJets.size();

    // Select 2 jets whose mass closest to W-boson mass
    for (int CountJet1 = 0; CountJet1 < nTagJets; CountJet1++)
    {
        if (DEBUG) std::cout << CountJet1 << ": " << b_dis[CountJet1] << ",\t" << AllGoodJets[CountJet1].Pt() << std::endl;
        if (b_dis[CountJet1] > tempBScore1)
        {
            tempBScore1 = b_dis[CountJet1];
            index1 = CountJet1;
        }
    }
    Jet1 = AllGoodJets[index1];
    if (DEBUG) std::cout << "\n\n" << std::endl;

    for (int CountJet1 = 0; CountJet1 < nTagJets; CountJet1++)
    {
        if (CountJet1 == index1) continue;
        if (DEBUG) std::cout << CountJet1 << ": " << tempPt << "\t" << AllGoodJets[CountJet1].Pt() << std::endl;
        if (AllGoodJets[CountJet1].Pt() > tempPt)
        {
            Jet2 = AllGoodJets[CountJet1];
            tempBScore2 = b_dis[CountJet1];
            index2 = CountJet1;
            tempPt = AllGoodJets[CountJet1].Pt();
        }
    }
    if (DEBUG) std::cout << "Two selected b-scores: " << tempBScore1 << "("<< index1 << "),\t" << tempBScore2 <<"(" << index2 << ")"  << std::endl;
    if (DEBUG) std::cout << "Two selected b-scores: " << Jet1.Pt() << "("<< index1 << "),\t" << Jet2.Pt() <<"(" << index2 << ")"  << std::endl;
    SelectedJets = Jet1 + Jet2;
    Selectedb_dis = tempBScore1 + tempBScore2;
}

void SumOfHighestTwoBScores(std::vector<Float_t> &b_dis, Float_t &SumBScore, bool DEBUG )
{
    // get 4 jets for FH final state with minWH vals
    double tempBScore1 = -999.0;
    double tempBScore2 = -999.0;

    // Select 2 highest b-score jets
    for (int CountJet1 = 0; CountJet1 < b_dis.size(); CountJet1++)
    {
        if (DEBUG) std::cout << CountJet1 << ": " << b_dis[CountJet1]<< std::endl;
        if (b_dis[CountJet1] > tempBScore1)
        {
            tempBScore2 = tempBScore1;
            tempBScore1 = b_dis[CountJet1];
        } else {
            if (b_dis[CountJet1] > tempBScore2)
            {
                tempBScore2 = b_dis[CountJet1];
            }
        }
    }
    if (DEBUG) std::cout << "Two selected b-scores: " << tempBScore1 << ",\t" << tempBScore2 << std::endl;
    SumBScore = tempBScore1 + tempBScore2;
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


