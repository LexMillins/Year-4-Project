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

    // For standalone example, make some "toy" signal and background histogram
    //MakeExample(h_Signal,h_Bkgd);

    //----------
    // Here, you should open a file, load you S and B histograms
    // then set them to the pointers h_Signal and h_Bkgd
    // and comment out "MakeExample"

    TString inputFileName = "plots.root";

    TFile* inputFile = TFile::Open(inputFileName);

    TString histNameSig = "h_Sig";

    TString histNameBkgd = "h_Bckgd";

    h_Signal = (TH1D*)inputFile->Get(histNameSig);

    h_Bkgd = (TH1D*)inputFile->Get(histNameBkgd);
    
    //----------

    // Make a "dummy" dataset from the expected data and background
    TH1D* h_Data = (TH1D*) h_Bkgd->Clone("h_Data");
    h_Data->Reset();
    h_Data->Add(h_Signal);
    h_Data->Add(h_Bkgd);

    //----------
    // When you get the "real" data, you can simply load it from the file and
    // set the h_Data pointer to that histogram and comment out the code above
    //----------

    // Build fit observable from the range in the input histograms
    RooRealVar m_Mass("Mass","m_{jj}",h_Bkgd->GetBinLowEdge(1),h_Bkgd->GetBinLowEdge(h_Bkgd->GetNbinsX()+1),"GeV");

    m_Mass.Print();

    // Build dataset object from real or dummy data
    RooDataHist m_Hist_Data("m_Hist_Data","",m_Mass,h_Data);

    m_Hist_Data.Print();

    // Do the same for signal and background histograms, used to build PDFs
    RooDataHist m_Hist_Signal("m_Hist_Signal","",m_Mass,h_Signal);
    RooDataHist m_Hist_Bkgd("m_Hist_Bkgd","",m_Mass,h_Bkgd);

    RooHistPdf pdf_Signal("pdf_Signal","",m_Mass,m_Hist_Signal);
    RooHistPdf pdf_Bkgd("pdf_Bkgd","",m_Mass,m_Hist_Bkgd);

    // Signal Strength parameters for signal and background
    RooRealVar mu_Signal("mu_Signal","",1.0,-1000.0,1000.0);
    RooRealVar mu_Bkgd("mu_Bkgd","",1.0,-1000.0,1000.0);

    // Number of events (after weighting / scaling) for MC prediction
    RooRealVar N_Signal_MC("N_Signal_MC","",h_Signal->Integral());
    RooRealVar N_Bkgd_MC("N_Bkgd_MC","",h_Bkgd->Integral());

    // Our number of events in the fit for S and B: mu*N_Events for S and B, separately
    RooFormulaVar N_Signal("N_Signal","mu_Signal*N_Signal_MC",RooArgSet(mu_Signal,N_Signal_MC));
    RooFormulaVar N_Bkgd("N_Bkgd","mu_Bkgd*N_Bkgd_MC",RooArgSet(mu_Bkgd,N_Bkgd_MC));

    // Build Poisson terms for N_Signal and N_Bkgd and associate them with relevant PDFs
    RooExtendPdf epdf_Signal("epdf_Signal","",pdf_Signal,N_Signal);
    RooExtendPdf epdf_Bkgd("epdf_Bkgd","",pdf_Bkgd,N_Bkgd);

    RooAddPdf pdf_Total("pdf_Total","",RooArgList(epdf_Signal,epdf_Bkgd));

    // Run the fit
    RooFitResult* fit_result = pdf_Total.fitTo(m_Hist_Data,Save());


    // Make a plot
    TCanvas* c = new TCanvas("c","",800,600);

    RooPlot* frame = m_Mass.frame();

    // Plot data and PDF overlaid, use expected number of events for p.d.f projection normalization
    // rather than observed number of events (==data->numEntries())

    m_Hist_Data.plotOn(frame,Name("Data"));

    pdf_Total.plotOn(frame,Normalization(1.0,RooAbsReal::RelativeExpected),Name("Total")) ;
    // Overlay the background component of model with a dashed line
    pdf_Total.plotOn(frame,Components(epdf_Bkgd),LineStyle(kDashed),Normalization(1.0,RooAbsReal::RelativeExpected),Name("BOnly")) ;
    // Overlay the signal components
    pdf_Total.plotOn(frame,Components(RooArgSet(epdf_Signal)),LineColor(kRed),Normalization(1.0,RooAbsReal::RelativeExpected),Name("SOnly")) ;

    frame->Draw();

    TLegend * Leg = new TLegend(0.65,0.2+0.5,0.9,0.4+0.5);

    Leg->SetTextFont(42);
    Leg->SetTextSize(0.04);
    Leg->SetBorderSize(0);
    Leg->SetFillStyle(0);

    Leg->AddEntry("Data", "Data" , "lep");
    Leg->AddEntry("Total", "Fit Result" , "l");
    Leg->AddEntry("BOnly", "Bkgd. Component" , "l");
    Leg->AddEntry("SOnly", "Signal Component" , "l");

    Leg->Draw();


    fit_result->Print();

    c->SaveAs("FitResult.pdf");

}
