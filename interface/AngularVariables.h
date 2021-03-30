
void computeAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12,
          TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22,
          double& costheta1,  double& costheta2,  double& Phi,
          double& costhetastar, double& Phi1);


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
void computeAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4M11, TLorentzVector thep4M12, TLorentzVector thep4Z2, TLorentzVector thep4M21, TLorentzVector thep4M22, double& costheta1, double& costheta2, double& Phi, double& costhetastar, double& Phi1)
{

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
    TLorentzVector thep4Z1inXFrame( p4Z1 ); //a
    TLorentzVector thep4Z2inXFrame( p4Z2 );
    thep4Z1inXFrame.Boost( boostX );
    thep4Z2inXFrame.Boost( boostX );
    TVector3 theZ1X_p3 = TVector3( thep4Z1inXFrame.X(), thep4Z1inXFrame.Y(), thep4Z1inXFrame.Z() );
    TVector3 theZ2X_p3 = TVector3( thep4Z2inXFrame.X(), thep4Z2inXFrame.Y(), thep4Z2inXFrame.Z() );
    costhetastar = theZ1X_p3.CosTheta();

    //// --------------------------- costheta1
    TVector3 boostV1 = -(thep4Z1.BoostVector()); // c
    TLorentzVector p4M11_BV1( p4M11 ); // b
    TLorentzVector p4M12_BV1( p4M12 );
    TLorentzVector p4M21_BV1( p4M21 );
    TLorentzVector p4M22_BV1( p4M22 );
    p4M11_BV1.Boost( boostV1 ); // d
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



float getCosThetaStar_CS(){

    LorentzVector hh_lor = diPhoton()->p4() + dijet();
    TLorentzVector hh;
    hh.SetPxPyPzE(hh_lor.Px(),hh_lor.Py(),hh_lor.Pz(),hh_lor.E()) ;

    LorentzVector h1_lor = diPhoton()->p4();
    TLorentzVector h_1;
    h_1.SetPxPyPzE(h1_lor.Px(),h1_lor.Py(),h1_lor.Pz(),h1_lor.E()) ;

    h_1.Boost(-hh.BoostVector());

    return h_1.CosTheta();
}

float getCosThetaStar_CS_old(float ebeam) const {
    // cos theta star angle in the Collins Soper frame
    // Copied directly from here: https://github.com/ResonantHbbHgg/Selection/blob/master/selection.h#L3367-L3385
    TLorentzVector p1, p2;
    p1.SetPxPyPzE(0, 0,  ebeam, ebeam);
    p2.SetPxPyPzE(0, 0, -ebeam, ebeam);

    LorentzVector hh_lor = diPhoton()->p4() + dijet();
    TLorentzVector hh;
    hh.SetPxPyPzE(hh_lor.Px(),hh_lor.Py(),hh_lor.Pz(),hh_lor.E()) ;

    TVector3 boost = - hh.BoostVector();
    p1.Boost(boost);
    p2.Boost(boost);
    LorentzVector h1_lor = diPhoton()->p4();
    TLorentzVector h_1;
    h_1.SetPxPyPzE(h1_lor.Px(),h1_lor.Py(),h1_lor.Pz(),h1_lor.E()) ;
    h_1.Boost(boost);

    TVector3 CSaxis = p1.Vect().Unit() - p2.Vect().Unit();
    CSaxis.Unit();


    return cos(   CSaxis.Angle( h_1.Vect().Unit() )    );
}


std::vector<float> CosThetaAngles() const {
    //helicityThetas[0] = cosTheta_gg
    //helicityThetas[1] = cosTheta_bb

    std::vector<float> helicityThetas;

    TLorentzVector BoostedHgg(0,0,0,0);
    BoostedHgg.SetPxPyPzE(diPhoton()->px(),diPhoton()->py(),diPhoton()->pz(),diPhoton()->energy()) ;
    TLorentzVector BoostedLeadingPhoton(0,0,0,0);
    BoostedLeadingPhoton.SetPxPyPzE(diPhoton()->leadingPhoton()->px(),diPhoton()->leadingPhoton()->py(),diPhoton()->leadingPhoton()->pz(),diPhoton()->leadingPhoton()->energy()) ;

    helicityThetas.push_back( HelicityCosTheta(BoostedHgg, BoostedLeadingPhoton));

    TLorentzVector BoostedHbb(0,0,0,0);
    BoostedHbb.SetPxPyPzE(dijet().px(),dijet().py(),dijet().pz(),dijet().energy()) ;
    TLorentzVector BoostedLeadingJet(0,0,0,0);
    BoostedLeadingJet.SetPxPyPzE(leadJet().px(),leadJet().py(),leadJet().pz(),leadJet().energy()) ;

    helicityThetas.push_back( HelicityCosTheta(BoostedHbb, BoostedLeadingJet));

    return helicityThetas;

}


float HelicityCosTheta( TLorentzVector Booster, TLorentzVector Boosted) const
{
    TVector3 BoostVector = Booster.BoostVector();
    Boosted.Boost( -BoostVector.x(), -BoostVector.y(), -BoostVector.z() );
    return Boosted.CosTheta();
}

float getPhoJetMinDr() const
{
    float PhoJetMinDr = min( min( deltaR( diPhoton()->leadingPhoton()->p4(), leadJet().p4() ), deltaR( diPhoton()->leadingPhoton()->p4(), subleadJet().p4() ) ), min( deltaR( diPhoton()->subLeadingPhoton()->p4(), leadJet().p4() ), deltaR( diPhoton()->subLeadingPhoton()->p4(), subleadJet().p4() ) ) );

    return PhoJetMinDr;
}
