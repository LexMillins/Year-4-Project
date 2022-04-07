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

	h_Bckgd->Reset();

	int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 45};

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

	outputFile->cd();

	h_W_mass->SetName("h_W_mass");

	h_Sig->SetName("h_Sig");

	h_Bckgd->Write();

	h_W_mass->Write("h_W_mass");

	h_Sig->Write("h_Sig");

	TCanvas* c = new TCanvas("c", "c", 800, 600);

	h_W_mass->Draw();
	
	h_W_mass->Print();

	c->SaveAs("h_W_mass.pdf");

	outputFile->Close();

	return 0;

}