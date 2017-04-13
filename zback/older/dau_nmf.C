void dau_nmf()
{

  doit(1,5,33,false);
  doit(1,3,16,false);

}

void doit(int pi8pid=1, int pr8pid=5, int number=-1, bool chavers=false)
{

  //cout<<"number is "<<number<<" and it means nothing"<<endl;

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
  // -- RDA -- //
  // --------- //



  // --

  float ptpion_RDA[36];
  float eptpion_RDA[36];
  float pionpos_RDA[36];
  float pionneg_RDA[36];
  float epionpos_RDA[36];
  float epionneg_RDA[36];
  float esyspionpos_RDA[36];
  float esyspionneg_RDA[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent0020.txt",pi8pid);
  ifstream fRDA(filename);
  for(int i=0; i<36; i++)
    {
      fRDA>>ptpion_RDA[i]>>pionpos_RDA[i]>>epionpos_RDA[i]>>pionneg_RDA[i]>>epionneg_RDA[i];
      eptpion_RDA[i]=0;
      if(chavers)
	{
	  pionpos_RDA[i] += pionneg_RDA[i];
	  pionpos_RDA[i] /= 2.0;
	  epionpos_RDA[i] = sqrt(epionpos_RDA[i]**2+epionneg_RDA[i]**2)/2.0;
	}
      esyspionpos_RDA[i] = sysvalue*pionpos_RDA[i];
      esyspionneg_RDA[i] = sysvalue*pionneg_RDA[i];
    }
  fRDA.close();
  TGraphErrors *tge_pionpos_RDA = new TGraphErrors(27,ptpion_RDA,pionpos_RDA,eptpion_RDA,epionpos_RDA);
  tge_pionpos_RDA->SetMarkerStyle(kFullCircle);
  tge_pionpos_RDA->SetMarkerColor(kRed);
  TGraphErrors *tge_pionneg_RDA = new TGraphErrors(27,ptpion_RDA,pionneg_RDA,eptpion_RDA,epionneg_RDA);
  tge_pionneg_RDA->SetMarkerStyle(kFullCircle);
  tge_pionneg_RDA->SetMarkerColor(kBlue);
  TGraphErrors *tge_syspionpos_RDA = new TGraphErrors(27,ptpion_RDA,pionpos_RDA,eptpion_RDA,esyspionpos_RDA);
  tge_syspionpos_RDA->SetMarkerStyle(1);
  tge_syspionpos_RDA->SetMarkerColor(kGray);
  tge_syspionpos_RDA->SetFillColor(kGray);
  tge_syspionpos_RDA->SetLineColor(kGray);
  tge_syspionpos_RDA->SetLineWidth(15);
  TGraphErrors *tge_syspionneg_RDA = new TGraphErrors(27,ptpion_RDA,pionneg_RDA,eptpion_RDA,esyspionneg_RDA);
  tge_syspionneg_RDA->SetMarkerStyle(1);
  tge_syspionneg_RDA->SetMarkerColor(kGray);
  tge_syspionneg_RDA->SetFillColor(kGray);
  tge_syspionneg_RDA->SetLineColor(kGray);
  tge_syspionneg_RDA->SetLineWidth(15);

  // --

  float ptproton_RDA[36];
  float eptproton_RDA[36];
  float protonpos_RDA[36];
  float protonneg_RDA[36];
  float eprotonpos_RDA[36];
  float eprotonneg_RDA[36];
  float esysprotonpos_RDA[36];
  float esysprotonneg_RDA[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rda_%d_cent0020.txt",pr8pid);
  fRDA.open(filename);
  //cout<<"filename is "<<filename<<endl;
  for(int i=0; i<36; i++)
    {
      fRDA>>ptproton_RDA[i]>>protonpos_RDA[i]>>eprotonpos_RDA[i]>>protonneg_RDA[i]>>eprotonneg_RDA[i];
      eptproton_RDA[i]=0;
      //cout<<"info "<<protonpos_RDA[i]<<endl;
      if(chavers)
	{
	  protonpos_RDA[i] += protonneg_RDA[i];
	  protonpos_RDA[i] /= 2.0;
	  eprotonpos_RDA[i] = sqrt(eprotonpos_RDA[i]**2+eprotonneg_RDA[i]**2)/2.0;
	}
      esysprotonpos_RDA[i] = sysvalue*protonpos_RDA[i];
      esysprotonneg_RDA[i] = sysvalue*protonneg_RDA[i];
    }
  fRDA.close();
  TGraphErrors *tge_protonpos_RDA = new TGraphErrors(number,ptproton_RDA,protonpos_RDA,eptproton_RDA,eprotonpos_RDA);
  tge_protonpos_RDA->SetMarkerStyle(kFullSquare);
  tge_protonpos_RDA->SetMarkerColor(kRed);
  TGraphErrors *tge_protonneg_RDA = new TGraphErrors(number,ptproton_RDA,protonneg_RDA,eptproton_RDA,eprotonneg_RDA);
  tge_protonneg_RDA->SetMarkerStyle(kFullSquare);
  tge_protonneg_RDA->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysprotonpos_RDA = new TGraphErrors(number,ptproton_RDA,protonpos_RDA,eptproton_RDA,esysprotonpos_RDA);
  tge_sysprotonpos_RDA->SetMarkerStyle(1);
  tge_sysprotonpos_RDA->SetMarkerColor(kGray);
  tge_sysprotonpos_RDA->SetFillColor(kGray);
  tge_sysprotonpos_RDA->SetLineColor(kGray);
  tge_sysprotonpos_RDA->SetLineWidth(15);
  TGraphErrors *tge_sysprotonneg_RDA = new TGraphErrors(number,ptproton_RDA,protonneg_RDA,eptproton_RDA,esysprotonneg_RDA);
  tge_sysprotonneg_RDA->SetMarkerStyle(1);
  tge_sysprotonneg_RDA->SetMarkerColor(kGray);
  tge_sysprotonneg_RDA->SetFillColor(kGray);
  tge_sysprotonneg_RDA->SetLineColor(kGray);
  tge_sysprotonneg_RDA->SetLineWidth(15);



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
  sprintf(filename,"../Run8dAu/Ratios/regular/rcp_%d.txt",pi8pid);
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
      esyspionpos_RCP[i] = sysvalue*pionpos_RCP[i];
      esyspionneg_RCP[i] = sysvalue*pionneg_RCP[i];
    }
  TGraphErrors *tge_pionpos_RCP = new TGraphErrors(34,pt_RCP,pionpos_RCP,ept_RCP,epionpos_RCP);
  tge_pionpos_RCP->SetMarkerStyle(kFullCircle);
  tge_pionpos_RCP->SetMarkerColor(kRed);
  TGraphErrors *tge_pionneg_RCP = new TGraphErrors(34,pt_RCP,pionneg_RCP,ept_RCP,epionneg_RCP);
  tge_pionneg_RCP->SetMarkerStyle(kFullCircle);
  tge_pionneg_RCP->SetMarkerColor(kBlue);
  TGraphErrors *tge_syspionpos_RCP = new TGraphErrors(34,pt_RCP,pionpos_RCP,ept_RCP,esyspionpos_RCP);
  tge_syspionpos_RCP->SetMarkerStyle(1);
  tge_syspionpos_RCP->SetMarkerColor(kGray);
  tge_syspionpos_RCP->SetFillColor(kGray);
  tge_syspionpos_RCP->SetLineColor(kGray);
  tge_syspionpos_RCP->SetLineWidth(15);
  TGraphErrors *tge_syspionneg_RCP = new TGraphErrors(34,pt_RCP,pionneg_RCP,ept_RCP,esyspionneg_RCP);
  tge_syspionneg_RCP->SetMarkerStyle(1);
  tge_syspionneg_RCP->SetMarkerColor(kGray);
  tge_syspionneg_RCP->SetFillColor(kGray);
  tge_syspionneg_RCP->SetLineColor(kGray);
  tge_syspionneg_RCP->SetLineWidth(15);

  // --

  float protonpos_RCP[36];
  float protonneg_RCP[36];
  float eprotonpos_RCP[36];
  float eprotonneg_RCP[36];
  float esysprotonpos_RCP[36];
  float esysprotonneg_RCP[36];
  sprintf(filename,"../Run8dAu/Ratios/regular/rcp_%d.txt",pr8pid);
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
      esysprotonpos_RCP[i] = sysvalue*protonpos_RCP[i];
      esysprotonneg_RCP[i] = sysvalue*protonneg_RCP[i];
    }
  TGraphErrors *tge_protonpos_RCP = new TGraphErrors(34,pt_RCP,protonpos_RCP,ept_RCP,eprotonpos_RCP);
  tge_protonpos_RCP->SetMarkerStyle(kFullSquare);
  tge_protonpos_RCP->SetMarkerColor(kRed);
  TGraphErrors *tge_protonneg_RCP = new TGraphErrors(34,pt_RCP,protonneg_RCP,ept_RCP,eprotonneg_RCP);
  tge_protonneg_RCP->SetMarkerStyle(kFullSquare);
  tge_protonneg_RCP->SetMarkerColor(kBlue);
  TGraphErrors *tge_sysprotonpos_RCP = new TGraphErrors(34,pt_RCP,protonpos_RCP,ept_RCP,esysprotonpos_RCP);
  tge_sysprotonpos_RCP->SetMarkerStyle(1);
  tge_sysprotonpos_RCP->SetMarkerColor(kGray);
  tge_sysprotonpos_RCP->SetFillColor(kGray);
  tge_sysprotonpos_RCP->SetLineColor(kGray);
  tge_sysprotonpos_RCP->SetLineWidth(15);
  TGraphErrors *tge_sysprotonneg_RCP = new TGraphErrors(34,pt_RCP,protonneg_RCP,ept_RCP,esysprotonneg_RCP);
  tge_sysprotonneg_RCP->SetMarkerStyle(1);
  tge_sysprotonneg_RCP->SetMarkerColor(kGray);
  tge_sysprotonneg_RCP->SetFillColor(kGray);
  tge_sysprotonneg_RCP->SetLineColor(kGray);
  tge_sysprotonneg_RCP->SetLineWidth(15);




  // ---
  // --- now draw
  // ---






  TCanvas *c1 = new TCanvas("c1","",1200,500);
  //c1->Divide(2);
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
  TMultiGraph *tmg_rda = new TMultiGraph();
  //tmg_rda->Add(tge_sys4);
  tmg_rda->Add(tge_sys3);
  tmg_rda->Add(tge_syspionpos_RDA);
  tmg_rda->Add(tge_syspionneg_RDA);
  tmg_rda->Add(tge_sysprotonpos_RDA);
  tmg_rda->Add(tge_sysprotonneg_RDA);
  tmg_rda->Add(tge_pionpos_RDA);
  tmg_rda->Add(tge_pionneg_RDA);
  tmg_rda->Add(tge_protonpos_RDA);
  tmg_rda->Add(tge_protonneg_RDA);
  tmg_rda->Draw("apz");
  tmg_rda->SetMaximum(3.0);
  tmg_rda->SetMinimum(0.0);
  tmg_rda->GetXaxis()->SetLimits(0.0,6.0);
  TLine *line_rda = new TLine(0.0,1.0,6.0,1.0);
  line_rda->Draw();
  tmg_rda->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_rda->GetXaxis()->CenterTitle();
  tmg_rda->GetYaxis()->SetTitle("Nuclear Modification Factor");
  //tmg_rda->GetYaxis()->SetTitle("R_{dA}");
  tmg_rda->GetYaxis()->CenterTitle();
  //tmg_rda->GetYaxis()->SetTitleOffset(1.5);
  tmg_rda->GetYaxis()->SetTitleSize(0.04);
  tmg_rda->GetYaxis()->SetLabelSize(0.04);
  tmg_rda->GetXaxis()->SetTitleSize(0.04);
  tmg_rda->GetXaxis()->SetLabelSize(0.04);
  TLegend *leg_rda = new TLegend(0.68,0.68,0.88,0.88);
  leg_rda->SetBorderSize(0);
  leg_rda->SetFillColor(kWhite);
  leg_rda->AddEntry(tge_pionpos_RDA,"#pi^{+}","p");
  leg_rda->AddEntry(tge_pionneg_RDA,"#pi^{-}","p");
  if(pr8pid>=4)
    {
      leg_rda->AddEntry(tge_protonpos_RDA,"p","p");
      leg_rda->AddEntry(tge_protonneg_RDA,"#bar{p}","p");
    }
  else
    {
      leg_rda->AddEntry(tge_pionpos_RDA,"K^{+}","p");
      leg_rda->AddEntry(tge_pionneg_RDA,"K^{-}","p");
    }
  leg_rda->SetTextSize(0.05);
  leg_rda->Draw();


  c1_2->cd();
  TMultiGraph *tmg_rcp = new TMultiGraph();
  //tmg_rcp->Add(tge_sys1);
  tmg_rcp->Add(tge_sys2);
  tmg_rcp->Add(tge_syspionpos_RCP);
  tmg_rcp->Add(tge_syspionneg_RCP);
  tmg_rcp->Add(tge_sysprotonpos_RCP);
  tmg_rcp->Add(tge_sysprotonneg_RCP);
  tmg_rcp->Add(tge_pionpos_RCP);
  tmg_rcp->Add(tge_pionneg_RCP);
  tmg_rcp->Add(tge_protonpos_RCP);
  tmg_rcp->Add(tge_protonneg_RCP);
  tmg_rcp->Draw("apz");
  tmg_rcp->SetMaximum(3.0);
  tmg_rcp->SetMinimum(0.0);
  tmg_rcp->GetXaxis()->SetLimits(0.0,6.0);
  TLine *line_rcp = new TLine(0.0,1.0,6.0,1.0);
  line_rcp->Draw();
  tmg_rcp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_rcp->GetXaxis()->CenterTitle();
  //tmg_rcp->GetYaxis()->SetTitle("Nuclear Modification Factor");
  //tmg_rcp->GetYaxis()->SetTitle("R_{CP}");
  //tmg_rcp->GetYaxis()->CenterTitle();
  //tmg_rcp->GetYaxis()->SetTitleOffset(1.5);
  tmg_rcp->GetYaxis()->SetTitleSize(0);
  tmg_rcp->GetYaxis()->SetLabelSize(0);
  tmg_rcp->GetXaxis()->SetTitleSize(0.04);
  tmg_rcp->GetXaxis()->SetLabelSize(0.04);
  TLegend *leg_rcp = new TLegend(0.68,0.68,0.88,0.88);
  leg_rcp->SetBorderSize(0);
  leg_rcp->SetFillColor(kWhite);
  leg_rcp->AddEntry(tge_pionpos_RCP,"#pi^{+}","p");
  leg_rcp->AddEntry(tge_pionneg_RCP,"#pi^{-}","p");
  if(pr8pid>=4)
    {
      leg_rcp->AddEntry(tge_protonpos_RCP,"p","p");
      leg_rcp->AddEntry(tge_protonneg_RCP,"#bar{p}","p");
    }
  else
    {
      leg_rcp->AddEntry(tge_pionpos_RCP,"K^{+}","p");
      leg_rcp->AddEntry(tge_pionneg_RCP,"K^{-}","p");
    }
  leg_rcp->SetTextSize(0.05);
  leg_rcp->Draw();





  char particle[7];
  if(pr8pid<=3) sprintf(particle,"kaon");
  else if(pr8pid>=4) sprintf(particle,"proton");
  char figname[100];
  sprintf(figname,"figures/dau_nmf_pion%s.gif",particle);
  c1->Print(figname);
  sprintf(figname,"figures/dau_nmf_pion%s.eps",particle);
  c1->Print(figname);



  c1->Clear();
  delete c1;

  TCanvas *c2 = new TCanvas();
  tmg_rda->Draw("apz");
  line_rda->Draw();
  leg_rda->Draw();
  sprintf(figname,"figures/dau_nmf_RDA_pion%s.gif",particle);
  c2->Print(figname);
  sprintf(figname,"figures/dau_nmf_RDA_pion%s.eps",particle);
  c2->Print(figname);
  c2->Clear();
  tmg_rcp->Draw("apz");
  line_rcp->Draw();
  leg_rcp->Draw();
  sprintf(figname,"figures/dau_nmf_RCP_pion%s.gif",particle);
  c2->Print(figname);
  sprintf(figname,"figures/dau_nmf_RCP_pion%s.eps",particle);
  c2->Print(figname);

  c2->Clear();
  delete c2;






}
