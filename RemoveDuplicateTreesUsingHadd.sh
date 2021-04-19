# @Author: Ram Krishna Sharma
# @Date:   2021-04-12 17:40:46
# @Last Modified by:   Ram Krishna Sharma
# @Last Modified time: 2021-04-19
path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Signal/*cHHH1_2017.root"
# path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Backgrounds/*.root"
# path1="/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar_v3_WithSyst_2017/Data/*.root"

doHadd=${1}
DirName="tagsDumper/trees"
DirName=""

if [[ doHadd -eq 1 ]]; then
    #statements
    for filename in ${path1}
    do
        NewFileName="${filename%.root}"
        NewFileName="${NewFileName}_hadd.root"
        echo "hadd $NewFileName $filename"
        hadd $NewFileName $filename
        echo "---"
        echo "mv $NewFileName $filename"
        mv $NewFileName $filename
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