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

/*Double_t background(Double_t *x, Double_t *par){
    return par[0] + par[1]*x[0] + par[2]*x[0]*x[0];
}

Double_t lorentzianPeak(Double_t *x, Double_t *par){
    return (0.5*par[0]*par[1]/TMath::Pi()) / TMath::Max(1.e-10,
    (x[0]-par[2])*(x[0]-par[2])+ .25*par[1]*par[1]);
}

Double_t fitFunction(Double_t background, Double_t lorentzianPeak){

	background(x, par) + lorentzianPeak(x,&par[3]);

}
*/

void merge_plot_sum() {

//h_CosThetaHel
//h_nJet
//h_LeptonAsymmetry
//h_JetAsymmetry

	//TString histName = "h_CosThetaHel";
	TString histName = "h_Z_mass";

///TString histName = "h_LeptonAsymmetry";



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

	map_file[410472] = TFile::Open("files_410472.root");


	map_file_sig[363356] = TFile::Open("files_363356.root");
	map_file_sig[363358] = TFile::Open("files_363358.root");


	std::map<int,int> map_nFiles;

	map_nFiles[364100] = 1;
	map_nFiles[364101] = 1;
	map_nFiles[364102] = 3;
	map_nFiles[364103] = 1;
	map_nFiles[364104] = 1;
	map_nFiles[364105] = 4;
	map_nFiles[364106] = 1;
	map_nFiles[364107] = 1;
	map_nFiles[364108] = 3;
	map_nFiles[364109] = 1;
	map_nFiles[364110] = 1;

	map_nFiles[364111] = 2;
	map_nFiles[364112] = 1;
	map_nFiles[364113] = 1;
	map_nFiles[364114] = 1;
	map_nFiles[364115] = 1;
	map_nFiles[364116] = 3;
	map_nFiles[364117] = 1;
	map_nFiles[364118] = 1;
	map_nFiles[364119] = 3;
	map_nFiles[364120] = 1;

	map_nFiles[364121] = 1;
	map_nFiles[364122] = 4;
	map_nFiles[364123] = 1;
	map_nFiles[364124] = 1;
	map_nFiles[364125] = 2;
	map_nFiles[364126] = 1;
	map_nFiles[364127] = 1;
	map_nFiles[364128] = 1;
	map_nFiles[364129] = 1;
	map_nFiles[364130] = 2;

	map_nFiles[364131] = 1;
	map_nFiles[364132] = 1;
	map_nFiles[364133] = 2;
	map_nFiles[364134] = 1;
	map_nFiles[364135] = 1;
	map_nFiles[364136] = 2;
	map_nFiles[364137] = 1;
	map_nFiles[364138] = 1;
	map_nFiles[364139] = 2;
	map_nFiles[364140] = 1;

	map_nFiles[364141] = 1;

	map_nFiles[410472] = 15;

	map_nFiles[363356] = 3;
	map_nFiles[363358] = 4;



for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist[it->first] = (TH1D*) (it->second)->Get(histName);

	map_hist[it->first] -> Scale(1.0/map_nFiles[it->first]);

	std::cout << map_hist[it->first] << std::endl;


}


for (std::map<int, TFile*>::iterator it=map_file_sig.begin(); it != map_file_sig.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_sig[it->first] = (TH1D*) (it->second)->Get(histName);

	map_hist_sig[it->first] -> Scale(1.0/map_nFiles[it->first]);

	std::cout << map_hist_sig[it->first] << std::endl;


} 


	TH1D* h_Sum = (TH1D*) map_hist[364100]->Clone("h_Sum");
	h_Sum->Reset();

for (std::map < int, TH1D*>::iterator it=map_hist.begin(); it != map_hist.end(); it++){
	h_Sum->Add(map_hist[it->first]);



}

	//TF1 *fitFcn = new TF1("fitFcn",fitFunction,0,3,6);

	TCanvas* c = new TCanvas("c","c",800,600);

	h_Sum->SetTitle("Invariant Mass of dijet");

	//h_Sum->Fit(fitFunction);

	h_Sum->Draw();



//map_hist_sig[363356]->Draw("SAME");
//map_hist_sig[363358]->Draw("SAME");

//map_hist_sig[363356]->SetLineColor(kRed);
//map_hist_sig[363358]->SetLineColor(kGreen);

//map_hist_sig[363356]->Scale(100);
//map_hist_sig[363358]->Scale(100);


const double mass_peak = 91.2; // [GeV]
const double mass_sigma = 18.0; // 1 sigma [GeV]


int bin_low = map_hist_sig[363356]->FindBin(mass_peak - 2.0*mass_sigma);
int bin_high = map_hist_sig[363356]->FindBin(mass_peak + 2.0*mass_sigma);


std::cout<< "bin_low =" << bin_low << std::endl;
std::cout<< "bin_high =" << bin_high << std::endl;


float b = h_Sum->Integral(bin_low,bin_high);
float sz = map_hist_sig[363356]->Integral(bin_low,bin_high);
float sw = map_hist_sig[363358]->Integral(bin_low,bin_high);

std::cout<< "number of background events = " << b << std::endl;
std::cout<< "number of Z signal events = " << sz << std::endl;
std::cout<< "number of w signal events = " << sw << std::endl;

float Fz = fig_of_merit(sz, b);
float Fw = fig_of_merit(sw, b);
std::cout<< "Fz = " << Fz << std::endl;
//std::cout<< "Fw = " << Fw << std::endl;





return 0;

}
