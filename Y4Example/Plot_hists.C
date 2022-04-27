#include <stdio.h>
#include <math.h>

void Plot_hists(){


	TString inputFileName = "histograms.root";

	TString outputFileName = "plots.root";

	TFile* inputFile = TFile::Open(inputFileName);

	TFile* outputFile = new TFile(outputFileName, "recreate");

	outputFile -> cd();

	TString histName = "h_Z_mass";

	TString histCloneName = histName;

	histCloneName += 1;

	TH1D* histClone = (TH1D *) inputFile->Get(histCloneName);

	TH1D * h_Bckgd = (TH1D *) histClone->Clone("h_Bckgd");

	TH1D * h_light_Bckgd = (TH1D *) histClone->Clone("h_light_Bckgd");

	TH1D * h_bb_Bckgd = (TH1D *) histClone->Clone("h_bb_Bckgd");


	h_bb_Bckgd->Reset();

	h_light_Bckgd->Reset();

	h_Bckgd->Reset();

	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 45};

	for( int n: b){

		TString histName_N = histName;
		histName_N += n;

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

	for( int n: b){

		TString histNamelightflav_N = histNamelightflav;
		histNamelightflav_N += n;

		TH1D* hist_lightn = (TH1D *) inputFile->Get(histNamelightflav_N);
		h_light_Bckgd->Add(hist_lightn);

	}

	for( int n: b){

		TString histNamebb_N = "h_Dijet_Mass_bb";
		histNamebb_N += n;

		TH1D* hist_bbn = (TH1D *) inputFile->Get(histNamebb_N);
		h_bb_Bckgd->Add(hist_bbn);

	}




	outputFile->cd();

	h_light_Bckgd->Write();

	h_bb_Bckgd->Write();

	h_W_mass->SetName("h_W_mass");

	h_ttbar->SetName("h_ttbar");

	h_Sig->SetName("h_Sig");

	h_Bckgd->Write();

	h_ttbar->Write();

	h_W_mass->Write("h_W_mass");

	h_Sig->Write("h_Sig");

	/*TCanvas* c = new TCanvas("c", "c", 800, 600);

	h_Sig->Draw();

	h_Sig->Print();

	h_Bckgd->Draw();
	
	h_Bckgd->Print();

	c->SaveAs("h_Sig.pdf");
	*/

	outputFile->Close();

	return 0;

}