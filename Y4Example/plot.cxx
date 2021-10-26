void plot(){

 	TFile *inputFile = new TFile("output.root");
 	inputFile->ls();

 	TH1F * h1 = (TH1F*)inputFile->Get("h_Dimuon_Mass");
 	h1->Draw();


}