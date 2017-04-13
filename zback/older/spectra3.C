TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;

void spectra3()
{

  doit(2,1);
  doit(4,3);
  doit(8,5);

  doit3x1(tmg_pion,tmg_kaon,tmg_prot);

}


void doit3x1(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  cout<<"3x1"<<endl;

  cout<<"pion is "<<pion<<endl;
  cout<<"kaon is "<<kaon<<endl;
  cout<<"prot is "<<prot<<endl;

  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TCanvas *c1 = new TCanvas("c1","c1",1100,700);
  c1->Divide(3,1);
  c1_1->cd();
  c1_1->SetLogy();
  pion->Draw("apz");
  c1_2->cd();
  c1_2->SetLogy();
  kaon->Draw("apz");
  c1_3->cd();
  c1_3->SetLogy();
  prot->Draw("apz");

  c1->Print("figures/spectra_333.gif");
  c1->Print("figures/spectra_333.eps");

}

void doit(int r7pid=2, int r8pid=1)
{

  float sysvalue = 0.1;

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->cd();

  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.0,0.5,1.0);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",0.5,0.0,1.0,1.0);
  c1_2->Draw();
  c1->cd();

  c1_1->SetLogy();
  c1_1->SetTicks(1,1);

  c1_1->SetLeftMargin(0.15);
  c1_1->SetRightMargin(0);
  c1_1->SetTopMargin(0.05);
  c1_2->SetLeftMargin(0);
  c1_2->SetRightMargin(0.15);
  c1_2->SetTopMargin(0.05);

  c1_2->SetLogy();
  c1_2->SetTicks(1,1);


  // --- now AuAu --- //


  char fpospion0010AuAuNAME[100];
  char fpospion1020AuAuNAME[100];
  char fpospion2040AuAuNAME[100];
  char fpospion4060AuAuNAME[100];
  char fpospion6092AuAuNAME[100];

  sprintf(fpospion0010AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent0010.txt",r7pid);
  sprintf(fpospion1020AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent1020.txt",r7pid);
  sprintf(fpospion2040AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent2040.txt",r7pid);
  sprintf(fpospion4060AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent4060.txt",r7pid);
  sprintf(fpospion6092AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent6092.txt",r7pid);

  ifstream fpospion0010AuAu(fpospion0010AuAuNAME);
  ifstream fpospion1020AuAu(fpospion1020AuAuNAME);
  ifstream fpospion2040AuAu(fpospion2040AuAuNAME);
  ifstream fpospion4060AuAu(fpospion4060AuAuNAME);
  ifstream fpospion6092AuAu(fpospion6092AuAuNAME);

  float pT_pospion0010AuAu[44], epT_pospion0010AuAu[44], yield_pospion0010AuAu[44], eyield_pospion0010AuAu[44], esysyield_pospion0010AuAu[44];
  float pT_pospion1020AuAu[44], epT_pospion1020AuAu[44], yield_pospion1020AuAu[44], eyield_pospion1020AuAu[44], esysyield_pospion1020AuAu[44];
  float pT_pospion2040AuAu[44], epT_pospion2040AuAu[44], yield_pospion2040AuAu[44], eyield_pospion2040AuAu[44], esysyield_pospion2040AuAu[44];
  float pT_pospion4060AuAu[44], epT_pospion4060AuAu[44], yield_pospion4060AuAu[44], eyield_pospion4060AuAu[44], esysyield_pospion4060AuAu[44];
  float pT_pospion6092AuAu[44], epT_pospion6092AuAu[44], yield_pospion6092AuAu[44], eyield_pospion6092AuAu[44], esysyield_pospion6092AuAu[44];

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
      //---
      sysvalue = 0.1;
      if(i>33) sysvalue = 0.2; // first step towards pt dependent sys errors
      esysyield_pospion0010AuAu[i] = sysvalue*yield_pospion0010AuAu[i];
      esysyield_pospion1020AuAu[i] = sysvalue*yield_pospion1020AuAu[i];
      esysyield_pospion2040AuAu[i] = sysvalue*yield_pospion2040AuAu[i];
      esysyield_pospion4060AuAu[i] = sysvalue*yield_pospion4060AuAu[i];
      esysyield_pospion6092AuAu[i] = sysvalue*yield_pospion6092AuAu[i];
    }
  fpospion0010AuAu.close();
  fpospion1020AuAu.close();
  fpospion2040AuAu.close();
  fpospion4060AuAu.close();
  fpospion6092AuAu.close();

  // --- now dAu --- //

  char fpospion0088dAuNAME[100];
  char fpospion0020dAuNAME[100];
  char fpospion2040dAuNAME[100];
  char fpospion4060dAuNAME[100];
  char fpospion6088dAuNAME[100];

  sprintf(fpospion0088dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent0088.txt",r8pid);
  sprintf(fpospion0020dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent0020.txt",r8pid);
  sprintf(fpospion2040dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent2040.txt",r8pid);
  sprintf(fpospion4060dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent4060.txt",r8pid);
  sprintf(fpospion6088dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent6088.txt",r8pid);

  ifstream fpospion0088dAu(fpospion0088dAuNAME);
  ifstream fpospion0020dAu(fpospion0020dAuNAME);
  ifstream fpospion2040dAu(fpospion2040dAuNAME);
  ifstream fpospion4060dAu(fpospion4060dAuNAME);
  ifstream fpospion6088dAu(fpospion6088dAuNAME);

  float pT_pospion0088dAu[36], epT_pospion0088dAu[36], yield_pospion0088dAu[36], eyield_pospion0088dAu[36], esysyield_pospion0088dAu[36];
  float pT_pospion0020dAu[36], epT_pospion0020dAu[36], yield_pospion0020dAu[36], eyield_pospion0020dAu[36], esysyield_pospion0020dAu[36];
  float pT_pospion2040dAu[36], epT_pospion2040dAu[36], yield_pospion2040dAu[36], eyield_pospion2040dAu[36], esysyield_pospion2040dAu[36];
  float pT_pospion4060dAu[36], epT_pospion4060dAu[36], yield_pospion4060dAu[36], eyield_pospion4060dAu[36], esysyield_pospion4060dAu[36];
  float pT_pospion6088dAu[36], epT_pospion6088dAu[36], yield_pospion6088dAu[36], eyield_pospion6088dAu[36], esysyield_pospion6088dAu[36];

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
      // ---
      sysvalue = 0.1;
      if(i>33) sysvalue = 0.2; // first step towards pt dependent sys errors
      // of course, this doesn't apply to dAu
      esysyield_pospion0088dAu[i] = sysvalue*yield_pospion0088dAu[i];
      esysyield_pospion0020dAu[i] = sysvalue*yield_pospion0020dAu[i];
      esysyield_pospion2040dAu[i] = sysvalue*yield_pospion2040dAu[i];
      esysyield_pospion4060dAu[i] = sysvalue*yield_pospion4060dAu[i];
      esysyield_pospion6088dAu[i] = sysvalue*yield_pospion6088dAu[i];
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



  // --- SYSYSYSYSYS

  TGraphErrors *tgeS_pospion0010AuAu = new TGraphErrors(36,pT_pospion0010AuAu,yield_pospion0010AuAu,epT_pospion0010AuAu,esysyield_pospion0010AuAu);
  TGraphErrors *tgeS_pospion1020AuAu = new TGraphErrors(36,pT_pospion1020AuAu,yield_pospion1020AuAu,epT_pospion1020AuAu,esysyield_pospion1020AuAu);
  TGraphErrors *tgeS_pospion2040AuAu = new TGraphErrors(36,pT_pospion2040AuAu,yield_pospion2040AuAu,epT_pospion2040AuAu,esysyield_pospion2040AuAu);
  TGraphErrors *tgeS_pospion4060AuAu = new TGraphErrors(36,pT_pospion4060AuAu,yield_pospion4060AuAu,epT_pospion4060AuAu,esysyield_pospion4060AuAu);
  TGraphErrors *tgeS_pospion6092AuAu = new TGraphErrors(36,pT_pospion6092AuAu,yield_pospion6092AuAu,epT_pospion6092AuAu,esysyield_pospion6092AuAu);
  TGraphErrors *tgeS_pospion0020dAu = new TGraphErrors(36,pT_pospion0020dAu,yield_pospion0020dAu,epT_pospion0020dAu,esysyield_pospion0020dAu);
  TGraphErrors *tgeS_pospion2040dAu = new TGraphErrors(36,pT_pospion2040dAu,yield_pospion2040dAu,epT_pospion2040dAu,esysyield_pospion2040dAu);
  TGraphErrors *tgeS_pospion0088dAu = new TGraphErrors(36,pT_pospion0088dAu,yield_pospion0088dAu,epT_pospion0088dAu,esysyield_pospion0088dAu);
  TGraphErrors *tgeS_pospion4060dAu = new TGraphErrors(36,pT_pospion4060dAu,yield_pospion4060dAu,epT_pospion4060dAu,esysyield_pospion4060dAu);
  TGraphErrors *tgeS_pospion6088dAu = new TGraphErrors(36,pT_pospion6088dAu,yield_pospion6088dAu,epT_pospion6088dAu,esysyield_pospion6088dAu);
  tgeS_pospion0010AuAu->SetMarkerColor(kGray);
  tgeS_pospion1020AuAu->SetMarkerColor(kGray);
  tgeS_pospion2040AuAu->SetMarkerColor(kGray);
  tgeS_pospion4060AuAu->SetMarkerColor(kGray);
  tgeS_pospion6092AuAu->SetMarkerColor(kGray);
  tgeS_pospion0020dAu->SetMarkerColor(kGray);
  tgeS_pospion2040dAu->SetMarkerColor(kGray);
  tgeS_pospion0088dAu->SetMarkerColor(kGray);
  tgeS_pospion4060dAu->SetMarkerColor(kGray);
  tgeS_pospion6088dAu->SetMarkerColor(kGray);
  tgeS_pospion0010AuAu->SetLineColor(kGray);
  tgeS_pospion1020AuAu->SetLineColor(kGray);
  tgeS_pospion2040AuAu->SetLineColor(kGray);
  tgeS_pospion4060AuAu->SetLineColor(kGray);
  tgeS_pospion6092AuAu->SetLineColor(kGray);
  tgeS_pospion0020dAu->SetLineColor(kGray);
  tgeS_pospion2040dAu->SetLineColor(kGray);
  tgeS_pospion0088dAu->SetLineColor(kGray);
  tgeS_pospion4060dAu->SetLineColor(kGray);
  tgeS_pospion6088dAu->SetLineColor(kGray);
  tgeS_pospion0010AuAu->SetLineWidth(15);
  tgeS_pospion1020AuAu->SetLineWidth(15);
  tgeS_pospion2040AuAu->SetLineWidth(15);
  tgeS_pospion4060AuAu->SetLineWidth(15);
  tgeS_pospion6092AuAu->SetLineWidth(15);
  tgeS_pospion0020dAu->SetLineWidth(15);
  tgeS_pospion2040dAu->SetLineWidth(15);
  tgeS_pospion0088dAu->SetLineWidth(15);
  tgeS_pospion4060dAu->SetLineWidth(15);
  tgeS_pospion6088dAu->SetLineWidth(15);




  //c1->cd(1); // first panel of canvas
  c1_1->cd();
  TMultiGraph *pospion = new TMultiGraph();
  pospion->Add(tgeS_pospion0010AuAu);
  pospion->Add(tgeS_pospion1020AuAu);
  pospion->Add(tgeS_pospion2040AuAu);
  pospion->Add(tgeS_pospion4060AuAu);
  pospion->Add(tgeS_pospion6092AuAu);
  pospion->Add(tgeS_pospion0020dAu);
  pospion->Add(tgeS_pospion0088dAu);
  pospion->Add(tgeS_pospion2040dAu);
  pospion->Add(tgeS_pospion4060dAu);
  pospion->Add(tgeS_pospion6088dAu);
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
  pospion->Draw("apz");
  pospion->SetMaximum(1e5);
  pospion->SetMinimum(1e-10);
  pospion->GetXaxis()->SetLimits(0.0,6.0);
  pospion->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  pospion->GetXaxis()->CenterTitle();
  pospion->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  pospion->GetYaxis()->CenterTitle();
  pospion->GetYaxis()->SetTitleOffset(1.5);
  pospion->GetYaxis()->SetTitleSize(0.045); // NEW
  pospion->GetYaxis()->SetLabelSize(0.045); // NEW
  pospion->GetXaxis()->SetTitleSize(0.045); // NEW
  pospion->GetXaxis()->SetLabelSize(0.045); // NEW

  //TPaveText *pospave = new TPaveText(1.3,3e3,2.3,3e4);
  TPaveText *pospave = new TPaveText(0.8,3e3,1.5,3e4);
  pospave->SetFillColor(kWhite);
  pospave->SetBorderSize(0);
  if(r7pid<=3) pospave->AddText("#pi^{+}");
  else if(r7pid<=5) pospave->AddText("K^{+}");
  else if(r7pid>=6) pospave->AddText("p");
  else pospave->AddText("h^{+}");
  pospave->SetTextSize(0.07);
  pospave->Draw();

  //TLegend *leg_pospion = new TLegend(0.28,0.68,0.58,0.88);
  //TLegend *leg_pospion = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_pospion = new TLegend(0.28,0.68,0.58,0.88);
  //TLegend *leg_pospion = new TLegend(0.48,0.48,0.68,0.88);
  //TLegend *leg_pospion = new TLegend(0.42,0.68,0.62,0.88); // previous
  TLegend *leg_pospion = new TLegend(0.48,0.68,0.68,0.88);
  leg_pospion->SetFillColor(kWhite);
  leg_pospion->SetBorderSize(0);
  leg_pospion->SetHeader("Au+Au");
  leg_pospion->AddEntry(tge_pospion0010AuAu,"0-10% #times 20","p");
  leg_pospion->AddEntry(tge_pospion1020AuAu,"10-20% #times 5","p");
  leg_pospion->AddEntry(tge_pospion2040AuAu,"20-40% #times 2","p");
  leg_pospion->AddEntry(tge_pospion4060AuAu,"40-60%","p");
  leg_pospion->AddEntry(tge_pospion6092AuAu,"60-92%","p");
  // leg_pospion->AddEntry(tge_pospion0010AuAu,"0-10%","p");
  // leg_pospion->AddEntry(tge_pospion1020AuAu,"10-20%","p");
  // leg_pospion->AddEntry(tge_pospion2040AuAu,"20-40%","p");
  // leg_pospion->AddEntry(tge_pospion4060AuAu,"40-60%","p");
  // leg_pospion->AddEntry(tge_pospion6092AuAu,"60-92%","p");
  leg_pospion->SetTextSize(0.03);
  leg_pospion->Draw();

  //TLegend *leg_pospion2 = new TLegend(0.58,0.68,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.58,0.68,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.58,0.48,0.88,0.88);
  //TLegend *leg_pospion2 = new TLegend(0.62,0.68,0.88,0.88); // previous
  TLegend *leg_pospion2 = new TLegend(0.68,0.68,0.92,0.88);
  leg_pospion2->SetFillColor(kWhite);
  leg_pospion2->SetBorderSize(0);
  leg_pospion2->SetHeader("d+Au");
  leg_pospion2->AddEntry(tge_pospion0020dAu,"0-20% #times 0.13","p");
  leg_pospion2->AddEntry(tge_pospion2040dAu,"20-40% #times 0.035","p");
  leg_pospion2->AddEntry(tge_pospion0088dAu,"0-88% #times 0.0075","p");
  leg_pospion2->AddEntry(tge_pospion4060dAu,"40-60% #times 0.002","p");
  leg_pospion2->AddEntry(tge_pospion6088dAu,"60-88% #times 0.001","p");
  // leg_pospion2->AddEntry(tge_pospion0020dAu,"0-20%","p");
  // leg_pospion2->AddEntry(tge_pospion2040dAu,"20-40%","p");
  // leg_pospion2->AddEntry(tge_pospion0088dAu,"0-88%","p");
  // leg_pospion2->AddEntry(tge_pospion4060dAu,"40-60%","p");
  // leg_pospion2->AddEntry(tge_pospion6088dAu,"60-88%","p");
  leg_pospion2->SetTextSize(0.03);
  leg_pospion2->Draw();



  // ---
  // ---
  // --- now negative --- //
  // -------------------- //
  // -------------------- //

  // --- now AuAu --- //

  char fnegpion0010AuAuNAME[100];
  char fnegpion1020AuAuNAME[100];
  char fnegpion2040AuAuNAME[100];
  char fnegpion4060AuAuNAME[100];
  char fnegpion6092AuAuNAME[100];

  sprintf(fnegpion0010AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent0010.txt",r7pid);
  sprintf(fnegpion1020AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent1020.txt",r7pid);
  sprintf(fnegpion2040AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent2040.txt",r7pid);
  sprintf(fnegpion4060AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent4060.txt",r7pid);
  sprintf(fnegpion6092AuAuNAME,"../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent6092.txt",r7pid);

  ifstream fnegpion0010AuAu(fnegpion0010AuAuNAME);
  ifstream fnegpion1020AuAu(fnegpion1020AuAuNAME);
  ifstream fnegpion2040AuAu(fnegpion2040AuAuNAME);
  ifstream fnegpion4060AuAu(fnegpion4060AuAuNAME);
  ifstream fnegpion6092AuAu(fnegpion6092AuAuNAME);

  float pT_negpion0010AuAu[44], epT_negpion0010AuAu[44], yield_negpion0010AuAu[44], eyield_negpion0010AuAu[44], esysyield_negpion0010AuAu[44];
  float pT_negpion1020AuAu[44], epT_negpion1020AuAu[44], yield_negpion1020AuAu[44], eyield_negpion1020AuAu[44], esysyield_negpion1020AuAu[44];
  float pT_negpion2040AuAu[44], epT_negpion2040AuAu[44], yield_negpion2040AuAu[44], eyield_negpion2040AuAu[44], esysyield_negpion2040AuAu[44];
  float pT_negpion4060AuAu[44], epT_negpion4060AuAu[44], yield_negpion4060AuAu[44], eyield_negpion4060AuAu[44], esysyield_negpion4060AuAu[44];
  float pT_negpion6092AuAu[44], epT_negpion6092AuAu[44], yield_negpion6092AuAu[44], eyield_negpion6092AuAu[44], esysyield_negpion6092AuAu[44];

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
      // ---
      sysvalue = 0.1;
      if(i>33) sysvalue = 0.2; // first step towards pt dependent sys errors
      esysyield_negpion0010AuAu[i] = sysvalue*yield_negpion0010AuAu[i];
      esysyield_negpion1020AuAu[i] = sysvalue*yield_negpion1020AuAu[i];
      esysyield_negpion2040AuAu[i] = sysvalue*yield_negpion2040AuAu[i];
      esysyield_negpion4060AuAu[i] = sysvalue*yield_negpion4060AuAu[i];
      esysyield_negpion6092AuAu[i] = sysvalue*yield_negpion6092AuAu[i];
    }
  fnegpion0010AuAu.close();
  fnegpion1020AuAu.close();
  fnegpion2040AuAu.close();
  fnegpion4060AuAu.close();
  fnegpion6092AuAu.close();

  // --- now dAu --- //

  char fnegpion0088dAuNAME[100];
  char fnegpion0020dAuNAME[100];
  char fnegpion2040dAuNAME[100];
  char fnegpion4060dAuNAME[100];
  char fnegpion6088dAuNAME[100];

  sprintf(fnegpion0088dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent0088.txt",r8pid);
  sprintf(fnegpion0020dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent0020.txt",r8pid);
  sprintf(fnegpion2040dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent2040.txt",r8pid);
  sprintf(fnegpion4060dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent4060.txt",r8pid);
  sprintf(fnegpion6088dAuNAME,"../Run8dAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent6088.txt",r8pid);

  ifstream fnegpion0088dAu(fnegpion0088dAuNAME);
  ifstream fnegpion0020dAu(fnegpion0020dAuNAME);
  ifstream fnegpion2040dAu(fnegpion2040dAuNAME);
  ifstream fnegpion4060dAu(fnegpion4060dAuNAME);
  ifstream fnegpion6088dAu(fnegpion6088dAuNAME);

  float pT_negpion0088dAu[36], epT_negpion0088dAu[36], yield_negpion0088dAu[36], eyield_negpion0088dAu[36], esysyield_negpion0088dAu[36];
  float pT_negpion0020dAu[36], epT_negpion0020dAu[36], yield_negpion0020dAu[36], eyield_negpion0020dAu[36], esysyield_negpion0020dAu[36];
  float pT_negpion2040dAu[36], epT_negpion2040dAu[36], yield_negpion2040dAu[36], eyield_negpion2040dAu[36], esysyield_negpion2040dAu[36];
  float pT_negpion4060dAu[36], epT_negpion4060dAu[36], yield_negpion4060dAu[36], eyield_negpion4060dAu[36], esysyield_negpion4060dAu[36];
  float pT_negpion6088dAu[36], epT_negpion6088dAu[36], yield_negpion6088dAu[36], eyield_negpion6088dAu[36], esysyield_negpion6088dAu[36];

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
      sysvalue = 0.1;
      if(i>33) sysvalue = 0.2; // first step towards pt dependent sys errors
      // of course, this doesn't apply to dAu
      esysyield_negpion0088dAu[i] = sysvalue*yield_negpion0088dAu[i];
      esysyield_negpion0020dAu[i] = sysvalue*yield_negpion0020dAu[i];
      esysyield_negpion2040dAu[i] = sysvalue*yield_negpion2040dAu[i];
      esysyield_negpion4060dAu[i] = sysvalue*yield_negpion4060dAu[i];
      esysyield_negpion6088dAu[i] = sysvalue*yield_negpion6088dAu[i];
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

  // --- SYSYSYSYSYS

  TGraphErrors *tgeS_negpion0010AuAu = new TGraphErrors(36,pT_negpion0010AuAu,yield_negpion0010AuAu,epT_negpion0010AuAu,esysyield_negpion0010AuAu);
  TGraphErrors *tgeS_negpion1020AuAu = new TGraphErrors(36,pT_negpion1020AuAu,yield_negpion1020AuAu,epT_negpion1020AuAu,esysyield_negpion1020AuAu);
  TGraphErrors *tgeS_negpion2040AuAu = new TGraphErrors(36,pT_negpion2040AuAu,yield_negpion2040AuAu,epT_negpion2040AuAu,esysyield_negpion2040AuAu);
  TGraphErrors *tgeS_negpion4060AuAu = new TGraphErrors(36,pT_negpion4060AuAu,yield_negpion4060AuAu,epT_negpion4060AuAu,esysyield_negpion4060AuAu);
  TGraphErrors *tgeS_negpion6092AuAu = new TGraphErrors(36,pT_negpion6092AuAu,yield_negpion6092AuAu,epT_negpion6092AuAu,esysyield_negpion6092AuAu);
  TGraphErrors *tgeS_negpion0020dAu = new TGraphErrors(36,pT_negpion0020dAu,yield_negpion0020dAu,epT_negpion0020dAu,esysyield_negpion0020dAu);
  TGraphErrors *tgeS_negpion2040dAu = new TGraphErrors(36,pT_negpion2040dAu,yield_negpion2040dAu,epT_negpion2040dAu,esysyield_negpion2040dAu);
  TGraphErrors *tgeS_negpion0088dAu = new TGraphErrors(36,pT_negpion0088dAu,yield_negpion0088dAu,epT_negpion0088dAu,esysyield_negpion0088dAu);
  TGraphErrors *tgeS_negpion4060dAu = new TGraphErrors(36,pT_negpion4060dAu,yield_negpion4060dAu,epT_negpion4060dAu,esysyield_negpion4060dAu);
  TGraphErrors *tgeS_negpion6088dAu = new TGraphErrors(36,pT_negpion6088dAu,yield_negpion6088dAu,epT_negpion6088dAu,esysyield_negpion6088dAu);
  tgeS_negpion0010AuAu->SetMarkerColor(kGray);
  tgeS_negpion1020AuAu->SetMarkerColor(kGray);
  tgeS_negpion2040AuAu->SetMarkerColor(kGray);
  tgeS_negpion4060AuAu->SetMarkerColor(kGray);
  tgeS_negpion6092AuAu->SetMarkerColor(kGray);
  tgeS_negpion0020dAu->SetMarkerColor(kGray);
  tgeS_negpion2040dAu->SetMarkerColor(kGray);
  tgeS_negpion0088dAu->SetMarkerColor(kGray);
  tgeS_negpion4060dAu->SetMarkerColor(kGray);
  tgeS_negpion6088dAu->SetMarkerColor(kGray);
  tgeS_negpion0010AuAu->SetLineColor(kGray);
  tgeS_negpion1020AuAu->SetLineColor(kGray);
  tgeS_negpion2040AuAu->SetLineColor(kGray);
  tgeS_negpion4060AuAu->SetLineColor(kGray);
  tgeS_negpion6092AuAu->SetLineColor(kGray);
  tgeS_negpion0020dAu->SetLineColor(kGray);
  tgeS_negpion2040dAu->SetLineColor(kGray);
  tgeS_negpion0088dAu->SetLineColor(kGray);
  tgeS_negpion4060dAu->SetLineColor(kGray);
  tgeS_negpion6088dAu->SetLineColor(kGray);
  tgeS_negpion0010AuAu->SetLineWidth(15);
  tgeS_negpion1020AuAu->SetLineWidth(15);
  tgeS_negpion2040AuAu->SetLineWidth(15);
  tgeS_negpion4060AuAu->SetLineWidth(15);
  tgeS_negpion6092AuAu->SetLineWidth(15);
  tgeS_negpion0020dAu->SetLineWidth(15);
  tgeS_negpion2040dAu->SetLineWidth(15);
  tgeS_negpion0088dAu->SetLineWidth(15);
  tgeS_negpion4060dAu->SetLineWidth(15);
  tgeS_negpion6088dAu->SetLineWidth(15);

  //c1->cd(2); // second panel of canvas
  c1_2->cd();
  TMultiGraph *negpion = new TMultiGraph();
  negpion->Add(tgeS_negpion0010AuAu);
  negpion->Add(tgeS_negpion1020AuAu);
  negpion->Add(tgeS_negpion2040AuAu);
  negpion->Add(tgeS_negpion4060AuAu);
  negpion->Add(tgeS_negpion6092AuAu);
  negpion->Add(tgeS_negpion0020dAu);
  negpion->Add(tgeS_negpion0088dAu);
  negpion->Add(tgeS_negpion2040dAu);
  negpion->Add(tgeS_negpion4060dAu);
  negpion->Add(tgeS_negpion6088dAu);
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
  negpion->Draw("apz");
  // negpion->SetMaximum(1e5);
  // negpion->SetMinimum(1e-12);
  negpion->SetMaximum(1e5);
  negpion->SetMinimum(1e-10);
  negpion->GetXaxis()->SetLimits(0.0,6.0);
  negpion->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  negpion->GetXaxis()->CenterTitle();
  negpion->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  negpion->GetYaxis()->CenterTitle();
  negpion->GetYaxis()->SetTitleOffset(1.5);
  negpion->GetYaxis()->SetTitleSize(0); // NEW
  negpion->GetYaxis()->SetLabelSize(0); // NEW
  negpion->GetXaxis()->SetTitleSize(0.045); // NEW
  negpion->GetXaxis()->SetLabelSize(0.045); // NEW

  //TPaveText *negpave = new TPaveText(1.3,3e3,2.3,3e4);
  TPaveText *negpave = new TPaveText(0.8,3e3,1.5,3e4);
  negpave->SetFillColor(kWhite);
  negpave->SetBorderSize(0);
  if(r7pid<=3) negpave->AddText("#pi^{-}");
  else if(r7pid<=5) negpave->AddText("K^{-}");
  else if(r7pid>=6) negpave->AddText("#bar{p}");
  else negpave->AddText("h^{-}");
  negpave->SetTextSize(0.07);
  negpave->Draw();

  //TLegend *leg_negpion = new TLegend(0.48,0.58,0.68,0.88);
  //TLegend *leg_negpion = new TLegend(0.42,0.68,0.62,0.88); // previous
  TLegend *leg_negpion = new TLegend(0.33,0.68,0.53,0.88);
  leg_negpion->SetFillColor(kWhite);
  leg_negpion->SetBorderSize(0);
  leg_negpion->SetHeader("Au+Au");
  leg_negpion->AddEntry(tge_negpion0010AuAu,"0-10% #times 20","p");
  leg_negpion->AddEntry(tge_negpion1020AuAu,"10-20% #times 5","p");
  leg_negpion->AddEntry(tge_negpion2040AuAu,"20-40% #times 2","p");
  leg_negpion->AddEntry(tge_negpion4060AuAu,"40-60%","p");
  leg_negpion->AddEntry(tge_negpion6092AuAu,"60-92%","p");
  // leg_negpion->AddEntry(tge_negpion0010AuAu,"0-10%","p");
  // leg_negpion->AddEntry(tge_negpion1020AuAu,"10-20%","p");
  // leg_negpion->AddEntry(tge_negpion2040AuAu,"20-40%","p");
  // leg_negpion->AddEntry(tge_negpion4060AuAu,"40-60%","p");
  // leg_negpion->AddEntry(tge_negpion6092AuAu,"60-92%","p");
  leg_negpion->SetTextSize(0.03);
  leg_negpion->Draw();

  //TLegend *leg_negpion2 = new TLegend(0.68,0.58,0.88,0.88);
  //TLegend *leg_negpion2 = new TLegend(0.62,0.68,0.88,0.88); // previous
  TLegend *leg_negpion2 = new TLegend(0.53,0.68,0.79,0.88);
  leg_negpion2->SetFillColor(kWhite);
  leg_negpion2->SetBorderSize(0);
  leg_negpion2->SetHeader("d+Au");
  leg_negpion2->AddEntry(tge_negpion0020dAu,"0-20% #times 0.13","p");
  leg_negpion2->AddEntry(tge_negpion2040dAu,"20-40% #times 0.035","p");
  leg_negpion2->AddEntry(tge_negpion0088dAu,"0-88% #times 0.0075","p");
  leg_negpion2->AddEntry(tge_negpion4060dAu,"40-60% #times 0.002","p");
  leg_negpion2->AddEntry(tge_negpion6088dAu,"60-88% #times 0.001","p");
  // leg_negpion2->AddEntry(tge_negpion0020dAu,"0-20%","p");
  // leg_negpion2->AddEntry(tge_negpion2040dAu,"20-40%","p");
  // leg_negpion2->AddEntry(tge_negpion0088dAu,"0-88%","p");
  // leg_negpion2->AddEntry(tge_negpion4060dAu,"40-60%","p");
  // leg_negpion2->AddEntry(tge_negpion6088dAu,"60-88%","p");
  leg_negpion2->SetTextSize(0.03);
  leg_negpion2->Draw();




  char particle[7];
  if(r7pid<=3) sprintf(particle,"pion");
  else if(r7pid>=6) sprintf(particle,"proton");
  else sprintf(particle,"kaon");
  char figname[100];
  sprintf(figname,"figures/spectra_%s.gif",particle);
  c1->Print(figname);
  sprintf(figname,"figures/spectra_%s.eps",particle);
  c1->Print(figname);


  c1->Clear();
  delete c1;






  tge_pospion0010AuAu->SetMarkerStyle(kFullCircle);
  tge_pospion1020AuAu->SetMarkerStyle(kFullSquare);
  tge_pospion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  tge_pospion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  tge_pospion6092AuAu->SetMarkerStyle(kFullDiamond);
  tge_negpion0010AuAu->SetMarkerStyle(kOpenCircle);
  tge_negpion1020AuAu->SetMarkerStyle(kOpenSquare);
  tge_negpion2040AuAu->SetMarkerStyle(kOpenTriangleUp);
  tge_negpion4060AuAu->SetMarkerStyle(kOpenTriangleDown);
  tge_negpion6092AuAu->SetMarkerStyle(kOpenDiamond);

  tge_pospion0020dAu->SetMarkerStyle(kFullCircle);
  tge_pospion2040dAu->SetMarkerStyle(kFullSquare);
  tge_pospion0088dAu->SetMarkerStyle(kFullTriangleUp);
  tge_pospion4060dAu->SetMarkerStyle(kFullTriangleDown);
  tge_pospion6088dAu->SetMarkerStyle(kFullDiamond);
  tge_negpion0020dAu->SetMarkerStyle(kOpenCircle);
  tge_negpion2040dAu->SetMarkerStyle(kOpenSquare);
  tge_negpion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  tge_negpion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  tge_negpion6088dAu->SetMarkerStyle(kOpenDiamond);






  TCanvas *c2 = new TCanvas("c2","c2");
  c2->SetLogy();

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tgeS_negpion0010AuAu);
  tmg->Add(tgeS_negpion1020AuAu);
  tmg->Add(tgeS_negpion2040AuAu);
  tmg->Add(tgeS_negpion4060AuAu);
  tmg->Add(tgeS_negpion6092AuAu);
  tmg->Add(tgeS_negpion0020dAu);
  tmg->Add(tgeS_negpion0088dAu);
  tmg->Add(tgeS_negpion2040dAu);
  tmg->Add(tgeS_negpion4060dAu);
  tmg->Add(tgeS_negpion6088dAu);
  tmg->Add(tgeS_pospion0010AuAu);
  tmg->Add(tgeS_pospion1020AuAu);
  tmg->Add(tgeS_pospion2040AuAu);
  tmg->Add(tgeS_pospion4060AuAu);
  tmg->Add(tgeS_pospion6092AuAu);
  tmg->Add(tgeS_pospion0020dAu);
  tmg->Add(tgeS_pospion0088dAu);
  tmg->Add(tgeS_pospion2040dAu);
  tmg->Add(tgeS_pospion4060dAu);
  tmg->Add(tgeS_pospion6088dAu);
  tmg->Add(tge_negpion0010AuAu);
  tmg->Add(tge_negpion1020AuAu);
  tmg->Add(tge_negpion2040AuAu);
  tmg->Add(tge_negpion4060AuAu);
  tmg->Add(tge_negpion6092AuAu);
  tmg->Add(tge_negpion0020dAu);
  tmg->Add(tge_negpion0088dAu);
  tmg->Add(tge_negpion2040dAu);
  tmg->Add(tge_negpion4060dAu);
  tmg->Add(tge_negpion6088dAu);
  tmg->Add(tge_pospion0010AuAu);
  tmg->Add(tge_pospion1020AuAu);
  tmg->Add(tge_pospion2040AuAu);
  tmg->Add(tge_pospion4060AuAu);
  tmg->Add(tge_pospion6092AuAu);
  tmg->Add(tge_pospion0020dAu);
  tmg->Add(tge_pospion0088dAu);
  tmg->Add(tge_pospion2040dAu);
  tmg->Add(tge_pospion4060dAu);
  tmg->Add(tge_pospion6088dAu);
  tmg->Draw("apz");
  tmg->SetMaximum(1e5);
  tmg->SetMinimum(1e-10);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("1/2#pip_{T} d^{2}N/dp_{T}dy (c^{2}/GeV^{2})");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitleOffset(1.5);

  if(r7pid<=3)      tmg_pion = (TMultiGraph *)tmg->Clone();
  else if(r7pid>=6) tmg_prot = (TMultiGraph *)tmg->Clone();
  else              tmg_kaon = (TMultiGraph *)tmg->Clone();

  c2->Draw();

  sprintf(figname,"figures/spectra_pnx_%s.gif",particle);
  c2->Print(figname);
  sprintf(figname,"figures/spectra_pnx_%s.eps",particle);
  c2->Print(figname);

  c2->Clear();
  delete c2;

}
