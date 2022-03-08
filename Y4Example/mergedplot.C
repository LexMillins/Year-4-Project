#include <stdio.h>
#include <math.h>


void Plot_File_Components() {


	TString histName = "h_Dijet_Mass";

	TString histNameSig = "h_Z_mass";


	std::map<int,TFile*>map_file;
	std::map<int, TH1D*> map_hist;
	std::map<int,TFile*>map_file_sig;
	std::map<int, TH1D*> map_hist_sig;
	std::map<int,TFile*>map_file_Zjets;
	std::map<int, TH1D*> map_hist_Zjets;
	std::map<int,TFile*>map_file_ttbar;
	std::map<int, TH1D*> map_hist_ttbar;


	map_file_Zjets[1] = TFile::Open("Z+jets.root");
	map_file_ttbar[1] = TFile::Open("ttbar.root");
	map_file_Signal[1] = TFile::Open("Signal.root");
	


for (std::map<int, TFile*>::iterator it=map_file_Zjets.begin(); it != map_file_Zjets.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_Zjets[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_Zjets[it->first] << std::endl;


} 


for (std::map<int, TFile*>::iterator it=map_file_ttbar.begin(); it != map_file_ttbar.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_ttbar[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_ttbar[it->first] << std::endl;
}



for (std::map<int, TFile*>::iterator it=map_file_Signal.begin(); it != map_file_Signal.end(); it++){

	std::cout<< it->first << ':' << it->second << std::endl;

	map_hist_Signal[it->first] = (TH1D*) (it->second)->Get(histNameSig);

	std::cout << map_hist_Signal[it->first] << std::endl;
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


		TH1D* h_Sum_Sig = (TH1D*) map_hist_Signal[1]->Clone("h_Sum_Sig");
		h_Sum_Sig->Reset();

		TH1D* h_Sum_Zjets = (TH1D*) map_hist_Signal[1]->Clone("h_Sum_Zjets");
		h_Sum_Zjets->Reset();

		TH1D* h_Sum_ttbar = (TH1D*) map_hist_Signal[1]->Clone("h_Sum_ttbar");
		h_Sum_ttbar->Reset();






	for (std::map < int, TH1D*>::iterator it=map_hist_Signal.begin(); it != map_hist_Signal.end(); it++){
		h_Sum_Sig->Add(map_hist_Signal[it->first]);
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
