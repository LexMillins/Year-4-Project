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

	TString histNamejet1pT = "h_jet1_pt";

	TH1D* h_jet1_pt = (TH1D*) inputFile->Get(histNamejet1pT);

	TString histNamejet2pT = "h_jet2_pt";

	TH1D* h_jet2_pt = (TH1D*) inputFile->Get(histNamejet2pT);

	TString histNamedilep = "h_dilepton_mass";

	TH1D* h_dilepton_mass = (TH1D*) inputFile->Get(histNamedilep);

	TString histNamediboson = "h_diboson_mass";

	TH1D* h_diboson_mass = (TH1D*) inputFile->Get(histNamediboson);

	TString histNamehadpt = "h_hadronic_boson_pt";

	TH1D* h_hadronic_boson_pt = (TH1D*) inputFile->Get(histNamehadpt);

	TString histNameleppt = "h_leptonic_boson_pt";

	TH1D* h_leptonic_boson_pt = (TH1D*) inputFile->Get(histNameleppt);

	outputFile->cd();

	histZ->SetName("h_Z_mass");

	histZ->Write("h_Z_mass");

	h_jet1_pt->Write();

	h_jet2_pt->Write();

	h_dilepton_mass->Write();

	h_diboson_mass->Write();

	h_hadronic_boson_pt->Write();

	h_leptonic_boson_pt->Write();

	TCanvas* c = new TCanvas("c", "c", 800, 600);

	histZ->Draw();
	
	histZ->Print();

	c->SaveAs("h_Z_mass.pdf");

	outputFile->Close();

	return 0;

}