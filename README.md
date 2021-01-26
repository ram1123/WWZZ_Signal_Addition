# WWZZ_Signal_Addition

To run the macro:

```bash
root -l -b -q ReRunFHJetSelection.C

# or

root -l -b -q "ReRunFHJetSelection.C(\"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root\")""
```

***The input tree structure for the data and MC are different. Currently, this macro is not generalized for data and MC. So, one need to uncomment `flashgg_MC flashggReader(OldTree);` everytime when running over MC and uncomment `flashgg_Data flashggReader(OldTree);` while running over data.***


# Get Scaled ZZ root file

```bash
rooteventselector -s "rand()/2147483647 <= 0.12269939" nodecHHH1_GluGluToHHTo2G2ZTo2G4Q_1.root:tagsDumper/trees/GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1 nodecHHH1_GluGluToHHTo2G2ZTo2G4Q_trimmed.root
```

This command applies a scale factor of 0.12 to the input root tree.

The above command changes the tree structure from `tagsDumper/trees/GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1` to `GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1`.

To regain the tree structure run the c++ macro: `ReStructureTTree.C`.

# Get WW+ZZ root file

Now just hadd the scaled ZZ root file and the original WW root file.