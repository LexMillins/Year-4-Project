#include <stdio.h>
#include <math.h>

void Plot_hists(){


	TString inputFileName = "histograms.root";

	TString outputFileName = "plots.root";

	TFile * inputFile = TFile::Open(inputFileName);

	TFile * outputFile = new TFile(outputFileName, "recreate");

	outputFile -> cd();

	TString histName = "h_Z_mass";

	TString histCloneName = histName;

	histCloneName+= ";1";

	TH1D* histClone = inputFile->Get(histName);

	TH1D * h_Bckgd = histClone->Clone("h_Bckgd");

	h_Bckgd->Reset();

	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};

	for( int n: a){

		TString histName_n = histName=+ ";";
		histName_n += n; 

		TH1D* hist_n = inputFile->Get(histName_n);
		h_Bckgd->Add(hist_n);
	}






	return 0;

}