// This is here just to build an example S and B histogram
// but it can also be used to help understand how the
// fit reacts to changes in the parameters

void MakeExample(TH1D* & h_Signal, TH1D* & h_Bkgd) {

    // Range of histogram and number of bins
    const double Mass_Low = 0.0;
    const double Mass_High = 200.0;
    const unsigned int Mass_nBins = 40;

    // Characteristics of signal
    const double signal_peak_mean = 91.0; // GeV
    const double signal_peak_sigma = 10.0; // GeV

    h_Signal = new TH1D("h_Signal","; m_{jj} [GeV]; Events / 5 GeV",Mass_nBins,Mass_Low,Mass_High);

    h_Bkgd = (TH1D*) h_Signal->Clone("h_Bkgd");

    TRandom3* m_rand = new TRandom3(387);

    const unsigned int nSignal = 5000;
    const unsigned int nBkgd = 50000;

    // Signal events - Gaussian
    for(unsigned int n = 0; n < nSignal; ++n) {

        const double m = m_rand->Gaus(signal_peak_mean,signal_peak_sigma); // (mean,sigma)

        h_Signal->Fill(m);

    } // Signal events

    // Background events
    for(unsigned int n = 0; n < nBkgd; ++n) {

        // Flat background as a function of m_jj
        const double m = m_rand->Uniform(Mass_Low,Mass_High);

        h_Bkgd->Fill(m);

    } // Background events

}


void Fit() {

    using namespace RooFit;

    TH1D* h_Signal = NULL;
    TH1D* h_Bkgd = NULL;
    TH1D* h_Data = NULL;
    TH1D* h_ttbar = NULL;
    TH1D* h_light_Bckgd = NULL;
    TH1D* h_bb_bckgd = NULL;

    // For standalone example, make some "toy" signal and background histogram
    //MakeExample(h_Signal,h_Bkgd);

    //----------
    // Here, you should open a file, load you S and B histograms
    // then set them to the pointers h_Signal and h_Bkgd
    // and comment out "MakeExample"

    TString inputFileName = "plots.root";

    TString inputFileNameData = "data_total_13TeV_Output.root";

    TString inputFileNameMG = "MadGraphplots.root";

    TFile* inputFile = TFile::Open(inputFileName);

    TFile* inputFileData = TFile::Open(inputFileNameData);

    TString histNameData = "h_Z_mass";

    TString histNameSig = "h_Sig";

    TString histNameBkgd = "h_Bckgd";

    TString histNamettBkgd = "h_ttbar";

    TString histNamelightBkgd = "h_light_Bckgd";

    TString histNamebbBkgd = "h_bb_Bckgd";

    h_Signal = (TH1D*)inputFile->Get(histNameSig);

    h_Bkgd = (TH1D*)inputFile->Get(histNameBkgd);

    h_ttbar = (TH1D*)inputFile->Get(histNamettBkgd);

    h_Data = (TH1D*)inputFileData->Get(histNameData);

    h_light_Bckgd = (TH1D*)inputFile->Get(histNamelightBkgd);

    h_bb_bckgd = (TH1D*)inputFile->Get(histNamebbBkgd);
    
    //----------

    // Make a "dummy" dataset from the expected data and background
    /*h_Data = (TH1D*) h_Bkgd->Clone("h_Data");
    h_Data->Reset();
    h_Data->Add(h_Signal);
    h_Data->Add(h_Bkgd);*/

    //----------
    // When you get the "real" data, you can simply load it from the file and
    // set the h_Data pointer to that histogram and comment out the code above
    //----------

    // Build fit observable from the range in the input histograms
    //RooRealVar m_Mass("Mass","m_{jj}",h_Bkgd->GetBinLowEdge(1),h_Bkgd->GetBinLowEdge(h_Bkgd->GetNbinsX()+1),"GeV");
    RooRealVar m_Mass("Mass","m_{jj}",20.0,h_Bkgd->GetBinLowEdge(h_Bkgd->GetNbinsX()+1),"GeV");

    m_Mass.Print();

    // Build dataset object from real or dummy data
    RooDataHist m_Hist_Data("m_Hist_Data","",m_Mass,h_Data);

    m_Hist_Data.Print();

    // Do the same for signal and background histograms, used to build PDFs
    RooDataHist m_Hist_Signal("m_Hist_Signal","",m_Mass,h_Signal);
    RooDataHist m_Hist_Bkgd("m_Hist_Bkgd","",m_Mass,h_Bkgd);
    RooDataHist m_Hist_Bkgd_ttbar("m_Hist_Bkgd_ttbar","",m_Mass,h_ttbar);
    RooDataHist m_Hist_Bkgd_light("m_Hist_Bkgd_light","",m_Mass,h_light_Bckgd);
    RooDataHist m_Hist_Bkgd_bb("m_Hist_Bkgd_bb","",m_Mass,h_bb_bckgd);

    RooHistPdf pdf_Signal("pdf_Signal","",m_Mass,m_Hist_Signal);
    RooHistPdf pdf_Bkgd("pdf_Bkgd","",m_Mass,m_Hist_Bkgd);
    RooHistPdf pdf_Bkgd_ttbar("pdf_Bkgd_ttbar","",m_Mass,m_Hist_Bkgd_ttbar);
    RooHistPdf pdf_Bkgd_light("pdf_Bkgd_light","",m_Mass,m_Hist_Bkgd_light);
    RooHistPdf pdf_Bkgd_bb("pdf_Bkgd_bb","",m_Mass,m_Hist_Bkgd_bb);


    // Signal Strength parameters for signal and background
    RooRealVar mu_Signal("mu_Signal","",1.0,-1000.0,1000.0);
    RooRealVar mu_Bkgd("mu_Bkgd","",1.0,-1000.0,1000.0);
    RooRealVar mu_Bkgd_ttbar("mu_Bkgd_ttbar","",1.0,-1000.0,1000.0);
    RooRealVar mu_Bkgd_light("mu_Bkgd_light","",1.0,-1000.0,1000.0);
    RooRealVar mu_Bkgd_bb("mu_Bkgd_bb","",1.0,-1000.0,1000.0);

    mu_Signal.setConstant(kTRUE);
    mu_Signal.setVal(0);

    

    // Number of events (after weighting / scaling) for MC prediction
    RooRealVar N_Signal_MC("N_Signal_MC","",h_Signal->Integral());
    RooRealVar N_Bkgd_MC("N_Bkgd_MC","",h_Bkgd->Integral());
    RooRealVar N_Bkgd_ttbar_MC("N_Bkgd_ttbar_MC","",h_ttbar->Integral());
    RooRealVar N_Bkgd_light_MC("N_Bkgd_light_MC","",h_light_Bckgd->Integral());
    RooRealVar N_Bkgd_bb_MC("N_Bkgd_bb_MC","",h_bb_bckgd->Integral());

    // Our number of events in the fit for S and B: mu*N_Events for S and B, separately
    RooFormulaVar N_Signal("N_Signal","mu_Signal*N_Signal_MC",RooArgSet(mu_Signal,N_Signal_MC));
    RooFormulaVar N_Bkgd("N_Bkgd","mu_Bkgd*N_Bkgd_MC",RooArgSet(mu_Bkgd,N_Bkgd_MC));
    RooFormulaVar N_Bkgd_ttbar("N_Bkgd_ttbar","mu_Bkgd_ttbar*N_Bkgd_ttbar_MC",RooArgSet(mu_Bkgd_ttbar,N_Bkgd_ttbar_MC));
    RooFormulaVar N_Bkgd_light("N_Bkgd_light","mu_Bkgd_light*N_Bkgd_light_MC",RooArgSet(mu_Bkgd_light,N_Bkgd_light_MC));
    RooFormulaVar N_Bkgd_bb("N_Bkgd_bb","mu_Bkgd_bb*N_Bkgd_bb_MC",RooArgSet(mu_Bkgd_bb,N_Bkgd_bb_MC));

    // Build Poisson terms for N_Signal and N_Bkgd and associate them with relevant PDFs
    RooExtendPdf epdf_Signal("epdf_Signal","",pdf_Signal,N_Signal);
    RooExtendPdf epdf_Bkgd("epdf_Bkgd","",pdf_Bkgd,N_Bkgd);
    RooExtendPdf epdf_Bkgd_ttbar("epdf_Bkgd_ttbar","",pdf_Bkgd_ttbar,N_Bkgd_ttbar);
    RooExtendPdf epdf_Bkgd_light("epdf_Bkgd_light","",pdf_Bkgd_light,N_Bkgd_light);
    RooExtendPdf epdf_Bkgd_bb("epdf_Bkgd_bb","",pdf_Bkgd_bb,N_Bkgd_bb);

    RooAddPdf pdf_Total("pdf_Total","",RooArgList(epdf_Signal,epdf_Bkgd_bb, epdf_Bkgd_light, epdf_Bkgd_ttbar));

    //mu_Bkgd.setConstant(kTRUE);

    // Run the fit
    RooFitResult* fit_result = pdf_Total.fitTo(m_Hist_Data,Save());


    // Make a plot
    TCanvas* c = new TCanvas("c","",800,600);

    RooPlot* frame = m_Mass.frame(Title("Invariant Mass of Z Fit Data (after b-tag)"));


    // Plot data and PDF overlaid, use expected number of events for p.d.f projection normalization
    // rather than observed number of events (==data->numEntries())

    m_Hist_Data.plotOn(frame,Name("Data"));

    pdf_Total.plotOn(frame,Normalization(1.0,RooAbsReal::RelativeExpected),Name("Total")) ;
    // Overlay the background component of model with a dashed line
    //pdf_Total.plotOn(frame,Components(epdf_Bkgd),LineStyle(kDashed),Normalization(1.0,RooAbsReal::RelativeExpected),Name("BOnly")) ;
    pdf_Total.plotOn(frame,Components(epdf_Bkgd_light),LineColor(kGreen), LineStyle(kDashed),Normalization(1.0,RooAbsReal::RelativeExpected),Name("lightBOnly")) ;
    pdf_Total.plotOn(frame,Components(epdf_Bkgd_bb),LineColor(kOrange), LineStyle(kDashed),Normalization(1.0,RooAbsReal::RelativeExpected),Name("bbBOnly")) ;
    pdf_Total.plotOn(frame,Components(epdf_Bkgd_ttbar),LineStyle(kDotted),Normalization(1.0,RooAbsReal::RelativeExpected),Name("ttBOnly")) ;
    // Overlay the signal components
    pdf_Total.plotOn(frame,Components(RooArgSet(epdf_Signal)),LineColor(kRed),Normalization(1.0,RooAbsReal::RelativeExpected),Name("SOnly")) ;

    frame->Draw();

    const double offset = -120729;

    //0.163743 S+B

    const double nll = fit_result->minNll() - offset;

    std::cout << "nll = " << nll << std::endl;

    TLegend * Leg = new TLegend(0.65,0.2+0.5,0.9,0.4+0.5);

    Leg->SetTextFont(42);
    Leg->SetTextSize(0.04);
    Leg->SetBorderSize(0);
    Leg->SetFillStyle(0);

    Leg->AddEntry("Data", "Data" , "lep");
    Leg->AddEntry("Total", "Fit Result" , "l");
    Leg->AddEntry("BOnly", "Z+jets Bkgd. Component" , "l");
    Leg->AddEntry("ttBOnly", "ttbar Bkgd. Component" , "l");
    Leg->AddEntry("lightBOnly", "light Z+jets Bkgd. Component" , "l");
    Leg->AddEntry("bbBOnly", "bb Z+jets Bkgd. Component" , "l");
    Leg->AddEntry("SOnly", "Signal Component" , "l");

    Leg->Draw();


    fit_result->Print();

    c->SaveAs("FitResult.pdf");

}
