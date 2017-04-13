void ratio2()
{

  TCanvas *c1 = new TCanvas("c1","",1200,400);

  float pt[33], ept[33], ratio[33], eratio[33], esysratio[33];
  ifstream fin;

  fin.open("pipi.dat");
  for(int i=0; i<14; i++)
    {
      fin>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
      ept[i] = 0;
    }
  fin.close();
  TGraphErrors *tge_pipi = new TGraphErrors(14,pt,ratio,ept,eratio);
  TGraphErrors *tge_pipiS = new TGraphErrors(14,pt,ratio,ept,esysratio);

  fin.open("kaka.dat");
  for(int i=0; i<14; i++)
    {
      fin>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
      ept[i] = 0;
    }
  fin.close();
  TGraphErrors *tge_kaka = new TGraphErrors(14,pt,ratio,ept,eratio);
  TGraphErrors *tge_kakaS = new TGraphErrors(14,pt,ratio,ept,esysratio);

  fin.open("pbarp.dat");
  for(int i=0; i<14; i++)
    {
      fin>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
      ept[i] = 0;
    }
  fin.close();
  TGraphErrors *tge_pbarp = new TGraphErrors(14,pt,ratio,ept,eratio);
  TGraphErrors *tge_pbarpS = new TGraphErrors(14,pt,ratio,ept,esysratio);






  fin.open("pipi1.dat");
  for(int i=0; i<27; i++)
    {
      fin>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
      ept[i] = 0;
    }
  fin.close();
  TGraphErrors *tge_pipi1 = new TGraphErrors(27,pt,ratio,ept,eratio);
  TGraphErrors *tge_pipi1S = new TGraphErrors(27,pt,ratio,ept,esysratio);

  fin.open("kaka1.dat");
  for(int i=0; i<16; i++)
    {
      fin>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
      ept[i] = 0;
    }
  fin.close();
  TGraphErrors *tge_kaka1 = new TGraphErrors(16,pt,ratio,ept,eratio);
  TGraphErrors *tge_kaka1S = new TGraphErrors(16,pt,ratio,ept,esysratio);

  fin.open("pbarp1.dat");
  for(int i=0; i<33; i++)
    {
      fin>>pt[i]>>ratio[i]>>eratio[i]>>esysratio[i];
      ept[i] = 0;
    }
  fin.close();
  // TGraphErrors *tge_pbarp1 = new TGraphErrors(33,pt,ratio,ept,eratio);
  // TGraphErrors *tge_pbarp1S = new TGraphErrors(33,pt,ratio,ept,esysratio);
  TGraphErrors *tge_pbarp1 = new TGraphErrors(25,pt,ratio,ept,eratio);
  TGraphErrors *tge_pbarp1S = new TGraphErrors(25,pt,ratio,ept,esysratio);





  tge_pipi->SetMarkerStyle(kFullStar);
  tge_kaka->SetMarkerStyle(kFullStar);
  tge_pbarp->SetMarkerStyle(kFullStar);

  tge_pipi->SetMarkerSize(1.8);
  tge_kaka->SetMarkerSize(1.8);
  tge_pbarp->SetMarkerSize(1.8);


  tge_pipiS->SetLineColor(kGray);
  tge_pipiS->SetLineWidth(10);
  tge_kakaS->SetLineColor(kGray);
  tge_kakaS->SetLineWidth(10);
  tge_pbarpS->SetLineColor(kGray);
  tge_pbarpS->SetLineWidth(10);



  tge_pipi1->SetMarkerStyle(kFullCross);
  tge_kaka1->SetMarkerStyle(kFullCross);
  tge_pbarp1->SetMarkerStyle(kFullCross);


  tge_pipi1S->SetLineColor(kGray);
  tge_pipi1S->SetLineWidth(10);
  tge_kaka1S->SetLineColor(kGray);
  tge_kaka1S->SetLineWidth(10);
  tge_pbarp1S->SetLineColor(kGray);
  tge_pbarp1S->SetLineWidth(10);



  TMultiGraph *tmg_pipi = new TMultiGraph();
  tmg_pipi->Add(tge_pipiS);
  tmg_pipi->Add(tge_pipi);

  TMultiGraph *tmg_kaka = new TMultiGraph();
  tmg_kaka->Add(tge_kakaS);
  tmg_kaka->Add(tge_kaka);

  TMultiGraph *tmg_pbarp = new TMultiGraph();
  tmg_pbarp->Add(tge_pbarpS);
  tmg_pbarp->Add(tge_pbarp);



  TMultiGraph *tmg_pipi1 = new TMultiGraph();
  tmg_pipi1->Add(tge_pipi1S);
  tmg_pipi1->Add(tge_pipi1);

  TMultiGraph *tmg_kaka1 = new TMultiGraph();
  tmg_kaka1->Add(tge_kaka1S);
  tmg_kaka1->Add(tge_kaka1);

  TMultiGraph *tmg_pbarp1 = new TMultiGraph();
  tmg_pbarp1->Add(tge_pbarp1S);
  tmg_pbarp1->Add(tge_pbarp1);


  c1->Divide(3,1);



  float minx = 0.0;
  float maxx = 9.0;
  float miny = 0.2;
  float maxy = 1.2;

  c1_1->cd();
  tmg_pipi->Draw("apz");
  tmg_pipi1->Draw("pz");
  tmg_pipi->SetMaximum(maxy);
  tmg_pipi->SetMinimum(miny);
  tmg_pipi->GetXaxis()->SetLimits(minx,maxx);
  tmg_pipi->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pipi->GetXaxis()->CenterTitle();
  TLegend *leg1 = new TLegend(0.18,0.18,0.38,0.38);
  leg1->SetBorderSize(0);
  leg1->SetFillColor(kWhite);
  leg1->AddEntry((TObject*)0,"#pi^{-}/#pi^{+}","");
  leg1->SetTextSize(0.1);
  leg1->Draw();

  c1_2->cd();
  tmg_kaka->Draw("apz");
  tmg_kaka1->Draw("pz");
  tmg_kaka->SetMaximum(maxy);
  tmg_kaka->SetMinimum(miny);
  tmg_kaka->GetXaxis()->SetLimits(minx,maxx);
  tmg_kaka->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_kaka->GetXaxis()->CenterTitle();
  TLegend *leg2 = new TLegend(0.18,0.18,0.38,0.38);
  leg2->SetBorderSize(0);
  leg2->SetFillColor(kWhite);
  leg2->AddEntry((TObject*)0,"K^{-}/K^{+}","");
  leg2->SetTextSize(0.1);
  leg2->Draw();

  c1_3->cd();
  tmg_pbarp->Draw("apz");
  tmg_pbarp1->Draw("pz");
  tmg_pbarp->SetMaximum(maxy);
  tmg_pbarp->SetMinimum(miny);
  tmg_pbarp->GetXaxis()->SetLimits(minx,maxx);
  tmg_pbarp->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pbarp->GetXaxis()->CenterTitle();
  TLegend *leg3 = new TLegend(0.18,0.18,0.38,0.38);
  leg3->SetBorderSize(0);
  leg3->SetFillColor(kWhite);
  leg3->AddEntry((TObject*)0,"#bar{p}/p","");
  leg3->SetTextSize(0.1);
  leg3->Draw();



  c1->Print("star_pp_ratios2.eps");
  c1->Print("pp_ratios2.gif");


}
