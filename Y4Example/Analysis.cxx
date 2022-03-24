#include "Analysis.h"
#include <algorithm>
#include <dirent.h>


//print function for vectors of float
void print_vect_float(std::vector <float> const &a) {
   std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++){
   std::cout << a.at(i) << std::endl;
   }
}


//print function for Pt in vectors of TLorentzVectors
void print_vect_TLor(std::vector <TLorentzVector> const &b) {
   std::cout << "The vector elements are : ";
 
   for(int i=0; i < b.size(); i++){
   std::cout << b.at(i).Pt() << std::endl;
   }
}


//print function for a vector of pairs
void print_vect_pair(std::vector< std::pair<int,double>> const &b) {
   std::cout << "The vector elements are : ";
 
   for(int i=0; i < b.size(); i++){
   std::cout << b.at(i).first << std::endl;
   std::cout << b.at(i).second << std::endl;
   }
}



//function to sort TLorentzVectors by transverse momentum
bool sortby_pt(const TLorentzVector &lhs, const TLorentzVector &rhs){
	return lhs.Pt() > rhs.Pt();
}

//Function to sort pairs by their second element
bool sort_pair(const std::pair<int,double> &lhs, const std::pair<int,double> &rhs){
	return lhs.second > rhs.second;
}


// Need to make a function to create histograms. Will take the quark flavour and property being plotted and return a histogram with a name h_quarkflavour_property

TH1D* write_hist(TString flavour, TString property, TString axes, int bins, int start, int end){

	//hist name is h_(append property)_(append flavour)

	TString hist_name = "h_";
	hist_name += property;
	hist_name += "_";
	hist_name += flavour;

	TH1D* h = new TH1D(hist_name,axes,bins,start,end);
	return h;

	//should return histogram when function is called so that it can be filled

}

int main(int argc, char* argv[]) {


	// DSID -> cross-section [pb]

   crossSection[361108] = 1950.632; //Z+jets
   crossSection[361107] = 1950.632; //Z+jets
   crossSection[410501] = 452.2944528; //  "ttbar"
   crossSection[361106] = 1950.529; //Z+jets

   crossSection[410472] = 87.71741; //ttbar

   crossSection[363356] = 2.18227464; //  "ZZ"
   crossSection[363358] = 3.433; //  "WZ"

   //Zmumu

   crossSection[364100] =  1588.66746389;
   crossSection[364101] =  219.465881813;
   crossSection[364102] =  126.881010892;
   crossSection[364103] =  73.4175295308;
   crossSection[364104] =  20.6122362812;
   crossSection[364105] =  12.5960346435;
   crossSection[364106] =  23.7652919679;
   crossSection[364107] =  9.14987883537;
   crossSection[364108] =  6.12043965702;
   crossSection[364109] =  4.65594981299;
   crossSection[364110] =  2.21715064245;
   crossSection[364111] =  1.46733700049;
   crossSection[364112] =  1.74182113;
   crossSection[364113] =  0.143963764;

   // Zee

   crossSection[364114] = 1587.09608;
   crossSection[364115] = 220.385164;
   crossSection[364116] = 127.09156;
   crossSection[364117] = 74.899987;
   crossSection[364118] = 20.136631;
   crossSection[364119] = 12.896334;
   crossSection[364120] = 24.466238;
   crossSection[364121] = 9.235908;
   crossSection[364122] = 6.082048;
   crossSection[364123] = 4.764969;
   crossSection[364124] = 2.249123;
   crossSection[364125] = 1.492287;
   crossSection[364126] = 1.764736;
   crossSection[364127] = 0.144997;

   // Ztautau

   crossSection[364128] = 1587.275594;
   crossSection[364129] = 210.751398;
   crossSection[364130] = 127.095425;
   crossSection[364131] = 74.667167;
   crossSection[364132] = 20.50304;
   crossSection[364133] = 11.961862;
   crossSection[364134] = 24.591492;
   crossSection[364135] = 9.297514;
   crossSection[364136] = 6.199607;
   crossSection[364137] = 4.758765;
   crossSection[364138] = 2.243734;
   crossSection[364139] = 1.49179;
   crossSection[364140] = 1.762883;
   crossSection[364141] = 0.144539;

   crossSection[361107] =  1950.6321;

   // Zmumu

   crossSection[363123] = 1627.05549938;
   crossSection[363124] = 212.234137612;
   crossSection[363125] = 115.867239676;
   crossSection[363126] = 69.3063656744;
   crossSection[363127] = 16.7738146771;
   crossSection[363128] = 10.4410415888;
   crossSection[363129] = 27.6014492698;
   crossSection[363130] = 8.17763119439;
   crossSection[363131] = 5.16031502231;
   crossSection[363132] = 5.87007931406;
   crossSection[363133] = 2.12860741152;
   crossSection[363134] = 1.33177380798;
   crossSection[363135] = 0.864774186115;
   crossSection[363136] = 0.360773876232;
   crossSection[363137] = 0.220740938418;
   crossSection[363138] = 0.287942570138;
   crossSection[363139] = 0.133775886529;
   crossSection[363140] = 0.08110283909;
   crossSection[363141] = 0.093795915954;
   crossSection[363142] = 0.044430101856;
   crossSection[363143] = 0.028714102038;
   crossSection[363144] = 0.003493780443;
   crossSection[363145] = 0.001813103676;
   crossSection[363146] = 0.001105508894;

    // Zee

   crossSection[363147] = 1634.592133;
   crossSection[363148] = 213.155455;
   crossSection[363149] = 118.312407;
   crossSection[363150] = 69.771049;
   crossSection[363151] = 17.160109;
   crossSection[363152] = 11.002726;
   crossSection[363153] = 27.695231;
   crossSection[363154] = 8.372705;
   crossSection[363155] = 5.430767;
   crossSection[363156] = 5.897428;
   crossSection[363157] = 2.172475;
   crossSection[363158] = 1.41238;
   crossSection[363159] = 0.871643;
   crossSection[363160] = 0.367826;
   crossSection[363161] = 0.234049;
   crossSection[363162] = 0.293262;
   crossSection[363163] = 0.135603;
   crossSection[363164] = 0.086362;
   crossSection[363165] = 0.09762;
   crossSection[363166] = 0.049845;
   crossSection[363167] = 0.032079;
   crossSection[363168] = 0.003461;
   crossSection[363169] = 0.00199;
   crossSection[363170] = 0.00127;

    // Ztautau

   crossSection[361510] = 1723.1984;
   crossSection[361511] = 260.5064;
   crossSection[361512] = 82.794096;
   crossSection[361513] = 22.929984;
   crossSection[361514] = 8.941117;



	std::cout << "Starting Analysis!" << std::endl;

	// Input Analysis, File Name, DSID

	TString inputFileName = argv[1];
	TString inputFileNumber = argv[2];

	//int dsid_int = dsidName.Atoi();

	std::cout << "Opening: " << inputFileName  << std::endl;


	// Open the file and setup the reader class

	TFile* inputFile = TFile::Open(inputFileName);


	// Get event tree
	TTree* tree = (TTree*) inputFile->Get("nominal");

	Reader* r = new Reader(tree);

	// Get weight tree
	TTree* tree_w = (TTree*) inputFile->Get("sumWeights");

	WeightReader* r_w = new WeightReader(tree_w);



	// Work out our normalisation factor "S"


	int dsid_temp = 0;


	double sumW = 0.0;

	for(unsigned int i = 0; i < tree_w->GetEntries(); ++i) {


		r_w->GetEntry(i);

		sumW += r_w->totalEventsWeighted;

		if(i == 0) dsid_temp = r_w->dsid;


	}


	const double lumi = 36.1e3; // pb^-1
	const double xs = crossSection[dsid_temp]; // pb


	std::cout << "DSID: " << dsid_temp  << std::endl;
	std::cout << "Cross-section = " << crossSection[dsid_temp]  << " pb " << std::endl;



	std::cout << "Normalisation ingredients..."  << std::endl;
	std::cout << "Lumi = " << lumi  << std::endl;
	std::cout << "sigma = " << xs  << std::endl;
	std::cout << "sumW = " << sumW  << std::endl;

	const double S = lumi*xs/sumW;

	std::cout << "Scale Factor = " << S  << std::endl;



	// Setup an output ROOT file to store histograms

	TString outputFileName = "Output_";
	outputFileName += dsid_temp;
	outputFileName += "_";
	outputFileName += inputFileNumber; 
	outputFileName += ".root";

	std::cout << "outputFileName = " << outputFileName << std::endl;

	TFile* outputFile = new TFile(outputFileName,"recreate");

	outputFile->cd();

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
	
	//map

	std::map<TString, TH1D*> h_Coll_Dijet_Mass;



	// Create histograms

	for(int f=0; f<flav_combs.size(); ++f){

		h_Coll_Dijet_Mass[flav_combs.at(f)] = write_hist(flav_combs.at(f), "Dijet_Mass", ";Mass [GeV]; Events/GeV", 50, 0, 300);
		

	}

	//-----------------------------------
	// Special histogram for bookkeeping of weights
	//-----------------------------------
	TH1D* h_weight_track = new TH1D("h_weight_track", ";arb.; weights", 1, 0, 1);
	h_weight_track->Fill(0.5,sumW);
	TH1D* h_xs_track = new TH1D("h_xs_track", ";arb.; weights", 1, 0, 1);
	h_xs_track->Fill(0.5,xs);
	//-----------------------------------

	TH1D* h_jet1_pt = new TH1D("h_jet1_pt", ";pT [GeV]; Events/GeV", 30, 0, 300);

	TH1D* h_jet2_pt = new TH1D("h_jet2_pt", ";pT [GeV]; Events/GeV", 30, 0, 300);

	TH1D* h_Z_mass = new TH1D("h_Z_mass", ";Invariant Mass [GeV]; Events/GeV", 50, 0, 300);

	TH1D* h_angle_between_jets = new TH1D("h_angle_between_jets", ";Theta [rad]; Events/GeV", 10, 0, 1); 


	// Event loop

	const int nEvents = r->fChain->GetEntries();

	std::cout << "Events to process = " << nEvents << std::endl;

	// Event Loop
	for(int n = 0; n < nEvents; ++n) {

		if(n%10000 == 0) std::cout << "Event " << n << std::endl;


		r->GetEntry(n);

		// Find Scale Factor for each event

		const double weight_mc = r->weight_mc;


		//const double weight = weight_mc * S;
		const double weight = weight_mc; // Don't apply lumi*XS factor anymore, do later

		// require 2 jets and 2 leptons in each event

		if (r->jet_pt->size() <2 ){

			continue;
		}

		if (r->el_pt->size() < 2 && r->mu_pt->size() < 2) {
			continue;
		}

		std::vector<TLorentzVector> my_jets;
		std::vector<TLorentzVector> DL1_jets;
		TLorentzVector dijet;
		TLorentzVector dijet1_3;
		TLorentzVector jeti;
		TLorentzVector jetj;
		double DL1;
		int flavour;
		vector<TLorentzVector> light_jets;
		vector<TLorentzVector> b_jets;
		vector<TLorentzVector> c_jets;
		vector<TLorentzVector> taus;
		float jet1_pt;


		std::vector< std::pair<int,double> > jet_index_DL1;
		std::pair<int, double> temp;


		// Create pairs of index, DL1 discriminant

		for( int j = 0; j <(r->jet_pt->size()); ++j){


			jetj.SetPtEtaPhiE(r->jet_pt->at(j), r->jet_eta->at(j), r->jet_phi->at(j), r->jet_e->at(j));

			DL1 = r->jet_DL1->at(j);

			//record truth flavour of jets (MC only)
			flavour = r->jet_truthflav->at(j);


			temp.first = j;
			temp.second = DL1;

			jet_index_DL1.push_back(temp);


		}


	// Sort by b-tag	
		
	std::sort(jet_index_DL1.begin(), jet_index_DL1.end(),sort_pair);


	for(unsigned int i = 0; i < jet_index_DL1.size(); ++i ) {

		const unsigned int index = jet_index_DL1.at(i).first;

		//std::cout << jet_index_DL1.at(i).first << " " << jet_index_DL1.at(i).second << std::endl;

		//create 4-vectors using the original index

		jeti.SetPtEtaPhiE(r->jet_pt->at(index), r->jet_eta->at(index), r->jet_phi->at(index), r->jet_e->at(index));

		my_jets.push_back(jeti);

	}

	//Create dijet using the sorted jet - 2 highest DL1 values




	TLorentzVector jet1 = my_jets.at(0);

	int jet1_flavour = r->jet_truthflav->at(jet_index_DL1.at(0).first);

	TLorentzVector jet2 = my_jets.at(1);

	int jet2_flavour = r->jet_truthflav->at(jet_index_DL1.at(1).first);

	
	//Use truth information to determine flavour of jet for plotting (MC only)

	TString flav_pair = "";


	if(jet1_flavour == 0 || jet1_flavour == 15) { flav_pair += "l"; }
	if(jet1_flavour == 4) { flav_pair += "c"; }
	if(jet1_flavour == 5) { flav_pair += "b"; }

	if(jet2_flavour == 0 || jet2_flavour == 15) { flav_pair += "l"; }
	if(jet2_flavour == 4) { flav_pair += "c"; }
	if(jet2_flavour == 5) { flav_pair += "b"; }





	float jet1_DL1 = jet_index_DL1.at(0).second; 

	float jet2_DL1 = jet_index_DL1.at(1).second;

	float jet1_Pt = jet1.Pt();

	float jet2_Pt = jet2.Pt();

	// b-tag requirement

	if(jet1_DL1 < 2.02){
		continue;
	}
	if(jet2_DL1 < 2.02){
		continue;
	}

	dijet = my_jets.at(0) + my_jets.at(1);


	// Fill histograms

	h_Coll_Dijet_Mass[flav_pair]->Fill(dijet.M()*1e-3,weight);

	h_Z_mass->Fill(dijet.M()*1e-3, weight);

	h_jet1_pt->Fill(jet1.Pt()*1e-3, weight);

	h_jet2_pt->Fill(jet2.Pt()*1e-3, weight);



} //Event Loop

//Write histograms
	outputFile->cd();

	//write histograms here


	for(int f=0; f<flav_combs.size(); ++f){

		h_Coll_Dijet_Mass[flav_combs.at(f)] ->Write();

	}
	h_Z_mass->Write();

	h_jet1_pt->Write();

	h_jet2_pt->Write();

	h_weight_track->Write();

	h_xs_track->Write();


	outputFile->Close();


	std::cout << "Tidy Up..." << std::endl;

	delete r;

	std::cout << "Done Analysis!" << std::endl;

	return 0;

}