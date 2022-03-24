#include <stdio.h>
#include <math.h>


void mergeplot_File_Components() {


	TString histName = "h_Dijet_Mass";

	TString histNameSig = "h_Z_mass";

	const double lumi = 36.1e3; // pb^-1

	std::map<int,TFile*>map_file;
	std::map<int, TH1D*> map_hist;
	std::map<int,TFile*>map_file_sig;
	std::map<int, TH1D*> map_hist_sig;
	std::map<int,TFile*>map_file_Zjets;
	std::map<int, TH1D*> map_hist_Zjets;
	std::map<int,TFile*>map_file_ttbar;
	std::map<int, TH1D*> map_hist_ttbar;


	map_file_Zjets[364100] = TFile::Open("files_364100.root");
	map_file_Zjets[364101] = TFile::Open("files_364101.root");
	map_file_Zjets[364102] = TFile::Open("files_364102.root");
	map_file_Zjets[364103] = TFile::Open("files_364103.root");
	map_file_Zjets[364104] = TFile::Open("files_364104.root");
	map_file_Zjets[364105] = TFile::Open("files_364105.root");
	map_file_Zjets[364106] = TFile::Open("files_364106.root");
	map_file_Zjets[364107] = TFile::Open("files_364107.root");
	map_file_Zjets[364108] = TFile::Open("files_364108.root");
	map_file_Zjets[364109] = TFile::Open("files_364109.root");
	map_file_Zjets[364110] = TFile::Open("files_364110.root");

	map_file_Zjets[364111] = TFile::Open("files_364111.root");
	map_file_Zjets[364112] = TFile::Open("files_364112.root");
	map_file_Zjets[364113] = TFile::Open("files_364113.root");
	map_file_Zjets[364114] = TFile::Open("files_364114.root");
	map_file_Zjets[364115] = TFile::Open("files_364115.root");
	map_file_Zjets[364116] = TFile::Open("files_364116.root");
	map_file_Zjets[364117] = TFile::Open("files_364117.root");
	map_file_Zjets[364118] = TFile::Open("files_364118.root");
	map_file_Zjets[364119] = TFile::Open("files_364119.root");
	map_file_Zjets[364120] = TFile::Open("files_364120.root");

	map_file_Zjets[364121] = TFile::Open("files_364121.root");
	map_file_Zjets[364122] = TFile::Open("files_364122.root");
	map_file_Zjets[364123] = TFile::Open("files_364123.root");
	map_file_Zjets[364124] = TFile::Open("files_364124.root");
	map_file_Zjets[364125] = TFile::Open("files_364125.root");
	map_file_Zjets[364126] = TFile::Open("files_364126.root");
	map_file_Zjets[364127] = TFile::Open("files_364127.root");
	map_file_Zjets[364128] = TFile::Open("files_364128.root");
	map_file_Zjets[364129] = TFile::Open("files_364129.root");
	map_file_Zjets[364130] = TFile::Open("files_364130.root");

	map_file_Zjets[364131] = TFile::Open("files_364131.root");
	map_file_Zjets[364132] = TFile::Open("files_364132.root");
	map_file_Zjets[364133] = TFile::Open("files_364133.root");
	map_file_Zjets[364134] = TFile::Open("files_364134.root");
	map_file_Zjets[364135] = TFile::Open("files_364135.root");
	map_file_Zjets[364136] = TFile::Open("files_364136.root");
	map_file_Zjets[364137] = TFile::Open("files_364137.root");
	map_file_Zjets[364138] = TFile::Open("files_364138.root");
	map_file_Zjets[364139] = TFile::Open("files_364139.root");
	map_file_Zjets[364140] = TFile::Open("files_364140.root");

	map_file_Zjets[364141] = TFile::Open("files_364141.root");


	map_file_ttbar[410472] = TFile::Open("files_410472.root"); //ttbar

	map_file_sig[363356] = TFile::Open("files_363356.root");
	map_file_sig[363358] = TFile::Open("files_363358.root");



for (std::map<int, TFile*>::iterator it=map_file_sig.begin(); it != map_file_sig.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_sig[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_sig[it->first] << std::endl;

	// Perform lumi*xs/sumw scaling
	TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
	TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

	// Undo the artificial growth of xs due to nFiles
	const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

	const double sumw = h_weight_track->GetBinContent(1);

	std::cout << "DSID = " << map_hist_sig[it->first] << ", xs = " << xs << " pb" << std::endl;

	const double scale_factor = lumi*xs/sumw;

	map_hist_sig[it->first]->Scale(scale_factor);


} 


for (std::map<int, TFile*>::iterator it=map_file_Zjets.begin(); it != map_file_Zjets.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_Zjets[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_Zjets[it->first] << std::endl;

	// Perform lumi*xs/sumw scaling
	TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
	TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

	// Undo the artificial growth of xs due to nFiles
	const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

	const double sumw = h_weight_track->GetBinContent(1);

	std::cout << "DSID = " << map_hist_Zjets[it->first] << ", xs = " << xs << " pb" << std::endl;

	const double scale_factor = lumi*xs/sumw;

	map_hist_Zjets[it->first]->Scale(scale_factor);
}



for (std::map<int, TFile*>::iterator it=map_file_ttbar.begin(); it != map_file_ttbar.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_ttbar[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_ttbar[it->first] << std::endl;

	// Perform lumi*xs/sumw scaling
	TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
	TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

	// Undo the artificial growth of xs due to nFiles
	const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

	const double sumw = h_weight_track->GetBinContent(1);

	std::cout << "DSID = " << map_hist_ttbar[it->first] << ", xs = " << xs << " pb" << std::endl;

	const double scale_factor = lumi*xs/sumw;

	map_hist_ttbar[it->first]->Scale(scale_factor);
}



	std::map<TString, TH1D*> h_Sum_Flavs;

	vector<TString> flav_combs;

	//Flavour combinations to loop through

	flav_combs.push_back("ll");
	flav_combs.push_back("lc");
	flav_combs.push_back("lb");

	flav_combs.push_back("cl");
	flav_combs.push_back("cc");
	flav_combs.push_back("cb");

	flav_combs.push_back("bl");
	flav_combs.push_back("bc");
	flav_combs.push_back("bb");


		TH1D* h_Sum_Sig = (TH1D*) map_hist_sig[363356]->Clone("h_Sum_Sig");
		h_Sum_Sig->Reset();

		TH1D* h_Sum_Zjets = (TH1D*) map_hist_sig[363356]->Clone("h_Sum_Zjets");
		h_Sum_Zjets->Reset();

		TH1D* h_Sum_ttbar = (TH1D*) map_hist_sig[363356]->Clone("h_Sum_ttbar");
		h_Sum_ttbar->Reset();






	for (std::map < int, TH1D*>::iterator it=map_hist_sig.begin(); it != map_hist_sig.end(); it++){
		h_Sum_Sig->Add(map_hist_sig[it->first]);
	}

	for (std::map < int, TH1D*>::iterator it=map_hist_Zjets.begin(); it != map_hist_Zjets.end(); it++){
		h_Sum_Zjets->Add(map_hist_Zjets[it->first]);
	}

	for (std::map < int, TH1D*>::iterator it=map_hist_ttbar.begin(); it != map_hist_ttbar.end(); it++){
		h_Sum_ttbar->Add(map_hist_ttbar[it->first]);
	}




	//TF1 *fitFcn = new TF1("fitFcn",fitFunction,0,3,6);

	TCanvas* c = new TCanvas("c","c",900,600);

	 h_Sum_Sig->SetFillColor(kCyan);
	 h_Sum_Sig->SetFillStyle(1001);

	 h_Sum_Zjets->SetFillColor(kMagenta+2);
 	 h_Sum_Zjets->SetFillStyle(1001);


	 h_Sum_ttbar->SetFillColor(kGreen-6);
	 h_Sum_ttbar->SetFillStyle(1001);





	 THStack *h_Stack = new THStack("h_Stack","");

	 	h_Stack->Add(h_Sum_Sig);
	 	h_Stack->Add(h_Sum_ttbar);
	 	h_Stack->Add(h_Sum_Zjets);

		h_Stack->Draw("HIST");
		h_Stack->SetTitle("Invariant Mass, 2 jets tagged tight");
		h_Stack->GetXaxis()->SetTitle("Dijet Mass [GeV]");
 		h_Stack->GetYaxis()->SetTitle("Events / [GeV]");



		auto legend = new TLegend(0.5,0.7,0.5, 0.7);
	   legend->SetHeader("Z Flavour combinations","C"); // option "C" allows to center the header
	   legend->AddEntry(h_Sum_Sig,"Signal","f");
	   legend->AddEntry(h_Sum_ttbar,"ttbar","f");
	   legend->AddEntry(h_Sum_Zjets,"Z + jets","f");


	   legend->Draw();


return 0;

}