void pionspectra1()
{

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->SetLogy();
  c1->Divide(2,1);
  c1_1->SetLogy();
  c1_2->SetLogy();

  // --- now AuAu --- //

  ifstream fpospion0010AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_2_dis_cent0010.txt");
  ifstream fpospion1020AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_2_dis_cent1020.txt");
  ifstream fpospion2040AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_2_dis_cent2040.txt");
  ifstream fpospion4060AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_2_dis_cent4060.txt");
  ifstream fpospion6092AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_2_dis_cent6092.txt");

  float pT_pospion0010AuAu[44], epT_pospion0010AuAu[44], yield_pospion0010AuAu[44], eyield_pospion0010AuAu[44];
  float pT_pospion1020AuAu[44], epT_pospion1020AuAu[44], yield_pospion1020AuAu[44], eyield_pospion1020AuAu[44];
  float pT_pospion2040AuAu[44], epT_pospion2040AuAu[44], yield_pospion2040AuAu[44], eyield_pospion2040AuAu[44];
  float pT_pospion4060AuAu[44], epT_pospion4060AuAu[44], yield_pospion4060AuAu[44], eyield_pospion4060AuAu[44];
  float pT_pospion6092AuAu[44], epT_pospion6092AuAu[44], yield_pospion6092AuAu[44], eyield_pospion6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fpospion0010AuAu>>pT_pospion0010AuAu[i]>>yield_pospion0010AuAu[i]>>eyield_pospion0010AuAu[i];
      fpospion1020AuAu>>pT_pospion1020AuAu[i]>>yield_pospion1020AuAu[i]>>eyield_pospion1020AuAu[i];
      fpospion2040AuAu>>pT_pospion2040AuAu[i]>>yield_pospion2040AuAu[i]>>eyield_pospion2040AuAu[i];
      fpospion4060AuAu>>pT_pospion4060AuAu[i]>>yield_pospion4060AuAu[i]>>eyield_pospion4060AuAu[i];
      fpospion6092AuAu>>pT_pospion6092AuAu[i]>>yield_pospion6092AuAu[i]>>eyield_pospion6092AuAu[i];
      epT_pospion0010AuAu[i] = 0;
      epT_pospion1020AuAu[i] = 0;
      epT_pospion2040AuAu[i] = 0;
      epT_pospion4060AuAu[i] = 0;
      epT_pospion6092AuAu[i] = 0;
      // now do some multiplication
      yield_pospion0010AuAu[i] *=20;eyield_pospion0010AuAu[i] *=20;
      yield_pospion1020AuAu[i] *=5;eyield_pospion1020AuAu[i] *=5;
      yield_pospion2040AuAu[i] *=2;eyield_pospion2040AuAu[i] *=2;
      //yield_pospion0020dAu[i] *= 1.3e-1;eyield_pospion0020dAu[i] *= 1.3e-1; // WATCH!!!
      //yield_pospion6092AuAu[i] *= 1.3e-1;eyield_pospion6092AuAu[i] *= 1.3e-1; // WATCH!!!
    }
  fpospion0010AuAu.close();
  fpospion1020AuAu.close();
  fpospion2040AuAu.close();
  fpospion4060AuAu.close();
  fpospion6092AuAu.close();

  // --- now dAu --- //

  ifstream fpospion0088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_1_dis_cent0088.txt");
  ifstream fpospion0020dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_1_dis_cent0020.txt");
  ifstream fpospion2040dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_1_dis_cent2040.txt");
  ifstream fpospion4060dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_1_dis_cent4060.txt");
  ifstream fpospion6088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_poscb_1_dis_cent6088.txt");

  float pT_pospion0088dAu[36], epT_pospion0088dAu[36], yield_pospion0088dAu[36], eyield_pospion0088dAu[36];
  float pT_pospion0020dAu[36], epT_pospion0020dAu[36], yield_pospion0020dAu[36], eyield_pospion0020dAu[36];
  float pT_pospion2040dAu[36], epT_pospion2040dAu[36], yield_pospion2040dAu[36], eyield_pospion2040dAu[36];
  float pT_pospion4060dAu[36], epT_pospion4060dAu[36], yield_pospion4060dAu[36], eyield_pospion4060dAu[36];
  float pT_pospion6088dAu[36], epT_pospion6088dAu[36], yield_pospion6088dAu[36], eyield_pospion6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fpospion0088dAu>>pT_pospion0088dAu[i]>>yield_pospion0088dAu[i]>>eyield_pospion0088dAu[i];
      fpospion0020dAu>>pT_pospion0020dAu[i]>>yield_pospion0020dAu[i]>>eyield_pospion0020dAu[i];
      fpospion2040dAu>>pT_pospion2040dAu[i]>>yield_pospion2040dAu[i]>>eyield_pospion2040dAu[i];
      fpospion4060dAu>>pT_pospion4060dAu[i]>>yield_pospion4060dAu[i]>>eyield_pospion4060dAu[i];
      fpospion6088dAu>>pT_pospion6088dAu[i]>>yield_pospion6088dAu[i]>>eyield_pospion6088dAu[i];
      epT_pospion0088dAu[i] = 0;
      epT_pospion0020dAu[i] = 0;
      epT_pospion2040dAu[i] = 0;
      epT_pospion4060dAu[i] = 0;
      epT_pospion6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  yield_pospion0088dAu[i] = 0;
	  yield_pospion0020dAu[i] = 0;
	  yield_pospion2040dAu[i] = 0;
	  yield_pospion4060dAu[i] = 0;
	  yield_pospion6088dAu[i] = 0;
	  eyield_pospion0088dAu[i] = 0;
	  eyield_pospion0020dAu[i] = 0;
	  eyield_pospion2040dAu[i] = 0;
	  eyield_pospion4060dAu[i] = 0;
	  eyield_pospion6088dAu[i] = 0;
	}
      // dAu scaling
      // got the order reversed :(
      // yield_pospion0088dAu[i] *= 2.5e-1;eyield_pospion0088dAu[i] *= 2.5e-1;
      // yield_pospion0020dAu[i] *= 2.5e-2;eyield_pospion0020dAu[i] *= 2.5e-2;
      //yield_pospion0020dAu[i] *= 1.0e-1;eyield_pospion0020dAu[i] *= 1.0e-1;
      //yield_pospion0088dAu[i] *= 5.0e-2;eyield_pospion0088dAu[i] *= 5.0e-2;
      yield_pospion0020dAu[i] *= 1.3e-1;eyield_pospion0020dAu[i] *= 1.3e-1; // WATCH!!!
      //yield_pospion0088dAu[i] *= 5.0e-2;eyield_pospion0088dAu[i] *= 5.0e-2;
      //yield_pospion2040dAu[i] *= 7.5e-3;eyield_pospion2040dAu[i] *= 7.5e-3;
      // yield_pospion2040dAu[i] *= 5.0e-2;eyield_pospion2040dAu[i] *= 5.0e-2;
      // yield_pospion0088dAu[i] *= 7.5e-3;eyield_pospion0088dAu[i] *= 7.5e-3;
      yield_pospion2040dAu[i] *= 3.5e-2;eyield_pospion2040dAu[i] *= 3.5e-2;
      yield_pospion0088dAu[i] *= 7.5e-3;eyield_pospion0088dAu[i] *= 7.5e-3;
      yield_pospion4060dAu[i] *= 2.0e-3;eyield_pospion4060dAu[i] *= 2.0e-3;
      yield_pospion6088dAu[i] *= 1.0e-3;eyield_pospion6088dAu[i] *= 1.0e-3;
    }
  fpospion0088dAu.close();
  fpospion0020dAu.close();
  fpospion2040dAu.close();
  fpospion4060dAu.close();
  fpospion6088dAu.close();




  TGraphErrors *tge_pospion0010AuAu = new TGraphErrors(36,pT_pospion0010AuAu,yield_pospion0010AuAu,epT_pospion0010AuAu,eyield_pospion0010AuAu);
  tge_pospion0010AuAu->SetMarkerColor(kBlack);
  tge_pospion0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_pospion1020AuAu = new TGraphErrors(36,pT_pospion1020AuAu,yield_pospion1020AuAu,epT_pospion1020AuAu,eyield_pospion1020AuAu);
  tge_pospion1020AuAu->SetMarkerColor(kBlack);
  tge_pospion1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_pospion2040AuAu = new TGraphErrors(36,pT_pospion2040AuAu,yield_pospion2040AuAu,epT_pospion2040AuAu,eyield_pospion2040AuAu);
  tge_pospion2040AuAu->SetMarkerColor(kBlack);
  tge_pospion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_pospion4060AuAu = new TGraphErrors(36,pT_pospion4060AuAu,yield_pospion4060AuAu,epT_pospion4060AuAu,eyield_pospion4060AuAu);
  tge_pospion4060AuAu->SetMarkerColor(kBlack);
  tge_pospion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_pospion6092AuAu = new TGraphErrors(36,pT_pospion6092AuAu,yield_pospion6092AuAu,epT_pospion6092AuAu,eyield_pospion6092AuAu);
  tge_pospion6092AuAu->SetMarkerColor(kBlack);
  tge_pospion6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_pospion0088dAu = new TGraphErrors(36,pT_pospion0088dAu,yield_pospion0088dAu,epT_pospion0088dAu,eyield_pospion0088dAu);
  tge_pospion0088dAu->SetMarkerColor(kBlack);
  tge_pospion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_pospion0020dAu = new TGraphErrors(36,pT_pospion0020dAu,yield_pospion0020dAu,epT_pospion0020dAu,eyield_pospion0020dAu);
  tge_pospion0020dAu->SetMarkerColor(kBlack);
  tge_pospion0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_pospion2040dAu = new TGraphErrors(36,pT_pospion2040dAu,yield_pospion2040dAu,epT_pospion2040dAu,eyield_pospion2040dAu);
  tge_pospion2040dAu->SetMarkerColor(kBlack);
  tge_pospion2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_pospion4060dAu = new TGraphErrors(36,pT_pospion4060dAu,yield_pospion4060dAu,epT_pospion4060dAu,eyield_pospion4060dAu);
  tge_pospion4060dAu->SetMarkerColor(kBlack);
  tge_pospion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_pospion6088dAu = new TGraphErrors(36,pT_pospion6088dAu,yield_pospion6088dAu,epT_pospion6088dAu,eyield_pospion6088dAu);
  tge_pospion6088dAu->SetMarkerColor(kBlack);
  tge_pospion6088dAu->SetMarkerStyle(kOpenDiamond);

  c1->cd(1); // first panel of canvas

  TMultiGraph *pospion = new TMultiGraph();
  pospion->Add(tge_pospion0010AuAu);
  pospion->Add(tge_pospion1020AuAu);
  pospion->Add(tge_pospion2040AuAu);
  pospion->Add(tge_pospion4060AuAu);
  pospion->Add(tge_pospion6092AuAu);
  pospion->Add(tge_pospion0020dAu);
  pospion->Add(tge_pospion0088dAu);
  pospion->Add(tge_pospion2040dAu);
  pospion->Add(tge_pospion4060dAu);
  pospion->Add(tge_pospion6088dAu);
  pospion->Draw("ap");
  pospion->SetMaximum(1e6);
  pospion->SetMinimum(1e-9);
  pospion->GetXaxis()->SetLimits(0.0,6.0);
  pospion->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  pospion->GetXaxis()->CenterTitle();
  pospion->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  pospion->GetYaxis()->CenterTitle();

  TLegend *leg_pospion = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_pospion = new TLegend(0.48,0.68,0.68,0.88);
  //TLegend *leg_pospion = new TLegend(0.28,0.68,0.58,0.88);
  //TLegend *leg_pospion = new TLegend(0.48,0.48,0.68,0.88);
  leg_pospion->SetFillColor(kWhite);
  leg_pospion->SetBorderSize(0);
  leg_pospion->SetHeader("Au+Au");
  leg_pospion->AddEntry(tge_pospion0010AuAu,"0-10%","p");
  leg_pospion->AddEntry(tge_pospion1020AuAu,"10-20%","p");
  leg_pospion->AddEntry(tge_pospion2040AuAu,"20-40%","p");
  leg_pospion->AddEntry(tge_pospion4060AuAu,"40-60%","p");
  leg_pospion->AddEntry(tge_pospion6092AuAu,"60-92%","p");
  leg_pospion->Draw();

  TLegend *leg_pospion2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.68,0.68,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.58,0.68,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.58,0.48,0.88,0.88);
  leg_pospion2->SetFillColor(kWhite);
  leg_pospion2->SetBorderSize(0);
  leg_pospion2->SetHeader("d+Au");
  leg_pospion2->AddEntry(tge_pospion0020dAu,"0-20%","p");
  leg_pospion2->AddEntry(tge_pospion2040dAu,"20-40%","p");
  leg_pospion2->AddEntry(tge_pospion0088dAu,"0-88%","p");
  leg_pospion2->AddEntry(tge_pospion4060dAu,"40-60%","p");
  leg_pospion2->AddEntry(tge_pospion6088dAu,"60-88%","p");
  leg_pospion2->Draw();



  // ---
  // ---
  // --- now negative --- //
  // -------------------- //
  // -------------------- //

  // --- now AuAu --- //

  ifstream fnegpion0010AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_2_dis_cent0010.txt");
  ifstream fnegpion1020AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_2_dis_cent1020.txt");
  ifstream fnegpion2040AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_2_dis_cent2040.txt");
  ifstream fnegpion4060AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_2_dis_cent4060.txt");
  ifstream fnegpion6092AuAu("../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_2_dis_cent6092.txt");

  float pT_negpion0010AuAu[44], epT_negpion0010AuAu[44], yield_negpion0010AuAu[44], eyield_negpion0010AuAu[44];
  float pT_negpion1020AuAu[44], epT_negpion1020AuAu[44], yield_negpion1020AuAu[44], eyield_negpion1020AuAu[44];
  float pT_negpion2040AuAu[44], epT_negpion2040AuAu[44], yield_negpion2040AuAu[44], eyield_negpion2040AuAu[44];
  float pT_negpion4060AuAu[44], epT_negpion4060AuAu[44], yield_negpion4060AuAu[44], eyield_negpion4060AuAu[44];
  float pT_negpion6092AuAu[44], epT_negpion6092AuAu[44], yield_negpion6092AuAu[44], eyield_negpion6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fnegpion0010AuAu>>pT_negpion0010AuAu[i]>>yield_negpion0010AuAu[i]>>eyield_negpion0010AuAu[i];
      fnegpion1020AuAu>>pT_negpion1020AuAu[i]>>yield_negpion1020AuAu[i]>>eyield_negpion1020AuAu[i];
      fnegpion2040AuAu>>pT_negpion2040AuAu[i]>>yield_negpion2040AuAu[i]>>eyield_negpion2040AuAu[i];
      fnegpion4060AuAu>>pT_negpion4060AuAu[i]>>yield_negpion4060AuAu[i]>>eyield_negpion4060AuAu[i];
      fnegpion6092AuAu>>pT_negpion6092AuAu[i]>>yield_negpion6092AuAu[i]>>eyield_negpion6092AuAu[i];
      epT_negpion0010AuAu[i] = 0;
      epT_negpion1020AuAu[i] = 0;
      epT_negpion2040AuAu[i] = 0;
      epT_negpion4060AuAu[i] = 0;
      epT_negpion6092AuAu[i] = 0;
      // now do some multiplication
      yield_negpion0010AuAu[i] *=20;eyield_negpion0010AuAu[i] *=20;
      yield_negpion1020AuAu[i] *=5;eyield_negpion1020AuAu[i] *=5;
      yield_negpion2040AuAu[i] *=2;eyield_negpion2040AuAu[i] *=2;
    }
  fnegpion0010AuAu.close();
  fnegpion1020AuAu.close();
  fnegpion2040AuAu.close();
  fnegpion4060AuAu.close();
  fnegpion6092AuAu.close();

  // --- now dAu --- //

  ifstream fnegpion0088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_1_dis_cent0088.txt");
  ifstream fnegpion0020dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_1_dis_cent0020.txt");
  ifstream fnegpion2040dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_1_dis_cent2040.txt");
  ifstream fnegpion4060dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_1_dis_cent4060.txt");
  ifstream fnegpion6088dAu("../Run8dAu/Spectra/Text/ptpid_tofw_negcb_1_dis_cent6088.txt");

  float pT_negpion0088dAu[36], epT_negpion0088dAu[36], yield_negpion0088dAu[36], eyield_negpion0088dAu[36];
  float pT_negpion0020dAu[36], epT_negpion0020dAu[36], yield_negpion0020dAu[36], eyield_negpion0020dAu[36];
  float pT_negpion2040dAu[36], epT_negpion2040dAu[36], yield_negpion2040dAu[36], eyield_negpion2040dAu[36];
  float pT_negpion4060dAu[36], epT_negpion4060dAu[36], yield_negpion4060dAu[36], eyield_negpion4060dAu[36];
  float pT_negpion6088dAu[36], epT_negpion6088dAu[36], yield_negpion6088dAu[36], eyield_negpion6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fnegpion0088dAu>>pT_negpion0088dAu[i]>>yield_negpion0088dAu[i]>>eyield_negpion0088dAu[i];
      fnegpion0020dAu>>pT_negpion0020dAu[i]>>yield_negpion0020dAu[i]>>eyield_negpion0020dAu[i];
      fnegpion2040dAu>>pT_negpion2040dAu[i]>>yield_negpion2040dAu[i]>>eyield_negpion2040dAu[i];
      fnegpion4060dAu>>pT_negpion4060dAu[i]>>yield_negpion4060dAu[i]>>eyield_negpion4060dAu[i];
      fnegpion6088dAu>>pT_negpion6088dAu[i]>>yield_negpion6088dAu[i]>>eyield_negpion6088dAu[i];
      epT_negpion0088dAu[i] = 0;
      epT_negpion0020dAu[i] = 0;
      epT_negpion2040dAu[i] = 0;
      epT_negpion4060dAu[i] = 0;
      epT_negpion6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  yield_negpion0088dAu[i] = 0;
	  yield_negpion0020dAu[i] = 0;
	  yield_negpion2040dAu[i] = 0;
	  yield_negpion4060dAu[i] = 0;
	  yield_negpion6088dAu[i] = 0;
	  eyield_negpion0088dAu[i] = 0;
	  eyield_negpion0020dAu[i] = 0;
	  eyield_negpion2040dAu[i] = 0;
	  eyield_negpion4060dAu[i] = 0;
	  eyield_negpion6088dAu[i] = 0;
	}
      // yield_negpion0088dAu[i] *= 1e-1;eyield_negpion0088dAu[i] *= 1e-1;
      // yield_negpion0020dAu[i] *= 1e-2;eyield_negpion0020dAu[i] *= 1e-2;
      // yield_negpion2040dAu[i] *= 2e-3;eyield_negpion2040dAu[i] *= 2e-3;
      // yield_negpion4060dAu[i] *= 3e-4;eyield_negpion4060dAu[i] *= 3e-4;
      // yield_negpion6088dAu[i] *= 6e-5;eyield_negpion6088dAu[i] *= 6e-5;
      yield_negpion0020dAu[i] *= 1.3e-1;eyield_negpion0020dAu[i] *= 1.3e-1;
      yield_negpion2040dAu[i] *= 3.5e-2;eyield_negpion2040dAu[i] *= 3.5e-2;
      yield_negpion0088dAu[i] *= 7.5e-3;eyield_negpion0088dAu[i] *= 7.5e-3;
      yield_negpion4060dAu[i] *= 2.0e-3;eyield_negpion4060dAu[i] *= 2.0e-3;
      yield_negpion6088dAu[i] *= 1.0e-3;eyield_negpion6088dAu[i] *= 1.0e-3;
    }
  fnegpion0088dAu.close();
  fnegpion0020dAu.close();
  fnegpion2040dAu.close();
  fnegpion4060dAu.close();
  fnegpion6088dAu.close();




  TGraphErrors *tge_negpion0010AuAu = new TGraphErrors(36,pT_negpion0010AuAu,yield_negpion0010AuAu,epT_negpion0010AuAu,eyield_negpion0010AuAu);
  tge_negpion0010AuAu->SetMarkerColor(kBlack);
  tge_negpion0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_negpion1020AuAu = new TGraphErrors(36,pT_negpion1020AuAu,yield_negpion1020AuAu,epT_negpion1020AuAu,eyield_negpion1020AuAu);
  tge_negpion1020AuAu->SetMarkerColor(kBlack);
  tge_negpion1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_negpion2040AuAu = new TGraphErrors(36,pT_negpion2040AuAu,yield_negpion2040AuAu,epT_negpion2040AuAu,eyield_negpion2040AuAu);
  tge_negpion2040AuAu->SetMarkerColor(kBlack);
  tge_negpion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_negpion4060AuAu = new TGraphErrors(36,pT_negpion4060AuAu,yield_negpion4060AuAu,epT_negpion4060AuAu,eyield_negpion4060AuAu);
  tge_negpion4060AuAu->SetMarkerColor(kBlack);
  tge_negpion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_negpion6092AuAu = new TGraphErrors(36,pT_negpion6092AuAu,yield_negpion6092AuAu,epT_negpion6092AuAu,eyield_negpion6092AuAu);
  tge_negpion6092AuAu->SetMarkerColor(kBlack);
  tge_negpion6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_negpion0088dAu = new TGraphErrors(36,pT_negpion0088dAu,yield_negpion0088dAu,epT_negpion0088dAu,eyield_negpion0088dAu);
  tge_negpion0088dAu->SetMarkerColor(kBlack);
  tge_negpion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_negpion0020dAu = new TGraphErrors(36,pT_negpion0020dAu,yield_negpion0020dAu,epT_negpion0020dAu,eyield_negpion0020dAu);
  tge_negpion0020dAu->SetMarkerColor(kBlack);
  tge_negpion0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_negpion2040dAu = new TGraphErrors(36,pT_negpion2040dAu,yield_negpion2040dAu,epT_negpion2040dAu,eyield_negpion2040dAu);
  tge_negpion2040dAu->SetMarkerColor(kBlack);
  tge_negpion2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_negpion4060dAu = new TGraphErrors(36,pT_negpion4060dAu,yield_negpion4060dAu,epT_negpion4060dAu,eyield_negpion4060dAu);
  tge_negpion4060dAu->SetMarkerColor(kBlack);
  tge_negpion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_negpion6088dAu = new TGraphErrors(36,pT_negpion6088dAu,yield_negpion6088dAu,epT_negpion6088dAu,eyield_negpion6088dAu);
  tge_negpion6088dAu->SetMarkerColor(kBlack);
  tge_negpion6088dAu->SetMarkerStyle(kOpenDiamond);

  c1->cd(2); // second panel of canvas

  TMultiGraph *negpion = new TMultiGraph();
  negpion->Add(tge_negpion0010AuAu);
  negpion->Add(tge_negpion1020AuAu);
  negpion->Add(tge_negpion2040AuAu);
  negpion->Add(tge_negpion4060AuAu);
  negpion->Add(tge_negpion6092AuAu);
  negpion->Add(tge_negpion0020dAu);
  negpion->Add(tge_negpion0088dAu);
  negpion->Add(tge_negpion2040dAu);
  negpion->Add(tge_negpion4060dAu);
  negpion->Add(tge_negpion6088dAu);
  negpion->Draw("ap");
  // negpion->SetMaximum(1e5);
  // negpion->SetMinimum(1e-12);
  negpion->SetMaximum(1e6);
  negpion->SetMinimum(1e-9);
  negpion->GetXaxis()->SetLimits(0.0,6.0);
  negpion->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  negpion->GetXaxis()->CenterTitle();
  negpion->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  negpion->GetYaxis()->CenterTitle();

  TLegend *leg_negpion = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_negpion = new TLegend(0.48,0.68,0.68,0.88);
  leg_negpion->SetFillColor(kWhite);
  leg_negpion->SetBorderSize(0);
  leg_negpion->SetHeader("Au+Au");
  leg_negpion->AddEntry(tge_negpion0010AuAu,"0-10%","p");
  leg_negpion->AddEntry(tge_negpion1020AuAu,"10-20%","p");
  leg_negpion->AddEntry(tge_negpion2040AuAu,"20-40%","p");
  leg_negpion->AddEntry(tge_negpion4060AuAu,"40-60%","p");
  leg_negpion->AddEntry(tge_negpion6092AuAu,"60-92%","p");
  leg_negpion->Draw();

  TLegend *leg_negpion2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_negpion2 = new TLegend(0.68,0.68,0.88,0.88);
  leg_negpion2->SetFillColor(kWhite);
  leg_negpion2->SetBorderSize(0);
  leg_negpion2->SetHeader("d+Au");
  leg_negpion2->AddEntry(tge_negpion0020dAu,"0-20%","p");
  leg_negpion2->AddEntry(tge_negpion2040dAu,"20-40%","p");
  leg_negpion2->AddEntry(tge_negpion0088dAu,"0-88%","p");
  leg_negpion2->AddEntry(tge_negpion4060dAu,"40-60%","p");
  leg_negpion2->AddEntry(tge_negpion6088dAu,"60-88%","p");
  leg_negpion2->Draw();







}
