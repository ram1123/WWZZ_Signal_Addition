/*
 * =====================================================================================
 *
 *       Filename:  RdataFrame.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/21 16:38:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */

// ROOT::EnableImplicitMT(); // uncomment to run in parallel mode
// using TLorentzVectors = vector<TLorentzVector>;
// using doubles = vector<double>;
// using crvecRef = const ROOT::VecOps::RVec<double>&;

// const TLorentzVector CalcInvMass(double pt, double eta, double phi, double mass) {
//         TLorentzVector lv;
//         lv.SetPtEtaPhiM(pt, eta, phi, mass);
//         return lv;
// }

// doubles CalcInvMasses(int nParts, crvecRef pts, crvecRef etas, crvecRef phis, crvecRef masses)
// {
//    doubles masses(nParts);
//    for (auto i : ROOT::TSeqU(nParts)) {
//       masses[i] = CalcInvMass(pts[i], etas[i], phis[i], masses[i]);
//    }
//    return masses;
// }

double testFunc(float test) {
    return test;
}

void RdataFrame() {
    // ROOT::RDataFrame rdf("tagsDumper/trees/Data_13TeV_HHWWggTag_1", "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root");
    ROOT::RDataFrame rdf("tagsDumper/trees/Data_13TeV_HHWWggTag_1", "test.root");
    // auto CMS_hgg_mass = rdf.Histo1D("CMS_hgg_mass");
    auto rdf1 = rdf.Define("testFunc", testFunc, {"CMS_hgg_mass"});
    auto newDf = rdf.Snapshot("Data_13TeV_HHWWggTag_1", "outNameFile.root");
    auto newHist = rdf1.Histo1D("testFunc");
}