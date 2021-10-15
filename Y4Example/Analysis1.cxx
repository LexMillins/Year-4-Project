#include "Analysis.h"


int main(int argc, char* argv[]) {

	std::cout << "Starting Analysis!" << std::endl;




	// Open the file and setup the reader class

	TFile* inputFile = TFile::Open("user.achishol.18108467._000001.output.root");

	TTree* tree = (TTree*) inputFile->Get("nominal");

	Reader* r = new Reader(tree);


	// Setup an output ROOT file to store histograms

	TFile* outputFile = new TFile("output.root","recreate");

	outputFile->cd();

	TH1D* h_DiMuon_Mass = new TH1D("h_DiMuon_Mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_DiElectron_Mass = new TH1D("h_DiElectron_mass","; Mass [GeV]; Events / GeV",100,50,150);

	// Event loop

	const int nEvents = r->fChain->GetEntries();

	std::cout << "Events to process = " << nEvents << std::endl;

	// Event Loop
	for(int n = 0; n < nEvents; ++n) {

		if(n%10000 == 0) std::cout << "Event " << n << std::endl;


		r->GetEntry(n);

		if( r->mu_pt->size() == 2) {


			TLorentzVector muon1, muon2;

			muon1.SetPtEtaPhiM(r->mu_pt->at(0)*1e-3,r->mu_eta->at(0),r->mu_phi->at(0),105.67e-3);
			muon2.SetPtEtaPhiM(r->mu_pt->at(1)*1e-3,r->mu_eta->at(1),r->mu_phi->at(1),105.67e-3);

			TLorentzVector dimuon = muon1 + muon2;

			h_DiMuon_Mass->Fill(dimuon.M());

		}

		else if ( r->el_pt->size() == 2)
		{
			TLorentzVector elec1, elec2;

			elec1.SetPtEtaPhiM(r->el_pt->at(0)*1e-3,r->el_eta->at(0),r->el_phi->at(0),0.511e-3);
			elec2.SetPtEtaPhiM(r->el_pt->at(1)*1e-3,r->el_eta->at(1),r->el_phi->at(1),0.511e-3);

			TLorentzVector dieelectron = elec1 + elec2;

			h_DiElectron_Mass->Fill(dieelectron.M());

		}


		if ( r->jet_pt->size() >= 2)
		{

			std::cout << "New Events" << std::endl;
			std::vector<float> *jet_pt_dummy = *(r->jet_pt);

			int p = sizeof(jet_pt_dummy)/sizeof(jet_pt_dummy[0]);
			sort(jet_pt_dummy, jet_pt_dummy + p);

			cout << "Array after sorting : \n" ;

			for (int k=0; k< p; k++) {
				cout << jet_pt_dummy[k] << "";
 
				return 0;
			}


			for (int i = 0; i < &r->jet_pt->size(); ++i)
			{
				std::cout << r->jet_pt->at(i)*1e-3 << std::endl;
			}

		}

	}  //Event Loop



	// Write histogram to output file

	outputFile->cd();

	h_DiMuon_Mass->Write();
	h_DiElectron_Mass->Write();

	outputFile->Close();



	std::cout << "Tidy Up..." << std::endl;

	delete r;

	std::cout << "Done Analysis!" << std::endl;

	return 0;
}

