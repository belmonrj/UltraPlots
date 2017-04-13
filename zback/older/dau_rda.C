void dau_rda()
{

  doit(1,27,true);
  doit(3,16,true);
  doit(5,33,true);

}



void doit(int r8pid=2, int number=27, bool chavers=true)
{

  float sysvalue = 0.05;

  TCanvas *c1 = new TCanvas();

  char filename[100];

  float pt_sys0088[1] = {5.45};
  float ept_sys0088[1] = {0.0};
  float point_sys0088[1] = {1.0};
  float epoint_sys0088[1] = {0.053};
  TGraphErrors *tge_sys0088 = new TGraphErrors(1,pt_sys0088,point_sys0088,ept_sys0088,epoint_sys0088);
  tge_sys0088->SetMarkerStyle(1);
  tge_sys0088->SetMarkerColor(kBlue-7);
  tge_sys0088->SetLineWidth(19);
  tge_sys0088->SetLineColor(kBlue-7);

  float pt_sys0020[1] = {5.05};
  float ept_sys0020[1] = {0.0};
  float point_sys0020[1] = {1.0};
  float epoint_sys0020[1] = {0.066};
  TGraphErrors *tge_sys0020 = new TGraphErrors(1,pt_sys0020,point_sys0020,ept_sys0020,epoint_sys0020);
  tge_sys0020->SetMarkerStyle(1);
  tge_sys0020->SetMarkerColor(kGray+2);
  tge_sys0020->SetLineWidth(19);
  tge_sys0020->SetLineColor(kGray+2);

  float pt_sys2040[1] = {5.25};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.068};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kRed-7);
  tge_sys2040->SetLineWidth(19);
  tge_sys2040->SetLineColor(kRed-7);

  float pt_sys4060[1] = {5.65};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.061};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGreen-7);
  tge_sys4060->SetLineWidth(19);
  tge_sys4060->SetLineColor(kGreen-7);

  float pt_sys6088[1] = {5.85};
  float ept_sys6088[1] = {0.0};
  float point_sys6088[1] = {1.0};
  float epoint_sys6088[1] = {0.063};
  TGraphErrors *tge_sys6088 = new TGraphErrors(1,pt_sys6088,point_sys6088,ept_sys6088,epoint_sys6088);
  tge_sys6088->SetMarkerStyle(1);
  tge_sys6088->SetMarkerColor(kMagenta-7);
  tge_sys6088->SetLineWidth(19);
  tge_sys6088->SetLineColor(kMagenta-7);

  // ---------- //
  // -- 0088 -- //
  // ---------- //

  float pt_dau0088[36];
  float ept_dau0088[36];
  float ratiopos_dau0088[36];
  float rationeg_dau0088[36];
  float eratiopos_dau0088[36];
  float erationeg_dau0088[36];
  float esysratiopos_dau0088[36];
  float esysrationeg_dau0088[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent0088.txt",r8pid);
  ifstream fdau0088(filename);
  for(int i=0; i<number; i++)
    {
      fdau0088>>pt_dau0088[i]>>ratiopos_dau0088[i]>>eratiopos_dau0088[i]>>rationeg_dau0088[i]>>erationeg_dau0088[i];
      ept_dau0088[i]=0;
      if(chavers)
	{
	  ratiopos_dau0088[i] += rationeg_dau0088[i];
	  ratiopos_dau0088[i] /= 2.0;
	  eratiopos_dau0088[i] = sqrt(eratiopos_dau0088[i]**2+erationeg_dau0088[i]**2)/2.0;
	}
      esysratiopos_dau0088[i] = sysvalue*ratiopos_dau0088[i];
      esysrationeg_dau0088[i] = sysvalue*rationeg_dau0088[i];
    }
  TGraphErrors *tge_ratiopos_dau0088 = new TGraphErrors(number,pt_dau0088,ratiopos_dau0088,ept_dau0088,eratiopos_dau0088);
  tge_ratiopos_dau0088->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau0088->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau0088 = new TGraphErrors(number,pt_dau0088,rationeg_dau0088,ept_dau0088,erationeg_dau0088);
  tge_rationeg_dau0088->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0088->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau0088 = new TGraphErrors(number,pt_dau0088,ratiopos_dau0088,ept_dau0088,esysratiopos_dau0088);
  tge_sysratiopos_dau0088->SetMarkerStyle(1);
  tge_sysratiopos_dau0088->SetMarkerColor(kGray);
  tge_sysratiopos_dau0088->SetFillColor(kGray);
  tge_sysratiopos_dau0088->SetLineColor(kGray);
  tge_sysratiopos_dau0088->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau0088 = new TGraphErrors(number,pt_dau0088,rationeg_dau0088,ept_dau0088,esysrationeg_dau0088);
  tge_sysrationeg_dau0088->SetMarkerStyle(1);
  tge_sysrationeg_dau0088->SetMarkerColor(kGray);
  tge_sysrationeg_dau0088->SetFillColor(kGray);
  tge_sysrationeg_dau0088->SetLineColor(kGray);
  tge_sysrationeg_dau0088->SetLineWidth(15);

  // ---------- //
  // -- 0020 -- //
  // ---------- //
  float pt_dau0020[36];
  float ept_dau0020[36];
  float ratiopos_dau0020[36];
  float rationeg_dau0020[36];
  float eratiopos_dau0020[36];
  float erationeg_dau0020[36];
  float esysratiopos_dau0020[36];
  float esysrationeg_dau0020[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent0020.txt",r8pid);
  ifstream fdau0020(filename);
  for(int i=0; i<number; i++)
    {
      fdau0020>>pt_dau0020[i]>>ratiopos_dau0020[i]>>eratiopos_dau0020[i]>>rationeg_dau0020[i]>>erationeg_dau0020[i];
      ept_dau0020[i]=0;
      if(chavers)
	{
	  ratiopos_dau0020[i] += rationeg_dau0020[i];
	  ratiopos_dau0020[i] /= 2.0;
	  eratiopos_dau0020[i] = sqrt(eratiopos_dau0020[i]**2+erationeg_dau0020[i]**2)/2.0;
	}
      esysratiopos_dau0020[i] = sysvalue*ratiopos_dau0020[i];
      esysrationeg_dau0020[i] = sysvalue*rationeg_dau0020[i];
    }
  TGraphErrors *tge_ratiopos_dau0020 = new TGraphErrors(number,pt_dau0020,ratiopos_dau0020,ept_dau0020,eratiopos_dau0020);
  tge_ratiopos_dau0020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau0020->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau0020 = new TGraphErrors(number,pt_dau0020,rationeg_dau0020,ept_dau0020,erationeg_dau0020);
  tge_rationeg_dau0020->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0020->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau0020 = new TGraphErrors(number,pt_dau0020,ratiopos_dau0020,ept_dau0020,esysratiopos_dau0020);
  tge_sysratiopos_dau0020->SetMarkerStyle(1);
  tge_sysratiopos_dau0020->SetMarkerColor(kGray);
  tge_sysratiopos_dau0020->SetFillColor(kGray);
  tge_sysratiopos_dau0020->SetLineColor(kGray);
  tge_sysratiopos_dau0020->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau0020 = new TGraphErrors(number,pt_dau0020,rationeg_dau0020,ept_dau0020,esysrationeg_dau0020);
  tge_sysrationeg_dau0020->SetMarkerStyle(1);
  tge_sysrationeg_dau0020->SetMarkerColor(kGray);
  tge_sysrationeg_dau0020->SetFillColor(kGray);
  tge_sysrationeg_dau0020->SetLineColor(kGray);
  tge_sysrationeg_dau0020->SetLineWidth(15);

  // ---------- //
  // -- 2040 -- //
  // ---------- //

  float pt_dau2040[36];
  float ept_dau2040[36];
  float ratiopos_dau2040[36];
  float rationeg_dau2040[36];
  float eratiopos_dau2040[36];
  float erationeg_dau2040[36];
  float esysratiopos_dau2040[36];
  float esysrationeg_dau2040[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent2040.txt",r8pid);
  ifstream fdau2040(filename);
  for(int i=0; i<number; i++)
    {
      fdau2040>>pt_dau2040[i]>>ratiopos_dau2040[i]>>eratiopos_dau2040[i]>>rationeg_dau2040[i]>>erationeg_dau2040[i];
      ept_dau2040[i]=0;
      if(chavers)
	{
	  ratiopos_dau2040[i] += rationeg_dau2040[i];
	  ratiopos_dau2040[i] /= 2.0;
	  eratiopos_dau2040[i] = sqrt(eratiopos_dau2040[i]**2+erationeg_dau2040[i]**2)/2.0;
	}
      esysratiopos_dau2040[i] = sysvalue*ratiopos_dau2040[i];
      esysrationeg_dau2040[i] = sysvalue*rationeg_dau2040[i];
    }
  TGraphErrors *tge_ratiopos_dau2040 = new TGraphErrors(number,pt_dau2040,ratiopos_dau2040,ept_dau2040,eratiopos_dau2040);
  tge_ratiopos_dau2040->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau2040->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau2040 = new TGraphErrors(number,pt_dau2040,rationeg_dau2040,ept_dau2040,erationeg_dau2040);
  tge_rationeg_dau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau2040->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau2040 = new TGraphErrors(number,pt_dau2040,ratiopos_dau2040,ept_dau2040,esysratiopos_dau2040);
  tge_sysratiopos_dau2040->SetMarkerStyle(1);
  tge_sysratiopos_dau2040->SetMarkerColor(kGray);
  tge_sysratiopos_dau2040->SetFillColor(kGray);
  tge_sysratiopos_dau2040->SetLineColor(kGray);
  tge_sysratiopos_dau2040->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau2040 = new TGraphErrors(number,pt_dau2040,rationeg_dau2040,ept_dau2040,esysrationeg_dau2040);
  tge_sysrationeg_dau2040->SetMarkerStyle(1);
  tge_sysrationeg_dau2040->SetMarkerColor(kGray);
  tge_sysrationeg_dau2040->SetFillColor(kGray);
  tge_sysrationeg_dau2040->SetLineColor(kGray);
  tge_sysrationeg_dau2040->SetLineWidth(15);

  // ---------- //
  // -- 4060 -- //
  // ---------- //

  float pt_dau4060[36];
  float ept_dau4060[36];
  float ratiopos_dau4060[36];
  float rationeg_dau4060[36];
  float eratiopos_dau4060[36];
  float erationeg_dau4060[36];
  float esysratiopos_dau4060[36];
  float esysrationeg_dau4060[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent4060.txt",r8pid);
  ifstream fdau4060(filename);
  for(int i=0; i<number; i++)
    {
      fdau4060>>pt_dau4060[i]>>ratiopos_dau4060[i]>>eratiopos_dau4060[i]>>rationeg_dau4060[i]>>erationeg_dau4060[i];
      ept_dau4060[i]=0;
      if(chavers)
	{
	  ratiopos_dau4060[i] += rationeg_dau4060[i];
	  ratiopos_dau4060[i] /= 2.0;
	  eratiopos_dau4060[i] = sqrt(eratiopos_dau4060[i]**2+erationeg_dau4060[i]**2)/2.0;
	}
      esysratiopos_dau4060[i] = sysvalue*ratiopos_dau4060[i];
      esysrationeg_dau4060[i] = sysvalue*rationeg_dau4060[i];
    }
  TGraphErrors *tge_ratiopos_dau4060 = new TGraphErrors(number,pt_dau4060,ratiopos_dau4060,ept_dau4060,eratiopos_dau4060);
  tge_ratiopos_dau4060->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau4060->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau4060 = new TGraphErrors(number,pt_dau4060,rationeg_dau4060,ept_dau4060,erationeg_dau4060);
  tge_rationeg_dau4060->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau4060->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau4060 = new TGraphErrors(number,pt_dau4060,ratiopos_dau4060,ept_dau4060,esysratiopos_dau4060);
  tge_sysratiopos_dau4060->SetMarkerStyle(1);
  tge_sysratiopos_dau4060->SetMarkerColor(kGray);
  tge_sysratiopos_dau4060->SetFillColor(kGray);
  tge_sysratiopos_dau4060->SetLineColor(kGray);
  tge_sysratiopos_dau4060->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau4060 = new TGraphErrors(number,pt_dau4060,rationeg_dau4060,ept_dau4060,esysrationeg_dau4060);
  tge_sysrationeg_dau4060->SetMarkerStyle(1);
  tge_sysrationeg_dau4060->SetMarkerColor(kGray);
  tge_sysrationeg_dau4060->SetFillColor(kGray);
  tge_sysrationeg_dau4060->SetLineColor(kGray);
  tge_sysrationeg_dau4060->SetLineWidth(15);

  // ---------- //
  // -- 6088 -- //
  // ---------- //

  float pt_dau6088[36];
  float ept_dau6088[36];
  float ratiopos_dau6088[36];
  float rationeg_dau6088[36];
  float eratiopos_dau6088[36];
  float erationeg_dau6088[36];
  float esysratiopos_dau6088[36];
  float esysrationeg_dau6088[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent6088.txt",r8pid);
  ifstream fdau6088(filename);
  for(int i=0; i<number; i++)
    {
      fdau6088>>pt_dau6088[i]>>ratiopos_dau6088[i]>>eratiopos_dau6088[i]>>rationeg_dau6088[i]>>erationeg_dau6088[i];
      ept_dau6088[i]=0;
      if(chavers)
	{
	  ratiopos_dau6088[i] += rationeg_dau6088[i];
	  ratiopos_dau6088[i] /= 2.0;
	  eratiopos_dau6088[i] = sqrt(eratiopos_dau6088[i]**2+erationeg_dau6088[i]**2)/2.0;
	}
      esysratiopos_dau6088[i] = sysvalue*ratiopos_dau6088[i];
      esysrationeg_dau6088[i] = sysvalue*rationeg_dau6088[i];
    }
  TGraphErrors *tge_ratiopos_dau6088 = new TGraphErrors(number,pt_dau6088,ratiopos_dau6088,ept_dau6088,eratiopos_dau6088);
  tge_ratiopos_dau6088->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau6088->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau6088 = new TGraphErrors(number,pt_dau6088,rationeg_dau6088,ept_dau6088,erationeg_dau6088);
  tge_rationeg_dau6088->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau6088->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau6088 = new TGraphErrors(number,pt_dau6088,ratiopos_dau6088,ept_dau6088,esysratiopos_dau6088);
  tge_sysratiopos_dau6088->SetMarkerStyle(1);
  tge_sysratiopos_dau6088->SetMarkerColor(kGray);
  tge_sysratiopos_dau6088->SetFillColor(kGray);
  tge_sysratiopos_dau6088->SetLineColor(kGray);
  tge_sysratiopos_dau6088->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau6088 = new TGraphErrors(number,pt_dau6088,rationeg_dau6088,ept_dau6088,esysrationeg_dau6088);
  tge_sysrationeg_dau6088->SetMarkerStyle(1);
  tge_sysrationeg_dau6088->SetMarkerColor(kGray);
  tge_sysrationeg_dau6088->SetFillColor(kGray);
  tge_sysrationeg_dau6088->SetLineColor(kGray);
  tge_sysrationeg_dau6088->SetLineWidth(15);






  // tge_ratiopos_dau0088->SetMarkerColor(kBlack);
  // tge_ratiopos_dau0020->SetMarkerColor(kBlack);
  // tge_ratiopos_dau2040->SetMarkerColor(kBlack);
  // tge_ratiopos_dau4060->SetMarkerColor(kBlack);
  // tge_ratiopos_dau6088->SetMarkerColor(kBlack);

  // tge_ratiopos_dau0088->SetMarkerColor(kBlack);
  // tge_ratiopos_dau0020->SetMarkerColor(kRed);
  // tge_ratiopos_dau2040->SetMarkerColor(kBlue);
  // tge_ratiopos_dau4060->SetMarkerColor(kGreen+2);
  // tge_ratiopos_dau6088->SetMarkerColor(kMagenta+2);

  // tge_ratiopos_dau0088->SetMarkerStyle(kFullCircle);
  // tge_ratiopos_dau0020->SetMarkerStyle(kFullSquare);
  // tge_ratiopos_dau2040->SetMarkerStyle(kFullTriangleUp);
  // tge_ratiopos_dau4060->SetMarkerStyle(kFullTriangleDown);
  // tge_ratiopos_dau6088->SetMarkerStyle(kFullDiamond);



  tge_ratiopos_dau0020->SetMarkerColor(kBlack);
  tge_ratiopos_dau2040->SetMarkerColor(kRed);
  tge_ratiopos_dau0088->SetMarkerColor(kBlue);
  tge_ratiopos_dau4060->SetMarkerColor(kGreen+2);
  tge_ratiopos_dau6088->SetMarkerColor(kMagenta+2);

  tge_ratiopos_dau0020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau2040->SetMarkerStyle(kFullSquare);
  tge_ratiopos_dau0088->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_dau4060->SetMarkerStyle(kFullTriangleDown);
  tge_ratiopos_dau6088->SetMarkerStyle(kFullDiamond);



  c1->cd(1);
  TMultiGraph *tmgpos1 = new TMultiGraph();
  tmgpos1->Add(tge_sys0020);
  tmgpos1->Add(tge_sys2040);
  tmgpos1->Add(tge_sys0088);
  tmgpos1->Add(tge_sys4060);
  tmgpos1->Add(tge_sys6088);
  tmgpos1->Add(tge_sysratiopos_dau0020);
  tmgpos1->Add(tge_sysratiopos_dau2040);
  tmgpos1->Add(tge_sysratiopos_dau0088);
  tmgpos1->Add(tge_sysratiopos_dau4060);
  tmgpos1->Add(tge_sysratiopos_dau6088);
  tmgpos1->Add(tge_ratiopos_dau0020);
  tmgpos1->Add(tge_ratiopos_dau2040);
  tmgpos1->Add(tge_ratiopos_dau0088);
  tmgpos1->Add(tge_ratiopos_dau4060);
  tmgpos1->Add(tge_ratiopos_dau6088);
  tmgpos1->Draw("apz");
  TLine *line = new TLine(0.0,1.0,6.0,1.0);
  line->Draw();
  tmgpos1->SetMaximum(3.0);
  tmgpos1->SetMinimum(0.0);
  tmgpos1->GetXaxis()->SetLimits(0.0,6.0);
  tmgpos1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos1->GetXaxis()->CenterTitle();
  //tmgpos1->GetYaxis()->SetTitle("Nuclear Modification Factor");
  tmgpos1->GetYaxis()->SetTitle("R_{dA}");
  tmgpos1->GetYaxis()->CenterTitle();
  tmgpos1->GetYaxis()->SetTitleOffset(1.5);

  TLegend *legpos1 = new TLegend(0.12,0.68,0.38,0.88);
  legpos1->SetBorderSize(0);
  legpos1->SetFillColor(kWhite);
  if(r8pid<=1&&!chavers)
    {
      legpos1->AddEntry(tge_ratiopos_dau0020,"#pi^{+} R_{dA} 0-20%","p");
      legpos1->AddEntry(tge_ratiopos_dau2040,"#pi^{+} R_{dA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_dau0088,"#pi^{+} R_{dA} 0-88%","p");
      legpos1->AddEntry(tge_ratiopos_dau4060,"#pi^{+} R_{dA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_dau6088,"#pi^{+} R_{dA} 60-88%","p");
    }
  if(r8pid<=1&&chavers)
    {
      legpos1->AddEntry(tge_ratiopos_dau0020,"(#pi^{+}+#pi^{-})/2 R_{dA} 0-20%","p");
      legpos1->AddEntry(tge_ratiopos_dau2040,"(#pi^{+}+#pi^{-})/2 R_{dA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_dau0088,"(#pi^{+}+#pi^{-})/2 R_{dA} 0-88%","p");
      legpos1->AddEntry(tge_ratiopos_dau4060,"(#pi^{+}+#pi^{-})/2 R_{dA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_dau6088,"(#pi^{+}+#pi^{-})/2 R_{dA} 60-88%","p");
    }
  if((r8pid==2||r8pid==3)&&!chavers)
    {
      legpos1->AddEntry(tge_ratiopos_dau0020,"K^{+} R_{dA} 0-20%","p");
      legpos1->AddEntry(tge_ratiopos_dau2040,"K^{+} R_{dA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_dau0088,"K^{+} R_{dA} 0-88%","p");
      legpos1->AddEntry(tge_ratiopos_dau4060,"K^{+} R_{dA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_dau6088,"K^{+} R_{dA} 60-88%","p");
    }
  if((r8pid==2||r8pid==3)&&chavers)
    {
      legpos1->AddEntry(tge_ratiopos_dau0020,"(K^{+}+K^{-})/2 R_{dA} 0-20%","p");
      legpos1->AddEntry(tge_ratiopos_dau2040,"(K^{+}+K^{-})/2 R_{dA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_dau0088,"(K^{+}+K^{-})/2 R_{dA} 0-88%","p");
      legpos1->AddEntry(tge_ratiopos_dau4060,"(K^{+}+K^{-})/2 R_{dA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_dau6088,"(K^{+}+K^{-})/2 R_{dA} 60-88%","p");
    }
  if(r8pid>=4&&!chavers)
    {
      legpos1->AddEntry(tge_ratiopos_dau0020,"p R_{dA} 0-20%","p");
      legpos1->AddEntry(tge_ratiopos_dau2040,"p R_{dA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_dau0088,"p R_{dA} 0-88%","p");
      legpos1->AddEntry(tge_ratiopos_dau4060,"p R_{dA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_dau6088,"p R_{dA} 60-88%","p");
    }
  if(r8pid>=4&&chavers)
    {
      legpos1->AddEntry(tge_ratiopos_dau0020,"(p+#bar{p})/2 R_{dA} 0-20%","p");
      legpos1->AddEntry(tge_ratiopos_dau2040,"(p+#bar{p})/2 R_{dA} 20-40%","p");
      legpos1->AddEntry(tge_ratiopos_dau0088,"(p+#bar{p})/2 R_{dA} 0-88%","p");
      legpos1->AddEntry(tge_ratiopos_dau4060,"(p+#bar{p})/2 R_{dA} 40-60%","p");
      legpos1->AddEntry(tge_ratiopos_dau6088,"(p+#bar{p})/2 R_{dA} 60-88%","p");
    }
  legpos1->SetTextSize(0.05);
  legpos1->Draw();





  /*
  c1->cd(2);
  TMultiGraph *tmgneg1 = new TMultiGraph();
  tmgneg1->Add(tge_rationeg_dau0088);
  tmgneg1->Add(tge_rationeg_dau0020);
  tmgneg1->Add(tge_rationeg_dau2040);
  tmgneg1->Add(tge_rationeg_dau4060);
  tmgneg1->Add(tge_rationeg_dau6088);
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
  legneg1->AddEntry(tge_rationeg_dau0088,"#pi^{-} R_{dA} 0-20%","p");
  legneg1->AddEntry(tge_rationeg_dau0020,"#pi^{-} R_{dA} 20-40%","p");
  legneg1->AddEntry(tge_rationeg_dau2040,"#pi^{-} R_{dA} 0-88%","p");
  legneg1->AddEntry(tge_rationeg_dau4060,"#pi^{-} R_{dA} 40-60%","p");
  legneg1->AddEntry(tge_rationeg_dau6088,"#pi^{-} R_{dA} 60-88%","p");
  legneg1->Draw();
  */





  char particle[7];
  if(r8pid<=1) sprintf(particle,"pion");
  else if(r8pid>=4) sprintf(particle,"proton");
  else sprintf(particle,"kaon");
  char figname[100];
  sprintf(figname,"figures/dau_rda_%s.gif",particle);
  c1->Print(figname);
  sprintf(figname,"figures/dau_rda_%s.eps",particle);
  c1->Print(figname);





}
