#include <stdio.h>
#include <math.h>


void Write_MadGraph_TFile(){


	// Create a new TFile to store hist objects

	TString outputFileName = "MadGraphHists.root";

	TFile * outputFile = new TFile(outputFileName, "recreate");

	outputFile -> cd();

	// Histogram creation here


	// Get histogram

	TString histName = "h_Z_mass";

	TString histNameb = "h_Dijet_Mass_bb";

	TString histNameflav = "h_Dijet_Mass";

	TString histNamejet1pT = "h_jet1_pt";

	TString histNamejet2pT = "h_jet2_pt";

	TString histNamedilepmass = "h_dilepton_mass";

	TString histNamediboson = "h_diboson_mass";

	TString histNamehadpT = "h_hadronic_boson_pt";

	TString histNameleppT = "h_leptonic_boson_pt";


	// Define luminosity for weighting

	const double lumi = 36.1e3; // pb^-1


	// Create map

	std::map<int,TFile*>map_file;

	std::map<int, TH1D*> map_hist;

	std::map<int, TH1D*> map_histb;

	std::map<int, TH1D*> map_histjet1pT;

	std::map<int, TH1D*> map_histjet2pT;

	std::map<int, TH1D*> map_histdilepmass;

	std::map<int, TH1D*> map_histdiboson;

	std::map<int, TH1D*> map_histhadpT;

	std::map<int, TH1D*> map_histleppT;

	std::map<int, TH1D*> map_histflav;

	std::map<int,TFile*>map_file_sig;

	std::map<int, TH1D*> map_hist_sig;

	std::map<int, int>map_files_N;



	map_file[363125] = TFile::Open("files_363125.root");
	map_file[363128] = TFile::Open("files_363128.root"); 
	map_file[363131] = TFile::Open("files_363131.root");
	map_file[363134] = TFile::Open("files_363134.root");
	map_file[363137] = TFile::Open("files_363137.root"); 
	map_file[363140] = TFile::Open("files_363140.root");
	map_file[363143] = TFile::Open("files_363143.root"); 
	map_file[363146] = TFile::Open("files_363146.root"); 

	// Zee 
	map_file[363149] = TFile::Open("files_363149.root"); 
	map_file[363152] = TFile::Open("files_363152.root");
	map_file[363155] = TFile::Open("files_363155.root");
	map_file[363158] = TFile::Open("files_363158.root");
	map_file[363161] = TFile::Open("files_363161.root"); 
	map_file[363164] = TFile::Open("files_363164.root");
	map_file[363167] = TFile::Open("files_363167.root");
	map_file[363170] = TFile::Open("files_363170.root");

	map_file[410472] = TFile::Open("files_410472.root");


	map_file[363356] = TFile::Open("files_363356.root");
	map_file[363358] = TFile::Open("files_363358.root");





	map_files_N[410472] = 43;

	map_files_N[363356] = 44;
	map_files_N[363358] = 45;

	map_files_N[363125] = 46;
	map_files_N[363128] = 47;
	map_files_N[363131] = 48;
	map_files_N[363134] = 49;
	map_files_N[363137] = 50;
	map_files_N[363140] = 51;
	map_files_N[363143] = 52;
	map_files_N[363146] = 53;

	// Zee 
	map_files_N[363149] = 54;
	map_files_N[363152] = 55;
	map_files_N[363155] = 56;
	map_files_N[363158] = 57;
	map_files_N[363161] = 58;
	map_files_N[363164] = 59;
	map_files_N[363167] = 60;
	map_files_N[363170] = 63;

	// Get histograms

	for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

		std::cout<< it->first << ':' << it->second << std::endl;

		map_hist[it->first] = (TH1D*) (it->second)->Get(histName);
		map_histb[it->first] = (TH1D*) (it->second)->Get(histNameb);
		map_histflav[it->first] = (TH1D*) (it->second)->Get(histNameflav);
		map_histjet1pT[it->first] = (TH1D*) (it->second)->Get(histNamejet1pT);
		map_histjet2pT[it->first] = (TH1D*) (it->second)->Get(histNamejet2pT);
		map_histdilepmass[it->first] = (TH1D*) (it->second)->Get(histNamedilepmass);
		map_histdiboson[it->first] = (TH1D*) (it->second)->Get(histNamediboson);
		map_histhadpT[it->first] = (TH1D*) (it->second)->Get(histNamehadpT);
		map_histleppT[it->first] = (TH1D*) (it->second)->Get(histNameleppT);


		TString newhistName = histName;

		newhistName += map_files_N[it->first];

		TString newhistNameb = histNameb;

		newhistNameb += map_files_N[it->first];		

		TString newhistNameflav = histNameflav;

		newhistNameflav += map_files_N[it->first];

		TString newhistNamejet1 = histNamejet1pT;

		newhistNamejet1 += map_files_N[it->first];

		TString newhistNamejet2 = histNamejet2pT;

		newhistNamejet2 += map_files_N[it->first];

		TString newhistNamedilepmass = histNamedilepmass;

		newhistNamedilepmass += map_files_N[it->first];

		TString newhistNamediboson = histNamediboson;

		newhistNamediboson += map_files_N[it->first];

		TString newhistNamehadpT = histNamehadpT;

		newhistNamehadpT += map_files_N[it->first];

		TString newhistNameleppT = histNameleppT;

		newhistNameleppT += map_files_N[it->first];


		// Perform lumi*xs/sumw scaling
		TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
		TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

		// Undo the artificial growth of xs due to nFiles
		const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

		const double sumw = h_weight_track->GetBinContent(1);

		std::cout << "DSID = " << map_hist[it->first] << ", xs = " << xs << " pb" << std::endl;

		const double scale_factor = lumi*xs/sumw;

		map_hist[it->first]->Scale(scale_factor);

		map_histb[it->first]->Scale(scale_factor);

		map_histjet1pT[it->first]->Scale(scale_factor);

		map_histjet2pT[it->first]->Scale(scale_factor);

		map_histdilepmass[it->first]->Scale(scale_factor);

		map_histdiboson[it->first]->Scale(scale_factor);

		map_histhadpT[it->first]->Scale(scale_factor);

		map_histleppT[it->first]->Scale(scale_factor);

		outputFile -> cd();

		// Write histograms here 

		map_hist[it->first]->SetName(newhistName);

		map_hist[it->first]->Write(newhistName);

		map_histb[it->first]->SetName(newhistNameb);

		map_histb[it->first]->Write(newhistNameb);

		map_histjet1pT[it->first]->SetName(newhistNamejet1);
		
		map_histjet1pT[it->first]->Write();
		
		map_histjet2pT[it->first]->SetName(newhistNamejet2);

		map_histjet2pT[it->first]->Write();

		map_histdilepmass[it->first]->SetName(newhistNamedilepmass);

		map_histdilepmass[it->first]->Write();

		map_histdiboson[it->first]->SetName(newhistNamediboson);

		map_histdiboson[it->first]->Write();

		map_histhadpT[it->first]->SetName(newhistNamehadpT);

		map_histhadpT[it->first]->Write();

		map_histleppT[it->first]->SetName(newhistNameleppT);

		map_histleppT[it->first]->Write();





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

	for(int f=0; f<flav_combs.size(); ++f){

		TH1D* h_Sum = (TH1D*) map_hist[363358]->Clone("h_Sum_"+flav_combs.at(f));
		h_Sum->Reset();

		h_Sum_Flavs[flav_combs.at(f)] = h_Sum;

	}



	for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

		std::cout<< it->first << ':' << it->second << std::endl;

		for(int f=0; f<flav_combs.size(); ++f){

			TH1D* h_Contrib = (TH1D*) (it->second)->Get(histNameflav+"_"+flav_combs.at(f));

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


		TString histNamelightflav = "h_light_flav";

		TH1D* h_light_flav = (TH1D*) map_histb[363358]->Clone("h_light_flav");

		h_light_flav->Reset();

		for(int f=0; f<flav_combs.size(); ++f){

			h_light_flav->Add(h_Sum_Flavs[flav_combs.at(f)]);

		}

		TString newhistNamelightflav = histNamelightflav;

		newhistNamelightflav += map_files_N[it->first];		


		outputFile -> cd();

		// Write histograms here 

		h_light_flav->SetName(newhistNamelightflav);

		h_light_flav->Write(newhistNamelightflav);

	}

	outputFile -> Close();


	outputFile -> Close();


	return 0;

}