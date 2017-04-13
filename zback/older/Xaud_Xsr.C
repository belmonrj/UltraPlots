TMultiGraph *tmg_pion;
TMultiGraph *tmg_kaon;
TMultiGraph *tmg_prot;

int xtitleoffset = 1.5;

void aud_sr()
{

  doit(0,1,"0020");
  doit(4,3,"0020");
  doit(6,5,"0020");

  doit4x4(tmg_pion,tmg_kaon,tmg_prot);

}

void doit4x4(TMultiGraph *pion, TMultiGraph *kaon, TMultiGraph *prot)
{

  cout<<"4x4"<<endl;

  cout<<"pion is "<<pion<<endl;
  cout<<"kaon is "<<kaon<<endl;
  cout<<"prot is "<<prot<<endl;

  if(pion==NULL||kaon==NULL||prot==NULL)
    {
      cout<<"one or more TMGs are NULL, aborting"<<endl;
      return;
    }

  TLine *line = new TLine(0.0,0.7,6.0,0.7);

  TCanvas *c1 = new TCanvas("c1","",700,700);
  // c1->Divide(2,2);

  float padmargin = 0.1; // 0.1 is default...

  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.5,0.5,1.0); // upper left
  c1_1->Draw();
  c1_1->SetTopMargin(padmargin);
  c1_1->SetLeftMargin(padmargin);
  c1_1->SetRightMargin(0);
  c1_1->SetBottomMargin(0);
  c1_1->SetTicks(1,1);
  c1_1->cd();
  pion->Draw("ap");
  TLegend *leg1 = new TLegend(0.68,0.6,0.8,0.8);
  leg1->SetBorderSize(0);
  leg1->SetFillColor(kWhite);
  leg1->AddEntry((TObject*)0,"#pi","");
  leg1->SetTextSize(0.1);
  leg1->Draw();
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
  kaon->Draw("ap");
  TLegend *leg2 = new TLegend(0.68,0.68,0.88,0.88);
  leg2->SetBorderSize(0);
  leg2->SetFillColor(kWhite);
  leg2->AddEntry((TObject*)0,"K","");
  leg2->SetTextSize(0.1);
  leg2->Draw();
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
  prot->Draw("ap");
  TLegend *leg3 = new TLegend(0.68,0.6,0.8,0.8);
  leg3->SetBorderSize(0);
  leg3->SetFillColor(kWhite);
  leg3->AddEntry((TObject*)0,"p","");
  leg3->SetTextSize(0.1);
  leg3->Draw();
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
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  //tmg->GetXaxis()->SetTitleOffset(xtitleoffset);
  TGraph *tge_pos = new TGraph(1,dummy,dummy);
  TGraph *tge_neg = new TGraph(1,dummy,dummy);
  tge_pos->SetMarkerColor(kRed);
  tge_neg->SetMarkerColor(kBlue);
  tge_pos->SetMarkerStyle(kFullSquare);
  tge_neg->SetMarkerStyle(kFullSquare);
  //TLegend *leg4 = new TLegend(0.12,0.4,0.88,0.6);
  TLegend *leg4 = new TLegend(0.15,0.35,0.85,0.65);
  leg4->SetBorderSize(0);
  leg4->SetFillColor(kWhite);
  leg4->AddEntry((TObject*)0,"(Au+Au 60-92%)/(d+Au 0-20%),","");
  leg4->AddEntry((TObject*)0,"Scaled by N_{coll}","");
  leg4->AddEntry(tge_pos,"positive particles","p");
  leg4->AddEntry(tge_neg,"negative particles","p");
  leg4->AddEntry(line,"line drawn at 0.70 as visual aid","l");
  leg4->Draw();

  c1->Print("figures/aud_4x4.gif");
  c1->Print("figures/aud_4x4.eps");
  c1->Print("figures/thedau.gif");
  c1->Print("figures/thedau.eps");

}

void doit(int pi7id = 6, int pi8id = 5, char *daucent="0020")
{

  TCanvas *c1 = new TCanvas();

  float ncoll7 = 14.5;
  float ncoll8 = 15.1;

  float corrector = ncoll8/ncoll7;

  float ptpos[36], ptneg[36];
  float eptpos[36], eptneg[36];
  float ratiopos[36], rationeg[36];
  float eratiopos[36], erationeg[36];

  float yield_daupos, yield_dauneg;
  float eyield_daupos, eyield_dauneg;
  float yield_auaupos, yield_auauneg;
  float eyield_auaupos, eyield_auauneg;


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

  cout<<"corrector is "<<corrector<<endl;
  for(int i=0; i<36; i++)
    {
      fauaupos>>ptpos[i]>>yield_auaupos>>eyield_auaupos;
      fauauneg>>ptneg[i]>>yield_auauneg>>eyield_auauneg;
      fdaupos>>ptpos[i]>>yield_daupos>>eyield_daupos;
      fdauneg>>ptneg[i]>>yield_dauneg>>eyield_dauneg;

      ratiopos[i] = yield_auaupos/yield_daupos;
      eratiopos[i] = (yield_auaupos/yield_daupos)*sqrt((eyield_auaupos/yield_auaupos)**2+(eyield_daupos/yield_daupos)**2);

      rationeg[i] = yield_auauneg/yield_dauneg;
      erationeg[i] = (yield_auauneg/yield_dauneg)*sqrt((eyield_auauneg/yield_auauneg)**2+(eyield_dauneg/yield_dauneg)**2);

      eptpos[i] = 0;
      eptneg[i] = 0;

      ratiopos[i] *= corrector;
      rationeg[i] *= corrector;
      eratiopos[i] *= corrector;
      erationeg[i] *= corrector;

      if(ptpos[i]>3.5&&(pi7id==4||pi7id==5||pi8id==2||pi8id==3))
	{
	  ratiopos[i] = -9;
	  rationeg[i] = -9;
	}

    }
  fauaupos.close();
  fauauneg.close();
  fdaupos.close();
  fdauneg.close();



  TGraphErrors *tge_pos = new TGraphErrors(34,ptpos,ratiopos,eptpos,eratiopos);
  tge_pos->SetMarkerColor(kRed);
  tge_pos->SetMarkerStyle(kFullSquare);

  TGraphErrors *tge_neg = new TGraphErrors(34,ptneg,rationeg,eptneg,erationeg);
  tge_neg->SetMarkerColor(kBlue);
  tge_neg->SetMarkerStyle(kFullSquare);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_pos);
  tmg->Add(tge_neg);
  tmg->Draw("apz");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  //tmg->GetXaxis()->SetTitleOffset(xtitleoffset);

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
  c1->Print(figname);
  sprintf(figname,"figures/aud_sr_%s.eps",particle);
  c1->Print(figname);


  c1->Clear();
  delete c1;

}
