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


void plot_all_flav() {


	TString histName = "h_Dijet_Mass";

	TString histNameSig = "h_Z_mass";


	std::map<int,TFile*>map_file;
	std::map<int, TH1D*> map_hist;
	std::map<int,TFile*>map_file_sig;
	std::map<int, TH1D*> map_hist_sig;


	map_file[364100] = TFile::Open("Output_364100.root");
	map_file[364101] = TFile::Open("Output_364101.root");
	map_file[364102] = TFile::Open("Output_364102.root");
	map_file[364103] = TFile::Open("Output_364103.root");
	map_file[364104] = TFile::Open("Output_364104.root");
	map_file[364105] = TFile::Open("Output_364105.root");
	map_file[364106] = TFile::Open("Output_364106.root");
	map_file[364107] = TFile::Open("Output_364107.root");
	map_file[364108] = TFile::Open("Output_364108.root");
	map_file[364109] = TFile::Open("Output_364109.root");
	map_file[364110] = TFile::Open("Output_364110.root");

	map_file[364111] = TFile::Open("Output_364111.root");
	map_file[364112] = TFile::Open("Output_364112.root");
	map_file[364113] = TFile::Open("Output_364113.root");
	map_file[364114] = TFile::Open("Output_364114.root");
	map_file[364115] = TFile::Open("Output_364115.root");
	map_file[364116] = TFile::Open("Output_364116.root");
	map_file[364117] = TFile::Open("Output_364117.root");
	map_file[364118] = TFile::Open("Output_364118.root");
	map_file[364119] = TFile::Open("Output_364119.root");
	map_file[364120] = TFile::Open("Output_364120.root");

	map_file[364121] = TFile::Open("Output_364121.root");
	map_file[364122] = TFile::Open("Output_364122.root");
	map_file[364123] = TFile::Open("Output_364123.root");
	map_file[364124] = TFile::Open("Output_364124.root");
	map_file[364125] = TFile::Open("Output_364125.root");
	map_file[364126] = TFile::Open("Output_364126.root");
	map_file[364127] = TFile::Open("Output_364127.root");
	map_file[364128] = TFile::Open("Output_364128.root");
	map_file[364129] = TFile::Open("Output_364129.root");
	map_file[364130] = TFile::Open("Output_364130.root");

	map_file[364131] = TFile::Open("Output_364131.root");
	map_file[364132] = TFile::Open("Output_364132.root");
	map_file[364133] = TFile::Open("Output_364133.root");
	map_file[364134] = TFile::Open("Output_364134.root");
	map_file[364135] = TFile::Open("Output_364135.root");
	map_file[364136] = TFile::Open("Output_364136.root");
	map_file[364137] = TFile::Open("Output_364137.root");
	map_file[364138] = TFile::Open("Output_364138.root");
	map_file[364139] = TFile::Open("Output_364139.root");
	map_file[364140] = TFile::Open("Output_364140.root");

	map_file[364141] = TFile::Open("Output_364141.root");


	map_file[410472] = TFile::Open("Output_410472.root"); //ttbar


	map_file[363356] = TFile::Open("Output_363356.root"); //ZZ
	map_file[363358] = TFile::Open("Output_363358.root"); //WZ


	map_file_sig[363356] = TFile::Open("Output_363356.root");
	map_file_sig[363358] = TFile::Open("Output_363358.root");



for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist[it->first] = (TH1D*) (it->second)->Get(histName+"_ll");

	std::cout << map_hist[it->first] << std::endl;


}

std::cout<< "----------------------------------------------signal" << std::endl;


for (std::map<int, TFile*>::iterator it=map_file_sig.begin(); it != map_file_sig.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_sig[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_sig[it->first] << std::endl;


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


			std::cout << h_Contrib << std::endl;

			h_Sum_Flavs[flav_combs.at(f)]->Add(h_Contrib);

		}


	}


	//TF1 *fitFcn = new TF1("fitFcn",fitFunction,0,3,6);

	TCanvas* c = new TCanvas("c","c",900,600);

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


 		map_hist_sig[363356]->Draw("SAME");
	 	map_hist_sig[363356]->SetLineColor(kOrange+1);
	 	map_hist_sig[363356]->Scale(10);


		auto legend = new TLegend(0.55,0.49,0.9, 0.9);
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


 		/*TH1D* h_sig = (TH1D*) map_hist_sig[363356]->Clone("h_sig");
 		h_sig->Reset();
 		h_sig->Add(map_hist_sig[363356]);
	 	map_hist_sig[363356]->SetLineColor(kRed);
	 	map_hist_sig[363356]->Scale(100);


 		h_sig->Draw("SAME"); */

return 0;

}
