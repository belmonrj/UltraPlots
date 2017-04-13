void aud_kpi()
{

  float pt_auau[36];
  float pt_dau[36];
  float ept_auau[36];
  float ept_dau[36];
  float ratiopos_auau[36];
  float ratiopos_dau[36];
  float rationeg_auau[36];
  float rationeg_dau[36];
  float eratiopos_auau[36];
  float eratiopos_dau[36];
  float erationeg_auau[36];
  float erationeg_dau[36];
  float esysratiopos_auau[36];
  float esysratiopos_dau[36];
  float esysrationeg_auau[36];
  float esysrationeg_dau[36];

  int number = 26;

  ifstream fauau("../Run7AuAu/Ratios/regular/kpi_04_cent6092.txt");
  ifstream fdau("../Run8dAu/Ratios/regular/kpi_13_cent0020.txt");
  for(int i=0; i<36; i++)
    {
      fauau>>pt_auau[i]>>ratiopos_auau[i]>>eratiopos_auau[i]>>rationeg_auau[i]>>erationeg_auau[i];
      fdau>>pt_dau[i]>>ratiopos_dau[i]>>eratiopos_dau[i]>>rationeg_dau[i]>>erationeg_dau[i];
      if(i<5)
	{
	  ratiopos_auau[i] = -9;
	  rationeg_auau[i] = -9;
	  ratiopos_dau[i] = -9;
	  rationeg_dau[i] = -9;	  
	}
      ept_auau[i]=0;
      ept_dau[i]=0;
      esysratiopos_auau[i]=0.05*ratiopos_auau[i];
      esysratiopos_dau[i]=0.05*ratiopos_dau[i];
      esysrationeg_auau[i]=0.05*rationeg_auau[i];
      esysrationeg_dau[i]=0.05*rationeg_dau[i];
    }

  TGraphErrors *tge_sysratiopos_auau = new TGraphErrors(number,pt_auau,ratiopos_auau,ept_auau,esysratiopos_auau);
  tge_sysratiopos_auau->SetMarkerColor(kGray);
  tge_sysratiopos_auau->SetLineColor(kGray);
  tge_sysratiopos_auau->SetLineWidth(15);
  TGraphErrors *tge_sysratiopos_dau = new TGraphErrors(number,pt_dau,ratiopos_dau,ept_dau,esysratiopos_dau);
  tge_sysratiopos_dau->SetMarkerColor(kGray);
  tge_sysratiopos_dau->SetLineColor(kGray);
  tge_sysratiopos_dau->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau = new TGraphErrors(number,pt_auau,rationeg_auau,ept_auau,esysrationeg_auau);
  tge_sysrationeg_auau->SetMarkerColor(kGray);
  tge_sysrationeg_auau->SetLineColor(kGray);
  tge_sysrationeg_auau->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau = new TGraphErrors(number,pt_dau,rationeg_dau,ept_dau,esysrationeg_dau);
  tge_sysrationeg_dau->SetMarkerColor(kGray);
  tge_sysrationeg_dau->SetLineColor(kGray);
  tge_sysrationeg_dau->SetLineWidth(15);
  // ---
  TGraphErrors *tge_ratiopos_auau = new TGraphErrors(number,pt_auau,ratiopos_auau,ept_auau,eratiopos_auau);
  tge_ratiopos_auau->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau = new TGraphErrors(number,pt_auau,rationeg_auau,ept_auau,erationeg_auau);
  tge_rationeg_auau->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau->SetMarkerColor(kBlue);

  TGraphErrors *tge_ratiopos_dau = new TGraphErrors(number,pt_dau,ratiopos_dau,ept_dau,eratiopos_dau);
  tge_ratiopos_dau->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_dau->SetMarkerColor(kGreen+2);
  TGraphErrors *tge_rationeg_dau = new TGraphErrors(number,pt_dau,rationeg_dau,ept_dau,erationeg_dau);
  tge_rationeg_dau->SetMarkerStyle(kFullTriangleDown);
  tge_rationeg_dau->SetMarkerColor(kMagenta+2);




  // DIFFERENT
  // tge_ratiopos_auau->SetMarkerStyle(kFullCircle);
  // tge_ratiopos_dau->SetMarkerStyle(kOpenSquare);
  // tge_rationeg_auau->SetMarkerStyle(kFullCircle);
  // tge_rationeg_dau->SetMarkerStyle(kOpenSquare);
  tge_ratiopos_auau->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau->SetMarkerStyle(kOpenCircle);
  tge_rationeg_auau->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau->SetMarkerStyle(kOpenSquare);

  // SAME
  tge_ratiopos_auau->SetMarkerColor(kRed);
  tge_ratiopos_dau->SetMarkerColor(kGreen+2);
  tge_rationeg_auau->SetMarkerColor(kBlue);
  tge_rationeg_dau->SetMarkerColor(kMagenta+2);
  // new
  tge_sysratiopos_auau->SetLineColor(kRed-9);
  tge_sysratiopos_dau->SetLineColor(kGreen-9);
  tge_sysrationeg_auau->SetLineColor(kBlue-9);
  tge_sysrationeg_dau->SetLineColor(kMagenta-9);




  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();



  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.0,1.0,1.0);
  c1_1->Draw();
  c1_1->SetTopMargin(0.05);
  c1_1->SetRightMargin(0.05);
  c1_1->SetBottomMargin(0.15);
  c1_1->SetLeftMargin(0.15);
  c1_1->SetTicks(1,1);

  float size = 0.055; // very, very close to previous settings before using TGaxis...
  float scale = 1.0;
  float titleoff = 1.0;
  int ndivisions = 510;

  //TGaxis *yaxis0 = new TGaxis(0.15,0.15,0.15,0.95,0.0,0.7,ndivisions,"S");
  TGaxis *yaxis0 = new TGaxis(0.15,0.15,0.15,0.95,0.0,0.6,ndivisions,"S");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("Ratio K/#pi");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(size*scale);
  yaxis0->SetTitleSize(size*scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->SetTickSize(0.01);
  yaxis0->Draw();

  TGaxis *xaxis0 = new TGaxis(0.15,0.15,0.95,0.15,0.0,4.0,510,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(size*scale);
  xaxis0->SetTitleSize(size*scale);
  xaxis0->SetTitleOffset(1.1);
  xaxis0->Draw();



  c1_1->cd();
  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_sysratiopos_dau);
  tmg->Add(tge_sysrationeg_dau);
  tmg->Add(tge_sysratiopos_auau);
  tmg->Add(tge_sysrationeg_auau);
  tmg->Add(tge_ratiopos_auau);
  tmg->Add(tge_rationeg_auau);
  tmg->Add(tge_ratiopos_dau);
  tmg->Add(tge_rationeg_dau);
  tmg->Draw("apz");
  //tmg->SetMaximum(0.7);
  tmg->SetMaximum(0.6);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,4.0);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("Ratio K/#pi");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitleOffset(1.5);
  tmg->GetXaxis()->SetLabelSize(0.0);
  tmg->GetXaxis()->SetTitleSize(0.0);
  tmg->GetXaxis()->SetTitleOffset(1.3);
  tmg->GetYaxis()->SetLabelSize(0.0);
  tmg->GetYaxis()->SetTitleSize(0.0);
  tmg->GetYaxis()->SetTitleOffset(1.1);

  //TLegend *leg = new TLegend(0.12,0.68,0.42,0.88);
  //TLegend *leg = new TLegend(0.18,0.73,0.48,0.93);
  TLegend *leg = new TLegend(0.40,0.23,0.70,0.43);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_ratiopos_auau,"K^{+}/#pi^{+} Au+Au 60-92%","p");
  leg->AddEntry(tge_rationeg_auau,"K^{-}/#pi^{-} Au+Au 60-92%","p");
  leg->AddEntry(tge_ratiopos_dau,"K^{+}/#pi^{+} d+Au 0-20%","p");
  leg->AddEntry(tge_rationeg_dau,"K^{-}/#pi^{-} d+Au 0-20%","p");
  leg->SetTextSize(0.05);
  leg->Draw();



  c1->Print("figures/aud_kpi.gif");
  c1->Print("figures/aud_kpi.eps");

  c1->Clear();
  delete c1;


}
