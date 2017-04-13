TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;
TGraphErrors *tge_pionA;
TGraphErrors *tge_kaonA;
TGraphErrors *tge_protA;
TGraphErrors *tge_pionSA;
TGraphErrors *tge_kaonSA;
TGraphErrors *tge_protSA;

int xtitleoffset = 1.5;

float minx = 0.00;
float maxx = 6.00;

bool showsys = true;

bool simple = false;

void aud_sr2()
{

  doit(0,1,"0020");
  doit(4,3,"0020");
  doit(6,5,"0020");

  doit4x4(tmg_pion,tmg_kaon,tmg_prot);
  doitAVE(tge_pionA,tge_kaonA,tge_protA,
	  tge_pionSA,tge_kaonSA,tge_protSA);

}

void doitAVE(TGraphErrors *pion, TGraphErrors *kaon, TGraphErrors *prot,
	     TGraphErrors *pionS, TGraphErrors *kaonS, TGraphErrors *protS)
{

  char filename[100] = "ExtraData/NeutralPion/pi0_aud_ratio.dat";
  float pt[12], ratio[12], eratio[12];
  float ptPHI[12];
  float ptPI0[12];
  float phi_RATIO[12];
  float pi0_RATIO[12];
  float esys_PHI[12];
  float esys_PI0[12];

  ifstream finn;
  finn.open(filename);
  for(int i=0; i<12; i++){finn>>pt[i]>>ratio[i]>>eratio[i]>>esys_PI0[i];ptPI0[i]=pt[i];pi0_RATIO[i]=ratio[i];}
  TGraphErrors *tge_pi0 = new TGraphErrors(12,pt,ratio,0,eratio);
  finn.close();
  for(int i=0; i<12; i++){pt[i]=9;ratio[i]=-9;eratio[i]=-9;}
  sprintf(filename,"ExtraData/PhiMeson/phi_aud_ratio.dat");
  finn.open(filename);
  for(int i=0; i<10; i++){finn>>pt[i]>>ratio[i]>>eratio[i]>>esys_PHI[i];ptPHI[i]=pt[i];phi_RATIO[i]=ratio[i];}
  TGraphErrors *tge_phi = new TGraphErrors(10,pt,ratio,0,eratio);
  finn.close();



  tge_pi0->SetMarkerStyle(kOpenCircle);
  tge_pi0->SetMarkerColor(kRed); // new
  tge_phi->SetMarkerStyle(kOpenCross);

  cout<<"AVE"<<endl;


  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"pion is "<<pion<<endl;
      cout<<"kaon is "<<kaon<<endl;
      cout<<"prot is "<<prot<<endl;
      cout<<"one or more TGEs are NULL, aborting"<<endl;
      return;
    }

  TLine *line = new TLine(0.0,0.65,5.0,0.65);
  line->SetLineStyle(2);

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.0,1.0,1.0);
  c1_1->Draw();
  c1_1->SetTopMargin(0.05);
  c1_1->SetRightMargin(0.05);
  c1_1->SetBottomMargin(0.15);
  c1_1->SetLeftMargin(0.15);
  c1_1->SetTicks(1,1);

  float size = 0.055; // very, very close to previous settings before using TGaxis...
  float scale = 1.0;
  float titleoff = 1.0;
  int ndivisions = 505;

  TGaxis *yaxis0 = new TGaxis(0.15,0.15,0.15,0.95,0.0,2.0,ndivisions,"S");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("Ratio of Spectra");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(size*scale);
  yaxis0->SetTitleSize(size*scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->SetTickSize(0.01);
  yaxis0->Draw();

  TGaxis *xaxis0 = new TGaxis(0.15,0.15,0.95,0.15,0.0,5.0,510,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(size*scale);
  xaxis0->SetTitleSize(size*scale);
  xaxis0->SetTitleOffset(1.1);
  xaxis0->Draw();



  c1_1->cd();
  TMultiGraph *supermult = new TMultiGraph();
  supermult->Add(pionS);
  supermult->Add(kaonS);
  supermult->Add(protS);
  supermult->Add(prot);
  supermult->Add(pion);
  supermult->Add(kaon);
  supermult->Add(tge_pi0);
  //supermult->Add(tge_phi);
  supermult->Draw("apz");
  line->Draw();
  supermult->SetMaximum(2.0);
  supermult->SetMinimum(0.0);
  supermult->GetXaxis()->SetLimits(0.0,5.0);
  supermult->GetYaxis()->SetTitle("Ratio of Spectra");
  supermult->GetYaxis()->CenterTitle();
  supermult->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  supermult->GetXaxis()->CenterTitle();
  supermult->GetXaxis()->SetLabelSize(0.0);
  supermult->GetXaxis()->SetTitleSize(0.0);
  supermult->GetXaxis()->SetTitleOffset(1.3);
  supermult->GetYaxis()->SetLabelSize(0.0);
  supermult->GetYaxis()->SetTitleSize(0.0);
  supermult->GetYaxis()->SetTitleOffset(1.1);
  supermult->GetYaxis()->SetNdivisions(ndivisions);

  TLegend *superleg = new TLegend(0.68,0.62,0.88,0.92);
  superleg->SetBorderSize(0);
  superleg->SetFillColor(kWhite);
  superleg->SetTextSize(0.05);
  superleg->AddEntry(pion,"#pi^{-}+#pi^{+}","p");
  superleg->AddEntry(kaon,"K^{-}+K^{+}","p");
  superleg->AddEntry(prot,"#bar{p}+p","p");
  superleg->AddEntry(tge_pi0,"#pi^{0}","p");
  //superleg->AddEntry(tge_phi,"#phi","p");
  superleg->Draw();

  TLatex *tex = new TLatex(0.8,0.25,"(Au+Au 60-92%)/(d+Au 0-20%)");
  tex->SetTextSize(0.06);
  tex->Draw();


  for(int i=0; i<8; i++)
    {
      double px1 = i/2.0+1.25-0.15;
      double px2 = i/2.0+1.25+0.15;
      double py1 = pi0_RATIO[i]-esys_PI0[i];
      double py2 = pi0_RATIO[i]+esys_PI0[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kRed);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kRed);
      boxauaupos->SetLineWidth(1);
      boxauaupos->Draw("lsame");
    }
  for(int i=0; i<8; i++)
    {
      double px1 = ptPHI[i]-0.15;
      double px2 = ptPHI[i]+0.15;
      double py1 = phi_RATIO[i]-esys_PHI[i];
      double py2 = phi_RATIO[i]+esys_PHI[i];
      TBox *boxauaupos = new TBox(px1,py1,px2,py2);
      boxauaupos->SetFillColor(kBlack);
      boxauaupos->SetFillStyle(0);
      boxauaupos->SetLineColor(kBlack);
      boxauaupos->SetLineWidth(1);
      //boxauaupos->Draw("lsame");
    }

  c1->Print("figures/aud_AVE_nophi.gif");
  c1->Print("figures/aud_AVE_nophi.eps");
  c1->Print("figures/thedaujobes_nophi.gif");
  c1->Print("figures/thedaujobes_nophi.eps");

  c1->Clear();
  delete c1;

}










void doit4x4(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  cout<<"4x4"<<endl;


  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"pion is "<<pion<<endl;
      cout<<"kaon is "<<kaon<<endl;
      cout<<"prot is "<<prot<<endl;
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TLine *line = new TLine(0.0,0.65,6.0,0.65);

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
  // tmg->SetMaximum(2.0);
  // tmg->SetMinimum(0.0);
  tmg->SetMaximum(1.99);
  tmg->SetMinimum(0.01);
  tmg->GetXaxis()->SetLimits(minx,maxx);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitleOffset(xtitleoffset);
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
  leg4->AddEntry(line,"line drawn at 0.65 as visual aid","l");
  leg4->SetTextSize(0.045); // 0.04 works okay, 0.05 is a bit big, too big for padmargin>0.1
  leg4->Draw();

  c1->Print("figures/aud_4x4.gif");
  c1->Print("figures/aud_4x4.eps");
  c1->Print("figures/thedau.gif");
  c1->Print("figures/thedau.eps");

  c1->Clear();
  delete c1;

}

void doit(int pi7id = 6, int pi8id = 5, char *daucent="0020")
{

  TCanvas *c1 = new TCanvas();

  float ncoll7 = 14.8;
  float ncoll8 = 15.1;

  float corrector = ncoll8/ncoll7;

  float ptpos[36], ptneg[36];
  float eptpos[36], eptneg[36];
  float ratiopos[36], rationeg[36];
  float eratiopos[36], erationeg[36];
  float esysratiopos[36], esysrationeg[36];
  float ratioave[36]; // new
  float eratioave[36]; // new
  float esysratioave[36]; // new

  float yield_daupos, yield_dauneg;
  float eyield_daupos, eyield_dauneg;
  float yield_auaupos, yield_auauneg;
  float eyield_auaupos, eyield_auauneg;
  float yield_dauave;
  float eyield_dauave;
  float yield_auauave;
  float eyield_auauave;


  char fauauposname[100];
  char fauaunegname[100];
  char fdauposname[100];
  char fdaunegname[100];

  sprintf(fauauposname,"../Run7AuAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent6092.txt",pi7id);
  sprintf(fauaunegname,"../Run7AuAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent6092.txt",pi7id);
  sprintf(fdauposname,"../Run8dAu/Spectra/Text/ptpid_tofw_poscb_%d_dis_cent%s.txt",pi8id,daucent);
  sprintf(fdaunegname,"../Run8dAu/Spectra/Text/ptpid_tofw_negcb_%d_dis_cent%s.txt",pi8id,daucent);

  ifstream fauaupos(fauauposname);
  ifstream fauauneg(fauaunegname);
  ifstream fdaupos(fdauposname);
  ifstream fdauneg(fdaunegname);


  char foutname[100]; // new
  sprintf(foutname,"aud_sr_%d-%d.txt",pi7id,pi8id); // new
  ofstream fout(foutname);
  for(int i=0; i<36; i++)
    {
      fauaupos>>ptpos[i]>>yield_auaupos>>eyield_auaupos;
      fauauneg>>ptneg[i]>>yield_auauneg>>eyield_auauneg;
      fdaupos>>ptpos[i]>>yield_daupos>>eyield_daupos;
      fdauneg>>ptneg[i]>>yield_dauneg>>eyield_dauneg;

      yield_auauave[i] = (yield_auaupos+yield_auauneg)/2.0;
      yield_dauave[i] = (yield_daupos+yield_dauneg)/2.0;
      eyield_auauave[i] = sqrt(eyield_auaupos**2+eyield_auauneg**2)/2.0;
      eyield_dauave[i] = sqrt(eyield_daupos**2+eyield_dauneg**2)/2.0;


      ratiopos[i] = yield_auaupos/yield_daupos;
      eratiopos[i] = (yield_auaupos/yield_daupos)*sqrt((eyield_auaupos/yield_auaupos)**2+(eyield_daupos/yield_daupos)**2);

      rationeg[i] = yield_auauneg/yield_dauneg;
      erationeg[i] = (yield_auauneg/yield_dauneg)*sqrt((eyield_auauneg/yield_auauneg)**2+(eyield_dauneg/yield_dauneg)**2);

      ratioave[i] = yield_auauave/yield_dauave;
      eratioave[i] = (yield_auauave/yield_dauave)*sqrt((eyield_auauave/yield_auauave)**2+(eyield_dauave/yield_dauave)**2);


      eptpos[i] = 0;
      eptneg[i] = 0;

      // decided to leave it alone.  only a 2% difference anyway
      // ratiopos[i] *= corrector;
      // rationeg[i] *= corrector;
      // ratioave[i] *= corrector;
      // eratiopos[i] *= corrector;
      // erationeg[i] *= corrector;
      // eratioave[i] *= corrector;

      if(ptpos[i]>3.5&&(pi7id==4||pi7id==5||pi8id==2||pi8id==3))
	{
	  ratiopos[i] = -9;
	  rationeg[i] = -9;
	  ratioave[i] = -9;
	}

      // COME BACK HERE for systematics 
      // ------------------------------ 
      // pions
      if(pi7id<=3&&ptpos[i]<3)
	{
	  esysratiopos[i] = 0.12*ratiopos[i];
	  esysrationeg[i] = 0.12*rationeg[i];
	  esysratioave[i] = 0.12*ratioave[i];
	}
      if(pi7id<=3&&ptpos[i]>3)
	{
	  esysratiopos[i] = 0.13*ratiopos[i];
	  esysrationeg[i] = 0.13*rationeg[i];
	  esysratioave[i] = 0.13*ratioave[i];
	}
      // protons
      if(pi7id>=6&&ptpos[i]<3)
	{
	  esysratiopos[i] = 0.13*ratiopos[i];
	  esysrationeg[i] = 0.13*rationeg[i];
	  esysratioave[i] = 0.13*ratioave[i];
	}
      if(pi7id>=6&&ptpos[i]>3)
	{
	  esysratiopos[i] = 0.16*ratiopos[i];
	  esysrationeg[i] = 0.16*rationeg[i];
	  esysratioave[i] = 0.16*ratioave[i];
	}
      // kaons
      if(pi7id==4||pi7id==5)
	{
	  esysratiopos[i] = 0.17*ratiopos[i];
	  esysrationeg[i] = 0.17*rationeg[i];
	  esysratioave[i] = 0.17*ratioave[i];
	}
      // simple
      if(simple)
	{
	  esysratiopos[i] = 0.14*ratiopos[i];
	  esysrationeg[i] = 0.14*rationeg[i];
	  esysratioave[i] = 0.14*ratioave[i];
	}
      fout<<ptpos[i]<<"\t"<<ratioave[i]<<"\t"<<eratioave[i]<<"\t"<<esysratioave[i]<<endl;
    }
  fout.close();
  fauaupos.close();
  fauauneg.close();
  fdaupos.close();
  fdauneg.close();






  TGraphErrors *tge_syspos = new TGraphErrors(34,ptpos,ratiopos,eptpos,esysratiopos);
  tge_syspos->SetMarkerColor(kGray);
  tge_syspos->SetLineColor(kGray);
  tge_syspos->SetLineWidth(kGray);

  TGraphErrors *tge_sysneg = new TGraphErrors(34,ptneg,rationeg,eptneg,esysrationeg);
  tge_sysneg->SetMarkerColor(kGray);
  tge_sysneg->SetLineColor(kGray);
  tge_sysneg->SetLineWidth(kGray);

  TGraphErrors *tge_pos = new TGraphErrors(34,ptpos,ratiopos,eptpos,eratiopos);
  tge_pos->SetMarkerColor(kRed);
  tge_pos->SetMarkerStyle(kFullSquare);

  TGraphErrors *tge_neg = new TGraphErrors(34,ptneg,rationeg,eptneg,erationeg);
  tge_neg->SetMarkerColor(kBlue);
  tge_neg->SetMarkerStyle(kFullSquare);

  TGraphErrors *tge_sysave = new TGraphErrors(34,ptpos,ratioave,eptpos,esysratioave);
  tge_sysave->SetMarkerColor(kGray);
  tge_sysave->SetLineColor(kGray);
  tge_sysave->SetLineWidth(kGray);
  TGraphErrors *tge_ave = new TGraphErrors(34,ptpos,ratioave,eptpos,eratioave);
  tge_ave->SetMarkerColor(kBlack);
  tge_ave->SetMarkerStyle(kFullCircle);


  TMultiGraph *tmg = new TMultiGraph();
  if(showsys) tmg->Add(tge_syspos);
  if(showsys) tmg->Add(tge_sysneg);
  tmg->Add(tge_pos);
  tmg->Add(tge_neg);
  tmg->Draw("apz");
  tmg->SetMaximum(1.99);
  tmg->SetMinimum(0.01);
  // tmg->SetMaximum(2.0);
  // tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(minx,maxx);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitleOffset(xtitleoffset);

  //tmgclone = (TMultiGraph *)tmg->Clone();
  //cout<<"tmg is "<<tmg<<" tmgclone is "<<tmgclone<<endl;
  if(pi7id<=3)      tmg_pion = (TMultiGraph *)tmg->Clone();
  else if(pi7id>=6) tmg_prot = (TMultiGraph *)tmg->Clone();
  else              tmg_kaon = (TMultiGraph *)tmg->Clone();



  // TLine *line = new TLine(0.0,0.8,6.0,0.8);
  // line->Draw();

  TLegend *leg = new TLegend(0.38,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  if(pi7id<4)
    {
      leg->AddEntry(tge_pos,"#pi^{+}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
      leg->AddEntry(tge_neg,"#pi^{-}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
    }
  else if(pi7id<6)
    {
      leg->AddEntry(tge_pos,"K^{+}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
      leg->AddEntry(tge_neg,"K^{-}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
    }
  else
    {
      leg->AddEntry(tge_pos,"p, (Au+Au 60-92%)/(d+Au 0-20%)","p");
      leg->AddEntry(tge_neg,"#bar{p}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
    }
  leg->SetTextSize(0.035);
  leg->Draw();



  char particle[7];
  if(pi7id<=3) sprintf(particle,"pion");
  else if(pi7id>=6) sprintf(particle,"proton");
  else sprintf(particle,"kaon");
  char figname[100];
  sprintf(figname,"figures/aud_sr_%s.gif",particle);
  //c1->Print(figname);
  sprintf(figname,"figures/aud_sr_%s.eps",particle);
  //c1->Print(figname);


  c1->Clear();
  delete c1;

  delete tmg;
  delete leg;


  TCanvas *c2 = new TCanvas();

  if(pi7id<=3)      {tge_ave->SetMarkerColor(kRed);tge_ave->SetMarkerStyle(kFullCircle);}
  else if(pi7id>=6) {tge_ave->SetMarkerColor(kBlue);tge_ave->SetMarkerStyle(kFullSquare);}
  else              {tge_ave->SetMarkerColor(kGreen+2);tge_ave->SetMarkerStyle(kFullTriangleUp);}

  TMultiGraph *tmg = new TMultiGraph();
  if(showsys) tmg->Add(tge_sysave);
  tmg->Add(tge_ave);
  tmg->Draw("apz");
  tmg->SetMaximum(1.99);
  tmg->SetMinimum(0.01);
  // tmg->SetMaximum(2.0);
  // tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(minx,maxx);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitleOffset(xtitleoffset);


  if(pi7id<=3)      tge_pionA = (TGraphErrors *)tge_ave->Clone();
  else if(pi7id>=6) tge_protA = (TGraphErrors *)tge_ave->Clone();
  else              tge_kaonA = (TGraphErrors *)tge_ave->Clone();
  // this is new
  if(pi7id<=3)      tge_sysave->SetLineColor(kRed-9);
  else if(pi7id>=6) tge_sysave->SetLineColor(kBlue-9);
  else              tge_sysave->SetLineColor(kGreen-9);
  // back to this
  if(pi7id<=3)      tge_pionSA = (TGraphErrors *)tge_sysave->Clone();
  else if(pi7id>=6) tge_protSA = (TGraphErrors *)tge_sysave->Clone();
  else              tge_kaonSA = (TGraphErrors *)tge_sysave->Clone();



  TLegend *leg = new TLegend(0.38,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  if(pi7id<4)
    {
      leg->AddEntry(tge_ave,"#pi^{+}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
    }
  else if(pi7id<6)
    {
      leg->AddEntry(tge_ave,"K^{+}, (Au+Au 60-92%)/(d+Au 0-20%)","p");
    }
  else
    {
      leg->AddEntry(tge_ave,"p, (Au+Au 60-92%)/(d+Au 0-20%)","p");
    }
  leg->SetTextSize(0.035);
  leg->Draw();

  sprintf(figname,"figures/aud_sr_AVE_%s.gif",particle);
  //c2->Print(figname);
  sprintf(figname,"figures/aud_sr_AVE_%s.eps",particle);
  //c2->Print(figname);


  c2->Clear();
  delete c2;


}
