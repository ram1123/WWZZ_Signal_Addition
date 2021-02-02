# WWZZ_Signal_Addition

To run the macro:

```bash
root -l -b -q ReRunFHJetSelection.C

# or

root -l -b -q "ReRunFHJetSelection.C(\"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root\")""
```

***The input tree structure for the data and MC are different. Currently, this macro is not generalized for data and MC. So, one need to uncomment `flashgg_MC flashggReader(OldTree);` everytime when running over MC and uncomment `flashgg_Data flashggReader(OldTree);` while running over data.***


# Get Scaled ZZ root file

1. Run script: `python TrimZZRootFile.py`
    1. This will generate a trimmed root file for ZZ. But, it strips the directory name `tagsDumper/trees`.
2. To get the directory name `tagsDumper/trees` run the script: `root -l -b -q ReStructureTTree.C`.


```bash
root -l -b -q "ReRunFHJetSelection.C(true, \"/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal//FHWW_NLO_2016_Hadded_2/nodecHHH1_GluGluToHHTo2G4Q.root\")"

root -l -b -q "ReRunFHJetSelection_Data.C(true, \"/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Data_Trees_2016_Hadded_Combined/allData.root\")"

root -l -b -q "ReRunFHJetSelection.C(true, \"/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/2016/Signal/FHZZ_NLO_2016_Hadded/nodecHHH1_GluGluToHHTo2G2ZTo2G4Q.root\")"

root -l -b -q "ReRunFHJetSelection.C(true, \"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/GluGluHToGG_M125.root\")"

root -l -b -q "ReRunFHJetSelection.C(true, \"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/VBFHToGG_M125.root\")"

root -l -b -q "ReRunFHJetSelection.C(true, \"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/VHToGG_M125.root\")"

root -l -b -q "ReRunFHJetSelection.C(true, \"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/ttHJetToGG_M125.root\")"

```