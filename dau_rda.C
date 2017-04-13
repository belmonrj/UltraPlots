TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;




float minx = 0.00;
//float maxx = 5.99;
//float maxx = 5.00;
float maxx = 6.00;
//float maxx = 4.8;




void dau_rda()
{

  // ------------------- //
  // --- old binning --- //
  // doit(1,27,true);    //
  // doit(3,16,true);    //
  // doit(5,33,true);    //
  //                     //
  // ------------------- //

  doit(1,22,true);
  doit(3,16,true);
  doit(5,24,true);

  doit4x4(tmg_pion,tmg_kaon,tmg_prot);
  doitSPC(tmg_pion,tmg_kaon,tmg_prot);

}


void doitSPC(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{



  float PT = 0.3;
  int WIDTH = 10;

  float pt_sys0020[1] = {PT};
  float ept_sys0020[1] = {0.0};
  float point_sys0020[1] = {1.0};
  float epoint_sys0020[1] = {0.066};
  TGraphErrors *tge_sys0020 = new TGraphErrors(1,pt_sys0020,point_sys0020,ept_sys0020,epoint_sys0020);
  tge_sys0020->SetMarkerStyle(1);
  tge_sys0020->SetMarkerColor(kGray+2);
  tge_sys0020->SetLineWidth(WIDTH);
  tge_sys0020->SetLineColor(kGray+2);

  float pt_sys2040[1] = {PT};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.069};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kGray+2);
  tge_sys2040->SetLineWidth(WIDTH);
  tge_sys2040->SetLineColor(kGray+2);

  float pt_sys0088[1] = {PT};
  float ept_sys0088[1] = {0.0};
  float point_sys0088[1] = {1.0};
  float epoint_sys0088[1] = {0.053};
  TGraphErrors *tge_sys0088 = new TGraphErrors(1,pt_sys0088,point_sys0088,ept_sys0088,epoint_sys0088);
  tge_sys0088->SetMarkerStyle(1);
  tge_sys0088->SetMarkerColor(kGray+2);
  tge_sys0088->SetLineWidth(WIDTH);
  tge_sys0088->SetLineColor(kGray+2);

  float pt_sys4060[1] = {PT};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.061};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGray+2);
  tge_sys4060->SetLineWidth(WIDTH);
  tge_sys4060->SetLineColor(kGray+2);

  float pt_sys6088[1] = {PT};
  float ept_sys6088[1] = {0.0};
  float point_sys6088[1] = {1.0};
  float epoint_sys6088[1] = {0.065};
  TGraphErrors *tge_sys6088 = new TGraphErrors(1,pt_sys6088,point_sys6088,ept_sys6088,epoint_sys6088);
  tge_sys6088->SetMarkerStyle(1);
  tge_sys6088->SetMarkerColor(kGray+2);
  tge_sys6088->SetLineWidth(WIDTH);
  tge_sys6088->SetLineColor(kGray+2);






  float pt[18], ratio[18], eratio[18], esysratio[18];
  float tmp;
  ifstream fpi0;

  //fpi0.open("ExtraData/NeutralPion/ppg044_RdA0088.dat");
  fpi0.open("ExtraData/NeutralPion/ppg044_RdA0100.dat"); // which one?
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_0088[18]; for(int i=0; i<18; i++){pi0_0088[i]=ratio[i];}
  float pi0sys0088[18]; for(int i=0; i<18; i++){pi0sys0088[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_syspi0_0088 = new TGraphErrors(18,pt,ratio,0,esysratio);
  TGraphErrors *tge_pi0_0088 = new TGraphErrors(18,pt,ratio,0,eratio);
  fpi0.open("ExtraData/NeutralPion/ppg044_RdA0020.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_0020[18]; for(int i=0; i<18; i++){pi0_0020[i]=ratio[i];}
  float pi0sys0020[18]; for(int i=0; i<18; i++){pi0sys0020[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_syspi0_0020 = new TGraphErrors(18,pt,ratio,0,esysratio);
  TGraphErrors *tge_pi0_0020 = new TGraphErrors(18,pt,ratio,0,eratio);
  fpi0.open("ExtraData/NeutralPion/ppg044_RdA2040.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_2040[18]; for(int i=0; i<18; i++){pi0_2040[i]=ratio[i];}
  float pi0sys2040[18]; for(int i=0; i<18; i++){pi0sys2040[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_syspi0_2040 = new TGraphErrors(18,pt,ratio,0,esysratio);
  TGraphErrors *tge_pi0_2040 = new TGraphErrors(18,pt,ratio,0,eratio);
  fpi0.open("ExtraData/NeutralPion/ppg044_RdA4060.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_4060[18]; for(int i=0; i<18; i++){pi0_4060[i]=ratio[i];}
  float pi0sys4060[18]; for(int i=0; i<18; i++){pi0sys4060[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_syspi0_4060 = new TGraphErrors(18,pt,ratio,0,esysratio);
  TGraphErrors *tge_pi0_4060 = new TGraphErrors(18,pt,ratio,0,eratio);
  fpi0.open("ExtraData/NeutralPion/ppg044_RdA6088.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];}
  float pi0_6088[18]; for(int i=0; i<18; i++){pi0_6088[i]=ratio[i];}
  float pi0sys6088[18]; for(int i=0; i<18; i++){pi0sys6088[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_6088 = new TGraphErrors(18,pt,ratio,0,eratio);
  TGraphErrors *tge_syspi0_6088 = new TGraphErrors(18,pt,ratio,0,esysratio);

  tge_pi0_0088->SetMarkerStyle(kOpenCircle);
  tge_pi0_0020->SetMarkerStyle(kOpenCircle);
  tge_pi0_2040->SetMarkerStyle(kOpenCircle);
  tge_pi0_4060->SetMarkerStyle(kOpenCircle);
  tge_pi0_6088->SetMarkerStyle(kOpenCircle);

  tge_syspi0_0088->SetMarkerStyle(1);
  tge_syspi0_0088->SetMarkerColor(kGray);
  tge_syspi0_0088->SetFillColor(kGray);
  tge_syspi0_0088->SetLineColor(kGray);
  tge_syspi0_0088->SetLineWidth(15);
  tge_syspi0_0020->SetMarkerStyle(1);
  tge_syspi0_0020->SetMarkerColor(kGray);
  tge_syspi0_0020->SetFillColor(kGray);
  tge_syspi0_0020->SetLineColor(kGray);
  tge_syspi0_0020->SetLineWidth(15);
  tge_syspi0_2040->SetMarkerStyle(1);
  tge_syspi0_2040->SetMarkerColor(kGray);
  tge_syspi0_2040->SetFillColor(kGray);
  tge_syspi0_2040->SetLineColor(kGray);
  tge_syspi0_2040->SetLineWidth(15);
  tge_syspi0_4060->SetMarkerStyle(1);
  tge_syspi0_4060->SetMarkerColor(kGray);
  tge_syspi0_4060->SetFillColor(kGray);
  tge_syspi0_4060->SetLineColor(kGray);
  tge_syspi0_4060->SetLineWidth(15);
  tge_syspi0_6088->SetMarkerStyle(1);
  tge_syspi0_6088->SetMarkerColor(kGray);
  tge_syspi0_6088->SetFillColor(kGray);
  tge_syspi0_6088->SetLineColor(kGray);
  tge_syspi0_6088->SetLineWidth(15);


  // tge_pi0_0088->SetMarkerStyle(kFullCircle);
  // tge_pi0_0020->SetMarkerStyle(kFullCircle);
  // tge_pi0_2040->SetMarkerStyle(kFullCircle);
  // tge_pi0_4060->SetMarkerStyle(kFullCircle);
  // tge_pi0_6088->SetMarkerStyle(kFullCircle);



  for(int i=0; i<18; i++){pt[i]=-9,ratio[i]=-9;eratio[i]=-9;}


  ifstream fphi;


  //float phi_0088[18]; for(int i=0; i<18; i++){phi_0088[i]=ratio[i];}
  //float phisys0088[18]; for(int i=0; i<18; i++){phisys0088[i]=esysratio[i];}

  float       phipt[10];
  float    phi_0088[10];
  float phisys_0088[10];
  float    phi_0020[10];
  float phisys_0020[10];
  float    phi_2040[10];
  float phisys_2040[10];
  float    phi_4060[10];
  float phisys_4060[10];
  float    phi_6088[10];
  float phisys_6088[10];

  fphi.open("ExtraData/PhiMeson/phi_RdA_cent0088.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phipt[i]=pt[i];phi_0088[i]=ratio[i];phisys_0088[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_0088 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_0088 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RdA_cent0020.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_0020[i]=ratio[i];phisys_0020[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_0020 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_0020 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RdA_cent2040.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_2040[i]=ratio[i];phisys_2040[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_2040 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_2040 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RdA_cent4060.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_4060[i]=ratio[i];phisys_4060[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_4060 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_4060 = new TGraphErrors(10,pt,ratio,0,esysratio);
  fphi.open("ExtraData/PhiMeson/phi_RdA_cent6088.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phi_6088[i]=ratio[i];phisys_6088[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_6088 = new TGraphErrors(10,pt,ratio,0,eratio);
  TGraphErrors *tge_sysphi_6088 = new TGraphErrors(10,pt,ratio,0,esysratio);

  tge_phi_0088->SetMarkerStyle(kOpenCross);
  tge_phi_0020->SetMarkerStyle(kOpenCross);
  tge_phi_2040->SetMarkerStyle(kOpenCross);
  tge_phi_4060->SetMarkerStyle(kOpenCross);
  tge_phi_6088->SetMarkerStyle(kOpenCross);
  // tge_phi_0088->SetMarkerStyle(kFullCross);
  // tge_phi_0020->SetMarkerStyle(kFullCross);
  // tge_phi_2040->SetMarkerStyle(kFullCross);
  // tge_phi_4060->SetMarkerStyle(kFullCross);
  // tge_phi_6088->SetMarkerStyle(kFullCross);

  tge_sysphi_0088->SetMarkerStyle(1);
  tge_sysphi_0088->SetMarkerColor(kGray);
  tge_sysphi_0088->SetFillColor(kGray);
  tge_sysphi_0088->SetLineColor(kGray);
  tge_sysphi_0088->SetLineWidth(15);
  tge_sysphi_0020->SetMarkerStyle(1);
  tge_sysphi_0020->SetMarkerColor(kGray);
  tge_sysphi_0020->SetFillColor(kGray);
  tge_sysphi_0020->SetLineColor(kGray);
  tge_sysphi_0020->SetLineWidth(15);
  tge_sysphi_2040->SetMarkerStyle(1);
  tge_sysphi_2040->SetMarkerColor(kGray);
  tge_sysphi_2040->SetFillColor(kGray);
  tge_sysphi_2040->SetLineColor(kGray);
  tge_sysphi_2040->SetLineWidth(15);
  tge_sysphi_4060->SetMarkerStyle(1);
  tge_sysphi_4060->SetMarkerColor(kGray);
  tge_sysphi_4060->SetFillColor(kGray);
  tge_sysphi_4060->SetLineColor(kGray);
  tge_sysphi_4060->SetLineWidth(15);
  tge_sysphi_6088->SetMarkerStyle(1);
  tge_sysphi_6088->SetMarkerColor(kGray);
  tge_sysphi_6088->SetFillColor(kGray);
  tge_sysphi_6088->SetLineColor(kGray);
  tge_sysphi_6088->SetLineWidth(15);




  cout<<"pion "<<pion<<endl;

  // pion
  TGraphErrors *tge_pion0088 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_dau0088");
  TGraphErrors *tge_pion0020 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_dau0020");
  TGraphErrors *tge_pion2040 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_dau2040");
  TGraphErrors *tge_pion4060 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_dau4060");
  TGraphErrors *tge_pion6088 = pion->GetListOfGraphs()->FindObject("tge_ratiopos_dau6088");
  TGraphErrors *tge_syspion0088 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_dau0088");
  TGraphErrors *tge_syspion0020 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_dau0020");
  TGraphErrors *tge_syspion2040 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_dau2040");
  TGraphErrors *tge_syspion4060 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_dau4060");
  TGraphErrors *tge_syspion6088 = pion->GetListOfGraphs()->FindObject("tge_sysratiopos_dau6088");
  // kaon
  TGraphErrors *tge_kaon0088 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_dau0088");
  TGraphErrors *tge_kaon0020 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_dau0020");
  TGraphErrors *tge_kaon2040 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_dau2040");
  TGraphErrors *tge_kaon4060 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_dau4060");
  TGraphErrors *tge_kaon6088 = kaon->GetListOfGraphs()->FindObject("tge_ratiopos_dau6088");
  TGraphErrors *tge_syskaon0088 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_dau0088");
  TGraphErrors *tge_syskaon0020 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_dau0020");
  TGraphErrors *tge_syskaon2040 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_dau2040");
  TGraphErrors *tge_syskaon4060 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_dau4060");
  TGraphErrors *tge_syskaon6088 = kaon->GetListOfGraphs()->FindObject("tge_sysratiopos_dau6088");
  // prot
  TGraphErrors *tge_prot0088 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_dau0088");
  TGraphErrors *tge_prot0020 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_dau0020");
  TGraphErrors *tge_prot2040 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_dau2040");
  TGraphErrors *tge_prot4060 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_dau4060");
  TGraphErrors *tge_prot6088 = prot->GetListOfGraphs()->FindObject("tge_ratiopos_dau6088");
  TGraphErrors *tge_sysprot0088 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_dau0088");
  TGraphErrors *tge_sysprot0020 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_dau0020");
  TGraphErrors *tge_sysprot2040 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_dau2040");
  TGraphErrors *tge_sysprot4060 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_dau4060");
  TGraphErrors *tge_sysprot6088 = prot->GetListOfGraphs()->FindObject("tge_sysratiopos_dau6088");

  cout<<"tge_pion0088 "<<tge_pion0088<<endl;
  cout<<"tge_kaon0088 "<<tge_kaon0088<<endl;
  cout<<"tge_prot0088 "<<tge_prot0088<<endl;

  TCanvas *c1 = new TCanvas("c1","c1",1000,700);

  float left = 0.07;
  float bottom = 0.09;
  float width = 0.3;
  float height = 0.43;

  float xmin = 0.0;
  float xmax = 6.0;
  float ymin = 0.0;
  //float ymax = 3.0;
  float ymax = 2.2;
  float labelsize = 0.08;
  float textsize = 0.08;
  //int divisions = 510; // too clustered for ymax=2.2
  int xdivisions = 510;
  int ydivisions = 505;


  TLine *line = new TLine(xmin,1.0,xmax,1.0);
  line->SetLineStyle(2);


  c1->cd();
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
  //TGaxis *yaxis0 = new TGaxis(left,bottom+0*height,left,bottom+1*height,ymin,ymax,divisions,"");
  TGaxis *yaxis0 = new TGaxis(left,bottom+0*height,left,bottom+1*height,ymin,ymax-1e-4,ydivisions,"");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("R_{dA}");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(labelsize/scale);
  yaxis0->SetTitleSize(labelsize/scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->Draw();
  TGaxis *yaxis1 = new TGaxis(left,bottom+1*height,left,bottom+2*height,ymin,ymax,ydivisions,"");
  yaxis1->SetName("yaxis1");
  yaxis1->SetTitle("R_{dA}");
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






  tge_pi0_0088->SetMarkerColor(kRed);
  tge_pi0_0020->SetMarkerColor(kRed);
  tge_pi0_2040->SetMarkerColor(kRed);
  tge_pi0_4060->SetMarkerColor(kRed);
  tge_pi0_6088->SetMarkerColor(kRed);


  c1_1->cd();
  c1_1->SetTopMargin(0);
  c1_1->SetLeftMargin(0);
  c1_1->SetRightMargin(0);
  c1_1->SetBottomMargin(0);
  c1_1->SetTicks(1,1);
  tge_pion0020->SetMarkerColor(kRed);
  tge_kaon0020->SetMarkerColor(kGreen+2);
  tge_prot0020->SetMarkerColor(kBlue);
  tge_pion0020->SetMarkerStyle(kFullCircle);
  tge_kaon0020->SetMarkerStyle(kFullTriangleUp);
  tge_prot0020->SetMarkerStyle(kFullSquare);
  int cad = 9; // color adjustment
  tge_syspion0020->SetMarkerColor(kRed-cad);   //new
  tge_syskaon0020->SetMarkerColor(kGreen-cad); //new
  tge_sysprot0020->SetMarkerColor(kBlue-cad);  //new
  tge_syspion0020->SetLineColor(kRed-cad);     //new
  tge_syskaon0020->SetLineColor(kGreen-cad);   //new
  tge_sysprot0020->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg0020 = new TMultiGraph();
  //tmg0020->Add(tge_syspi0_0020);
  //tmg0020->Add(tge_sysphi_0020);
  tmg0020->Add(tge_sys0020); // normalization from Glauber
  tmg0020->Add(tge_sysprot0020);
  tmg0020->Add(tge_syspion0020);
  tmg0020->Add(tge_syskaon0020);
  tmg0020->Add(tge_prot0020);
  tmg0020->Add(tge_pion0020);
  tmg0020->Add(tge_kaon0020);
  tmg0020->Add(tge_pi0_0020);
  tmg0020->Add(tge_phi_0020);
  tmg0020->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_0020[i]-pi0sys0020[i];
      double py2 = pi0_0020[i]+pi0sys0020[i];
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
      double py1 = phi_0020[i]-phisys_0020[i];
      double py2 = phi_0020[i]+phisys_0020[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg0020->SetMaximum(ymax);
  tmg0020->SetMinimum(ymin);
  tmg0020->GetXaxis()->SetLimits(xmin,xmax);
  tmg0020->GetYaxis()->SetTitle("R_{dA}");
  tmg0020->GetYaxis()->CenterTitle();
  tmg0020->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg0020->GetXaxis()->CenterTitle();
  tmg0020->GetXaxis()->SetLabelSize(0);
  tmg0020->GetXaxis()->SetTitleSize(0);
  tmg0020->GetXaxis()->SetTitleOffset(1.3);
  tmg0020->GetYaxis()->SetLabelSize(0);
  tmg0020->GetYaxis()->SetTitleSize(0);
  tmg0020->GetYaxis()->SetTitleOffset(1.3);
  tmg0020->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl0020 = new TLatex(0.65,0.85*ymax,"0-20%");
  tl0020->SetTextSize(textsize);
  tl0020->Draw();



  // ------------ //
  // --- 2040 --- //
  // ------------ //

  c1_2->cd();
  c1_2->SetTopMargin(0);
  c1_2->SetLeftMargin(0);
  c1_2->SetRightMargin(0);
  c1_2->SetBottomMargin(0);
  c1_2->SetTicks(1,1);
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
  //tmg2040->Add(tge_syspi0_2040);
  //tmg2040->Add(tge_sysphi_2040);
  tmg2040->Add(tge_sys2040); // normalization from Glauber
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
  tmg2040->GetYaxis()->SetTitle("R_{dA}");
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
  // --- 0088 --- //
  // ------------ //

  c1_3->cd();
  c1_3->SetTopMargin(0);
  c1_3->SetLeftMargin(0);
  c1_3->SetRightMargin(0);
  c1_3->SetBottomMargin(0);
  c1_3->SetTicks(1,1);
  tge_pion0088->SetMarkerColor(kRed);
  tge_kaon0088->SetMarkerColor(kGreen+2);
  tge_prot0088->SetMarkerColor(kBlue);
  tge_pion0088->SetMarkerStyle(kFullCircle);
  tge_kaon0088->SetMarkerStyle(kFullTriangleUp);
  tge_prot0088->SetMarkerStyle(kFullSquare);
  tge_syspion0088->SetMarkerColor(kRed-cad);   //new
  tge_syskaon0088->SetMarkerColor(kGreen-cad); //new
  tge_sysprot0088->SetMarkerColor(kBlue-cad);  //new
  tge_syspion0088->SetLineColor(kRed-cad);     //new
  tge_syskaon0088->SetLineColor(kGreen-cad);   //new
  tge_sysprot0088->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg0088 = new TMultiGraph();
  //tmg0088->Add(tge_syspi0_0088);
  //tmg0088->Add(tge_sysphi_0088);
  tmg0088->Add(tge_sys0088); // normalization from Glauber
  tmg0088->Add(tge_sysprot0088);
  tmg0088->Add(tge_syspion0088);
  tmg0088->Add(tge_syskaon0088);
  tmg0088->Add(tge_prot0088);
  tmg0088->Add(tge_pion0088);
  tmg0088->Add(tge_kaon0088);
  tmg0088->Add(tge_pi0_0088);
  tmg0088->Add(tge_phi_0088);
  tmg0088->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_0088[i]-pi0sys0088[i];
      double py2 = pi0_0088[i]+pi0sys0088[i];
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
      double py1 = phi_0088[i]-phisys_0088[i];
      double py2 = phi_0088[i]+phisys_0088[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg0088->SetMaximum(ymax);
  tmg0088->SetMinimum(ymin);
  tmg0088->GetXaxis()->SetLimits(xmin,xmax);
  tmg0088->GetYaxis()->SetTitle("R_{dA}");
  tmg0088->GetYaxis()->CenterTitle();
  tmg0088->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg0088->GetXaxis()->CenterTitle();
  tmg0088->GetXaxis()->SetLabelSize(0);
  tmg0088->GetXaxis()->SetTitleSize(0);
  tmg0088->GetXaxis()->SetTitleOffset(1.3);
  tmg0088->GetYaxis()->SetLabelSize(0);
  tmg0088->GetYaxis()->SetTitleSize(0);
  tmg0088->GetYaxis()->SetTitleOffset(1.3);
  tmg0088->GetYaxis()->SetNdivisions(ydivisions);
  //TLatex *tl0088 = new TLatex(0.65,0.85*ymax,"min. bias");
  TLatex *tl0088 = new TLatex(0.65,0.85*ymax,"0-100%");
  tl0088->SetTextSize(textsize);
  tl0088->Draw();




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
  //tmg4060->Add(tge_syspi0_4060);
  //tmg4060->Add(tge_sysphi_4060);
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
  tmg4060->GetYaxis()->SetTitle("R_{dA}");
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
  // --- 6088 --- //
  // ------------ //

  c1_5->cd();
  c1_5->SetTopMargin(0);
  c1_5->SetLeftMargin(0);
  c1_5->SetRightMargin(0);
  c1_5->SetBottomMargin(0);
  c1_5->SetTicks(1,1);
  tge_pion6088->SetMarkerColor(kRed);
  tge_kaon6088->SetMarkerColor(kGreen+2);
  tge_prot6088->SetMarkerColor(kBlue);
  tge_pion6088->SetMarkerStyle(kFullCircle);
  tge_kaon6088->SetMarkerStyle(kFullTriangleUp);
  tge_prot6088->SetMarkerStyle(kFullSquare);
  tge_syspion6088->SetMarkerColor(kRed-cad);   //new
  tge_syskaon6088->SetMarkerColor(kGreen-cad); //new
  tge_sysprot6088->SetMarkerColor(kBlue-cad);  //new
  tge_syspion6088->SetLineColor(kRed-cad);     //new
  tge_syskaon6088->SetLineColor(kGreen-cad);   //new
  tge_sysprot6088->SetLineColor(kBlue-cad);    //new
  TMultiGraph *tmg6088 = new TMultiGraph();
  //tmg6088->Add(tge_syspi0_6088);
  //tmg6088->Add(tge_sysphi_6088);
  tmg6088->Add(tge_sys6088); // normalization from Glauber
  tmg6088->Add(tge_sysprot6088);
  tmg6088->Add(tge_syspion6088);
  tmg6088->Add(tge_syskaon6088);
  tmg6088->Add(tge_prot6088);
  tmg6088->Add(tge_pion6088);
  tmg6088->Add(tge_kaon6088);
  tmg6088->Add(tge_pi0_6088);
  tmg6088->Add(tge_phi_6088);
  tmg6088->Draw("apz");
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_6088[i]-pi0sys6088[i];
      double py2 = pi0_6088[i]+pi0sys6088[i];
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
      double py1 = phi_6088[i]-phisys_6088[i];
      double py2 = phi_6088[i]+phisys_6088[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  tmg6088->SetMaximum(ymax);
  tmg6088->SetMinimum(ymin);
  tmg6088->GetXaxis()->SetLimits(xmin,xmax);
  tmg6088->GetYaxis()->SetTitle("R_{dA}");
  tmg6088->GetYaxis()->CenterTitle();
  tmg6088->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg6088->GetXaxis()->CenterTitle();
  tmg6088->GetXaxis()->SetLabelSize(0);
  tmg6088->GetXaxis()->SetTitleSize(0);
  tmg6088->GetXaxis()->SetTitleOffset(1.3);
  tmg6088->GetYaxis()->SetLabelSize(0);
  tmg6088->GetYaxis()->SetTitleSize(0);
  tmg6088->GetYaxis()->SetTitleOffset(1.3);
  tmg6088->GetYaxis()->SetNdivisions(ydivisions);
  TLatex *tl6088 = new TLatex(0.65,0.85*ymax,"60-88%");
  tl6088->SetTextSize(textsize);
  tl6088->Draw();




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
  tmgXTRA->GetYaxis()->SetTitle("R_{dA}");
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
  //TLegend *leg = new TLegend(0.15,0.20,0.85,0.80);
  TLegend *leg = new TLegend(0.07,0.15,0.65,0.85);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->AddEntry((TObject*)0,"d+Au #sqrt{s_{NN}} = 200 GeV","");
  leg->AddEntry(tge_pion0088,"#pi^{-}+#pi^{+}","p");
  leg->AddEntry(tge_kaon0088,"K^{-}+K^{+}","p");
  leg->AddEntry(tge_prot0088,"#bar{p}+p","p");
  // leg->SetTextSize(textsize);
  // leg->Draw();
  // TLegend *leg = new TLegend(0.15,0.30,0.85,0.48);
  // leg->SetFillColor(kWhite);
  // leg->SetBorderSize(0);
  leg->AddEntry(tge_pi0_0088,"#pi^{0}","p");
  leg->AddEntry(tge_phi_0088,"#phi","p");
  leg->SetTextSize(textsize);
  //leg->SetTextSize(textsize+0.015);//LEGEND TESTING!!!
  leg->Draw();



  c1->Print("figures/dau_rda_newall.gif");
  c1->Print("figures/dau_rda_newall.eps");


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
  // --- 0020 --- //
  // ------------ //

  c2_2->cd();
  c2_2->SetTopMargin(0);
  c2_2->SetLeftMargin(0);
  c2_2->SetRightMargin(0);
  c2_2->SetBottomMargin(0);
  c2_2->SetTicks(1,1);
  tmg0020->Draw("apz");
  tl0020->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_0020[i]-pi0sys0020[i];
      double py2 = pi0_0020[i]+pi0sys0020[i];
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
      double py1 = phi_0020[i]-phisys_0020[i];
      double py2 = phi_0020[i]+phisys_0020[i];
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

  c2_3->cd();
  c2_3->SetTopMargin(0);
  c2_3->SetLeftMargin(0);
  c2_3->SetRightMargin(0);
  c2_3->SetBottomMargin(0);
  c2_3->SetTicks(1,1);
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
  // --- 0088 --- //
  // ------------ //

  c2_4->cd();
  c2_4->SetTopMargin(0);
  c2_4->SetLeftMargin(0);
  c2_4->SetRightMargin(0);
  c2_4->SetBottomMargin(0);
  c2_4->SetTicks(1,1);
  tmg0088->Draw("apz");
  tl0088->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_0088[i]-pi0sys0088[i];
      double py2 = pi0_0088[i]+pi0sys0088[i];
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
      double py1 = phi_0088[i]-phisys_0088[i];
      double py2 = phi_0088[i]+phisys_0088[i];
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
  // --- 6088 --- //
  // ------------ //

  c2_6->cd();
  c2_6->SetTopMargin(0);
  c2_6->SetLeftMargin(0);
  c2_6->SetRightMargin(0);
  c2_6->SetBottomMargin(0);
  c2_6->SetTicks(1,1);
  tmg6088->Draw("apz");
  tl6088->Draw();
  line->Draw();
  for(int i=0; i<10; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_6088[i]-pi0sys6088[i];
      double py2 = pi0_6088[i]+pi0sys6088[i];
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
      double py1 = phi_6088[i]-phisys_6088[i];
      double py2 = phi_6088[i]+phisys_6088[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }



  c2->Print("figures/dau_rda_swapnewall.gif");
  c2->Print("figures/dau_rda_swapnewall.eps");

}




void doit4x4(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  int width = 13;







  //float pt_sys0020[1] = {3.8};
  float pt_sys0020[1] = {0.76*maxx};
  float ept_sys0020[1] = {0.0};
  float point_sys0020[1] = {1.0};
  float epoint_sys0020[1] = {0.066};
  TGraphErrors *tge_sys0020 = new TGraphErrors(1,pt_sys0020,point_sys0020,ept_sys0020,epoint_sys0020);
  tge_sys0020->SetMarkerStyle(1);
  tge_sys0020->SetMarkerColor(kGray+2);
  tge_sys0020->SetLineWidth(width);
  tge_sys0020->SetLineColor(kGray+2);

  //float pt_sys2040[1] = {4.0};
  float pt_sys2040[1] = {0.80*maxx};
  float ept_sys2040[1] = {0.0};
  float point_sys2040[1] = {1.0};
  float epoint_sys2040[1] = {0.068};
  TGraphErrors *tge_sys2040 = new TGraphErrors(1,pt_sys2040,point_sys2040,ept_sys2040,epoint_sys2040);
  tge_sys2040->SetMarkerStyle(1);
  tge_sys2040->SetMarkerColor(kRed-7);
  tge_sys2040->SetLineWidth(width);
  tge_sys2040->SetLineColor(kRed-7);

  //float pt_sys0088[1] = {4.2};
  float pt_sys0088[1] = {0.84*maxx};
  float ept_sys0088[1] = {0.0};
  float point_sys0088[1] = {1.0};
  float epoint_sys0088[1] = {0.053};
  TGraphErrors *tge_sys0088 = new TGraphErrors(1,pt_sys0088,point_sys0088,ept_sys0088,epoint_sys0088);
  tge_sys0088->SetMarkerStyle(1);
  tge_sys0088->SetMarkerColor(kBlue-7);
  tge_sys0088->SetLineWidth(width);
  tge_sys0088->SetLineColor(kBlue-7);

  //float pt_sys4060[1] = {4.4};
  float pt_sys4060[1] = {0.88*maxx};
  float ept_sys4060[1] = {0.0};
  float point_sys4060[1] = {1.0};
  float epoint_sys4060[1] = {0.061};
  TGraphErrors *tge_sys4060 = new TGraphErrors(1,pt_sys4060,point_sys4060,ept_sys4060,epoint_sys4060);
  tge_sys4060->SetMarkerStyle(1);
  tge_sys4060->SetMarkerColor(kGreen-7);
  tge_sys4060->SetLineWidth(width);
  tge_sys4060->SetLineColor(kGreen-7);

  //float pt_sys6088[1] = {4.6};
  float pt_sys6088[1] = {0.92*maxx};
  float ept_sys6088[1] = {0.0};
  float point_sys6088[1] = {1.0};
  float epoint_sys6088[1] = {0.063};
  TGraphErrors *tge_sys6088 = new TGraphErrors(1,pt_sys6088,point_sys6088,ept_sys6088,epoint_sys6088);
  tge_sys6088->SetMarkerStyle(1);
  tge_sys6088->SetMarkerColor(kMagenta-7);
  tge_sys6088->SetLineWidth(width);
  tge_sys6088->SetLineColor(kMagenta-7);






  cout<<"4x4"<<endl;

  cout<<"pion is "<<pion<<endl;
  cout<<"kaon is "<<kaon<<endl;
  cout<<"prot is "<<prot<<endl;

  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TLine *line = new TLine(minx,1.0,maxx,1.0);

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
  TLatex *tex1 = new TLatex(4.0,2.3,"#pi");
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
  TLatex *tex2 = new TLatex(4.0,2.3,"K");
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
  TLatex *tex3 = new TLatex(4.0,2.3,"p");
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
  tmg->Add(tge_sys0020);
  tmg->Add(tge_sys2040);
  tmg->Add(tge_sys0088);
  tmg->Add(tge_sys4060);
  tmg->Add(tge_sys6088);
  tmg->Draw("apz");
  line->Draw("same");
  tmg->GetXaxis()->SetTitleSize(0.05);
  tmg->GetXaxis()->SetLabelSize(0.05);
  tmg->GetYaxis()->SetTitleSize(0);
  tmg->GetYaxis()->SetLabelSize(0);
  tmg->SetMaximum(3.0);
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
  TGraph *tge_0020 = new TGraph(1,dummy,dummy);
  TGraph *tge_2040 = new TGraph(1,dummy,dummy);
  TGraph *tge_0088 = new TGraph(1,dummy,dummy);
  TGraph *tge_4060 = new TGraph(1,dummy,dummy);
  TGraph *tge_6088 = new TGraph(1,dummy,dummy);
  tge_0020->SetMarkerColor(kBlack);
  tge_2040->SetMarkerColor(kRed);
  tge_0088->SetMarkerColor(kBlue);
  tge_4060->SetMarkerColor(kGreen+2);
  tge_6088->SetMarkerColor(kMagenta+2);
  tge_0020->SetMarkerStyle(kFullCircle);
  tge_2040->SetMarkerStyle(kFullSquare);
  tge_0088->SetMarkerStyle(kFullTriangleUp);
  tge_4060->SetMarkerStyle(kFullTriangleDown);
  tge_6088->SetMarkerStyle(kFullDiamond);
  TLegend *leg4 = new TLegend(0.05,0.60,0.5,0.95);
  leg4->SetBorderSize(0);
  leg4->SetFillColor(kWhite);
  leg4->AddEntry((TObject*)0,"d+Au #sqrt{s_{NN}}=200 GeV","");
  // leg4->AddEntry((TObject*)0,"","");
  leg4->AddEntry(tge_0020,"R_{dA} 0-20%","p");
  leg4->AddEntry(tge_2040,"R_{dA} 20-40%","p");
  //leg4->AddEntry(tge_0088,"R_{dA} min. bias","p");
  leg4->AddEntry(tge_0088,"R_{dA} 0-100%","p");
  leg4->AddEntry(tge_4060,"R_{dA} 40-60%","p");
  leg4->AddEntry(tge_6088,"R_{dA} 60-88%","p");
  leg4->SetTextSize(0.045); // 0.04 works okay, 0.05 is a bit big, too big for padmargin>0.1
  leg4->Draw();


  c1->Print("figures/dau_rda_all.gif");
  c1->Print("figures/dau_rda_all.eps");


  c1->Clear();
  delete c1;


}


void doit(int r8pid=2, int number=27, bool chavers=true)
{

  float sysvalue = 0.1;
  // COME BACK HERE
  if(r8pid<=1) sysvalue = 0.09;
  if(r8pid>=4) sysvalue = 0.11;
  if(r8pid==2||r8pid==3) sysvalue = 0.13;

  int simple = 0;
 
  if(simple==2) sysvalue = 0.1;

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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r8pid<=1||r8pid>=4)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_dau0088[i] = sysvalueX*ratiopos_dau0088[i];
      esysrationeg_dau0088[i] = sysvalueX*rationeg_dau0088[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r8pid<=1||r8pid>=4)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_dau0020[i] = sysvalueX*ratiopos_dau0020[i];
      esysrationeg_dau0020[i] = sysvalueX*rationeg_dau0020[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r8pid<=1||r8pid>=4)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_dau2040[i] = sysvalueX*ratiopos_dau2040[i];
      esysrationeg_dau2040[i] = sysvalueX*rationeg_dau2040[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r8pid<=1||r8pid>=4)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_dau4060[i] = sysvalueX*ratiopos_dau4060[i];
      esysrationeg_dau4060[i] = sysvalueX*rationeg_dau4060[i];
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
      // COME BACK HERE
      float sysvalueX = sysvalue;
      if((r8pid<=1||r8pid>=4)&&i<20&&simple==0) sysvalueX = sysvalue - 0.01;
      esysratiopos_dau6088[i] = sysvalueX*ratiopos_dau6088[i];
      esysrationeg_dau6088[i] = sysvalueX*rationeg_dau6088[i];
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



  tge_ratiopos_dau0020->SetName("tge_ratiopos_dau0020");
  tge_ratiopos_dau2040->SetName("tge_ratiopos_dau2040");
  tge_ratiopos_dau0088->SetName("tge_ratiopos_dau0088");
  tge_ratiopos_dau4060->SetName("tge_ratiopos_dau4060");
  tge_ratiopos_dau6088->SetName("tge_ratiopos_dau6088");

  tge_sysratiopos_dau0020->SetName("tge_sysratiopos_dau0020");
  tge_sysratiopos_dau2040->SetName("tge_sysratiopos_dau2040");
  tge_sysratiopos_dau0088->SetName("tge_sysratiopos_dau0088");
  tge_sysratiopos_dau4060->SetName("tge_sysratiopos_dau4060");
  tge_sysratiopos_dau6088->SetName("tge_sysratiopos_dau6088");

  tge_ratiopos_dau0020->SetMarkerColor(kBlack);
  tge_ratiopos_dau2040->SetMarkerColor(kRed);
  tge_ratiopos_dau0088->SetMarkerColor(kBlue);
  tge_ratiopos_dau4060->SetMarkerColor(kGreen+2);
  tge_ratiopos_dau6088->SetMarkerColor(kMagenta+2);

  // tge_sysratiopos_dau0020->SetMarkerColor(kBlack);
  // tge_sysratiopos_dau2040->SetMarkerColor(kRed);
  // tge_sysratiopos_dau0088->SetMarkerColor(kBlue);
  // tge_sysratiopos_dau4060->SetMarkerColor(kGreen+2);
  // tge_sysratiopos_dau6088->SetMarkerColor(kMagenta+2);
  // tge_sysratiopos_dau0020->SetLineColor(kBlack);
  // tge_sysratiopos_dau2040->SetLineColor(kRed);
  // tge_sysratiopos_dau0088->SetLineColor(kBlue);
  // tge_sysratiopos_dau4060->SetLineColor(kGreen+2);
  // tge_sysratiopos_dau6088->SetLineColor(kMagenta+2);

  tge_ratiopos_dau0020->SetMarkerStyle(kFullCircle);
  tge_ratiopos_dau2040->SetMarkerStyle(kFullSquare);
  tge_ratiopos_dau0088->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_dau4060->SetMarkerStyle(kFullTriangleDown);
  tge_ratiopos_dau6088->SetMarkerStyle(kFullDiamond);



  c1->cd(1);
  TMultiGraph *tmgpos1 = new TMultiGraph();
  // tmgpos1->Add(tge_sys0020);
  // tmgpos1->Add(tge_sys2040);
  // tmgpos1->Add(tge_sys0088);
  // tmgpos1->Add(tge_sys4060);
  // tmgpos1->Add(tge_sys6088);
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
  tmgpos1->GetXaxis()->SetLimits(minx,maxx);
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
  tmgneg1->SetMaximum(3.0);
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
  //c1->Print(figname);
  sprintf(figname,"figures/dau_rda_%s.eps",particle);
  //c1->Print(figname);



  if(r8pid<=1)      tmg_pion = (TMultiGraph *)tmgpos1->Clone();
  else if(r8pid>=4) tmg_prot = (TMultiGraph *)tmgpos1->Clone();
  else              tmg_kaon = (TMultiGraph *)tmgpos1->Clone();


  c1->Clear();
  delete c1;


}
