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

void RdataFrame() {
    ROOT::RDataFrame df("tagsDumper/trees/Data_13TeV_HHWWggTag_1", "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root");
    // df.Filter("") // some cut expression -- you can also pass a C++ function
    df.Snapshot("Data_13TeV_HHWWggTag_1", "RESULT.root"); // write to file all events that pass the filter
}