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
