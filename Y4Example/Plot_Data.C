#include <stdio.h>
#include <math.h>

void Plot_Data(){


	TString inputFileName = "data_total_13TeV_Output.root";

	TString outputFileName = "data_total_hists.root";

	TFile* inputFile = TFile::Open(inputFileName);

	TFile* outputFile = new TFile(outputFileName, "recreate");

	outputFile -> cd();

	TString histName = "h_Z_mass";

	TH1D* histZ = (TH1D *) inputFile->Get(histName);


	outputFile->cd();

	histZ->SetName("h_Z_mass");

	histZ->Write("h_Z_mass");

	TCanvas* c = new TCanvas("c", "c", 800, 600);

	histZ->Draw();
	
	histZ->Print();

	c->SaveAs("h_Z_mass.pdf");

	outputFile->Close();

	return 0;

}