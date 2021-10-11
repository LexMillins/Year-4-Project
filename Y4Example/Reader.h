//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Oct  8 08:43:37 2021 by ROOT version 6.24/04
// from TTree nominal/tree
// found on file: /disk/moose/atlas/asc/AnalysisTop/PFlowVR_v16/period_mc16a/user.achishol.mc16_13TeV.363356.Sherpa_NNPDF30NNLO_ZqqZll.deriv.DAOD_FTAG2.e5525_s3126_r9364_p3801.ATop.PFlowVR.v16_output.root/user.achishol.18108467._000001.output.root
//////////////////////////////////////////////////////////

#ifndef Reader_h
#define Reader_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"

using namespace std;

class Reader {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *mc_generator_weights;
   Float_t         weight_mc;
   Float_t         weight_pileup;
   Float_t         weight_leptonSF;
   Float_t         weight_globalLeptonTriggerSF;
   Float_t         weight_oldTriggerSF;
   Float_t         weight_jvt;
   Float_t         weight_pileup_UP;
   Float_t         weight_pileup_DOWN;
   Float_t         weight_leptonSF_EL_SF_Trigger_UP;
   Float_t         weight_leptonSF_EL_SF_Trigger_DOWN;
   Float_t         weight_leptonSF_EL_SF_Reco_UP;
   Float_t         weight_leptonSF_EL_SF_Reco_DOWN;
   Float_t         weight_leptonSF_EL_SF_ID_UP;
   Float_t         weight_leptonSF_EL_SF_ID_DOWN;
   Float_t         weight_leptonSF_EL_SF_Isol_UP;
   Float_t         weight_leptonSF_EL_SF_Isol_DOWN;
   Float_t         weight_leptonSF_MU_SF_Trigger_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_Trigger_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Trigger_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_Trigger_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;
   Float_t         weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Isol_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_Isol_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_Isol_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_Isol_SYST_DOWN;
   Float_t         weight_leptonSF_MU_SF_TTVA_STAT_UP;
   Float_t         weight_leptonSF_MU_SF_TTVA_STAT_DOWN;
   Float_t         weight_leptonSF_MU_SF_TTVA_SYST_UP;
   Float_t         weight_leptonSF_MU_SF_TTVA_SYST_DOWN;
   Float_t         weight_globalLeptonTriggerSF_EL_Trigger_UP;
   Float_t         weight_globalLeptonTriggerSF_EL_Trigger_DOWN;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP;
   Float_t         weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN;
   Float_t         weight_oldTriggerSF_EL_Trigger_UP;
   Float_t         weight_oldTriggerSF_EL_Trigger_DOWN;
   Float_t         weight_oldTriggerSF_MU_Trigger_STAT_UP;
   Float_t         weight_oldTriggerSF_MU_Trigger_STAT_DOWN;
   Float_t         weight_oldTriggerSF_MU_Trigger_SYST_UP;
   Float_t         weight_oldTriggerSF_MU_Trigger_SYST_DOWN;
   Float_t         weight_indiv_SF_EL_Reco;
   Float_t         weight_indiv_SF_EL_Reco_UP;
   Float_t         weight_indiv_SF_EL_Reco_DOWN;
   Float_t         weight_indiv_SF_EL_ID;
   Float_t         weight_indiv_SF_EL_ID_UP;
   Float_t         weight_indiv_SF_EL_ID_DOWN;
   Float_t         weight_indiv_SF_EL_Isol;
   Float_t         weight_indiv_SF_EL_Isol_UP;
   Float_t         weight_indiv_SF_EL_Isol_DOWN;
   Float_t         weight_indiv_SF_EL_ChargeID;
   Float_t         weight_indiv_SF_EL_ChargeID_UP;
   Float_t         weight_indiv_SF_EL_ChargeID_DOWN;
   Float_t         weight_indiv_SF_EL_ChargeMisID;
   Float_t         weight_indiv_SF_EL_ChargeMisID_STAT_UP;
   Float_t         weight_indiv_SF_EL_ChargeMisID_STAT_DOWN;
   Float_t         weight_indiv_SF_EL_ChargeMisID_SYST_UP;
   Float_t         weight_indiv_SF_EL_ChargeMisID_SYST_DOWN;
   Float_t         weight_indiv_SF_MU_ID;
   Float_t         weight_indiv_SF_MU_ID_STAT_UP;
   Float_t         weight_indiv_SF_MU_ID_STAT_DOWN;
   Float_t         weight_indiv_SF_MU_ID_SYST_UP;
   Float_t         weight_indiv_SF_MU_ID_SYST_DOWN;
   Float_t         weight_indiv_SF_MU_ID_STAT_LOWPT_UP;
   Float_t         weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN;
   Float_t         weight_indiv_SF_MU_ID_SYST_LOWPT_UP;
   Float_t         weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN;
   Float_t         weight_indiv_SF_MU_Isol;
   Float_t         weight_indiv_SF_MU_Isol_STAT_UP;
   Float_t         weight_indiv_SF_MU_Isol_STAT_DOWN;
   Float_t         weight_indiv_SF_MU_Isol_SYST_UP;
   Float_t         weight_indiv_SF_MU_Isol_SYST_DOWN;
   Float_t         weight_indiv_SF_MU_TTVA;
   Float_t         weight_indiv_SF_MU_TTVA_STAT_UP;
   Float_t         weight_indiv_SF_MU_TTVA_STAT_DOWN;
   Float_t         weight_indiv_SF_MU_TTVA_SYST_UP;
   Float_t         weight_indiv_SF_MU_TTVA_SYST_DOWN;
   Float_t         weight_jvt_UP;
   Float_t         weight_jvt_DOWN;
   ULong64_t       eventNumber;
   UInt_t          runNumber;
   UInt_t          randomRunNumber;
   UInt_t          mcChannelNumber;
   Float_t         mu;
   Float_t         mu_actual;
   UInt_t          backgroundFlags;
   UInt_t          hasBadMuon;
   vector<float>   *el_pt;
   vector<float>   *el_eta;
   vector<float>   *el_cl_eta;
   vector<float>   *el_phi;
   vector<float>   *el_e;
   vector<float>   *el_charge;
   vector<float>   *el_topoetcone20;
   vector<float>   *el_ptvarcone20;
   vector<char>    *el_CF;
   vector<float>   *el_d0sig;
   vector<float>   *el_delta_z0_sintheta;
   vector<int>     *el_true_type;
   vector<int>     *el_true_origin;
   vector<int>     *el_true_firstEgMotherTruthType;
   vector<int>     *el_true_firstEgMotherTruthOrigin;
   vector<int>     *el_true_firstEgMotherPdgId;
   vector<char>    *el_true_isPrompt;
   vector<char>    *el_true_isChargeFl;
   vector<float>   *mu_pt;
   vector<float>   *mu_eta;
   vector<float>   *mu_phi;
   vector<float>   *mu_e;
   vector<float>   *mu_charge;
   vector<float>   *mu_topoetcone20;
   vector<float>   *mu_ptvarcone30;
   vector<float>   *mu_d0sig;
   vector<float>   *mu_delta_z0_sintheta;
   vector<int>     *mu_true_type;
   vector<int>     *mu_true_origin;
   vector<char>    *mu_true_isPrompt;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_e;
   vector<float>   *jet_mv2c00;
   vector<float>   *jet_mv2c10;
   vector<float>   *jet_mv2c20;
   vector<float>   *jet_ip3dsv1;
   vector<float>   *jet_jvt;
   vector<char>    *jet_passfjvt;
   vector<int>     *jet_truthflav;
   vector<int>     *jet_truthPartonLabel;
   vector<char>    *jet_isTrueHS;
   vector<int>     *jet_truthflavExtended;
   vector<float>   *jet_MV2r;
   vector<float>   *jet_MV2rmu;
   vector<float>   *jet_DL1;
   vector<float>   *jet_DL1r;
   vector<float>   *jet_DL1rmu;
   vector<float>   *jet_MV2cl100;
   vector<float>   *jet_MV2c100;
   vector<float>   *jet_DL1_pu;
   vector<float>   *jet_DL1_pc;
   vector<float>   *jet_DL1_pb;
   vector<float>   *jet_DL1r_pu;
   vector<float>   *jet_DL1r_pc;
   vector<float>   *jet_DL1r_pb;
   vector<float>   *jet_DL1rmu_pu;
   vector<float>   *jet_DL1rmu_pc;
   vector<float>   *jet_DL1rmu_pb;
   vector<float>   *tjet_pt;
   vector<float>   *tjet_eta;
   vector<float>   *tjet_phi;
   vector<float>   *tjet_e;
   vector<float>   *tjet_mv2c00;
   vector<float>   *tjet_mv2c10;
   vector<float>   *tjet_mv2c20;
   Float_t         met_met;
   Float_t         met_phi;
   Int_t           ee_2015;
   Int_t           ee_2016;
   Int_t           mumu_2015;
   Int_t           mumu_2016;
   Char_t          HLT_mu20_iloose_L1MU15;
   Char_t          HLT_e60_lhmedium_nod0;
   Char_t          HLT_mu50;
   Char_t          HLT_e60_lhmedium;
   Char_t          HLT_mu40;
   Char_t          HLT_e120_lhloose;
   Char_t          HLT_e24_lhmedium_L1EM20VH;
   Char_t          HLT_mu26_ivarmedium;
   Char_t          HLT_e140_lhloose_nod0;
   Char_t          HLT_e26_lhtight_nod0_ivarloose;
   vector<char>    *el_trigMatch_HLT_e60_lhmedium_nod0;
   vector<char>    *el_trigMatch_HLT_e60_lhmedium;
   vector<char>    *el_trigMatch_HLT_e120_lhloose;
   vector<char>    *el_trigMatch_HLT_e24_lhmedium_L1EM20VH;
   vector<char>    *el_trigMatch_HLT_e140_lhloose_nod0;
   vector<char>    *el_trigMatch_HLT_e26_lhtight_nod0_ivarloose;
   vector<char>    *mu_trigMatch_HLT_mu50;
   vector<char>    *mu_trigMatch_HLT_mu26_ivarmedium;
   vector<char>    *mu_trigMatch_HLT_mu40;
   vector<char>    *mu_trigMatch_HLT_mu20_iloose_L1MU15;
   //vector<int>     *jet_truthflavExtended;
   vector<double>  *jet_mv2c10Flip;
   vector<double>  *jet_mv2c10r;
   vector<double>  *jet_mv2c10rFlip;
   vector<double>  *jet_DL1Flip_pb;
   vector<double>  *jet_DL1Flip_pc;
   vector<double>  *jet_DL1Flip_pu;
   //vector<double>  *jet_DL1r_pb;
   //vector<double>  *jet_DL1r_pc;
   //vector<double>  *jet_DL1r_pu;
   vector<double>  *jet_SMT_discriminant;
   vector<float>   *jet_SV1_masssvx;
   vector<float>   *jet_SV1_Lxy;
   vector<float>   *jet_SV1_L3d;
   vector<int>     *tjet_numConstituents;
   vector<int>     *tjet_truthflav;
   vector<int>     *tjet_truthflavExtended;
   vector<double>  *tjet_mv2c10Flip;
   vector<double>  *tjet_mv2c10r;
   vector<double>  *tjet_mv2c10rFlip;
   vector<double>  *tjet_DL1_pb;
   vector<double>  *tjet_DL1_pc;
   vector<double>  *tjet_DL1_pu;
   vector<double>  *tjet_DL1r_pb;
   vector<double>  *tjet_DL1r_pc;
   vector<double>  *tjet_DL1r_pu;
   vector<double>  *tjet_DL1Flip_pb;
   vector<double>  *tjet_DL1Flip_pc;
   vector<double>  *tjet_DL1Flip_pu;
   vector<double>  *tjet_SMT_discriminant;
   vector<float>   *tjet_SV1_masssvx;
   vector<float>   *tjet_SV1_Lxy;
   vector<float>   *tjet_SV1_L3d;

   // List of branches
   TBranch        *b_mc_generator_weights;   //!
   TBranch        *b_weight_mc;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_weight_leptonSF;   //!
   TBranch        *b_weight_globalLeptonTriggerSF;   //!
   TBranch        *b_weight_oldTriggerSF;   //!
   TBranch        *b_weight_jvt;   //!
   TBranch        *b_weight_pileup_UP;   //!
   TBranch        *b_weight_pileup_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Trigger_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Trigger_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Reco_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Reco_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_ID_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_ID_DOWN;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Isol_UP;   //!
   TBranch        *b_weight_leptonSF_EL_SF_Isol_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Trigger_SYST_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_Isol_SYST_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_STAT_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_STAT_DOWN;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_SYST_UP;   //!
   TBranch        *b_weight_leptonSF_MU_SF_TTVA_SYST_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_Trigger_UP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_EL_Trigger_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP;   //!
   TBranch        *b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN;   //!
   TBranch        *b_weight_oldTriggerSF_EL_Trigger_UP;   //!
   TBranch        *b_weight_oldTriggerSF_EL_Trigger_DOWN;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_STAT_UP;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_STAT_DOWN;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_SYST_UP;   //!
   TBranch        *b_weight_oldTriggerSF_MU_Trigger_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_Reco;   //!
   TBranch        *b_weight_indiv_SF_EL_Reco_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_Reco_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ID;   //!
   TBranch        *b_weight_indiv_SF_EL_ID_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ID_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_Isol;   //!
   TBranch        *b_weight_indiv_SF_EL_Isol_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_Isol_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeID;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeID_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeID_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_EL_ChargeMisID_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_LOWPT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_LOWPT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_Isol_SYST_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_STAT_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_STAT_DOWN;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_SYST_UP;   //!
   TBranch        *b_weight_indiv_SF_MU_TTVA_SYST_DOWN;   //!
   TBranch        *b_weight_jvt_UP;   //!
   TBranch        *b_weight_jvt_DOWN;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_randomRunNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_mu_actual;   //!
   TBranch        *b_backgroundFlags;   //!
   TBranch        *b_hasBadMuon;   //!
   TBranch        *b_el_pt;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_cl_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_e;   //!
   TBranch        *b_el_charge;   //!
   TBranch        *b_el_topoetcone20;   //!
   TBranch        *b_el_ptvarcone20;   //!
   TBranch        *b_el_CF;   //!
   TBranch        *b_el_d0sig;   //!
   TBranch        *b_el_delta_z0_sintheta;   //!
   TBranch        *b_el_true_type;   //!
   TBranch        *b_el_true_origin;   //!
   TBranch        *b_el_true_firstEgMotherTruthType;   //!
   TBranch        *b_el_true_firstEgMotherTruthOrigin;   //!
   TBranch        *b_el_true_firstEgMotherPdgId;   //!
   TBranch        *b_el_true_isPrompt;   //!
   TBranch        *b_el_true_isChargeFl;   //!
   TBranch        *b_mu_pt;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_e;   //!
   TBranch        *b_mu_charge;   //!
   TBranch        *b_mu_topoetcone20;   //!
   TBranch        *b_mu_ptvarcone30;   //!
   TBranch        *b_mu_d0sig;   //!
   TBranch        *b_mu_delta_z0_sintheta;   //!
   TBranch        *b_mu_true_type;   //!
   TBranch        *b_mu_true_origin;   //!
   TBranch        *b_mu_true_isPrompt;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_mv2c00;   //!
   TBranch        *b_jet_mv2c10;   //!
   TBranch        *b_jet_mv2c20;   //!
   TBranch        *b_jet_ip3dsv1;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_passfjvt;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_jet_truthPartonLabel;   //!
   TBranch        *b_jet_isTrueHS;   //!
   TBranch        *b_jet_truthflavExtended;   //!
   TBranch        *b_jet_MV2r;   //!
   TBranch        *b_jet_MV2rmu;   //!
   TBranch        *b_jet_DL1;   //!
   TBranch        *b_jet_DL1r;   //!
   TBranch        *b_jet_DL1rmu;   //!
   TBranch        *b_jet_MV2cl100;   //!
   TBranch        *b_jet_MV2c100;   //!
   TBranch        *b_jet_DL1_pu;   //!
   TBranch        *b_jet_DL1_pc;   //!
   TBranch        *b_jet_DL1_pb;   //!
   TBranch        *b_jet_DL1r_pu;   //!
   TBranch        *b_jet_DL1r_pc;   //!
   TBranch        *b_jet_DL1r_pb;   //!
   TBranch        *b_jet_DL1rmu_pu;   //!
   TBranch        *b_jet_DL1rmu_pc;   //!
   TBranch        *b_jet_DL1rmu_pb;   //!
   TBranch        *b_tjet_pt;   //!
   TBranch        *b_tjet_eta;   //!
   TBranch        *b_tjet_phi;   //!
   TBranch        *b_tjet_e;   //!
   TBranch        *b_tjet_mv2c00;   //!
   TBranch        *b_tjet_mv2c10;   //!
   TBranch        *b_tjet_mv2c20;   //!
   TBranch        *b_met_met;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_ee_2015;   //!
   TBranch        *b_ee_2016;   //!
   TBranch        *b_mumu_2015;   //!
   TBranch        *b_mumu_2016;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_mu40;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_el_trigMatch_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_el_trigMatch_HLT_e60_lhmedium;   //!
   TBranch        *b_el_trigMatch_HLT_e120_lhloose;   //!
   TBranch        *b_el_trigMatch_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_el_trigMatch_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_el_trigMatch_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_mu_trigMatch_HLT_mu50;   //!
   TBranch        *b_mu_trigMatch_HLT_mu26_ivarmedium;   //!
   TBranch        *b_mu_trigMatch_HLT_mu40;   //!
   TBranch        *b_mu_trigMatch_HLT_mu20_iloose_L1MU15;   //!
   //TBranch        *b_jet_truthflavExtended;   //!
   TBranch        *b_jet_mv2c10Flip;   //!
   TBranch        *b_jet_mv2c10r;   //!
   TBranch        *b_jet_mv2c10rFlip;   //!
   TBranch        *b_jet_DL1Flip_pb;   //!
   TBranch        *b_jet_DL1Flip_pc;   //!
   TBranch        *b_jet_DL1Flip_pu;   //!
   //TBranch        *b_jet_DL1r_pb;   //!
   //TBranch        *b_jet_DL1r_pc;   //!
   //TBranch        *b_jet_DL1r_pu;   //!
   TBranch        *b_jet_SMT_discriminant;   //!
   TBranch        *b_jet_SV1_masssvx;   //!
   TBranch        *b_jet_SV1_Lxy;   //!
   TBranch        *b_jet_SV1_L3d;   //!
   TBranch        *b_tjet_numConstituents;   //!
   TBranch        *b_tjet_truthflav;   //!
   TBranch        *b_tjet_truthflavExtended;   //!
   TBranch        *b_tjet_mv2c10Flip;   //!
   TBranch        *b_tjet_mv2c10r;   //!
   TBranch        *b_tjet_mv2c10rFlip;   //!
   TBranch        *b_tjet_DL1_pb;   //!
   TBranch        *b_tjet_DL1_pc;   //!
   TBranch        *b_tjet_DL1_pu;   //!
   TBranch        *b_tjet_DL1r_pb;   //!
   TBranch        *b_tjet_DL1r_pc;   //!
   TBranch        *b_tjet_DL1r_pu;   //!
   TBranch        *b_tjet_DL1Flip_pb;   //!
   TBranch        *b_tjet_DL1Flip_pc;   //!
   TBranch        *b_tjet_DL1Flip_pu;   //!
   TBranch        *b_tjet_SMT_discriminant;   //!
   TBranch        *b_tjet_SV1_masssvx;   //!
   TBranch        *b_tjet_SV1_Lxy;   //!
   TBranch        *b_tjet_SV1_L3d;   //!

   Reader(TTree *tree=0);
   virtual ~Reader();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Reader_cxx
Reader::Reader(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

   }
   Init(tree);
}

Reader::~Reader()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Reader::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Reader::LoadTree(Long64_t entry)
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

void Reader::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mc_generator_weights = 0;
   el_pt = 0;
   el_eta = 0;
   el_cl_eta = 0;
   el_phi = 0;
   el_e = 0;
   el_charge = 0;
   el_topoetcone20 = 0;
   el_ptvarcone20 = 0;
   el_CF = 0;
   el_d0sig = 0;
   el_delta_z0_sintheta = 0;
   el_true_type = 0;
   el_true_origin = 0;
   el_true_firstEgMotherTruthType = 0;
   el_true_firstEgMotherTruthOrigin = 0;
   el_true_firstEgMotherPdgId = 0;
   el_true_isPrompt = 0;
   el_true_isChargeFl = 0;
   mu_pt = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_e = 0;
   mu_charge = 0;
   mu_topoetcone20 = 0;
   mu_ptvarcone30 = 0;
   mu_d0sig = 0;
   mu_delta_z0_sintheta = 0;
   mu_true_type = 0;
   mu_true_origin = 0;
   mu_true_isPrompt = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_e = 0;
   jet_mv2c00 = 0;
   jet_mv2c10 = 0;
   jet_mv2c20 = 0;
   jet_ip3dsv1 = 0;
   jet_jvt = 0;
   jet_passfjvt = 0;
   jet_truthflav = 0;
   jet_truthPartonLabel = 0;
   jet_isTrueHS = 0;
   jet_truthflavExtended = 0;
   jet_MV2r = 0;
   jet_MV2rmu = 0;
   jet_DL1 = 0;
   jet_DL1r = 0;
   jet_DL1rmu = 0;
   jet_MV2cl100 = 0;
   jet_MV2c100 = 0;
   jet_DL1_pu = 0;
   jet_DL1_pc = 0;
   jet_DL1_pb = 0;
   jet_DL1r_pu = 0;
   jet_DL1r_pc = 0;
   jet_DL1r_pb = 0;
   jet_DL1rmu_pu = 0;
   jet_DL1rmu_pc = 0;
   jet_DL1rmu_pb = 0;
   tjet_pt = 0;
   tjet_eta = 0;
   tjet_phi = 0;
   tjet_e = 0;
   tjet_mv2c00 = 0;
   tjet_mv2c10 = 0;
   tjet_mv2c20 = 0;
   el_trigMatch_HLT_e60_lhmedium_nod0 = 0;
   el_trigMatch_HLT_e60_lhmedium = 0;
   el_trigMatch_HLT_e120_lhloose = 0;
   el_trigMatch_HLT_e24_lhmedium_L1EM20VH = 0;
   el_trigMatch_HLT_e140_lhloose_nod0 = 0;
   el_trigMatch_HLT_e26_lhtight_nod0_ivarloose = 0;
   mu_trigMatch_HLT_mu50 = 0;
   mu_trigMatch_HLT_mu26_ivarmedium = 0;
   mu_trigMatch_HLT_mu40 = 0;
   mu_trigMatch_HLT_mu20_iloose_L1MU15 = 0;
   //jet_truthflavExtended = 0;
   jet_mv2c10Flip = 0;
   jet_mv2c10r = 0;
   jet_mv2c10rFlip = 0;
   jet_DL1Flip_pb = 0;
   jet_DL1Flip_pc = 0;
   jet_DL1Flip_pu = 0;
   jet_DL1r_pb = 0;
   jet_DL1r_pc = 0;
   jet_DL1r_pu = 0;
   jet_SMT_discriminant = 0;
   jet_SV1_masssvx = 0;
   jet_SV1_Lxy = 0;
   jet_SV1_L3d = 0;
   tjet_numConstituents = 0;
   tjet_truthflav = 0;
   tjet_truthflavExtended = 0;
   tjet_mv2c10Flip = 0;
   tjet_mv2c10r = 0;
   tjet_mv2c10rFlip = 0;
   tjet_DL1_pb = 0;
   tjet_DL1_pc = 0;
   tjet_DL1_pu = 0;
   tjet_DL1r_pb = 0;
   tjet_DL1r_pc = 0;
   tjet_DL1r_pu = 0;
   tjet_DL1Flip_pb = 0;
   tjet_DL1Flip_pc = 0;
   tjet_DL1Flip_pu = 0;
   tjet_SMT_discriminant = 0;
   tjet_SV1_masssvx = 0;
   tjet_SV1_Lxy = 0;
   tjet_SV1_L3d = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("mc_generator_weights", &mc_generator_weights, &b_mc_generator_weights);
   fChain->SetBranchAddress("weight_mc", &weight_mc, &b_weight_mc);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("weight_leptonSF", &weight_leptonSF, &b_weight_leptonSF);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF", &weight_globalLeptonTriggerSF, &b_weight_globalLeptonTriggerSF);
   fChain->SetBranchAddress("weight_oldTriggerSF", &weight_oldTriggerSF, &b_weight_oldTriggerSF);
   fChain->SetBranchAddress("weight_jvt", &weight_jvt, &b_weight_jvt);
   fChain->SetBranchAddress("weight_pileup_UP", &weight_pileup_UP, &b_weight_pileup_UP);
   fChain->SetBranchAddress("weight_pileup_DOWN", &weight_pileup_DOWN, &b_weight_pileup_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Trigger_UP", &weight_leptonSF_EL_SF_Trigger_UP, &b_weight_leptonSF_EL_SF_Trigger_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Trigger_DOWN", &weight_leptonSF_EL_SF_Trigger_DOWN, &b_weight_leptonSF_EL_SF_Trigger_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Reco_UP", &weight_leptonSF_EL_SF_Reco_UP, &b_weight_leptonSF_EL_SF_Reco_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Reco_DOWN", &weight_leptonSF_EL_SF_Reco_DOWN, &b_weight_leptonSF_EL_SF_Reco_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_ID_UP", &weight_leptonSF_EL_SF_ID_UP, &b_weight_leptonSF_EL_SF_ID_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_ID_DOWN", &weight_leptonSF_EL_SF_ID_DOWN, &b_weight_leptonSF_EL_SF_ID_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Isol_UP", &weight_leptonSF_EL_SF_Isol_UP, &b_weight_leptonSF_EL_SF_Isol_UP);
   fChain->SetBranchAddress("weight_leptonSF_EL_SF_Isol_DOWN", &weight_leptonSF_EL_SF_Isol_DOWN, &b_weight_leptonSF_EL_SF_Isol_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_STAT_UP", &weight_leptonSF_MU_SF_Trigger_STAT_UP, &b_weight_leptonSF_MU_SF_Trigger_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_STAT_DOWN", &weight_leptonSF_MU_SF_Trigger_STAT_DOWN, &b_weight_leptonSF_MU_SF_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_SYST_UP", &weight_leptonSF_MU_SF_Trigger_SYST_UP, &b_weight_leptonSF_MU_SF_Trigger_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Trigger_SYST_DOWN", &weight_leptonSF_MU_SF_Trigger_SYST_DOWN, &b_weight_leptonSF_MU_SF_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_UP", &weight_leptonSF_MU_SF_ID_STAT_UP, &b_weight_leptonSF_MU_SF_ID_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_DOWN", &weight_leptonSF_MU_SF_ID_STAT_DOWN, &b_weight_leptonSF_MU_SF_ID_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_UP", &weight_leptonSF_MU_SF_ID_SYST_UP, &b_weight_leptonSF_MU_SF_ID_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_DOWN", &weight_leptonSF_MU_SF_ID_SYST_DOWN, &b_weight_leptonSF_MU_SF_ID_SYST_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP", &weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP, &b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN", &weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN, &b_weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP", &weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP, &b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN", &weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN, &b_weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_STAT_UP", &weight_leptonSF_MU_SF_Isol_STAT_UP, &b_weight_leptonSF_MU_SF_Isol_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_STAT_DOWN", &weight_leptonSF_MU_SF_Isol_STAT_DOWN, &b_weight_leptonSF_MU_SF_Isol_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_SYST_UP", &weight_leptonSF_MU_SF_Isol_SYST_UP, &b_weight_leptonSF_MU_SF_Isol_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_Isol_SYST_DOWN", &weight_leptonSF_MU_SF_Isol_SYST_DOWN, &b_weight_leptonSF_MU_SF_Isol_SYST_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_STAT_UP", &weight_leptonSF_MU_SF_TTVA_STAT_UP, &b_weight_leptonSF_MU_SF_TTVA_STAT_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_STAT_DOWN", &weight_leptonSF_MU_SF_TTVA_STAT_DOWN, &b_weight_leptonSF_MU_SF_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_SYST_UP", &weight_leptonSF_MU_SF_TTVA_SYST_UP, &b_weight_leptonSF_MU_SF_TTVA_SYST_UP);
   fChain->SetBranchAddress("weight_leptonSF_MU_SF_TTVA_SYST_DOWN", &weight_leptonSF_MU_SF_TTVA_SYST_DOWN, &b_weight_leptonSF_MU_SF_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_Trigger_UP", &weight_globalLeptonTriggerSF_EL_Trigger_UP, &b_weight_globalLeptonTriggerSF_EL_Trigger_UP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_EL_Trigger_DOWN", &weight_globalLeptonTriggerSF_EL_Trigger_DOWN, &b_weight_globalLeptonTriggerSF_EL_Trigger_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP", &weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP, &b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN", &weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN, &b_weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP", &weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP, &b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP);
   fChain->SetBranchAddress("weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN", &weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN, &b_weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("weight_oldTriggerSF_EL_Trigger_UP", &weight_oldTriggerSF_EL_Trigger_UP, &b_weight_oldTriggerSF_EL_Trigger_UP);
   fChain->SetBranchAddress("weight_oldTriggerSF_EL_Trigger_DOWN", &weight_oldTriggerSF_EL_Trigger_DOWN, &b_weight_oldTriggerSF_EL_Trigger_DOWN);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_STAT_UP", &weight_oldTriggerSF_MU_Trigger_STAT_UP, &b_weight_oldTriggerSF_MU_Trigger_STAT_UP);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_STAT_DOWN", &weight_oldTriggerSF_MU_Trigger_STAT_DOWN, &b_weight_oldTriggerSF_MU_Trigger_STAT_DOWN);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_SYST_UP", &weight_oldTriggerSF_MU_Trigger_SYST_UP, &b_weight_oldTriggerSF_MU_Trigger_SYST_UP);
   fChain->SetBranchAddress("weight_oldTriggerSF_MU_Trigger_SYST_DOWN", &weight_oldTriggerSF_MU_Trigger_SYST_DOWN, &b_weight_oldTriggerSF_MU_Trigger_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco", &weight_indiv_SF_EL_Reco, &b_weight_indiv_SF_EL_Reco);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco_UP", &weight_indiv_SF_EL_Reco_UP, &b_weight_indiv_SF_EL_Reco_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Reco_DOWN", &weight_indiv_SF_EL_Reco_DOWN, &b_weight_indiv_SF_EL_Reco_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID", &weight_indiv_SF_EL_ID, &b_weight_indiv_SF_EL_ID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID_UP", &weight_indiv_SF_EL_ID_UP, &b_weight_indiv_SF_EL_ID_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ID_DOWN", &weight_indiv_SF_EL_ID_DOWN, &b_weight_indiv_SF_EL_ID_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol", &weight_indiv_SF_EL_Isol, &b_weight_indiv_SF_EL_Isol);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol_UP", &weight_indiv_SF_EL_Isol_UP, &b_weight_indiv_SF_EL_Isol_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_Isol_DOWN", &weight_indiv_SF_EL_Isol_DOWN, &b_weight_indiv_SF_EL_Isol_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeID", &weight_indiv_SF_EL_ChargeID, &b_weight_indiv_SF_EL_ChargeID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeID_UP", &weight_indiv_SF_EL_ChargeID_UP, &b_weight_indiv_SF_EL_ChargeID_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeID_DOWN", &weight_indiv_SF_EL_ChargeID_DOWN, &b_weight_indiv_SF_EL_ChargeID_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID", &weight_indiv_SF_EL_ChargeMisID, &b_weight_indiv_SF_EL_ChargeMisID);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_STAT_UP", &weight_indiv_SF_EL_ChargeMisID_STAT_UP, &b_weight_indiv_SF_EL_ChargeMisID_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_STAT_DOWN", &weight_indiv_SF_EL_ChargeMisID_STAT_DOWN, &b_weight_indiv_SF_EL_ChargeMisID_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_SYST_UP", &weight_indiv_SF_EL_ChargeMisID_SYST_UP, &b_weight_indiv_SF_EL_ChargeMisID_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_EL_ChargeMisID_SYST_DOWN", &weight_indiv_SF_EL_ChargeMisID_SYST_DOWN, &b_weight_indiv_SF_EL_ChargeMisID_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID", &weight_indiv_SF_MU_ID, &b_weight_indiv_SF_MU_ID);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_UP", &weight_indiv_SF_MU_ID_STAT_UP, &b_weight_indiv_SF_MU_ID_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_DOWN", &weight_indiv_SF_MU_ID_STAT_DOWN, &b_weight_indiv_SF_MU_ID_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_UP", &weight_indiv_SF_MU_ID_SYST_UP, &b_weight_indiv_SF_MU_ID_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_DOWN", &weight_indiv_SF_MU_ID_SYST_DOWN, &b_weight_indiv_SF_MU_ID_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_LOWPT_UP", &weight_indiv_SF_MU_ID_STAT_LOWPT_UP, &b_weight_indiv_SF_MU_ID_STAT_LOWPT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN", &weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN, &b_weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_LOWPT_UP", &weight_indiv_SF_MU_ID_SYST_LOWPT_UP, &b_weight_indiv_SF_MU_ID_SYST_LOWPT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN", &weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN, &b_weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol", &weight_indiv_SF_MU_Isol, &b_weight_indiv_SF_MU_Isol);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_STAT_UP", &weight_indiv_SF_MU_Isol_STAT_UP, &b_weight_indiv_SF_MU_Isol_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_STAT_DOWN", &weight_indiv_SF_MU_Isol_STAT_DOWN, &b_weight_indiv_SF_MU_Isol_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_SYST_UP", &weight_indiv_SF_MU_Isol_SYST_UP, &b_weight_indiv_SF_MU_Isol_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_Isol_SYST_DOWN", &weight_indiv_SF_MU_Isol_SYST_DOWN, &b_weight_indiv_SF_MU_Isol_SYST_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA", &weight_indiv_SF_MU_TTVA, &b_weight_indiv_SF_MU_TTVA);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_STAT_UP", &weight_indiv_SF_MU_TTVA_STAT_UP, &b_weight_indiv_SF_MU_TTVA_STAT_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_STAT_DOWN", &weight_indiv_SF_MU_TTVA_STAT_DOWN, &b_weight_indiv_SF_MU_TTVA_STAT_DOWN);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_SYST_UP", &weight_indiv_SF_MU_TTVA_SYST_UP, &b_weight_indiv_SF_MU_TTVA_SYST_UP);
   fChain->SetBranchAddress("weight_indiv_SF_MU_TTVA_SYST_DOWN", &weight_indiv_SF_MU_TTVA_SYST_DOWN, &b_weight_indiv_SF_MU_TTVA_SYST_DOWN);
   fChain->SetBranchAddress("weight_jvt_UP", &weight_jvt_UP, &b_weight_jvt_UP);
   fChain->SetBranchAddress("weight_jvt_DOWN", &weight_jvt_DOWN, &b_weight_jvt_DOWN);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("randomRunNumber", &randomRunNumber, &b_randomRunNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("mu_actual", &mu_actual, &b_mu_actual);
   fChain->SetBranchAddress("backgroundFlags", &backgroundFlags, &b_backgroundFlags);
   fChain->SetBranchAddress("hasBadMuon", &hasBadMuon, &b_hasBadMuon);
   fChain->SetBranchAddress("el_pt", &el_pt, &b_el_pt);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_cl_eta", &el_cl_eta, &b_el_cl_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_e", &el_e, &b_el_e);
   fChain->SetBranchAddress("el_charge", &el_charge, &b_el_charge);
   fChain->SetBranchAddress("el_topoetcone20", &el_topoetcone20, &b_el_topoetcone20);
   fChain->SetBranchAddress("el_ptvarcone20", &el_ptvarcone20, &b_el_ptvarcone20);
   fChain->SetBranchAddress("el_CF", &el_CF, &b_el_CF);
   fChain->SetBranchAddress("el_d0sig", &el_d0sig, &b_el_d0sig);
   fChain->SetBranchAddress("el_delta_z0_sintheta", &el_delta_z0_sintheta, &b_el_delta_z0_sintheta);
   fChain->SetBranchAddress("el_true_type", &el_true_type, &b_el_true_type);
   fChain->SetBranchAddress("el_true_origin", &el_true_origin, &b_el_true_origin);
   fChain->SetBranchAddress("el_true_firstEgMotherTruthType", &el_true_firstEgMotherTruthType, &b_el_true_firstEgMotherTruthType);
   fChain->SetBranchAddress("el_true_firstEgMotherTruthOrigin", &el_true_firstEgMotherTruthOrigin, &b_el_true_firstEgMotherTruthOrigin);
   fChain->SetBranchAddress("el_true_firstEgMotherPdgId", &el_true_firstEgMotherPdgId, &b_el_true_firstEgMotherPdgId);
   fChain->SetBranchAddress("el_true_isPrompt", &el_true_isPrompt, &b_el_true_isPrompt);
   fChain->SetBranchAddress("el_true_isChargeFl", &el_true_isChargeFl, &b_el_true_isChargeFl);
   fChain->SetBranchAddress("mu_pt", &mu_pt, &b_mu_pt);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("mu_charge", &mu_charge, &b_mu_charge);
   fChain->SetBranchAddress("mu_topoetcone20", &mu_topoetcone20, &b_mu_topoetcone20);
   fChain->SetBranchAddress("mu_ptvarcone30", &mu_ptvarcone30, &b_mu_ptvarcone30);
   fChain->SetBranchAddress("mu_d0sig", &mu_d0sig, &b_mu_d0sig);
   fChain->SetBranchAddress("mu_delta_z0_sintheta", &mu_delta_z0_sintheta, &b_mu_delta_z0_sintheta);
   fChain->SetBranchAddress("mu_true_type", &mu_true_type, &b_mu_true_type);
   fChain->SetBranchAddress("mu_true_origin", &mu_true_origin, &b_mu_true_origin);
   fChain->SetBranchAddress("mu_true_isPrompt", &mu_true_isPrompt, &b_mu_true_isPrompt);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_mv2c00", &jet_mv2c00, &b_jet_mv2c00);
   fChain->SetBranchAddress("jet_mv2c10", &jet_mv2c10, &b_jet_mv2c10);
   fChain->SetBranchAddress("jet_mv2c20", &jet_mv2c20, &b_jet_mv2c20);
   fChain->SetBranchAddress("jet_ip3dsv1", &jet_ip3dsv1, &b_jet_ip3dsv1);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("jet_passfjvt", &jet_passfjvt, &b_jet_passfjvt);
   fChain->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav);
   fChain->SetBranchAddress("jet_truthPartonLabel", &jet_truthPartonLabel, &b_jet_truthPartonLabel);
   fChain->SetBranchAddress("jet_isTrueHS", &jet_isTrueHS, &b_jet_isTrueHS);
   fChain->SetBranchAddress("jet_truthflavExtended", &jet_truthflavExtended, &b_jet_truthflavExtended);
   fChain->SetBranchAddress("jet_MV2r", &jet_MV2r, &b_jet_MV2r);
   fChain->SetBranchAddress("jet_MV2rmu", &jet_MV2rmu, &b_jet_MV2rmu);
   fChain->SetBranchAddress("jet_DL1", &jet_DL1, &b_jet_DL1);
   fChain->SetBranchAddress("jet_DL1r", &jet_DL1r, &b_jet_DL1r);
   fChain->SetBranchAddress("jet_DL1rmu", &jet_DL1rmu, &b_jet_DL1rmu);
   fChain->SetBranchAddress("jet_MV2cl100", &jet_MV2cl100, &b_jet_MV2cl100);
   fChain->SetBranchAddress("jet_MV2c100", &jet_MV2c100, &b_jet_MV2c100);
   fChain->SetBranchAddress("jet_DL1_pu", &jet_DL1_pu, &b_jet_DL1_pu);
   fChain->SetBranchAddress("jet_DL1_pc", &jet_DL1_pc, &b_jet_DL1_pc);
   fChain->SetBranchAddress("jet_DL1_pb", &jet_DL1_pb, &b_jet_DL1_pb);
   fChain->SetBranchAddress("jet_DL1r_pu", &jet_DL1r_pu, &b_jet_DL1r_pu);
   fChain->SetBranchAddress("jet_DL1r_pc", &jet_DL1r_pc, &b_jet_DL1r_pc);
   fChain->SetBranchAddress("jet_DL1r_pb", &jet_DL1r_pb, &b_jet_DL1r_pb);
   fChain->SetBranchAddress("jet_DL1rmu_pu", &jet_DL1rmu_pu, &b_jet_DL1rmu_pu);
   fChain->SetBranchAddress("jet_DL1rmu_pc", &jet_DL1rmu_pc, &b_jet_DL1rmu_pc);
   fChain->SetBranchAddress("jet_DL1rmu_pb", &jet_DL1rmu_pb, &b_jet_DL1rmu_pb);
   fChain->SetBranchAddress("tjet_pt", &tjet_pt, &b_tjet_pt);
   fChain->SetBranchAddress("tjet_eta", &tjet_eta, &b_tjet_eta);
   fChain->SetBranchAddress("tjet_phi", &tjet_phi, &b_tjet_phi);
   fChain->SetBranchAddress("tjet_e", &tjet_e, &b_tjet_e);
   fChain->SetBranchAddress("tjet_mv2c00", &tjet_mv2c00, &b_tjet_mv2c00);
   fChain->SetBranchAddress("tjet_mv2c10", &tjet_mv2c10, &b_tjet_mv2c10);
   fChain->SetBranchAddress("tjet_mv2c20", &tjet_mv2c20, &b_tjet_mv2c20);
   fChain->SetBranchAddress("met_met", &met_met, &b_met_met);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("ee_2015", &ee_2015, &b_ee_2015);
   fChain->SetBranchAddress("ee_2016", &ee_2016, &b_ee_2016);
   fChain->SetBranchAddress("mumu_2015", &mumu_2015, &b_mumu_2015);
   fChain->SetBranchAddress("mumu_2016", &mumu_2016, &b_mumu_2016);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_mu40", &HLT_mu40, &b_HLT_mu40);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("el_trigMatch_HLT_e60_lhmedium_nod0", &el_trigMatch_HLT_e60_lhmedium_nod0, &b_el_trigMatch_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("el_trigMatch_HLT_e60_lhmedium", &el_trigMatch_HLT_e60_lhmedium, &b_el_trigMatch_HLT_e60_lhmedium);
   fChain->SetBranchAddress("el_trigMatch_HLT_e120_lhloose", &el_trigMatch_HLT_e120_lhloose, &b_el_trigMatch_HLT_e120_lhloose);
   fChain->SetBranchAddress("el_trigMatch_HLT_e24_lhmedium_L1EM20VH", &el_trigMatch_HLT_e24_lhmedium_L1EM20VH, &b_el_trigMatch_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("el_trigMatch_HLT_e140_lhloose_nod0", &el_trigMatch_HLT_e140_lhloose_nod0, &b_el_trigMatch_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("el_trigMatch_HLT_e26_lhtight_nod0_ivarloose", &el_trigMatch_HLT_e26_lhtight_nod0_ivarloose, &b_el_trigMatch_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu50", &mu_trigMatch_HLT_mu50, &b_mu_trigMatch_HLT_mu50);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu26_ivarmedium", &mu_trigMatch_HLT_mu26_ivarmedium, &b_mu_trigMatch_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu40", &mu_trigMatch_HLT_mu40, &b_mu_trigMatch_HLT_mu40);
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu20_iloose_L1MU15", &mu_trigMatch_HLT_mu20_iloose_L1MU15, &b_mu_trigMatch_HLT_mu20_iloose_L1MU15);
//    fChain->SetBranchAddress("jet_truthflavExtended", &jet_truthflavExtended, &b_jet_truthflavExtended);
   fChain->SetBranchAddress("jet_mv2c10Flip", &jet_mv2c10Flip, &b_jet_mv2c10Flip);
   fChain->SetBranchAddress("jet_mv2c10r", &jet_mv2c10r, &b_jet_mv2c10r);
   fChain->SetBranchAddress("jet_mv2c10rFlip", &jet_mv2c10rFlip, &b_jet_mv2c10rFlip);
   fChain->SetBranchAddress("jet_DL1Flip_pb", &jet_DL1Flip_pb, &b_jet_DL1Flip_pb);
   fChain->SetBranchAddress("jet_DL1Flip_pc", &jet_DL1Flip_pc, &b_jet_DL1Flip_pc);
   fChain->SetBranchAddress("jet_DL1Flip_pu", &jet_DL1Flip_pu, &b_jet_DL1Flip_pu);
//    fChain->SetBranchAddress("jet_DL1r_pb", &jet_DL1r_pb, &b_jet_DL1r_pb);
//    fChain->SetBranchAddress("jet_DL1r_pc", &jet_DL1r_pc, &b_jet_DL1r_pc);
//    fChain->SetBranchAddress("jet_DL1r_pu", &jet_DL1r_pu, &b_jet_DL1r_pu);
   fChain->SetBranchAddress("jet_SMT_discriminant", &jet_SMT_discriminant, &b_jet_SMT_discriminant);
   fChain->SetBranchAddress("jet_SV1_masssvx", &jet_SV1_masssvx, &b_jet_SV1_masssvx);
   fChain->SetBranchAddress("jet_SV1_Lxy", &jet_SV1_Lxy, &b_jet_SV1_Lxy);
   fChain->SetBranchAddress("jet_SV1_L3d", &jet_SV1_L3d, &b_jet_SV1_L3d);
   fChain->SetBranchAddress("tjet_numConstituents", &tjet_numConstituents, &b_tjet_numConstituents);
   fChain->SetBranchAddress("tjet_truthflav", &tjet_truthflav, &b_tjet_truthflav);
   fChain->SetBranchAddress("tjet_truthflavExtended", &tjet_truthflavExtended, &b_tjet_truthflavExtended);
   fChain->SetBranchAddress("tjet_mv2c10Flip", &tjet_mv2c10Flip, &b_tjet_mv2c10Flip);
   fChain->SetBranchAddress("tjet_mv2c10r", &tjet_mv2c10r, &b_tjet_mv2c10r);
   fChain->SetBranchAddress("tjet_mv2c10rFlip", &tjet_mv2c10rFlip, &b_tjet_mv2c10rFlip);
   fChain->SetBranchAddress("tjet_DL1_pb", &tjet_DL1_pb, &b_tjet_DL1_pb);
   fChain->SetBranchAddress("tjet_DL1_pc", &tjet_DL1_pc, &b_tjet_DL1_pc);
   fChain->SetBranchAddress("tjet_DL1_pu", &tjet_DL1_pu, &b_tjet_DL1_pu);
   fChain->SetBranchAddress("tjet_DL1r_pb", &tjet_DL1r_pb, &b_tjet_DL1r_pb);
   fChain->SetBranchAddress("tjet_DL1r_pc", &tjet_DL1r_pc, &b_tjet_DL1r_pc);
   fChain->SetBranchAddress("tjet_DL1r_pu", &tjet_DL1r_pu, &b_tjet_DL1r_pu);
   fChain->SetBranchAddress("tjet_DL1Flip_pb", &tjet_DL1Flip_pb, &b_tjet_DL1Flip_pb);
   fChain->SetBranchAddress("tjet_DL1Flip_pc", &tjet_DL1Flip_pc, &b_tjet_DL1Flip_pc);
   fChain->SetBranchAddress("tjet_DL1Flip_pu", &tjet_DL1Flip_pu, &b_tjet_DL1Flip_pu);
   fChain->SetBranchAddress("tjet_SMT_discriminant", &tjet_SMT_discriminant, &b_tjet_SMT_discriminant);
   fChain->SetBranchAddress("tjet_SV1_masssvx", &tjet_SV1_masssvx, &b_tjet_SV1_masssvx);
   fChain->SetBranchAddress("tjet_SV1_Lxy", &tjet_SV1_Lxy, &b_tjet_SV1_Lxy);
   fChain->SetBranchAddress("tjet_SV1_L3d", &tjet_SV1_L3d, &b_tjet_SV1_L3d);
   Notify();
}

Bool_t Reader::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Reader::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Reader::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Reader_cxx
