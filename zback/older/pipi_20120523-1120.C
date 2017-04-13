void pipi()
{

  float MAXY = 2.0;
  float MINY = 0.0;

  float MAXX = 6.0;
  float MINX = 0.0;

  float RVAL = 1.0;

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->Divide(2,5);

  // --- now AuAu --- //

  ifstream fpipi0010AuAu("../Run7AuAu/Ratios/regular/pipi_2_cent0010.txt");
  ifstream fpipi1020AuAu("../Run7AuAu/Ratios/regular/pipi_2_cent1020.txt");
  ifstream fpipi2040AuAu("../Run7AuAu/Ratios/regular/pipi_2_cent2040.txt");
  ifstream fpipi4060AuAu("../Run7AuAu/Ratios/regular/pipi_2_cent4060.txt");
  ifstream fpipi6092AuAu("../Run7AuAu/Ratios/regular/pipi_2_cent6092.txt");

  float pT_pipi0010AuAu[44], epT_pipi0010AuAu[44], ratio_pipi0010AuAu[44], eratio_pipi0010AuAu[44];
  float pT_pipi1020AuAu[44], epT_pipi1020AuAu[44], ratio_pipi1020AuAu[44], eratio_pipi1020AuAu[44];
  float pT_pipi2040AuAu[44], epT_pipi2040AuAu[44], ratio_pipi2040AuAu[44], eratio_pipi2040AuAu[44];
  float pT_pipi4060AuAu[44], epT_pipi4060AuAu[44], ratio_pipi4060AuAu[44], eratio_pipi4060AuAu[44];
  float pT_pipi6092AuAu[44], epT_pipi6092AuAu[44], ratio_pipi6092AuAu[44], eratio_pipi6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fpipi0010AuAu>>pT_pipi0010AuAu[i]>>ratio_pipi0010AuAu[i]>>eratio_pipi0010AuAu[i];
      fpipi1020AuAu>>pT_pipi1020AuAu[i]>>ratio_pipi1020AuAu[i]>>eratio_pipi1020AuAu[i];
      fpipi2040AuAu>>pT_pipi2040AuAu[i]>>ratio_pipi2040AuAu[i]>>eratio_pipi2040AuAu[i];
      fpipi4060AuAu>>pT_pipi4060AuAu[i]>>ratio_pipi4060AuAu[i]>>eratio_pipi4060AuAu[i];
      fpipi6092AuAu>>pT_pipi6092AuAu[i]>>ratio_pipi6092AuAu[i]>>eratio_pipi6092AuAu[i];
      epT_pipi0010AuAu[i] = 0;
      epT_pipi1020AuAu[i] = 0;
      epT_pipi2040AuAu[i] = 0;
      epT_pipi4060AuAu[i] = 0;
      epT_pipi6092AuAu[i] = 0;
    }
  fpipi0010AuAu.close();
  fpipi1020AuAu.close();
  fpipi2040AuAu.close();
  fpipi4060AuAu.close();
  fpipi6092AuAu.close();

  // --- now dAu --- //

  ifstream fpipi0088dAu("../Run8dAu/Ratios/regular/pipi_1_cent0088.txt");
  ifstream fpipi0020dAu("../Run8dAu/Ratios/regular/pipi_1_cent0020.txt");
  ifstream fpipi2040dAu("../Run8dAu/Ratios/regular/pipi_1_cent2040.txt");
  ifstream fpipi4060dAu("../Run8dAu/Ratios/regular/pipi_1_cent4060.txt");
  ifstream fpipi6088dAu("../Run8dAu/Ratios/regular/pipi_1_cent6088.txt");

  float pT_pipi0088dAu[36], epT_pipi0088dAu[36], ratio_pipi0088dAu[36], eratio_pipi0088dAu[36];
  float pT_pipi0020dAu[36], epT_pipi0020dAu[36], ratio_pipi0020dAu[36], eratio_pipi0020dAu[36];
  float pT_pipi2040dAu[36], epT_pipi2040dAu[36], ratio_pipi2040dAu[36], eratio_pipi2040dAu[36];
  float pT_pipi4060dAu[36], epT_pipi4060dAu[36], ratio_pipi4060dAu[36], eratio_pipi4060dAu[36];
  float pT_pipi6088dAu[36], epT_pipi6088dAu[36], ratio_pipi6088dAu[36], eratio_pipi6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fpipi0088dAu>>pT_pipi0088dAu[i]>>ratio_pipi0088dAu[i]>>eratio_pipi0088dAu[i];
      fpipi0020dAu>>pT_pipi0020dAu[i]>>ratio_pipi0020dAu[i]>>eratio_pipi0020dAu[i];
      fpipi2040dAu>>pT_pipi2040dAu[i]>>ratio_pipi2040dAu[i]>>eratio_pipi2040dAu[i];
      fpipi4060dAu>>pT_pipi4060dAu[i]>>ratio_pipi4060dAu[i]>>eratio_pipi4060dAu[i];
      fpipi6088dAu>>pT_pipi6088dAu[i]>>ratio_pipi6088dAu[i]>>eratio_pipi6088dAu[i];
      epT_pipi0088dAu[i] = 0;
      epT_pipi0020dAu[i] = 0;
      epT_pipi2040dAu[i] = 0;
      epT_pipi4060dAu[i] = 0;
      epT_pipi6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  ratio_pipi0088dAu[i] = -9;
	  ratio_pipi0020dAu[i] = -9;
	  ratio_pipi2040dAu[i] = -9;
	  ratio_pipi4060dAu[i] = -9;
	  ratio_pipi6088dAu[i] = -9;
	  eratio_pipi0088dAu[i] = 0;
	  eratio_pipi0020dAu[i] = 0;
	  eratio_pipi2040dAu[i] = 0;
	  eratio_pipi4060dAu[i] = 0;
	  eratio_pipi6088dAu[i] = 0;
	}
    }
  fpipi0088dAu.close();
  fpipi0020dAu.close();
  fpipi2040dAu.close();
  fpipi4060dAu.close();
  fpipi6088dAu.close();




  TGraphErrors *tge_pipi0010AuAu = new TGraphErrors(36,pT_pipi0010AuAu,ratio_pipi0010AuAu,epT_pipi0010AuAu,eratio_pipi0010AuAu);
  tge_pipi0010AuAu->SetMarkerColor(kBlack);
  tge_pipi0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_pipi1020AuAu = new TGraphErrors(36,pT_pipi1020AuAu,ratio_pipi1020AuAu,epT_pipi1020AuAu,eratio_pipi1020AuAu);
  tge_pipi1020AuAu->SetMarkerColor(kBlack);
  tge_pipi1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_pipi2040AuAu = new TGraphErrors(36,pT_pipi2040AuAu,ratio_pipi2040AuAu,epT_pipi2040AuAu,eratio_pipi2040AuAu);
  tge_pipi2040AuAu->SetMarkerColor(kBlack);
  tge_pipi2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_pipi4060AuAu = new TGraphErrors(36,pT_pipi4060AuAu,ratio_pipi4060AuAu,epT_pipi4060AuAu,eratio_pipi4060AuAu);
  tge_pipi4060AuAu->SetMarkerColor(kBlack);
  tge_pipi4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_pipi6092AuAu = new TGraphErrors(36,pT_pipi6092AuAu,ratio_pipi6092AuAu,epT_pipi6092AuAu,eratio_pipi6092AuAu);
  tge_pipi6092AuAu->SetMarkerColor(kBlack);
  tge_pipi6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_pipi0088dAu = new TGraphErrors(36,pT_pipi0088dAu,ratio_pipi0088dAu,epT_pipi0088dAu,eratio_pipi0088dAu);
  tge_pipi0088dAu->SetMarkerColor(kBlack);
  tge_pipi0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_pipi0020dAu = new TGraphErrors(36,pT_pipi0020dAu,ratio_pipi0020dAu,epT_pipi0020dAu,eratio_pipi0020dAu);
  tge_pipi0020dAu->SetMarkerColor(kBlack);
  tge_pipi0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_pipi2040dAu = new TGraphErrors(36,pT_pipi2040dAu,ratio_pipi2040dAu,epT_pipi2040dAu,eratio_pipi2040dAu);
  tge_pipi2040dAu->SetMarkerColor(kBlack);
  tge_pipi2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_pipi4060dAu = new TGraphErrors(36,pT_pipi4060dAu,ratio_pipi4060dAu,epT_pipi4060dAu,eratio_pipi4060dAu);
  tge_pipi4060dAu->SetMarkerColor(kBlack);
  tge_pipi4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_pipi6088dAu = new TGraphErrors(36,pT_pipi6088dAu,ratio_pipi6088dAu,epT_pipi6088dAu,eratio_pipi6088dAu);
  tge_pipi6088dAu->SetMarkerColor(kBlack);
  tge_pipi6088dAu->SetMarkerStyle(kOpenDiamond);

  TLine *line;// = new TLine(MINX,RVAL,MAXX,RVAL);
  //TLine line(MINX,RVAL,MAXX,RVAL);
  TLegend *leg;

  c1->cd(1);
  tge_pipi0010AuAu->Draw("apz");
  tge_pipi0010AuAu->SetMaximum(MAXY);
  tge_pipi0010AuAu->SetMinimum(MINY);
  tge_pipi0010AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi0010AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi0010AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi0010AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi0010AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0010AuAu,"Au+Au 0-10%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(3);
  tge_pipi1020AuAu->Draw("apz");
  tge_pipi1020AuAu->SetMaximum(MAXY);
  tge_pipi1020AuAu->SetMinimum(MINY);
  tge_pipi1020AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi1020AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi1020AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi1020AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi1020AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi1020AuAu,"Au+Au 10-20%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(5);
  tge_pipi2040AuAu->Draw("apz");
  tge_pipi2040AuAu->SetMaximum(MAXY);
  tge_pipi2040AuAu->SetMinimum(MINY);
  tge_pipi2040AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi2040AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi2040AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi2040AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi2040AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi2040AuAu,"Au+Au 20-40%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(7);
  tge_pipi4060AuAu->Draw("apz");
  tge_pipi4060AuAu->SetMaximum(MAXY);
  tge_pipi4060AuAu->SetMinimum(MINY);
  tge_pipi4060AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi4060AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi4060AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi4060AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi4060AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi4060AuAu,"Au+Au 40-60%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(9);
  tge_pipi6092AuAu->Draw("apz");
  tge_pipi6092AuAu->SetMaximum(MAXY);
  tge_pipi6092AuAu->SetMinimum(MINY);
  tge_pipi6092AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi6092AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi6092AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi6092AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi6092AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi6092AuAu,"Au+Au 60-92%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  // ---

  c1->cd(2);
  tge_pipi0020dAu->Draw("apz");
  tge_pipi0020dAu->SetMaximum(MAXY);
  tge_pipi0020dAu->SetMinimum(MINY);
  tge_pipi0020dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi0020dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi0020dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi0020dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi0020dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0020dAu,"d+Au 0-20%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(4);
  tge_pipi2040dAu->Draw("apz");
  tge_pipi2040dAu->SetMaximum(MAXY);
  tge_pipi2040dAu->SetMinimum(MINY);
  tge_pipi2040dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi2040dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi2040dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi2040dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi2040dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi2040dAu,"d+Au 20-40%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(6);
  tge_pipi0088dAu->Draw("apz");
  tge_pipi0088dAu->SetMaximum(MAXY);
  tge_pipi0088dAu->SetMinimum(MINY);
  tge_pipi0088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi0088dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi0088dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi0088dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi0088dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0088dAu,"d+Au 0-88%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(8);
  tge_pipi4060dAu->Draw("apz");
  tge_pipi4060dAu->SetMaximum(MAXY);
  tge_pipi4060dAu->SetMinimum(MINY);
  tge_pipi4060dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi4060dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi4060dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi4060dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi4060dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi4060dAu,"d+Au 40-60%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(10);
  tge_pipi6088dAu->Draw("apz");
  tge_pipi6088dAu->SetMaximum(MAXY);
  tge_pipi6088dAu->SetMinimum(MINY);
  tge_pipi6088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi6088dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pipi6088dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pipi6088dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi6088dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi6088dAu,"d+Au 60-88%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  // ---






  c1->Print("figures/pipi.gif");
  c1->Print("figures/pipi.eps");



}
