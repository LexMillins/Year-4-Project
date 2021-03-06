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


void Plot_Prelim() {

	TString histName = "h_DiLepton_Mass";

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

	map_file[410472] = TFile::Open("Output_410472.root");


	map_file[363356] = TFile::Open("Output_363356.root");
	map_file[363358] = TFile::Open("Output_363358.root");




for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist[it->first] = (TH1D*) (it->second)->Get(histName);

	std::cout << map_hist[it->first] << std::endl;


}

	TH1D* h_Sum = (TH1D*) map_hist[364100]->Clone("h_Sum");
	h_Sum->Reset();

for (std::map < int, TH1D*>::iterator it=map_hist.begin(); it != map_hist.end(); it++){
	
	h_Sum->Add(map_hist[it->first]);
}


	TCanvas* c = new TCanvas("c","c",800,600);

	h_Sum->Draw();


return 0;

}