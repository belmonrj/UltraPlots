void all_ppi()
{



  // ---------- //
  // -- 0010 -- //
  // ---------- //

  float pt_auau0010[36];
  float ept_auau0010[36];
  float ratiopos_auau0010[36];
  float rationeg_auau0010[36];
  float eratiopos_auau0010[36];
  float erationeg_auau0010[36];
  ifstream fauau0010("../Run7AuAu/Ratios/regular/ppi_28_cent0010.txt");
  for(int i=0; i<36; i++)
    {
      fauau0010>>pt_auau0010[i]>>ratiopos_auau0010[i]>>eratiopos_auau0010[i]>>rationeg_auau0010[i]>>erationeg_auau0010[i];
      ept_auau0010[i]=0;
    }
  TGraphErrors *tge_ratiopos_auau0010 = new TGraphErrors(36,pt_auau0010,ratiopos_auau0010,ept_auau0010,eratiopos_auau0010);
  tge_ratiopos_auau0010->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau0010->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau0010 = new TGraphErrors(36,pt_auau0010,rationeg_auau0010,ept_auau0010,erationeg_auau0010);
  tge_rationeg_auau0010->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau0010->SetMarkerColor(kBlue);

  // ---------- //
  // -- 1020 -- //
  // ---------- //
  float pt_auau1020[36];
  float ept_auau1020[36];
  float ratiopos_auau1020[36];
  float rationeg_auau1020[36];
  float eratiopos_auau1020[36];
  float erationeg_auau1020[36];
  ifstream fauau1020("../Run7AuAu/Ratios/regular/ppi_28_cent1020.txt");
  for(int i=0; i<36; i++)
    {
      fauau1020>>pt_auau1020[i]>>ratiopos_auau1020[i]>>eratiopos_auau1020[i]>>rationeg_auau1020[i]>>erationeg_auau1020[i];
      ept_auau1020[i]=0;
    }
  TGraphErrors *tge_ratiopos_auau1020 = new TGraphErrors(36,pt_auau1020,ratiopos_auau1020,ept_auau1020,eratiopos_auau1020);
  tge_ratiopos_auau1020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau1020->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau1020 = new TGraphErrors(36,pt_auau1020,rationeg_auau1020,ept_auau1020,erationeg_auau1020);
  tge_rationeg_auau1020->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau1020->SetMarkerColor(kBlue);

  // ---------- //
  // -- 2040 -- //
  // ---------- //

  float pt_auau2040[36];
  float ept_auau2040[36];
  float ratiopos_auau2040[36];
  float rationeg_auau2040[36];
  float eratiopos_auau2040[36];
  float erationeg_auau2040[36];
  ifstream fauau2040("../Run7AuAu/Ratios/regular/ppi_28_cent2040.txt");
  for(int i=0; i<36; i++)
    {
      fauau2040>>pt_auau2040[i]>>ratiopos_auau2040[i]>>eratiopos_auau2040[i]>>rationeg_auau2040[i]>>erationeg_auau2040[i];
      ept_auau2040[i]=0;
    }
  TGraphErrors *tge_ratiopos_auau2040 = new TGraphErrors(36,pt_auau2040,ratiopos_auau2040,ept_auau2040,eratiopos_auau2040);
  tge_ratiopos_auau2040->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau2040->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau2040 = new TGraphErrors(36,pt_auau2040,rationeg_auau2040,ept_auau2040,erationeg_auau2040);
  tge_rationeg_auau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau2040->SetMarkerColor(kBlue);

  // ---------- //
  // -- 4060 -- //
  // ---------- //

  float pt_auau4060[36];
  float ept_auau4060[36];
  float ratiopos_auau4060[36];
  float rationeg_auau4060[36];
  float eratiopos_auau4060[36];
  float erationeg_auau4060[36];
  ifstream fauau4060("../Run7AuAu/Ratios/regular/ppi_28_cent4060.txt");
  for(int i=0; i<36; i++)
    {
      fauau4060>>pt_auau4060[i]>>ratiopos_auau4060[i]>>eratiopos_auau4060[i]>>rationeg_auau4060[i]>>erationeg_auau4060[i];
      ept_auau4060[i]=0;
    }
  TGraphErrors *tge_ratiopos_auau4060 = new TGraphErrors(36,pt_auau4060,ratiopos_auau4060,ept_auau4060,eratiopos_auau4060);
  tge_ratiopos_auau4060->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau4060->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau4060 = new TGraphErrors(36,pt_auau4060,rationeg_auau4060,ept_auau4060,erationeg_auau4060);
  tge_rationeg_auau4060->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau4060->SetMarkerColor(kBlue);

  // ---------- //
  // -- 6092 -- //
  // ---------- //

  float pt_auau6092[36];
  float ept_auau6092[36];
  float ratiopos_auau6092[36];
  float rationeg_auau6092[36];
  float eratiopos_auau6092[36];
  float erationeg_auau6092[36];
  ifstream fauau6092("../Run7AuAu/Ratios/regular/ppi_28_cent6092.txt");
  for(int i=0; i<36; i++)
    {
      fauau6092>>pt_auau6092[i]>>ratiopos_auau6092[i]>>eratiopos_auau6092[i]>>rationeg_auau6092[i]>>erationeg_auau6092[i];
      ept_auau6092[i]=0;
    }
  TGraphErrors *tge_ratiopos_auau6092 = new TGraphErrors(36,pt_auau6092,ratiopos_auau6092,ept_auau6092,eratiopos_auau6092);
  tge_ratiopos_auau6092->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau6092->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau6092 = new TGraphErrors(36,pt_auau6092,rationeg_auau6092,ept_auau6092,erationeg_auau6092);
  tge_rationeg_auau6092->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau6092->SetMarkerColor(kBlue);






  // ---
  // ---
  // --- COME BACK HERE


  // ---------- //
  // -- 0088 -- //
  // ---------- //

  float pt_dau0088[36];
  float ept_dau0088[36];
  float ratiopos_dau0088[36];
  float rationeg_dau0088[36];
  float eratiopos_dau0088[36];
  float erationeg_dau0088[36];
  ifstream fdau0088("../Run8dAu/Ratios/regular/ppi_15_cent0088.txt");
  for(int i=0; i<36; i++)
    {
      fdau0088>>pt_dau0088[i]>>ratiopos_dau0088[i]>>eratiopos_dau0088[i]>>rationeg_dau0088[i]>>erationeg_dau0088[i];
      ept_dau0088[i]=0;
    }
  TGraphErrors *tge_ratiopos_dau0088 = new TGraphErrors(36,pt_dau0088,ratiopos_dau0088,ept_dau0088,eratiopos_dau0088);
  tge_ratiopos_dau0088->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau0088->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau0088 = new TGraphErrors(36,pt_dau0088,rationeg_dau0088,ept_dau0088,erationeg_dau0088);
  tge_rationeg_dau0088->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0088->SetMarkerColor(kBlue);

  // ---------- //
  // -- 0020 -- //
  // ---------- //
  float pt_dau0020[36];
  float ept_dau0020[36];
  float ratiopos_dau0020[36];
  float rationeg_dau0020[36];
  float eratiopos_dau0020[36];
  float erationeg_dau0020[36];
  ifstream fdau0020("../Run8dAu/Ratios/regular/ppi_15_cent0020.txt");
  for(int i=0; i<36; i++)
    {
      fdau0020>>pt_dau0020[i]>>ratiopos_dau0020[i]>>eratiopos_dau0020[i]>>rationeg_dau0020[i]>>erationeg_dau0020[i];
      ept_dau0020[i]=0;
    }
  TGraphErrors *tge_ratiopos_dau0020 = new TGraphErrors(36,pt_dau0020,ratiopos_dau0020,ept_dau0020,eratiopos_dau0020);
  tge_ratiopos_dau0020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau0020->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau0020 = new TGraphErrors(36,pt_dau0020,rationeg_dau0020,ept_dau0020,erationeg_dau0020);
  tge_rationeg_dau0020->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau0020->SetMarkerColor(kBlue);

  // ---------- //
  // -- 2040 -- //
  // ---------- //

  float pt_dau2040[36];
  float ept_dau2040[36];
  float ratiopos_dau2040[36];
  float rationeg_dau2040[36];
  float eratiopos_dau2040[36];
  float erationeg_dau2040[36];
  ifstream fdau2040("../Run8dAu/Ratios/regular/ppi_15_cent2040.txt");
  for(int i=0; i<36; i++)
    {
      fdau2040>>pt_dau2040[i]>>ratiopos_dau2040[i]>>eratiopos_dau2040[i]>>rationeg_dau2040[i]>>erationeg_dau2040[i];
      ept_dau2040[i]=0;
    }
  TGraphErrors *tge_ratiopos_dau2040 = new TGraphErrors(36,pt_dau2040,ratiopos_dau2040,ept_dau2040,eratiopos_dau2040);
  tge_ratiopos_dau2040->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau2040->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau2040 = new TGraphErrors(36,pt_dau2040,rationeg_dau2040,ept_dau2040,erationeg_dau2040);
  tge_rationeg_dau2040->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau2040->SetMarkerColor(kBlue);

  // ---------- //
  // -- 4060 -- //
  // ---------- //

  float pt_dau4060[36];
  float ept_dau4060[36];
  float ratiopos_dau4060[36];
  float rationeg_dau4060[36];
  float eratiopos_dau4060[36];
  float erationeg_dau4060[36];
  ifstream fdau4060("../Run8dAu/Ratios/regular/ppi_15_cent4060.txt");
  for(int i=0; i<36; i++)
    {
      fdau4060>>pt_dau4060[i]>>ratiopos_dau4060[i]>>eratiopos_dau4060[i]>>rationeg_dau4060[i]>>erationeg_dau4060[i];
      ept_dau4060[i]=0;
    }
  TGraphErrors *tge_ratiopos_dau4060 = new TGraphErrors(36,pt_dau4060,ratiopos_dau4060,ept_dau4060,eratiopos_dau4060);
  tge_ratiopos_dau4060->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau4060->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau4060 = new TGraphErrors(36,pt_dau4060,rationeg_dau4060,ept_dau4060,erationeg_dau4060);
  tge_rationeg_dau4060->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau4060->SetMarkerColor(kBlue);

  // ---------- //
  // -- 6088 -- //
  // ---------- //

  float pt_dau6088[36];
  float ept_dau6088[36];
  float ratiopos_dau6088[36];
  float rationeg_dau6088[36];
  float eratiopos_dau6088[36];
  float erationeg_dau6088[36];
  ifstream fdau6088("../Run8dAu/Ratios/regular/ppi_15_cent6088.txt");
  for(int i=0; i<36; i++)
    {
      fdau6088>>pt_dau6088[i]>>ratiopos_dau6088[i]>>eratiopos_dau6088[i]>>rationeg_dau6088[i]>>erationeg_dau6088[i];
      ept_dau6088[i]=0;
    }
  TGraphErrors *tge_ratiopos_dau6088 = new TGraphErrors(36,pt_dau6088,ratiopos_dau6088,ept_dau6088,eratiopos_dau6088);
  tge_ratiopos_dau6088->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau6088->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_dau6088 = new TGraphErrors(36,pt_dau6088,rationeg_dau6088,ept_dau6088,erationeg_dau6088);
  tge_rationeg_dau6088->SetMarkerStyle(kFullSquare);
  tge_rationeg_dau6088->SetMarkerColor(kBlue);


  // ---
  // ---
  // --- daudaudaudaudaudaudaudaudaudaudaudaudaudaudaudaudaudaudaudaudauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau
  // --- auauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauauau



  tge_ratiopos_auau0010->SetMarkerColor(kBlack);
  tge_ratiopos_auau1020->SetMarkerColor(kBlack);
  tge_ratiopos_auau2040->SetMarkerColor(kBlack);
  tge_ratiopos_auau4060->SetMarkerColor(kBlack);
  tge_ratiopos_auau6092->SetMarkerColor(kBlack);

  tge_ratiopos_auau0010->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau1020->SetMarkerStyle(kFullSquare);
  tge_ratiopos_auau2040->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_auau4060->SetMarkerStyle(kFullTriangleDown);
  tge_ratiopos_auau6092->SetMarkerStyle(kFullDiamond);


  tge_ratiopos_dau0020->SetMarkerColor(kBlack);
  tge_ratiopos_dau2040->SetMarkerColor(kBlack);
  tge_ratiopos_dau0088->SetMarkerColor(kBlack);
  tge_ratiopos_dau4060->SetMarkerColor(kBlack);
  tge_ratiopos_dau6088->SetMarkerColor(kBlack);

  tge_ratiopos_dau0020->SetMarkerStyle(kOpenCircle);
  tge_ratiopos_dau2040->SetMarkerStyle(kOpenSquare);
  tge_ratiopos_dau0088->SetMarkerStyle(kOpenTriangleUp);
  tge_ratiopos_dau4060->SetMarkerStyle(kOpenTriangleDown);
  tge_ratiopos_dau6088->SetMarkerStyle(kOpenDiamond);


  TMultiGraph *tmgpos1 = new TMultiGraph();
  tmgpos1->Add(tge_ratiopos_auau0010);
  tmgpos1->Add(tge_ratiopos_auau1020);
  tmgpos1->Add(tge_ratiopos_auau2040);
  tmgpos1->Add(tge_ratiopos_auau4060);
  tmgpos1->Add(tge_ratiopos_auau6092);
  // tmgpos1->Add(tge_ratiopos_dau0088);
  // tmgpos1->Add(tge_ratiopos_dau0020);
  // tmgpos1->Add(tge_ratiopos_dau2040);
  // tmgpos1->Add(tge_ratiopos_dau4060);
  // tmgpos1->Add(tge_ratiopos_dau6088);
  tmgpos1->Draw("ap");
  tmgpos1->SetMaximum(1.0);
  tmgpos1->SetMinimum(0.0);
  tmgpos1->GetXaxis()->SetLimits(0.0,6.0);
  tmgpos1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgpos1->GetXaxis()->CenterTitle();
  tmgpos1->GetYaxis()->SetTitle("Ratio p/#pi");
  tmgpos1->GetYaxis()->CenterTitle();

  TLegend *legpos1 = new TLegend(0.12,0.68,0.38,0.88);
  legpos1->SetBorderSize(0);
  legpos1->SetFillColor(kWhite);
  legpos1->AddEntry(tge_ratiopos_auau0010,"p/#pi^{+} Au+Au 0-10%","p");
  legpos1->AddEntry(tge_ratiopos_auau1020,"p/#pi^{+} Au+Au 10-20%","p");
  legpos1->AddEntry(tge_ratiopos_auau2040,"p/#pi^{+} Au+Au 20-40%","p");
  legpos1->AddEntry(tge_ratiopos_auau4060,"p/#pi^{+} Au+Au 40-60%","p");
  legpos1->AddEntry(tge_ratiopos_auau6092,"p/#pi^{+} Au+Au 60-92%","p");
  legpos1->Draw();











}
