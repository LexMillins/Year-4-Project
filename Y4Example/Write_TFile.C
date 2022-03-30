#include <stdio.h>
#include <math.h>


void Write_TFile(){


	// Create a new TFile to store hist objects

	TString outputFileName = "histograms.root";

	TFile * outputFile = new TFile(outputFileName, "recreate");

	outputFile -> cd();

	// Histogram creation here


	// Get histogram

	TString histName = "h_Z_mass";


	// Define luminosity for weighting

	const double lumi = 36.1e3; // pb^-1


	// Create map

	std::map<int,TFile*>map_file;
	std::map<int, TH1D*> map_hist;
	std::map<int,TFile*>map_file_sig;
	std::map<int, TH1D*> map_hist_sig;


	std::map<int, int>map_files_N;


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


	map_file[363356] = TFile::Open("files_363356.root");
	map_file[363358] = TFile::Open("files_363358.root");



	map_files_N[364100] = 1;
	map_files_N[364101] = 2;
	map_files_N[364102] = 3;
	map_files_N[364103] = 4;
	map_files_N[364104] = 5;
	map_files_N[364105] = 6;
	map_files_N[364106] = 7;
	map_files_N[364107] = 8;
	map_files_N[364108] = 9;
	map_files_N[364109] = 10;
	map_files_N[364110] = 11;

	map_files_N[364111] = 12;
	map_files_N[364112] = 13;
	map_files_N[364113] = 14;
	map_files_N[364114] = 15;
	map_files_N[364115] = 16;
	map_files_N[364116] = 17;
	map_files_N[364117] = 18;
	map_files_N[364118] = 19;
	map_files_N[364119] = 20;
	map_files_N[364120] = 21;

	map_files_N[364121] = 22;
	map_files_N[364122] = 23;
	map_files_N[364123] = 24;
	map_files_N[364124] = 25;
	map_files_N[364125] = 26;
	map_files_N[364126] = 27;
	map_files_N[364127] = 28;
	map_files_N[364128] = 29;
	map_files_N[364129] = 30;
	map_files_N[364130] = 31;

	map_files_N[364131] = 32;
	map_files_N[364132] = 33;
	map_files_N[364133] = 34;
	map_files_N[364134] = 35;
	map_files_N[364135] = 36;
	map_files_N[364136] = 37;
	map_files_N[364137] = 38;
	map_files_N[364138] = 39;
	map_files_N[364139] = 40;
	map_files_N[364140] = 41;

	map_files_N[364141] = 42;

	map_files_N[410472] = 43;

	map_files_N[363356] = 44;
	map_files_N[363358] = 45;


	// Get histograms

	for (std::map<int, TFile*>::iterator it = map_file.begin(); it != map_file.end(); it++){

		std::cout<< it->first << ':' << it->second << std::endl;

		map_hist[it->first] = (TH1D*) (it->second)->Get(histName);

		TString newhistName = histName;

		newhistName += map_files_N[it->first];

		// Perform lumi*xs/sumw scaling
		TH1D* h_weight_track = (TH1D*) (it->second)->Get("h_weight_track");
		TH1D* h_xs_track = (TH1D*) (it->second)->Get("h_xs_track");

		// Undo the artificial growth of xs due to nFiles
		const double xs = h_xs_track->GetBinContent(1)/h_xs_track->GetEntries();

		const double sumw = h_weight_track->GetBinContent(1);

		std::cout << "DSID = " << map_hist[it->first] << ", xs = " << xs << " pb" << std::endl;

		const double scale_factor = lumi*xs/sumw;

		map_hist[it->first]->Scale(scale_factor);

		outputFile -> cd();

		// Write histograms here 

		map_hist[it->first]->SetName(newhistName);

		map_hist[it->first]->Write(newhistName);


	}

	outputFile -> Close();


	return 0;

}