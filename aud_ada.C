void aud_ada()
{

  doit();

}



void doit(int pi7id = 6, int pi8id = 5, char *daucent="0020")
{

  float max = 5.0;

  float highcut = 3.0;
  float height = 2.0;
  if(pi7id>5)
    {
      highcut = 4.5;
      height = 3.0;
    }

  float pt_auau[36];
  float pt_dau[36];
  float ept_auau[36];
  float ept_dau[36];
  float ratiopos_auau[36];
  float ratiopos_dau[36];
  float rationeg_auau[36];
  float rationeg_dau[36];
  float eratiopos_auau[36];
  float eratiopos_dau[36];
  float erationeg_auau[36];
  float erationeg_dau[36];

  char fauauname[100];
  char fdauname[100];
  sprintf(fauauname,"../Run7AuAu/Ratios/regular/raa_%d_cent6092.txt",pi7id);
  sprintf(fdauname,"../Run8dAu/Ratios/regular/rda_%d_cent%s.txt",pi8id,daucent);
  ifstream fauau(fauauname);
  ifstream fdau(fdauname);
  for(int i=0; i<36; i++)
    {
      fauau>>pt_auau[i]>>ratiopos_auau[i]>>eratiopos_auau[i]>>rationeg_auau[i]>>erationeg_auau[i];
      fdau>>pt_dau[i]>>ratiopos_dau[i]>>eratiopos_dau[i]>>rationeg_dau[i]>>erationeg_dau[i];
      ept_auau[i]=0;
      ept_dau[i]=0;
      if(pt_auau[i]<0.5||pt_auau[i]>highcut)
	{
	  ratiopos_auau[i] = -9;
	  rationeg_auau[i] = -9;
	  ratiopos_dau[i] = -9;
	  rationeg_dau[i] = -9;
	  eratiopos_auau[i] = 0;
	  erationeg_auau[i] = 0;
	  eratiopos_dau[i] = 0;
	  erationeg_dau[i] = 0;
	}
    }

  TGraphErrors *tge_ratiopos_auau = new TGraphErrors(36,pt_auau,ratiopos_auau,ept_auau,eratiopos_auau);
  tge_ratiopos_auau->SetMarkerStyle(kFullCircle);
  tge_ratiopos_auau->SetMarkerColor(kRed);
  TGraphErrors *tge_rationeg_auau = new TGraphErrors(36,pt_auau,rationeg_auau,ept_auau,erationeg_auau);
  tge_rationeg_auau->SetMarkerStyle(kFullSquare);
  tge_rationeg_auau->SetMarkerColor(kBlue);

  TGraphErrors *tge_ratiopos_dau = new TGraphErrors(36,pt_dau,ratiopos_dau,ept_dau,eratiopos_dau);
  tge_ratiopos_dau->SetMarkerStyle(kFullTriangleUp);
  tge_ratiopos_dau->SetMarkerColor(kGreen+2);
  TGraphErrors *tge_rationeg_dau = new TGraphErrors(36,pt_dau,rationeg_dau,ept_dau,erationeg_dau);
  tge_rationeg_dau->SetMarkerStyle(kFullTriangleDown);
  tge_rationeg_dau->SetMarkerColor(kMagenta+2);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge_ratiopos_auau);
  tmg->Add(tge_rationeg_auau);
  tmg->Add(tge_ratiopos_dau);
  tmg->Add(tge_rationeg_dau);
  tmg->Draw("apz");
  tmg->SetMaximum(height);
  tmg->SetMinimum(0.0);
  TLine *line = new TLine(0.0,1.0,max,1.0);
  line->Draw();
  tmg->GetXaxis()->SetLimits(0.0,max);
  tmg->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg->GetXaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitle("Nuclear Modification Ractor");
  tmg->GetYaxis()->CenterTitle();
  tmg->GetYaxis()->SetTitleOffset(1.5);

  TLegend *leg = new TLegend(0.12,0.68,0.48,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  if(pi7id<4)
    {
      leg->AddEntry(tge_ratiopos_auau,"#pi^{+} R_{AA} 60-92%","p");
      leg->AddEntry(tge_rationeg_auau,"#pi^{-} R_{AA} 60-92%","p");
      leg->AddEntry(tge_ratiopos_dau,"#pi^{+} R_{dA} 0-20%","p");
      leg->AddEntry(tge_rationeg_dau,"#pi^{-} R_{dA} 0-20%","p");
    }
  else
    {
      leg->AddEntry(tge_ratiopos_auau,"p R_{AA} 60-92%","p");
      leg->AddEntry(tge_rationeg_auau,"#bar{p} R_{AA} 60-92%","p");
      leg->AddEntry(tge_ratiopos_dau,"p R_{dA} 0-20%","p");
      leg->AddEntry(tge_rationeg_dau,"#bar{p} R_{dA} 0-20%","p");
    }
  leg->Draw();

}
