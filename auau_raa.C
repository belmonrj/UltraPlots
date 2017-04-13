TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;

float minx = 0.00;
//float maxx = 5.99;
//float maxx = 5.00;
float maxx = 6.00;

void auau_raa()
{

  // ------------------- //
  // --- old binning --- //
  // doit(0,27,true);    //
  // doit(4,16,true);    //
  // doit(6,33,true);    //
  //                     //
  // ------------------- //

  doit(0,22,true);
  doit(4,16,true);
  doit(6,24,true);

  doit4x4(tmg_pion,tmg_kaon,tmg_prot);
  doitSPC(tmg_pion,tmg_kaon,tmg_prot);

}


void doitSPC(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  //float textsize = 0.08; // see below

  float pt[18], ratio[18], eratio[18], esysratio[18];
  float tmp;
  ifstream fpi0;

  float PT = 0.3;
  int WIDTH = 10;

  float pt_sys0010[1] = {PT};
  float ept_sys0010[1] = {0.0};
  float point_sys0010[1] = {1.0};
  float epoint_sys0010[1] = {0.1};
  TGraphErrors *tge_sys0010 = new TGraphErrors(1,pt_sys0010,point_sys0010,ept_sys0010,epoint_sys0010);
  tge_sys0010->SetMarkerStyle(1);
  tge_sys0010->SetMarkerColor(kGray+2);
  tge_sys0010->SetLineWidth(WIDTH);
  tge_sys0010->SetLineColor(kGray+2);

  float pt_sys1020[1] = {PT};
  float ept_sys1020[1] = {0.0};
  float point_sys1020[1] = {1.0};
  float epoint_sys1020[1] = {0.1};
  TGraphErrors *tge_sys1020 = new TGraphErrors(1,pt_sys1020,point_sys1020,ept_sys1020,epoint_sys1020);
  tge_sys1020->SetMarkerStyle(1);
  tge_sys1020->SetMarkerColor(kGray+2);
  tge_sys1020->SetLineWidth(WIDTH);
  tge_sys1020->SetLineColor(kGray+2);

  float pt_sys2040[1] = {PT};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.1};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kGray+2);
  tge_sys2040->SetLineWidth(WIDTH);
  tge_sys2040->SetLineColor(kGray+2);

  float pt_sys4060[1] = {PT};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.13};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGray+2);
  tge_sys4060->SetLineWidth(WIDTH);
  tge_sys4060->SetLineColor(kGray+2);

  float pt_sys6092[1] = {PT};
  float ept_sys6092[1] = {0.0};
  float point_sys6092[1] = {1.0};
  float epoint_sys6092[1] = {0.23};
  TGraphErrors *tge_sys6092 = new TGraphErrors(1,pt_sys6092,point_sys6092,ept_sys6092,epoint_sys6092);
  tge_sys6092->SetMarkerStyle(1);
  tge_sys6092->SetMarkerColor(kGray+2);
  tge_sys6092->SetLineWidth(WIDTH);
  tge_sys6092->SetLineColor(kGray+2);




  fpi0.open("ExtraData/NeutralPion/ppg080_RAA0010.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_0010[18]; for(int i=0; i<18; i++){pi0_0010[i]=ratio[i];}
  float pi0sys0010[18]; for(int i=0; i<18; i++){pi0sys0010[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_0010 = new TGraphErrors(18,pt,ratio,0,eratio);
  TGraphErrors *tge_syspi0_0010 = new TGraphErrors(18,pt,ratio,0,esysratio);
  fpi0.open("ExtraData/NeutralPion/ppg080_RAA1020.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_1020[18]; for(int i=0; i<18; i++){pi0_1020[i]=ratio[i];}
  float pi0sys1020[18]; for(int i=0; i<18; i++){pi0sys1020[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_1020 = new TGraphErrors(18,pt,ratio,0,eratio);
  TGraphErrors *tge_syspi0_1020 = new TGraphErrors(18,pt,ratio,0,esysratio);
  fpi0.open("ExtraData/NeutralPion/ppg080_RAA2040.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_2040[18]; for(int i=0; i<18; i++){pi0_2040[i]=ratio[i];}
  float pi0sys2040[18]; for(int i=0; i<18; i++){pi0sys2040[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_2040 = new TGraphErrors(18,pt,ratio,0,eratio);
  TGraphErrors *tge_syspi0_2040 = new TGraphErrors(18,pt,ratio,0,esysratio);
  fpi0.open("ExtraData/NeutralPion/ppg080_RAA4060.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_4060[18]; for(int i=0; i<18; i++){pi0_4060[i]=ratio[i];}
  float pi0sys4060[18]; for(int i=0; i<18; i++){pi0sys4060[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_4060 = new TGraphErrors(18,pt,ratio,0,eratio);
  TGraphErrors *tge_syspi0_4060 = new TGraphErrors(18,pt,ratio,0,esysratio);
  fpi0.open("ExtraData/NeutralPion/ppg080_RAA6092.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_6092[18]; for(int i=0; i<18; i++){pi0_6092[i]=ratio[i];}
  float pi0sys6092[18]; for(int i=0; i<18; i++){pi0sys6092[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_6092 = new TGraphErrors(18,pt,ratio,0,eratio);
  TGraphErrors *tge_syspi0_6092 = new TGraphErrors(18,pt,ratio,0,esysratio);


  tge_pi0_0010->SetMarkerStyle(kOpenCircle);
  tge_pi0_1020->SetMarkerStyle(kOpenCircle);
  tge_pi0_2040->SetMarkerStyle(kOpenCircle);
  tge_pi0_4060->SetMarkerStyle(kOpenCircle);
  tge_pi0_6092->SetMarkerStyle(kOpenCircle);



  for(int i=0; i<18; i++){pt[i]=-9,ratio[i]=-9;eratio[i]=-9;}


  ifstream fphi;


  float       phipt[10];
  float    phi_0010[10];
  float phisys_0010[10];
  float    phi_1020[10];
  float phisys_1020[10];
  float    phi_2040[10];
  float phisys_2040[10];
  float    phi_4060[10];
  float phisys_4060[10];
  float    phi_6092[10];
  float phisys_6092[10];

  fphi.open("ExtraData/PhiMeson/phi_RAA_cent0010.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phipt[i]=pt[i];phi_0010[i]=ratio[i];phisys_0010[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_0010 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_0010 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RAA_cent1020.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_1020[i]=ratio[i];phisys_1020[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_1020 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_1020 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RAA_cent2040.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_2040[i]=ratio[i];phisys_2040[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_2040 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_2040 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RAA_cent4060.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_4060[i]=ratio[i];phisys_4060[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_4060 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_4060 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RAA_cent6092.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_6092[i]=ratio[i];phisys_6092[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_6092 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_6092 = new TGraphErrors(10,pt,ratio,0,esysratio);


  tge_phi_0010->SetMarkerStyle(kOpenCross);
  tge_phi_1020->SetMarkerStyle(kOpenCross);
  tge_phi_2040->SetMarkerStyle(kOpenCross);
  tge_phi_4060->SetMarkerStyle(kOpenCross);
  tge_phi_6092->SetMarkerStyle(kOpenCross);



  cout<<"SPC"<<endl;

  cout<<"pion "<<pion<<endl;

  // pion
  TGraphErrors *tge_pion0010 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_auau0010");
  TGraphErrors *tge_pion1020 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_auau1020");
  TGraphErrors *tge_pion2040 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_auau2040");
  TGraphErrors *tge_pion4060 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_auau4060");
  TGraphErrors *tge_pion6092 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_auau6092");
  TGraphErrors *tge_syspion0010 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_auau0010");
  TGraphErrors *tge_syspion1020 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_auau1020");
  TGraphErrors *tge_syspion2040 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_auau2040");
  TGraphErrors *tge_syspion4060 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_auau4060");
  TGraphErrors *tge_syspion6092 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_auau6092");
  // kaon
  TGraphErrors *tge_kaon0010 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_auau0010");
  TGraphErrors *tge_kaon1020 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_auau1020");
  TGraphErrors *tge_kaon2040 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_auau2040");
  TGraphErrors *tge_kaon4060 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_auau4060");
  TGraphErrors *tge_kaon6092 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_auau6092");
  TGraphErrors *tge_syskaon0010 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_auau0010");
  TGraphErrors *tge_syskaon1020 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_auau1020");
  TGraphErrors *tge_syskaon2040 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_auau2040");
  TGraphErrors *tge_syskaon4060 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_auau4060");
  TGraphErrors *tge_syskaon6092 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_auau6092");
  // prot
  TGraphErrors *tge_prot0010 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_auau0010");
  TGraphErrors *tge_prot1020 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_auau1020");
  TGraphErrors *tge_prot2040 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_auau2040");
  TGraphErrors *tge_prot4060 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_auau4060");
  TGraphErrors *tge_prot6092 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_auau6092");
  TGraphErrors *tge_sysprot0010 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_auau0010");
  TGraphErrors *tge_sysprot1020 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_auau1020");
  TGraphErrors *tge_sysprot2040 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_auau2040");
  TGraphErrors *tge_sysprot4060 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_auau4060");
  TGraphErrors *tge_sysprot6092 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_auau6092");

  cout<<"tge_pion0010 "<<tge_pion0010<<endl;



  TCanvas *c1 = new TCanvas("c1","c1",1000,700);

  float left = 0.07;
  float bottom = 0.09;
  float width = 0.3;
  float height = 0.43;

  float xmin = 0.0;
  float xmax = 6.0;
  float ymin = 0.0;
  float ymax = 2.2;
  float labelsize = 0.08;
  float textsize = 0.08;
  int ydivisions = 505;
  int xdivisions = 510;

  TLine *line = new TLine(xmin,1.0,xmax,1.0);
  line->SetLineStyle(2);



  c1->cd();
  float left = 0.07;
  float bottom = 0.09;
  float width = 0.3;
  float height = 0.43;
  TPad *c1_1 = new TPad("c1_1","c1_1",left+0*width,bottom+1*height,left+1*width,bottom+2*height);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",left+1*width,bottom+1*height,left+2*width,bottom+2*height);
  c1_2->Draw();
  c1->cd();
  TPad *c1_3 = new TPad("c1_3","c1_3",left+2*width,bottom+1*height,left+3*width,bottom+2*height);
  c1_3->Draw();
  c1->cd();
  TPad *c1_4 = new TPad("c1_4","c1_4",left+0*width,bottom+0*height,left+1*width,bottom+1*height);
  c1_4->Draw();
  c1->cd();
  TPad *c1_5 = new TPad("c1_5","c1_5",left+1*width,bottom+0*height,left+2*width,bottom+1*height);
  c1_5->Draw();
  c1->cd();
  TPad *c1_6 = new TPad("c1_6","c1_6",left+2*width,bottom+0*height,left+3*width,bottom+1*height);
  c1_6->Draw();



  // --- now using TGaxis --- //
  // x1,  y1,x2, y2 are canvas coordinate is standard root convention
  // 0 is min, 3.0 is max, 510 is divisions, "" is no option
  c1->cd();
  float scale = 2.4;
  float titleoff = 1.0;
  //TGaxis *yaxis0 = new TGaxis(left,bottom+0*height,left,bottom+1*height,ymin,ymax,ydivisions,"");
  TGaxis *yaxis0 = new TGaxis(left,bottom+0*height,left,bottom+1*height,ymin,ymax-1e-4,ydivisions,"");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("R_{AA}");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(labelsize/scale);
  yaxis0->SetTitleSize(labelsize/scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->Draw();
  TGaxis *yaxis1 = new TGaxis(left,bottom+1*height,left,bottom+2*height,ymin,ymax,ydivisions,"");
  yaxis1->SetName("yaxis1");
  yaxis1->SetTitle("R_{AA}");
  yaxis1->CenterTitle();
  yaxis1->SetLabelSize(labelsize/scale);
  yaxis1->SetTitleSize(labelsize/scale);
  yaxis1->SetTitleOffset(titleoff);
  yaxis1->Draw();
  //TGaxis *xaxis0 = new TGaxis(left+0*width,bottom+0*height,left+1*width,bottom+0*height,xmin,xmax,xdivisions,"");
  TGaxis *xaxis0 = new TGaxis(left+0*width,bottom+0*height,left+1*width,bottom+0*height,xmin,xmax-1e-4,xdivisions,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(labelsize/scale);
  xaxis0->SetTitleSize(labelsize/scale);
  xaxis0->SetTitleOffset(titleoff);
  xaxis0->Draw();
  //TGaxis *xaxis1 = new TGaxis(left+1*width,bottom+0*height,left+2*width,bottom+0*height,xmin,xmax,xdivisions,"");
  TGaxis *xaxis1 = new TGaxis(left+1*width,bottom+0*height,left+2*width,bottom+0*height,xmin,xmax-1e-4,xdivisions,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(labelsize/scale);
  xaxis1->SetTitleSize(labelsize/scale);
  xaxis1->SetTitleOffset(titleoff);
  xaxis1->Draw();
  TGaxis *xaxis2 = new TGaxis(left+2*width,bottom+0*height,left+3*width,bottom+0*height,xmin,xmax,xdivisions,"");
  xaxis2->SetName("xaxis2");
  xaxis2->SetTitle("p_{T} (GeV/c)");
  xaxis2->CenterTitle();
  xaxis2->SetLabelSize(labelsize/scale);
  xaxis2->SetTitleSize(labelsize/scale);
  xaxis2->SetTitleOffset(titleoff);
  xaxis2->Draw();






  tge_pi0_0010->SetMarkerColor(kRed);
  tge_pi0_1020->SetMarkerColor(kRed);
  tge_pi0_2040->SetMarkerColor(kRed);
  tge_pi0_4060->SetMarkerColor(kRed);
  tge_pi0_6092->SetMarkerColor(kRed);



  c1_1->cd();
  c1_1->SetTopMargin(0);
  c1_1->SetLeftMargin(0);
  c1_1->SetRightMargin(0);
  c1_1->SetBottomMargin(0);
  c1_1->SetTicks(1,1);
  tge_pion0010->SetMarkerColor(kRed);
  tge_kaon0010->SetMarkerColor(kGreen+2);
  tge_prot0010->SetMarkerColor(kBlue);
  tge_pion0010->SetMarkerStyle(kFullCircle);
  tge_kaon0010->SetMarkerStyle(kFullTriangleUp);
  tge_prot0010->SetMarkerStyle(kFullSquare);
  int cad = 9; // color adjustment
  tge_syspion0010->SetMarkerColor(kRed-cad);   //new
  tge_syskaon0010->SetMarkerColor(kGreen-cad); //new
  tge_sysprot0010->SetMarkerColor(kBlue-cad);  //new
  tge_syspion0010->SetLineColor(kRed-cad);     //new
  tge_syskaon0010->SetLineColor(kGreen-cad);   //new
  tge_sysprot0010->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg0010 = new TMultiGraph();
  tmg0010->Add(tge_sys0010); // normalization from Glauber
  tmg0010->Add(tge_sysprot0010);
  tmg0010->Add(tge_syspion0010);
  tmg0010->Add(tge_syskaon0010);
  tmg0010->Add(tge_prot0010);
  tmg0010->Add(tge_pion0010);
  tmg0010->Add(tge_kaon0010);
  tmg0010->Add(tge_pi0_0010);
  tmg0010->Add(tge_phi_0010);
  tmg0010->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_0010[i]-pi0sys0010[i];
      double py2 = pi0_0010[i]+pi0sys0010[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_0010[i]-phisys_0010[i];
      double py2 = phi_0010[i]+phisys_0010[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg0010->SetMaximum(ymax);
  tmg0010->SetMinimum(ymin);
  tmg0010->GetXaxis()->SetLimits(xmin,xmax);
  tmg0010->GetYaxis()->SetTitle("R_{AA}");
  tmg0010->GetYaxis()->CenterTitle();
  tmg0010->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg0010->GetXaxis()->CenterTitle();
  tmg0010->GetXaxis()->SetLabelSize(0);
  tmg0010->GetXaxis()->SetTitleSize(0);
  tmg0010->GetXaxis()->SetTitleOffset(1.3);
  tmg0010->GetYaxis()->SetLabelSize(0);
  tmg0010->GetYaxis()->SetTitleSize(0);
  tmg0010->GetYaxis()->SetTitleOffset(1.3);
  tmg0010->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl0010 = new TLatex(0.65,0.85*ymax,"0-10%");
  tl0010->SetTextSize(textsize);
  tl0010->Draw();


  // ------------ //
  // --- 1020 --- //
  // ------------ //

  c1_2->cd();
  c1_2->SetTopMargin(0);
  c1_2->SetLeftMargin(0);
  c1_2->SetRightMargin(0);
  c1_2->SetBottomMargin(0);
  c1_2->SetTicks(1,1);
  tge_pion1020->SetMarkerColor(kRed);
  tge_kaon1020->SetMarkerColor(kGreen+2);
  tge_prot1020->SetMarkerColor(kBlue);
  tge_pion1020->SetMarkerStyle(kFullCircle);
  tge_kaon1020->SetMarkerStyle(kFullTriangleUp);
  tge_prot1020->SetMarkerStyle(kFullSquare);
  tge_syspion1020->SetMarkerColor(kRed-cad);   //new
  tge_syskaon1020->SetMarkerColor(kGreen-cad); //new
  tge_sysprot1020->SetMarkerColor(kBlue-cad);  //new
  tge_syspion1020->SetLineColor(kRed-cad);     //new
  tge_syskaon1020->SetLineColor(kGreen-cad);   //new
  tge_sysprot1020->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg1020 = new TMultiGraph();
  tmg1020->Add(tge_sys1020); // normalization from Glauber
  tmg1020->Add(tge_sysprot1020);
  tmg1020->Add(tge_syspion1020);
  tmg1020->Add(tge_syskaon1020);
  tmg1020->Add(tge_prot1020);
  tmg1020->Add(tge_pion1020);
  tmg1020->Add(tge_kaon1020);
  tmg1020->Add(tge_pi0_1020);
  tmg1020->Add(tge_phi_1020);
  tmg1020->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_1020[i]-pi0sys1020[i];
      double py2 = pi0_1020[i]+pi0sys1020[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_1020[i]-phisys_1020[i];
      double py2 = phi_1020[i]+phisys_1020[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg1020->SetMaximum(ymax);
  tmg1020->SetMinimum(ymin);
  tmg1020->GetXaxis()->SetLimits(xmin,xmax);
  tmg1020->GetYaxis()->SetTitle("R_{AA}");
  tmg1020->GetYaxis()->CenterTitle();
  tmg1020->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg1020->GetXaxis()->CenterTitle();
  tmg1020->GetXaxis()->SetLabelSize(0);
  tmg1020->GetXaxis()->SetTitleSize(0);
  tmg1020->GetXaxis()->SetTitleOffset(1.3);
  tmg1020->GetYaxis()->SetLabelSize(0);
  tmg1020->GetYaxis()->SetTitleSize(0);
  tmg1020->GetYaxis()->SetTitleOffset(1.3);
  tmg1020->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl1020 = new TLatex(0.65,0.85*ymax,"10-20%");
  tl1020->SetTextSize(textsize);
  tl1020->Draw();



  // ------------ //
  // --- 2040 --- //
  // ------------ //

  c1_3->cd();
  c1_3->SetTopMargin(0);
  c1_3->SetLeftMargin(0);
  c1_3->SetRightMargin(0);
  c1_3->SetBottomMargin(0);
  c1_3->SetTicks(1,1);
  tge_pion2040->SetMarkerColor(kRed);
  tge_kaon2040->SetMarkerColor(kGreen+2);
  tge_prot2040->SetMarkerColor(kBlue);
  tge_pion2040->SetMarkerStyle(kFullCircle);
  tge_kaon2040->SetMarkerStyle(kFullTriangleUp);
  tge_prot2040->SetMarkerStyle(kFullSquare);
  tge_syspion2040->SetMarkerColor(kRed-cad);   //new
  tge_syskaon2040->SetMarkerColor(kGreen-cad); //new
  tge_sysprot2040->SetMarkerColor(kBlue-cad);  //new
  tge_syspion2040->SetLineColor(kRed-cad);     //new
  tge_syskaon2040->SetLineColor(kGreen-cad);   //new
  tge_sysprot2040->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg2040 = new TMultiGraph();
  tmg2040->Add(tge_sys2040); // normalization from Galuber
  tmg2040->Add(tge_sysprot2040);
  tmg2040->Add(tge_syspion2040);
  tmg2040->Add(tge_syskaon2040);
  tmg2040->Add(tge_prot2040);
  tmg2040->Add(tge_pion2040);
  tmg2040->Add(tge_kaon2040);
  tmg2040->Add(tge_pi0_2040);
  tmg2040->Add(tge_phi_2040);
  tmg2040->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_2040[i]-pi0sys2040[i];
      double py2 = pi0_2040[i]+pi0sys2040[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_2040[i]-phisys_2040[i];
      double py2 = phi_2040[i]+phisys_2040[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg2040->SetMaximum(ymax);
  tmg2040->SetMinimum(ymin);
  tmg2040->GetXaxis()->SetLimits(xmin,xmax);
  tmg2040->GetYaxis()->SetTitle("R_{AA}");
  tmg2040->GetYaxis()->CenterTitle();
  tmg2040->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg2040->GetXaxis()->CenterTitle();
  tmg2040->GetXaxis()->SetLabelSize(0);
  tmg2040->GetXaxis()->SetTitleSize(0);
  tmg2040->GetXaxis()->SetTitleOffset(1.3);
  tmg2040->GetYaxis()->SetLabelSize(0);
  tmg2040->GetYaxis()->SetTitleSize(0);
  tmg2040->GetYaxis()->SetTitleOffset(1.3);
  tmg2040->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl2040 = new TLatex(0.65,0.85*ymax,"20-40%");
  tl2040->SetTextSize(textsize);
  tl2040->Draw();




  // ------------ //
  // --- 4060 --- //
  // ------------ //

  c1_4->cd();
  c1_4->SetTopMargin(0);
  c1_4->SetLeftMargin(0);
  c1_4->SetRightMargin(0);
  c1_4->SetBottomMargin(0);
  c1_4->SetTicks(1,1);
  tge_pion4060->SetMarkerColor(kRed);
  tge_kaon4060->SetMarkerColor(kGreen+2);
  tge_prot4060->SetMarkerColor(kBlue);
  tge_pion4060->SetMarkerStyle(kFullCircle);
  tge_kaon4060->SetMarkerStyle(kFullTriangleUp);
  tge_prot4060->SetMarkerStyle(kFullSquare);
  tge_syspion4060->SetMarkerColor(kRed-cad);   //new
  tge_syskaon4060->SetMarkerColor(kGreen-cad); //new
  tge_sysprot4060->SetMarkerColor(kBlue-cad);  //new
  tge_syspion4060->SetLineColor(kRed-cad);     //new
  tge_syskaon4060->SetLineColor(kGreen-cad);   //new
  tge_sysprot4060->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg4060 = new TMultiGraph();
  tmg4060->Add(tge_sys4060); // normalization from Glauber
  tmg4060->Add(tge_sysprot4060);
  tmg4060->Add(tge_syspion4060);
  tmg4060->Add(tge_syskaon4060);
  tmg4060->Add(tge_prot4060);
  tmg4060->Add(tge_pion4060);
  tmg4060->Add(tge_kaon4060);
  tmg4060->Add(tge_pi0_4060);
  tmg4060->Add(tge_phi_4060);
  tmg4060->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_4060[i]-pi0sys4060[i];
      double py2 = pi0_4060[i]+pi0sys4060[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_4060[i]-phisys_4060[i];
      double py2 = phi_4060[i]+phisys_4060[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg4060->SetMaximum(ymax);
  tmg4060->SetMinimum(ymin);
  tmg4060->GetXaxis()->SetLimits(xmin,xmax);
  tmg4060->GetYaxis()->SetTitle("R_{AA}");
  tmg4060->GetYaxis()->CenterTitle();
  tmg4060->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg4060->GetXaxis()->CenterTitle();
  tmg4060->GetXaxis()->SetLabelSize(0);
  tmg4060->GetXaxis()->SetTitleSize(0);
  tmg4060->GetXaxis()->SetTitleOffset(1.3);
  tmg4060->GetYaxis()->SetLabelSize(0);
  tmg4060->GetYaxis()->SetTitleSize(0);
  tmg4060->GetYaxis()->SetTitleOffset(1.3);
  tmg4060->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl4060 = new TLatex(0.65,0.85*ymax,"40-60%");
  tl4060->SetTextSize(textsize);
  tl4060->Draw();




  // ------------ //
  // --- 6092 --- //
  // ------------ //

  c1_5->cd();
  c1_5->SetTopMargin(0);
  c1_5->SetLeftMargin(0);
  c1_5->SetRightMargin(0);
  c1_5->SetBottomMargin(0);
  c1_5->SetTicks(1,1);
  tge_pion6092->SetMarkerColor(kRed);
  tge_kaon6092->SetMarkerColor(kGreen+2);
  tge_prot6092->SetMarkerColor(kBlue);
  tge_pion6092->SetMarkerStyle(kFullCircle);
  tge_kaon6092->SetMarkerStyle(kFullTriangleUp);
  tge_prot6092->SetMarkerStyle(kFullSquare);
  tge_syspion6092->SetMarkerColor(kRed-cad);   //new
  tge_syskaon6092->SetMarkerColor(kGreen-cad); //new
  tge_sysprot6092->SetMarkerColor(kBlue-cad);  //new
  tge_syspion6092->SetLineColor(kRed-cad);     //new
  tge_syskaon6092->SetLineColor(kGreen-cad);   //new
  tge_sysprot6092->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg6092 = new TMultiGraph();
  tmg6092->Add(tge_sys6092); // normalization from Glauber
  tmg6092->Add(tge_sysprot6092);
  tmg6092->Add(tge_syspion6092);
  tmg6092->Add(tge_syskaon6092);
  tmg6092->Add(tge_prot6092);
  tmg6092->Add(tge_pion6092);
  tmg6092->Add(tge_kaon6092);
  tmg6092->Add(tge_pi0_6092);
  tmg6092->Add(tge_phi_6092);
  tmg6092->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_6092[i]-pi0sys6092[i];
      double py2 = pi0_6092[i]+pi0sys6092[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_6092[i]-phisys_6092[i];
      double py2 = phi_6092[i]+phisys_6092[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg6092->SetMaximum(ymax);
  tmg6092->SetMinimum(ymin);
  tmg6092->GetXaxis()->SetLimits(xmin,xmax);
  tmg6092->GetYaxis()->SetTitle("R_{AA}");
  tmg6092->GetYaxis()->CenterTitle();
  tmg6092->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg6092->GetXaxis()->CenterTitle();
  tmg6092->GetXaxis()->SetLabelSize(0);
  tmg6092->GetXaxis()->SetTitleSize(0);
  tmg6092->GetXaxis()->SetTitleOffset(1.3);
  tmg6092->GetYaxis()->SetLabelSize(0);
  tmg6092->GetYaxis()->SetTitleSize(0);
  tmg6092->GetYaxis()->SetTitleOffset(1.3);
  tmg6092->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl6092 = new TLatex(0.65,0.85*ymax,"60-92%");
  tl6092->SetTextSize(textsize);
  tl6092->Draw();




  // ------------ //
  // --- XTRA --- //
  // ------------ //

  c1_6->cd();
  c1_6->SetTopMargin(0);
  c1_6->SetLeftMargin(0);
  c1_6->SetRightMargin(0);
  c1_6->SetBottomMargin(0);
  c1_6->SetTicks(1,1);
  TMultiGraph *tmgXTRA = new TMultiGraph();
  float p[1] = -9;
  TGraph *tg = new TGraph(1,p,p);
  tmgXTRA->Add(tg);
  tmgXTRA->Draw("apz");
  //line->Draw();
  tmgXTRA->SetMaximum(ymax);
  tmgXTRA->SetMinimum(ymin);
  tmgXTRA->GetXaxis()->SetLimits(xmin,xmax);
  tmgXTRA->GetYaxis()->SetTitle("R_{AA}");
  tmgXTRA->GetYaxis()->CenterTitle();
  tmgXTRA->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgXTRA->GetXaxis()->CenterTitle();
  tmgXTRA->GetXaxis()->SetLabelSize(0);
  tmgXTRA->GetXaxis()->SetTitleSize(0);
  tmgXTRA->GetXaxis()->SetTitleOffset(1.3);
  tmgXTRA->GetYaxis()->SetLabelSize(0);
  tmgXTRA->GetYaxis()->SetTitleSize(0);
  tmgXTRA->GetYaxis()->SetTitleOffset(1.3);
  tmgXTRA->GetYaxis()->SetNdivisions(ydivisions);

  //TLegend *leg = new TLegend(0.15,0.52,0.85,0.85);
  //TLegend *leg = new TLegend(0.15,0.42,0.85,0.88);
  TLegend *leg = new TLegend(0.07,0.15,0.65,0.85);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->AddEntry((TObject*)0,"Au+Au #sqrt{s_{NN}} = 200 GeV","");
  leg->AddEntry(tge_pion0010,"#pi^{-}+#pi^{+}","p");
  leg->AddEntry(tge_kaon0010,"K^{-}+K^{+}","p");
  leg->AddEntry(tge_prot0010,"#bar{p}+p","p");
  // leg->SetTextSize(textsize);
  // leg->Draw();

  // TLegend *leg = new TLegend(0.15,0.30,0.85,0.48);
  // leg->SetFillColor(kWhite);
  // leg->SetBorderSize(0);
  leg->AddEntry(tge_pi0_0010,"#pi^{0}","p");
  leg->AddEntry(tge_phi_0010,"#phi","p");
  leg->SetTextSize(textsize);
  leg->Draw();



  c1->Print("figures/auau_raa_newall.gif");
  c1->Print("figures/auau_raa_newall.eps");

  c1->Clear();
  delete c1;

  TCanvas *c2 = new TCanvas("c2","c2",1000,700);
  c2->cd();
  TPad *c2_1 = new TPad("c2_1","c2_1",left+0*width,bottom+1*height,left+1*width,bottom+2*height);
  c2_1->Draw();
  c2->cd();
  TPad *c2_2 = new TPad("c2_2","c2_2",left+1*width,bottom+1*height,left+2*width,bottom+2*height);
  c2_2->Draw();
  c2->cd();
  TPad *c2_3 = new TPad("c2_3","c2_3",left+2*width,bottom+1*height,left+3*width,bottom+2*height);
  c2_3->Draw();
  c2->cd();
  TPad *c2_4 = new TPad("c2_4","c2_4",left+0*width,bottom+0*height,left+1*width,bottom+1*height);
  c2_4->Draw();
  c2->cd();
  TPad *c2_5 = new TPad("c2_5","c2_5",left+1*width,bottom+0*height,left+2*width,bottom+1*height);
  c2_5->Draw();
  c2->cd();
  TPad *c2_6 = new TPad("c2_6","c2_6",left+2*width,bottom+0*height,left+3*width,bottom+1*height);
  c2_6->Draw();

  yaxis0->Draw();
  yaxis1->Draw();
  xaxis0->Draw();
  xaxis1->Draw();
  xaxis2->Draw();


  c2_1->cd();
  c2_1->SetTopMargin(0);
  c2_1->SetLeftMargin(0);
  c2_1->SetRightMargin(0);
  c2_1->SetBottomMargin(0);
  c2_1->SetTicks(1,1);
  tmgXTRA->Draw("apz");
  leg->Draw();



  // ------------ //
  // --- 0010 --- //
  // ------------ //

  c2_2->cd();
  c2_2->SetTopMargin(0);
  c2_2->SetLeftMargin(0);
  c2_2->SetRightMargin(0);
  c2_2->SetBottomMargin(0);
  c2_2->SetTicks(1,1);
  tmg0010->Draw("apz");
  tl0010->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_0010[i]-pi0sys0010[i];
      double py2 = pi0_0010[i]+pi0sys0010[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_0010[i]-phisys_0010[i];
      double py2 = phi_0010[i]+phisys_0010[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }



  // ------------ //
  // --- 1020 --- //
  // ------------ //

  c2_3->cd();
  c2_3->SetTopMargin(0);
  c2_3->SetLeftMargin(0);
  c2_3->SetRightMargin(0);
  c2_3->SetBottomMargin(0);
  c2_3->SetTicks(1,1);
  tmg1020->Draw("apz");
  tl1020->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_1020[i]-pi0sys1020[i];
      double py2 = pi0_1020[i]+pi0sys1020[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_1020[i]-phisys_1020[i];
      double py2 = phi_1020[i]+phisys_1020[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }




  // ------------ //
  // --- 2040 --- //
  // ------------ //

  c2_4->cd();
  c2_4->SetTopMargin(0);
  c2_4->SetLeftMargin(0);
  c2_4->SetRightMargin(0);
  c2_4->SetBottomMargin(0);
  c2_4->SetTicks(1,1);
  tmg2040->Draw("apz");
  tl2040->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_2040[i]-pi0sys2040[i];
      double py2 = pi0_2040[i]+pi0sys2040[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_2040[i]-phisys_2040[i];
      double py2 = phi_2040[i]+phisys_2040[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }




  // ------------ //
  // --- 4060 --- //
  // ------------ //

  c2_5->cd();
  c2_5->SetTopMargin(0);
  c2_5->SetLeftMargin(0);
  c2_5->SetRightMargin(0);
  c2_5->SetBottomMargin(0);
  c2_5->SetTicks(1,1);
  tmg4060->Draw("apz");
  tl4060->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_4060[i]-pi0sys4060[i];
      double py2 = pi0_4060[i]+pi0sys4060[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_4060[i]-phisys_4060[i];
      double py2 = phi_4060[i]+phisys_4060[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }




  // ------------ //
  // --- 6092 --- //
  // ------------ //

  c2_6->cd();
  c2_6->SetTopMargin(0);
  c2_6->SetLeftMargin(0);
  c2_6->SetRightMargin(0);
  c2_6->SetBottomMargin(0);
  c2_6->SetTicks(1,1);
  tmg6092->Draw("apz");
  tl6092->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_6092[i]-pi0sys6092[i];
      double py2 = pi0_6092[i]+pi0sys6092[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<9; i++)
    {
      double px1 = phipt[i]-0.15;
      double px2 = phipt[i]+0.15;
      double py1 = phi_6092[i]-phisys_6092[i];
      double py2 = phi_6092[i]+phisys_6092[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }



  c2->Print("figures/auau_raa_swapnewall.gif");
  c2->Print("figures/auau_raa_swapnewall.eps");

} // end of doitSPC


void doit4x4(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  //int width = 15;
  int width = 13;

  float pt_sys0010[1] = {0.76*maxx};
  float ept_sys0010[1] = {0.0};
  float point_sys0010[1] = {1.0};
  float epoint_sys0010[1] = {0.1};
  TGraphErrors *tge_sys0010 = new TGraphErrors(1,pt_sys0010,point_sys0010,ept_sys0010,epoint_sys0010);
  tge_sys0010->SetMarkerStyle(1);
  tge_sys0010->SetMarkerColor(kGray+2);
  tge_sys0010->SetLineWidth(width);
  tge_sys0010->SetLineColor(kGray+2);

  float pt_sys1020[1] = {0.80*maxx};
  float ept_sys1020[1] = {0.0};
  float point_sys1020[1] = {1.0};
  float epoint_sys1020[1] = {0.1};
  TGraphErrors *tge_sys1020 = new TGraphErrors(1,pt_sys1020,point_sys1020,ept_sys1020,epoint_sys1020);
  tge_sys1020->SetMarkerStyle(1);
  tge_sys1020->SetMarkerColor(kRed-7);
  tge_sys1020->SetLineWidth(width);
  tge_sys1020->SetLineColor(kRed-7);

  float pt_sys2040[1] = {0.84*maxx};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.1};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kBlue-7);
  tge_sys2040->SetLineWidth(width);
  tge_sys2040->SetLineColor(kBlue-7);

  float pt_sys4060[1] = {0.88*maxx};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.13};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGreen-7);
  tge_sys4060->SetLineWidth(width);
  tge_sys4060->SetLineColor(kGreen-7);

  float pt_sys6092[1] = {0.92*maxx};
  float ept_sys6092[1] = {0.0};
  float point_sys6092[1] = {1.0};
  float epoint_sys6092[1] = {0.23};
  TGraphErrors *tge_sys6092 = new TGraphErrors(1,pt_sys6092,point_sys6092,ept_sys6092,epoint_sys6092);
  tge_sys6092->SetMarkerStyle(1);
  tge_sys6092->SetMarkerColor(kMagenta-7);
  tge_sys6092->SetLineWidth(width);
  tge_sys6092->SetLineColor(kMagenta-7);

  cout<<"4x4"<<endl;

  cout<<"pion "<<pion<<endl;

  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TLine *line = new TLine(0.0,1.0,maxx,1.0);

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
  TLatex *tex1 = new TLatex(4.0,1.6,"#pi");
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
  TLatex *tex2 = new TLatex(4.0,1.6,"K");
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
  TLatex *tex3 = new TLatex(4.0,1.6,"p");
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
  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_sys0010);
  tmg->Add(tge_sys1020);
  tmg->Add(tge_sys2040);
  tmg->Add(tge_sys4060);
  tmg->Add(tge_sys6092);
  tmg->Draw("apz");
  line->Draw("same");
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
  // --------------------------------------- //
  TGraph *tge_0010 = new TGraph(1,dummy,dummy);
  TGraph *tge_1020 = new TGraph(1,dummy,dummy);
  TGraph *tge_2040 = new TGraph(1,dummy,dummy);
  TGraph *tge_4060 = new TGraph(1,dummy,dummy);
  TGraph *tge_6092 = new TGraph(1,dummy,dummy);
  tge_0010->SetMarkerColor(kBlack);
  tge_1020->SetMarkerColor(kRed);
  tge_2040->SetMarkerColor(kBlue);
  tge_4060->SetMarkerColor(kGreen+2);
  tge_6092->SetMarkerColor(kMagenta+2);
  tge_0010->SetMarkerStyle(kFullCircle);
  tge_1020->SetMarkerStyle(kFullSquare);
  tge_2040->SetMarkerStyle(kFullTriangleUp);
  tge_4060->SetMarkerStyle(kFullTriangleDown);
  tge_6092->SetMarkerStyle(kFullDiamond);
  TLegend *leg4 = new TLegend(0.05,0.60,0.5,0.95);
  leg4->SetBorderSize(0);
  leg4->SetFillColor(kWhite);
  leg4->AddEntry((TObject*)0,"Au+Au #sqrt{s_{NN}}=200 GeV","");
  // leg4->AddEntry((TObject*)0,"","");
  leg4->AddEntry(tge_0010,"R_{AA} 0-10%","p");
  leg4->AddEntry(tge_1020,"R_{AA} 10-20%","p");
  leg4->AddEntry(tge_2040,"R_{AA} 20-40%","p");
  leg4->AddEntry(tge_4060,"R_{AA} 40-60%","p");
  leg4->AddEntry(tge_6092,"R_{AA} 60-92%","p");
  leg4->SetTextSize(0.045); // 0.04 works okay, 0.05 is a bit big, too big for padmargin>0.1
  leg4->Draw();


  c1->Print("figures/auau_raa_all.gif");
  c1->Print("figures/auau_raa_all.eps");

  c1->Clear();
  delete c1;

} // end of doit4x4


void doit(int r7pid=2, int number=27, bool chavers=true)
{

  float sysvalue = 0.1; // original 0.05, should be 0.1 (or 0.14?) because nothing cancels across species
  // COME BACK HERE
  if(r7pid<=3) sysvalue = 0.1;
  if(r7pid>=6) sysvalue = 0.11;
  if(r7pid==4||r7pid==5) sysvalue = 0.11;

  int simple = 0;
 
  if(simple==2) sysvalue = 0.1;

  TCanvas *c1 = new TCanvas();

  char filename[100];

  int width = 13;

  float pt_sys0010[1] = {0.76*maxx};
  float ept_sys0010[1] = {0.0};
  float point_sys0010[1] = {1.0};
  float epoint_sys0010[1] = {0.1};
  TGraphErrors *tge_sys0010 = new TGraphErrors(1,pt_sys0010,point_sys0010,ept_sys0010,epoint_sys0010);
  tge_sys0010->SetMarkerStyle(1);
  tge_sys0010->SetMarkerColor(kGray+2);
  tge_sys0010->SetLineWidth(width);
  tge_sys0010->SetLineColor(kGray+2);

  float pt_sys1020[1] = {0.80*maxx};
  float ept_sys1020[1] = {0.0};
  float point_sys1020[1] = {1.0};
  float epoint_sys1020[1] = {0.1};
  TGraphErrors *tge_sys1020 = new TGraphErrors(1,pt_sys1020,point_sys1020,ept_sys1020,epoint_sys1020);
  tge_sys1020->SetMarkerStyle(1);
  tge_sys1020->SetMarkerColor(kRed-7);
  tge_sys1020->SetLineWidth(width);
  tge_sys1020->SetLineColor(kRed-7);

  float pt_sys2040[1] = {0.84*maxx};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.1};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kBlue-7);
  tge_sys2040->SetLineWidth(width);
  tge_sys2040->SetLineColor(kBlue-7);

  float pt_sys4060[1] = {0.88*maxx};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.13};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGreen-7);
  tge_sys4060->SetLineWidth(width);
  tge_sys4060->SetLineColor(kGreen-7);

  float pt_sys6092[1] = {0.92*maxx};
  float ept_sys6092[1] = {0.0};
  float point_sys6092[1] = {1.0};
  float epoint_sys6092[1] = {0.22};
  TGraphErrors *tge_sys6092 = new TGraphErrors(1,pt_sys6092,point_sys6092,ept_sys6092,epoint_sys6092);
  tge_sys6092->SetMarkerStyle(1);
  tge_sys6092->SetMarkerColor(kMagenta-7);
  tge_sys6092->SetLineWidth(width);
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r7pid<=3||r7pid>=6)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_auau0010[i] = sysvalueX*ratiopos_auau0010[i];
      esysrationeg_auau0010[i] = sysvalueX*rationeg_auau0010[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r7pid<=3||r7pid>=6)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_auau1020[i] = sysvalueX*ratiopos_auau1020[i];
      esysrationeg_auau1020[i] = sysvalueX*rationeg_auau1020[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r7pid<=3||r7pid>=6)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_auau2040[i] = sysvalueX*ratiopos_auau2040[i];
      esysrationeg_auau2040[i] = sysvalueX*rationeg_auau2040[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r7pid<=3||r7pid>=6)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_auau4060[i] = sysvalueX*ratiopos_auau4060[i];
      esysrationeg_auau4060[i] = sysvalueX*rationeg_auau4060[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r7pid<=3||r7pid>=6)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_auau6092[i] = sysvalueX*ratiopos_auau6092[i];
      esysrationeg_auau6092[i] = sysvalueX*rationeg_auau6092[i];
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






  tge_ratiopos_auau0010->SetName("tge_ratiopos_auau0010");
  tge_ratiopos_auau1020->SetName("tge_ratiopos_auau1020");
  tge_ratiopos_auau2040->SetName("tge_ratiopos_auau2040");
  tge_ratiopos_auau4060->SetName("tge_ratiopos_auau4060");
  tge_ratiopos_auau6092->SetName("tge_ratiopos_auau6092");

  tge_sysratiopos_auau0010->SetName("tge_sysratiopos_auau0010");
  tge_sysratiopos_auau1020->SetName("tge_sysratiopos_auau1020");
  tge_sysratiopos_auau2040->SetName("tge_sysratiopos_auau2040");
  tge_sysratiopos_auau4060->SetName("tge_sysratiopos_auau4060");
  tge_sysratiopos_auau6092->SetName("tge_sysratiopos_auau6092");

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
  // tmgpos1->Add(tge_sys0010);
  // tmgpos1->Add(tge_sys1020);
  // tmgpos1->Add(tge_sys2040);
  // tmgpos1->Add(tge_sys4060);
  // tmgpos1->Add(tge_sys6092);
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
  TLine *line = new TLine(0.0,1.0,maxx,1.0);
  line->Draw();
  tmgpos1->SetMaximum(2.0);
  tmgpos1->SetMinimum(0.0);
  tmgpos1->GetXaxis()->SetLimits(0.0,maxx);
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
  tmgneg1->GetXaxis()->SetLimits(0.0,maxx);
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
  //c1->Print(figname);
  sprintf(figname,"figures/auau_raa_%s.eps",particle);
  //c1->Print(figname);


  if(r7pid<=3)      tmg_pion = (TMultiGraph *)tmgpos1->Clone();
  else if(r7pid>=6) tmg_prot = (TMultiGraph *)tmgpos1->Clone();
  else              tmg_kaon = (TMultiGraph *)tmgpos1->Clone();


  c1->Clear();
  delete c1;


}
