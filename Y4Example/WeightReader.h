//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Nov  1 13:37:45 2021 by ROOT version 6.22/08
// from TTree sumWeights/
// found on file: /disk/moose/general/asc/Y4_VV_2022/user.achishol.mc16_13TeV.410472.PhPy8EG_hdamp258p75_dil.deriv.DAOD_FTAG2.e6348_s3126_r9364_p3801.ATop.PFlowVR.v16_output.root/user.achishol.18108485._000001.output.root
//////////////////////////////////////////////////////////

#ifndef WeightReader_h
#define WeightReader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "string"
#include "vector"
#include "vector"

using namespace std;

class WeightReader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           dsid;
   Int_t           isAFII;
   string          *generators;
   string          *AMITag;
   Float_t         totalEventsWeighted;
   vector<float>   *totalEventsWeighted_mc_generator_weights;
   vector<string>  *names_mc_generator_weights;
   ULong64_t       totalEvents;

   // List of branches
   TBranch        *b_dsid;   //!
   TBranch        *b_isAFII;   //!
   TBranch        *b_generators;   //!
   TBranch        *b_AMITag;   //!
   TBranch        *b_totalEventsWeighted;   //!
   TBranch        *b_totalEventsWeighted_mc_generator_weights;   //!
   TBranch        *b_names_mc_generator_weights;   //!
   TBranch        *b_totalEvents;   //!

   WeightReader(TTree *tree=0);
   virtual ~WeightReader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef WeightReader_cxx
WeightReader::WeightReader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

   }
   Init(tree);
}

WeightReader::~WeightReader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t WeightReader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t WeightReader::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void WeightReader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   generators = 0;
   AMITag = 0;
   totalEventsWeighted_mc_generator_weights = 0;
   names_mc_generator_weights = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("dsid", &dsid, &b_dsid);
   fChain->SetBranchAddress("isAFII", &isAFII, &b_isAFII);
   fChain->SetBranchAddress("generators", &generators, &b_generators);
   fChain->SetBranchAddress("AMITag", &AMITag, &b_AMITag);
   fChain->SetBranchAddress("totalEventsWeighted", &totalEventsWeighted, &b_totalEventsWeighted);
   fChain->SetBranchAddress("totalEventsWeighted_mc_generator_weights", &totalEventsWeighted_mc_generator_weights, &b_totalEventsWeighted_mc_generator_weights);
   fChain->SetBranchAddress("names_mc_generator_weights", &names_mc_generator_weights, &b_names_mc_generator_weights);
   fChain->SetBranchAddress("totalEvents", &totalEvents, &b_totalEvents);
   Notify();
}

Bool_t WeightReader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void WeightReader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t WeightReader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef WeightReader_cxx
