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



//function to sort TLorentzVectors by transverse momentum
bool sortby_pt(const TLorentzVector &lhs, const TLorentzVector &rhs){
	return lhs.Pt() > rhs.Pt();
}



int main(int argc, char* argv[]) {


	// DSID -> cross-section [pb]

  	crossSection[361108] = 1950.632;
   crossSection[361107] = 1950.632;
	crossSection[410501] = 452.2944528; //  "ttbar"
   crossSection[361106] = 1950.529;

	crossSection[410472] = 87.71741;

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
	//TString dsidName = argv[2];

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
	outputFileName += ".root";;

	std::cout << "outputFileName = " << outputFileName << std::endl;

	TFile* outputFile = new TFile(outputFileName,"recreate");

	outputFile->cd();

	TH1D* h_DiMuon_Mass = new TH1D("h_DiMuon_Mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_DiElectron_Mass = new TH1D("h_DiElectron_mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_Dijet_mass = new TH1D("h_Dijet_Mass", ";Mass [GeV]; Events/GeV",30,0,300);

	TH1D* h_Di_Boson_Mass = new TH1D("h_Di_Boson_Mass", "; Mass [GeV]; Events /GeV", 70, 50, 750);

	TH1D* h_Z_pt_lep = new TH1D("h_Z_pt_lep", ";pt [GeV]; Events /GeV", 16, 0, 500);

	TH1D* h_Boson_jets_pt = new TH1D("h_Boson_jets_pt", ";pt [GeV]; Events /GeV", 25, 0, 500);

	TH1D* h_DiBoson_Pt = new TH1D("h_DiBoson_Pt", ";pt [GeV]; Events /GeV", 25, 0, 500);

	//TH1D* h_Boson_pseudorap = new TH1D("h_Boson_psuedorap", "psuedorapidity; Events /GeV", 100, 0, 500);

	//TH1D* h_Boson_phi = new TH1D("h_Boson_phi", "phi; Events /GeV", 100, 0, 500);

	TH1D* h_lep_pseudorap = new TH1D("h_lep_pseudorap", ";psuedorapidity; Events /GeV", 40, 0, 50);

	TH1D* h_jet_pseudorap = new TH1D("h_jet_psedorap", ";psuedorapidity; Events/GeV", 60, 0, 50);

	TH1D* h_lep_phi = new TH1D("h_lep_phi", ";phi [rad]; Events/GeV", 25, 0, 10);

	TH1D* h_jet_phi = new TH1D("h_jet_phi", ";phi [rad]; Events/GeV", 25, 0, 10);

	TH1D* h_angle_between_lep = new TH1D("h_angle_between_lep", ";Theta [rad]; Events/GeV", 100, 0 , 10);

	TH1D* h_angle_between_jets = new TH1D("h_angle_between_jets", ";Theta [rad]; Events/GeV", 50, 0, 10); 

	TH1D * h_jet_rapidity = new TH1D("h_jet_rapidity", ";Rapidity, y; Events/GeV", 20, 0, 5);

	TH1D* h_lep_rapidity = new TH1D("h_lep_rapidity", ";Rapidity, y; Events/GeV", 30, 0, 5);

	TH1D* h_jet2_pt = new TH1D("h_jet2_pt", ";pT [GeV]; Events/GeV", 100, 0, 500);

	TH1D* h_CosThetaHel = new TH1D("h_CosThetaHel", ";cos(#theta_{Hel.}); Events/", 100, -1.0, 1.0);

	TH1D* h_CosThetaHel2 = new TH1D("h_CosThetaHel2", ";cos(#theta_{Hel.}); Events/", 100, -1.0, 1.0);

	TH1D* h_nJet = new TH1D("h_nJet", "; n. Jet; Events/", 10,0,10);

	TH1D* h_LeptonAsymmetry = new TH1D("h_LeptonAsymmetry", "; [p_{T}^{l1}-p_{T}^{l2}]/[p_{T}^{l1}+p_{T}^{l2}]; Events/", 100,0,1.0);

	TH1D* h_JetAsymmetry = new TH1D("h_JetAsymmetry", "; [p_{T}^{l1}-p_{T}^{l2}]/[p_{T}^{l1}+p_{T}^{l2}]; Events/", 100,0,1.0);

	TH1D* h_CosThetaHel_had = new TH1D("h_CosThetaHel_had", ";cos(#theta_{Hel.}); Events/", 100, -1.0, 0.5);

	TH1D* h_CosThetaHel2_had = new TH1D("h_CosThetaHel2_had", ";cos(#theta_{Hel.}); Events/", 100, -1.0, 0.0);


	// Event loop

	const int nEvents = r->fChain->GetEntries();

	std::cout << "Events to process = " << nEvents << std::endl;

	// Event Loop
	for(int n = 0; n < nEvents; ++n) {

		if(n%10000 == 0) std::cout << "Event " << n << std::endl;


		r->GetEntry(n);

		// Find Scale Factor for each event

		const double weight_mc = r->weight_mc;


		const double weight = weight_mc * S;

		if (r->jet_pt->size() <2 ){

			continue;
		}

		std::vector<TLorentzVector> my_jets;
		TLorentzVector dijet;
		TLorentzVector jetj;

		for( int j = 0; j <(r->jet_pt->size()); ++j){


			jetj.SetPtEtaPhiE(r->jet_pt->at(j)*1e-3, r->jet_eta->at(j), r->jet_phi->at(j), r->jet_e->at(j)*1e-3);

			my_jets.push_back(jetj);

		}


		std::sort(my_jets.begin(), my_jets.end(),sortby_pt);
		double angle_between_jets;
		TLorentzVector jet1;
		TLorentzVector jet2;
		double jet1_rapidity;
		double jet2_rapidity;

		//print_vect_TLor(my_jets);

		if(my_jets.size() >= 2){


			
			dijet = my_jets.at(0) + my_jets.at(1);
			
			if( dijet.M() < 50){
				continue;
			}
			if(dijet.M() > 160){
				continue;
			}

			jet1 = my_jets.at(0);
			jet2 = my_jets.at(1);

			//if( jet2.Pt() > 80){

			//continue;
			//}

			angle_between_jets = jet1.Angle(jet2.Vect()); 

			//if(angle_between_jets > 2.2){

			//	continue;
			//}

			if( (jet1.Pt() < 40) && (jet2.Pt() < 33)){

				continue;
			}


			jet1_rapidity = jet1.Rapidity();
			jet2_rapidity = jet2.Rapidity();


			h_jet2_pt->Fill(jet2.Pt(),weight);
			h_jet_rapidity->Fill(jet1_rapidity, weight);
			h_jet_rapidity->Fill(jet2_rapidity, weight);
			h_angle_between_jets->Fill(angle_between_jets, weight);
			h_Dijet_mass->Fill(dijet.M(),weight);
			h_Boson_jets_pt->Fill(dijet.Pt(),weight);
			h_jet_pseudorap->Fill(dijet.Eta(), weight);
			h_jet_phi->Fill(dijet.Phi(), weight);

			// Fill histogram with weighted values

		}
		std::vector<TLorentzVector> muon_vector;
		std::vector<TLorentzVector> electron_vector;
		TLorentzVector dielectron;
		TLorentzVector dimuon;
		Double_t angle_between_muons;
		Double_t angle_between_electrons;
		TLorentzVector muon1;
		TLorentzVector muon2;
		TLorentzVector elec1;
		TLorentzVector elec2;

		TLorentzVector lepton1;
		TLorentzVector lepton2;


		if( r->mu_pt->size() >= 2) {


			for( int k = 0; k<(r->mu_pt->size()); ++k){
				TLorentzVector muon;

				muon.SetPtEtaPhiM(r->mu_pt->at(k)*1e-3,r->mu_eta->at(k),r->mu_phi->at(k),105.67e-3);
				muon_vector.push_back(muon);

			}
			std::sort(muon_vector.begin(), muon_vector.end(), sortby_pt);


			dimuon = muon_vector.at(0) + muon_vector.at(1);

			muon1 = muon_vector.at(0);
			muon2 = muon_vector.at(1);

			if(muon1.Pt() < 25){

				continue;
			}

			angle_between_muons = muon1.Angle(muon2.Vect());

			/*if(angle_between_muons < 1){

				continue;
			}
*/
			//if(angle_between_muons > 5){
			//	continue;
			//}

			if(fabs(muon1.Rapidity()) > 2.5){
				continue;
			}
			
			if(fabs(muon2.Rapidity()) > 2.5){
				continue;
			}

			lepton1 = muon1;
			lepton2 = muon2;

			h_lep_rapidity->Fill(muon1.Rapidity(), weight);
			h_lep_rapidity->Fill(muon2.Rapidity(), weight);
			h_angle_between_lep->Fill(angle_between_muons, weight);
			h_DiMuon_Mass->Fill(dimuon.M(),weight);
			h_Z_pt_lep->Fill(dimuon.Pt(),weight);
			h_lep_pseudorap->Fill(dimuon.Eta(), weight);
			h_lep_phi->Fill(dimuon.Phi(), weight); 

		}


		else if ( r->el_pt->size() >= 2){

			for(int j = 0; j<(r->el_pt->size()); ++j){
				TLorentzVector elec;

				elec.SetPtEtaPhiM(r->el_pt->at(j)*1e-3,r->el_eta->at(j),r->el_phi->at(j),0.511e-3);
				electron_vector.push_back(elec);

			}

			std::sort(electron_vector.begin(), electron_vector.end(), sortby_pt);


			
			dielectron = electron_vector.at(0) + electron_vector.at(1);

			elec1 = electron_vector.at(0);

			if(elec1.Pt() < 25){

				continue;
			}

			elec2 = electron_vector.at(1);
			angle_between_electrons = elec2.Angle(elec1.Vect());

		/*	if(angle_between_electrons < 1){

				continue;
			}
*/
			//if(angle_between_electrons > 5){

				//continue;
			//}


			if(fabs(elec1.Rapidity()) > 2.5){
				continue;
			}

			if(fabs(elec2.Rapidity()) > 2.5){
				continue;
			}

			lepton1 = elec1;
			lepton2 = elec2;


			h_angle_between_lep->Fill(angle_between_electrons, weight);


			h_lep_rapidity->Fill(elec1.Rapidity(), weight);
			h_lep_rapidity->Fill(elec2.Rapidity(), weight);
			h_DiElectron_Mass->Fill(dielectron.M(),weight);
			h_Z_pt_lep->Fill(dielectron.Pt(),weight);
			h_lep_pseudorap->Fill(dielectron.Eta(), weight);
			h_lep_phi->Fill(dielectron.Phi(), weight);

		}

		
		TLorentzVector dilepton = lepton1 + lepton2;

		// Copy lepton 4-vectors
		TLorentzVector lepton1_rest = lepton1;
		TLorentzVector lepton2_rest = lepton2;
		TLorentzVector jet2_rest = lepton2;
		TLorentzVector jet1_rest = lepton1;
		TLorentzVector dilepton_rest = dilepton;

		TLorentzVector dijet_rest = dijet;

		// Boost into di-lepton (Z) rest frame
		lepton1_rest.Boost( -1.0*dilepton.BoostVector() );
		lepton2_rest.Boost( -1.0*dilepton.BoostVector() );
		dijet_rest.Boost( -1.0*dilepton.BoostVector() );

		// Boost into hadronic V rest frame
		jet1_rest.Boost( -1.0*dijet.BoostVector() );
		jet2_rest.Boost( -1.0*dijet.BoostVector() );
		dilepton_rest.Boost( -1.0*dijet.BoostVector() );

		double cosThetaHel_had = cos( jet1_rest.Angle(dilepton_rest.Vect()) );

		double cosThetaHel2_had = cos( jet1_rest.Angle(dijet_rest.Vect()) );

		// Helicity angle
		double cosThetaHel = cos( lepton1_rest.Angle(dijet_rest.Vect()) );

		double cosThetaHel2 = cos( lepton1_rest.Angle(dilepton.Vect()) );

		h_CosThetaHel->Fill(cosThetaHel,weight);
		h_CosThetaHel2->Fill(cosThetaHel2,weight);
		h_CosThetaHel_had->Fill(cosThetaHel_had, weight);
		h_CosThetaHel2_had->Fill(cosThetaHel2_had, weight);

		const double asym_lep =  ( lepton1.Pt() - lepton2.Pt() ) / ( lepton1.Pt() + lepton2.Pt() );
		const double asym_jet =  ( jet1.Pt() - jet2.Pt() ) / ( jet1.Pt() + jet2.Pt() );



		TLorentzVector diZ;
		if( dijet.Pt() != 0){

			if (dimuon.Pt() !=0){
				diZ = dijet + dimuon;     	
			}

			else if (dielectron.Pt() !=0){

				diZ = dijet + dielectron;
			}

		}


		h_Di_Boson_Mass->Fill(diZ.M(),weight);
		h_DiBoson_Pt->Fill(diZ.Pt(),weight);
		//h_Boson_pseudorap->Fill(diZ.Eta());
		//h_Boson_phi->Fill(diZ.Phi());

		h_nJet->Fill(r->jet_pt->size(),weight);

		h_LeptonAsymmetry->Fill(asym_lep,weight);
		h_JetAsymmetry->Fill(asym_jet,weight);

	} // Event Loop



	// Write histogram to output file

	outputFile->cd();

	h_DiMuon_Mass->Write();
	h_DiElectron_Mass->Write();
	h_Dijet_mass->Write();
	h_Di_Boson_Mass->Write();
	h_Z_pt_lep->Write();
	h_Boson_jets_pt->Write();
	h_DiBoson_Pt->Write();
	//h_Boson_pseudorap->Write();
	//h_Boson_phi->Write();
	h_lep_pseudorap->Write();
	h_lep_phi->Write();
	h_jet_pseudorap->Write();
	h_jet_phi->Write();
	h_angle_between_jets->Write();
	h_angle_between_lep->Write();
	h_jet_rapidity->Write();
	h_lep_rapidity->Write();
	h_jet2_pt->Write();

	h_CosThetaHel->Write();
	h_CosThetaHel2->Write();

	h_CosThetaHel2_had->Write();
	h_CosThetaHel_had->Write();


	h_nJet->Write();
	h_LeptonAsymmetry->Write();
	h_JetAsymmetry->Write();


	outputFile->Close();



	std::cout << "Tidy Up..." << std::endl;

	delete r;

	std::cout << "Done Analysis!" << std::endl;

	return 0;
} 