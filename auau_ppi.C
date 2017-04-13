void auau_ppi()
{

  TCanvas *c1 = new TCanvas("c1","",1200,600);
  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.0,0.5,1.0);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",0.5,0.0,1.0,1.0);
  c1_2->Draw();
  c1->cd();

  float MAX = 1.0;


  float sysvalue = 0.05;

  // ---------- //
  // -- 0010 -- //
  // ---------- //

  float pt_auau0010[31];
  float ept_auau0010[31];
  float ratiopos_auau0010[31];
  float rationeg_auau0010[31];
  float eratiopos_auau0010[31];
  float erationeg_auau0010[31];
  float esysratiopos_auau0010[31];
  float esysrationeg_auau0010[31];
  ifstream fauau0010("../Run7AuAu/Ratios/regular/ppi_28_cent0010.txt");
  for(int i=0; i<31; i++)
    {
      fauau0010>>pt_auau0010[i]>>ratiopos_auau0010[i]>>eratiopos_auau0010[i]>>rationeg_auau0010[i]>>erationeg_auau0010[i];
      ept_auau0010[i]=0;
      esysratiopos_auau0010[i] = sysvalue*ratiopos_auau0010[i];
      esysrationeg_auau0010[i] = sysvalue*rationeg_auau0010[i];
    }
  TGraphErrors *tge_ratiopos_auau0010 = new TGraphErrors(31,pt_auau0010,ratiopos_auau0010,ept_auau0010,eratiopos_auau0010);
  tge_ratiopos_auau0010->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau0010->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau0010 = new TGraphErrors(31,pt_auau0010,rationeg_auau0010,ept_auau0010,erationeg_auau0010);
  tge_rationeg_auau0010->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau0010->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau0010 = new TGraphErrors(31,pt_auau0010,ratiopos_auau0010,ept_auau0010,esysratiopos_auau0010);
  tge_sysratiopos_auau0010->SetMarkerStyle(1);
  tge_sysratiopos_auau0010->SetMarkerColor(kGray);
  tge_sysratiopos_auau0010->SetFillColor(kGray);
  tge_sysratiopos_auau0010->SetLineColor(kGray);
  tge_sysratiopos_auau0010->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau0010 = new TGraphErrors(31,pt_auau0010,rationeg_auau0010,ept_auau0010,esysrationeg_auau0010);
  tge_sysrationeg_auau0010->SetMarkerStyle(1);
  tge_sysrationeg_auau0010->SetMarkerColor(kGray);
  tge_sysrationeg_auau0010->SetFillColor(kGray);
  tge_sysrationeg_auau0010->SetLineColor(kGray);
  tge_sysrationeg_auau0010->SetLineWidth(15);

  // ---------- //
  // -- 1020 -- //
  // ---------- //

  float pt_auau1020[31];
  float ept_auau1020[31];
  float ratiopos_auau1020[31];
  float rationeg_auau1020[31];
  float eratiopos_auau1020[31];
  float erationeg_auau1020[31];
  float esysratiopos_auau1020[31];
  float esysrationeg_auau1020[31];
  ifstream fauau1020("../Run7AuAu/Ratios/regular/ppi_28_cent1020.txt");
  for(int i=0; i<31; i++)
    {
      fauau1020>>pt_auau1020[i]>>ratiopos_auau1020[i]>>eratiopos_auau1020[i]>>rationeg_auau1020[i]>>erationeg_auau1020[i];
      ept_auau1020[i]=0;
      esysratiopos_auau1020[i] = sysvalue*ratiopos_auau1020[i];
      esysrationeg_auau1020[i] = sysvalue*rationeg_auau1020[i];
    }
  TGraphErrors *tge_ratiopos_auau1020 = new TGraphErrors(31,pt_auau1020,ratiopos_auau1020,ept_auau1020,eratiopos_auau1020);
  tge_ratiopos_auau1020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau1020->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau1020 = new TGraphErrors(31,pt_auau1020,rationeg_auau1020,ept_auau1020,erationeg_auau1020);
  tge_rationeg_auau1020->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau1020->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau1020 = new TGraphErrors(31,pt_auau1020,ratiopos_auau1020,ept_auau1020,esysratiopos_auau1020);
  tge_sysratiopos_auau1020->SetMarkerStyle(1);
  tge_sysratiopos_auau1020->SetMarkerColor(kGray);
  tge_sysratiopos_auau1020->SetFillColor(kGray);
  tge_sysratiopos_auau1020->SetLineColor(kGray);
  tge_sysratiopos_auau1020->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau1020 = new TGraphErrors(31,pt_auau1020,rationeg_auau1020,ept_auau1020,esysrationeg_auau1020);
  tge_sysrationeg_auau1020->SetMarkerStyle(1);
  tge_sysrationeg_auau1020->SetMarkerColor(kGray);
  tge_sysrationeg_auau1020->SetFillColor(kGray);
  tge_sysrationeg_auau1020->SetLineColor(kGray);
  tge_sysrationeg_auau1020->SetLineWidth(15);

  // ---------- //
  // -- 2040 -- //
  // ---------- //

  float pt_auau2040[31];
  float ept_auau2040[31];
  float ratiopos_auau2040[31];
  float rationeg_auau2040[31];
  float eratiopos_auau2040[31];
  float erationeg_auau2040[31];
  float esysratiopos_auau2040[31];
  float esysrationeg_auau2040[31];
  ifstream fauau2040("../Run7AuAu/Ratios/regular/ppi_28_cent2040.txt");
  for(int i=0; i<31; i++)
    {
      fauau2040>>pt_auau2040[i]>>ratiopos_auau2040[i]>>eratiopos_auau2040[i]>>rationeg_auau2040[i]>>erationeg_auau2040[i];
      ept_auau2040[i]=0;
      esysratiopos_auau2040[i] = sysvalue*ratiopos_auau2040[i];
      esysrationeg_auau2040[i] = sysvalue*rationeg_auau2040[i];
    }
  TGraphErrors *tge_ratiopos_auau2040 = new TGraphErrors(31,pt_auau2040,ratiopos_auau2040,ept_auau2040,eratiopos_auau2040);
  tge_ratiopos_auau2040->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau2040->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau2040 = new TGraphErrors(31,pt_auau2040,rationeg_auau2040,ept_auau2040,erationeg_auau2040);
  tge_rationeg_auau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau2040->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau2040 = new TGraphErrors(31,pt_auau2040,ratiopos_auau2040,ept_auau2040,esysratiopos_auau2040);
  tge_sysratiopos_auau2040->SetMarkerStyle(1);
  tge_sysratiopos_auau2040->SetMarkerColor(kGray);
  tge_sysratiopos_auau2040->SetFillColor(kGray);
  tge_sysratiopos_auau2040->SetLineColor(kGray);
  tge_sysratiopos_auau2040->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau2040 = new TGraphErrors(31,pt_auau2040,rationeg_auau2040,ept_auau2040,esysrationeg_auau2040);
  tge_sysrationeg_auau2040->SetMarkerStyle(1);
  tge_sysrationeg_auau2040->SetMarkerColor(kGray);
  tge_sysrationeg_auau2040->SetFillColor(kGray);
  tge_sysrationeg_auau2040->SetLineColor(kGray);
  tge_sysrationeg_auau2040->SetLineWidth(15);

  // ---------- //
  // -- 4060 -- //
  // ---------- //

  float pt_auau4060[31];
  float ept_auau4060[31];
  float ratiopos_auau4060[31];
  float rationeg_auau4060[31];
  float eratiopos_auau4060[31];
  float erationeg_auau4060[31];
  float esysratiopos_auau4060[31];
  float esysrationeg_auau4060[31];
  ifstream fauau4060("../Run7AuAu/Ratios/regular/ppi_28_cent4060.txt");
  for(int i=0; i<31; i++)
    {
      fauau4060>>pt_auau4060[i]>>ratiopos_auau4060[i]>>eratiopos_auau4060[i]>>rationeg_auau4060[i]>>erationeg_auau4060[i];
      ept_auau4060[i]=0;
      esysratiopos_auau4060[i] = sysvalue*ratiopos_auau4060[i];
      esysrationeg_auau4060[i] = sysvalue*rationeg_auau4060[i];
    }
  TGraphErrors *tge_ratiopos_auau4060 = new TGraphErrors(31,pt_auau4060,ratiopos_auau4060,ept_auau4060,eratiopos_auau4060);
  tge_ratiopos_auau4060->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau4060->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau4060 = new TGraphErrors(31,pt_auau4060,rationeg_auau4060,ept_auau4060,erationeg_auau4060);
  tge_rationeg_auau4060->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau4060->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau4060 = new TGraphErrors(31,pt_auau4060,ratiopos_auau4060,ept_auau4060,esysratiopos_auau4060);
  tge_sysratiopos_auau4060->SetMarkerStyle(1);
  tge_sysratiopos_auau4060->SetMarkerColor(kGray);
  tge_sysratiopos_auau4060->SetFillColor(kGray);
  tge_sysratiopos_auau4060->SetLineColor(kGray);
  tge_sysratiopos_auau4060->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau4060 = new TGraphErrors(31,pt_auau4060,rationeg_auau4060,ept_auau4060,esysrationeg_auau4060);
  tge_sysrationeg_auau4060->SetMarkerStyle(1);
  tge_sysrationeg_auau4060->SetMarkerColor(kGray);
  tge_sysrationeg_auau4060->SetFillColor(kGray);
  tge_sysrationeg_auau4060->SetLineColor(kGray);
  tge_sysrationeg_auau4060->SetLineWidth(15);

  // ---------- //
  // -- 6092 -- //
  // ---------- //

  float pt_auau6092[31];
  float ept_auau6092[31];
  float ratiopos_auau6092[31];
  float rationeg_auau6092[31];
  float eratiopos_auau6092[31];
  float erationeg_auau6092[31];
  float esysratiopos_auau6092[31];
  float esysrationeg_auau6092[31];
  ifstream fauau6092("../Run7AuAu/Ratios/regular/ppi_28_cent6092.txt");
  for(int i=0; i<31; i++)
    {
      fauau6092>>pt_auau6092[i]>>ratiopos_auau6092[i]>>eratiopos_auau6092[i]>>rationeg_auau6092[i]>>erationeg_auau6092[i];
      ept_auau6092[i]=0;
      esysratiopos_auau6092[i] = sysvalue*ratiopos_auau6092[i];
      esysrationeg_auau6092[i] = sysvalue*rationeg_auau6092[i];
    }
  TGraphErrors *tge_ratiopos_auau6092 = new TGraphErrors(31,pt_auau6092,ratiopos_auau6092,ept_auau6092,eratiopos_auau6092);
  tge_ratiopos_auau6092->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau6092->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau6092 = new TGraphErrors(31,pt_auau6092,rationeg_auau6092,ept_auau6092,erationeg_auau6092);
  tge_rationeg_auau6092->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau6092->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_auau6092 = new TGraphErrors(31,pt_auau6092,ratiopos_auau6092,ept_auau6092,esysratiopos_auau6092);
  tge_sysratiopos_auau6092->SetMarkerStyle(1);
  tge_sysratiopos_auau6092->SetMarkerColor(kGray);
  tge_sysratiopos_auau6092->SetFillColor(kGray);
  tge_sysratiopos_auau6092->SetLineColor(kGray);
  tge_sysratiopos_auau6092->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_auau6092 = new TGraphErrors(31,pt_auau6092,rationeg_auau6092,ept_auau6092,esysrationeg_auau6092);
  tge_sysrationeg_auau6092->SetMarkerStyle(1);
  tge_sysrationeg_auau6092->SetMarkerColor(kGray);
  tge_sysrationeg_auau6092->SetFillColor(kGray);
  tge_sysrationeg_auau6092->SetLineColor(kGray);
  tge_sysrationeg_auau6092->SetLineWidth(15);


  // -------- //
  // -- pp -- //
  // -------- //

  float pt_pp[25];
  float ept_pp[25];
  float ratiopos_pp[25];
  float rationeg_pp[25];
  float eratiopos_pp[25];
  float erationeg_pp[25];
  float esysratiopos_pp[25];
  float esysrationeg_pp[25];
  ifstream fpp("ExtraData/PPG101/ppi.dat");
  for(int i=0; i<25; i++)
    {
      fpp>>pt_pp[i]>>ratiopos_pp[i]>>eratiopos_pp[i]>>esysratiopos_pp[i]>>rationeg_pp[i]>>erationeg_pp[i]>>esysrationeg_pp[i];
      ept_pp[i]=0;
    }
  TGraphErrors *tge_ratiopos_pp = new TGraphErrors(25,pt_pp,ratiopos_pp,ept_pp,eratiopos_pp);
  tge_ratiopos_pp->SetMarkerStyle(kFullCircle);
  tge_ratiopos_pp->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_pp = new TGraphErrors(25,pt_pp,rationeg_pp,ept_pp,erationeg_pp);
  tge_rationeg_pp->SetMarkerStyle(kFullSquare);
  tge_rationeg_pp->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_pp = new TGraphErrors(25,pt_pp,ratiopos_pp,ept_pp,esysratiopos_pp);
  tge_sysratiopos_pp->SetMarkerStyle(1);
  tge_sysratiopos_pp->SetMarkerColor(kGray);
  tge_sysratiopos_pp->SetFillColor(kGray);
  tge_sysratiopos_pp->SetLineColor(kGray);
  tge_sysratiopos_pp->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_pp = new TGraphErrors(25,pt_pp,rationeg_pp,ept_pp,esysrationeg_pp);
  tge_sysrationeg_pp->SetMarkerStyle(1);
  tge_sysrationeg_pp->SetMarkerColor(kGray);
  tge_sysrationeg_pp->SetFillColor(kGray);
  tge_sysrationeg_pp->SetLineColor(kGray);
  tge_sysrationeg_pp->SetLineWidth(15);







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

  tge_ratiopos_pp->SetMarkerColor(kBlack);
  tge_ratiopos_pp->SetMarkerStyle(kFullCross);

  tge_sysratiopos_auau0010->SetLineColor(kGray);
  tge_sysratiopos_auau1020->SetLineColor(kRed-9);
  tge_sysratiopos_auau2040->SetLineColor(kBlue-9);
  tge_sysratiopos_auau4060->SetLineColor(kGreen-9);
  tge_sysratiopos_auau6092->SetLineColor(kMagenta-9);



  c1_1->cd();
  c1_1->SetRightMargin(0);
  c1_1->SetTopMargin(0.05);
  c1_1->SetLeftMargin(0.15);
  c1_1->SetBottomMargin(0.15);
  c1_1->SetTicks(1,1);
  TMultiGraph *tmgpos1 = new TMultiGraph();
  //tmgpos1->Add(tge_sysratiopos_pp);
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
  tmgpos1->Add(tge_ratiopos_pp);
  tmgpos1->Draw("apz");
  for(int i=0; i<26; i++)
    {
      double px1 = pt_pp[i]-0.05;//ept[i];
      double py1 = ratiopos_pp[i]-esysratiopos_pp[i];
      double px2 = pt_pp[i]+0.05;//ept[i];
      double py2 = ratiopos_pp[i]+esysratiopos_pp[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmgpos1->SetMaximum(MAX);
  tmgpos1->SetMinimum(0.0);
  tmgpos1->GetXaxis()->SetLimits(0.0,6.0);
  tmgpos1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos1->GetXaxis()->CenterTitle();
  tmgpos1->GetYaxis()->SetTitle("Ratio p/#pi");
  tmgpos1->GetYaxis()->CenterTitle();
  tmgpos1->GetYaxis()->SetTitleOffset(1.3);
  tmgpos1->GetYaxis()->SetTitleSize(0.05);
  tmgpos1->GetYaxis()->SetLabelSize(0.05);
  tmgpos1->GetXaxis()->SetTitleSize(0.05);
  tmgpos1->GetXaxis()->SetLabelSize(0.05);
  TLatex *tlpos = new TLatex(0.5,0.85*MAX,"p/#pi^{+}");
  tlpos->SetTextSize(0.075);
  tlpos->Draw();

  TLegend *legpos1 = new TLegend(0.12,0.68,0.38,0.88);
  legpos1->SetBorderSize(0);
  legpos1->SetFillColor(kWhite);
  legpos1->AddEntry(tge_ratiopos_auau0010,"p/#pi^{+} Au+Au 0-10%","p");
  legpos1->AddEntry(tge_ratiopos_auau1020,"p/#pi^{+} Au+Au 10-20%","p");
  legpos1->AddEntry(tge_ratiopos_auau2040,"p/#pi^{+} Au+Au 20-40%","p");
  legpos1->AddEntry(tge_ratiopos_auau4060,"p/#pi^{+} Au+Au 40-60%","p");
  legpos1->AddEntry(tge_ratiopos_auau6092,"p/#pi^{+} Au+Au 60-92%","p");
  legpos1->SetTextSize(0.05);
  //legpos1->Draw();


  // ---
  // --- now do neg
  // ---


  tge_rationeg_auau0010->SetMarkerColor(kBlack);
  tge_rationeg_auau1020->SetMarkerColor(kRed);
  tge_rationeg_auau2040->SetMarkerColor(kBlue);
  tge_rationeg_auau4060->SetMarkerColor(kGreen+2);
  tge_rationeg_auau6092->SetMarkerColor(kMagenta+2);

  tge_rationeg_auau0010->SetMarkerStyle(kOpenCircle);
  tge_rationeg_auau1020->SetMarkerStyle(kOpenSquare);
  tge_rationeg_auau2040->SetMarkerStyle(kOpenTriangleUp);
  tge_rationeg_auau4060->SetMarkerStyle(kOpenTriangleDown);
  tge_rationeg_auau6092->SetMarkerStyle(kOpenDiamond);

  tge_rationeg_pp->SetMarkerColor(kBlack);
  tge_rationeg_pp->SetMarkerStyle(kOpenCross);

  tge_rationeg_auau0010->SetMarkerStyle(kFullCircle);
  tge_rationeg_auau1020->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau2040->SetMarkerStyle(kFullTriangleUp);
  tge_rationeg_auau4060->SetMarkerStyle(kFullTriangleDown);
  tge_rationeg_auau6092->SetMarkerStyle(kFullDiamond);

  tge_rationeg_pp->SetMarkerColor(kBlack);
  tge_rationeg_pp->SetMarkerStyle(kFullCross);

  tge_sysrationeg_auau0010->SetLineColor(kGray);
  tge_sysrationeg_auau1020->SetLineColor(kRed-9);
  tge_sysrationeg_auau2040->SetLineColor(kBlue-9);
  tge_sysrationeg_auau4060->SetLineColor(kGreen-9);
  tge_sysrationeg_auau6092->SetLineColor(kMagenta-9);

  c1_2->cd();
  c1_2->SetLeftMargin(0);
  c1_2->SetTopMargin(0.05);
  c1_2->SetRightMargin(0.15);
  c1_2->SetBottomMargin(0.15);
  c1_2->SetTicks(1,1);
  TMultiGraph *tmgneg1 = new TMultiGraph();
  //tmgneg1->Add(tge_sysrationeg_pp);
  tmgneg1->Add(tge_sysrationeg_auau0010);
  tmgneg1->Add(tge_sysrationeg_auau1020);
  tmgneg1->Add(tge_sysrationeg_auau2040);
  tmgneg1->Add(tge_sysrationeg_auau4060);
  tmgneg1->Add(tge_sysrationeg_auau6092);
  tmgneg1->Add(tge_rationeg_auau0010);
  tmgneg1->Add(tge_rationeg_auau1020);
  tmgneg1->Add(tge_rationeg_auau2040);
  tmgneg1->Add(tge_rationeg_auau4060);
  tmgneg1->Add(tge_rationeg_auau6092);
  tmgneg1->Add(tge_rationeg_pp);
  tmgneg1->Draw("apz");
  for(int i=0; i<26; i++)
    {
      double px1 = pt_pp[i]-0.05;//ept[i];
      double py1 = rationeg_pp[i]-esysrationeg_pp[i];
      double px2 = pt_pp[i]+0.05;//ept[i];
      double py2 = rationeg_pp[i]+esysrationeg_pp[i];
      TBox *boxauauneg = new TBox(px1,py1,px2,py2);
      boxauauneg->SetFillColor(kBlack);
      boxauauneg->SetFillStyle(0);
      boxauauneg->SetLineColor(kBlack);
      boxauauneg->SetLineWidth(1);
      boxauauneg->Draw("lsame");
    }
  tmgneg1->SetMaximum(MAX);
  tmgneg1->SetMinimum(0.0);
  tmgneg1->GetXaxis()->SetLimits(0.0,6.0);
  tmgneg1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgneg1->GetXaxis()->CenterTitle();
  tmgneg1->GetYaxis()->SetTitle("Ratio p/#pi");
  tmgneg1->GetYaxis()->CenterTitle();
  tmgneg1->GetYaxis()->SetTitleOffset(1.5);
  TMultiGraph *tmgneg2 = (TMultiGraph *)tmgneg1->Clone();
  tmgneg1->GetYaxis()->SetTitleSize(0);
  tmgneg1->GetYaxis()->SetLabelSize(0);
  tmgneg1->GetXaxis()->SetTitleSize(0.05);
  tmgneg1->GetXaxis()->SetLabelSize(0.05);
  TLatex *tlneg = new TLatex(0.5,0.85*MAX,"#bar{p}/#pi^{-}");
  tlneg->SetTextSize(0.075);
  tlneg->Draw();

  // LEGENDY GOODNESS
  tge_ratiopos_auau0010->SetTitle("");
  tge_ratiopos_auau1020->SetTitle("");
  tge_ratiopos_auau2040->SetTitle("");
  tge_ratiopos_auau4060->SetTitle("");
  tge_ratiopos_auau6092->SetTitle("");
  tge_ratiopos_pp->SetTitle("");
  TLegend *lg11 = new TLegend(0.22,0.58,0.23,0.88);//adding pp now
  lg11->SetBorderSize(0);
  lg11->SetFillColor(kWhite);
  lg11->AddEntry((TObject*)0,"","");
  lg11->AddEntry(tge_ratiopos_auau0010,"","p");
  lg11->AddEntry(tge_ratiopos_auau1020,"","p");
  lg11->AddEntry(tge_ratiopos_auau2040,"","p");
  lg11->AddEntry(tge_ratiopos_auau4060,"","p");
  lg11->AddEntry(tge_ratiopos_auau6092,"","p");
  lg11->AddEntry(tge_ratiopos_pp,"","p");
  lg11->SetTextSize(0.05);
  //lg11->Draw();
  //TLegend *leg1 = new TLegend(0.38,0.68,0.88,0.88);
  //TLegend *leg1 = new TLegend(0.39,0.68,0.81,0.88);
  //TLegend *leg1 = new TLegend(0.23,0.65,0.78,0.88);
  //TLegend *leg1 = new TLegend(0.23,0.58,0.78,0.88);//adding pp now
  //TLegend *leg1 = new TLegend(0.23,0.58,0.58,0.88);//adding pp now
  //TLegend *leg1 = new TLegend(0.23,0.60,0.58,0.90);//adding pp now // COME BACK HERE
  //TLegend *leg1 = new TLegend(0.43,0.60,0.78,0.90);//adding pp now // COME BACK HERE
  TLegend *leg1 = new TLegend(0.27,0.62,0.62,0.92);//adding pp now // COME BACK HERE
  leg1->SetBorderSize(0);
  leg1->SetFillColor(kWhite);
  leg1->AddEntry((TObject*)0,"Au+Au #sqrt{s_{NN}}=200 GeV","");
  leg1->AddEntry(tge_rationeg_auau0010,"0-10%","p");
  leg1->AddEntry(tge_rationeg_auau1020,"10-20%","p");
  leg1->AddEntry(tge_rationeg_auau2040,"20-40%","p");
  leg1->AddEntry(tge_rationeg_auau4060,"40-60%","p");
  leg1->AddEntry(tge_rationeg_auau6092,"60-92%","p");
  leg1->AddEntry(tge_rationeg_pp,"p+p","p");
  leg1->SetTextSize(0.05);
  leg1->Draw();

  c1->cd();
  //TLegend *legB = new TLegend(0.2,0.2,0.8,0.8);//adding pp now
  //TLegend *legB = new TLegend(0.0,0.0,1.0,1.0);//adding pp now
  TLegend *legB = new TLegend(0.39,0.6,0.61,0.90);//adding pp now
  legB->SetBorderSize(0);
  legB->SetFillColor(kWhite);
  legB->AddEntry((TObject*)0,"Au+Au #sqrt{s_{NN}}=200 GeV","");
  legB->AddEntry(tge_ratiopos_auau0010,"0-10%","p");
  legB->AddEntry(tge_ratiopos_auau1020,"10-20%","p");
  legB->AddEntry(tge_ratiopos_auau2040,"20-40%","p");
  legB->AddEntry(tge_ratiopos_auau4060,"40-60%","p");
  legB->AddEntry(tge_ratiopos_auau6092,"60-92%","p");
  legB->AddEntry(tge_ratiopos_pp,"p+p","p");
  legB->SetTextSize(0.05);
  //legB->Draw();

  //c1->cd();

  c1->Print("figures/auau_ppi_both.gif");
  c1->Print("figures/auau_ppi_both.eps");


  c1->Clear();
  delete c1;

  // TCanvas *c2 = new TCanvas();
  // tmgpos1->Draw("apz");
  // legpos1->Draw();
  // c2->Print("figures/auau_ppi_pos.gif");
  // c2->Print("figures/auau_ppi_pos.eps");
  // c2->Clear();
  // tmgneg2->Draw("apz");
  // legneg1->Draw();
  // c2->Print("figures/auau_ppi_neg.gif");
  // c2->Print("figures/auau_ppi_neg.eps");



  TCanvas *c2 = new TCanvas("c2","c2",600,700);
  TPad *c2_1 = new TPad("c2_1","c2_1",0.0,0.0,1.0,0.5);
  c2_1->Draw();
  c2->cd();
  TPad *c2_2 = new TPad("c2_2","c2_2",0.0,0.5,1.0,1.0);
  c2_2->Draw();
  c2->cd();

  float size = 0.05;
  float titleoff = 0.9;
  float scale = 0.78;

  //if(yaxis0!=NULL) delete yaxis0;
  TGaxis *yaxis0 = new TGaxis(0.15,0.075,0.15,0.5,0.0,MAX-0.0001,505,"");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("Ratio p/#pi");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(size*scale);
  yaxis0->SetTitleSize(size*scale);
  yaxis0->SetTitleOffset(1.5);
  //yaxis0->SetTickSize(0.01);
  yaxis0->Draw();

  //if(yaxis1!=NULL) delete yaxis1;
  TGaxis *yaxis1 = new TGaxis(0.15,0.5,0.15,0.925,0.0,MAX,505,"");
  yaxis1->SetName("yaxis1");
  yaxis1->SetTitle("Ratio p/#pi");
  yaxis1->CenterTitle();
  yaxis1->SetLabelSize(size*scale);
  yaxis1->SetTitleSize(size*scale);
  yaxis1->SetTitleOffset(1.5);
  yaxis1->Draw();

  //if(xaxis0!=NULL) delete xaxis0;
  TGaxis *xaxis0 = new TGaxis(0.15,0.075,0.9,0.075,0.0,6.0,510,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(size*scale);
  xaxis0->SetTitleSize(size*scale);
  xaxis0->SetTitleOffset(0.9);
  xaxis0->Draw();

  //if(xaxis1!=NULL) delete xaxis1;
  TGaxis *xaxis1 = new TGaxis(0.15,0.55,0.9,0.55,0.0,6.0,510,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(size*scale);
  xaxis1->SetTitleSize(size*scale);
  xaxis1->SetTitleOffset(0.9);
  //xaxis1->Draw();



  c2_2->cd();
  c2_2->SetLeftMargin(0.15);
  c2_2->SetTopMargin(0.15);
  c2_2->SetRightMargin(0.1);
  c2_2->SetBottomMargin(0.0);
  c2_2->SetTicks(1,1);
  tmgpos1->GetYaxis()->SetTitleOffset(1.0);
  // tmgpos1->GetYaxis()->SetTitleSize(0.06);
  // tmgpos1->GetYaxis()->SetLabelSize(0.06);
  tmgpos1->GetYaxis()->SetTitleSize(0.0);
  tmgpos1->GetYaxis()->SetLabelSize(0.0);
  tmgpos1->GetXaxis()->SetTitleSize(0.0);
  tmgpos1->GetXaxis()->SetLabelSize(0.0);
  tmgpos1->GetYaxis()->SetNdivisions(505);
  tmgpos1->Draw("apz");
  tlpos->Draw();
  for(int i=0; i<26; i++)
    {
      double px1 = pt_pp[i]-0.05;//ept[i];
      double py1 = ratiopos_pp[i]-esysratiopos_pp[i];
      double px2 = pt_pp[i]+0.05;//ept[i];
      double py2 = ratiopos_pp[i]+esysratiopos_pp[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  TLatex *tlsys = new TLatex(3.0,0.85*MAX,"Au+Au #sqrt{s_{NN}} = 200 GeV");
  tlsys->SetTextSize(0.06);
  tlsys->Draw();
  c2_1->cd();
  c2_1->SetRightMargin(0.1);
  c2_1->SetTopMargin(0.0);
  c2_1->SetLeftMargin(0.15);
  c2_1->SetBottomMargin(0.15);
  c2_1->SetTicks(1,1);
  tmgneg2->GetYaxis()->SetTitleOffset(1.0);
  // tmgneg2->GetYaxis()->SetTitleSize(0.06);
  // tmgneg2->GetYaxis()->SetLabelSize(0.06);
  // tmgneg2->GetXaxis()->SetTitleSize(0.06);
  // tmgneg2->GetXaxis()->SetLabelSize(0.06); 
  tmgneg2->GetYaxis()->SetTitleSize(0.0);
  tmgneg2->GetYaxis()->SetLabelSize(0.0);
  tmgneg2->GetXaxis()->SetTitleSize(0.0);
  tmgneg2->GetXaxis()->SetLabelSize(0.0); 
  tmgneg2->GetYaxis()->SetNdivisions(505);
  tmgneg2->SetMaximum(MAX-0.0001);
  tmgneg2->Draw("apz");
  tlneg->Draw();
  for(int i=0; i<26; i++)
    {
      double px1 = pt_pp[i]-0.05;//ept[i];
      double py1 = rationeg_pp[i]-esysrationeg_pp[i];
      double px2 = pt_pp[i]+0.05;//ept[i];
      double py2 = rationeg_pp[i]+esysrationeg_pp[i];
      TBox *boxauauneg = new TBox(px1,py1,px2,py2);
      boxauauneg->SetFillColor(kBlack);
      boxauauneg->SetFillStyle(0);
      boxauauneg->SetLineColor(kBlack);
      boxauauneg->SetLineWidth(1);
      boxauauneg->Draw("lsame");
    }
  // this is the minor legend
  //TLegend *LEG = new TLegend(0.67,0.58,0.68,0.88);//adding pp now
  TLegend *LEG = new TLegend(0.67,0.62,0.68,0.92);//adding pp now
  LEG->SetBorderSize(0);
  LEG->SetFillColor(kWhite);
  LEG->AddEntry(tge_ratiopos_auau0010,"","p");
  LEG->AddEntry(tge_ratiopos_auau1020,"","p");
  LEG->AddEntry(tge_ratiopos_auau2040,"","p");
  LEG->AddEntry(tge_ratiopos_auau4060,"","p");
  LEG->AddEntry(tge_ratiopos_auau6092,"","p");
  LEG->AddEntry(tge_ratiopos_pp,"","p");
  LEG->SetTextSize(0.06);
  //LEG->Draw(); // Jamie Nagle
  // this is the major legend
  //TLegend *LG2 = new TLegend(0.68,0.58,0.88,0.88);//adding pp now
  TLegend *LG2 = new TLegend(0.68,0.62,0.88,0.92);//adding pp now
  LG2->SetBorderSize(0);
  LG2->SetFillColor(kWhite);
  LG2->AddEntry(tge_rationeg_auau0010,"0-10%","p");
  LG2->AddEntry(tge_rationeg_auau1020,"10-20%","p");
  LG2->AddEntry(tge_rationeg_auau2040,"20-40%","p");
  LG2->AddEntry(tge_rationeg_auau4060,"40-60%","p");
  LG2->AddEntry(tge_rationeg_auau6092,"60-92%","p");
  LG2->AddEntry(tge_rationeg_pp,"p+p","p");
  LG2->SetTextSize(0.06);
  LG2->Draw();
  //legneg1->Draw();

  c2->Print("figures/auau_ppi_voth.gif");
  c2->Print("figures/auau_ppi_voth.eps");


  c2->Clear();
  delete c2;

}
