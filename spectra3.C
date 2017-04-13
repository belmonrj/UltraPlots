double MAX = 1e11;
double MIN = 1e-13;
double xmin = 0.0;
double xmax = 6.0;

TLegend *leg1;
TLegend *leg2;

TLegend *legpos1;
TLegend *legpos2;
TLegend *legneg1;
TLegend *legneg2;

TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;
TMultiGraph *tmg_pospion;
TMultiGraph *tmg_poskaon;
TMultiGraph *tmg_posprot;
TMultiGraph *tmg_negpion;
TMultiGraph *tmg_negkaon;
TMultiGraph *tmg_negprot;

void spectra3()
{

  doit(2,1);
  doit(4,3);
  doit(8,5);

  doit3x1(tmg_pion,tmg_kaon,tmg_prot);
  doit3x2(tmg_pospion,tmg_poskaon,tmg_posprot,tmg_negpion,tmg_negkaon,tmg_negprot);

}


void doit3x2(TMultiGraph *pospion, TMultiGraph *poskaon, TMultiGraph *posprot,
	     TMultiGraph *negpion, TMultiGraph *negkaon, TMultiGraph *negprot)
{

  cout<<"3x2"<<endl;

  cout<<"pospion is "<<pospion<<endl;
  cout<<"poskaon is "<<poskaon<<endl;
  cout<<"posprot is "<<posprot<<endl;
  cout<<"negpion is "<<negpion<<endl;
  cout<<"negkaon is "<<negkaon<<endl;
  cout<<"negprot is "<<negprot<<endl;

  if(pospion==NULL||poskaon==NULL||posprot==NULL||negpion==NULL||negkaon==NULL||negprot==NULL)
    {
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TCanvas *c1 = new TCanvas("c1","c1",1000,650);
  //c1->Divide(3,1);
  double left = 0.09;
  double top = 0.05;
  double bottom = 0.12;
  double width = 0.29;
  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",left+0*width,bottom,left+1*width,1.0-top);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",left+1*width,bottom,left+2*width,1.0-top);
  c1_2->Draw();
  c1->cd();
  TPad *c1_3 = new TPad("c1_3","c1_3",left+2*width,bottom,left+3*width,1.0-top);
  c1_3->Draw();
  c1->cd();



  double ymin = MIN;
  double ymax = MAX;
  double labelsize = 0.04;
  double titleoff = 1.0;
  int divisions = 510;

  TGaxis *yaxis0 = new TGaxis(left,bottom,left,1.0-top,ymin,ymax-1e-4,divisions,"SG");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTickSize(0.01);// yes with option "S"
  yaxis0->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(labelsize);
  yaxis0->SetTitleSize(labelsize);
  yaxis0->SetTitleOffset(1.0);
  yaxis0->Draw();
  TGaxis *xaxis0 = new TGaxis(left+0*width,bottom,left+1*width,bottom,xmin,xmax-1e-4,divisions,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(labelsize);
  xaxis0->SetTitleSize(labelsize);
  xaxis0->SetTitleOffset(titleoff);
  xaxis0->Draw();
  TGaxis *xaxis1 = new TGaxis(left+1*width,bottom,left+2*width,bottom,xmin,xmax-1e-4,divisions,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(labelsize);
  xaxis1->SetTitleSize(labelsize);
  xaxis1->SetTitleOffset(titleoff);
  xaxis1->Draw();
  TGaxis *xaxis2 = new TGaxis(left+2*width,bottom,left+3*width,bottom,xmin,xmax,divisions,"");
  xaxis2->SetName("xaxis2");
  xaxis2->SetTitle("p_{T} (GeV/c)");
  xaxis2->CenterTitle();
  xaxis2->SetLabelSize(labelsize);
  xaxis2->SetTitleSize(labelsize);
  xaxis2->SetTitleOffset(titleoff);
  xaxis2->Draw();


  c1_1->cd();
  c1_1->SetLeftMargin(0.0);
  c1_1->SetRightMargin(0.0);
  c1_1->SetTopMargin(0.0);
  c1_1->SetBottomMargin(0.0);
  c1_1->SetTicks(1,1);
  c1_1->SetLogy();
  pospion->GetYaxis()->SetTitleSize(0.0);
  pospion->GetYaxis()->SetLabelSize(0.0);
  pospion->GetXaxis()->SetTitleSize(0.0);
  pospion->GetXaxis()->SetLabelSize(0.0);
  pospion->Draw("apz");
  TLatex *tls = new TLatex(2.0,1e9,"#sqrt{s_{NN}} = 200 GeV");
  tls->SetTextSize(0.08);
  tls->Draw();
  TLatex *tlp1 = new TLatex(1.0,5e-12,"#pi^{+}");
  tlp1->SetTextSize(0.12);
  tlp1->Draw();
  c1_2->cd();
  c1_2->SetLeftMargin(0.0);
  c1_2->SetRightMargin(0.0);
  c1_2->SetTopMargin(0.0);
  c1_2->SetBottomMargin(0.0);
  c1_2->SetTicks(1,1);
  c1_2->SetLogy();
  poskaon->GetYaxis()->SetTitleSize(0.0);
  poskaon->GetYaxis()->SetLabelSize(0.0);
  poskaon->GetXaxis()->SetTitleSize(0.0);
  poskaon->GetXaxis()->SetLabelSize(0.0);
  poskaon->Draw("apz");
  legneg1->SetTextSize(0.08);
  legneg1->Draw();
  TLatex *tlp2 = new TLatex(1.0,5e-12,"K^{+}");
  tlp2->SetTextSize(0.12);
  tlp2->Draw();
  c1_3->cd(); 
  c1_3->SetLeftMargin(0.0);
  c1_3->SetRightMargin(0.0);
  c1_3->SetTopMargin(0.0);
  c1_3->SetBottomMargin(0.0);
  c1_3->SetTicks(1,1);
  c1_3->SetLogy();
  posprot->GetYaxis()->SetTitleSize(0.0);
  posprot->GetYaxis()->SetLabelSize(0.0);
  posprot->GetXaxis()->SetTitleSize(0.0);
  posprot->GetXaxis()->SetLabelSize(0.0);
  posprot->Draw("apz");
  legneg2->SetTextSize(0.08);
  legneg2->Draw();
  TLatex *tlp3 = new TLatex(1.0,5e-12,"p");
  tlp3->SetTextSize(0.12);
  tlp3->Draw();

  c1->Print("figures/spectra_pos333.gif");
  c1->Print("figures/spectra_pos333.eps");

  //c1->Clear(); // trouble ahead?


  c1_1->cd();
  c1_1->SetLeftMargin(0.0);
  c1_1->SetRightMargin(0.0);
  c1_1->SetTopMargin(0.0);
  c1_1->SetBottomMargin(0.0);
  c1_1->SetTicks(1,1);
  c1_1->SetLogy();
  negpion->GetYaxis()->SetTitleSize(0.0);
  negpion->GetYaxis()->SetLabelSize(0.0);
  negpion->GetXaxis()->SetTitleSize(0.0);
  negpion->GetXaxis()->SetLabelSize(0.0);
  negpion->Draw("apz");
  TLatex *tls = new TLatex(2.0,1e9,"#sqrt{s_{NN}} = 200 GeV");
  tls->SetTextSize(0.08);
  tls->Draw();
  TLatex *tlp1 = new TLatex(1.0,5e-12,"#pi^{-}");
  tlp1->SetTextSize(0.12);
  tlp1->Draw();
  c1_2->cd();
  c1_2->SetLeftMargin(0.0);
  c1_2->SetRightMargin(0.0);
  c1_2->SetTopMargin(0.0);
  c1_2->SetBottomMargin(0.0);
  c1_2->SetTicks(1,1);
  c1_2->SetLogy();
  negkaon->GetYaxis()->SetTitleSize(0.0);
  negkaon->GetYaxis()->SetLabelSize(0.0);
  negkaon->GetXaxis()->SetTitleSize(0.0);
  negkaon->GetXaxis()->SetLabelSize(0.0);
  negkaon->Draw("apz");
  legneg1->SetTextSize(0.08);
  legneg1->Draw();
  TLatex *tlp2 = new TLatex(1.0,5e-12,"K^{-}");
  tlp2->SetTextSize(0.12);
  tlp2->Draw();
  c1_3->cd(); 
  c1_3->SetLeftMargin(0.0);
  c1_3->SetRightMargin(0.0);
  c1_3->SetTopMargin(0.0);
  c1_3->SetBottomMargin(0.0);
  c1_3->SetTicks(1,1);
  c1_3->SetLogy();
  negprot->GetYaxis()->SetTitleSize(0.0);
  negprot->GetYaxis()->SetLabelSize(0.0);
  negprot->GetXaxis()->SetTitleSize(0.0);
  negprot->GetXaxis()->SetLabelSize(0.0);
  negprot->Draw("apz");
  legneg2->SetTextSize(0.08);
  legneg2->Draw();
  TLatex *tlp3 = new TLatex(1.0,5e-12,"#bar{p}");
  tlp3->SetTextSize(0.12);
  tlp3->Draw();

  c1->Print("figures/spectra_neg333.gif");
  c1->Print("figures/spectra_neg333.eps");




  c1->Clear();
  delete c1;


} // 3x2

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

  TCanvas *c1 = new TCanvas("c1","c1",1000,500);
  //c1->Divide(3,1);
  double left = 0.09;
  double top = 0.05;
  double bottom = 0.12;
  double width = 0.29;
  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",left+0*width,bottom,left+1*width,1.0-top);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",left+1*width,bottom,left+2*width,1.0-top);
  c1_2->Draw();
  c1->cd();
  TPad *c1_3 = new TPad("c1_3","c1_3",left+2*width,bottom,left+3*width,1.0-top);
  c1_3->Draw();
  c1->cd();



  double ymin = MIN;
  double ymax = MAX;
  double labelsize = 0.04;
  double titleoff = 1.0;
  int divisions = 510;

  TGaxis *yaxis0 = new TGaxis(left,bottom,left,1.0-top,ymin,ymax-1e-4,divisions,"G");
  yaxis0->SetName("yaxis0");
  yaxis0->SetGridLength(0);// no
  yaxis0->SetTickSize(0);// no
  yaxis0->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(labelsize);
  yaxis0->SetTitleSize(labelsize);
  yaxis0->SetTitleOffset(0.9);
  yaxis0->Draw();
  TGaxis *xaxis0 = new TGaxis(left+0*width,bottom,left+1*width,bottom,xmin,xmax-1e-4,divisions,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(labelsize);
  xaxis0->SetTitleSize(labelsize);
  xaxis0->SetTitleOffset(titleoff);
  xaxis0->Draw();
  TGaxis *xaxis1 = new TGaxis(left+1*width,bottom,left+2*width,bottom,xmin,xmax-1e-4,divisions,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(labelsize);
  xaxis1->SetTitleSize(labelsize);
  xaxis1->SetTitleOffset(titleoff);
  xaxis1->Draw();
  TGaxis *xaxis2 = new TGaxis(left+2*width,bottom,left+3*width,bottom,xmin,xmax,divisions,"");
  xaxis2->SetName("xaxis2");
  xaxis2->SetTitle("p_{T} (GeV/c)");
  xaxis2->CenterTitle();
  xaxis2->SetLabelSize(labelsize);
  xaxis2->SetTitleSize(labelsize);
  xaxis2->SetTitleOffset(titleoff);
  xaxis2->Draw();


  c1_1->cd();
  c1_1->SetLeftMargin(0.0);
  c1_1->SetRightMargin(0.0);
  c1_1->SetTopMargin(0.0);
  c1_1->SetBottomMargin(0.0);
  c1_1->SetTicks(1,1);
  c1_1->SetLogy();
  pion->GetYaxis()->SetTitleSize(0.0);
  pion->GetYaxis()->SetLabelSize(0.0);
  pion->GetXaxis()->SetTitleSize(0.0);
  pion->GetXaxis()->SetLabelSize(0.0);
  pion->Draw("apz");
  TLatex *tls = new TLatex(3.0,1e9,"#sqrt{s_{NN}} = 200 GeV");
  tls->SetTextSize(0.06);
  tls->Draw();
  TLatex *tlp1 = new TLatex(1.0,5e-12,"#pi");
  tlp1->SetTextSize(0.1);
  tlp1->Draw();
  c1_2->cd();
  c1_2->SetLeftMargin(0.0);
  c1_2->SetRightMargin(0.0);
  c1_2->SetTopMargin(0.0);
  c1_2->SetBottomMargin(0.0);
  c1_2->SetTicks(1,1);
  c1_2->SetLogy();
  kaon->GetYaxis()->SetTitleSize(0.0);
  kaon->GetYaxis()->SetLabelSize(0.0);
  kaon->GetXaxis()->SetTitleSize(0.0);
  kaon->GetXaxis()->SetLabelSize(0.0);
  kaon->Draw("apz");
  leg1->Draw();
  TLatex *tlp2 = new TLatex(1.0,5e-12,"K");
  tlp2->SetTextSize(0.1);
  tlp2->Draw();
  c1_3->cd(); 
  c1_3->SetLeftMargin(0.0);
  c1_3->SetRightMargin(0.0);
  c1_3->SetTopMargin(0.0);
  c1_3->SetBottomMargin(0.0);
  c1_3->SetTicks(1,1);
  c1_3->SetLogy();
  prot->GetYaxis()->SetTitleSize(0.0);
  prot->GetYaxis()->SetLabelSize(0.0);
  prot->GetXaxis()->SetTitleSize(0.0);
  prot->GetXaxis()->SetLabelSize(0.0);
  prot->Draw("apz");
  leg2->Draw();
  TLatex *tlp3 = new TLatex(1.0,5e-12,"p");
  tlp3->SetTextSize(0.1);
  tlp3->Draw();

  c1->Print("figures/spectra_333.gif");
  c1->Print("figures/spectra_333.eps");

  c1->Clear();
  delete c1;

}

void doit(int r7pid=2, int r8pid=1)
{

  int number7 = 31;
  int number8 = 29;
  if(r7pid==4||r8pid==3) {number7 = 27;number8 = 26;}

  // int check = 35;
  // int check2 = 33;
  // if(r7pid==4||r8pid==3) {check = 31;check2 = 30;}


  double sysvalue = 0.1;

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
  c1_2->SetLeftMargin(0);
  c1_2->SetRightMargin(0.15);

  c1_1->SetTopMargin(0.03);
  c1_2->SetTopMargin(0.03);

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

  double pT_pospion0010AuAu[44], epT_pospion0010AuAu[44], yield_pospion0010AuAu[44], eyield_pospion0010AuAu[44], esysyield_pospion0010AuAu[44];
  double pT_pospion1020AuAu[44], epT_pospion1020AuAu[44], yield_pospion1020AuAu[44], eyield_pospion1020AuAu[44], esysyield_pospion1020AuAu[44];
  double pT_pospion2040AuAu[44], epT_pospion2040AuAu[44], yield_pospion2040AuAu[44], eyield_pospion2040AuAu[44], esysyield_pospion2040AuAu[44];
  double pT_pospion4060AuAu[44], epT_pospion4060AuAu[44], yield_pospion4060AuAu[44], eyield_pospion4060AuAu[44], esysyield_pospion4060AuAu[44];
  double pT_pospion6092AuAu[44], epT_pospion6092AuAu[44], yield_pospion6092AuAu[44], eyield_pospion6092AuAu[44], esysyield_pospion6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      yield_pospion0010AuAu[i] = 1e12;
      yield_pospion1020AuAu[i] = 1e12;
      yield_pospion2040AuAu[i] = 1e12;
      yield_pospion4060AuAu[i] = 1e12;
      yield_pospion6092AuAu[i] = 1e12;
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
      yield_pospion0010AuAu[i] *=1e4;eyield_pospion0010AuAu[i] *=1e4;
      yield_pospion1020AuAu[i] *=1e3;eyield_pospion1020AuAu[i] *=1e3;
      yield_pospion2040AuAu[i] *=1e2;eyield_pospion2040AuAu[i] *=1e2;
      yield_pospion4060AuAu[i] *=1e1;eyield_pospion4060AuAu[i] *=1e1;
      yield_pospion6092AuAu[i] *=1e0;eyield_pospion6092AuAu[i] *=1e0;
      //---
      sysvalue = 0.1;
      esysyield_pospion0010AuAu[i] = sysvalue*yield_pospion0010AuAu[i];
      esysyield_pospion1020AuAu[i] = sysvalue*yield_pospion1020AuAu[i];
      esysyield_pospion2040AuAu[i] = sysvalue*yield_pospion2040AuAu[i];
      esysyield_pospion4060AuAu[i] = sysvalue*yield_pospion4060AuAu[i];
      esysyield_pospion6092AuAu[i] = sysvalue*yield_pospion6092AuAu[i];
      if(i<5) // check
      	{ 
      	  yield_pospion0010AuAu[i] = 1e12;
      	  yield_pospion1020AuAu[i] = 1e12;
      	  yield_pospion2040AuAu[i] = 1e12;
      	  yield_pospion4060AuAu[i] = 1e12;
      	  yield_pospion6092AuAu[i] = 1e12;
      	}
      //cout<<i<<" "<<yield_pospion0010AuAu[i]<<endl;
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

  double pT_pospion0088dAu[44], epT_pospion0088dAu[44], yield_pospion0088dAu[44], eyield_pospion0088dAu[44], esysyield_pospion0088dAu[44];
  double pT_pospion0020dAu[44], epT_pospion0020dAu[44], yield_pospion0020dAu[44], eyield_pospion0020dAu[44], esysyield_pospion0020dAu[44];
  double pT_pospion2040dAu[44], epT_pospion2040dAu[44], yield_pospion2040dAu[44], eyield_pospion2040dAu[44], esysyield_pospion2040dAu[44];
  double pT_pospion4060dAu[44], epT_pospion4060dAu[44], yield_pospion4060dAu[44], eyield_pospion4060dAu[44], esysyield_pospion4060dAu[44];
  double pT_pospion6088dAu[44], epT_pospion6088dAu[44], yield_pospion6088dAu[44], eyield_pospion6088dAu[44], esysyield_pospion6088dAu[44];

  for(int i=0; i<44; i++)
    {
      yield_pospion0088dAu[i] = 1e12;
      yield_pospion0020dAu[i] = 1e12;
      yield_pospion2040dAu[i] = 1e12;
      yield_pospion4060dAu[i] = 1e12;
      yield_pospion6088dAu[i] = 1e12;
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
      // dAu scaling
      yield_pospion0020dAu[i] *= 1e-2;eyield_pospion0020dAu[i] *= 1e-2;
      yield_pospion2040dAu[i] *= 1e-3;eyield_pospion2040dAu[i] *= 1e-3;
      yield_pospion0088dAu[i] *= 1e-4;eyield_pospion0088dAu[i] *= 1e-4;
      yield_pospion4060dAu[i] *= 1e-5;eyield_pospion4060dAu[i] *= 1e-5;
      yield_pospion6088dAu[i] *= 1e-6;eyield_pospion6088dAu[i] *= 1e-6;
      // ---
      sysvalue = 0.1;
      esysyield_pospion0088dAu[i] = sysvalue*yield_pospion0088dAu[i];
      esysyield_pospion0020dAu[i] = sysvalue*yield_pospion0020dAu[i];
      esysyield_pospion2040dAu[i] = sysvalue*yield_pospion2040dAu[i];
      esysyield_pospion4060dAu[i] = sysvalue*yield_pospion4060dAu[i];
      esysyield_pospion6088dAu[i] = sysvalue*yield_pospion6088dAu[i];
      if(i<5) // check
      	{ 
      	  yield_pospion0088dAu[i] = 1e12;
      	  yield_pospion0020dAu[i] = 1e12;
      	  yield_pospion2040dAu[i] = 1e12;
      	  yield_pospion4060dAu[i] = 1e12;
      	  yield_pospion6088dAu[i] = 1e12;
      	}
    }
  fpospion0088dAu.close();
  fpospion0020dAu.close();
  fpospion2040dAu.close();
  fpospion4060dAu.close();
  fpospion6088dAu.close();




  TGraphErrors *tge_pospion0010AuAu = new TGraphErrors(number7,pT_pospion0010AuAu,yield_pospion0010AuAu,epT_pospion0010AuAu,eyield_pospion0010AuAu);
  tge_pospion0010AuAu->SetMarkerColor(kBlack);
  tge_pospion0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_pospion1020AuAu = new TGraphErrors(number7,pT_pospion1020AuAu,yield_pospion1020AuAu,epT_pospion1020AuAu,eyield_pospion1020AuAu);
  tge_pospion1020AuAu->SetMarkerColor(kBlack);
  tge_pospion1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_pospion2040AuAu = new TGraphErrors(number7,pT_pospion2040AuAu,yield_pospion2040AuAu,epT_pospion2040AuAu,eyield_pospion2040AuAu);
  tge_pospion2040AuAu->SetMarkerColor(kBlack);
  tge_pospion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_pospion4060AuAu = new TGraphErrors(number7,pT_pospion4060AuAu,yield_pospion4060AuAu,epT_pospion4060AuAu,eyield_pospion4060AuAu);
  tge_pospion4060AuAu->SetMarkerColor(kBlack);
  tge_pospion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_pospion6092AuAu = new TGraphErrors(number7,pT_pospion6092AuAu,yield_pospion6092AuAu,epT_pospion6092AuAu,eyield_pospion6092AuAu);
  tge_pospion6092AuAu->SetMarkerColor(kBlack);
  tge_pospion6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_pospion0088dAu = new TGraphErrors(number8,pT_pospion0088dAu,yield_pospion0088dAu,epT_pospion0088dAu,eyield_pospion0088dAu);
  tge_pospion0088dAu->SetMarkerColor(kBlack);
  tge_pospion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_pospion0020dAu = new TGraphErrors(number8,pT_pospion0020dAu,yield_pospion0020dAu,epT_pospion0020dAu,eyield_pospion0020dAu);
  tge_pospion0020dAu->SetMarkerColor(kBlack);
  tge_pospion0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_pospion2040dAu = new TGraphErrors(number8,pT_pospion2040dAu,yield_pospion2040dAu,epT_pospion2040dAu,eyield_pospion2040dAu);
  tge_pospion2040dAu->SetMarkerColor(kBlack);
  tge_pospion2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_pospion4060dAu = new TGraphErrors(number8,pT_pospion4060dAu,yield_pospion4060dAu,epT_pospion4060dAu,eyield_pospion4060dAu);
  tge_pospion4060dAu->SetMarkerColor(kBlack);
  tge_pospion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_pospion6088dAu = new TGraphErrors(number8,pT_pospion6088dAu,yield_pospion6088dAu,epT_pospion6088dAu,eyield_pospion6088dAu);
  tge_pospion6088dAu->SetMarkerColor(kBlack);
  tge_pospion6088dAu->SetMarkerStyle(kOpenDiamond);



  // --- SYSYSYSYSYS

  TGraphErrors *tgeS_pospion0010AuAu = new TGraphErrors(number7,pT_pospion0010AuAu,yield_pospion0010AuAu,epT_pospion0010AuAu,esysyield_pospion0010AuAu);
  TGraphErrors *tgeS_pospion1020AuAu = new TGraphErrors(number7,pT_pospion1020AuAu,yield_pospion1020AuAu,epT_pospion1020AuAu,esysyield_pospion1020AuAu);
  TGraphErrors *tgeS_pospion2040AuAu = new TGraphErrors(number7,pT_pospion2040AuAu,yield_pospion2040AuAu,epT_pospion2040AuAu,esysyield_pospion2040AuAu);
  TGraphErrors *tgeS_pospion4060AuAu = new TGraphErrors(number7,pT_pospion4060AuAu,yield_pospion4060AuAu,epT_pospion4060AuAu,esysyield_pospion4060AuAu);
  TGraphErrors *tgeS_pospion6092AuAu = new TGraphErrors(number7,pT_pospion6092AuAu,yield_pospion6092AuAu,epT_pospion6092AuAu,esysyield_pospion6092AuAu);
  TGraphErrors *tgeS_pospion0020dAu = new TGraphErrors(number8,pT_pospion0020dAu,yield_pospion0020dAu,epT_pospion0020dAu,esysyield_pospion0020dAu);
  TGraphErrors *tgeS_pospion2040dAu = new TGraphErrors(number8,pT_pospion2040dAu,yield_pospion2040dAu,epT_pospion2040dAu,esysyield_pospion2040dAu);
  TGraphErrors *tgeS_pospion0088dAu = new TGraphErrors(number8,pT_pospion0088dAu,yield_pospion0088dAu,epT_pospion0088dAu,esysyield_pospion0088dAu);
  TGraphErrors *tgeS_pospion4060dAu = new TGraphErrors(number8,pT_pospion4060dAu,yield_pospion4060dAu,epT_pospion4060dAu,esysyield_pospion4060dAu);
  TGraphErrors *tgeS_pospion6088dAu = new TGraphErrors(number8,pT_pospion6088dAu,yield_pospion6088dAu,epT_pospion6088dAu,esysyield_pospion6088dAu);
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


  // ---
  tge_pospion0010AuAu->SetMarkerColor(kBlack);    
  tge_pospion1020AuAu->SetMarkerColor(kRed);      
  tge_pospion2040AuAu->SetMarkerColor(kBlue);     
  tge_pospion4060AuAu->SetMarkerColor(kGreen+2);  
  tge_pospion6092AuAu->SetMarkerColor(kMagenta+2);
  // ---
  tge_pospion0020dAu->SetMarkerColor(kBlack);    
  tge_pospion2040dAu->SetMarkerColor(kRed);      
  tge_pospion0088dAu->SetMarkerColor(kBlue);     
  tge_pospion4060dAu->SetMarkerColor(kGreen+2);  
  tge_pospion6088dAu->SetMarkerColor(kMagenta+2);



  //c1->cd(1); // first panel of canvas
  c1_1->cd();
  TMultiGraph *pospion = new TMultiGraph();
  // pospion->Add(tgeS_pospion0010AuAu);
  // pospion->Add(tgeS_pospion1020AuAu);
  // pospion->Add(tgeS_pospion2040AuAu);
  // pospion->Add(tgeS_pospion4060AuAu);
  // pospion->Add(tgeS_pospion6092AuAu);
  // pospion->Add(tgeS_pospion0020dAu);
  // pospion->Add(tgeS_pospion0088dAu);
  // pospion->Add(tgeS_pospion2040dAu);
  // pospion->Add(tgeS_pospion4060dAu);
  // pospion->Add(tgeS_pospion6088dAu);
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
  pospion->SetMaximum(MAX);
  pospion->SetMinimum(MIN);
  pospion->GetXaxis()->SetLimits(xmin,xmax);
  pospion->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  pospion->GetXaxis()->CenterTitle();
  pospion->GetYaxis()->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  pospion->GetYaxis()->CenterTitle();
  pospion->GetYaxis()->SetTitleOffset(1.5);
  pospion->GetYaxis()->SetTitleSize(0.045); // NEW
  pospion->GetYaxis()->SetLabelSize(0.045); // NEW
  pospion->GetXaxis()->SetTitleSize(0.045); // NEW
  pospion->GetXaxis()->SetLabelSize(0.045); // NEW

  //TPaveText *pospave = new TPaveText(1.3,3e3,2.3,3e4);
  //TPaveText *pospave = new TPaveText(0.8,3e3,1.5,3e4);
  TPaveText *pospave = new TPaveText(0.8,1e8,1.5,1e9);
  pospave->SetFillColor(kWhite);
  pospave->SetBorderSize(0);
  if(r7pid<=3) pospave->AddText("#pi^{+}");
  else if(r7pid<=5) pospave->AddText("K^{+}");
  else if(r7pid>=6) pospave->AddText("p");
  else pospave->AddText("h^{+}");
  pospave->SetTextSize(0.07);
  pospave->Draw();

  TPaveText *pospave2 = new TPaveText(3.7,1e9,5.7,1e10);
  pospave2->SetFillColor(kWhite);
  pospave2->SetBorderSize(0);
  pospave2->AddText("#sqrt{s_{NN}} = 200 GeV");
  pospave2->SetTextSize(0.035);
  pospave2->Draw();

  TLegend *leg_pospion = new TLegend(0.45,0.73,0.68,0.93);
  leg_pospion->SetFillColor(kWhite);
  leg_pospion->SetBorderSize(0);
  leg_pospion->SetHeader("Au+Au");
  leg_pospion->AddEntry(tge_pospion0010AuAu,"0-10% #times 20","p");
  leg_pospion->AddEntry(tge_pospion1020AuAu,"10-20% #times 5","p");
  leg_pospion->AddEntry(tge_pospion2040AuAu,"20-40% #times 2","p");
  leg_pospion->AddEntry(tge_pospion4060AuAu,"40-60%","p");
  leg_pospion->AddEntry(tge_pospion6092AuAu,"60-92%","p");
  leg_pospion->SetTextSize(0.035);
  //leg_pospion->Draw();

  TLegend *leg_pospion2 = new TLegend(0.68,0.73,0.92,0.93);
  leg_pospion2->SetFillColor(kWhite);
  leg_pospion2->SetBorderSize(0);
  leg_pospion2->SetHeader("d+Au");
  leg_pospion2->AddEntry(tge_pospion0020dAu,"0-20% #times 0.13","p");
  leg_pospion2->AddEntry(tge_pospion2040dAu,"20-40% #times 0.035","p");
  leg_pospion2->AddEntry(tge_pospion0088dAu,"0-88% #times 0.0075","p");
  leg_pospion2->AddEntry(tge_pospion4060dAu,"40-60% #times 0.002","p");
  leg_pospion2->AddEntry(tge_pospion6088dAu,"60-88% #times 0.001","p");
  leg_pospion2->SetTextSize(0.035);
  //leg_pospion2->Draw();



  // -------------------- //
  // -------------------- //
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

  double pT_negpion0010AuAu[44], epT_negpion0010AuAu[44], yield_negpion0010AuAu[44], eyield_negpion0010AuAu[44], esysyield_negpion0010AuAu[44];
  double pT_negpion1020AuAu[44], epT_negpion1020AuAu[44], yield_negpion1020AuAu[44], eyield_negpion1020AuAu[44], esysyield_negpion1020AuAu[44];
  double pT_negpion2040AuAu[44], epT_negpion2040AuAu[44], yield_negpion2040AuAu[44], eyield_negpion2040AuAu[44], esysyield_negpion2040AuAu[44];
  double pT_negpion4060AuAu[44], epT_negpion4060AuAu[44], yield_negpion4060AuAu[44], eyield_negpion4060AuAu[44], esysyield_negpion4060AuAu[44];
  double pT_negpion6092AuAu[44], epT_negpion6092AuAu[44], yield_negpion6092AuAu[44], eyield_negpion6092AuAu[44], esysyield_negpion6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      yield_negpion0010AuAu[i] = 1e12;
      yield_negpion1020AuAu[i] = 1e12;
      yield_negpion2040AuAu[i] = 1e12;
      yield_negpion4060AuAu[i] = 1e12;
      yield_negpion6092AuAu[i] = 1e12;
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
      yield_negpion0010AuAu[i] *=1e4;eyield_negpion0010AuAu[i] *=1e4;
      yield_negpion1020AuAu[i] *=1e3;eyield_negpion1020AuAu[i] *=1e3;
      yield_negpion2040AuAu[i] *=1e2;eyield_negpion2040AuAu[i] *=1e2;
      yield_negpion4060AuAu[i] *=1e1;eyield_negpion4060AuAu[i] *=1e1;
      yield_negpion6092AuAu[i] *=1e0;eyield_negpion6092AuAu[i] *=1e0;
      // ---
      sysvalue = 0.1;
      esysyield_negpion0010AuAu[i] = sysvalue*yield_negpion0010AuAu[i];
      esysyield_negpion1020AuAu[i] = sysvalue*yield_negpion1020AuAu[i];
      esysyield_negpion2040AuAu[i] = sysvalue*yield_negpion2040AuAu[i];
      esysyield_negpion4060AuAu[i] = sysvalue*yield_negpion4060AuAu[i];
      esysyield_negpion6092AuAu[i] = sysvalue*yield_negpion6092AuAu[i];
      if(i<5) // check
      	{ 
      	  yield_negpion0010AuAu[i] = 1e12;
      	  yield_negpion1020AuAu[i] = 1e12;
      	  yield_negpion2040AuAu[i] = 1e12;
      	  yield_negpion4060AuAu[i] = 1e12;
      	  yield_negpion6092AuAu[i] = 1e12;
      	}
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

  double pT_negpion0088dAu[44], epT_negpion0088dAu[44], yield_negpion0088dAu[44], eyield_negpion0088dAu[44], esysyield_negpion0088dAu[44];
  double pT_negpion0020dAu[44], epT_negpion0020dAu[44], yield_negpion0020dAu[44], eyield_negpion0020dAu[44], esysyield_negpion0020dAu[44];
  double pT_negpion2040dAu[44], epT_negpion2040dAu[44], yield_negpion2040dAu[44], eyield_negpion2040dAu[44], esysyield_negpion2040dAu[44];
  double pT_negpion4060dAu[44], epT_negpion4060dAu[44], yield_negpion4060dAu[44], eyield_negpion4060dAu[44], esysyield_negpion4060dAu[44];
  double pT_negpion6088dAu[44], epT_negpion6088dAu[44], yield_negpion6088dAu[44], eyield_negpion6088dAu[44], esysyield_negpion6088dAu[44];

  for(int i=0; i<44; i++)
    {
      yield_negpion0088dAu[i] = 1e12;
      yield_negpion0020dAu[i] = 1e12;
      yield_negpion2040dAu[i] = 1e12;
      yield_negpion4060dAu[i] = 1e12;
      yield_negpion6088dAu[i] = 1e12;
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
      yield_negpion0020dAu[i] *= 1e-2;eyield_negpion0020dAu[i] *= 1e-2;
      yield_negpion2040dAu[i] *= 1e-3;eyield_negpion2040dAu[i] *= 1e-3;
      yield_negpion0088dAu[i] *= 1e-4;eyield_negpion0088dAu[i] *= 1e-4;
      yield_negpion4060dAu[i] *= 1e-5;eyield_negpion4060dAu[i] *= 1e-5;
      yield_negpion6088dAu[i] *= 1e-6;eyield_negpion6088dAu[i] *= 1e-6;
      sysvalue = 0.1;
      esysyield_negpion0088dAu[i] = sysvalue*yield_negpion0088dAu[i];
      esysyield_negpion0020dAu[i] = sysvalue*yield_negpion0020dAu[i];
      esysyield_negpion2040dAu[i] = sysvalue*yield_negpion2040dAu[i];
      esysyield_negpion4060dAu[i] = sysvalue*yield_negpion4060dAu[i];
      esysyield_negpion6088dAu[i] = sysvalue*yield_negpion6088dAu[i];
      if(i<5) // check
      	{ 
      	  yield_negpion0088dAu[i] = 1e12;
      	  yield_negpion0020dAu[i] = 1e12;
      	  yield_negpion2040dAu[i] = 1e12;
      	  yield_negpion4060dAu[i] = 1e12;
      	  yield_negpion6088dAu[i] = 1e12;
      	}
    }
  fnegpion0088dAu.close();
  fnegpion0020dAu.close();
  fnegpion2040dAu.close();
  fnegpion4060dAu.close();
  fnegpion6088dAu.close();




  TGraphErrors *tge_negpion0010AuAu = new TGraphErrors(number7,pT_negpion0010AuAu,yield_negpion0010AuAu,epT_negpion0010AuAu,eyield_negpion0010AuAu);
  tge_negpion0010AuAu->SetMarkerColor(kBlack);
  tge_negpion0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_negpion1020AuAu = new TGraphErrors(number7,pT_negpion1020AuAu,yield_negpion1020AuAu,epT_negpion1020AuAu,eyield_negpion1020AuAu);
  tge_negpion1020AuAu->SetMarkerColor(kBlack);
  tge_negpion1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_negpion2040AuAu = new TGraphErrors(number7,pT_negpion2040AuAu,yield_negpion2040AuAu,epT_negpion2040AuAu,eyield_negpion2040AuAu);
  tge_negpion2040AuAu->SetMarkerColor(kBlack);
  tge_negpion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_negpion4060AuAu = new TGraphErrors(number7,pT_negpion4060AuAu,yield_negpion4060AuAu,epT_negpion4060AuAu,eyield_negpion4060AuAu);
  tge_negpion4060AuAu->SetMarkerColor(kBlack);
  tge_negpion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_negpion6092AuAu = new TGraphErrors(number7,pT_negpion6092AuAu,yield_negpion6092AuAu,epT_negpion6092AuAu,eyield_negpion6092AuAu);
  tge_negpion6092AuAu->SetMarkerColor(kBlack);
  tge_negpion6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_negpion0088dAu = new TGraphErrors(number8,pT_negpion0088dAu,yield_negpion0088dAu,epT_negpion0088dAu,eyield_negpion0088dAu);
  tge_negpion0088dAu->SetMarkerColor(kBlack);
  tge_negpion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_negpion0020dAu = new TGraphErrors(number8,pT_negpion0020dAu,yield_negpion0020dAu,epT_negpion0020dAu,eyield_negpion0020dAu);
  tge_negpion0020dAu->SetMarkerColor(kBlack);
  tge_negpion0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_negpion2040dAu = new TGraphErrors(number8,pT_negpion2040dAu,yield_negpion2040dAu,epT_negpion2040dAu,eyield_negpion2040dAu);
  tge_negpion2040dAu->SetMarkerColor(kBlack);
  tge_negpion2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_negpion4060dAu = new TGraphErrors(number8,pT_negpion4060dAu,yield_negpion4060dAu,epT_negpion4060dAu,eyield_negpion4060dAu);
  tge_negpion4060dAu->SetMarkerColor(kBlack);
  tge_negpion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_negpion6088dAu = new TGraphErrors(number8,pT_negpion6088dAu,yield_negpion6088dAu,epT_negpion6088dAu,eyield_negpion6088dAu);
  tge_negpion6088dAu->SetMarkerColor(kBlack);
  tge_negpion6088dAu->SetMarkerStyle(kOpenDiamond);

  // --- SYSYSYSYSYS

  TGraphErrors *tgeS_negpion0010AuAu = new TGraphErrors(number7,pT_negpion0010AuAu,yield_negpion0010AuAu,epT_negpion0010AuAu,esysyield_negpion0010AuAu);
  TGraphErrors *tgeS_negpion1020AuAu = new TGraphErrors(number7,pT_negpion1020AuAu,yield_negpion1020AuAu,epT_negpion1020AuAu,esysyield_negpion1020AuAu);
  TGraphErrors *tgeS_negpion2040AuAu = new TGraphErrors(number7,pT_negpion2040AuAu,yield_negpion2040AuAu,epT_negpion2040AuAu,esysyield_negpion2040AuAu);
  TGraphErrors *tgeS_negpion4060AuAu = new TGraphErrors(number7,pT_negpion4060AuAu,yield_negpion4060AuAu,epT_negpion4060AuAu,esysyield_negpion4060AuAu);
  TGraphErrors *tgeS_negpion6092AuAu = new TGraphErrors(number7,pT_negpion6092AuAu,yield_negpion6092AuAu,epT_negpion6092AuAu,esysyield_negpion6092AuAu);
  TGraphErrors *tgeS_negpion0020dAu = new TGraphErrors(number8,pT_negpion0020dAu,yield_negpion0020dAu,epT_negpion0020dAu,esysyield_negpion0020dAu);
  TGraphErrors *tgeS_negpion2040dAu = new TGraphErrors(number8,pT_negpion2040dAu,yield_negpion2040dAu,epT_negpion2040dAu,esysyield_negpion2040dAu);
  TGraphErrors *tgeS_negpion0088dAu = new TGraphErrors(number8,pT_negpion0088dAu,yield_negpion0088dAu,epT_negpion0088dAu,esysyield_negpion0088dAu);
  TGraphErrors *tgeS_negpion4060dAu = new TGraphErrors(number8,pT_negpion4060dAu,yield_negpion4060dAu,epT_negpion4060dAu,esysyield_negpion4060dAu);
  TGraphErrors *tgeS_negpion6088dAu = new TGraphErrors(number8,pT_negpion6088dAu,yield_negpion6088dAu,epT_negpion6088dAu,esysyield_negpion6088dAu);
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



  // ---
  tge_negpion0010AuAu->SetMarkerColor(kBlack);    
  tge_negpion1020AuAu->SetMarkerColor(kRed);      
  tge_negpion2040AuAu->SetMarkerColor(kBlue);     
  tge_negpion4060AuAu->SetMarkerColor(kGreen+2);  
  tge_negpion6092AuAu->SetMarkerColor(kMagenta+2);
  // ---
  tge_negpion0020dAu->SetMarkerColor(kBlack);    
  tge_negpion2040dAu->SetMarkerColor(kRed);      
  tge_negpion0088dAu->SetMarkerColor(kBlue);     
  tge_negpion4060dAu->SetMarkerColor(kGreen+2);  
  tge_negpion6088dAu->SetMarkerColor(kMagenta+2);



  //c1->cd(2); // second panel of canvas
  c1_2->cd();
  TMultiGraph *negpion = new TMultiGraph();
  // negpion->Add(tgeS_negpion0010AuAu);
  // negpion->Add(tgeS_negpion1020AuAu);
  // negpion->Add(tgeS_negpion2040AuAu);
  // negpion->Add(tgeS_negpion4060AuAu);
  // negpion->Add(tgeS_negpion6092AuAu);
  // negpion->Add(tgeS_negpion0020dAu);
  // negpion->Add(tgeS_negpion0088dAu);
  // negpion->Add(tgeS_negpion2040dAu);
  // negpion->Add(tgeS_negpion4060dAu);
  // negpion->Add(tgeS_negpion6088dAu);
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
  negpion->SetMaximum(MAX);
  negpion->SetMinimum(MIN);
  negpion->GetXaxis()->SetLimits(xmin,xmax);
  negpion->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  negpion->GetXaxis()->CenterTitle();
  negpion->GetYaxis()->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  negpion->GetYaxis()->CenterTitle();
  negpion->GetYaxis()->SetTitleOffset(1.5);
  negpion->GetYaxis()->SetTitleSize(0); // NEW
  negpion->GetYaxis()->SetLabelSize(0); // NEW
  negpion->GetXaxis()->SetTitleSize(0.045); // NEW
  negpion->GetXaxis()->SetLabelSize(0.045); // NEW

  //TPaveText *negpave = new TPaveText(1.3,3e3,2.3,3e4);
  TPaveText *negpave = new TPaveText(0.8,1e8,1.5,1e9);
  negpave->SetFillColor(kWhite);
  negpave->SetBorderSize(0);
  if(r7pid<=3) negpave->AddText("#pi^{-}");
  else if(r7pid<=5) negpave->AddText("K^{-}");
  else if(r7pid>=6) negpave->AddText("#bar{p}");
  else negpave->AddText("h^{-}");
  negpave->SetTextSize(0.07);
  negpave->Draw();

  //TLegend *leg_negpion = new TLegend(0.30,0.73,0.53,0.93);
  TLegend *leg_negpion = new TLegend(0.28,0.73,0.51,0.93);
  leg_negpion->SetFillColor(kWhite);
  leg_negpion->SetBorderSize(0);
  leg_negpion->SetHeader("Au+Au");
  leg_negpion->AddEntry(tge_negpion0010AuAu,"0-10% #times 10^{4}","p");
  leg_negpion->AddEntry(tge_negpion1020AuAu,"10-20% #times 10^{3}","p");
  leg_negpion->AddEntry(tge_negpion2040AuAu,"20-40% #times 10^{2}","p");
  leg_negpion->AddEntry(tge_negpion4060AuAu,"40-60% #times 10^{1}","p");
  leg_negpion->AddEntry(tge_negpion6092AuAu,"60-92% #times 10^{0}","p");
  leg_negpion->SetTextSize(0.035);
  leg_negpion->Draw();

  TLegend *leg_negpion2 = new TLegend(0.53,0.73,0.79,0.93);
  leg_negpion2->SetFillColor(kWhite);
  leg_negpion2->SetBorderSize(0);
  leg_negpion2->SetHeader("d+Au");
  leg_negpion2->AddEntry(tge_negpion0020dAu,"0-20% #times 10^{-2}","p");
  leg_negpion2->AddEntry(tge_negpion2040dAu,"20-40% #times 10^{-3}","p");
  //leg_negpion2->AddEntry(tge_negpion0088dAu,"min. bias #times 10^{-4}","p");
  leg_negpion2->AddEntry(tge_negpion0088dAu,"0-100% #times 10^{-4}","p");
  leg_negpion2->AddEntry(tge_negpion4060dAu,"40-60% #times 10^{-5}","p");
  leg_negpion2->AddEntry(tge_negpion6088dAu,"60-88% #times 10^{-6}","p");
  leg_negpion2->SetTextSize(0.035);
  leg_negpion2->Draw();





  TLegend *leg_1 = new TLegend(0.50,0.68,0.80,0.96);
  leg_1->SetFillColor(kWhite);
  leg_1->SetBorderSize(0);
  leg_1->SetHeader("Au+Au");
  leg_1->AddEntry(tge_negpion0010AuAu,"0-10% #times 10^{4}","p");
  leg_1->AddEntry(tge_negpion1020AuAu,"10-20% #times 10^{3}","p");
  leg_1->AddEntry(tge_negpion2040AuAu,"20-40% #times 10^{2}","p");
  leg_1->AddEntry(tge_negpion4060AuAu,"40-60% #times 10^{1}","p");
  leg_1->AddEntry(tge_negpion6092AuAu,"60-92% #times 10^{0}","p");
  leg_1->SetTextSize(0.06);
  //leg_1->Draw();

  TLegend *leg_2 = new TLegend(0.50,0.68,0.80,0.96);
  leg_2->SetFillColor(kWhite);
  leg_2->SetBorderSize(0);
  leg_2->SetHeader("d+Au");
  leg_2->AddEntry(tge_negpion0010AuAu,"0-20% #times 10^{-2}","p");
  leg_2->AddEntry(tge_negpion1020AuAu,"20-40% #times 10^{-3}","p");
  //leg_2->AddEntry(tge_negpion2040AuAu,"min. bias #times 10^{-4}","p");
  leg_2->AddEntry(tge_negpion2040AuAu,"0-100% #times 10^{-4}","p");
  leg_2->AddEntry(tge_negpion4060AuAu,"40-60% #times 10^{-5}","p");
  leg_2->AddEntry(tge_negpion6092AuAu,"60-88% #times 10^{-6}","p");
  leg_2->SetTextSize(0.06);
  //leg_2->Draw();


  leg1 = (TLegend *)leg_1->Clone();
  leg2 = (TLegend *)leg_2->Clone();

  // COME BACK HERE


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
  // tmg->Add(tgeS_negpion0010AuAu);
  // tmg->Add(tgeS_negpion1020AuAu);
  // tmg->Add(tgeS_negpion2040AuAu);
  // tmg->Add(tgeS_negpion4060AuAu);
  // tmg->Add(tgeS_negpion6092AuAu);
  // tmg->Add(tgeS_negpion0020dAu);
  // tmg->Add(tgeS_negpion0088dAu);
  // tmg->Add(tgeS_negpion2040dAu);
  // tmg->Add(tgeS_negpion4060dAu);
  // tmg->Add(tgeS_negpion6088dAu);
  // tmg->Add(tgeS_pospion0010AuAu);
  // tmg->Add(tgeS_pospion1020AuAu);
  // tmg->Add(tgeS_pospion2040AuAu);
  // tmg->Add(tgeS_pospion4060AuAu);
  // tmg->Add(tgeS_pospion6092AuAu);
  // tmg->Add(tgeS_pospion0020dAu);
  // tmg->Add(tgeS_pospion0088dAu);
  // tmg->Add(tgeS_pospion2040dAu);
  // tmg->Add(tgeS_pospion4060dAu);
  // tmg->Add(tgeS_pospion6088dAu);
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
  tmg->SetMaximum(MAX);
  tmg->SetMinimum(MIN);
  tmg->GetXaxis()->SetLimits(xmin,xmax);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitleOffset(1.5);

  if(r7pid<=3)      tmg_pion = (TMultiGraph *)tmg->Clone();
  else if(r7pid>=6) tmg_prot = (TMultiGraph *)tmg->Clone();
  else              tmg_kaon = (TMultiGraph *)tmg->Clone();

  c2->Draw();

  // sprintf(figname,"figures/spectra_pnx_%s.gif",particle);
  // c2->Print(figname);
  // sprintf(figname,"figures/spectra_pnx_%s.eps",particle);
  // c2->Print(figname);

  c2->Clear();
  delete c2;





  tge_pospion0010AuAu->SetMarkerStyle(kFullCircle);
  tge_pospion1020AuAu->SetMarkerStyle(kFullSquare);
  tge_pospion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  tge_pospion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  tge_pospion6092AuAu->SetMarkerStyle(kFullDiamond);

  tge_pospion0020dAu->SetMarkerStyle(kOpenCircle);
  tge_pospion2040dAu->SetMarkerStyle(kOpenSquare);
  tge_pospion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  tge_pospion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  tge_pospion6088dAu->SetMarkerStyle(kOpenDiamond);

  tge_negpion0010AuAu->SetMarkerStyle(kFullCircle);
  tge_negpion1020AuAu->SetMarkerStyle(kFullSquare);
  tge_negpion2040AuAu->SetMarkerStyle(kFullTriangleUp);
  tge_negpion4060AuAu->SetMarkerStyle(kFullTriangleDown);
  tge_negpion6092AuAu->SetMarkerStyle(kFullDiamond);

  tge_negpion0020dAu->SetMarkerStyle(kOpenCircle);
  tge_negpion2040dAu->SetMarkerStyle(kOpenSquare);
  tge_negpion0088dAu->SetMarkerStyle(kOpenTriangleUp);
  tge_negpion4060dAu->SetMarkerStyle(kOpenTriangleDown);
  tge_negpion6088dAu->SetMarkerStyle(kOpenDiamond);




  TCanvas *c3 = new TCanvas("c3","c3");
  c3->SetLogy();

  TMultiGraph *tmgpos = new TMultiGraph();
  tmgpos->Add(tge_pospion0010AuAu);
  tmgpos->Add(tge_pospion1020AuAu);
  tmgpos->Add(tge_pospion2040AuAu);
  tmgpos->Add(tge_pospion4060AuAu);
  tmgpos->Add(tge_pospion6092AuAu);
  tmgpos->Add(tge_pospion0020dAu);
  tmgpos->Add(tge_pospion0088dAu);
  tmgpos->Add(tge_pospion2040dAu);
  tmgpos->Add(tge_pospion4060dAu);
  tmgpos->Add(tge_pospion6088dAu);
  tmgpos->Draw("apz");
  tmgpos->SetMaximum(MAX);
  tmgpos->SetMinimum(MIN);
  tmgpos->GetXaxis()->SetLimits(xmin,xmax);
  tmgpos->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos->GetXaxis()->CenterTitle();
  tmgpos->GetYaxis()->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  tmgpos->GetYaxis()->CenterTitle();
  tmgpos->GetYaxis()->SetTitleOffset(1.5);


  if(r7pid<=3)      tmg_pospion = (TMultiGraph *)tmgpos->Clone();
  else if(r7pid>=6) tmg_posprot = (TMultiGraph *)tmgpos->Clone();
  else              tmg_poskaon = (TMultiGraph *)tmgpos->Clone();

  c3->Draw();

  // sprintf(figname,"figures/spectra_pnx_%s.gif",particle);
  // c3->Print(figname);
  // sprintf(figname,"figures/spectra_pnx_%s.eps",particle);
  // c3->Print(figname);

  c3->Clear();



  TMultiGraph *tmgneg = new TMultiGraph();
  tmgneg->Add(tge_negpion0010AuAu);
  tmgneg->Add(tge_negpion1020AuAu);
  tmgneg->Add(tge_negpion2040AuAu);
  tmgneg->Add(tge_negpion4060AuAu);
  tmgneg->Add(tge_negpion6092AuAu);
  tmgneg->Add(tge_negpion0020dAu);
  tmgneg->Add(tge_negpion0088dAu);
  tmgneg->Add(tge_negpion2040dAu);
  tmgneg->Add(tge_negpion4060dAu);
  tmgneg->Add(tge_negpion6088dAu);
  tmgneg->Draw("apz");
  tmgneg->SetMaximum(MAX);
  tmgneg->SetMinimum(MIN);
  tmgneg->GetXaxis()->SetLimits(xmin,xmax);
  tmgneg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgneg->GetXaxis()->CenterTitle();
  tmgneg->GetYaxis()->SetTitle("d^{2}N/(2#pip_{T}dp_{T}dy) (c^{2}/GeV^{2})");
  tmgneg->GetYaxis()->CenterTitle();
  tmgneg->GetYaxis()->SetTitleOffset(1.5);

  if(r7pid<=3)      tmg_negpion = (TMultiGraph *)tmgneg->Clone();
  else if(r7pid>=6) tmg_negprot = (TMultiGraph *)tmgneg->Clone();
  else              tmg_negkaon = (TMultiGraph *)tmgneg->Clone();

  c3->Draw();



  TLegend *legneg_1 = new TLegend(0.40,0.68,0.80,0.96);
  legneg_1->SetFillColor(kWhite);
  legneg_1->SetBorderSize(0);
  legneg_1->SetHeader("Au+Au");
  legneg_1->AddEntry(tge_negpion0010AuAu,"0-10% #times 10^{4}","p");
  legneg_1->AddEntry(tge_negpion1020AuAu,"10-20% #times 10^{3}","p");
  legneg_1->AddEntry(tge_negpion2040AuAu,"20-40% #times 10^{2}","p");
  legneg_1->AddEntry(tge_negpion4060AuAu,"40-60% #times 10^{1}","p");
  legneg_1->AddEntry(tge_negpion6092AuAu,"60-92% #times 10^{0}","p");
  legneg_1->SetTextSize(0.06);
  //legneg_1->Draw();

  TLegend *legneg_2 = new TLegend(0.40,0.68,0.80,0.96);
  legneg_2->SetFillColor(kWhite);
  legneg_2->SetBorderSize(0);
  legneg_2->SetHeader("d+Au");
  legneg_2->AddEntry(tge_negpion0020dAu,"0-20% #times 10^{-2}","p");
  legneg_2->AddEntry(tge_negpion2040dAu,"20-40% #times 10^{-3}","p");
  //legneg_2->AddEntry(tge_negpion0088dAu,"min. bias #times 10^{-4}","p");
  legneg_2->AddEntry(tge_negpion0088dAu,"0-100% #times 10^{-4}","p");
  legneg_2->AddEntry(tge_negpion4060dAu,"40-60% #times 10^{-5}","p");
  legneg_2->AddEntry(tge_negpion6088dAu,"60-88% #times 10^{-6}","p");
  legneg_2->SetTextSize(0.06);
  //legneg_2->Draw();

  legneg1 = (TLegend *)legneg_1->Clone();
  legneg2 = (TLegend *)legneg_2->Clone();

  // sprintf(figname,"figures/spectra_pnx_%s.gif",particle);
  // c3->Print(figname);
  // sprintf(figname,"figures/spectra_pnx_%s.eps",particle);
  // c3->Print(figname);

  c3->Clear();
  delete c3;





}
