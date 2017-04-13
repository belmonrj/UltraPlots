void pbarp()
{

  float MAXY = 1.5;
  float MINY = 0.0;

  float MAXX = 6.0;
  float MINX = 0.0;

  float RVAL = 0.74;

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->Divide(2,5);

  // --- now AuAu --- //

  ifstream fpbarp0010AuAu("../Run7AuAu/Ratios/regular/pbarp_8_cent0010.txt");
  ifstream fpbarp1020AuAu("../Run7AuAu/Ratios/regular/pbarp_8_cent1020.txt");
  ifstream fpbarp2040AuAu("../Run7AuAu/Ratios/regular/pbarp_8_cent2040.txt");
  ifstream fpbarp4060AuAu("../Run7AuAu/Ratios/regular/pbarp_8_cent4060.txt");
  ifstream fpbarp6092AuAu("../Run7AuAu/Ratios/regular/pbarp_8_cent6092.txt");

  float pT_pbarp0010AuAu[44], epT_pbarp0010AuAu[44], ratio_pbarp0010AuAu[44], eratio_pbarp0010AuAu[44];
  float pT_pbarp1020AuAu[44], epT_pbarp1020AuAu[44], ratio_pbarp1020AuAu[44], eratio_pbarp1020AuAu[44];
  float pT_pbarp2040AuAu[44], epT_pbarp2040AuAu[44], ratio_pbarp2040AuAu[44], eratio_pbarp2040AuAu[44];
  float pT_pbarp4060AuAu[44], epT_pbarp4060AuAu[44], ratio_pbarp4060AuAu[44], eratio_pbarp4060AuAu[44];
  float pT_pbarp6092AuAu[44], epT_pbarp6092AuAu[44], ratio_pbarp6092AuAu[44], eratio_pbarp6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fpbarp0010AuAu>>pT_pbarp0010AuAu[i]>>ratio_pbarp0010AuAu[i]>>eratio_pbarp0010AuAu[i];
      fpbarp1020AuAu>>pT_pbarp1020AuAu[i]>>ratio_pbarp1020AuAu[i]>>eratio_pbarp1020AuAu[i];
      fpbarp2040AuAu>>pT_pbarp2040AuAu[i]>>ratio_pbarp2040AuAu[i]>>eratio_pbarp2040AuAu[i];
      fpbarp4060AuAu>>pT_pbarp4060AuAu[i]>>ratio_pbarp4060AuAu[i]>>eratio_pbarp4060AuAu[i];
      fpbarp6092AuAu>>pT_pbarp6092AuAu[i]>>ratio_pbarp6092AuAu[i]>>eratio_pbarp6092AuAu[i];
      epT_pbarp0010AuAu[i] = 0;
      epT_pbarp1020AuAu[i] = 0;
      epT_pbarp2040AuAu[i] = 0;
      epT_pbarp4060AuAu[i] = 0;
      epT_pbarp6092AuAu[i] = 0;
    }
  fpbarp0010AuAu.close();
  fpbarp1020AuAu.close();
  fpbarp2040AuAu.close();
  fpbarp4060AuAu.close();
  fpbarp6092AuAu.close();

  // --- now dAu --- //

  ifstream fpbarp0088dAu("../Run8dAu/Ratios/regular/pbarp_5_cent0088.txt");
  ifstream fpbarp0020dAu("../Run8dAu/Ratios/regular/pbarp_5_cent0020.txt");
  ifstream fpbarp2040dAu("../Run8dAu/Ratios/regular/pbarp_5_cent2040.txt");
  ifstream fpbarp4060dAu("../Run8dAu/Ratios/regular/pbarp_5_cent4060.txt");
  ifstream fpbarp6088dAu("../Run8dAu/Ratios/regular/pbarp_5_cent6088.txt");

  float pT_pbarp0088dAu[36], epT_pbarp0088dAu[36], ratio_pbarp0088dAu[36], eratio_pbarp0088dAu[36];
  float pT_pbarp0020dAu[36], epT_pbarp0020dAu[36], ratio_pbarp0020dAu[36], eratio_pbarp0020dAu[36];
  float pT_pbarp2040dAu[36], epT_pbarp2040dAu[36], ratio_pbarp2040dAu[36], eratio_pbarp2040dAu[36];
  float pT_pbarp4060dAu[36], epT_pbarp4060dAu[36], ratio_pbarp4060dAu[36], eratio_pbarp4060dAu[36];
  float pT_pbarp6088dAu[36], epT_pbarp6088dAu[36], ratio_pbarp6088dAu[36], eratio_pbarp6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fpbarp0088dAu>>pT_pbarp0088dAu[i]>>ratio_pbarp0088dAu[i]>>eratio_pbarp0088dAu[i];
      fpbarp0020dAu>>pT_pbarp0020dAu[i]>>ratio_pbarp0020dAu[i]>>eratio_pbarp0020dAu[i];
      fpbarp2040dAu>>pT_pbarp2040dAu[i]>>ratio_pbarp2040dAu[i]>>eratio_pbarp2040dAu[i];
      fpbarp4060dAu>>pT_pbarp4060dAu[i]>>ratio_pbarp4060dAu[i]>>eratio_pbarp4060dAu[i];
      fpbarp6088dAu>>pT_pbarp6088dAu[i]>>ratio_pbarp6088dAu[i]>>eratio_pbarp6088dAu[i];
      epT_pbarp0088dAu[i] = 0;
      epT_pbarp0020dAu[i] = 0;
      epT_pbarp2040dAu[i] = 0;
      epT_pbarp4060dAu[i] = 0;
      epT_pbarp6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  ratio_pbarp0088dAu[i] = -9;
	  ratio_pbarp0020dAu[i] = -9;
	  ratio_pbarp2040dAu[i] = -9;
	  ratio_pbarp4060dAu[i] = -9;
	  ratio_pbarp6088dAu[i] = -9;
	  eratio_pbarp0088dAu[i] = 0;
	  eratio_pbarp0020dAu[i] = 0;
	  eratio_pbarp2040dAu[i] = 0;
	  eratio_pbarp4060dAu[i] = 0;
	  eratio_pbarp6088dAu[i] = 0;
	}
    }
  fpbarp0088dAu.close();
  fpbarp0020dAu.close();
  fpbarp2040dAu.close();
  fpbarp4060dAu.close();
  fpbarp6088dAu.close();




  TGraphErrors *tge_pbarp0010AuAu = new TGraphErrors(36,pT_pbarp0010AuAu,ratio_pbarp0010AuAu,epT_pbarp0010AuAu,eratio_pbarp0010AuAu);
  tge_pbarp0010AuAu->SetMarkerColor(kBlack);
  tge_pbarp0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_pbarp1020AuAu = new TGraphErrors(36,pT_pbarp1020AuAu,ratio_pbarp1020AuAu,epT_pbarp1020AuAu,eratio_pbarp1020AuAu);
  tge_pbarp1020AuAu->SetMarkerColor(kBlack);
  tge_pbarp1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_pbarp2040AuAu = new TGraphErrors(36,pT_pbarp2040AuAu,ratio_pbarp2040AuAu,epT_pbarp2040AuAu,eratio_pbarp2040AuAu);
  tge_pbarp2040AuAu->SetMarkerColor(kBlack);
  tge_pbarp2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_pbarp4060AuAu = new TGraphErrors(36,pT_pbarp4060AuAu,ratio_pbarp4060AuAu,epT_pbarp4060AuAu,eratio_pbarp4060AuAu);
  tge_pbarp4060AuAu->SetMarkerColor(kBlack);
  tge_pbarp4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_pbarp6092AuAu = new TGraphErrors(36,pT_pbarp6092AuAu,ratio_pbarp6092AuAu,epT_pbarp6092AuAu,eratio_pbarp6092AuAu);
  tge_pbarp6092AuAu->SetMarkerColor(kBlack);
  tge_pbarp6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_pbarp0088dAu = new TGraphErrors(36,pT_pbarp0088dAu,ratio_pbarp0088dAu,epT_pbarp0088dAu,eratio_pbarp0088dAu);
  tge_pbarp0088dAu->SetMarkerColor(kBlack);
  tge_pbarp0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_pbarp0020dAu = new TGraphErrors(36,pT_pbarp0020dAu,ratio_pbarp0020dAu,epT_pbarp0020dAu,eratio_pbarp0020dAu);
  tge_pbarp0020dAu->SetMarkerColor(kBlack);
  tge_pbarp0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_pbarp2040dAu = new TGraphErrors(36,pT_pbarp2040dAu,ratio_pbarp2040dAu,epT_pbarp2040dAu,eratio_pbarp2040dAu);
  tge_pbarp2040dAu->SetMarkerColor(kBlack);
  tge_pbarp2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_pbarp4060dAu = new TGraphErrors(36,pT_pbarp4060dAu,ratio_pbarp4060dAu,epT_pbarp4060dAu,eratio_pbarp4060dAu);
  tge_pbarp4060dAu->SetMarkerColor(kBlack);
  tge_pbarp4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_pbarp6088dAu = new TGraphErrors(36,pT_pbarp6088dAu,ratio_pbarp6088dAu,epT_pbarp6088dAu,eratio_pbarp6088dAu);
  tge_pbarp6088dAu->SetMarkerColor(kBlack);
  tge_pbarp6088dAu->SetMarkerStyle(kOpenDiamond);

  TLine *line;// = new TLine(MINX,RVAL,MAXX,RVAL);
  //TLine line(MINX,RVAL,MAXX,RVAL);
  TLegend *leg;

  c1->cd(1);
  tge_pbarp0010AuAu->Draw("apz");
  tge_pbarp0010AuAu->SetMaximum(MAXY);
  tge_pbarp0010AuAu->SetMinimum(MINY);
  tge_pbarp0010AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp0010AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp0010AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp0010AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp0010AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp0010AuAu,"Au+Au 0-10%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(3);
  tge_pbarp1020AuAu->Draw("apz");
  tge_pbarp1020AuAu->SetMaximum(MAXY);
  tge_pbarp1020AuAu->SetMinimum(MINY);
  tge_pbarp1020AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp1020AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp1020AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp1020AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp1020AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp1020AuAu,"Au+Au 10-20%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(5);
  tge_pbarp2040AuAu->Draw("apz");
  tge_pbarp2040AuAu->SetMaximum(MAXY);
  tge_pbarp2040AuAu->SetMinimum(MINY);
  tge_pbarp2040AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp2040AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp2040AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp2040AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp2040AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp2040AuAu,"Au+Au 20-40%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(7);
  tge_pbarp4060AuAu->Draw("apz");
  tge_pbarp4060AuAu->SetMaximum(MAXY);
  tge_pbarp4060AuAu->SetMinimum(MINY);
  tge_pbarp4060AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp4060AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp4060AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp4060AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp4060AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp4060AuAu,"Au+Au 40-60%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(9);
  tge_pbarp6092AuAu->Draw("apz");
  tge_pbarp6092AuAu->SetMaximum(MAXY);
  tge_pbarp6092AuAu->SetMinimum(MINY);
  tge_pbarp6092AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp6092AuAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp6092AuAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp6092AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp6092AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp6092AuAu,"Au+Au 60-92%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  // ---

  c1->cd(2);
  tge_pbarp0020dAu->Draw("apz");
  tge_pbarp0020dAu->SetMaximum(MAXY);
  tge_pbarp0020dAu->SetMinimum(MINY);
  tge_pbarp0020dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp0020dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp0020dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp0020dAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp0020dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp0020dAu,"d+Au 0-20%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(4);
  tge_pbarp2040dAu->Draw("apz");
  tge_pbarp2040dAu->SetMaximum(MAXY);
  tge_pbarp2040dAu->SetMinimum(MINY);
  tge_pbarp2040dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp2040dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp2040dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp2040dAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp2040dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp2040dAu,"d+Au 20-40%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(6);
  tge_pbarp0088dAu->Draw("apz");
  tge_pbarp0088dAu->SetMaximum(MAXY);
  tge_pbarp0088dAu->SetMinimum(MINY);
  tge_pbarp0088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp0088dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp0088dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp0088dAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp0088dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp0088dAu,"d+Au 0-88%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(8);
  tge_pbarp4060dAu->Draw("apz");
  tge_pbarp4060dAu->SetMaximum(MAXY);
  tge_pbarp4060dAu->SetMinimum(MINY);
  tge_pbarp4060dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp4060dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp4060dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp4060dAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp4060dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp4060dAu,"d+Au 40-60%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1->cd(10);
  tge_pbarp6088dAu->Draw("apz");
  tge_pbarp6088dAu->SetMaximum(MAXY);
  tge_pbarp6088dAu->SetMinimum(MINY);
  tge_pbarp6088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pbarp6088dAu->GetYaxis()->SetLabelSize(0.12);
  tge_pbarp6088dAu->GetXaxis()->SetLabelSize(0.12);
  tge_pbarp6088dAu->GetYaxis()->SetNdivisions(505);
  //tge_pbarp6088dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pbarp6088dAu,"d+Au 60-88%","p");
  leg->Draw("same");
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  // ---






  c1->Print("figures/pbarp.gif");
  c1->Print("figures/pbarp.eps");



}
