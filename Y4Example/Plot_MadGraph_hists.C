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

	h_Bckgd->Reset();

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



	outputFile->cd();

	h_W_mass->SetName("h_W_mass");

	h_ttbar->SetName("h_ttbar");

	h_Sig->SetName("h_Sig");

	h_Bckgd->Write();

	h_W_mass->Write("h_W_mass");

	h_ttbar->Write();

	h_Sig->Write("h_Sig");


	outputFile->Close();

	return 0;

}