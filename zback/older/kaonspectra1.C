void kaonspectra1()
{

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->SetLogy();
  c1->Divide(2,1);
  c1_1->SetLogy();
  c1_2->SetLogy();

  // --- now AuAu --- //

  ifstream fposkaon0010AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_4_dis_cent0010.txt");
  ifstream fposkaon1020AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_4_dis_cent1020.txt");
  ifstream fposkaon2040AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_4_dis_cent2040.txt");
  ifstream fposkaon4060AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_4_dis_cent4060.txt");
  ifstream fposkaon6092AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_4_dis_cent6092.txt");

  float pT_poskaon0010AuAu[44], epT_poskaon0010AuAu[44], yield_poskaon0010AuAu[44], eyield_poskaon0010AuAu[44];
  float pT_poskaon1020AuAu[44], epT_poskaon1020AuAu[44], yield_poskaon1020AuAu[44], eyield_poskaon1020AuAu[44];
  float pT_poskaon2040AuAu[44], epT_poskaon2040AuAu[44], yield_poskaon2040AuAu[44], eyield_poskaon2040AuAu[44];
  float pT_poskaon4060AuAu[44], epT_poskaon4060AuAu[44], yield_poskaon4060AuAu[44], eyield_poskaon4060AuAu[44];
  float pT_poskaon6092AuAu[44], epT_poskaon6092AuAu[44], yield_poskaon6092AuAu[44], eyield_poskaon6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fposkaon0010AuAu>>pT_poskaon0010AuAu[i]>>yield_poskaon0010AuAu[i]>>eyield_poskaon0010AuAu[i];
      fposkaon1020AuAu>>pT_poskaon1020AuAu[i]>>yield_poskaon1020AuAu[i]>>eyield_poskaon1020AuAu[i];
      fposkaon2040AuAu>>pT_poskaon2040AuAu[i]>>yield_poskaon2040AuAu[i]>>eyield_poskaon2040AuAu[i];
      fposkaon4060AuAu>>pT_poskaon4060AuAu[i]>>yield_poskaon4060AuAu[i]>>eyield_poskaon4060AuAu[i];
      fposkaon6092AuAu>>pT_poskaon6092AuAu[i]>>yield_poskaon6092AuAu[i]>>eyield_poskaon6092AuAu[i];
      epT_poskaon0010AuAu[i] = 0;
      epT_poskaon1020AuAu[i] = 0;
      epT_poskaon2040AuAu[i] = 0;
      epT_poskaon4060AuAu[i] = 0;
      epT_poskaon6092AuAu[i] = 0;
      // now do some multiplication
      yield_poskaon0010AuAu[i] *=20;eyield_poskaon0010AuAu[i] *=20;
      yield_poskaon1020AuAu[i] *=5;eyield_poskaon1020AuAu[i] *=5;
      yield_poskaon2040AuAu[i] *=2;eyield_poskaon2040AuAu[i] *=2;
    }
  fposkaon0010AuAu.close();
  fposkaon1020AuAu.close();
  fposkaon2040AuAu.close();
  fposkaon4060AuAu.close();
  fposkaon6092AuAu.close();

  // --- now dAu --- //

  ifstream fposkaon0088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_3_dis_cent0088.txt");
  ifstream fposkaon0020dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_3_dis_cent0020.txt");
  ifstream fposkaon2040dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_3_dis_cent2040.txt");
  ifstream fposkaon4060dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_3_dis_cent4060.txt");
  ifstream fposkaon6088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_3_dis_cent6088.txt");

  float pT_poskaon0088dAu[36], epT_poskaon0088dAu[36], yield_poskaon0088dAu[36], eyield_poskaon0088dAu[36];
  float pT_poskaon0020dAu[36], epT_poskaon0020dAu[36], yield_poskaon0020dAu[36], eyield_poskaon0020dAu[36];
  float pT_poskaon2040dAu[36], epT_poskaon2040dAu[36], yield_poskaon2040dAu[36], eyield_poskaon2040dAu[36];
  float pT_poskaon4060dAu[36], epT_poskaon4060dAu[36], yield_poskaon4060dAu[36], eyield_poskaon4060dAu[36];
  float pT_poskaon6088dAu[36], epT_poskaon6088dAu[36], yield_poskaon6088dAu[36], eyield_poskaon6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fposkaon0088dAu>>pT_poskaon0088dAu[i]>>yield_poskaon0088dAu[i]>>eyield_poskaon0088dAu[i];
      fposkaon0020dAu>>pT_poskaon0020dAu[i]>>yield_poskaon0020dAu[i]>>eyield_poskaon0020dAu[i];
      fposkaon2040dAu>>pT_poskaon2040dAu[i]>>yield_poskaon2040dAu[i]>>eyield_poskaon2040dAu[i];
      fposkaon4060dAu>>pT_poskaon4060dAu[i]>>yield_poskaon4060dAu[i]>>eyield_poskaon4060dAu[i];
      fposkaon6088dAu>>pT_poskaon6088dAu[i]>>yield_poskaon6088dAu[i]>>eyield_poskaon6088dAu[i];
      epT_poskaon0088dAu[i] = 0;
      epT_poskaon0020dAu[i] = 0;
      epT_poskaon2040dAu[i] = 0;
      epT_poskaon4060dAu[i] = 0;
      epT_poskaon6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  yield_poskaon0088dAu[i] = 0;
	  yield_poskaon0020dAu[i] = 0;
	  yield_poskaon2040dAu[i] = 0;
	  yield_poskaon4060dAu[i] = 0;
	  yield_poskaon6088dAu[i] = 0;
	  eyield_poskaon0088dAu[i] = 0;
	  eyield_poskaon0020dAu[i] = 0;
	  eyield_poskaon2040dAu[i] = 0;
	  eyield_poskaon4060dAu[i] = 0;
	  eyield_poskaon6088dAu[i] = 0;
	}
      // dAu scaling
      // got the order reversed :(
      // yield_poskaon0088dAu[i] *= 2.5e-1;eyield_poskaon0088dAu[i] *= 2.5e-1;
      // yield_poskaon0020dAu[i] *= 2.5e-2;eyield_poskaon0020dAu[i] *= 2.5e-2;
      //yield_poskaon0020dAu[i] *= 1.0e-1;eyield_poskaon0020dAu[i] *= 1.0e-1;
      //yield_poskaon0088dAu[i] *= 5.0e-2;eyield_poskaon0088dAu[i] *= 5.0e-2;
      yield_poskaon0020dAu[i] *= 1.3e-1;eyield_poskaon0020dAu[i] *= 1.3e-1;
      yield_poskaon0088dAu[i] *= 5.0e-2;eyield_poskaon0088dAu[i] *= 5.0e-2;
      yield_poskaon2040dAu[i] *= 7.5e-3;eyield_poskaon2040dAu[i] *= 7.5e-3;
      yield_poskaon4060dAu[i] *= 2.0e-3;eyield_poskaon4060dAu[i] *= 2.0e-3;
      yield_poskaon6088dAu[i] *= 1.0e-3;eyield_poskaon6088dAu[i] *= 1.0e-3;
    }
  fposkaon0088dAu.close();
  fposkaon0020dAu.close();
  fposkaon2040dAu.close();
  fposkaon4060dAu.close();
  fposkaon6088dAu.close();




  TGraphErrors *tge_poskaon0010AuAu = new TGraphErrors(36,pT_poskaon0010AuAu,yield_poskaon0010AuAu,epT_poskaon0010AuAu,eyield_poskaon0010AuAu);
  tge_poskaon0010AuAu->SetMarkerColor(kBlack);
  tge_poskaon0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_poskaon1020AuAu = new TGraphErrors(36,pT_poskaon1020AuAu,yield_poskaon1020AuAu,epT_poskaon1020AuAu,eyield_poskaon1020AuAu);
  tge_poskaon1020AuAu->SetMarkerColor(kBlack);
  tge_poskaon1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_poskaon2040AuAu = new TGraphErrors(36,pT_poskaon2040AuAu,yield_poskaon2040AuAu,epT_poskaon2040AuAu,eyield_poskaon2040AuAu);
  tge_poskaon2040AuAu->SetMarkerColor(kBlack);
  tge_poskaon2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_poskaon4060AuAu = new TGraphErrors(36,pT_poskaon4060AuAu,yield_poskaon4060AuAu,epT_poskaon4060AuAu,eyield_poskaon4060AuAu);
  tge_poskaon4060AuAu->SetMarkerColor(kBlack);
  tge_poskaon4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_poskaon6092AuAu = new TGraphErrors(36,pT_poskaon6092AuAu,yield_poskaon6092AuAu,epT_poskaon6092AuAu,eyield_poskaon6092AuAu);
  tge_poskaon6092AuAu->SetMarkerColor(kBlack);
  tge_poskaon6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_poskaon0088dAu = new TGraphErrors(36,pT_poskaon0088dAu,yield_poskaon0088dAu,epT_poskaon0088dAu,eyield_poskaon0088dAu);
  tge_poskaon0088dAu->SetMarkerColor(kBlack);
  tge_poskaon0088dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_poskaon0020dAu = new TGraphErrors(36,pT_poskaon0020dAu,yield_poskaon0020dAu,epT_poskaon0020dAu,eyield_poskaon0020dAu);
  tge_poskaon0020dAu->SetMarkerColor(kBlack);
  tge_poskaon0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_poskaon2040dAu = new TGraphErrors(36,pT_poskaon2040dAu,yield_poskaon2040dAu,epT_poskaon2040dAu,eyield_poskaon2040dAu);
  tge_poskaon2040dAu->SetMarkerColor(kBlack);
  tge_poskaon2040dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_poskaon4060dAu = new TGraphErrors(36,pT_poskaon4060dAu,yield_poskaon4060dAu,epT_poskaon4060dAu,eyield_poskaon4060dAu);
  tge_poskaon4060dAu->SetMarkerColor(kBlack);
  tge_poskaon4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_poskaon6088dAu = new TGraphErrors(36,pT_poskaon6088dAu,yield_poskaon6088dAu,epT_poskaon6088dAu,eyield_poskaon6088dAu);
  tge_poskaon6088dAu->SetMarkerColor(kBlack);
  tge_poskaon6088dAu->SetMarkerStyle(kOpenDiamond);

  c1->cd(1); // first panel of canvas

  TMultiGraph *poskaon = new TMultiGraph();
  poskaon->Add(tge_poskaon0010AuAu);
  poskaon->Add(tge_poskaon1020AuAu);
  poskaon->Add(tge_poskaon2040AuAu);
  poskaon->Add(tge_poskaon4060AuAu);
  poskaon->Add(tge_poskaon6092AuAu);
  poskaon->Add(tge_poskaon0020dAu);
  poskaon->Add(tge_poskaon0088dAu);
  poskaon->Add(tge_poskaon2040dAu);
  poskaon->Add(tge_poskaon4060dAu);
  poskaon->Add(tge_poskaon6088dAu);
  poskaon->Draw("ap");
  poskaon->SetMaximum(1e6);
  poskaon->SetMinimum(1e-9);
  poskaon->GetXaxis()->SetLimits(0.0,6.0);
  poskaon->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  poskaon->GetXaxis()->CenterTitle();
  poskaon->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  poskaon->GetYaxis()->CenterTitle();

  TLegend *leg_poskaon = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_poskaon = new TLegend(0.48,0.68,0.68,0.88);
  //TLegend *leg_poskaon = new TLegend(0.28,0.68,0.58,0.88);
  //TLegend *leg_poskaon = new TLegend(0.48,0.48,0.68,0.88);
  leg_poskaon->SetFillColor(kWhite);
  leg_poskaon->SetBorderSize(0);
  leg_poskaon->SetHeader("Au+Au");
  leg_poskaon->AddEntry(tge_poskaon0010AuAu,"0-10%","p");
  leg_poskaon->AddEntry(tge_poskaon1020AuAu,"10-20%","p");
  leg_poskaon->AddEntry(tge_poskaon2040AuAu,"20-40%","p");
  leg_poskaon->AddEntry(tge_poskaon4060AuAu,"40-60%","p");
  leg_poskaon->AddEntry(tge_poskaon6092AuAu,"60-92%","p");
  leg_poskaon->Draw();

  TLegend *leg_poskaon2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_poskaon2 = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg_poskaon2 = new TLegend(0.58,0.68,0.88,0.88);
  //TLegend *leg_poskaon2 = new TLegend(0.58,0.48,0.88,0.88);
  leg_poskaon2->SetFillColor(kWhite);
  leg_poskaon2->SetBorderSize(0);
  leg_poskaon2->SetHeader("d+Au");
  leg_poskaon2->AddEntry(tge_poskaon0020dAu,"0-20%","p");
  leg_poskaon2->AddEntry(tge_poskaon0088dAu,"0-88%","p");
  leg_poskaon2->AddEntry(tge_poskaon2040dAu,"20-40%","p");
  leg_poskaon2->AddEntry(tge_poskaon4060dAu,"40-60%","p");
  leg_poskaon2->AddEntry(tge_poskaon6088dAu,"60-88%","p");
  leg_poskaon2->Draw();



  // ---
  // ---
  // --- now negative --- //
  // -------------------- //
  // -------------------- //

  // --- now AuAu --- //

  ifstream fnegkaon0010AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_4_dis_cent0010.txt");
  ifstream fnegkaon1020AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_4_dis_cent1020.txt");
  ifstream fnegkaon2040AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_4_dis_cent2040.txt");
  ifstream fnegkaon4060AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_4_dis_cent4060.txt");
  ifstream fnegkaon6092AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_4_dis_cent6092.txt");

  float pT_negkaon0010AuAu[44], epT_negkaon0010AuAu[44], yield_negkaon0010AuAu[44], eyield_negkaon0010AuAu[44];
  float pT_negkaon1020AuAu[44], epT_negkaon1020AuAu[44], yield_negkaon1020AuAu[44], eyield_negkaon1020AuAu[44];
  float pT_negkaon2040AuAu[44], epT_negkaon2040AuAu[44], yield_negkaon2040AuAu[44], eyield_negkaon2040AuAu[44];
  float pT_negkaon4060AuAu[44], epT_negkaon4060AuAu[44], yield_negkaon4060AuAu[44], eyield_negkaon4060AuAu[44];
  float pT_negkaon6092AuAu[44], epT_negkaon6092AuAu[44], yield_negkaon6092AuAu[44], eyield_negkaon6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fnegkaon0010AuAu>>pT_negkaon0010AuAu[i]>>yield_negkaon0010AuAu[i]>>eyield_negkaon0010AuAu[i];
      fnegkaon1020AuAu>>pT_negkaon1020AuAu[i]>>yield_negkaon1020AuAu[i]>>eyield_negkaon1020AuAu[i];
      fnegkaon2040AuAu>>pT_negkaon2040AuAu[i]>>yield_negkaon2040AuAu[i]>>eyield_negkaon2040AuAu[i];
      fnegkaon4060AuAu>>pT_negkaon4060AuAu[i]>>yield_negkaon4060AuAu[i]>>eyield_negkaon4060AuAu[i];
      fnegkaon6092AuAu>>pT_negkaon6092AuAu[i]>>yield_negkaon6092AuAu[i]>>eyield_negkaon6092AuAu[i];
      epT_negkaon0010AuAu[i] = 0;
      epT_negkaon1020AuAu[i] = 0;
      epT_negkaon2040AuAu[i] = 0;
      epT_negkaon4060AuAu[i] = 0;
      epT_negkaon6092AuAu[i] = 0;
      // now do some multiplication
      yield_negkaon0010AuAu[i] *=20;eyield_negkaon0010AuAu[i] *=20;
      yield_negkaon1020AuAu[i] *=5;eyield_negkaon1020AuAu[i] *=5;
      yield_negkaon2040AuAu[i] *=2;eyield_negkaon2040AuAu[i] *=2;
    }
  fnegkaon0010AuAu.close();
  fnegkaon1020AuAu.close();
  fnegkaon2040AuAu.close();
  fnegkaon4060AuAu.close();
  fnegkaon6092AuAu.close();

  // --- now dAu --- //

  ifstream fnegkaon0088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_3_dis_cent0088.txt");
  ifstream fnegkaon0020dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_3_dis_cent0020.txt");
  ifstream fnegkaon2040dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_3_dis_cent2040.txt");
  ifstream fnegkaon4060dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_3_dis_cent4060.txt");
  ifstream fnegkaon6088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_3_dis_cent6088.txt");

  float pT_negkaon0088dAu[36], epT_negkaon0088dAu[36], yield_negkaon0088dAu[36], eyield_negkaon0088dAu[36];
  float pT_negkaon0020dAu[36], epT_negkaon0020dAu[36], yield_negkaon0020dAu[36], eyield_negkaon0020dAu[36];
  float pT_negkaon2040dAu[36], epT_negkaon2040dAu[36], yield_negkaon2040dAu[36], eyield_negkaon2040dAu[36];
  float pT_negkaon4060dAu[36], epT_negkaon4060dAu[36], yield_negkaon4060dAu[36], eyield_negkaon4060dAu[36];
  float pT_negkaon6088dAu[36], epT_negkaon6088dAu[36], yield_negkaon6088dAu[36], eyield_negkaon6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fnegkaon0088dAu>>pT_negkaon0088dAu[i]>>yield_negkaon0088dAu[i]>>eyield_negkaon0088dAu[i];
      fnegkaon0020dAu>>pT_negkaon0020dAu[i]>>yield_negkaon0020dAu[i]>>eyield_negkaon0020dAu[i];
      fnegkaon2040dAu>>pT_negkaon2040dAu[i]>>yield_negkaon2040dAu[i]>>eyield_negkaon2040dAu[i];
      fnegkaon4060dAu>>pT_negkaon4060dAu[i]>>yield_negkaon4060dAu[i]>>eyield_negkaon4060dAu[i];
      fnegkaon6088dAu>>pT_negkaon6088dAu[i]>>yield_negkaon6088dAu[i]>>eyield_negkaon6088dAu[i];
      epT_negkaon0088dAu[i] = 0;
      epT_negkaon0020dAu[i] = 0;
      epT_negkaon2040dAu[i] = 0;
      epT_negkaon4060dAu[i] = 0;
      epT_negkaon6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  yield_negkaon0088dAu[i] = 0;
	  yield_negkaon0020dAu[i] = 0;
	  yield_negkaon2040dAu[i] = 0;
	  yield_negkaon4060dAu[i] = 0;
	  yield_negkaon6088dAu[i] = 0;
	  eyield_negkaon0088dAu[i] = 0;
	  eyield_negkaon0020dAu[i] = 0;
	  eyield_negkaon2040dAu[i] = 0;
	  eyield_negkaon4060dAu[i] = 0;
	  eyield_negkaon6088dAu[i] = 0;
	}
      // yield_negkaon0088dAu[i] *= 1e-1;eyield_negkaon0088dAu[i] *= 1e-1;
      // yield_negkaon0020dAu[i] *= 1e-2;eyield_negkaon0020dAu[i] *= 1e-2;
      // yield_negkaon2040dAu[i] *= 2e-3;eyield_negkaon2040dAu[i] *= 2e-3;
      // yield_negkaon4060dAu[i] *= 3e-4;eyield_negkaon4060dAu[i] *= 3e-4;
      // yield_negkaon6088dAu[i] *= 6e-5;eyield_negkaon6088dAu[i] *= 6e-5;
      yield_negkaon0020dAu[i] *= 1.3e-1;eyield_negkaon0020dAu[i] *= 1.3e-1;
      yield_negkaon0088dAu[i] *= 5.0e-2;eyield_negkaon0088dAu[i] *= 5.0e-2;
      yield_negkaon2040dAu[i] *= 7.5e-3;eyield_negkaon2040dAu[i] *= 7.5e-3;
      yield_negkaon4060dAu[i] *= 2.0e-3;eyield_negkaon4060dAu[i] *= 2.0e-3;
      yield_negkaon6088dAu[i] *= 1.0e-3;eyield_negkaon6088dAu[i] *= 1.0e-3;
    }
  fnegkaon0088dAu.close();
  fnegkaon0020dAu.close();
  fnegkaon2040dAu.close();
  fnegkaon4060dAu.close();
  fnegkaon6088dAu.close();




  TGraphErrors *tge_negkaon0010AuAu = new TGraphErrors(36,pT_negkaon0010AuAu,yield_negkaon0010AuAu,epT_negkaon0010AuAu,eyield_negkaon0010AuAu);
  tge_negkaon0010AuAu->SetMarkerColor(kBlack);
  tge_negkaon0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_negkaon1020AuAu = new TGraphErrors(36,pT_negkaon1020AuAu,yield_negkaon1020AuAu,epT_negkaon1020AuAu,eyield_negkaon1020AuAu);
  tge_negkaon1020AuAu->SetMarkerColor(kBlack);
  tge_negkaon1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_negkaon2040AuAu = new TGraphErrors(36,pT_negkaon2040AuAu,yield_negkaon2040AuAu,epT_negkaon2040AuAu,eyield_negkaon2040AuAu);
  tge_negkaon2040AuAu->SetMarkerColor(kBlack);
  tge_negkaon2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_negkaon4060AuAu = new TGraphErrors(36,pT_negkaon4060AuAu,yield_negkaon4060AuAu,epT_negkaon4060AuAu,eyield_negkaon4060AuAu);
  tge_negkaon4060AuAu->SetMarkerColor(kBlack);
  tge_negkaon4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_negkaon6092AuAu = new TGraphErrors(36,pT_negkaon6092AuAu,yield_negkaon6092AuAu,epT_negkaon6092AuAu,eyield_negkaon6092AuAu);
  tge_negkaon6092AuAu->SetMarkerColor(kBlack);
  tge_negkaon6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_negkaon0088dAu = new TGraphErrors(36,pT_negkaon0088dAu,yield_negkaon0088dAu,epT_negkaon0088dAu,eyield_negkaon0088dAu);
  tge_negkaon0088dAu->SetMarkerColor(kBlack);
  tge_negkaon0088dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_negkaon0020dAu = new TGraphErrors(36,pT_negkaon0020dAu,yield_negkaon0020dAu,epT_negkaon0020dAu,eyield_negkaon0020dAu);
  tge_negkaon0020dAu->SetMarkerColor(kBlack);
  tge_negkaon0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_negkaon2040dAu = new TGraphErrors(36,pT_negkaon2040dAu,yield_negkaon2040dAu,epT_negkaon2040dAu,eyield_negkaon2040dAu);
  tge_negkaon2040dAu->SetMarkerColor(kBlack);
  tge_negkaon2040dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_negkaon4060dAu = new TGraphErrors(36,pT_negkaon4060dAu,yield_negkaon4060dAu,epT_negkaon4060dAu,eyield_negkaon4060dAu);
  tge_negkaon4060dAu->SetMarkerColor(kBlack);
  tge_negkaon4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_negkaon6088dAu = new TGraphErrors(36,pT_negkaon6088dAu,yield_negkaon6088dAu,epT_negkaon6088dAu,eyield_negkaon6088dAu);
  tge_negkaon6088dAu->SetMarkerColor(kBlack);
  tge_negkaon6088dAu->SetMarkerStyle(kOpenDiamond);

  c1->cd(2); // second panel of canvas

  TMultiGraph *negkaon = new TMultiGraph();
  negkaon->Add(tge_negkaon0010AuAu);
  negkaon->Add(tge_negkaon1020AuAu);
  negkaon->Add(tge_negkaon2040AuAu);
  negkaon->Add(tge_negkaon4060AuAu);
  negkaon->Add(tge_negkaon6092AuAu);
  negkaon->Add(tge_negkaon0020dAu);
  negkaon->Add(tge_negkaon0088dAu);
  negkaon->Add(tge_negkaon2040dAu);
  negkaon->Add(tge_negkaon4060dAu);
  negkaon->Add(tge_negkaon6088dAu);
  negkaon->Draw("ap");
  // negkaon->SetMaximum(1e5);
  // negkaon->SetMinimum(1e-12);
  negkaon->SetMaximum(1e6);
  negkaon->SetMinimum(1e-9);
  negkaon->GetXaxis()->SetLimits(0.0,6.0);
  negkaon->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  negkaon->GetXaxis()->CenterTitle();
  negkaon->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  negkaon->GetYaxis()->CenterTitle();

  TLegend *leg_negkaon = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_negkaon = new TLegend(0.48,0.68,0.68,0.88);
  leg_negkaon->SetFillColor(kWhite);
  leg_negkaon->SetBorderSize(0);
  leg_negkaon->SetHeader("Au+Au");
  leg_negkaon->AddEntry(tge_negkaon0010AuAu,"0-10%","p");
  leg_negkaon->AddEntry(tge_negkaon1020AuAu,"10-20%","p");
  leg_negkaon->AddEntry(tge_negkaon2040AuAu,"20-40%","p");
  leg_negkaon->AddEntry(tge_negkaon4060AuAu,"40-60%","p");
  leg_negkaon->AddEntry(tge_negkaon6092AuAu,"60-92%","p");
  leg_negkaon->Draw();

  TLegend *leg_negkaon2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_negkaon2 = new TLegend(0.68,0.68,0.88,0.88);
  leg_negkaon2->SetFillColor(kWhite);
  leg_negkaon2->SetBorderSize(0);
  leg_negkaon2->SetHeader("d+Au");
  leg_negkaon2->AddEntry(tge_negkaon0020dAu,"0-20%","p");
  leg_negkaon2->AddEntry(tge_negkaon0088dAu,"0-88%","p");
  leg_negkaon2->AddEntry(tge_negkaon2040dAu,"20-40%","p");
  leg_negkaon2->AddEntry(tge_negkaon4060dAu,"40-60%","p");
  leg_negkaon2->AddEntry(tge_negkaon6088dAu,"60-88%","p");
  leg_negkaon2->Draw();







}
