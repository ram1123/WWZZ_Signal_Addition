# Some Macros

## Append new branches

This macro clone a tree and saves it into new ROOT file. Also, this is able to append new branches into the input tree.


To run the macro:

```bash
root -l -b -q ReRunFHJetSelection.C
# or
root -l -b -q ReRunFHJetSelection.C\(\"/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Data_Trees/Data_2017.root\"\)
```

One can provide following information while running:

```c++
void ReRunFHJetSelection(
    TString inputFile1 = "./GluGluToHHTo2G4Q_node_cHHH1_2017.root",
    TString OutPutPath = "./",
    TString PrefixOutPutRootFileName = "",
    bool WithSyst = true,
    bool ifDNN = false
    )
```

## Batch jobs

### Condor jobs

```bash
python condor_script.py
```
This script will generate the `.sh` and `.jdl` files. Using which one can submit the jobs.

## Remove duplicate trees using hadd

- There is a script, named `RemoveDuplicateTreesUsingHadd.sh`, to scan over all root files using the wild card and run the hadd command.
- This script takes one argument 1 or any other number.
    - If the number is equal to 1, only then it will run the hadd command else it will just run the `rootls` command, to show the content of root file.
- Update the path of the directory inside the script `RemoveDuplicateTreesUsingHadd.sh` then run:

```bash
bash RemoveDuplicateTreesUsingHadd.sh 0/1
```


## Get Scaled ZZ root file

```bash
rooteventselector -s "rand()/2147483647 <= 0.12269939" nodecHHH1_GluGluToHHTo2G2ZTo2G4Q_1.root:tagsDumper/trees/GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1 nodecHHH1_GluGluToHHTo2G2ZTo2G4Q_trimmed.root
```

This command applies a scale factor of 0.12 to the input root tree.

The above command changes the tree structure from `tagsDumper/trees/GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1` to `GluGluToHHTo2G2ZTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1`.

To regain the tree structure run the c++ macro: `ReStructureTTree.C`.

- Get WW+ZZ root file. For this just hadd the scaled ZZ root file and the original WW root file.
