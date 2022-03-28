
#include <stdio.h>
#include <math.h>


float fig_of_merit(float &s, float &b){
	// a function that returns the Number of signal events
	//over the square root of the number of background events
	//provides a figure of merit for cuts

	float f;
	f = s/sqrt(b);
	return f;

}


void mergeplot_flav() {


	TString histName = "h_Dijet_Mass";

	TString histNameSig = "h_Z_mass";

	const double lumi = 36.1e3; // pb^-1


	std::map<int,TFile*>map_file;
	std::map<int, TH1D*> map_hist;
	std::map<int,TFile*>map_file_sig;
	std::map<int, TH1D*> map_hist_sig;


	map_file[364100] = TFile::Open("files_364100.root");
	map_file[364101] = TFile::Open("files_364101.root");
	map_file[364102] = TFile::Open("files_364102.root");
	map_file[364103] = TFile::Open("files_364103.root");
	map_file[364104] = TFile::Open("files_364104.root");
	map_file[364105] = TFile::Open("files_364105.root");
	map_file[364106] = TFile::Open("files_364106.root");
	map_file[364107] = TFile::Open("files_364107.root");
	map_file[364108] = TFile::Open("files_364108.root");
	map_file[364109] = TFile::Open("files_364109.root");
	map_file[364110] = TFile::Open("files_364110.root");

	map_file[364111] = TFile::Open("files_364111.root");
	map_file[364112] = TFile::Open("files_364112.root");
	map_file[364113] = TFile::Open("files_364113.root");
	map_file[364114] = TFile::Open("files_364114.root");
	map_file[364115] = TFile::Open("files_364115.root");
	map_file[364116] = TFile::Open("files_364116.root");
	map_file[364117] = TFile::Open("files_364117.root");
	map_file[364118] = TFile::Open("files_364118.root");
	map_file[364119] = TFile::Open("files_364119.root");
	map_file[364120] = TFile::Open("files_364120.root");

	map_file[364121] = TFile::Open("files_364121.root");
	map_file[364122] = TFile::Open("files_364122.root");
	map_file[364123] = TFile::Open("files_364123.root");
	map_file[364124] = TFile::Open("files_364124.root");
	map_file[364125] = TFile::Open("files_364125.root");
	map_file[364126] = TFile::Open("files_364126.root");
	map_file[364127] = TFile::Open("files_364127.root");
	map_file[364128] = TFile::Open("files_364128.root");
	map_file[364129] = TFile::Open("files_364129.root");
	map_file[364130] = TFile::Open("files_364130.root");

	map_file[364131] = TFile::Open("files_364131.root");
	map_file[364132] = TFile::Open("files_364132.root");
	map_file[364133] = TFile::Open("files_364133.root");
	map_file[364134] = TFile::Open("files_364134.root");
	map_file[364135] = TFile::Open("files_364135.root");
	map_file[364136] = TFile::Open("files_364136.root");
	map_file[364137] = TFile::Open("files_364137.root");
	map_file[364138] = TFile::Open("files_364138.root");
	map_file[364139] = TFile::Open("files_364139.root");
	map_file[364140] = TFile::Open("files_364140.root");

	map_file[364141] = TFile::Open("files_364141.root");


	map_file[410472] = TFile::Open("files_410472.root"); //ttbar


	map_file[363356] = TFile::Open("files_363356.root"); //ZZ
	map_file[363358] = TFile::Open("files_363358.root"); //WZ




for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist[it->first] = (TH1D*) (it->second)->Get(histName+"_ll");

	// Perform lumi*xs/sumw scaling
	TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
	TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

	// Undo the artificial growth of xs due to nFiles
	const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

	const double sumw = h_weight_track->GetBinContent(1);

	std::cout << "DSID = " << map_hist[it->first] << ", xs = " << xs << " pb" << std::endl;

	const double scale_factor = lumi*xs/sumw;

	map_hist[it->first]->Scale(scale_factor);


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

	for(int f=0; f<flav_combs.size(); ++f){

		TH1D* h_Sum = (TH1D*) map_hist[363356]->Clone("h_Sum_"+flav_combs.at(f));
		h_Sum->Reset();

		h_Sum_Flavs[flav_combs.at(f)] = h_Sum;

	}



	for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

		std::cout<< it->first << ':' << it->second << std::endl;

		for(int f=0; f<flav_combs.size(); ++f){

			TH1D* h_Contrib = (TH1D*) (it->second)->Get(histName+"_"+flav_combs.at(f));

			// Perform lumi*xs/sumw scaling
			TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
			TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

			// Undo the artificial growth of xs due to nFiles
			const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

			const double sumw = h_weight_track->GetBinContent(1);

			std::cout << "DSID = " << map_hist[it->first] << ", xs = " << xs << " pb" << std::endl;

			const double scale_factor = lumi*xs/sumw;

			h_Contrib->Scale(scale_factor);

			h_Sum_Flavs[flav_combs.at(f)]->Add(h_Contrib);


		}


	}


	TCanvas* c = new TCanvas("c","c");

	 h_Sum_Flavs["ll"]->SetFillColor(kGray);

	 h_Sum_Flavs["lc"]->SetFillColor(kOrange);

	 h_Sum_Flavs["lb"]->SetFillColor(kBlue);

	 h_Sum_Flavs["cl"]->SetFillColor(kRed);

	 h_Sum_Flavs["cc"]->SetFillColor(kAzure+1);

	 h_Sum_Flavs["cb"]->SetFillColor(kViolet-6);
	 h_Sum_Flavs["bl"]->SetFillColor(kGreen);
	 h_Sum_Flavs["bc"]->SetFillColor(kPink+10);
	 h_Sum_Flavs["bb"]->SetFillColor(kGreen+3);



	 THStack *h_Stack = new THStack("h_Stack","");


		for(int f=0; f<flav_combs.size(); ++f){

			h_Sum_Flavs[flav_combs.at(f)]->SetFillStyle(1001);

			h_Stack->Add(h_Sum_Flavs[flav_combs.at(f)]);
		}

		h_Stack->Draw("HIST");
		h_Stack->SetTitle("Invariant Mass, 2 jets tagged tight");
		h_Stack->GetXaxis()->SetTitle("Dijet Mass [GeV]");
 		h_Stack->GetYaxis()->SetTitle("Events / [GeV]");


 		map_hist[363356]->Draw("SAME");
	 	map_hist[363356]->SetLineColor(kOrange+1);
	 	map_hist[363356]->Scale(10);


		auto legend = new TLegend(0.65,0.49,0.9, 0.9);
	   legend->SetHeader("Z Flavour combinations","C"); // option "C" allows to center the header
	   legend->AddEntry(h_Sum_Flavs["ll"],"light light jets","f");
	   legend->AddEntry(h_Sum_Flavs["lc"],"light charm jets","f");
	   legend->AddEntry(h_Sum_Flavs["lb"],"light bottom jets","f");

	   legend->AddEntry(h_Sum_Flavs["cl"],"charm light jets","f");
	   legend->AddEntry(h_Sum_Flavs["cc"],"charm charm jets","f");
	   legend->AddEntry(h_Sum_Flavs["cb"],"charm bottom jets","f");

	   legend->AddEntry(h_Sum_Flavs["bl"],"bottom light jets","f");
	   legend->AddEntry(h_Sum_Flavs["bc"],"bottom charm jets","f");
	   legend->AddEntry(h_Sum_Flavs["bb"],"bottom bottom jets","f");



	   legend->Draw();

return 0;

}