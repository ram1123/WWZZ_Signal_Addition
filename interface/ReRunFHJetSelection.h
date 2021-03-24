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
TString GetTreeName(TFile *f, std::vector<TString> &RootFileDirStructure, std::vector<TString> &ListOfAllTrees, bool DEBUG=0);
void GetFHminWHJets(bool DEBUG, std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis);
TString GetLastString(string s, string delimiter, bool DEBUG=0);
void computeAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12, 
          TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22,
          double& costheta1,  double& costheta2,  double& Phi,
          double& costhetastar, double& Phi1);

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
 * @brief      Select 4 jets for FH selection that satisfies W-mass and H-mass constraints.
 *
 * @param      AllGoodJets    All good jets satisfying the jets pre-selection.
 * @param      b_dis          b-discriminator branches fro all good jets.
 * @param      SelectedJets   Four selected jets that satisfying FH selection.
 * @param      Selectedb_dis  b-discriminator for the 4-selected jets.
 * @param[in]  DEBUG          If its 1 then print more info that helps for debug.
 */
void GetFHminWHJets(std::vector<TLorentzVector> &AllGoodJets, std::vector<Float_t> &b_dis, std::vector<TLorentzVector> &SelectedJets, std::vector<Float_t> &Selectedb_dis, bool DEBUG = 0)
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


/**
 * @brief      Calculates the internal angles for the HH system. Where the two 
 *             H decays into two particles.
 *
 * @param[in]  thep4H        TLorentzVector of HH System
 * @param[in]  thep4Z1       TLorentzVector of H1
 * @param[in]  thep4M11      TLorentzVector of the first decay product of H1
 * @param[in]  thep4M12      TLorentzVector of the second decay product of H1
 * @param[in]  thep4Z2       TLorentzVector of H2
 * @param[in]  thep4M21      TLorentzVector of the first decay product of H2
 * @param[in]  thep4M22      TLorentzVector of the second decay product of H2
 * @param      costheta1     calculated variable costheta1
 * @param      costheta2     calculated variable costheta2
 * @param      Phi           calculated variable Phi
 * @param      costhetastar  calculated variable costhetastar
 * @param      Phi1          calculated variable phi1
 */
void computeAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12, TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22, double& costheta1, double& costheta2, double& Phi, double& costhetastar, double& Phi1){
    
  //std::cout<<"After: "<<thep4H.Pt() << " " << thep4Z1.Pt() << " " << thep4M11.Pt() << " " <<thep4M12.Pt() << " "  << thep4Z2.Pt() << " " << thep4M21.Pt() << " " << thep4M22.Pt() << std::endl;
    ///////////////////////////////////////////////
    // check for z1/z2 convention, redefine all 4 vectors with convention
    /////////////////////////////////////////////// 
    TLorentzVector p4H, p4Z1, p4M11, p4M12, p4Z2, p4M21, p4M22;
    p4H = thep4H;
    
    p4Z1 = thep4Z1; p4M11 = thep4M11; p4M12 = thep4M12;
    p4Z2 = thep4Z2; p4M21 = thep4M21; p4M22 = thep4M22;
    //// costhetastar
    TVector3 boostX = -(thep4H.BoostVector());
    TLorentzVector thep4Z1inXFrame( p4Z1 );
    TLorentzVector thep4Z2inXFrame( p4Z2 ); 
    thep4Z1inXFrame.Boost( boostX );
    thep4Z2inXFrame.Boost( boostX );
    TVector3 theZ1X_p3 = TVector3( thep4Z1inXFrame.X(), thep4Z1inXFrame.Y(), thep4Z1inXFrame.Z() );
    TVector3 theZ2X_p3 = TVector3( thep4Z2inXFrame.X(), thep4Z2inXFrame.Y(), thep4Z2inXFrame.Z() );    
    costhetastar = theZ1X_p3.CosTheta();
    
    //// --------------------------- costheta1
    TVector3 boostV1 = -(thep4Z1.BoostVector());
    TLorentzVector p4M11_BV1( p4M11 );
    TLorentzVector p4M12_BV1( p4M12 );  
    TLorentzVector p4M21_BV1( p4M21 );
    TLorentzVector p4M22_BV1( p4M22 );
    p4M11_BV1.Boost( boostV1 );
    p4M12_BV1.Boost( boostV1 );
    p4M21_BV1.Boost( boostV1 );
    p4M22_BV1.Boost( boostV1 );
    
    TLorentzVector p4V2_BV1 = p4M21_BV1 + p4M22_BV1;
    //// costheta1
    costheta1 = -p4V2_BV1.Vect().Dot( p4M11_BV1.Vect() )/p4V2_BV1.Vect().Mag()/p4M11_BV1.Vect().Mag();

    if (boostV1.Mag()  > 1.0)
        std::cout<<"p4V2 = "<< p4V2_BV1.Vect().Mag() << "\t" << p4M11_BV1.Vect().Mag() << "\t Boost = " << boostV1.Mag() << std::endl;
    if (isnan( (float) costheta1) == 1)
        std::cout<<"p4V2 = "<< p4V2_BV1.Vect().Mag() << "\t" << p4M11_BV1.Vect().Mag() << "\t Boost = " << boostV1.Mag() << std::endl;
    
    //// --------------------------- costheta2
    TVector3 boostV2 = -(thep4Z2.BoostVector());
    TLorentzVector p4M11_BV2( p4M11 );
    TLorentzVector p4M12_BV2( p4M12 );  
    TLorentzVector p4M21_BV2( p4M21 );
    TLorentzVector p4M22_BV2( p4M22 );
    p4M11_BV2.Boost( boostV2 );
    p4M12_BV2.Boost( boostV2 );
    p4M21_BV2.Boost( boostV2 );
    p4M22_BV2.Boost( boostV2 );
    
    TLorentzVector p4V1_BV2 = p4M11_BV2 + p4M12_BV2;
    //// costheta2
    costheta2 = -p4V1_BV2.Vect().Dot( p4M21_BV2.Vect() )/p4V1_BV2.Vect().Mag()/p4M21_BV2.Vect().Mag();
    
    //// --------------------------- Phi and Phi1
    //    TVector3 boostX = -(thep4H.BoostVector());
    TLorentzVector p4M11_BX( p4M11 );
    TLorentzVector p4M12_BX( p4M12 );   
    TLorentzVector p4M21_BX( p4M21 );
    TLorentzVector p4M22_BX( p4M22 );   
    
    p4M11_BX.Boost( boostX );
    p4M12_BX.Boost( boostX );
    p4M21_BX.Boost( boostX );
    p4M22_BX.Boost( boostX );
    
    TVector3 tmp1 = p4M11_BX.Vect().Cross( p4M12_BX.Vect() );
    TVector3 tmp2 = p4M21_BX.Vect().Cross( p4M22_BX.Vect() );    
    
    TVector3 normal1_BX( tmp1.X()/tmp1.Mag(), tmp1.Y()/tmp1.Mag(), tmp1.Z()/tmp1.Mag() ); 
    TVector3 normal2_BX( tmp2.X()/tmp2.Mag(), tmp2.Y()/tmp2.Mag(), tmp2.Z()/tmp2.Mag() ); 
    
    //// Phi
    TLorentzVector p4Z1_BX = p4M11_BX + p4M12_BX;    
    double tmpSgnPhi = p4Z1_BX.Vect().Dot( normal1_BX.Cross( normal2_BX) );
    double sgnPhi = tmpSgnPhi/fabs(tmpSgnPhi);
    Phi = sgnPhi * acos( -1.*normal1_BX.Dot( normal2_BX) );
    
    
    //////////////
    
    TVector3 beamAxis(0,0,1);
    TVector3 tmp3 = (p4M11_BX + p4M12_BX).Vect();
    
    TVector3 p3V1_BX( tmp3.X()/tmp3.Mag(), tmp3.Y()/tmp3.Mag(), tmp3.Z()/tmp3.Mag() );
    TVector3 tmp4 = beamAxis.Cross( p3V1_BX );
    TVector3 normalSC_BX( tmp4.X()/tmp4.Mag(), tmp4.Y()/tmp4.Mag(), tmp4.Z()/tmp4.Mag() );
    
    //// Phi1
    double tmpSgnPhi1 = p4Z1_BX.Vect().Dot( normal1_BX.Cross( normalSC_BX) );
    double sgnPhi1 = tmpSgnPhi1/fabs(tmpSgnPhi1);    
    Phi1 = sgnPhi1 * acos( normal1_BX.Dot( normalSC_BX) );    
    
    //    std::cout << "extractAngles: " << std::endl;
    //    std::cout << "costhetastar = " << costhetastar << ", costheta1 = " << costheta1 << ", costheta2 = " << costheta2 << std::endl;
    //    std::cout << "Phi = " << Phi << ", Phi1 = " << Phi1 << std::endl;    
    
}
