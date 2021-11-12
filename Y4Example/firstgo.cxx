	TFile* inputFile = TFile::Open("user.achishol.18108467._000001.output.root");

	TTree* tree = (TTree*) inputFile->Get("nominal");

	Reader* r = new Reader(tree);


	// Setup an output ROOT file to store histograms

	TFile* outputFile = new TFile("output.root","recreate");

	outputFile->cd();

	TH1D* h_DiMuon_Mass = new TH1D("h_DiMuon_Mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_DiElectron_Mass = new TH1D("h_DiElectron_mass","; Mass [GeV]; Events / GeV",100,50,150);

	TH1D* h_Dijet_mass = new TH1D("h_Dijet_Mass", "Mass [GeV]; Events/GeV",100,50,150);

	// Event loop

	const int nEvents = r->fChain->GetEntries();

	std::cout << "Events to process = " << nEvents << std::endl;

	// Event Loop
	for(int n = 0; n < nEvents; ++n) {

		if(n%10000 == 0) std::cout << "Event " << n << std::endl;


		r->GetEntry(n);


		std::vector<TLorentzVector> my_jets;



		for( int j = 0; j <(r->jet_pt->size()); ++j){

			TLorentzVector jetj;

			jetj.SetPtEtaPhiE(r->jet_pt->at(j)*1e-3, r->jet_eta->at(j), r->jet_phi->at(j), r->jet_e->at(j)*1e-3);

			my_jets.push_back(jetj);

		}


		std::sort(my_jets.begin(), my_jets.end(),sortby_jet_pt);

		print_vect_TLor(my_jets);

		if(my_jets.size() >= 2){
		std::vector<TLorentzVector> biggest_jets;
		biggest_jets.push_back(my_jets.at(0));
		biggest_jets.push_back(my_jets.at(1));
		
		TLorentzVector dijet = my_jets.at(0) + my_jets.at(1);

		h_Dijet_mass->Fill(dijet.M());



		}
		//std::vector<TLorentzVector> biggest_jets;
		//biggest_jets.push_back(my_jets.at(0));
		//biggest_jets.push_back(my_jets.at(1));
		
		//TLorentzVector dijet = my_jets.at(0) + my_jets.at(1);

		//h_Dijet_mass->Fill(dijet.M());

		//if( r->mu_pt->size() == 2) {


			//TLorentzVector muon1, muon2;

			//muon1.SetPtEtaPhiM(r->mu_pt->at(0)*1e-3,r->mu_eta->at(0),r->mu_phi->at(0),105.67e-3);
			//muon2.SetPtEtaPhiM(r->mu_pt->at(1)*1e-3,r->mu_eta->at(1),r->mu_phi->at(1),105.67e-3);

			//TLorentzVector dimuon = muon1 + muon2;

			//h_DiMuon_Mass->Fill(dimuon.M());

		//}

		//else if ( r->el_pt->size() == 2)
		//{
			//TLorentzVector elec1, elec2;

			//elec1.SetPtEtaPhiM(r->el_pt->at(0)*1e-3,r->el_eta->at(0),r->el_phi->at(0),0.511e-3);
			//elec2.SetPtEtaPhiM(r->el_pt->at(1)*1e-3,r->el_eta->at(1),r->el_phi->at(1),0.511e-3);

			//TLorentzVector dieelectron = elec1 + elec2;

			//h_DiElectron_Mass->Fill(dieelectron.M());

		//}

		//if( r->mu_pt->size()>2){
		//	std::vector<float> muon_vector = *(r->mu_pt);
		//	print_vect_float(muon_vector);


		//}
/*
		if ( r->jet_pt->size() >= 2)
		{

			std::cout << "New Event" << std::endl;
			std::vector<float> jet_pt_dummy = *(r->jet_pt);
			//print_vect_float(jet_pt_dummy);

			int p = r->jet_pt->size();
			std::sort(jet_pt_dummy.begin(), jet_pt_dummy.begin()+p);

			std::cout << "Array after sorting : \n" ;
			print_vect_float(jet_pt_dummy);
		

			//return 0;

			std::vector<vector<double>> jets_total;
			std::vector<vector<double>> biggest_jets;


				for( int j = 0; j <(r->jet_pt->size()); ++j){

					TLorentzVector jetj;

					jetj.SetPtEtaPhiE(r->jet_pt->at(j)*1e-3, r->jet_eta->at(j), r->jet_phi->at(j), r->jet_e->at(j)*1e-3);

					std::vector<double> jet_vector;

					std::vector<vector<double>> jets_total;

						
					for (int L=0; L<4; L++){
	        			jet_vector.push_back(jetj(L));					
					

						jets_total.push_back(jet_vector);
					}

				for(int a = 0; a < p; ++a){

					std::vector<double> v = jets_total.at(a);
					std::vector<double> c = jets_total.at(a+1);

					if (sortby_jet_pt(v, c) == 1){
						biggest_jets.push_back(v);

					}
				}

			}

			//std::vector<double> jet1 = biggest_jets.at(0);
			//std::vector<double> jet2 = biggest_jets.at(1);

			//float inv_mass__squared_Z = 2*jet1.at(0)*jet2.at(0)*(cosh(jet1.at(1) - jet2.at(1)) - cos(jet1.at(2) - jet2.at(2)));
			//float inv_mass_z = sqrt(inv_mass__squared_Z);
			//h_Dijet_mass->Fill(inv_mass_z);



			

	


		}
*/
	} // Event Loop



	// Write histogram to output file

	outputFile->cd();

	h_DiMuon_Mass->Write();
	h_DiElectron_Mass->Write();
	h_Dijet_mass->Write();

	outputFile->Close();



	std::cout << "Tidy Up..." << std::endl;

	delete r;

	std::cout << "Done Analysis!" << std::endl;

	return 0;
} 