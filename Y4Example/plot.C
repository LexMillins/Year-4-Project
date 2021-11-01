void plot(){

 	TFile *f = new TFile("output.root");
 	f->ls();

 	auto c1 = new TCanvas("pt", "Canvas 1", 600, 600);

 	TH1F * h1 = (TH1F*)f->Get("h_Z_pt_lep");
 	TH1F * h2 = (TH1F*)f->Get("h_Boson_jets_pt");

 	h2->SetLineColor(kRed);


 	h1->Draw();
 	h2->Draw("same");

   auto legend = new TLegend(0.3,0.7,0.7,0.9);
   legend->SetHeader("Transverse Momentum of Z boson","C"); // option "C" allows to center the header
   legend->AddEntry(h1,"pt from leptons","l");
   legend->AddEntry(h2,"pt from jets","l");
   legend->Draw();


 	c1->Draw();
 	c1->Update();
 	c1->Show();

   
 	auto c2 = new TCanvas("inv_mass", "Canvas 2", 600, 600);

 	TH1F * h3 = (TH1F*)f->Get("h_DiMuon_Mass");
 	TH1F * h4 = (TH1F*)f->Get("h_DiElectron_mass");

   h3->SetLineColor(kGreen);

 	h3->Draw();
 	h4->Draw("same");
 	c2->Draw();
 	c2->Update();
 	c2->Show();

 	auto c3 = new TCanvas("Transverse Momentum of Di-boson system");

 	TH1F * h5 = (TH1F*)f->Get("h_DiBoson_Pt");

 	h5->Draw();
 	c3->Draw();
 	c3->Update();
 	c3->Show();

 	auto c4 = new TCanvas("Inv Mass", "Canvas 3", 600, 600);

 	TH1F * h6 = (TH1F*)f->Get("h_Boson_jets_pt");

 	h6->Draw();
 	c4->Draw();
 	c4->Update();
 	c4->Show();

   auto c5 = new TCanvas("Invariant_Mass", "Canvas 3", 600, 600);

   TH1F * h7 = (TH1F*)f->Get("h_Dijet_Mass");

   h7->Draw();
   c5->Draw();
   c5->Update();
   c5->Show();


   


}