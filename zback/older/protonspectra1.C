void protonspectra1()
{

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->SetLogy();
  c1->Divide(2,1);
  c1_1->SetLogy();
  c1_2->SetLogy();

  // --- now AuAu --- //

  ifstream fposproton0010AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_8_dis_cent0010.txt");
  ifstream fposproton1020AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_8_dis_cent1020.txt");
  ifstream fposproton2040AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_8_dis_cent2040.txt");
  ifstream fposproton4060AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_8_dis_cent4060.txt");
  ifstream fposproton6092AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_8_dis_cent6092.txt");

  float pT_posproton0010AuAu[44], epT_posproton0010AuAu[44], yield_posproton0010AuAu[44], eyield_posproton0010AuAu[44];
  float pT_posproton1020AuAu[44], epT_posproton1020AuAu[44], yield_posproton1020AuAu[44], eyield_posproton1020AuAu[44];
  float pT_posproton2040AuAu[44], epT_posproton2040AuAu[44], yield_posproton2040AuAu[44], eyield_posproton2040AuAu[44];
  float pT_posproton4060AuAu[44], epT_posproton4060AuAu[44], yield_posproton4060AuAu[44], eyield_posproton4060AuAu[44];
  float pT_posproton6092AuAu[44], epT_posproton6092AuAu[44], yield_posproton6092AuAu[44], eyield_posproton6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fposproton0010AuAu>>pT_posproton0010AuAu[i]>>yield_posproton0010AuAu[i]>>eyield_posproton0010AuAu[i];
      fposproton1020AuAu>>pT_posproton1020AuAu[i]>>yield_posproton1020AuAu[i]>>eyield_posproton1020AuAu[i];
      fposproton2040AuAu>>pT_posproton2040AuAu[i]>>yield_posproton2040AuAu[i]>>eyield_posproton2040AuAu[i];
      fposproton4060AuAu>>pT_posproton4060AuAu[i]>>yield_posproton4060AuAu[i]>>eyield_posproton4060AuAu[i];
      fposproton6092AuAu>>pT_posproton6092AuAu[i]>>yield_posproton6092AuAu[i]>>eyield_posproton6092AuAu[i];
      epT_posproton0010AuAu[i] = 0;
      epT_posproton1020AuAu[i] = 0;
      epT_posproton2040AuAu[i] = 0;
      epT_posproton4060AuAu[i] = 0;
      epT_posproton6092AuAu[i] = 0;
      // now do some multiplication
      yield_posproton0010AuAu[i] *=20;eyield_posproton0010AuAu[i] *=20;
      yield_posproton1020AuAu[i] *=5;eyield_posproton1020AuAu[i] *=5;
      yield_posproton2040AuAu[i] *=2;eyield_posproton2040AuAu[i] *=2;
    }
  fposproton0010AuAu.close();
  fposproton1020AuAu.close();
  fposproton2040AuAu.close();
  fposproton4060AuAu.close();
  fposproton6092AuAu.close();

  // --- now dAu --- //

  ifstream fposproton0088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_5_dis_cent0088.txt");
  ifstream fposproton0020dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_5_dis_cent0020.txt");
  ifstream fposproton2040dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_5_dis_cent2040.txt");
  ifstream fposproton4060dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_5_dis_cent4060.txt");
  ifstream fposproton6088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_5_dis_cent6088.txt");

  float pT_posproton0088dAu[36], epT_posproton0088dAu[36], yield_posproton0088dAu[36], eyield_posproton0088dAu[36];
  float pT_posproton0020dAu[36], epT_posproton0020dAu[36], yield_posproton0020dAu[36], eyield_posproton0020dAu[36];
  float pT_posproton2040dAu[36], epT_posproton2040dAu[36], yield_posproton2040dAu[36], eyield_posproton2040dAu[36];
  float pT_posproton4060dAu[36], epT_posproton4060dAu[36], yield_posproton4060dAu[36], eyield_posproton4060dAu[36];
  float pT_posproton6088dAu[36], epT_posproton6088dAu[36], yield_posproton6088dAu[36], eyield_posproton6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fposproton0088dAu>>pT_posproton0088dAu[i]>>yield_posproton0088dAu[i]>>eyield_posproton0088dAu[i];
      fposproton0020dAu>>pT_posproton0020dAu[i]>>yield_posproton0020dAu[i]>>eyield_posproton0020dAu[i];
      fposproton2040dAu>>pT_posproton2040dAu[i]>>yield_posproton2040dAu[i]>>eyield_posproton2040dAu[i];
      fposproton4060dAu>>pT_posproton4060dAu[i]>>yield_posproton4060dAu[i]>>eyield_posproton4060dAu[i];
      fposproton6088dAu>>pT_posproton6088dAu[i]>>yield_posproton6088dAu[i]>>eyield_posproton6088dAu[i];
      epT_posproton0088dAu[i] = 0;
      epT_posproton0020dAu[i] = 0;
      epT_posproton2040dAu[i] = 0;
      epT_posproton4060dAu[i] = 0;
      epT_posproton6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  yield_posproton0088dAu[i] = 0;
	  yield_posproton0020dAu[i] = 0;
	  yield_posproton2040dAu[i] = 0;
	  yield_posproton4060dAu[i] = 0;
	  yield_posproton6088dAu[i] = 0;
	  eyield_posproton0088dAu[i] = 0;
	  eyield_posproton0020dAu[i] = 0;
	  eyield_posproton2040dAu[i] = 0;
	  eyield_posproton4060dAu[i] = 0;
	  eyield_posproton6088dAu[i] = 0;
	}
      // dAu scaling
      // got the order reversed :(
      // yield_posproton0088dAu[i] *= 2.5e-1;eyield_posproton0088dAu[i] *= 2.5e-1;
      // yield_posproton0020dAu[i] *= 2.5e-2;eyield_posproton0020dAu[i] *= 2.5e-2;
      //yield_posproton0020dAu[i] *= 1.0e-1;eyield_posproton0020dAu[i] *= 1.0e-1;
      //yield_posproton0088dAu[i] *= 5.0e-2;eyield_posproton0088dAu[i] *= 5.0e-2;
      yield_posproton0020dAu[i] *= 1.3e-1;eyield_posproton0020dAu[i] *= 1.3e-1;
      yield_posproton0088dAu[i] *= 5.0e-2;eyield_posproton0088dAu[i] *= 5.0e-2;
      yield_posproton2040dAu[i] *= 7.5e-3;eyield_posproton2040dAu[i] *= 7.5e-3;
      yield_posproton4060dAu[i] *= 2.0e-3;eyield_posproton4060dAu[i] *= 2.0e-3;
      yield_posproton6088dAu[i] *= 1.0e-3;eyield_posproton6088dAu[i] *= 1.0e-3;
    }
  fposproton0088dAu.close();
  fposproton0020dAu.close();
  fposproton2040dAu.close();
  fposproton4060dAu.close();
  fposproton6088dAu.close();




  TGraphErrors *tge_posproton0010AuAu = new TGraphErrors(36,pT_posproton0010AuAu,yield_posproton0010AuAu,epT_posproton0010AuAu,eyield_posproton0010AuAu);
  tge_posproton0010AuAu->SetMarkerColor(kBlack);
  tge_posproton0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_posproton1020AuAu = new TGraphErrors(36,pT_posproton1020AuAu,yield_posproton1020AuAu,epT_posproton1020AuAu,eyield_posproton1020AuAu);
  tge_posproton1020AuAu->SetMarkerColor(kBlack);
  tge_posproton1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_posproton2040AuAu = new TGraphErrors(36,pT_posproton2040AuAu,yield_posproton2040AuAu,epT_posproton2040AuAu,eyield_posproton2040AuAu);
  tge_posproton2040AuAu->SetMarkerColor(kBlack);
  tge_posproton2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_posproton4060AuAu = new TGraphErrors(36,pT_posproton4060AuAu,yield_posproton4060AuAu,epT_posproton4060AuAu,eyield_posproton4060AuAu);
  tge_posproton4060AuAu->SetMarkerColor(kBlack);
  tge_posproton4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_posproton6092AuAu = new TGraphErrors(36,pT_posproton6092AuAu,yield_posproton6092AuAu,epT_posproton6092AuAu,eyield_posproton6092AuAu);
  tge_posproton6092AuAu->SetMarkerColor(kBlack);
  tge_posproton6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_posproton0088dAu = new TGraphErrors(36,pT_posproton0088dAu,yield_posproton0088dAu,epT_posproton0088dAu,eyield_posproton0088dAu);
  tge_posproton0088dAu->SetMarkerColor(kBlack);
  tge_posproton0088dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_posproton0020dAu = new TGraphErrors(36,pT_posproton0020dAu,yield_posproton0020dAu,epT_posproton0020dAu,eyield_posproton0020dAu);
  tge_posproton0020dAu->SetMarkerColor(kBlack);
  tge_posproton0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_posproton2040dAu = new TGraphErrors(36,pT_posproton2040dAu,yield_posproton2040dAu,epT_posproton2040dAu,eyield_posproton2040dAu);
  tge_posproton2040dAu->SetMarkerColor(kBlack);
  tge_posproton2040dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_posproton4060dAu = new TGraphErrors(36,pT_posproton4060dAu,yield_posproton4060dAu,epT_posproton4060dAu,eyield_posproton4060dAu);
  tge_posproton4060dAu->SetMarkerColor(kBlack);
  tge_posproton4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_posproton6088dAu = new TGraphErrors(36,pT_posproton6088dAu,yield_posproton6088dAu,epT_posproton6088dAu,eyield_posproton6088dAu);
  tge_posproton6088dAu->SetMarkerColor(kBlack);
  tge_posproton6088dAu->SetMarkerStyle(kOpenDiamond);

  c1->cd(1); // first panel of canvas

  TMultiGraph *posproton = new TMultiGraph();
  posproton->Add(tge_posproton0010AuAu);
  posproton->Add(tge_posproton1020AuAu);
  posproton->Add(tge_posproton2040AuAu);
  posproton->Add(tge_posproton4060AuAu);
  posproton->Add(tge_posproton6092AuAu);
  posproton->Add(tge_posproton0020dAu);
  posproton->Add(tge_posproton0088dAu);
  posproton->Add(tge_posproton2040dAu);
  posproton->Add(tge_posproton4060dAu);
  posproton->Add(tge_posproton6088dAu);
  posproton->Draw("ap");
  // posproton->SetMaximum(1e6);
  // posproton->SetMinimum(1e-9);
  posproton->SetMaximum(1e6);
  posproton->SetMinimum(1e-10);
  posproton->GetXaxis()->SetLimits(0.0,6.0);
  posproton->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  posproton->GetXaxis()->CenterTitle();
  posproton->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  posproton->GetYaxis()->CenterTitle();

  TLegend *leg_posproton = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_posproton = new TLegend(0.48,0.68,0.68,0.88);
  //TLegend *leg_posproton = new TLegend(0.28,0.68,0.58,0.88);
  //TLegend *leg_posproton = new TLegend(0.48,0.48,0.68,0.88);
  leg_posproton->SetFillColor(kWhite);
  leg_posproton->SetBorderSize(0);
  leg_posproton->SetHeader("Au+Au");
  leg_posproton->AddEntry(tge_posproton0010AuAu,"0-10%","p");
  leg_posproton->AddEntry(tge_posproton1020AuAu,"10-20%","p");
  leg_posproton->AddEntry(tge_posproton2040AuAu,"20-40%","p");
  leg_posproton->AddEntry(tge_posproton4060AuAu,"40-60%","p");
  leg_posproton->AddEntry(tge_posproton6092AuAu,"60-92%","p");
  leg_posproton->Draw();

  TLegend *leg_posproton2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_posproton2 = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg_posproton2 = new TLegend(0.58,0.68,0.88,0.88);
  //TLegend *leg_posproton2 = new TLegend(0.58,0.48,0.88,0.88);
  leg_posproton2->SetFillColor(kWhite);
  leg_posproton2->SetBorderSize(0);
  leg_posproton2->SetHeader("d+Au");
  leg_posproton2->AddEntry(tge_posproton0020dAu,"0-20%","p");
  leg_posproton2->AddEntry(tge_posproton0088dAu,"0-88%","p");
  leg_posproton2->AddEntry(tge_posproton2040dAu,"20-40%","p");
  leg_posproton2->AddEntry(tge_posproton4060dAu,"40-60%","p");
  leg_posproton2->AddEntry(tge_posproton6088dAu,"60-88%","p");
  leg_posproton2->Draw();



  // ---
  // ---
  // --- now negative --- //
  // -------------------- //
  // -------------------- //

  // --- now AuAu --- //

  ifstream fnegproton0010AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_8_dis_cent0010.txt");
  ifstream fnegproton1020AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_8_dis_cent1020.txt");
  ifstream fnegproton2040AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_8_dis_cent2040.txt");
  ifstream fnegproton4060AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_8_dis_cent4060.txt");
  ifstream fnegproton6092AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_8_dis_cent6092.txt");

  float pT_negproton0010AuAu[44], epT_negproton0010AuAu[44], yield_negproton0010AuAu[44], eyield_negproton0010AuAu[44];
  float pT_negproton1020AuAu[44], epT_negproton1020AuAu[44], yield_negproton1020AuAu[44], eyield_negproton1020AuAu[44];
  float pT_negproton2040AuAu[44], epT_negproton2040AuAu[44], yield_negproton2040AuAu[44], eyield_negproton2040AuAu[44];
  float pT_negproton4060AuAu[44], epT_negproton4060AuAu[44], yield_negproton4060AuAu[44], eyield_negproton4060AuAu[44];
  float pT_negproton6092AuAu[44], epT_negproton6092AuAu[44], yield_negproton6092AuAu[44], eyield_negproton6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fnegproton0010AuAu>>pT_negproton0010AuAu[i]>>yield_negproton0010AuAu[i]>>eyield_negproton0010AuAu[i];
      fnegproton1020AuAu>>pT_negproton1020AuAu[i]>>yield_negproton1020AuAu[i]>>eyield_negproton1020AuAu[i];
      fnegproton2040AuAu>>pT_negproton2040AuAu[i]>>yield_negproton2040AuAu[i]>>eyield_negproton2040AuAu[i];
      fnegproton4060AuAu>>pT_negproton4060AuAu[i]>>yield_negproton4060AuAu[i]>>eyield_negproton4060AuAu[i];
      fnegproton6092AuAu>>pT_negproton6092AuAu[i]>>yield_negproton6092AuAu[i]>>eyield_negproton6092AuAu[i];
      epT_negproton0010AuAu[i] = 0;
      epT_negproton1020AuAu[i] = 0;
      epT_negproton2040AuAu[i] = 0;
      epT_negproton4060AuAu[i] = 0;
      epT_negproton6092AuAu[i] = 0;
      // now do some multiplication
      yield_negproton0010AuAu[i] *=20;eyield_negproton0010AuAu[i] *=20;
      yield_negproton1020AuAu[i] *=5;eyield_negproton1020AuAu[i] *=5;
      yield_negproton2040AuAu[i] *=2;eyield_negproton2040AuAu[i] *=2;
    }
  fnegproton0010AuAu.close();
  fnegproton1020AuAu.close();
  fnegproton2040AuAu.close();
  fnegproton4060AuAu.close();
  fnegproton6092AuAu.close();

  // --- now dAu --- //

  ifstream fnegproton0088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_5_dis_cent0088.txt");
  ifstream fnegproton0020dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_5_dis_cent0020.txt");
  ifstream fnegproton2040dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_5_dis_cent2040.txt");
  ifstream fnegproton4060dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_5_dis_cent4060.txt");
  ifstream fnegproton6088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_5_dis_cent6088.txt");

  float pT_negproton0088dAu[36], epT_negproton0088dAu[36], yield_negproton0088dAu[36], eyield_negproton0088dAu[36];
  float pT_negproton0020dAu[36], epT_negproton0020dAu[36], yield_negproton0020dAu[36], eyield_negproton0020dAu[36];
  float pT_negproton2040dAu[36], epT_negproton2040dAu[36], yield_negproton2040dAu[36], eyield_negproton2040dAu[36];
  float pT_negproton4060dAu[36], epT_negproton4060dAu[36], yield_negproton4060dAu[36], eyield_negproton4060dAu[36];
  float pT_negproton6088dAu[36], epT_negproton6088dAu[36], yield_negproton6088dAu[36], eyield_negproton6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fnegproton0088dAu>>pT_negproton0088dAu[i]>>yield_negproton0088dAu[i]>>eyield_negproton0088dAu[i];
      fnegproton0020dAu>>pT_negproton0020dAu[i]>>yield_negproton0020dAu[i]>>eyield_negproton0020dAu[i];
      fnegproton2040dAu>>pT_negproton2040dAu[i]>>yield_negproton2040dAu[i]>>eyield_negproton2040dAu[i];
      fnegproton4060dAu>>pT_negproton4060dAu[i]>>yield_negproton4060dAu[i]>>eyield_negproton4060dAu[i];
      fnegproton6088dAu>>pT_negproton6088dAu[i]>>yield_negproton6088dAu[i]>>eyield_negproton6088dAu[i];
      epT_negproton0088dAu[i] = 0;
      epT_negproton0020dAu[i] = 0;
      epT_negproton2040dAu[i] = 0;
      epT_negproton4060dAu[i] = 0;
      epT_negproton6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  yield_negproton0088dAu[i] = 0;
	  yield_negproton0020dAu[i] = 0;
	  yield_negproton2040dAu[i] = 0;
	  yield_negproton4060dAu[i] = 0;
	  yield_negproton6088dAu[i] = 0;
	  eyield_negproton0088dAu[i] = 0;
	  eyield_negproton0020dAu[i] = 0;
	  eyield_negproton2040dAu[i] = 0;
	  eyield_negproton4060dAu[i] = 0;
	  eyield_negproton6088dAu[i] = 0;
	}
      // yield_negproton0088dAu[i] *= 1e-1;eyield_negproton0088dAu[i] *= 1e-1;
      // yield_negproton0020dAu[i] *= 1e-2;eyield_negproton0020dAu[i] *= 1e-2;
      // yield_negproton2040dAu[i] *= 2e-3;eyield_negproton2040dAu[i] *= 2e-3;
      // yield_negproton4060dAu[i] *= 3e-4;eyield_negproton4060dAu[i] *= 3e-4;
      // yield_negproton6088dAu[i] *= 6e-5;eyield_negproton6088dAu[i] *= 6e-5;
      yield_negproton0020dAu[i] *= 1.3e-1;eyield_negproton0020dAu[i] *= 1.3e-1;
      yield_negproton0088dAu[i] *= 5.0e-2;eyield_negproton0088dAu[i] *= 5.0e-2;
      yield_negproton2040dAu[i] *= 7.5e-3;eyield_negproton2040dAu[i] *= 7.5e-3;
      yield_negproton4060dAu[i] *= 2.0e-3;eyield_negproton4060dAu[i] *= 2.0e-3;
      yield_negproton6088dAu[i] *= 1.0e-3;eyield_negproton6088dAu[i] *= 1.0e-3;
    }
  fnegproton0088dAu.close();
  fnegproton0020dAu.close();
  fnegproton2040dAu.close();
  fnegproton4060dAu.close();
  fnegproton6088dAu.close();




  TGraphErrors *tge_negproton0010AuAu = new TGraphErrors(36,pT_negproton0010AuAu,yield_negproton0010AuAu,epT_negproton0010AuAu,eyield_negproton0010AuAu);
  tge_negproton0010AuAu->SetMarkerColor(kBlack);
  tge_negproton0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_negproton1020AuAu = new TGraphErrors(36,pT_negproton1020AuAu,yield_negproton1020AuAu,epT_negproton1020AuAu,eyield_negproton1020AuAu);
  tge_negproton1020AuAu->SetMarkerColor(kBlack);
  tge_negproton1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_negproton2040AuAu = new TGraphErrors(36,pT_negproton2040AuAu,yield_negproton2040AuAu,epT_negproton2040AuAu,eyield_negproton2040AuAu);
  tge_negproton2040AuAu->SetMarkerColor(kBlack);
  tge_negproton2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_negproton4060AuAu = new TGraphErrors(36,pT_negproton4060AuAu,yield_negproton4060AuAu,epT_negproton4060AuAu,eyield_negproton4060AuAu);
  tge_negproton4060AuAu->SetMarkerColor(kBlack);
  tge_negproton4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_negproton6092AuAu = new TGraphErrors(36,pT_negproton6092AuAu,yield_negproton6092AuAu,epT_negproton6092AuAu,eyield_negproton6092AuAu);
  tge_negproton6092AuAu->SetMarkerColor(kBlack);
  tge_negproton6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_negproton0088dAu = new TGraphErrors(36,pT_negproton0088dAu,yield_negproton0088dAu,epT_negproton0088dAu,eyield_negproton0088dAu);
  tge_negproton0088dAu->SetMarkerColor(kBlack);
  tge_negproton0088dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_negproton0020dAu = new TGraphErrors(36,pT_negproton0020dAu,yield_negproton0020dAu,epT_negproton0020dAu,eyield_negproton0020dAu);
  tge_negproton0020dAu->SetMarkerColor(kBlack);
  tge_negproton0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_negproton2040dAu = new TGraphErrors(36,pT_negproton2040dAu,yield_negproton2040dAu,epT_negproton2040dAu,eyield_negproton2040dAu);
  tge_negproton2040dAu->SetMarkerColor(kBlack);
  tge_negproton2040dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_negproton4060dAu = new TGraphErrors(36,pT_negproton4060dAu,yield_negproton4060dAu,epT_negproton4060dAu,eyield_negproton4060dAu);
  tge_negproton4060dAu->SetMarkerColor(kBlack);
  tge_negproton4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_negproton6088dAu = new TGraphErrors(36,pT_negproton6088dAu,yield_negproton6088dAu,epT_negproton6088dAu,eyield_negproton6088dAu);
  tge_negproton6088dAu->SetMarkerColor(kBlack);
  tge_negproton6088dAu->SetMarkerStyle(kOpenDiamond);

  c1->cd(2); // second panel of canvas

  TMultiGraph *negproton = new TMultiGraph();
  negproton->Add(tge_negproton0010AuAu);
  negproton->Add(tge_negproton1020AuAu);
  negproton->Add(tge_negproton2040AuAu);
  negproton->Add(tge_negproton4060AuAu);
  negproton->Add(tge_negproton6092AuAu);
  negproton->Add(tge_negproton0020dAu);
  negproton->Add(tge_negproton0088dAu);
  negproton->Add(tge_negproton2040dAu);
  negproton->Add(tge_negproton4060dAu);
  negproton->Add(tge_negproton6088dAu);
  negproton->Draw("ap");
  // negproton->SetMaximum(1e5);
  // negproton->SetMinimum(1e-12);
  // negproton->SetMaximum(1e6);
  // negproton->SetMinimum(1e-9);
  negproton->SetMaximum(1e6);
  negproton->SetMinimum(1e-10);
  negproton->GetXaxis()->SetLimits(0.0,6.0);
  negproton->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  negproton->GetXaxis()->CenterTitle();
  negproton->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  negproton->GetYaxis()->CenterTitle();

  TLegend *leg_negproton = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_negproton = new TLegend(0.48,0.68,0.68,0.88);
  leg_negproton->SetFillColor(kWhite);
  leg_negproton->SetBorderSize(0);
  leg_negproton->SetHeader("Au+Au");
  leg_negproton->AddEntry(tge_negproton0010AuAu,"0-10%","p");
  leg_negproton->AddEntry(tge_negproton1020AuAu,"10-20%","p");
  leg_negproton->AddEntry(tge_negproton2040AuAu,"20-40%","p");
  leg_negproton->AddEntry(tge_negproton4060AuAu,"40-60%","p");
  leg_negproton->AddEntry(tge_negproton6092AuAu,"60-92%","p");
  leg_negproton->Draw();

  TLegend *leg_negproton2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_negproton2 = new TLegend(0.68,0.68,0.88,0.88);
  leg_negproton2->SetFillColor(kWhite);
  leg_negproton2->SetBorderSize(0);
  leg_negproton2->SetHeader("d+Au");
  leg_negproton2->AddEntry(tge_negproton0020dAu,"0-20%","p");
  leg_negproton2->AddEntry(tge_negproton0088dAu,"0-88%","p");
  leg_negproton2->AddEntry(tge_negproton2040dAu,"20-40%","p");
  leg_negproton2->AddEntry(tge_negproton4060dAu,"40-60%","p");
  leg_negproton2->AddEntry(tge_negproton6088dAu,"60-88%","p");
  leg_negproton2->Draw();







}
