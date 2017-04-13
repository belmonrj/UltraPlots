void auau_rcp()
{

  //doit(2,4,8,16,33,false);
  //doit(2,4,8,16,33,true);
  doit(3,4,9,16,33,true);

}

void doit(int pi7pid=1, int ka7pid=3, int pr7pid=5, int numberK=16, int numberP=33, bool chavers=false)
{


  //bool showsys = true;
  //bool showsys = false;
  int showsys = 1;
  int showother = 0;


  float pt[18], ratio[18], eratio[18], esysratio[18];
  float tmp;
  ifstream fpi0;

  float      pi0pt[18];
  float    pi0_c04[18];
  float pi0sys_c04[18];
  float    pi0_c03[18];
  float pi0sys_c03[18];

  fpi0.open("ExtraData/NeutralPion/ppg080_RCP_c04.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    pi0pt[i]=pt[i];pi0_c04[i]=ratio[i];pi0sys_c04[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_c04 = new TGraphErrors(10,pt,ratio,0,eratio);
  fpi0.open("ExtraData/NeutralPion/ppg080_RCP_c03.dat");
  for(int i=0; i<18; i++){fpi0>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    pi0pt[i]=pt[i];pi0_c03[i]=ratio[i];pi0sys_c03[i]=esysratio[i];}
  fpi0.close();
  TGraphErrors *tge_pi0_c03 = new TGraphErrors(10,pt,ratio,0,eratio);

  tge_pi0_c04->SetMarkerStyle(kOpenCircle);
  tge_pi0_c03->SetMarkerStyle(kOpenCircle);



  for(int i=0; i<18; i++){pt[i]=-9,ratio[i]=-9;eratio[i]=-9;}


  ifstream fphi;

  float      phipt[10];
  float    phi_c04[10];
  float phisys_c04[10];
  float    phi_c03[10];
  float phisys_c03[10];

  fphi.open("ExtraData/PhiMeson/phi_RCP_c04.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phipt[i]=pt[i];phi_c04[i]=ratio[i];phisys_c04[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_c04 = new TGraphErrors(10,pt,ratio,0,eratio);
  fphi.open("ExtraData/PhiMeson/phi_RCP_c03.dat");
  for(int i=0; i<10; i++){fphi>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
    phipt[i]=pt[i];phi_c03[i]=ratio[i];phisys_c03[i]=esysratio[i];}
  fphi.close();
  TGraphErrors *tge_phi_c03 = new TGraphErrors(10,pt,ratio,0,eratio);

  tge_phi_c03->SetMarkerStyle(kOpenCross);
  tge_phi_c04->SetMarkerStyle(kOpenCross);






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



  // new-ish

  float PT=0.3;

  float pt_sys2[1] = {PT};
  float ept_sys2[1] = {0.0};
  float point_sys2[1] = {1.0};
  float epoint_sys2[1] = {0.162}; // 0-10/40-60
  TGraphErrors *tge_sys2 = new TGraphErrors(1,pt_sys2,point_sys2,ept_sys2,epoint_sys2);
  tge_sys2->SetMarkerStyle(1);
  tge_sys2->SetMarkerColor(kGray+2);
  tge_sys2->SetLineWidth(15);
  tge_sys2->SetLineColor(kGray+2);


  float pt_sys3[1] = {PT};
  float ept_sys3[1] = {0.0};
  float point_sys3[1] = {1.0};
  float epoint_sys3[1] = {0.226}; // 0-10/60-92
  TGraphErrors *tge_sys3 = new TGraphErrors(1,pt_sys3,point_sys3,ept_sys3,epoint_sys3);
  tge_sys3->SetMarkerStyle(1);
  tge_sys3->SetMarkerColor(kGray+2);
  tge_sys3->SetLineWidth(15);
  tge_sys3->SetLineColor(kGray+2);









  // ---------- //
  // -- RCP1 -- //
  // ---------- //

  float pt_RCP1[36];
  float ept_RCP1[36];

  // --

  float pionpos_RCP1[36];
  float pionneg_RCP1[36];
  float epionpos_RCP1[36];
  float epionneg_RCP1[36];
  float esyspionpos_RCP1[36];
  float esyspionneg_RCP1[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d_c04.txt",pi7pid);
  ifstream fRCP1(filename);
  for(int i=0; i<36; i++)
    {
      fRCP1>>pt_RCP1[i]>>pionpos_RCP1[i]>>epionpos_RCP1[i]>>pionneg_RCP1[i]>>epionneg_RCP1[i];
      ept_RCP1[i]=0;
      if(i<5)
	{
	  pionpos_RCP1[i] = -9;
	  pionneg_RCP1[i] = -9;
	}
      if(chavers)
	{
	  pionpos_RCP1[i] += pionneg_RCP1[i];
	  pionpos_RCP1[i] /= 2.0;
	  epionpos_RCP1[i] = sqrt(epionpos_RCP1[i]**2+epionneg_RCP1[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP1
      sysvalue = 0.02; // for RCP1 // COME BACK HERE NEW NEW NEW NEW NEW
      esyspionpos_RCP1[i] = sysvalue*pionpos_RCP1[i];
      esyspionneg_RCP1[i] = sysvalue*pionneg_RCP1[i];
    }

  TGraphErrors *tge_pionpos_RCP1 = new TGraphErrors(36,pt_RCP1,pionpos_RCP1,ept_RCP1,epionpos_RCP1);
  TGraphErrors *tge_pionneg_RCP1 = new TGraphErrors(36,pt_RCP1,pionneg_RCP1,ept_RCP1,epionneg_RCP1);

  TGraphErrors *tge_syspionpos_RCP1 = new TGraphErrors(36,pt_RCP1,pionpos_RCP1,ept_RCP1,esyspionpos_RCP1);
  tge_syspionpos_RCP1->SetMarkerStyle(1);
  tge_syspionpos_RCP1->SetMarkerColor(kGray);
  tge_syspionpos_RCP1->SetFillColor(kGray);
  tge_syspionpos_RCP1->SetLineColor(kGray);
  tge_syspionpos_RCP1->SetLineWidth(15);
  TGraphErrors *tge_syspionneg_RCP1 = new TGraphErrors(36,pt_RCP1,pionneg_RCP1,ept_RCP1,esyspionneg_RCP1);
  tge_syspionneg_RCP1->SetMarkerStyle(1);
  tge_syspionneg_RCP1->SetMarkerColor(kGray);
  tge_syspionneg_RCP1->SetFillColor(kGray);
  tge_syspionneg_RCP1->SetLineColor(kGray);
  tge_syspionneg_RCP1->SetLineWidth(15);

  // -- KAON!!!

  float kaonpos_RCP1[36];
  float kaonneg_RCP1[36];
  float ekaonpos_RCP1[36];
  float ekaonneg_RCP1[36];
  float esyskaonpos_RCP1[36];
  float esyskaonneg_RCP1[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d_c04.txt",ka7pid);
  ifstream fRCP1(filename);
  for(int i=0; i<36; i++)
    {
      fRCP1>>pt_RCP1[i]>>kaonpos_RCP1[i]>>ekaonpos_RCP1[i]>>kaonneg_RCP1[i]>>ekaonneg_RCP1[i];
      ept_RCP1[i]=0;
      if(i<5)
	{
	  kaonpos_RCP1[i] = -9;
	  kaonneg_RCP1[i] = -9;
	}
      if(chavers)
	{
	  kaonpos_RCP1[i] += kaonneg_RCP1[i];
	  kaonpos_RCP1[i] /= 2.0;
	  ekaonpos_RCP1[i] = sqrt(ekaonpos_RCP1[i]**2+ekaonneg_RCP1[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP1
      sysvalue = 0.02; // for RCP1 // COME BACK HERE NEW NEW NEW NEW NEW
      esyskaonpos_RCP1[i] = sysvalue*kaonpos_RCP1[i];
      esyskaonneg_RCP1[i] = sysvalue*kaonneg_RCP1[i];
    }
  TGraphErrors *tge_kaonpos_RCP1 = new TGraphErrors(36,pt_RCP1,kaonpos_RCP1,ept_RCP1,ekaonpos_RCP1);
  TGraphErrors *tge_kaonneg_RCP1 = new TGraphErrors(36,pt_RCP1,kaonneg_RCP1,ept_RCP1,ekaonneg_RCP1);

  TGraphErrors *tge_syskaonpos_RCP1 = new TGraphErrors(36,pt_RCP1,kaonpos_RCP1,ept_RCP1,esyskaonpos_RCP1);
  tge_syskaonpos_RCP1->SetMarkerStyle(1);
  tge_syskaonpos_RCP1->SetMarkerColor(kGray);
  tge_syskaonpos_RCP1->SetFillColor(kGray);
  tge_syskaonpos_RCP1->SetLineColor(kGray);
  tge_syskaonpos_RCP1->SetLineWidth(15);
  TGraphErrors *tge_syskaonneg_RCP1 = new TGraphErrors(36,pt_RCP1,kaonneg_RCP1,ept_RCP1,esyskaonneg_RCP1);
  tge_syskaonneg_RCP1->SetMarkerStyle(1);
  tge_syskaonneg_RCP1->SetMarkerColor(kGray);
  tge_syskaonneg_RCP1->SetFillColor(kGray);
  tge_syskaonneg_RCP1->SetLineColor(kGray);
  tge_syskaonneg_RCP1->SetLineWidth(15);




  // -- PROTON!!!

  float protonpos_RCP1[36];
  float protonneg_RCP1[36];
  float eprotonpos_RCP1[36];
  float eprotonneg_RCP1[36];
  float esysprotonpos_RCP1[36];
  float esysprotonneg_RCP1[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d_c04.txt",pr7pid);
  ifstream fRCP1(filename);
  for(int i=0; i<36; i++)
    {
      fRCP1>>pt_RCP1[i]>>protonpos_RCP1[i]>>eprotonpos_RCP1[i]>>protonneg_RCP1[i]>>eprotonneg_RCP1[i];
      ept_RCP1[i]=0;
      if(i<5)
	{
	  protonpos_RCP1[i] = -9;
	  protonneg_RCP1[i] = -9;
	}
      if(chavers)
	{
	  protonpos_RCP1[i] += protonneg_RCP1[i];
	  protonpos_RCP1[i] /= 2.0;
	  eprotonpos_RCP1[i] = sqrt(eprotonpos_RCP1[i]**2+eprotonneg_RCP1[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP1
      sysvalue = 0.02; // for RCP1 // COME BACK HERE NEW NEW NEW NEW NEW
      esysprotonpos_RCP1[i] = sysvalue*protonpos_RCP1[i];
      esysprotonneg_RCP1[i] = sysvalue*protonneg_RCP1[i];
    }

  TGraphErrors *tge_protonpos_RCP1 = new TGraphErrors(36,pt_RCP1,protonpos_RCP1,ept_RCP1,eprotonpos_RCP1);
  TGraphErrors *tge_protonneg_RCP1 = new TGraphErrors(36,pt_RCP1,protonneg_RCP1,ept_RCP1,eprotonneg_RCP1);

  TGraphErrors *tge_sysprotonpos_RCP1 = new TGraphErrors(36,pt_RCP1,protonpos_RCP1,ept_RCP1,esysprotonpos_RCP1);
  tge_sysprotonpos_RCP1->SetMarkerStyle(1);
  tge_sysprotonpos_RCP1->SetMarkerColor(kGray);
  tge_sysprotonpos_RCP1->SetFillColor(kGray);
  tge_sysprotonpos_RCP1->SetLineColor(kGray);
  tge_sysprotonpos_RCP1->SetLineWidth(15);
  TGraphErrors *tge_sysprotonneg_RCP1 = new TGraphErrors(36,pt_RCP1,protonneg_RCP1,ept_RCP1,esysprotonneg_RCP1);
  tge_sysprotonneg_RCP1->SetMarkerStyle(1);
  tge_sysprotonneg_RCP1->SetMarkerColor(kGray);
  tge_sysprotonneg_RCP1->SetFillColor(kGray);
  tge_sysprotonneg_RCP1->SetLineColor(kGray);
  tge_sysprotonneg_RCP1->SetLineWidth(15);



  // ---
  // --- set colors and shapes
  // ---

  // ---










  // ---------- //
  // -- RCP2 -- //
  // ---------- //

  float pt_RCP2[36];
  float ept_RCP2[36];

  // --

  float pionpos_RCP2[36];
  float pionneg_RCP2[36];
  float epionpos_RCP2[36];
  float epionneg_RCP2[36];
  float esyspionpos_RCP2[36];
  float esyspionneg_RCP2[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d_c03.txt",pi7pid);
  ifstream fRCP2(filename);
  for(int i=0; i<36; i++)
    {
      fRCP2>>pt_RCP2[i]>>pionpos_RCP2[i]>>epionpos_RCP2[i]>>pionneg_RCP2[i]>>epionneg_RCP2[i];
      ept_RCP2[i]=0;
      if(i<5)
	{
	  pionpos_RCP2[i] = -9;
	  pionneg_RCP2[i] = -9;
	}
      if(chavers)
	{
	  pionpos_RCP2[i] += pionneg_RCP2[i];
	  pionpos_RCP2[i] /= 2.0;
	  epionpos_RCP2[i] = sqrt(epionpos_RCP2[i]**2+epionneg_RCP2[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP2
      sysvalue = 0.02; // for RCP1 // COME BACK HERE NEW NEW NEW NEW NEW
      esyspionpos_RCP2[i] = sysvalue*pionpos_RCP2[i];
      esyspionneg_RCP2[i] = sysvalue*pionneg_RCP2[i];
    }

  TGraphErrors *tge_pionpos_RCP2 = new TGraphErrors(36,pt_RCP2,pionpos_RCP2,ept_RCP2,epionpos_RCP2);
  TGraphErrors *tge_pionneg_RCP2 = new TGraphErrors(36,pt_RCP2,pionneg_RCP2,ept_RCP2,epionneg_RCP2);

  TGraphErrors *tge_syspionpos_RCP2 = new TGraphErrors(36,pt_RCP2,pionpos_RCP2,ept_RCP2,esyspionpos_RCP2);
  tge_syspionpos_RCP2->SetMarkerStyle(1);
  tge_syspionpos_RCP2->SetMarkerColor(kGray);
  tge_syspionpos_RCP2->SetFillColor(kGray);
  tge_syspionpos_RCP2->SetLineColor(kGray);
  tge_syspionpos_RCP2->SetLineWidth(15);
  TGraphErrors *tge_syspionneg_RCP2 = new TGraphErrors(36,pt_RCP2,pionneg_RCP2,ept_RCP2,esyspionneg_RCP2);
  tge_syspionneg_RCP2->SetMarkerStyle(1);
  tge_syspionneg_RCP2->SetMarkerColor(kGray);
  tge_syspionneg_RCP2->SetFillColor(kGray);
  tge_syspionneg_RCP2->SetLineColor(kGray);
  tge_syspionneg_RCP2->SetLineWidth(15);

  // -- KAON!!!

  float kaonpos_RCP2[36];
  float kaonneg_RCP2[36];
  float ekaonpos_RCP2[36];
  float ekaonneg_RCP2[36];
  float esyskaonpos_RCP2[36];
  float esyskaonneg_RCP2[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d_c03.txt",ka7pid);
  ifstream fRCP2(filename);
  for(int i=0; i<36; i++)
    {
      fRCP2>>pt_RCP2[i]>>kaonpos_RCP2[i]>>ekaonpos_RCP2[i]>>kaonneg_RCP2[i]>>ekaonneg_RCP2[i];
      ept_RCP2[i]=0;
      if(i<5)
	{
	  kaonpos_RCP2[i] = -9;
	  kaonneg_RCP2[i] = -9;
	}
      if(chavers)
	{
	  kaonpos_RCP2[i] += kaonneg_RCP2[i];
	  kaonpos_RCP2[i] /= 2.0;
	  ekaonpos_RCP2[i] = sqrt(ekaonpos_RCP2[i]**2+ekaonneg_RCP2[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP2
      sysvalue = 0.02; // for RCP1 // COME BACK HERE NEW NEW NEW NEW NEW
      esyskaonpos_RCP2[i] = sysvalue*kaonpos_RCP2[i];
      esyskaonneg_RCP2[i] = sysvalue*kaonneg_RCP2[i];
    }
  TGraphErrors *tge_kaonpos_RCP2 = new TGraphErrors(36,pt_RCP2,kaonpos_RCP2,ept_RCP2,ekaonpos_RCP2);
  TGraphErrors *tge_kaonneg_RCP2 = new TGraphErrors(36,pt_RCP2,kaonneg_RCP2,ept_RCP2,ekaonneg_RCP2);

  TGraphErrors *tge_syskaonpos_RCP2 = new TGraphErrors(36,pt_RCP2,kaonpos_RCP2,ept_RCP2,esyskaonpos_RCP2);
  tge_syskaonpos_RCP2->SetMarkerStyle(1);
  tge_syskaonpos_RCP2->SetMarkerColor(kGray);
  tge_syskaonpos_RCP2->SetFillColor(kGray);
  tge_syskaonpos_RCP2->SetLineColor(kGray);
  tge_syskaonpos_RCP2->SetLineWidth(15);
  TGraphErrors *tge_syskaonneg_RCP2 = new TGraphErrors(36,pt_RCP2,kaonneg_RCP2,ept_RCP2,esyskaonneg_RCP2);
  tge_syskaonneg_RCP2->SetMarkerStyle(1);
  tge_syskaonneg_RCP2->SetMarkerColor(kGray);
  tge_syskaonneg_RCP2->SetFillColor(kGray);
  tge_syskaonneg_RCP2->SetLineColor(kGray);
  tge_syskaonneg_RCP2->SetLineWidth(15);




  // -- PROTON!!!

  float protonpos_RCP2[36];
  float protonneg_RCP2[36];
  float eprotonpos_RCP2[36];
  float eprotonneg_RCP2[36];
  float esysprotonpos_RCP2[36];
  float esysprotonneg_RCP2[36];
  sprintf(filename,"../Run7AuAu/Ratios/regular/rcp_%d_c03.txt",pr7pid);
  ifstream fRCP2(filename);
  for(int i=0; i<36; i++)
    {
      fRCP2>>pt_RCP2[i]>>protonpos_RCP2[i]>>eprotonpos_RCP2[i]>>protonneg_RCP2[i]>>eprotonneg_RCP2[i];
      ept_RCP2[i]=0;
      if(i<5)
	{
	  protonpos_RCP2[i] = -9;
	  protonneg_RCP2[i] = -9;
	}
      if(chavers)
	{
	  protonpos_RCP2[i] += protonneg_RCP2[i];
	  protonpos_RCP2[i] /= 2.0;
	  eprotonpos_RCP2[i] = sqrt(eprotonpos_RCP2[i]**2+eprotonneg_RCP2[i]**2)/2.0;
	}
      sysvalue = 0.05; // for RCP2
      sysvalue = 0.02; // for RCP1 // COME BACK HERE NEW NEW NEW NEW NEW
      esysprotonpos_RCP2[i] = sysvalue*protonpos_RCP2[i];
      esysprotonneg_RCP2[i] = sysvalue*protonneg_RCP2[i];
    }

  TGraphErrors *tge_protonpos_RCP2 = new TGraphErrors(36,pt_RCP2,protonpos_RCP2,ept_RCP2,eprotonpos_RCP2);
  TGraphErrors *tge_protonneg_RCP2 = new TGraphErrors(36,pt_RCP2,protonneg_RCP2,ept_RCP2,eprotonneg_RCP2);

  TGraphErrors *tge_sysprotonpos_RCP2 = new TGraphErrors(36,pt_RCP2,protonpos_RCP2,ept_RCP2,esysprotonpos_RCP2);
  tge_sysprotonpos_RCP2->SetMarkerStyle(1);
  tge_sysprotonpos_RCP2->SetMarkerColor(kGray);
  tge_sysprotonpos_RCP2->SetFillColor(kGray);
  tge_sysprotonpos_RCP2->SetLineColor(kGray);
  tge_sysprotonpos_RCP2->SetLineWidth(15);
  TGraphErrors *tge_sysprotonneg_RCP2 = new TGraphErrors(36,pt_RCP2,protonneg_RCP2,ept_RCP2,esysprotonneg_RCP2);
  tge_sysprotonneg_RCP2->SetMarkerStyle(1);
  tge_sysprotonneg_RCP2->SetMarkerColor(kGray);
  tge_sysprotonneg_RCP2->SetFillColor(kGray);
  tge_sysprotonneg_RCP2->SetLineColor(kGray);
  tge_sysprotonneg_RCP2->SetLineWidth(15);



  // ---
  // --- set colors and shapes
  // ---


  tge_pionpos_RCP1->SetMarkerStyle(kFullCircle);
  tge_pionneg_RCP1->SetMarkerStyle(kOpenCircle);
  tge_kaonpos_RCP1->SetMarkerStyle(kFullTriangleUp);
  tge_kaonneg_RCP1->SetMarkerStyle(kOpenTriangleUp);
  tge_protonpos_RCP1->SetMarkerStyle(kFullSquare);
  tge_protonneg_RCP1->SetMarkerStyle(kOpenSquare);

  tge_pionpos_RCP1->SetMarkerColor(kRed);
  tge_pionneg_RCP1->SetMarkerColor(kRed);
  tge_kaonpos_RCP1->SetMarkerColor(kGreen+2);
  tge_kaonneg_RCP1->SetMarkerColor(kGreen+2);
  tge_protonpos_RCP1->SetMarkerColor(kBlue);
  tge_protonneg_RCP1->SetMarkerColor(kBlue);


  tge_pionpos_RCP2->SetMarkerStyle(kFullCircle);
  tge_pionneg_RCP2->SetMarkerStyle(kOpenCircle);
  tge_kaonpos_RCP2->SetMarkerStyle(kFullTriangleUp);
  tge_kaonneg_RCP2->SetMarkerStyle(kOpenTriangleUp);
  tge_protonpos_RCP2->SetMarkerStyle(kFullSquare);
  tge_protonneg_RCP2->SetMarkerStyle(kOpenSquare);

  tge_pionpos_RCP2->SetMarkerColor(kRed);
  tge_pionneg_RCP2->SetMarkerColor(kRed);
  tge_kaonpos_RCP2->SetMarkerColor(kGreen+2);
  tge_kaonneg_RCP2->SetMarkerColor(kGreen+2);
  tge_protonpos_RCP2->SetMarkerColor(kBlue);
  tge_protonneg_RCP2->SetMarkerColor(kBlue);





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


  tge_syspionpos_RCP1->SetLineColor(kRed-9);
  tge_syskaonpos_RCP1->SetLineColor(kGreen-9);
  tge_sysprotonpos_RCP1->SetLineColor(kBlue-9);




  bool RED = true; // COME HERE TO SWITCH BETWEEN RED AND BLACK

  if(RED)
    {
      tge_pi0_c04->SetMarkerColor(kRed);
      tge_pi0_c03->SetMarkerColor(kRed);
    }

  TLine *line = new TLine(0.0,1.0,6.0,1.0);
  line->SetLineStyle(2);


  c1_1->cd();
  TMultiGraph *tmg_rcp1 = new TMultiGraph();
  //tmg_rcp1->Add(tge_sys4);
  tmg_rcp1->Add(tge_sys3);
  if(!chavers) tmg_rcp1->Add(tge_syspionneg_RCP1);
  if(!chavers) tmg_rcp1->Add(tge_syskaonneg_RCP1);
  if(!chavers) tmg_rcp1->Add(tge_sysprotonneg_RCP1);
  if(showsys>0)
    {
      tmg_rcp1->Add(tge_syspionpos_RCP1);
      tmg_rcp1->Add(tge_syskaonpos_RCP1);
      tmg_rcp1->Add(tge_sysprotonpos_RCP1);
    }
  tmg_rcp1->Add(tge_pionpos_RCP1);
  tmg_rcp1->Add(tge_kaonpos_RCP1);
  tmg_rcp1->Add(tge_protonpos_RCP1);
  if(!chavers) tmg_rcp1->Add(tge_pionneg_RCP1);
  if(!chavers) tmg_rcp1->Add(tge_kaonneg_RCP1);
  if(!chavers) tmg_rcp1->Add(tge_protonneg_RCP1);
  if(showother>0) tmg_rcp1->Add(tge_pi0_c04);
  if(showother>0) tmg_rcp1->Add(tge_phi_c04);
  tmg_rcp1->Draw("apz");
  line->Draw("same");
  if(showsys>1&&showother>0)
    {
      for(int i=0; i<10; i++)
	{
	  double px1 = i/2.0+1.25-0.15;
	  double px2 = i/2.0+1.25+0.15;
	  double py1 = pi0_c04[i]-pi0sys_c04[i];
	  double py2 = pi0_c04[i]+pi0sys_c04[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  if(RED) boxauaupos->SetLineColor(kRed);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
      for(int i=0; i<9; i++)
	{
	  double px1 = phipt[i]-0.15;
	  double px2 = phipt[i]+0.15;
	  double py1 = phi_c04[i]-phisys_c04[i];
	  double py2 = phi_c04[i]+phisys_c04[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
    }
  tmg_rcp1->SetMaximum(2.0);
  tmg_rcp1->SetMinimum(0.0);
  tmg_rcp1->GetXaxis()->SetLimits(0.0,6.0);
  tmg_rcp1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_rcp1->GetXaxis()->CenterTitle();
  tmg_rcp1->GetYaxis()->SetTitle("R_{CP}");
  tmg_rcp1->GetYaxis()->CenterTitle();
  tmg_rcp1->GetYaxis()->SetTitleSize(0.05);
  tmg_rcp1->GetYaxis()->SetLabelSize(0.05);
  tmg_rcp1->GetXaxis()->SetTitleSize(0.05);
  tmg_rcp1->GetXaxis()->SetLabelSize(0.05);
  //TLatex *tl_rcp1 = new TLatex(0.6,1.73,"R_{CP} (0-10%/60-92%)");
  //TLatex *tl_rcp1 = new TLatex(0.5,1.73,"R_{CP} (0-10%/60-92%)");
  TLatex *tl_rcp1 = new TLatex(0.4,1.73,"R_{CP} (0-10%/60-92%)");
  tl_rcp1->SetTextSize(0.055);
  tl_rcp1->Draw();



  tge_syspionpos_RCP2->SetLineColor(kRed-9);
  tge_syskaonpos_RCP2->SetLineColor(kGreen-9);
  tge_sysprotonpos_RCP2->SetLineColor(kBlue-9);



  c1_2->cd();
  TMultiGraph *tmg_rcp = new TMultiGraph();
  //tmg_rcp->Add(tge_sys1);
  tmg_rcp->Add(tge_sys2);
  if(!chavers) tmg_rcp->Add(tge_syspionneg_RCP2);
  if(!chavers) tmg_rcp->Add(tge_syskaonneg_RCP2);
  if(!chavers) tmg_rcp->Add(tge_sysprotonneg_RCP2);
  if(showsys>0)
    {
      tmg_rcp->Add(tge_syspionpos_RCP2);
      tmg_rcp->Add(tge_syskaonpos_RCP2);
      tmg_rcp->Add(tge_sysprotonpos_RCP2);
    }
  tmg_rcp->Add(tge_pionpos_RCP2);
  tmg_rcp->Add(tge_kaonpos_RCP2);
  tmg_rcp->Add(tge_protonpos_RCP2);
  if(!chavers) tmg_rcp->Add(tge_pionneg_RCP2);
  if(!chavers) tmg_rcp->Add(tge_kaonneg_RCP2);
  if(!chavers) tmg_rcp->Add(tge_protonneg_RCP2);
  if(showother>0) tmg_rcp->Add(tge_pi0_c03);
  if(showother>0) tmg_rcp->Add(tge_phi_c03);
  tmg_rcp->Draw("apz");
  line->Draw("same");
  if(showsys>1&&showother>0)
    {
      for(int i=0; i<10; i++)
	{
	  double px1 = i/2.0+1.25-0.15;
	  double px2 = i/2.0+1.25+0.15;
	  double py1 = pi0_c03[i]-pi0sys_c03[i];
	  double py2 = pi0_c03[i]+pi0sys_c03[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  if(RED) boxauaupos->SetLineColor(kRed);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
      for(int i=0; i<9; i++)
	{
	  double px1 = phipt[i]-0.15;
	  double px2 = phipt[i]+0.15;
	  double py1 = phi_c03[i]-phisys_c03[i];
	  double py2 = phi_c03[i]+phisys_c03[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
    }
  tmg_rcp->SetMaximum(2.0);
  tmg_rcp->SetMinimum(0.0);
  tmg_rcp->GetXaxis()->SetLimits(0.0,6.0);
  tmg_rcp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_rcp->GetXaxis()->CenterTitle();
  tmg_rcp->GetYaxis()->SetTitle("R_{CP}");
  tmg_rcp->GetYaxis()->CenterTitle();
  tmg_rcp->GetYaxis()->SetTitleSize(0);
  tmg_rcp->GetYaxis()->SetLabelSize(0);
  tmg_rcp->GetXaxis()->SetTitleSize(0.05);
  tmg_rcp->GetXaxis()->SetLabelSize(0.05);
  //TLegend *leg_rcp = new TLegend(0.77,0.55,0.85,0.80);
  TLegend *leg_rcp = new TLegend(0.70,0.55,0.78,0.80);
  leg_rcp->SetBorderSize(0);
  leg_rcp->SetFillColor(kWhite);
  if(!chavers)
    {
      leg_rcp->AddEntry(tge_pionpos_RCP2,"#pi^{+}","p");
      leg_rcp->AddEntry(tge_pionneg_RCP2,"#pi^{-}","p");
      leg_rcp->AddEntry(tge_kaonpos_RCP2,"K^{+}","p");
      leg_rcp->AddEntry(tge_kaonneg_RCP2,"K^{-}","p");
      leg_rcp->AddEntry(tge_protonpos_RCP2,"p","p");
      leg_rcp->AddEntry(tge_protonneg_RCP2,"#bar{p}","p");
    }
  if(chavers)
    {
      leg_rcp->AddEntry(tge_pionpos_RCP2,"#pi^{#pm}","p");
      leg_rcp->AddEntry(tge_kaonpos_RCP2,"K^{#pm}","p");
      leg_rcp->AddEntry(tge_protonpos_RCP2,"p","p");
    }
  if(showother>0) leg_rcp->AddEntry(tge_pi0_c04,"#pi^{0}","p");
  if(showother>0) leg_rcp->AddEntry(tge_phi_c04,"#phi","p");
  leg_rcp->SetTextSize(0.055);
  leg_rcp->Draw();
  //TLatex *tl_rcp = new TLatex(0.6,1.73,"R_{CP} (0-10%/40-60%)");
  //TLatex *tl_rcp = new TLatex(0.5,1.73,"R_{CP} (0-10%/40-60%)");
  TLatex *tl_rcp = new TLatex(0.4,1.73,"R_{CP} (0-10%/40-60%)");
  tl_rcp->SetTextSize(0.055);
  tl_rcp->Draw();
  //TLatex *tl_col = new TLatex(3.5,1.73,"Au+Au #sqrt{s_{NN}}=200 GeV");
  //TLatex *tl_col = new TLatex(3.2,1.73,"Au+Au #sqrt{s_{NN}}=200 GeV");
  TLatex *tl_col = new TLatex(3.1,1.73,"Au+Au #sqrt{s_{NN}}=200 GeV");
  tl_col->SetTextSize(0.055);
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
  sprintf(figname,"figures/auau_rcp_all.gif");
  c1->Print(figname);
  sprintf(figname,"figures/auau_rcp_all.eps");
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
  c2_1->SetLeftMargin(0.13);
  c2_2->SetRightMargin(0.13);
  c2_1->SetTopMargin(0.05);
  c2_2->SetTopMargin(0.05);
  c2_1->SetBottomMargin(0.13);
  c2_2->SetBottomMargin(0.13);
  c2_1->SetTicks(1,1);
  c2_2->SetTicks(1,1);

  // COME BACK HERE TO INSERT TGAXIS STUFF

  float size = 0.055; // very, very close to previous settings before using TGaxis...
  float scale = 1.0;
  float titleoff = 0.5;
  int ndivisions = 505;

  TGaxis *yaxis0 = new TGaxis(0.065,0.13,0.065,0.95,0.0,2.0,ndivisions,"S");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("R_{CP}");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(size*scale);
  yaxis0->SetTitleSize(size*scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->SetTickSize(0.01);
  yaxis0->Draw();

  TGaxis *xaxis0 = new TGaxis(0.065,0.13,0.5,0.13,0.0,5.9999,510,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(size*scale);
  xaxis0->SetTitleSize(size*scale);
  xaxis0->SetTitleOffset(1.1);
  xaxis0->Draw();

  TGaxis *xaxis1 = new TGaxis(0.5,0.13,0.935,0.13,0.0,6.0,510,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(size*scale);
  xaxis1->SetTitleSize(size*scale);
  xaxis1->SetTitleOffset(1.1);
  xaxis1->Draw();

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



  tmg_rcp->GetYaxis()->SetTitleSize(0);
  tmg_rcp->GetYaxis()->SetLabelSize(0);
  tmg_rcp1->GetYaxis()->SetTitleSize(0);
  tmg_rcp1->GetYaxis()->SetLabelSize(0);
  tmg_rcp->GetXaxis()->SetTitleSize(0);
  tmg_rcp->GetXaxis()->SetLabelSize(0);
  tmg_rcp1->GetXaxis()->SetTitleSize(0);
  tmg_rcp1->GetXaxis()->SetLabelSize(0);

  tmg_rcp->GetYaxis()->SetNdivisions(ndivisions);
  tmg_rcp->GetYaxis()->SetNdivisions(ndivisions);
  tmg_rcp1->GetYaxis()->SetNdivisions(ndivisions);
  tmg_rcp1->GetYaxis()->SetNdivisions(ndivisions);


  c2_1->cd();
  tmg_rcp->Draw("apz");
  line->Draw();
  if(showsys>1&&showother>0)
    {
      for(int i=0; i<10; i++)
	{
	  double px1 = i/2.0+1.25-0.15;
	  double px2 = i/2.0+1.25+0.15;
	  double py1 = pi0_c03[i]-pi0sys_c03[i];
	  double py2 = pi0_c03[i]+pi0sys_c03[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  if(RED) boxauaupos->SetLineColor(kRed);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
      for(int i=0; i<9; i++)
	{
	  double px1 = phipt[i]-0.15;
	  double px2 = phipt[i]+0.15;
	  double py1 = phi_c03[i]-phisys_c03[i];
	  double py2 = phi_c03[i]+phisys_c03[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
    }
  tl_rcp->Draw();
  c2_2->cd();
  tmg_rcp1->Draw("apz");
  line->Draw();
  if(showsys>1&&showother>0)
    {
      for(int i=0; i<10; i++)
	{
	  double px1 = i/2.0+1.25-0.15;
	  double px2 = i/2.0+1.25+0.15;
	  double py1 = pi0_c04[i]-pi0sys_c04[i];
	  double py2 = pi0_c04[i]+pi0sys_c04[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  if(RED) boxauaupos->SetLineColor(kRed);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
      for(int i=0; i<9; i++)
	{
	  double px1 = phipt[i]-0.15;
	  double px2 = phipt[i]+0.15;
	  double py1 = phi_c04[i]-phisys_c04[i];
	  double py2 = phi_c04[i]+phisys_c04[i];
	  TBox *boxauaupos = new TBox(px1,py1,px2,py2);
	  boxauaupos->SetFillColor(kBlack);
	  boxauaupos->SetFillStyle(0);
	  boxauaupos->SetLineColor(kBlack);
	  boxauaupos->SetLineWidth(1);
	  boxauaupos->Draw("lsame");
	}
    }
  leg_rcp->Draw(); // extra, right only
  tl_rcp1->Draw();
  tl_col->Draw(); // extra, right only

  sprintf(figname,"figures/auau_rcp_swall.gif"); // swap, all
  c2->Print(figname);
  sprintf(figname,"figures/auau_rcp_swall.eps"); // swap, all
  c2->Print(figname);


  c2->Clear();
  delete c2;




}
