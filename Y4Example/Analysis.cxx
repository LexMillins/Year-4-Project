#include "Analysis.h"
#include <algorithm>


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

	std::cout << "Starting Analysis!" << std::endl;




	// Open the file and setup the reader class

	TFile* inputFile = TFile::Open("WZ.root");

	TTree* tree = (TTree*) inputFile->Get("nominal");

	Reader* r = new Reader(tree);


	// Setup an output ROOT file to store histograms

	TFile* outputFile = new TFile("output.root","recreate");

	outputFile->cd();

	TH1D* h_DiMuon_Mass = new TH1D("h_DiMuon_Mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_DiElectron_Mass = new TH1D("h_DiElectron_mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_Dijet_mass = new TH1D("h_Dijet_Mass", ";Mass [GeV]; Events/GeV",100,0,300);

	TH1D* h_DiZ_mass = new TH1D("h_DiZ_Mass", "; Mass [GeV]; Events /GeV", 100, 50, 750);

	TH1D* h_Z_pt_lep = new TH1D("h_Z_pt_lep", ";pt [GeV]; Events /GeV", 100, 20, 500);

	TH1D* h_Z_jets_pt = new TH1D("h_Z_jets_pt", ";pt [GeV]; Events /GeV", 100, 10, 500);

	TH1D* h_DiZ_Pt = new TH1D("h_DiZ_Pt", ";pt [GeV]; Events /GeV", 100, 20, 500);



	// Event loop

	const int nEvents = r->fChain->GetEntries();

	std::cout << "Events to process = " << nEvents << std::endl;

	// Event Loop
	for(int n = 0; n < nEvents; ++n) {

		if(n%10000 == 0) std::cout << "Event " << n << std::endl;


		r->GetEntry(n);


		std::vector<TLorentzVector> my_jets;
		TLorentzVector dijet;
		TLorentzVector jetj;



		for( int j = 0; j <(r->jet_pt->size()); ++j){


			jetj.SetPtEtaPhiE(r->jet_pt->at(j)*1e-3, r->jet_eta->at(j), r->jet_phi->at(j), r->jet_e->at(j)*1e-3);

			my_jets.push_back(jetj);

		}


		std::sort(my_jets.begin(), my_jets.end(),sortby_pt);

		//print_vect_TLor(my_jets);

		if(my_jets.size() >= 2){
			
			dijet = my_jets.at(0) + my_jets.at(1);

			h_Dijet_mass->Fill(dijet.M());



		}
		std::vector<TLorentzVector> muon_vector;
		std::vector<TLorentzVector> electron_vector;
		TLorentzVector dielectron;
		TLorentzVector dimuon;

		if( r->mu_pt->size() >= 2) {


			for( int k = 0; k<(r->mu_pt->size()); ++k){
				TLorentzVector muon;

				muon.SetPtEtaPhiM(r->mu_pt->at(k)*1e-3,r->mu_eta->at(k),r->mu_phi->at(k),105.67e-3);
				muon_vector.push_back(muon);

			}
			std::sort(muon_vector.begin(), muon_vector.end(), sortby_pt);

			dimuon = muon_vector.at(0) + muon_vector.at(1);
			h_DiMuon_Mass->Fill(dimuon.M());


		}


		else if ( r->el_pt->size() >= 2){

			for(int j = 0; j<(r->el_pt->size()); ++j){
				TLorentzVector elec;

				elec.SetPtEtaPhiM(r->el_pt->at(j)*1e-3,r->el_eta->at(j),r->el_phi->at(j),0.511e-3);
				electron_vector.push_back(elec);

			}

			std::sort(electron_vector.begin(), electron_vector.end(), sortby_pt);
			
			dielectron = electron_vector.at(0) + electron_vector.at(1);

			h_DiElectron_Mass->Fill(dielectron.M());

		}

		h_Z_pt_lep->Fill(dimuon.Pt());
		h_Z_pt_lep->Fill(dielectron.Pt());
		h_Z_jets_pt->Fill(dijet.Pt());


		TLorentzVector diZ;
		if( dijet.Pt() != 0){

			if (dimuon.Pt() !=0){
				diZ = dijet + dimuon;
			}

			else if (dielectron.Pt() !=0){

				diZ = dijet + dielectron;
			}

		}

		h_DiZ_mass->Fill(diZ.M());
		h_DiZ_Pt->Fill(diZ.Pt());


	} // Event Loop



	// Write histogram to output file

	outputFile->cd();

	h_DiMuon_Mass->Write();
	h_DiElectron_Mass->Write();
	h_Dijet_mass->Write();
	h_DiZ_mass->Write();
	h_Z_pt_lep->Write();
	h_Z_jets_pt->Write();
	h_DiZ_Pt->Write();

	outputFile->Close();



	std::cout << "Tidy Up..." << std::endl;

	delete r;

	std::cout << "Done Analysis!" << std::endl;

	return 0;
} 