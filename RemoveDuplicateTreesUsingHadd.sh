# @Author: Ram Krishna Sharma
# @Date:   2021-04-12 17:40:46
# @Last Modified by:   Ram Krishna Sharma
# @Last Modified time: 2021-04-19

path1="/publicfs/cms/user/sharma/DNNVarAppend/CMSSW_10_6_8/src/WWZZ_Signal_Addition/*2017.root"
# path1="/publicfs/cms/user/sharma/DNNVarAppend/CMSSW_10_6_8/src/WWZZ_Signal_Addition/*GluGluToHHTo2B2G*.root"
# path1="/publicfs/cms/user/sharma/DNNVarAppend/CMSSW_10_6_8/src/WWZZ_Signal_Addition/*GluGluToHHTo2G4Q*.root"
# path1="/publicfs/cms/user/sharma/DNNVarAppend/CMSSW_10_6_8/src/WWZZ_Signal_Addition/*GluGluToHHTo2G2ZTo2G4Q*.root"
# path1="/publicfs/cms/user/sharma/DNNVarAppend/CMSSW_10_6_8/src/WWZZ_Signal_Addition/*GluGluHToGG_M125*.root"

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
        mkdir /tmp/rasharma/
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
