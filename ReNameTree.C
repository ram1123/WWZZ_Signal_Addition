/*
 * =====================================================================================
 *
 *       Filename:  ReNameTree.C
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/02/21 15:14:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */
#include <chrono>
#include <time.h>

TString GetLastString(string s, string delimiter, bool DEBUG=0);
void getallTrees(TDirectory *f, TString basepath, std::vector<TString> &TreeNames, TString SearchString, bool DEBUG=false);
void Tokenize(const std::string& str,
          std::vector<std::string>& tokens,
          const std::string& delimiters = " ",
          bool include_delimiters=false);

void ReNameTree( 
                          TString inputFile1 = "/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2017/Signal/FH_NLO_2017_hadded/GluGluToHHTo2G4Q_node_cHHH1_2017.root",
                          TString OutPutRootFileName = "",
                          TString OutPutPath = "/tmp/rasharma/",
                          TString PrefixOutPutRootFileName = "",
                          bool WithSyst = false,
                          TString ToReplace = "_ext1",
                          TString ReplaceWith = ""
                        )
{
    clock_t tStart = clock();
    TFile *OldRootFile = new TFile(inputFile1,"READ");

    if (OldRootFile->IsZombie()) {

        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }
    std::cout << "Reading file ==> " << inputFile1 << std::endl;

    std::vector<TString> Vec_ListOfAllTrees;
    getallTrees(OldRootFile,"/",Vec_ListOfAllTrees,"HHWWggTag_1");
    int Size_Vec_ListOfAllTrees = Vec_ListOfAllTrees.size();
    std::cout << "Number of Trees: " << Size_Vec_ListOfAllTrees << std::endl;

    vector<string> fields;
    Tokenize(std::string(Vec_ListOfAllTrees[0]),fields, "/");
    TString DirectoryName = "";
    for (std::vector<string>::iterator DirName = fields.begin(); DirName != (fields.end()-1); ++DirName)
    {
        DirectoryName += *DirName + "/";
    }
    std::cout << "DirectoryName: " << DirectoryName << std::endl;

    TString NewRootFileName = GetLastString(string(inputFile1), "/");
    if (OutPutRootFileName == "") {
        OutPutRootFileName = OutPutPath+"/"+PrefixOutPutRootFileName+NewRootFileName;
    } else {
        OutPutRootFileName = OutPutPath+"/"+OutPutRootFileName;
    }
    std::cout << "Output root file name: " << OutPutRootFileName << std::endl;
    TFile *newfile = new TFile(OutPutRootFileName, "RECREATE","",207);
    newfile->mkdir(DirectoryName);
    newfile->cd(DirectoryName);

    int TreesCount = 0;
    for (std::vector<TString>::iterator OldTreeName = Vec_ListOfAllTrees.begin(); OldTreeName != Vec_ListOfAllTrees.end(); ++OldTreeName)
    {
        TreesCount++;
        if (!WithSyst) {
          if (TreesCount>=2) break;
        }
        std::cout << "Reading Tree: " << TreesCount << "/" << Size_Vec_ListOfAllTrees << ": " << *OldTreeName << std::endl;

        TTree *OldTree = (TTree*)OldRootFile->Get(TString(*OldTreeName));
        std::cout << "\tTree name: " << OldTree->GetName() << std::endl;

        // Clone the old tree
        auto newtree = OldTree->CloneTree();

        newtree->SetName((((TString)OldTree->GetName()).ReplaceAll(ToReplace, ReplaceWith)).ReplaceAll("_ext2",""));

        printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

        delete OldTree;
    }
    newfile->Write();
    newfile->Close();
    printf("Time taken to run full code: %.2fs  (%.2fm)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}



void getallTrees(TDirectory *f, TString basepath, std::vector<TString> &TreeNames, TString SearchString, bool DEBUG)
{
    if (DEBUG) std::cout << "Starting!!!" << std::endl;
    if (DEBUG) std::cout << "basepath: " << basepath << std::endl;

    TIter next(f->GetListOfKeys());
    TKey *key;
    while ( (key = (TKey*)next())) {
        TString kname = key->GetName();
        TObject *obj = key->ReadObj();
        if (obj->IsA()->InheritsFrom(TDirectory::Class())) {
            if (DEBUG) std::cout << "kname: " <<  kname << std::endl;
            f->cd(key->GetName());
            TDirectory *subdir = gDirectory;
            getallTrees(subdir, basepath+kname+"/", TreeNames, SearchString);
        } else if(obj->IsA()->InheritsFrom(TTree::Class()) && kname.Contains(SearchString)) {
            if (DEBUG) std::cout << "basepath: " << basepath+kname << std::endl;
            TreeNames.push_back(basepath+kname);
        }
    }
}


/**
 * @brief      Get the root file name. Its the last string when
 *             we split is using "/" deliminator.
 *
 * @param[in]  s          Input string
 * @param[in]  delimiter  The delimiter to be used for seperation.
 * @param[in]  DEBUG      The debug
 *
 * @return     It returns the root file name.
 */
TString GetLastString(string s, string delimiter, bool DEBUG)
{
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if (DEBUG) std::cout << "\t==> " << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << "[INFO] ReRunFHJetSelection.h#186: Last string: " << s << std::endl;

    return TString(s);
}


void Tokenize(const std::string& str,
          std::vector<std::string>& tokens,
          const std::string& delimiters = " ",
          bool include_delimiters=false)
{
  std::string src=str;
  tokens.clear();

  // Skip delimiters at beginning.
  std::string::size_type lastPos = src.find_first_not_of(delimiters, 0);

  if (include_delimiters && lastPos>0)
    tokens.push_back(src.substr(0,lastPos));

  // Find first delimiter.
  std::string::size_type pos = src.find_first_of(delimiters, lastPos);

  while (pos != std::string::npos || lastPos != std::string::npos) {
    // Found a token, add it to the vector.
    tokens.push_back(src.substr(lastPos, pos - lastPos));

    lastPos = src.find_first_not_of(delimiters, pos);

    if (include_delimiters && pos!=std::string::npos) {
      tokens.push_back(src.substr(pos, lastPos-pos));
    } //else skip delimiters.

    // Find next delimiter
    pos = src.find_first_of(delimiters, lastPos);

  }
  //cout << "tokens.size() = " << tokens.size() <<endl;
}                                                            // Tokenize

