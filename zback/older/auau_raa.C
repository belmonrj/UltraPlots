TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;

float minx = 0.00;
//float maxx = 5.99;
float maxx = 6.00;



void auau_raa()
{

  doit(0,27,true);
  doit(4,16,true);
  doit(6,33,true);

  //doit4x4(tmg_pion,tmg_kaon,tmg_prot);

}


void doit4x4(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  cout<<"4x4"<<endl;

  cout<<"pion is "<<pion<<endl;
  cout<<"kaon is "<<kaon<<endl;
  cout<<"prot is "<<prot<<endl;

  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TLine *line = new TLine(0.0,0.7,6.0,0.7);

  TCanvas *c1 = new TCanvas("c1","",700,700);
  // c1->Divide(2,2);

  float padmargin = 0.12; // 0.1 is default...

  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.5,0.5,1.0); // upper left
  c1_1->Draw();
  c1_1->SetTopMargin(padmargin);
  c1_1->SetLeftMargin(padmargin);
  c1_1->SetRightMargin(0);
  c1_1->SetBottomMargin(0);
  c1_1->SetTicks(1,1);
  c1_1->cd();
  pion->Draw("apz");
  pion->GetXaxis()->SetTitleSize(0);
  pion->GetXaxis()->SetLabelSize(0);
  pion->GetYaxis()->SetTitleSize(0.05);
  pion->GetYaxis()->SetLabelSize(0.05);
  pion->GetYaxis()->SetTitleOffset(1.1);
  TLatex *tex1 = new TLatex(4.5,1.6,"#pi");
  tex1->SetTextSize(0.1);
  tex1->Draw();
  line->Draw();

  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",0.0,0.0,0.5,0.5); // lower left
  c1_2->Draw();
  c1_2->SetTopMargin(0);
  c1_2->SetLeftMargin(padmargin);
  c1_2->SetRightMargin(0);
  c1_2->SetBottomMargin(padmargin);
  c1_2->SetTicks(1,1);
  c1_2->cd();
  kaon->Draw("apz");
  kaon->GetXaxis()->SetTitleSize(0.05);
  kaon->GetXaxis()->SetLabelSize(0.05);
  kaon->GetYaxis()->SetTitleSize(0.05);
  kaon->GetYaxis()->SetLabelSize(0.05);
  kaon->GetYaxis()->SetTitleOffset(1.1);
  TLatex *tex2 = new TLatex(4.5,1.6,"K");
  tex2->SetTextSize(0.1);
  tex2->Draw();
  line->Draw();

  c1->cd();
  TPad *c1_3 = new TPad("c1_3","c1_3",0.5,0.5,1.0,1.0); // upper right
  c1_3->Draw();
  c1_3->SetTopMargin(padmargin);
  c1_3->SetLeftMargin(0);
  c1_3->SetRightMargin(padmargin);
  c1_3->SetBottomMargin(0);
  c1_3->SetTicks(1,1);
  c1_3->cd();
  prot->Draw("apz");
  prot->GetYaxis()->SetTitleSize(0);
  prot->GetYaxis()->SetLabelSize(0);
  prot->GetXaxis()->SetTitleSize(0);
  prot->GetXaxis()->SetLabelSize(0);
  TLatex *tex3 = new TLatex(4.5,1.6,"p");
  tex3->SetTextSize(0.1);
  tex3->Draw();
  line->Draw();

  c1->cd();
  TPad *c1_4 = new TPad("c1_4","c1_4",0.5,0.0,1.0,0.5); // lower right
  c1_4->Draw();
  c1_4->SetTopMargin(0);
  c1_4->SetLeftMargin(0);
  c1_4->SetRightMargin(padmargin);
  c1_4->SetBottomMargin(padmargin);
  c1_4->SetTicks(1,1);
  c1_4->cd();
  float dummy[1]={-9};
  TGraph *tmg = new TGraph(1,dummy,dummy);
  tmg->Draw("apz");
  tmg->GetXaxis()->SetTitleSize(0.05);
  tmg->GetXaxis()->SetLabelSize(0.05);
  tmg->GetYaxis()->SetTitleSize(0);
  tmg->GetYaxis()->SetLabelSize(0);
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  // tmg->SetMaximum(1.99);
  // tmg->SetMinimum(0.01);
  tmg->GetXaxis()->SetLimits(minx,maxx);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitleOffset(1.0); // 1.0 is default...
  TGraph *tge_pos = new TGraph(1,dummy,dummy);
  TGraph *tge_neg = new TGraph(1,dummy,dummy);
  tge_pos->SetMarkerColor(kRed);
  tge_neg->SetMarkerColor(kBlue);
  tge_pos->SetMarkerStyle(kFullSquare);
  tge_neg->SetMarkerStyle(kFullSquare);
  TLegend *leg4 = new TLegend(0.05,0.3,0.8,0.7);
  leg4->SetBorderSize(0);
  leg4->SetFillColor(kWhite);
  leg4->AddEntry((TObject*)0,"(Au+Au 60-92%)/(d+Au 0-20%),","");
  leg4->AddEntry((TObject*)0,"Scaled by N_{coll}","");
  leg4->AddEntry(tge_pos,"positive particles","p");
  leg4->AddEntry(tge_neg,"negative particles","p");
  leg4->AddEntry(line,"line drawn at 0.70 as visual aid","l");
  leg4->SetTextSize(0.045); // 0.04 works okay, 0.05 is a bit big, too big for padmargin>0.1
  //leg4->Draw();


  c1->Print("figures/auau_raa_all.gif");
  c1->Print("figures/auau_raa_all.eps");


}


void doit(int r7pid=2, int number=27, bool chavers=true)
{

  float sysvalue = 0.1; // original 0.05, should be 0.1 (or 0.14?) because nothing cancels across species

  TCanvas *c1 = new TCanvas();

  char filename[100];

  float pt_sys0010[1] = {5.05};
  float ept_sys0010[1] = {0.0};
  float point_sys0010[1] = {1.0};
  float epoint_sys0010[1] = {0.1};
  TGraphErrors *tge_sys0010 = new TGraphErrors(1,pt_sys0010,point_sys0010,ept_sys0010,epoint_sys0010);
  tge_sys0010->SetMarkerStyle(1);
  tge_sys0010->SetMarkerColor(kGray+2);
  tge_sys0010->SetLineWidth(19);
  tge_sys0010->SetLineColor(kGray+2);

  float pt_sys1020[1] = {5.25};
  float ept_sys1020[1] = {0.0};
  float point_sys1020[1] = {1.0};
  float epoint_sys1020[1] = {0.1};
  TGraphErrors *tge_sys1020 = new TGraphErrors(1,pt_sys1020,point_sys1020,ept_sys1020,epoint_sys1020);
  tge_sys1020->SetMarkerStyle(1);
  tge_sys1020->SetMarkerColor(kRed-7);
  tge_sys1020->SetLineWidth(19);
  tge_sys1020->SetLineColor(kRed-7);

  float pt_sys2040[1] = {5.45};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.1};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kBlue-7);
  tge_sys2040->SetLineWidth(19);
  tge_sys2040->SetLineColor(kBlue-7);

  float pt_sys4060[1] = {5.65};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.13};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGreen-7);
  tge_sys4060->SetLineWidth(19);
  tge_sys4060->SetLineColor(kGreen-7);

  float pt_sys6092[1] = {5.85};
  float ept_sys6092[1] = {0.0};
  float point_sys6092[1] = {1.0};
  float epoint_sys6092[1] = {0.22};
  TGraphErrors *tge_sys6092 = new TGraphErrors(1,pt_sys6092,point_sys6092,ept_sys6092,epoint_sys6092);
  tge_sys6092->SetMarkerStyle(1);
  tge_sys6092->SetMarkerColor(kMagenta-7);
  tge_sys6092->SetLineWidth(19);
  tge_sys6092->SetLineColor(kMagenta-7);

  // ---------- //
  // -- 0010 -- //
  // ---------- //

  float pt_auau0010[36];
  float ept_auau0010[36];
  float ratiopos_auau0010[36];
  float rationeg_auau0010[36];
  float eratiopos_auau0010[36];
  float erationeg_auau0010[36];
  float esysratiopos_auau0010[36];
  float esysrationeg_auau0010[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent0010.txt",r7pid);
  ifstream fauau0010(filename);
  for(int i=0; i<36; i++)
    {
      fauau0010>>pt_auau0010[i]>>ratiopos_auau0010[i]>>eratiopos_auau0010[i]>>rationeg_auau0010[i]>>erationeg_auau0010[i];
      ept_auau0010[i]=0;
      if(chavers)
	{
	  ratiopos_auau0010[i] += rationeg_auau0010[i];
	  ratiopos_auau0010[i] /= 2.0;
	  eratiopos_auau0010[i] = sqrt(eratiopos_auau0010[i]**2+erationeg_auau0010[i]**2)/2.0;
	}
      esysratiopos_auau0010[i] = sysvalue*ratiopos_auau0010[i];
      esysrationeg_auau0010[i] = sysvalue*rationeg_auau0010[i];
    }
  TGraphErrors *tge_ratiopos_auau0010 = new TGraphErrors(number,pt_auau0010,ratiopos_auau0010,ept_auau0010,eratiopos_auau0010);
  tge_ratiopos_auau0010->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau0010->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau0010 = new TGraphErrors(number,pt_auau0010,rationeg_auau0010,ept_auau0010,erationeg_auau0010);
  tge_rationeg_auau0010->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau0010->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau0010 = new TGraphErrors(number,pt_auau0010,ratiopos_auau0010,ept_auau0010,esysratiopos_auau0010);
  tge_sysratiopos_auau0010->SetMarkerStyle(1);
  tge_sysratiopos_auau0010->SetMarkerColor(kGray);
  tge_sysratiopos_auau0010->SetFillColor(kGray);
  tge_sysratiopos_auau0010->SetLineColor(kGray);
  tge_sysratiopos_auau0010->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau0010 = new TGraphErrors(number,pt_auau0010,rationeg_auau0010,ept_auau0010,esysrationeg_auau0010);
  tge_sysrationeg_auau0010->SetMarkerStyle(1);
  tge_sysrationeg_auau0010->SetMarkerColor(kGray);
  tge_sysrationeg_auau0010->SetFillColor(kGray);
  tge_sysrationeg_auau0010->SetLineColor(kGray);
  tge_sysrationeg_auau0010->SetLineWidth(15);

  // ---------- //
  // -- 1020 -- //
  // ---------- //
  float pt_auau1020[36];
  float ept_auau1020[36];
  float ratiopos_auau1020[36];
  float rationeg_auau1020[36];
  float eratiopos_auau1020[36];
  float erationeg_auau1020[36];
  float esysratiopos_auau1020[36];
  float esysrationeg_auau1020[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent1020.txt",r7pid);
  ifstream fauau1020(filename);
  for(int i=0; i<36; i++)
    {
      fauau1020>>pt_auau1020[i]>>ratiopos_auau1020[i]>>eratiopos_auau1020[i]>>rationeg_auau1020[i]>>erationeg_auau1020[i];
      ept_auau1020[i]=0;
      if(chavers)
	{
	  ratiopos_auau1020[i] += rationeg_auau1020[i];
	  ratiopos_auau1020[i] /= 2.0;
	  eratiopos_auau1020[i] = sqrt(eratiopos_auau1020[i]**2+erationeg_auau1020[i]**2)/2.0;
	}
      esysratiopos_auau1020[i] = sysvalue*ratiopos_auau1020[i];
      esysrationeg_auau1020[i] = sysvalue*rationeg_auau1020[i];
    }
  TGraphErrors *tge_ratiopos_auau1020 = new TGraphErrors(number,pt_auau1020,ratiopos_auau1020,ept_auau1020,eratiopos_auau1020);
  tge_ratiopos_auau1020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau1020->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau1020 = new TGraphErrors(number,pt_auau1020,rationeg_auau1020,ept_auau1020,erationeg_auau1020);
  tge_rationeg_auau1020->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau1020->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau1020 = new TGraphErrors(number,pt_auau1020,ratiopos_auau1020,ept_auau1020,esysratiopos_auau1020);
  tge_sysratiopos_auau1020->SetMarkerStyle(1);
  tge_sysratiopos_auau1020->SetMarkerColor(kGray);
  tge_sysratiopos_auau1020->SetFillColor(kGray);
  tge_sysratiopos_auau1020->SetLineColor(kGray);
  tge_sysratiopos_auau1020->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau1020 = new TGraphErrors(number,pt_auau1020,rationeg_auau1020,ept_auau1020,esysrationeg_auau1020);
  tge_sysrationeg_auau1020->SetMarkerStyle(1);
  tge_sysrationeg_auau1020->SetMarkerColor(kGray);
  tge_sysrationeg_auau1020->SetFillColor(kGray);
  tge_sysrationeg_auau1020->SetLineColor(kGray);
  tge_sysrationeg_auau1020->SetLineWidth(15);

  // ---------- //
  // -- 2040 -- //
  // ---------- //

  float pt_auau2040[36];
  float ept_auau2040[36];
  float ratiopos_auau2040[36];
  float rationeg_auau2040[36];
  float eratiopos_auau2040[36];
  float erationeg_auau2040[36];
  float esysratiopos_auau2040[36];
  float esysrationeg_auau2040[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent2040.txt",r7pid);
  ifstream fauau2040(filename);
  for(int i=0; i<36; i++)
    {
      fauau2040>>pt_auau2040[i]>>ratiopos_auau2040[i]>>eratiopos_auau2040[i]>>rationeg_auau2040[i]>>erationeg_auau2040[i];
      ept_auau2040[i]=0;
      if(chavers)
	{
	  ratiopos_auau2040[i] += rationeg_auau2040[i];
	  ratiopos_auau2040[i] /= 2.0;
	  eratiopos_auau2040[i] = sqrt(eratiopos_auau2040[i]**2+erationeg_auau2040[i]**2)/2.0;
	}
      esysratiopos_auau2040[i] = sysvalue*ratiopos_auau2040[i];
      esysrationeg_auau2040[i] = sysvalue*rationeg_auau2040[i];
    }
  TGraphErrors *tge_ratiopos_auau2040 = new TGraphErrors(number,pt_auau2040,ratiopos_auau2040,ept_auau2040,eratiopos_auau2040);
  tge_ratiopos_auau2040->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau2040->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau2040 = new TGraphErrors(number,pt_auau2040,rationeg_auau2040,ept_auau2040,erationeg_auau2040);
  tge_rationeg_auau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau2040->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau2040 = new TGraphErrors(number,pt_auau2040,ratiopos_auau2040,ept_auau2040,esysratiopos_auau2040);
  tge_sysratiopos_auau2040->SetMarkerStyle(1);
  tge_sysratiopos_auau2040->SetMarkerColor(kGray);
  tge_sysratiopos_auau2040->SetFillColor(kGray);
  tge_sysratiopos_auau2040->SetLineColor(kGray);
  tge_sysratiopos_auau2040->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau2040 = new TGraphErrors(number,pt_auau2040,rationeg_auau2040,ept_auau2040,esysrationeg_auau2040);
  tge_sysrationeg_auau2040->SetMarkerStyle(1);
  tge_sysrationeg_auau2040->SetMarkerColor(kGray);
  tge_sysrationeg_auau2040->SetFillColor(kGray);
  tge_sysrationeg_auau2040->SetLineColor(kGray);
  tge_sysrationeg_auau2040->SetLineWidth(15);

  // ---------- //
  // -- 4060 -- //
  // ---------- //

  float pt_auau4060[36];
  float ept_auau4060[36];
  float ratiopos_auau4060[36];
  float rationeg_auau4060[36];
  float eratiopos_auau4060[36];
  float erationeg_auau4060[36];
  float esysratiopos_auau4060[36];
  float esysrationeg_auau4060[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent4060.txt",r7pid);
  ifstream fauau4060(filename);
  for(int i=0; i<36; i++)
    {
      fauau4060>>pt_auau4060[i]>>ratiopos_auau4060[i]>>eratiopos_auau4060[i]>>rationeg_auau4060[i]>>erationeg_auau4060[i];
      ept_auau4060[i]=0;
      if(chavers)
	{
	  ratiopos_auau4060[i] += rationeg_auau4060[i];
	  ratiopos_auau4060[i] /= 2.0;
	  eratiopos_auau4060[i] = sqrt(eratiopos_auau4060[i]**2+erationeg_auau4060[i]**2)/2.0;
	}
      esysratiopos_auau4060[i] = sysvalue*ratiopos_auau4060[i];
      esysrationeg_auau4060[i] = sysvalue*rationeg_auau4060[i];
    }
  TGraphErrors *tge_ratiopos_auau4060 = new TGraphErrors(number,pt_auau4060,ratiopos_auau4060,ept_auau4060,eratiopos_auau4060);
  tge_ratiopos_auau4060->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau4060->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau4060 = new TGraphErrors(number,pt_auau4060,rationeg_auau4060,ept_auau4060,erationeg_auau4060);
  tge_rationeg_auau4060->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau4060->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau4060 = new TGraphErrors(number,pt_auau4060,ratiopos_auau4060,ept_auau4060,esysratiopos_auau4060);
  tge_sysratiopos_auau4060->SetMarkerStyle(1);
  tge_sysratiopos_auau4060->SetMarkerColor(kGray);
  tge_sysratiopos_auau4060->SetFillColor(kGray);
  tge_sysratiopos_auau4060->SetLineColor(kGray);
  tge_sysratiopos_auau4060->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau4060 = new TGraphErrors(number,pt_auau4060,rationeg_auau4060,ept_auau4060,esysrationeg_auau4060);
  tge_sysrationeg_auau4060->SetMarkerStyle(1);
  tge_sysrationeg_auau4060->SetMarkerColor(kGray);
  tge_sysrationeg_auau4060->SetFillColor(kGray);
  tge_sysrationeg_auau4060->SetLineColor(kGray);
  tge_sysrationeg_auau4060->SetLineWidth(15);

  // ---------- //
  // -- 6092 -- //
  // ---------- //

  float pt_auau6092[36];
  float ept_auau6092[36];
  float ratiopos_auau6092[36];
  float rationeg_auau6092[36];
  float eratiopos_auau6092[36];
  float erationeg_auau6092[36];
  float esysratiopos_auau6092[36];
  float esysrationeg_auau6092[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent6092.txt",r7pid);
  ifstream fauau6092(filename);
  for(int i=0; i<36; i++)
    {
      fauau6092>>pt_auau6092[i]>>ratiopos_auau6092[i]>>eratiopos_auau6092[i]>>rationeg_auau6092[i]>>erationeg_auau6092[i];
      ept_auau6092[i]=0;
      if(chavers)
	{
	  ratiopos_auau6092[i] += rationeg_auau6092[i];
	  ratiopos_auau6092[i] /= 2.0;
	  eratiopos_auau6092[i] = sqrt(eratiopos_auau6092[i]**2+erationeg_auau6092[i]**2)/2.0;
	}
      esysratiopos_auau6092[i] = sysvalue*ratiopos_auau6092[i];
      esysrationeg_auau6092[i] = sysvalue*rationeg_auau6092[i];
    }
  TGraphErrors *tge_ratiopos_auau6092 = new TGraphErrors(number,pt_auau6092,ratiopos_auau6092,ept_auau6092,eratiopos_auau6092);
  tge_ratiopos_auau6092->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau6092->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau6092 = new TGraphErrors(number,pt_auau6092,rationeg_auau6092,ept_auau6092,erationeg_auau6092);
  tge_rationeg_auau6092->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau6092->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau6092 = new TGraphErrors(number,pt_auau6092,ratiopos_auau6092,ept_auau6092,esysratiopos_auau6092);
  tge_sysratiopos_auau6092->SetMarkerStyle(1);
  tge_sysratiopos_auau6092->SetMarkerColor(kGray);
  tge_sysratiopos_auau6092->SetFillColor(kGray);
  tge_sysratiopos_auau6092->SetLineColor(kGray);
  tge_sysratiopos_auau6092->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau6092 = new TGraphErrors(number,pt_auau6092,rationeg_auau6092,ept_auau6092,esysrationeg_auau6092);
  tge_sysrationeg_auau6092->SetMarkerStyle(1);
  tge_sysrationeg_auau6092->SetMarkerColor(kGray);
  tge_sysrationeg_auau6092->SetFillColor(kGray);
  tge_sysrationeg_auau6092->SetLineColor(kGray);
  tge_sysrationeg_auau6092->SetLineWidth(15);






  tge_ratiopos_auau0010->SetMarkerColor(kBlack);
  tge_ratiopos_auau1020->SetMarkerColor(kBlack);
  tge_ratiopos_auau2040->SetMarkerColor(kBlack);
  tge_ratiopos_auau4060->SetMarkerColor(kBlack);
  tge_ratiopos_auau6092->SetMarkerColor(kBlack);

  tge_ratiopos_auau0010->SetMarkerColor(kBlack);
  tge_ratiopos_auau1020->SetMarkerColor(kRed);
  tge_ratiopos_auau2040->SetMarkerColor(kBlue);
  tge_ratiopos_auau4060->SetMarkerColor(kGreen+2);
  tge_ratiopos_auau6092->SetMarkerColor(kMagenta+2);

  tge_ratiopos_auau0010->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau1020->SetMarkerStyle(kFullSquare);
  tge_ratiopos_auau2040->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_auau4060->SetMarkerStyle(kFullTriangleDown);
  tge_ratiopos_auau6092->SetMarkerStyle(kFullDiamond);



  c1->cd(1);
  TMultiGraph *tmgpos1 = new TMultiGraph();
  tmgpos1->Add(tge_sys0010);
  tmgpos1->Add(tge_sys1020);
  tmgpos1->Add(tge_sys2040);
  tmgpos1->Add(tge_sys4060);
  tmgpos1->Add(tge_sys6092);
  tmgpos1->Add(tge_sysratiopos_auau0010);
  tmgpos1->Add(tge_sysratiopos_auau1020);
  tmgpos1->Add(tge_sysratiopos_auau2040);
  tmgpos1->Add(tge_sysratiopos_auau4060);
  tmgpos1->Add(tge_sysratiopos_auau6092);
  tmgpos1->Add(tge_ratiopos_auau0010);
  tmgpos1->Add(tge_ratiopos_auau1020);
  tmgpos1->Add(tge_ratiopos_auau2040);
  tmgpos1->Add(tge_ratiopos_auau4060);
  tmgpos1->Add(tge_ratiopos_auau6092);
  tmgpos1->Draw("apz");
  TLine *line = new TLine(0.0,1.0,6.0,1.0);
  line->Draw();
  tmgpos1->SetMaximum(2.0);
  tmgpos1->SetMinimum(0.0);
  tmgpos1->GetXaxis()->SetLimits(0.0,6.0);
  tmgpos1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos1->GetXaxis()->CenterTitle();
  //tmgpos1->GetYaxis()->SetTitle("Nuclear Modification Factor");
  tmgpos1->GetYaxis()->SetTitle("R_{AA}");
  tmgpos1->GetYaxis()->CenterTitle();
  tmgpos1->GetYaxis()->SetTitleOffset(1.5);

  TLegend *legpos1 = new TLegend(0.12,0.68,0.38,0.88);
  legpos1->SetBorderSize(0);
  legpos1->SetFillColor(kWhite);
  if(r7pid<=3&&!chavers)
    {
      legpos1->AddEntry(tge_ratiopos_auau0010,"#pi^{+} R_{AA} 0-10%","p");
      legpos1->AddEntry(tge_ratiopos_auau1020,"#pi^{+} R_{AA} 10-20%","p");
      legpos1->AddEntry(tge_ratiopos_auau2040,"#pi^{+} R_{AA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_auau4060,"#pi^{+} R_{AA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_auau6092,"#pi^{+} R_{AA} 60-92%","p");
    }
  if(r7pid<=3&&chavers)
    {
      legpos1->AddEntry(tge_ratiopos_auau0010,"(#pi^{+}+#pi^{-})/2 R_{AA} 0-10%","p");
      legpos1->AddEntry(tge_ratiopos_auau1020,"(#pi^{+}+#pi^{-})/2 R_{AA} 10-20%","p");
      legpos1->AddEntry(tge_ratiopos_auau2040,"(#pi^{+}+#pi^{-})/2 R_{AA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_auau4060,"(#pi^{+}+#pi^{-})/2 R_{AA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_auau6092,"(#pi^{+}+#pi^{-})/2 R_{AA} 60-92%","p");
    }
  if((r7pid==4||r7pid==5)&&!chavers)
    {
      legpos1->AddEntry(tge_ratiopos_auau0010,"K^{+} R_{AA} 0-10%","p");
      legpos1->AddEntry(tge_ratiopos_auau1020,"K^{+} R_{AA} 10-20%","p");
      legpos1->AddEntry(tge_ratiopos_auau2040,"K^{+} R_{AA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_auau4060,"K^{+} R_{AA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_auau6092,"K^{+} R_{AA} 60-92%","p");
    }
  if((r7pid==4||r7pid==5)&&chavers)
    {
      legpos1->AddEntry(tge_ratiopos_auau0010,"(K^{+}+K^{-})/2 R_{AA} 0-10%","p");
      legpos1->AddEntry(tge_ratiopos_auau1020,"(K^{+}+K^{-})/2 R_{AA} 10-20%","p");
      legpos1->AddEntry(tge_ratiopos_auau2040,"(K^{+}+K^{-})/2 R_{AA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_auau4060,"(K^{+}+K^{-})/2 R_{AA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_auau6092,"(K^{+}+K^{-})/2 R_{AA} 60-92%","p");
    }
  if(r7pid>=6&&!chavers)
    {
      legpos1->AddEntry(tge_ratiopos_auau0010,"p R_{AA} 0-10%","p");
      legpos1->AddEntry(tge_ratiopos_auau1020,"p R_{AA} 10-20%","p");
      legpos1->AddEntry(tge_ratiopos_auau2040,"p R_{AA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_auau4060,"p R_{AA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_auau6092,"p R_{AA} 60-92%","p");
    }
  if(r7pid>=6&&chavers)
    {
      legpos1->AddEntry(tge_ratiopos_auau0010,"(p+#bar{p})/2 R_{AA} 0-10%","p");
      legpos1->AddEntry(tge_ratiopos_auau1020,"(p+#bar{p})/2 R_{AA} 10-20%","p");
      legpos1->AddEntry(tge_ratiopos_auau2040,"(p+#bar{p})/2 R_{AA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_auau4060,"(p+#bar{p})/2 R_{AA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_auau6092,"(p+#bar{p})/2 R_{AA} 60-92%","p");
    }
  legpos1->SetTextSize(0.05);
  legpos1->Draw();





  /*
  c1->cd(2);
  TMultiGraph *tmgneg1 = new TMultiGraph();
  tmgneg1->Add(tge_rationeg_auau0010);
  tmgneg1->Add(tge_rationeg_auau1020);
  tmgneg1->Add(tge_rationeg_auau2040);
  tmgneg1->Add(tge_rationeg_auau4060);
  tmgneg1->Add(tge_rationeg_auau6092);
  tmgneg1->Draw("apz");
  tmgneg1->SetMaximum(2.0);
  tmgneg1->SetMinimum(0.0);
  tmgneg1->GetXaxis()->SetLimits(0.0,6.0);
  tmgneg1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgneg1->GetXaxis()->CenterTitle();
  tmgneg1->GetYaxis()->SetTitle("Ratio p/#pi");
  tmgneg1->GetYaxis()->CenterTitle();

  TLegend *legneg1 = new TLegend(0.12,0.68,0.38,0.88);
  legneg1->SetBorderSize(0);
  legneg1->SetFillColor(kWhite);
  legneg1->AddEntry(tge_rationeg_auau0010,"#pi^{-} R_{AA} 0-10%","p");
  legneg1->AddEntry(tge_rationeg_auau1020,"#pi^{-} R_{AA} 10-20%","p");
  legneg1->AddEntry(tge_rationeg_auau2040,"#pi^{-} R_{AA} 20-40%","p");
  legneg1->AddEntry(tge_rationeg_auau4060,"#pi^{-} R_{AA} 40-60%","p");
  legneg1->AddEntry(tge_rationeg_auau6092,"#pi^{-} R_{AA} 60-92%","p");
  legneg1->Draw();
  */



  char particle[7];
  if(r7pid<=3) sprintf(particle,"pion");
  else if(r7pid>=6) sprintf(particle,"proton");
  else sprintf(particle,"kaon");
  char figname[100];
  sprintf(figname,"figures/auau_raa_%s.gif",particle);
  c1->Print(figname);
  sprintf(figname,"figures/auau_raa_%s.eps",particle);
  c1->Print(figname);


  if(r7pid<=3)      tmg_pion = (TMultiGraph *)tmgpos1->Clone();
  else if(r7pid>=6) tmg_prot = (TMultiGraph *)tmgpos1->Clone();
  else              tmg_kaon = (TMultiGraph *)tmgpos1->Clone();





}
