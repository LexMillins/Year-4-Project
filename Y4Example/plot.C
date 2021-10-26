void plot(){

 	TFile *f = new TFile("output.root");
 	f->ls();

 	auto c1 = new TCanvas("pt", "Canvas 1", 600, 600);

 	TH1F * h1 = (TH1F*)f->Get("h_Z_pt_lep");
 	TH1F * h2 = (TH1F*)f->Get("h_Z_jets_pt");

 	h2->SetLineColor(2);


 	h1->Draw();
 	h2->Draw("same");
 	c1->Draw();
 	c1->Update();
 	c1->Show();

 	auto c2 = new TCanvas("inv_mass", "Canvas 2", 600, 600);

 	TH1F * h3 = (TH1F*)f->Get("h_DiMuon_Mass");
 	TH1F * h4 = (TH1F*)f->Get("h_DiElectron_mass");

 	h3->Draw();
 	h4->Draw("same");
 	c2->Draw();
 	c2->Update();
 	c2->Show();


}