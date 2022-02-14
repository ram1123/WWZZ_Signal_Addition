#ifndef OUTPUT_HH
#define OUTPUT_HH

#include "TTree.h"

class output{

public:

  output(TTree *t) {
    fTree = t;
    init(fTree);
  };

  ~output() {
    delete fTree;
  };

  void clearVars();
  virtual void init(TTree *tree);

  TTree *fTree;

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  Float_t   NewWeight = 1.0;
  Float_t   Node_Number = -1;
};

#endif

void output::init(TTree* tree) {

  fTree = tree;

  // fTree->Branch("NewWeight", &NewWeight,  "NewWeight/F");
  fTree->Branch("Node_Number", &Node_Number,  "Node_Number/F");
}
