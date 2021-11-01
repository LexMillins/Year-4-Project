

void Plot_Sum() {


	TFile* file_1 = TFile::Open("Output_364100.root");
	TFile* file_2 = TFile::Open("Output_364101.root");
	TFile* file_3 = TFile::Open("Output_364102.root");
	TFile* file_4 = TFile::Open("Output_364103.root");
	TFile* file_5 = TFile::Open("Output_364104.root");
	TFile* file_6 = TFile::Open("Output_364105.root");

	TH1D* h_1 = (TH1D*) file_1->Get("h_Z_pt_lep");
	TH1D* h_2 = (TH1D*) file_2->Get("h_Z_pt_lep");
	TH1D* h_3 = (TH1D*) file_3->Get("h_Z_pt_lep");
	TH1D* h_4 = (TH1D*) file_4->Get("h_Z_pt_lep");
	TH1D* h_5 = (TH1D*) file_5->Get("h_Z_pt_lep");
	TH1D* h_6 = (TH1D*) file_6->Get("h_Z_pt_lep");

	TCanvas* c = new TCanvas("c","c",800,600);



	h_1->Draw();
	h_2->Draw("SAME");
	h_3->Draw("SAME");
	h_4->Draw("SAME");
	h_5->Draw("SAME");
	h_6->Draw("SAME");


	TH1D* h_Sum = (TH1D*) h_1->Clone("h_Sum");
	h_Sum->Reset();

	h_Sum->Add(h_1);
	h_Sum->Add(h_2);
	h_Sum->Add(h_3);
	h_Sum->Add(h_4);
	h_Sum->Add(h_5);
	h_Sum->Add(h_6);


	h_Sum->Draw();




}
