# @Author: Ram Krishna Sharma
# @Date:   2021-04-12 17:40:46
# @Last Modified by:   Ram Krishna Sharma
# @Last Modified time: 2021-04-19
#path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Signal/GluGluToHHTo2G4Q_node_cHHH1_2017.root"
# path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Signal/*cHHH1_2017.root"
# path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Backgrounds/*.root"
# path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Data/*.root"

#path1="/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2016/ttHJetToGG_M125.root"
#path1="/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2018/VHToGG_M125_2018.root"
#path1="/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2018/*cHHH1_2018.root"
#path1="/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2017/*.root"
#path1="/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2018/GluGluToHHTo2G4Q_node_cHHH2p45_2018.root"
path1="/eos/user/l/lipe/ntuple/DNN_sample/FlashggNtuples_WithMoreVars/2018/*cHHH0*.root"

doHadd=${1}
DirName="tagsDumper/trees"
# DirName=""

if [[ doHadd -eq 1 ]]; then
    #statements
    for filename in ${path1}
    do
        echo "==============================================================="
        echo ""
        date
        echo ""
        echo "==============================================================="
        NewFileName="${filename%.root}"
        NewFileName="${NewFileName}_hadd.root"
        echo "Before hadd keep original file to /tmp/rasharma"
        echo "In case something happens we can grab them from /tmp/rasharma"
        cp $filename /tmp/rasharma/
        echo "hadd $NewFileName $filename"
        hadd $NewFileName $filename
        echo "---"
        echo "mv $NewFileName $filename"
        mv $NewFileName $filename
        echo "==========="
        date
        echo "==========="
    done
fi

echo "****************************************"
echo "****************************************"
echo "****************************************"
echo "****************************************"

for filename in ${path1}
do
    echo "rootls ${filename}:${DirName}"
    # rootls $filename
    # rootls $filename:tagsDumper/trees
    rootls $filename:$DirName
    echo "==========="
    echo " "
done


#if [[ doHadd -eq 1 ]]; then
#    #statements
#    for filename in ${path1}
#    do
#        echo "==============================================================="
#        echo ""
#        date
#        echo ""
#        echo "==============================================================="
#        NewFileName="${filename%.root}"
#        NewFileName="${NewFileName}_hadd.root"
#        echo "Before hadd keep original file to /tmp/rasharma"
#        echo "In case something happens we can grab them from /tmp/rasharma"
#        # cp $filename /tmp/rasharma/
#        echo "hadd $NewFileName $filename"
#        hadd $NewFileName $filename
#        echo "---"
#        echo "mv $NewFileName $filename"
#        mv $NewFileName $filename
#        echo "==========="
#        date
#        echo "==========="
#    done
#fi
#
#echo "****************************************"
#echo "****************************************"
#echo "****************************************"
#echo "****************************************"
#
#for filename in ${path1}
#do
#    echo "rootls ${filename}:${DirName}"
#    # rootls $filename
#    # rootls $filename:tagsDumper/trees
#    rootls $filename:$DirName
#    echo "==========="
#    echo " "
#done
