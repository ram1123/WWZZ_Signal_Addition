#pragma once

class AngularVariables {
public:

	AngularVariables(
                    TLorentzVector HH,
                    TLorentzVector HToGG,
                    TLorentzVector G1,
                    TLorentzVector G2,
                    TLorentzVector HToWW,
                    TLorentzVector W1,
                    TLorentzVector W2);
	~AngularVariables();
    void computeAngles(double& costheta1, double& costheta2, double& Phi, double& costhetastar, double& Phi1);
    float getCosThetaStar_CS();
    float getCosThetaStar_CS_old(float ebeam);
    std::vector<float> CosThetaAngles();
    float HelicityCosTheta( TLorentzVector Booster, TLorentzVector Boosted);
private:
    TLorentzVector thep4H;
    TLorentzVector thep4Z1;
    TLorentzVector thep4M11;
    TLorentzVector thep4M12;
    TLorentzVector thep4Z2;
    TLorentzVector thep4M21;
    TLorentzVector thep4M22;
};