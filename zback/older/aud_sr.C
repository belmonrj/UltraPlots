void aud_sr()
{

  doit(0,1,"0020");
  doit(4,3,"0020");
  doit(6,5,"0020");

}

void doit(int pi7id = 6, int pi8id = 5, char *daucent="0020")
{

  TCanvas *c1 = new TCanvas();

  float ncoll7 = 14.5;
  float ncoll8 = 15.1;
  float biasf8 = 0.95;

  float corrector = ncoll8/(ncoll7*biasf8);

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
  tmg->Draw("ap");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,6.0);
  tmg->GetYaxis()->SetTitle("Ratio of Spectra");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();

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
