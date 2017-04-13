void kaka()
{

  TCanvas *c1 = new TCanvas("c1","",950,700);
  c1->Divide(2,5);

  // --- now AuAu --- //

  ifstream fkaka0010AuAu("../Run7AuAu/Ratios/regular/kaka_4_cent0010.txt");
  ifstream fkaka1020AuAu("../Run7AuAu/Ratios/regular/kaka_4_cent1020.txt");
  ifstream fkaka2040AuAu("../Run7AuAu/Ratios/regular/kaka_4_cent2040.txt");
  ifstream fkaka4060AuAu("../Run7AuAu/Ratios/regular/kaka_4_cent4060.txt");
  ifstream fkaka6092AuAu("../Run7AuAu/Ratios/regular/kaka_4_cent6092.txt");

  float pT_kaka0010AuAu[44], epT_kaka0010AuAu[44], ratio_kaka0010AuAu[44], eratio_kaka0010AuAu[44];
  float pT_kaka1020AuAu[44], epT_kaka1020AuAu[44], ratio_kaka1020AuAu[44], eratio_kaka1020AuAu[44];
  float pT_kaka2040AuAu[44], epT_kaka2040AuAu[44], ratio_kaka2040AuAu[44], eratio_kaka2040AuAu[44];
  float pT_kaka4060AuAu[44], epT_kaka4060AuAu[44], ratio_kaka4060AuAu[44], eratio_kaka4060AuAu[44];
  float pT_kaka6092AuAu[44], epT_kaka6092AuAu[44], ratio_kaka6092AuAu[44], eratio_kaka6092AuAu[44];

  for(int i=0; i<44; i++)
    {
      fkaka0010AuAu>>pT_kaka0010AuAu[i]>>ratio_kaka0010AuAu[i]>>eratio_kaka0010AuAu[i];
      fkaka1020AuAu>>pT_kaka1020AuAu[i]>>ratio_kaka1020AuAu[i]>>eratio_kaka1020AuAu[i];
      fkaka2040AuAu>>pT_kaka2040AuAu[i]>>ratio_kaka2040AuAu[i]>>eratio_kaka2040AuAu[i];
      fkaka4060AuAu>>pT_kaka4060AuAu[i]>>ratio_kaka4060AuAu[i]>>eratio_kaka4060AuAu[i];
      fkaka6092AuAu>>pT_kaka6092AuAu[i]>>ratio_kaka6092AuAu[i]>>eratio_kaka6092AuAu[i];
      epT_kaka0010AuAu[i] = 0;
      epT_kaka1020AuAu[i] = 0;
      epT_kaka2040AuAu[i] = 0;
      epT_kaka4060AuAu[i] = 0;
      epT_kaka6092AuAu[i] = 0;
    }
  fkaka0010AuAu.close();
  fkaka1020AuAu.close();
  fkaka2040AuAu.close();
  fkaka4060AuAu.close();
  fkaka6092AuAu.close();

  // --- now dAu --- //

  ifstream fkaka0088dAu("../Run8dAu/Ratios/regular/kaka_3_cent0088.txt");
  ifstream fkaka0020dAu("../Run8dAu/Ratios/regular/kaka_3_cent0020.txt");
  ifstream fkaka2040dAu("../Run8dAu/Ratios/regular/kaka_3_cent2040.txt");
  ifstream fkaka4060dAu("../Run8dAu/Ratios/regular/kaka_3_cent4060.txt");
  ifstream fkaka6088dAu("../Run8dAu/Ratios/regular/kaka_3_cent6088.txt");

  float pT_kaka0088dAu[36], epT_kaka0088dAu[36], ratio_kaka0088dAu[36], eratio_kaka0088dAu[36];
  float pT_kaka0020dAu[36], epT_kaka0020dAu[36], ratio_kaka0020dAu[36], eratio_kaka0020dAu[36];
  float pT_kaka2040dAu[36], epT_kaka2040dAu[36], ratio_kaka2040dAu[36], eratio_kaka2040dAu[36];
  float pT_kaka4060dAu[36], epT_kaka4060dAu[36], ratio_kaka4060dAu[36], eratio_kaka4060dAu[36];
  float pT_kaka6088dAu[36], epT_kaka6088dAu[36], ratio_kaka6088dAu[36], eratio_kaka6088dAu[36];

  for(int i=0; i<36; i++)
    {
      fkaka0088dAu>>pT_kaka0088dAu[i]>>ratio_kaka0088dAu[i]>>eratio_kaka0088dAu[i];
      fkaka0020dAu>>pT_kaka0020dAu[i]>>ratio_kaka0020dAu[i]>>eratio_kaka0020dAu[i];
      fkaka2040dAu>>pT_kaka2040dAu[i]>>ratio_kaka2040dAu[i]>>eratio_kaka2040dAu[i];
      fkaka4060dAu>>pT_kaka4060dAu[i]>>ratio_kaka4060dAu[i]>>eratio_kaka4060dAu[i];
      fkaka6088dAu>>pT_kaka6088dAu[i]>>ratio_kaka6088dAu[i]>>eratio_kaka6088dAu[i];
      epT_kaka0088dAu[i] = 0;
      epT_kaka0020dAu[i] = 0;
      epT_kaka2040dAu[i] = 0;
      epT_kaka4060dAu[i] = 0;
      epT_kaka6088dAu[i] = 0;
      if(i<5||i>33) // check
	{ 
	  ratio_kaka0088dAu[i] = -9;
	  ratio_kaka0020dAu[i] = -9;
	  ratio_kaka2040dAu[i] = -9;
	  ratio_kaka4060dAu[i] = -9;
	  ratio_kaka6088dAu[i] = -9;
	  eratio_kaka0088dAu[i] = 0;
	  eratio_kaka0020dAu[i] = 0;
	  eratio_kaka2040dAu[i] = 0;
	  eratio_kaka4060dAu[i] = 0;
	  eratio_kaka6088dAu[i] = 0;
	}
    }
  fkaka0088dAu.close();
  fkaka0020dAu.close();
  fkaka2040dAu.close();
  fkaka4060dAu.close();
  fkaka6088dAu.close();



  int numberAu = 32;

  TGraphErrors *tge_kaka0010AuAu = new TGraphErrors(numberAu,pT_kaka0010AuAu,ratio_kaka0010AuAu,epT_kaka0010AuAu,eratio_kaka0010AuAu);
  tge_kaka0010AuAu->SetMarkerColor(kBlack);
  tge_kaka0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_kaka1020AuAu = new TGraphErrors(numberAu,pT_kaka1020AuAu,ratio_kaka1020AuAu,epT_kaka1020AuAu,eratio_kaka1020AuAu);
  tge_kaka1020AuAu->SetMarkerColor(kBlack);
  tge_kaka1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_kaka2040AuAu = new TGraphErrors(numberAu,pT_kaka2040AuAu,ratio_kaka2040AuAu,epT_kaka2040AuAu,eratio_kaka2040AuAu);
  tge_kaka2040AuAu->SetMarkerColor(kBlack);
  tge_kaka2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_kaka4060AuAu = new TGraphErrors(numberAu,pT_kaka4060AuAu,ratio_kaka4060AuAu,epT_kaka4060AuAu,eratio_kaka4060AuAu);
  tge_kaka4060AuAu->SetMarkerColor(kBlack);
  tge_kaka4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_kaka6092AuAu = new TGraphErrors(numberAu,pT_kaka6092AuAu,ratio_kaka6092AuAu,epT_kaka6092AuAu,eratio_kaka6092AuAu);
  tge_kaka6092AuAu->SetMarkerColor(kBlack);
  tge_kaka6092AuAu->SetMarkerStyle(kFullDiamond);

  int numberD = 31;

  TGraphErrors *tge_kaka0088dAu = new TGraphErrors(numberD,pT_kaka0088dAu,ratio_kaka0088dAu,epT_kaka0088dAu,eratio_kaka0088dAu);
  tge_kaka0088dAu->SetMarkerColor(kBlack);
  tge_kaka0088dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_kaka0020dAu = new TGraphErrors(numberD,pT_kaka0020dAu,ratio_kaka0020dAu,epT_kaka0020dAu,eratio_kaka0020dAu);
  tge_kaka0020dAu->SetMarkerColor(kBlack);
  tge_kaka0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_kaka2040dAu = new TGraphErrors(numberD,pT_kaka2040dAu,ratio_kaka2040dAu,epT_kaka2040dAu,eratio_kaka2040dAu);
  tge_kaka2040dAu->SetMarkerColor(kBlack);
  tge_kaka2040dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_kaka4060dAu = new TGraphErrors(numberD,pT_kaka4060dAu,ratio_kaka4060dAu,epT_kaka4060dAu,eratio_kaka4060dAu);
  tge_kaka4060dAu->SetMarkerColor(kBlack);
  tge_kaka4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_kaka6088dAu = new TGraphErrors(numberD,pT_kaka6088dAu,ratio_kaka6088dAu,epT_kaka6088dAu,eratio_kaka6088dAu);
  tge_kaka6088dAu->SetMarkerColor(kBlack);
  tge_kaka6088dAu->SetMarkerStyle(kOpenDiamond);

  TLine *line;// = new TLine(0.0,0.74,6.0,0.74);
  //TLine line(0.0,0.74,6.0,0.74);
  TLegend *leg;

  c1->cd(1);
  tge_kaka0010AuAu->Draw("apz");
  tge_kaka0010AuAu->SetMaximum(2.0);
  tge_kaka0010AuAu->SetMinimum(0.0);
  tge_kaka0010AuAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka0010AuAu,"Au+Au 0-10%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(3);
  tge_kaka1020AuAu->Draw("apz");
  tge_kaka1020AuAu->SetMaximum(2.0);
  tge_kaka1020AuAu->SetMinimum(0.0);
  tge_kaka1020AuAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka1020AuAu,"Au+Au 10-20%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(5);
  tge_kaka2040AuAu->Draw("apz");
  tge_kaka2040AuAu->SetMaximum(2.0);
  tge_kaka2040AuAu->SetMinimum(0.0);
  tge_kaka2040AuAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka2040AuAu,"Au+Au 20-40%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(7);
  tge_kaka4060AuAu->Draw("apz");
  tge_kaka4060AuAu->SetMaximum(2.0);
  tge_kaka4060AuAu->SetMinimum(0.0);
  tge_kaka4060AuAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka4060AuAu,"Au+Au 40-60%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(9);
  tge_kaka6092AuAu->Draw("apz");
  tge_kaka6092AuAu->SetMaximum(2.0);
  tge_kaka6092AuAu->SetMinimum(0.0);
  tge_kaka6092AuAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka6092AuAu,"Au+Au 60-92%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  // ---

  c1->cd(2);
  tge_kaka0020dAu->Draw("apz");
  tge_kaka0020dAu->SetMaximum(2.0);
  tge_kaka0020dAu->SetMinimum(0.0);
  tge_kaka0020dAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka0020dAu,"d+Au 0-20%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(4);
  tge_kaka2040dAu->Draw("apz");
  tge_kaka2040dAu->SetMaximum(2.0);
  tge_kaka2040dAu->SetMinimum(0.0);
  tge_kaka2040dAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka2040dAu,"d+Au 20-40%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(6);
  tge_kaka0088dAu->Draw("apz");
  tge_kaka0088dAu->SetMaximum(2.0);
  tge_kaka0088dAu->SetMinimum(0.0);
  tge_kaka0088dAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka0088dAu,"d+Au 0-88%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(8);
  tge_kaka4060dAu->Draw("apz");
  tge_kaka4060dAu->SetMaximum(2.0);
  tge_kaka4060dAu->SetMinimum(0.0);
  tge_kaka4060dAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka4060dAu,"d+Au 40-60%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  c1->cd(10);
  tge_kaka6088dAu->Draw("apz");
  tge_kaka6088dAu->SetMaximum(2.0);
  tge_kaka6088dAu->SetMinimum(0.0);
  tge_kaka6088dAu->GetXaxis()->SetLimits(0.0,6.0);
  leg = new TLegend(0.48,0.68,0.88,0.88);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_kaka6088dAu,"d+Au 60-88%","p");
  leg->Draw("same");
  line = new TLine(0.0,0.95,6.0,0.95);
  line->Draw("same");

  // ---





  c1->Print("figures/kaka.gif");
  c1->Print("figures/kaka.eps");




}
