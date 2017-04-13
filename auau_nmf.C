void auau_nmf()
{

  doit(2,4,8,16,33,false);

}

void doit(int pi7pid=1, int ka7pid=3, int pr7pid=5, int numberK=16, int numberP=33, bool chavers=false)
{

  float sysvalue = 0.05;

  char filename[100];

  float pt_sys1[1] = {5.5};
  float ept_sys1[1] = {0.0};
  float point_sys1[1] = {1.0};
  float epoint_sys1[1] = {0.05};
  TGraphErrors *tge_sys1 = new TGraphErrors(1,pt_sys1,point_sys1,ept_sys1,epoint_sys1);
  tge_sys1->SetMarkerStyle(1);
  tge_sys1->SetMarkerColor(kGray);
  tge_sys1->SetLineWidth(15);
  tge_sys1->SetLineColor(kGray);

  float pt_sys4[1] = {5.5};
  float ept_sys4[1] = {0.0};
  float point_sys4[1] = {1.0};
  float epoint_sys4[1] = {0.01};
  TGraphErrors *tge_sys4 = new TGraphErrors(1,pt_sys4,point_sys4,ept_sys4,epoint_sys4);
  tge_sys4->SetMarkerStyle(1);
  tge_sys4->SetMarkerColor(kGray);
  tge_sys4->SetLineWidth(15);
  tge_sys4->SetLineColor(kGray);

  float pt_sys2[1] = {5.7};
  float ept_sys2[1] = {0.0};
  float point_sys2[1] = {1.0};
  float epoint_sys2[1] = {0.09};
  TGraphErrors *tge_sys2 = new TGraphErrors(1,pt_sys2,point_sys2,ept_sys2,epoint_sys2);
  tge_sys2->SetMarkerStyle(1);
  tge_sys2->SetMarkerColor(kGray+2);
  tge_sys2->SetLineWidth(15);
  tge_sys2->SetLineColor(kGray+2);


  float pt_sys3[1] = {5.7};
  float ept_sys3[1] = {0.0};
  float point_sys3[1] = {1.0};
  float epoint_sys3[1] = {0.065};
  TGraphErrors *tge_sys3 = new TGraphErrors(1,pt_sys3,point_sys3,ept_sys3,epoint_sys3);
  tge_sys3->SetMarkerStyle(1);
  tge_sys3->SetMarkerColor(kGray+2);
  tge_sys3->SetLineWidth(15);
  tge_sys3->SetLineColor(kGray+2);


  // --------- //
  // -- RAA -- //
  // --------- //



  // --

  float ptpion_RAA[36];
  float eptpion_RAA[36];
  float pionpos_RAA[36];
  float pionneg_RAA[36];
  float epionpos_RAA[36];
  float epionneg_RAA[36];
  float esyspionpos_RAA[36];
  float esyspionneg_RAA[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent0010.txt",pi7pid);
  ifstream fRAA(filename);
  for(int i=0; i<36; i++)
    {
      fRAA>>ptpion_RAA[i]>>pionpos_RAA[i]>>epionpos_RAA[i]>>pionneg_RAA[i]>>epionneg_RAA[i];
      eptpion_RAA[i]=0;
      if(chavers)
	{
	  pionpos_RAA[i] += pionneg_RAA[i];
	  pionpos_RAA[i] /= 2.0;
	  epionpos_RAA[i] = sqrt(epionpos_RAA[i]**2+epionneg_RAA[i]**2)/2.0;
	}
      sysvalue = 0.1; // for RAA
      esyspionpos_RAA[i] = sysvalue*pionpos_RAA[i];
      esyspionneg_RAA[i] = sysvalue*pionneg_RAA[i];
    }
  fRAA.close();
  TGraphErrors *tge_pionpos_RAA = new TGraphErrors(27,ptpion_RAA,pionpos_RAA,eptpion_RAA,epionpos_RAA);
  TGraphErrors *tge_pionneg_RAA = new TGraphErrors(27,ptpion_RAA,pionneg_RAA,eptpion_RAA,epionneg_RAA);

  TGraphErrors *tge_syspionpos_RAA = new TGraphErrors(27,ptpion_RAA,pionpos_RAA,eptpion_RAA,esyspionpos_RAA);
  tge_syspionpos_RAA->SetMarkerStyle(1);
  tge_syspionpos_RAA->SetMarkerColor(kGray);
  tge_syspionpos_RAA->SetFillColor(kGray);
  tge_syspionpos_RAA->SetLineColor(kGray);
  tge_syspionpos_RAA->SetLineWidth(15);
  TGraphErrors *tge_syspionneg_RAA = new TGraphErrors(27,ptpion_RAA,pionneg_RAA,eptpion_RAA,esyspionneg_RAA);
  tge_syspionneg_RAA->SetMarkerStyle(1);
  tge_syspionneg_RAA->SetMarkerColor(kGray);
  tge_syspionneg_RAA->SetFillColor(kGray);
  tge_syspionneg_RAA->SetLineColor(kGray);
  tge_syspionneg_RAA->SetLineWidth(15);

  // -- PROTON!!!

  float ptproton_RAA[36];
  float eptproton_RAA[36];
  float protonpos_RAA[36];
  float protonneg_RAA[36];
  float eprotonpos_RAA[36];
  float eprotonneg_RAA[36];
  float esysprotonpos_RAA[36];
  float esysprotonneg_RAA[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent0010.txt",pr7pid);
  fRAA.open(filename);
  //cout<<"filename is "<<filename<<endl;
  for(int i=0; i<36; i++)
    {
      fRAA>>ptproton_RAA[i]>>protonpos_RAA[i]>>eprotonpos_RAA[i]>>protonneg_RAA[i]>>eprotonneg_RAA[i];
      eptproton_RAA[i]=0;
      //cout<<"info "<<protonpos_RAA[i]<<endl;
      if(chavers)
	{
	  protonpos_RAA[i] += protonneg_RAA[i];
	  protonpos_RAA[i] /= 2.0;
	  eprotonpos_RAA[i] = sqrt(eprotonpos_RAA[i]**2+eprotonneg_RAA[i]**2)/2.0;
	}
      sysvalue = 0.1; // for RAA
      esysprotonpos_RAA[i] = sysvalue*protonpos_RAA[i];
      esysprotonneg_RAA[i] = sysvalue*protonneg_RAA[i];
    }
  fRAA.close();

  TGraphErrors *tge_protonpos_RAA = new TGraphErrors(numberP,ptproton_RAA,protonpos_RAA,eptproton_RAA,eprotonpos_RAA);
  TGraphErrors *tge_protonneg_RAA = new TGraphErrors(numberP,ptproton_RAA,protonneg_RAA,eptproton_RAA,eprotonneg_RAA);

  TGraphErrors *tge_sysprotonpos_RAA = new TGraphErrors(numberP,ptproton_RAA,protonpos_RAA,eptproton_RAA,esysprotonpos_RAA);
  tge_sysprotonpos_RAA->SetMarkerStyle(1);
  tge_sysprotonpos_RAA->SetMarkerColor(kGray);
  tge_sysprotonpos_RAA->SetFillColor(kGray);
  tge_sysprotonpos_RAA->SetLineColor(kGray);
  tge_sysprotonpos_RAA->SetLineWidth(15);
  TGraphErrors *tge_sysprotonneg_RAA = new TGraphErrors(numberP,ptproton_RAA,protonneg_RAA,eptproton_RAA,esysprotonneg_RAA);
  tge_sysprotonneg_RAA->SetMarkerStyle(1);
  tge_sysprotonneg_RAA->SetMarkerColor(kGray);
  tge_sysprotonneg_RAA->SetFillColor(kGray);
  tge_sysprotonneg_RAA->SetLineColor(kGray);
  tge_sysprotonneg_RAA->SetLineWidth(15);



  // -- KAON!!!

  float ptkaon_RAA[36];
  float eptkaon_RAA[36];
  float kaonpos_RAA[36];
  float kaonneg_RAA[36];
  float ekaonpos_RAA[36];
  float ekaonneg_RAA[36];
  float esyskaonpos_RAA[36];
  float esyskaonneg_RAA[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/raa_%d_cent0010.txt",ka7pid);
  fRAA.open(filename);
  //cout<<"filename is "<<filename<<endl;
  for(int i=0; i<36; i++)
    {
      fRAA>>ptkaon_RAA[i]>>kaonpos_RAA[i]>>ekaonpos_RAA[i]>>kaonneg_RAA[i]>>ekaonneg_RAA[i];
      eptkaon_RAA[i]=0;
      //cout<<"info "<<kaonpos_RAA[i]<<endl;
      if(chavers)
	{
	  kaonpos_RAA[i] += kaonneg_RAA[i];
	  kaonpos_RAA[i] /= 2.0;
	  ekaonpos_RAA[i] = sqrt(ekaonpos_RAA[i]**2+ekaonneg_RAA[i]**2)/2.0;
	}
      sysvalue = 0.1; // for RAA
      esyskaonpos_RAA[i] = sysvalue*kaonpos_RAA[i];
      esyskaonneg_RAA[i] = sysvalue*kaonneg_RAA[i];
    }
  fRAA.close();

  TGraphErrors *tge_kaonpos_RAA = new TGraphErrors(numberK,ptkaon_RAA,kaonpos_RAA,eptkaon_RAA,ekaonpos_RAA);
  TGraphErrors *tge_kaonneg_RAA = new TGraphErrors(numberK,ptkaon_RAA,kaonneg_RAA,eptkaon_RAA,ekaonneg_RAA);

  TGraphErrors *tge_syskaonpos_RAA = new TGraphErrors(numberK,ptkaon_RAA,kaonpos_RAA,eptkaon_RAA,esyskaonpos_RAA);
  tge_syskaonpos_RAA->SetMarkerStyle(1);
  tge_syskaonpos_RAA->SetMarkerColor(kGray);
  tge_syskaonpos_RAA->SetFillColor(kGray);
  tge_syskaonpos_RAA->SetLineColor(kGray);
  tge_syskaonpos_RAA->SetLineWidth(15);
  TGraphErrors *tge_syskaonneg_RAA = new TGraphErrors(numberK,ptkaon_RAA,kaonneg_RAA,eptkaon_RAA,esyskaonneg_RAA);
  tge_syskaonneg_RAA->SetMarkerStyle(1);
  tge_syskaonneg_RAA->SetMarkerColor(kGray);
  tge_syskaonneg_RAA->SetFillColor(kGray);
  tge_syskaonneg_RAA->SetLineColor(kGray);
  tge_syskaonneg_RAA->SetLineWidth(15);





  // --------- //
  // -- RCP -- //
  // --------- //

  float pt_RCP[36];
  float ept_RCP[36];

  // --

  float pionpos_RCP[36];
  float pionneg_RCP[36];
  float epionpos_RCP[36];
  float epionneg_RCP[36];
  float esyspionpos_RCP[36];
  float esyspionneg_RCP[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d.txt",pi7pid);
  ifstream fRCP(filename);
  for(int i=0; i<36; i++)
    {
      fRCP>>pt_RCP[i]>>pionpos_RCP[i]>>epionpos_RCP[i]>>pionneg_RCP[i]>>epionneg_RCP[i];
      ept_RCP[i]=0;
      if(i<5)
	{
	  pionpos_RCP[i] = -9;
	  pionneg_RCP[i] = -9;
	}
      if(chavers)
	{
	  pionpos_RCP[i] += pionneg_RCP[i];
	  pionpos_RCP[i] /= 2.0;
	  epionpos_RCP[i] = sqrt(epionpos_RCP[i]**2+epionneg_RCP[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP
      esyspionpos_RCP[i] = sysvalue*pionpos_RCP[i];
      esyspionneg_RCP[i] = sysvalue*pionneg_RCP[i];
    }

  TGraphErrors *tge_pionpos_RCP = new TGraphErrors(36,pt_RCP,pionpos_RCP,ept_RCP,epionpos_RCP);
  TGraphErrors *tge_pionneg_RCP = new TGraphErrors(36,pt_RCP,pionneg_RCP,ept_RCP,epionneg_RCP);

  TGraphErrors *tge_syspionpos_RCP = new TGraphErrors(36,pt_RCP,pionpos_RCP,ept_RCP,esyspionpos_RCP);
  tge_syspionpos_RCP->SetMarkerStyle(1);
  tge_syspionpos_RCP->SetMarkerColor(kGray);
  tge_syspionpos_RCP->SetFillColor(kGray);
  tge_syspionpos_RCP->SetLineColor(kGray);
  tge_syspionpos_RCP->SetLineWidth(15);
  TGraphErrors *tge_syspionneg_RCP = new TGraphErrors(36,pt_RCP,pionneg_RCP,ept_RCP,esyspionneg_RCP);
  tge_syspionneg_RCP->SetMarkerStyle(1);
  tge_syspionneg_RCP->SetMarkerColor(kGray);
  tge_syspionneg_RCP->SetFillColor(kGray);
  tge_syspionneg_RCP->SetLineColor(kGray);
  tge_syspionneg_RCP->SetLineWidth(15);

  // -- KAON!!!

  float kaonpos_RCP[36];
  float kaonneg_RCP[36];
  float ekaonpos_RCP[36];
  float ekaonneg_RCP[36];
  float esyskaonpos_RCP[36];
  float esyskaonneg_RCP[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d.txt",ka7pid);
  ifstream fRCP(filename);
  for(int i=0; i<36; i++)
    {
      fRCP>>pt_RCP[i]>>kaonpos_RCP[i]>>ekaonpos_RCP[i]>>kaonneg_RCP[i]>>ekaonneg_RCP[i];
      ept_RCP[i]=0;
      if(i<5)
	{
	  kaonpos_RCP[i] = -9;
	  kaonneg_RCP[i] = -9;
	}
      if(chavers)
	{
	  kaonpos_RCP[i] += kaonneg_RCP[i];
	  kaonpos_RCP[i] /= 2.0;
	  ekaonpos_RCP[i] = sqrt(ekaonpos_RCP[i]**2+ekaonneg_RCP[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP
      esyskaonpos_RCP[i] = sysvalue*kaonpos_RCP[i];
      esyskaonneg_RCP[i] = sysvalue*kaonneg_RCP[i];
    }
  TGraphErrors *tge_kaonpos_RCP = new TGraphErrors(36,pt_RCP,kaonpos_RCP,ept_RCP,ekaonpos_RCP);
  TGraphErrors *tge_kaonneg_RCP = new TGraphErrors(36,pt_RCP,kaonneg_RCP,ept_RCP,ekaonneg_RCP);

  TGraphErrors *tge_syskaonpos_RCP = new TGraphErrors(36,pt_RCP,kaonpos_RCP,ept_RCP,esyskaonpos_RCP);
  tge_syskaonpos_RCP->SetMarkerStyle(1);
  tge_syskaonpos_RCP->SetMarkerColor(kGray);
  tge_syskaonpos_RCP->SetFillColor(kGray);
  tge_syskaonpos_RCP->SetLineColor(kGray);
  tge_syskaonpos_RCP->SetLineWidth(15);
  TGraphErrors *tge_syskaonneg_RCP = new TGraphErrors(36,pt_RCP,kaonneg_RCP,ept_RCP,esyskaonneg_RCP);
  tge_syskaonneg_RCP->SetMarkerStyle(1);
  tge_syskaonneg_RCP->SetMarkerColor(kGray);
  tge_syskaonneg_RCP->SetFillColor(kGray);
  tge_syskaonneg_RCP->SetLineColor(kGray);
  tge_syskaonneg_RCP->SetLineWidth(15);




  // -- PROTON!!!

  float protonpos_RCP[36];
  float protonneg_RCP[36];
  float eprotonpos_RCP[36];
  float eprotonneg_RCP[36];
  float esysprotonpos_RCP[36];
  float esysprotonneg_RCP[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d.txt",pr7pid);
  ifstream fRCP(filename);
  for(int i=0; i<36; i++)
    {
      fRCP>>pt_RCP[i]>>protonpos_RCP[i]>>eprotonpos_RCP[i]>>protonneg_RCP[i]>>eprotonneg_RCP[i];
      ept_RCP[i]=0;
      if(i<5)
	{
	  protonpos_RCP[i] = -9;
	  protonneg_RCP[i] = -9;
	}
      if(chavers)
	{
	  protonpos_RCP[i] += protonneg_RCP[i];
	  protonpos_RCP[i] /= 2.0;
	  eprotonpos_RCP[i] = sqrt(eprotonpos_RCP[i]**2+eprotonneg_RCP[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP
      esysprotonpos_RCP[i] = sysvalue*protonpos_RCP[i];
      esysprotonneg_RCP[i] = sysvalue*protonneg_RCP[i];
    }

  TGraphErrors *tge_protonpos_RCP = new TGraphErrors(36,pt_RCP,protonpos_RCP,ept_RCP,eprotonpos_RCP);
  TGraphErrors *tge_protonneg_RCP = new TGraphErrors(36,pt_RCP,protonneg_RCP,ept_RCP,eprotonneg_RCP);

  TGraphErrors *tge_sysprotonpos_RCP = new TGraphErrors(36,pt_RCP,protonpos_RCP,ept_RCP,esysprotonpos_RCP);
  tge_sysprotonpos_RCP->SetMarkerStyle(1);
  tge_sysprotonpos_RCP->SetMarkerColor(kGray);
  tge_sysprotonpos_RCP->SetFillColor(kGray);
  tge_sysprotonpos_RCP->SetLineColor(kGray);
  tge_sysprotonpos_RCP->SetLineWidth(15);
  TGraphErrors *tge_sysprotonneg_RCP = new TGraphErrors(36,pt_RCP,protonneg_RCP,ept_RCP,esysprotonneg_RCP);
  tge_sysprotonneg_RCP->SetMarkerStyle(1);
  tge_sysprotonneg_RCP->SetMarkerColor(kGray);
  tge_sysprotonneg_RCP->SetFillColor(kGray);
  tge_sysprotonneg_RCP->SetLineColor(kGray);
  tge_sysprotonneg_RCP->SetLineWidth(15);



  // ---
  // --- set colors and shapes
  // ---

  tge_pionpos_RAA->SetMarkerStyle(kFullCircle);
  tge_pionneg_RAA->SetMarkerStyle(kFullCircle);
  tge_kaonpos_RAA->SetMarkerStyle(kFullTriangleUp);
  tge_kaonneg_RAA->SetMarkerStyle(kFullTriangleUp);
  tge_protonpos_RAA->SetMarkerStyle(kFullSquare);
  tge_protonneg_RAA->SetMarkerStyle(kFullSquare);

  tge_pionpos_RAA->SetMarkerColor(kRed);
  tge_pionneg_RAA->SetMarkerColor(kBlue);
  tge_kaonpos_RAA->SetMarkerColor(kRed);
  tge_kaonneg_RAA->SetMarkerColor(kBlue);
  tge_protonpos_RAA->SetMarkerColor(kRed);
  tge_protonneg_RAA->SetMarkerColor(kBlue);

  tge_pionpos_RCP->SetMarkerStyle(kFullCircle);
  tge_pionneg_RCP->SetMarkerStyle(kFullCircle);
  tge_kaonpos_RCP->SetMarkerStyle(kFullTriangleUp);
  tge_kaonneg_RCP->SetMarkerStyle(kFullTriangleUp);
  tge_protonpos_RCP->SetMarkerStyle(kFullSquare);
  tge_protonneg_RCP->SetMarkerStyle(kFullSquare);

  tge_pionpos_RCP->SetMarkerColor(kRed);
  tge_pionneg_RCP->SetMarkerColor(kBlue);
  tge_kaonpos_RCP->SetMarkerColor(kRed);
  tge_kaonneg_RCP->SetMarkerColor(kBlue);
  tge_protonpos_RCP->SetMarkerColor(kRed);
  tge_protonneg_RCP->SetMarkerColor(kBlue);

  // ---

  tge_pionpos_RAA->SetMarkerStyle(kFullCircle);
  tge_pionneg_RAA->SetMarkerStyle(kOpenCircle);
  tge_kaonpos_RAA->SetMarkerStyle(kFullTriangleUp);
  tge_kaonneg_RAA->SetMarkerStyle(kOpenTriangleUp);
  tge_protonpos_RAA->SetMarkerStyle(kFullSquare);
  tge_protonneg_RAA->SetMarkerStyle(kOpenSquare);

  tge_pionpos_RAA->SetMarkerColor(kRed);
  tge_pionneg_RAA->SetMarkerColor(kRed);
  tge_kaonpos_RAA->SetMarkerColor(kGreen+2);
  tge_kaonneg_RAA->SetMarkerColor(kGreen+2);
  tge_protonpos_RAA->SetMarkerColor(kBlue);
  tge_protonneg_RAA->SetMarkerColor(kBlue);

  tge_pionpos_RCP->SetMarkerStyle(kFullCircle);
  tge_pionneg_RCP->SetMarkerStyle(kOpenCircle);
  tge_kaonpos_RCP->SetMarkerStyle(kFullTriangleUp);
  tge_kaonneg_RCP->SetMarkerStyle(kOpenTriangleUp);
  tge_protonpos_RCP->SetMarkerStyle(kFullSquare);
  tge_protonneg_RCP->SetMarkerStyle(kOpenSquare);

  tge_pionpos_RCP->SetMarkerColor(kRed);
  tge_pionneg_RCP->SetMarkerColor(kRed);
  tge_kaonpos_RCP->SetMarkerColor(kGreen+2);
  tge_kaonneg_RCP->SetMarkerColor(kGreen+2);
  tge_protonpos_RCP->SetMarkerColor(kBlue);
  tge_protonneg_RCP->SetMarkerColor(kBlue);

  // ---
  // --- draw
  // ---



  TCanvas *c1 = new TCanvas("c1","",1200,500);
  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.0,0.5,1.0);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",0.5,0.0,1.0,1.0);
  c1_2->Draw();
  c1->cd();

  c1_1->SetRightMargin(0);
  c1_2->SetLeftMargin(0);
  c1_1->SetTopMargin(0.05);
  c1_2->SetTopMargin(0.05);
  c1_1->SetTicks(1,1);
  c1_2->SetTicks(1,1);



  c1_1->cd();
  TMultiGraph *tmg_raa = new TMultiGraph();
  //tmg_raa->Add(tge_sys4);
  tmg_raa->Add(tge_sys3);
  tmg_raa->Add(tge_syspionpos_RAA);
  tmg_raa->Add(tge_syspionneg_RAA);
  tmg_raa->Add(tge_syskaonpos_RAA);
  tmg_raa->Add(tge_syskaonneg_RAA);
  tmg_raa->Add(tge_sysprotonpos_RAA);
  tmg_raa->Add(tge_sysprotonneg_RAA);
  tmg_raa->Add(tge_pionpos_RAA);
  tmg_raa->Add(tge_pionneg_RAA);
  tmg_raa->Add(tge_kaonpos_RAA);
  tmg_raa->Add(tge_kaonneg_RAA);
  tmg_raa->Add(tge_protonpos_RAA);
  tmg_raa->Add(tge_protonneg_RAA);
  tmg_raa->Draw("apz");
  tmg_raa->SetMaximum(2.0);
  tmg_raa->SetMinimum(0.0);
  tmg_raa->GetXaxis()->SetLimits(0.0,6.0);
  TLine *line_raa = new TLine(0.0,1.0,6.0,1.0);
  line_raa->Draw();
  tmg_raa->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_raa->GetXaxis()->CenterTitle();
  tmg_raa->GetYaxis()->SetTitle("Nuclear Modification Factor");
  //tmg_raa->GetYaxis()->SetTitle("R_{dA}");
  tmg_raa->GetYaxis()->CenterTitle();
  //tmg_raa->GetYaxis()->SetTitleOffset(1.5);
  tmg_raa->GetYaxis()->SetTitleSize(0.04);
  tmg_raa->GetYaxis()->SetLabelSize(0.04);
  tmg_raa->GetXaxis()->SetTitleSize(0.04);
  tmg_raa->GetXaxis()->SetLabelSize(0.04);
  TLegend *leg_raa = new TLegend(0.87,0.58,0.95,0.88);
  leg_raa->SetBorderSize(0);
  leg_raa->SetFillColor(kWhite);
  leg_raa->AddEntry(tge_pionpos_RAA,"#pi^{+}","p");
  leg_raa->AddEntry(tge_pionneg_RAA,"#pi^{-}","p");
  leg_raa->AddEntry(tge_kaonpos_RAA,"K^{+}","p");
  leg_raa->AddEntry(tge_kaonneg_RAA,"K^{-}","p");
  leg_raa->AddEntry(tge_protonpos_RAA,"p","p");
  leg_raa->AddEntry(tge_protonneg_RAA,"#bar{p}","p");
  leg_raa->SetTextSize(0.05);
  //leg_raa->Draw(); // just about perfect, but maybe only one for both panels
  TLatex *tl_raa = new TLatex(0.6,1.73,"R_{AA} (0-10%)");
  tl_raa->SetTextSize(0.05);
  tl_raa->Draw();


  c1_2->cd();
  TMultiGraph *tmg_rcp = new TMultiGraph();
  //tmg_rcp->Add(tge_sys1);
  tmg_rcp->Add(tge_sys2);
  tmg_rcp->Add(tge_syspionpos_RCP);
  tmg_rcp->Add(tge_syspionneg_RCP);
  tmg_rcp->Add(tge_syskaonpos_RCP);
  tmg_rcp->Add(tge_syskaonneg_RCP);
  tmg_rcp->Add(tge_sysprotonpos_RCP);
  tmg_rcp->Add(tge_sysprotonneg_RCP);
  tmg_rcp->Add(tge_pionpos_RCP);
  tmg_rcp->Add(tge_pionneg_RCP);
  tmg_rcp->Add(tge_kaonpos_RCP);
  tmg_rcp->Add(tge_kaonneg_RCP);
  tmg_rcp->Add(tge_protonpos_RCP);
  tmg_rcp->Add(tge_protonneg_RCP);
  tmg_rcp->Draw("apz");
  tmg_rcp->SetMaximum(2.0);
  tmg_rcp->SetMinimum(0.0);
  tmg_rcp->GetXaxis()->SetLimits(0.0,6.0);
  TLine *line_rcp = new TLine(0.0,1.0,6.0,1.0);
  line_rcp->Draw();
  tmg_rcp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_rcp->GetXaxis()->CenterTitle();
  tmg_rcp->GetYaxis()->SetTitle("Nuclear Modification Factor");
  //tmg_rcp->GetYaxis()->SetTitle("R_{CP}");
  tmg_rcp->GetYaxis()->CenterTitle();
  //tmg_rcp->GetYaxis()->SetTitleOffset(1.5);
  tmg_rcp->GetYaxis()->SetTitleSize(0);
  tmg_rcp->GetYaxis()->SetLabelSize(0);
  tmg_rcp->GetXaxis()->SetTitleSize(0.04);
  tmg_rcp->GetXaxis()->SetLabelSize(0.04);
  // just about perfect, but move down a little for new text
  //TLegend *leg_rcp = new TLegend(0.77,0.58,0.85,0.88);
  TLegend *leg_rcp = new TLegend(0.77,0.55,0.85,0.80);
  leg_rcp->SetBorderSize(0);
  leg_rcp->SetFillColor(kWhite);
  leg_rcp->AddEntry(tge_pionpos_RCP,"#pi^{+}","p");
  leg_rcp->AddEntry(tge_pionneg_RCP,"#pi^{-}","p");
  leg_rcp->AddEntry(tge_kaonpos_RCP,"K^{+}","p");
  leg_rcp->AddEntry(tge_kaonneg_RCP,"K^{-}","p");
  leg_rcp->AddEntry(tge_protonpos_RCP,"p","p");
  leg_rcp->AddEntry(tge_protonneg_RCP,"#bar{p}","p");
  leg_rcp->SetTextSize(0.05);
  leg_rcp->Draw();
  TLatex *tl_rcp = new TLatex(0.6,1.73,"R_{CP} (0-10%/60-92%)");
  tl_rcp->SetTextSize(0.05);
  tl_rcp->Draw();
  TLatex *tl_col = new TLatex(3.5,1.73,"Au+Au #sqrt{s_{NN}}=200 GeV");
  tl_col->SetTextSize(0.05);
  tl_col->Draw();





  // char particle[7];
  // if(pr7pid<=3) sprintf(particle,"kaon");
  // else if(pr7pid>=4) sprintf(particle,"proton");
  // char figname[100];
  // sprintf(figname,"figures/auau_nmf_pion%s.gif",particle);
  // c1->Print(figname);
  // sprintf(figname,"figures/auau_nmf_pion%s.eps",particle);
  // c1->Print(figname);

  char figname[100];
  sprintf(figname,"figures/auau_nmf_all.gif");
  c1->Print(figname);
  sprintf(figname,"figures/auau_nmf_all.eps");
  c1->Print(figname);

  c1->Clear();
  delete c1;

  TCanvas *c2 = new TCanvas("c2","",1200,500);
  //c2->Divide(2);
  c2->cd();
  TPad *c2_1 = new TPad("c2_1","c2_1",0.0,0.0,0.5,1.0);
  c2_1->Draw();
  c2->cd();
  TPad *c2_2 = new TPad("c2_2","c2_2",0.5,0.0,1.0,1.0);
  c2_2->Draw();
  c2->cd();
  c2_1->SetRightMargin(0);
  c2_2->SetLeftMargin(0);
  c2_1->SetTopMargin(0.05);
  c2_2->SetTopMargin(0.05);
  c2_1->SetTicks(1,1);
  c2_2->SetTicks(1,1);

  // ------------------------------------------------------------------------- //
  // --- this little section gives a perfect replica of the regular figure --- //
  // ------------------------------------------------------------------------- //
  // c2_1->cd();                                                               //
  // tmg_raa->Draw("apz");                                                     //
  // line_raa->Draw();                                                         //
  // tl_raa->Draw();                                                           //
  // c2_2->cd();                                                               //
  // tmg_rcp->Draw("apz");                                                     //
  // line_rcp->Draw();                                                         //
  // leg_rcp->Draw();                                                          //
  // tl_rcp->Draw();                                                           //
  // tl_col->Draw();                                                           //
  // ------------------------------------------------------------------------- //
  // ---                                                                   --- //
  // ------------------------------------------------------------------------- //



  // reversed from above
  tmg_rcp->GetYaxis()->SetTitleSize(0.04);
  tmg_rcp->GetYaxis()->SetLabelSize(0.04);
  tmg_raa->GetYaxis()->SetTitleSize(0);
  tmg_raa->GetYaxis()->SetLabelSize(0);

  c2_1->cd();
  tmg_rcp->Draw("apz");
  line_rcp->Draw();
  tl_rcp->Draw();
  c2_2->cd();
  tmg_raa->Draw("apz");
  line_raa->Draw();
  leg_rcp->Draw(); // extra, right only
  tl_raa->Draw();
  tl_col->Draw(); // extra, right only

  sprintf(figname,"figures/auau_nmf_swall.gif"); // swap, all
  c2->Print(figname);
  sprintf(figname,"figures/auau_nmf_swall.eps"); // swap, all
  c2->Print(figname);


  c2->Clear();
  delete c2;




}
