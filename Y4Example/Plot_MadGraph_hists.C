#include <stdio.h>
#include <math.h>

void Plot_MadGraph_hists(){


	TString inputFileName = "MadGraphHists.root";

	TString outputFileName = "MadGraphplots.root";

	TFile* inputFile = TFile::Open(inputFileName);

	TFile* outputFile = new TFile(outputFileName, "recreate");

	outputFile -> cd();

	TString histName = "h_Z_mass";

	TString histCloneName = histName;

	histCloneName += 43;

	TH1D* histClone = (TH1D *) inputFile->Get(histCloneName);

	TH1D * h_Bckgd = (TH1D *) histClone->Clone("h_Bckgd");

	TH1D * h_light_Bckgd = (TH1D *) histClone->Clone("h_light_Bckgd");

	TH1D * h_bb_Bckgd = (TH1D *) histClone->Clone("h_bb_Bckgd");

	TH1D * h_jet1_pt = (TH1D *) histClone->Clone("h_jet1_pt");

	TH1D * h_jet2_pt = (TH1D *) histClone->Clone("h_jet2_pt");

	TH1D * h_dilepton_mass = (TH1D *) histClone->Clone("h_dilepton_mass");

	TH1D * h_diboson_mass = (TH1D *) histClone->Clone("h_diboson_mass");

	TH1D * h_hadronic_boson_pt = (TH1D *) histClone->Clone("h_hadronic_boson_pt");

	TH1D * h_leptonic_boson_pt = (TH1D *) histClone->Clone("h_leptonic_boson_pt");

	h_Bckgd->Reset();

	h_light_Bckgd->Reset();

	h_Bckgd->Reset();

	h_jet1_pt->Reset();

	h_jet2_pt->Reset();



	int b[] = {45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 63};

	for( int n: b){

		TString histName_N = histName;
		histName_N += n;

		std::cout<< "hist number" << n <<std::endl;

		TH1D* hist_n = (TH1D *) inputFile->Get(histName_N);
		h_Bckgd->Add(hist_n);
	}

	TString histNameSig = histName;

	histNameSig += 44;

	TH1D * h_Sig = (TH1D *) inputFile->Get(histNameSig);

	TString histNameW = histName;

	histNameW += 45;

	TH1D* h_W_mass = (TH1D*) inputFile->Get(histNameW);

	
	TString histNamettbgd = histName;

	histNamettbgd += 43;

	TH1D * h_ttbar = (TH1D*) inputFile->Get(histNamettbgd);

	TString histNamelightflav = "h_light_flav";

	TString histNamejet1pT = "h_jet1_pt";

	TString histNamejet2pT = "h_jet2_pt";

	TString histNamedilep = "h_dilepton_mass";

	TString histNamediboson = "h_diboson_mass";

	TString histNamehadpt = "h_hadronic_boson_pt";

	TString histNameleppt = "h_leptonic_boson_pt";

	for( int n: b){

		TString histNamelightflav_N = histNamelightflav;
		histNamelightflav_N += n;

		TH1D* hist_lightn = (TH1D *) inputFile->Get(histNamelightflav_N);
		h_light_Bckgd->Add(hist_lightn);

	}

	for( int n: b){

		TString histNamejet1pT_N = histNamejet1pT;
		histNamejet1pT_N += n;

		TH1D* hist_jet1pTn = (TH1D *) inputFile->Get(histNamejet1pT_N);
		h_jet1_pt->Add(hist_jet1pTn);

	}

	for( int n: b){

		TString histNamejet2pT_N = histNamejet2pT;
		histNamejet2pT_N += n;

		TH1D* hist_jet2pTn = (TH1D *) inputFile->Get(histNamejet2pT_N);
		h_jet2_pt->Add(hist_jet2pTn);

	}

	for( int n: b){

		TString histNamebb_N = "h_Dijet_Mass_bb";
		histNamebb_N += n;

		TH1D* hist_bbn = (TH1D *) inputFile->Get(histNamebb_N);
		h_bb_Bckgd->Add(hist_bbn);

	}

		for( int n: b){

		TString histNamedilep_N = histNamedilep;
		histNamedilep_N += n;

		TH1D* hist_dilep = (TH1D *) inputFile->Get(histNamedilep_N);
		h_dilepton_mass->Add(hist_dilep);

	}

	for( int n: b){

		TString histNamediboson_N = histNamediboson;
		histNamediboson_N += n;

		TH1D* hist_diboson = (TH1D *) inputFile->Get(histNamediboson_N);
		h_diboson_mass->Add(hist_diboson);

	}

	for( int n: b){

		TString histNamehadpt_N = histNamehadpt;
		histNamehadpt_N += n;

		TH1D* hist_hadpt = (TH1D *) inputFile->Get(histNamehadpt_N);
		h_hadronic_boson_pt->Add(hist_hadpt);

	}

	for( int n: b){

		TString histNameleppt_N = histNameleppt;
		histNameleppt_N += n;

		TH1D* hist_leppt = (TH1D *) inputFile->Get(histNameleppt_N);
		h_leptonic_boson_pt->Add(hist_leppt);

	}



	outputFile->cd();

	h_light_Bckgd->Write();

	h_bb_Bckgd->Write();

	h_W_mass->SetName("h_W_mass");

	h_ttbar->SetName("h_ttbar");

	h_Sig->SetName("h_Sig");

	h_Bckgd->Write();

	h_W_mass->Write("h_W_mass");

	h_ttbar->Write();

	h_Sig->Write("h_Sig");

	h_jet1_pt->Write();

	h_jet2_pt->Write();

	h_dilepton_mass->Write();

	h_diboson_mass->Write();

	h_hadronic_boson_pt->Write();

	h_leptonic_boson_pt->Write();


	outputFile->Close();

	return 0;

}