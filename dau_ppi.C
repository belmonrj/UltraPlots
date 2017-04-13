void dau_ppi()
{

  TCanvas *c1 = new TCanvas("c1","",1200,600);
  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.0,0.5,1.0);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",0.5,0.0,1.0,1.0);
  c1_2->Draw();
  c1->cd();

  float MAX = 0.5;


  float sysvalue = 0.05;

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
  ifstream fdau0088("../Run8dAu/Ratios/regular/ppi_15_cent0088.txt");
  for(int i=0; i<36; i++)
    {
      fdau0088>>pt_dau0088[i]>>ratiopos_dau0088[i]>>eratiopos_dau0088[i]>>rationeg_dau0088[i]>>erationeg_dau0088[i];
      ept_dau0088[i]=0;
      esysratiopos_dau0088[i] = sysvalue*ratiopos_dau0088[i];
      esysrationeg_dau0088[i] = sysvalue*rationeg_dau0088[i];
      //cout<<i<<" "<<eratiopos_dau0088[i]/ratiopos_dau0088[i]<<" "<<erationeg_dau0088[i]/rationeg_dau0088[i]<<endl;
    }
  TGraphErrors *tge_ratiopos_dau0088 = new TGraphErrors(36,pt_dau0088,ratiopos_dau0088,ept_dau0088,eratiopos_dau0088);
  tge_ratiopos_dau0088->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau0088->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau0088 = new TGraphErrors(36,pt_dau0088,rationeg_dau0088,ept_dau0088,erationeg_dau0088);
  tge_rationeg_dau0088->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0088->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau0088 = new TGraphErrors(36,pt_dau0088,ratiopos_dau0088,ept_dau0088,esysratiopos_dau0088);
  tge_sysratiopos_dau0088->SetMarkerStyle(1);
  tge_sysratiopos_dau0088->SetMarkerColor(kGray);
  tge_sysratiopos_dau0088->SetFillColor(kGray);
  tge_sysratiopos_dau0088->SetLineColor(kGray);
  tge_sysratiopos_dau0088->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau0088 = new TGraphErrors(36,pt_dau0088,rationeg_dau0088,ept_dau0088,esysrationeg_dau0088);
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
  ifstream fdau0020("../Run8dAu/Ratios/regular/ppi_15_cent0020.txt");
  for(int i=0; i<36; i++)
    {
      fdau0020>>pt_dau0020[i]>>ratiopos_dau0020[i]>>eratiopos_dau0020[i]>>rationeg_dau0020[i]>>erationeg_dau0020[i];
      ept_dau0020[i]=0; 
      esysratiopos_dau0020[i] = sysvalue*ratiopos_dau0020[i];
      esysrationeg_dau0020[i] = sysvalue*rationeg_dau0020[i];
      //cout<<i<<" "<<eratiopos_dau0020[i]/ratiopos_dau0020[i]<<" "<<erationeg_dau0020[i]/rationeg_dau0020[i]<<endl;
    }
  TGraphErrors *tge_ratiopos_dau0020 = new TGraphErrors(36,pt_dau0020,ratiopos_dau0020,ept_dau0020,eratiopos_dau0020);
  tge_ratiopos_dau0020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau0020->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau0020 = new TGraphErrors(36,pt_dau0020,rationeg_dau0020,ept_dau0020,erationeg_dau0020);
  tge_rationeg_dau0020->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0020->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau0020 = new TGraphErrors(36,pt_dau0020,ratiopos_dau0020,ept_dau0020,esysratiopos_dau0020);
  tge_sysratiopos_dau0020->SetMarkerStyle(1);
  tge_sysratiopos_dau0020->SetMarkerColor(kGray);
  tge_sysratiopos_dau0020->SetFillColor(kGray);
  tge_sysratiopos_dau0020->SetLineColor(kGray);
  tge_sysratiopos_dau0020->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau0020 = new TGraphErrors(36,pt_dau0020,rationeg_dau0020,ept_dau0020,esysrationeg_dau0020);
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
  ifstream fdau2040("../Run8dAu/Ratios/regular/ppi_15_cent2040.txt");
  for(int i=0; i<36; i++)
    {
      fdau2040>>pt_dau2040[i]>>ratiopos_dau2040[i]>>eratiopos_dau2040[i]>>rationeg_dau2040[i]>>erationeg_dau2040[i];
      ept_dau2040[i]=0; 
      esysratiopos_dau2040[i] = sysvalue*ratiopos_dau2040[i];
      esysrationeg_dau2040[i] = sysvalue*rationeg_dau2040[i];
      //cout<<i<<" "<<eratiopos_dau2040[i]/ratiopos_dau2040[i]<<" "<<erationeg_dau2040[i]/rationeg_dau2040[i]<<endl;
    }
  TGraphErrors *tge_ratiopos_dau2040 = new TGraphErrors(36,pt_dau2040,ratiopos_dau2040,ept_dau2040,eratiopos_dau2040);
  tge_ratiopos_dau2040->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau2040->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau2040 = new TGraphErrors(36,pt_dau2040,rationeg_dau2040,ept_dau2040,erationeg_dau2040);
  tge_rationeg_dau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau2040->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau2040 = new TGraphErrors(36,pt_dau2040,ratiopos_dau2040,ept_dau2040,esysratiopos_dau2040);
  tge_sysratiopos_dau2040->SetMarkerStyle(1);
  tge_sysratiopos_dau2040->SetMarkerColor(kGray);
  tge_sysratiopos_dau2040->SetFillColor(kGray);
  tge_sysratiopos_dau2040->SetLineColor(kGray);
  tge_sysratiopos_dau2040->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau2040 = new TGraphErrors(36,pt_dau2040,rationeg_dau2040,ept_dau2040,esysrationeg_dau2040);
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
  ifstream fdau4060("../Run8dAu/Ratios/regular/ppi_15_cent4060.txt");
  for(int i=0; i<36; i++)
    {
      fdau4060>>pt_dau4060[i]>>ratiopos_dau4060[i]>>eratiopos_dau4060[i]>>rationeg_dau4060[i]>>erationeg_dau4060[i];
      ept_dau4060[i]=0; 
      esysratiopos_dau4060[i] = sysvalue*ratiopos_dau4060[i];
      esysrationeg_dau4060[i] = sysvalue*rationeg_dau4060[i];
      //cout<<i<<" "<<eratiopos_dau4060[i]/ratiopos_dau4060[i]<<" "<<erationeg_dau4060[i]/rationeg_dau4060[i]<<endl;
    }
  TGraphErrors *tge_ratiopos_dau4060 = new TGraphErrors(36,pt_dau4060,ratiopos_dau4060,ept_dau4060,eratiopos_dau4060);
  tge_ratiopos_dau4060->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau4060->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau4060 = new TGraphErrors(36,pt_dau4060,rationeg_dau4060,ept_dau4060,erationeg_dau4060);
  tge_rationeg_dau4060->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau4060->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau4060 = new TGraphErrors(36,pt_dau4060,ratiopos_dau4060,ept_dau4060,esysratiopos_dau4060);
  tge_sysratiopos_dau4060->SetMarkerStyle(1);
  tge_sysratiopos_dau4060->SetMarkerColor(kGray);
  tge_sysratiopos_dau4060->SetFillColor(kGray);
  tge_sysratiopos_dau4060->SetLineColor(kGray);
  tge_sysratiopos_dau4060->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau4060 = new TGraphErrors(36,pt_dau4060,rationeg_dau4060,ept_dau4060,esysrationeg_dau4060);
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
  ifstream fdau6088("../Run8dAu/Ratios/regular/ppi_15_cent6088.txt");
  for(int i=0; i<36; i++)
    {
      fdau6088>>pt_dau6088[i]>>ratiopos_dau6088[i]>>eratiopos_dau6088[i]>>rationeg_dau6088[i]>>erationeg_dau6088[i];
      ept_dau6088[i]=0; 
      esysratiopos_dau6088[i] = sysvalue*ratiopos_dau6088[i];
      esysrationeg_dau6088[i] = sysvalue*rationeg_dau6088[i];
      //cout<<i<<" "<<eratiopos_dau6088[i]/ratiopos_dau6088[i]<<" "<<erationeg_dau6088[i]/rationeg_dau6088[i]<<endl;
    }
  TGraphErrors *tge_ratiopos_dau6088 = new TGraphErrors(36,pt_dau6088,ratiopos_dau6088,ept_dau6088,eratiopos_dau6088);
  tge_ratiopos_dau6088->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau6088->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau6088 = new TGraphErrors(36,pt_dau6088,rationeg_dau6088,ept_dau6088,erationeg_dau6088);
  tge_rationeg_dau6088->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau6088->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysratiopos_dau6088 = new TGraphErrors(36,pt_dau6088,ratiopos_dau6088,ept_dau6088,esysratiopos_dau6088);
  tge_sysratiopos_dau6088->SetMarkerStyle(1);
  tge_sysratiopos_dau6088->SetMarkerColor(kGray);
  tge_sysratiopos_dau6088->SetFillColor(kGray);
  tge_sysratiopos_dau6088->SetLineColor(kGray);
  tge_sysratiopos_dau6088->SetLineWidth(15);
  TGraphErrors *tge_sysrationeg_dau6088 = new TGraphErrors(36,pt_dau6088,rationeg_dau6088,ept_dau6088,esysrationeg_dau6088);
  tge_sysrationeg_dau6088->SetMarkerStyle(1);
  tge_sysrationeg_dau6088->SetMarkerColor(kGray);
  tge_sysrationeg_dau6088->SetFillColor(kGray);
  tge_sysrationeg_dau6088->SetLineColor(kGray);
  tge_sysrationeg_dau6088->SetLineWidth(15);




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

  tge_ratiopos_pp->SetMarkerColor(kBlack);
  tge_ratiopos_pp->SetMarkerStyle(kFullCross);

  tge_sysratiopos_dau0020->SetLineColor(kGray);
  tge_sysratiopos_dau2040->SetLineColor(kRed-9);
  tge_sysratiopos_dau0088->SetLineColor(kBlue-9);
  tge_sysratiopos_dau4060->SetLineColor(kGreen-9);
  tge_sysratiopos_dau6088->SetLineColor(kMagenta-9);



  c1_1->cd();
  c1_1->SetRightMargin(0);
  c1_1->SetTopMargin(0.05);
  c1_1->SetLeftMargin(0.15);
  c1_1->SetBottomMargin(0.15);
  c1_1->SetTicks(1,1);
  TMultiGraph *tmgpos2 = new TMultiGraph();
  //tmgpos2->Add(tge_sysratiopos_pp);//new
  tmgpos2->Add(tge_sysratiopos_dau0088);
  tmgpos2->Add(tge_sysratiopos_dau0020);
  tmgpos2->Add(tge_sysratiopos_dau2040);
  tmgpos2->Add(tge_sysratiopos_dau4060);
  tmgpos2->Add(tge_sysratiopos_dau6088);
  tmgpos2->Add(tge_ratiopos_dau0088);
  tmgpos2->Add(tge_ratiopos_dau0020);
  tmgpos2->Add(tge_ratiopos_dau2040);
  tmgpos2->Add(tge_ratiopos_dau4060);
  tmgpos2->Add(tge_ratiopos_dau6088);
  tmgpos2->Add(tge_ratiopos_pp);
  tmgpos2->Draw("apz");
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
  tmgpos2->SetMaximum(MAX);
  tmgpos2->SetMinimum(0.0);
  tmgpos2->GetXaxis()->SetLimits(0.0,6.0);
  tmgpos2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos2->GetXaxis()->CenterTitle();
  tmgpos2->GetYaxis()->SetTitle("Ratio p/#pi");
  tmgpos2->GetYaxis()->CenterTitle();
  tmgpos2->GetYaxis()->SetTitleOffset(1.3);
  tmgpos2->GetYaxis()->SetTitleSize(0.05);
  tmgpos2->GetYaxis()->SetLabelSize(0.05);
  tmgpos2->GetXaxis()->SetTitleSize(0.05);
  tmgpos2->GetXaxis()->SetLabelSize(0.05);
  tmgpos2->GetYaxis()->SetNdivisions(505);
  TLatex *tlpos = new TLatex(0.5,0.85*MAX,"p/#pi^{+}");
  tlpos->SetTextSize(0.075);
  tlpos->Draw();

  TLegend *legpos2 = new TLegend(0.12,0.68,0.38,0.88);
  //TLegend *legpos2 = new TLegend(0.33,0.15,0.67,0.35);
  legpos2->SetBorderSize(0);
  legpos2->SetFillColor(kWhite);
  legpos2->AddEntry(tge_ratiopos_dau0020,"p/#pi^{+} d+Au 0-20%","p");
  legpos2->AddEntry(tge_ratiopos_dau2040,"p/#pi^{+} d+Au 20-40%","p");
  legpos2->AddEntry(tge_ratiopos_dau0088,"p/#pi^{+} d+Au 0-88%","p");
  legpos2->AddEntry(tge_ratiopos_dau4060,"p/#pi^{+} d+Au 40-60%","p");
  legpos2->AddEntry(tge_ratiopos_dau6088,"p/#pi^{+} d+Au 60-88%","p");
  legpos2->SetTextSize(0.05);
  //legpos2->Draw();


  // ---
  // --- now neg
  // ---


  tge_rationeg_dau0020->SetMarkerColor(kBlack);
  tge_rationeg_dau2040->SetMarkerColor(kRed);
  tge_rationeg_dau0088->SetMarkerColor(kBlue);
  tge_rationeg_dau4060->SetMarkerColor(kGreen+2);
  tge_rationeg_dau6088->SetMarkerColor(kMagenta+2);

  // Jamie Nagle

  tge_rationeg_dau0020->SetMarkerStyle(kFullCircle);
  tge_rationeg_dau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0088->SetMarkerStyle(kFullTriangleUp);
  tge_rationeg_dau4060->SetMarkerStyle(kFullTriangleDown);
  tge_rationeg_dau6088->SetMarkerStyle(kFullDiamond);

  tge_rationeg_pp->SetMarkerColor(kBlack);
  tge_rationeg_pp->SetMarkerStyle(kFullCross);

  tge_ratiopos_dau0020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau2040->SetMarkerStyle(kFullSquare);
  tge_ratiopos_dau0088->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_dau4060->SetMarkerStyle(kFullTriangleDown);
  tge_ratiopos_dau6088->SetMarkerStyle(kFullDiamond);

  tge_ratiopos_pp->SetMarkerColor(kBlack);
  tge_ratiopos_pp->SetMarkerStyle(kFullCross);

  tge_sysrationeg_dau0020->SetLineColor(kGray);
  tge_sysrationeg_dau2040->SetLineColor(kRed-9);
  tge_sysrationeg_dau0088->SetLineColor(kBlue-9);
  tge_sysrationeg_dau4060->SetLineColor(kGreen-9);
  tge_sysrationeg_dau6088->SetLineColor(kMagenta-9);



  c1_2->cd();
  c1_2->SetLeftMargin(0);
  c1_2->SetTopMargin(0.05);
  c1_2->SetRightMargin(0.15);
  c1_2->SetBottomMargin(0.15);
  c1_2->SetTicks(1,1);
  TMultiGraph *tmgneg2 = new TMultiGraph();
  //tmgneg2->Add(tge_sysrationeg_pp);
  tmgneg2->Add(tge_sysrationeg_dau0088);
  tmgneg2->Add(tge_sysrationeg_dau0020);
  tmgneg2->Add(tge_sysrationeg_dau2040);
  tmgneg2->Add(tge_sysrationeg_dau4060);
  tmgneg2->Add(tge_sysrationeg_dau6088);
  tmgneg2->Add(tge_rationeg_dau0088);
  tmgneg2->Add(tge_rationeg_dau0020);
  tmgneg2->Add(tge_rationeg_dau2040);
  tmgneg2->Add(tge_rationeg_dau4060);
  tmgneg2->Add(tge_rationeg_dau6088);
  tmgneg2->Add(tge_rationeg_pp);
  tmgneg2->Draw("apz");
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
  tmgneg2->SetMaximum(MAX);
  tmgneg2->SetMinimum(0.0);
  tmgneg2->GetXaxis()->SetLimits(0.0,6.0);
  tmgneg2->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgneg2->GetXaxis()->CenterTitle();
  tmgneg2->GetYaxis()->SetTitle("Ratio p/#pi");
  tmgneg2->GetYaxis()->CenterTitle();
  tmgneg2->GetYaxis()->SetTitleOffset(1.5);
  tmgneg2->GetYaxis()->SetNdivisions(505);
  TMultiGraph *tmgneg3 = (TMultiGraph *)tmgneg2->Clone();
  tmgneg2->GetYaxis()->SetTitleSize(0);
  tmgneg2->GetYaxis()->SetLabelSize(0);
  tmgneg2->GetXaxis()->SetTitleSize(0.05);
  tmgneg2->GetXaxis()->SetLabelSize(0.05);
  TLatex *tlneg = new TLatex(0.5,0.85*MAX,"#bar{p}/#pi^{-}");
  tlneg->SetTextSize(0.075);
  tlneg->Draw();

  TLegend *legneg2 = new TLegend(0.12,0.68,0.38,0.88);
  //TLegend *legneg2 = new TLegend(0.33,0.15,0.67,0.35);
  legneg2->SetBorderSize(0);
  legneg2->SetFillColor(kWhite);
  legneg2->AddEntry(tge_rationeg_dau0020,"#bar{p}/#pi^{-} d+Au 0-20%","p");
  legneg2->AddEntry(tge_rationeg_dau2040,"#bar{p}/#pi^{-} d+Au 20-40%","p");
  legneg2->AddEntry(tge_rationeg_dau0088,"#bar{p}/#pi^{-} d+Au 0-88%","p");
  legneg2->AddEntry(tge_rationeg_dau4060,"#bar{p}/#pi^{-} d+Au 40-60%","p");
  legneg2->AddEntry(tge_rationeg_dau6088,"#bar{p}/#pi^{-} d+Au 60-88%","p");
  legneg2->SetTextSize(0.05);
  //legneg2->Draw();

  tge_ratiopos_dau0020->SetTitle("");
  tge_ratiopos_dau2040->SetTitle("");
  tge_ratiopos_dau0088->SetTitle("");
  tge_ratiopos_dau4060->SetTitle("");
  tge_ratiopos_dau6088->SetTitle("");
  tge_ratiopos_pp->SetTitle("");
  TLegend *lg11 = new TLegend(0.22,0.58,0.23,0.88);//adding pp now
  lg11->SetBorderSize(0);
  lg11->SetFillColor(kWhite);
  lg11->AddEntry((TObject*)0,"","");
  lg11->AddEntry(tge_ratiopos_dau0020,"","p");
  lg11->AddEntry(tge_ratiopos_dau2040,"","p");
  lg11->AddEntry(tge_ratiopos_dau0088,"","p");
  lg11->AddEntry(tge_ratiopos_dau4060,"","p");
  lg11->AddEntry(tge_ratiopos_dau6088,"","p");
  lg11->AddEntry(tge_ratiopos_pp,"","p");
  lg11->SetTextSize(0.05);
  //lg11->Draw();
  //TLegend *leg1 = new TLegend(0.38,0.68,0.88,0.88);
  //TLegend *leg1 = new TLegend(0.28,0.68,0.81,0.88);
  //TLegend *leg1 = new TLegend(0.23,0.65,0.78,0.88);
  //TLegend *leg1 = new TLegend(0.23,0.58,0.58,0.88);//adding pp now
  TLegend *leg1 = new TLegend(0.27,0.62,0.62,0.92);//adding pp now
  leg1->SetBorderSize(0);
  leg1->SetFillColor(kWhite);
  leg1->AddEntry((TObject*)0,"d+Au #sqrt{s_{NN}}=200 GeV","");
  leg1->AddEntry(tge_rationeg_dau0020,"0-20%","p");
  leg1->AddEntry(tge_rationeg_dau2040,"20-40%","p");
  //leg1->AddEntry(tge_rationeg_dau0088,"min. bias","p");
  leg1->AddEntry(tge_rationeg_dau0088,"0-100%","p");
  leg1->AddEntry(tge_rationeg_dau4060,"40-60%","p");
  leg1->AddEntry(tge_rationeg_dau6088,"60-88%","p");
  leg1->AddEntry(tge_rationeg_pp,"p+p","p");
  leg1->SetTextSize(0.05);
  leg1->Draw();


  c1->Print("figures/dau_ppi_both.gif");
  c1->Print("figures/dau_ppi_both.eps");


  c1->Clear();
  delete c1;


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
  tmgpos2->GetYaxis()->SetTitleOffset(1.0);
  // tmgpos2->GetYaxis()->SetTitleSize(0.06);
  // tmgpos2->GetYaxis()->SetLabelSize(0.06);
  tmgpos2->GetYaxis()->SetTitleSize(0.0);
  tmgpos2->GetYaxis()->SetLabelSize(0.0);
  tmgpos2->GetXaxis()->SetTitleSize(0.0);
  tmgpos2->GetXaxis()->SetLabelSize(0.0);
  tmgpos2->GetYaxis()->SetNdivisions(505);
  tmgpos2->Draw("apz");
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
  tlpos->Draw();
  //TLatex *tlsys = new TLatex(3.0,1.0,"d+Au #sqrt{s_{NN}} = 200 GeV");
  TLatex *tlsys = new TLatex(3.0,0.85*MAX,"d+Au #sqrt{s_{NN}} = 200 GeV");
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
  tlneg->Draw();
  //TLegend *LEG = new TLegend(0.67,0.58,0.68,0.88);//adding pp now
  TLegend *LEG = new TLegend(0.67,0.62,0.68,0.92);//adding pp now
  LEG->SetBorderSize(0);
  LEG->SetFillColor(kWhite);
  LEG->AddEntry(tge_ratiopos_dau0020,"","p");
  LEG->AddEntry(tge_ratiopos_dau2040,"","p");
  LEG->AddEntry(tge_ratiopos_dau0088,"","p");
  LEG->AddEntry(tge_ratiopos_dau4060,"","p");
  LEG->AddEntry(tge_ratiopos_dau6088,"","p");
  LEG->AddEntry(tge_ratiopos_pp,"","p");
  LEG->SetTextSize(0.06);
  //LEG->Draw();//Jamie Nagle
  //TLegend *LG2 = new TLegend(0.68,0.58,0.88,0.88);//adding pp now
  TLegend *LG2 = new TLegend(0.68,0.62,0.88,0.92);//adding pp now
  LG2->SetBorderSize(0);
  LG2->SetFillColor(kWhite);
  LG2->AddEntry(tge_rationeg_dau0020,"0-20%","p");
  LG2->AddEntry(tge_rationeg_dau2040,"20-40%","p");
  //LG2->AddEntry(tge_rationeg_dau0088,"min. bias","p");
  LG2->AddEntry(tge_rationeg_dau0088,"0-100%","p");
  LG2->AddEntry(tge_rationeg_dau4060,"40-60%","p");
  LG2->AddEntry(tge_rationeg_dau6088,"60-88%","p");
  LG2->AddEntry(tge_rationeg_pp,"p+p","p");
  LG2->SetTextSize(0.06);
  LG2->Draw();
  // TLegend *LEG = new TLegend(0.68,0.58,0.88,0.88);//adding pp now
  // LEG->SetBorderSize(0);
  // LEG->SetFillColor(kWhite);
  // LEG->AddEntry(tge_ratiopos_dau0020,"0-20%","p");
  // LEG->AddEntry(tge_ratiopos_dau2040,"20-40%","p");
  // LEG->AddEntry(tge_ratiopos_dau0088,"min. bias","p");
  // LEG->AddEntry(tge_ratiopos_dau4060,"40-60%","p");
  // LEG->AddEntry(tge_ratiopos_dau6088,"60-88%","p");
  // LEG->AddEntry(tge_ratiopos_pp,"p+p","p");
  // LEG->SetTextSize(0.06);
  // LEG->Draw();
  //legneg1->Draw();

  c2->Print("figures/dau_ppi_voth.gif");
  c2->Print("figures/dau_ppi_voth.eps");


  c2->Clear();
  delete c2;



}
