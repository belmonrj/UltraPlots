void pipi()
{

  float MAXY = 2.0;
  float MINY = 0.0;

  float MAXX = 6.0;
  float MINX = 0.0;

  float RVAL = 1.0;

  float LX1=0.18;
  float LY1=0.68;
  float LX2=0.48; // just exp...
  float LY2=0.88;
  float legtextsize = 0.15;
  float labelsize = 0.15;

  gStyle->SetOptFit(0); // boxes don't show up in the right place and the text is too small

  TCanvas *c1 = new TCanvas("c1","",950,700);
  //c1->Divide(2,5);
  c1->cd();
  float mult = 0.85;
  float offs = (1.0-mult)/2.0;

  TPad *c1_TOP = new TPad("c1_TOP","c1_TOP",0.00,1.00-offs,1.00,1.00);
  c1_TOP->Draw();
  c1->cd();
  TPad *c1_BOT = new TPad("c1_BOT","c1_BOT",0.00,0.00,1.00,0.00+offs);
  c1_BOT->Draw();
  c1->cd();

  // cout<<1.0*mult+offs<<endl;
  // return;

  TPad *c1_1 = new TPad("c1_1","c1_1",0.0,0.8*mult+offs,0.5,1.0*mult+offs);
  c1_1->Draw();
  c1->cd();
  TPad *c1_3 = new TPad("c1_3","c1_3",0.0,0.6*mult+offs,0.5,0.8*mult+offs);
  c1_3->Draw();				               
  c1->cd();				               
  TPad *c1_5 = new TPad("c1_5","c1_5",0.0,0.4*mult+offs,0.5,0.6*mult+offs);
  c1_5->Draw();				               
  c1->cd();				               
  TPad *c1_7 = new TPad("c1_7","c1_7",0.0,0.2*mult+offs,0.5,0.4*mult+offs);
  c1_7->Draw();				               
  c1->cd();				               
  TPad *c1_9 = new TPad("c1_9","c1_9",0.0,0.0*mult+offs,0.5,0.2*mult+offs);
  c1_9->Draw();
  c1->cd();

  TPad *c1_2  = new TPad("c1_2",  "c1_2",0.5,0.8*mult+offs,1.0,1.0*mult+offs);
  c1_2->Draw();					          	          
  c1->cd();					          	          
  TPad *c1_4  = new TPad("c1_4",  "c1_4",0.5,0.6*mult+offs,1.0,0.8*mult+offs);
  c1_4->Draw();					          	          
  c1->cd();					          	          
  TPad *c1_6  = new TPad("c1_6",  "c1_6",0.5,0.4*mult+offs,1.0,0.6*mult+offs);
  c1_6->Draw();					          	          
  c1->cd();					          	          
  TPad *c1_8  = new TPad("c1_8",  "c1_8",0.5,0.2*mult+offs,1.0,0.4*mult+offs);
  c1_8->Draw();					          	          
  c1->cd();					          	          
  TPad *c1_10 = new TPad("c1_10","c1_10",0.5,0.0*mult+offs,1.0,0.2*mult+offs);
  c1_10->Draw();
  c1->cd();



  c1_1->SetTicks(1,1);
  c1_2->SetTicks(1,1);
  c1_3->SetTicks(1,1);
  c1_4->SetTicks(1,1);
  c1_5->SetTicks(1,1);
  c1_6->SetTicks(1,1);
  c1_7->SetTicks(1,1);
  c1_8->SetTicks(1,1);
  c1_9->SetTicks(1,1);
  c1_10->SetTicks(1,1);




  // --- now AuAu --- //

  // ifstream fpipi0010AuAu("../Run7AuAu/Ratios/regular/pipi_0_cent0010.txt");
  // ifstream fpipi1020AuAu("../Run7AuAu/Ratios/regular/pipi_0_cent1020.txt");
  // ifstream fpipi2040AuAu("../Run7AuAu/Ratios/regular/pipi_0_cent2040.txt");
  // ifstream fpipi4060AuAu("../Run7AuAu/Ratios/regular/pipi_0_cent4060.txt");
  // ifstream fpipi6092AuAu("../Run7AuAu/Ratios/regular/pipi_0_cent6092.txt");
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

  TGraphErrors *tge_pipi0020dAu = new TGraphErrors(36,pT_pipi0020dAu,ratio_pipi0020dAu,epT_pipi0020dAu,eratio_pipi0020dAu);
  tge_pipi0020dAu->SetMarkerColor(kBlack);
  tge_pipi0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_pipi2040dAu = new TGraphErrors(36,pT_pipi2040dAu,ratio_pipi2040dAu,epT_pipi2040dAu,eratio_pipi2040dAu);
  tge_pipi2040dAu->SetMarkerColor(kBlack);
  tge_pipi2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_pipi0088dAu = new TGraphErrors(36,pT_pipi0088dAu,ratio_pipi0088dAu,epT_pipi0088dAu,eratio_pipi0088dAu);
  tge_pipi0088dAu->SetMarkerColor(kBlack);
  tge_pipi0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_pipi4060dAu = new TGraphErrors(36,pT_pipi4060dAu,ratio_pipi4060dAu,epT_pipi4060dAu,eratio_pipi4060dAu);
  tge_pipi4060dAu->SetMarkerColor(kBlack);
  tge_pipi4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_pipi6088dAu = new TGraphErrors(36,pT_pipi6088dAu,ratio_pipi6088dAu,epT_pipi6088dAu,eratio_pipi6088dAu);
  tge_pipi6088dAu->SetMarkerColor(kBlack);
  tge_pipi6088dAu->SetMarkerStyle(kOpenDiamond);

  TGraphErrors *tge2_pipi0010AuAu = (TGraphErrors *)tge_pipi0010AuAu->Clone();
  TGraphErrors *tge2_pipi1020AuAu = (TGraphErrors *)tge_pipi1020AuAu->Clone();
  TGraphErrors *tge2_pipi2040AuAu = (TGraphErrors *)tge_pipi2040AuAu->Clone();
  TGraphErrors *tge2_pipi4060AuAu = (TGraphErrors *)tge_pipi4060AuAu->Clone();
  TGraphErrors *tge2_pipi6092AuAu = (TGraphErrors *)tge_pipi6092AuAu->Clone();

  TGraphErrors *tge2_pipi0020dAu = (TGraphErrors *)tge_pipi0020dAu->Clone();
  TGraphErrors *tge2_pipi2040dAu = (TGraphErrors *)tge_pipi2040dAu->Clone();
  TGraphErrors *tge2_pipi0088dAu = (TGraphErrors *)tge_pipi0088dAu->Clone();
  TGraphErrors *tge2_pipi4060dAu = (TGraphErrors *)tge_pipi4060dAu->Clone();
  TGraphErrors *tge2_pipi6088dAu = (TGraphErrors *)tge_pipi6088dAu->Clone();


  TLine *line;// = new TLine(MINX,RVAL,MAXX,RVAL);
  //TLine line(MINX,RVAL,MAXX,RVAL);
  TLegend *leg;

  c1_1->cd();
  //  c1_1->Draw();
  c1_1->SetTopMargin(0); // NEW
  c1_1->SetBottomMargin(0);
  c1_1->SetRightMargin(0);
  tge_pipi0010AuAu->Draw("apz");
  tge_pipi0010AuAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi0010AuAu->SetMaximum(MAXY);
  tge_pipi0010AuAu->SetMinimum(MINY);
  tge_pipi0010AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi0010AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi0010AuAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi0010AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi0010AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0010AuAu,"Au+Au 0-10%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_3->cd();
  //  c1_3->Draw();
  c1_3->SetTopMargin(0);
  c1_3->SetBottomMargin(0);
  c1_3->SetRightMargin(0);
  tge_pipi1020AuAu->Draw("apz");
  tge_pipi1020AuAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi1020AuAu->SetMaximum(MAXY);
  tge_pipi1020AuAu->SetMinimum(MINY);
  tge_pipi1020AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi1020AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi1020AuAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi1020AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi1020AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi1020AuAu,"Au+Au 10-20%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_5->cd();
  //  c1_5->Draw();
  c1_5->SetTopMargin(0);
  c1_5->SetBottomMargin(0);
  c1_5->SetRightMargin(0);
  tge_pipi2040AuAu->Draw("apz");
  tge_pipi2040AuAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi2040AuAu->SetMaximum(MAXY);
  tge_pipi2040AuAu->SetMinimum(MINY);
  tge_pipi2040AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi2040AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi2040AuAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi2040AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi2040AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi2040AuAu,"Au+Au 20-40%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_7->cd();
  //  c1_7->Draw();
  c1_7->SetTopMargin(0);
  c1_7->SetBottomMargin(0);
  c1_7->SetRightMargin(0);
  tge_pipi4060AuAu->Draw("apz");
  tge_pipi4060AuAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi4060AuAu->SetMaximum(MAXY);
  tge_pipi4060AuAu->SetMinimum(MINY);
  tge_pipi4060AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi4060AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi4060AuAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi4060AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi4060AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi4060AuAu,"Au+Au 40-60%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_9->cd();
  //  c1_9->Draw();
  c1_9->SetTopMargin(0);
  c1_9->SetRightMargin(0);
  c1_9->SetBottomMargin(0); // NEW!
  tge_pipi6092AuAu->Draw("apz");
  tge_pipi6092AuAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi6092AuAu->SetMaximum(MAXY);
  tge_pipi6092AuAu->SetMinimum(MINY);
  tge_pipi6092AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tge_pipi6092AuAu->GetYaxis()->SetLabelSize(labelsize);
  tge_pipi6092AuAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi6092AuAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi6092AuAu->GetXaxis()->SetNdivisions(505);
  tge_pipi6092AuAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_pipi6092AuAu->GetXaxis()->SetTitleSize(0.15);
  tge_pipi6092AuAu->GetXaxis()->CenterTitle();
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi6092AuAu,"Au+Au 60-92%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  // ---

  c1_2->cd();
  //  c1_2->Draw();
  c1_2->SetTopMargin(0); // NEW
  c1_2->SetBottomMargin(0);
  c1_2->SetLeftMargin(0);
  tge_pipi0020dAu->Draw("apz");
  tge_pipi0020dAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi0020dAu->SetMaximum(MAXY);
  tge_pipi0020dAu->SetMinimum(MINY);
  tge_pipi0020dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tge_pipi0020dAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi0020dAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi0020dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi0020dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0020dAu,"d+Au 0-20%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_4->cd();
  //  c1_4->Draw();
  c1_4->SetTopMargin(0);
  c1_4->SetBottomMargin(0);
  c1_4->SetLeftMargin(0);
  tge_pipi2040dAu->Draw("apz");
  tge_pipi2040dAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi2040dAu->SetMaximum(MAXY);
  tge_pipi2040dAu->SetMinimum(MINY);
  tge_pipi2040dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tge_pipi2040dAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi2040dAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi2040dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi2040dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi2040dAu,"d+Au 20-40%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_6->cd();
  //  c1_6->Draw();
  c1_6->SetTopMargin(0);
  c1_6->SetBottomMargin(0);
  c1_6->SetLeftMargin(0);
  tge_pipi0088dAu->Draw("apz");
  tge_pipi0088dAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi0088dAu->SetMaximum(MAXY);
  tge_pipi0088dAu->SetMinimum(MINY);
  tge_pipi0088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tge_pipi0088dAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi0088dAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi0088dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi0088dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0088dAu,"d+Au 0-88%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_8->cd();
  //  c1_8->Draw();
  c1_8->SetTopMargin(0);
  c1_8->SetBottomMargin(0);
  c1_8->SetLeftMargin(0);
  tge_pipi4060dAu->Draw("apz");
  tge_pipi4060dAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi4060dAu->SetMaximum(MAXY);
  tge_pipi4060dAu->SetMinimum(MINY);
  tge_pipi4060dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tge_pipi4060dAu->GetYaxis()->SetLabelSize(labelsize);
  //tge_pipi4060dAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi4060dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi4060dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi4060dAu,"d+Au 40-60%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  c1_10->cd();
  //  c1_10->Draw();
  c1_10->SetTopMargin(0);
  c1_10->SetLeftMargin(0);
  c1_10->SetBottomMargin(0); // NEW!
  tge_pipi6088dAu->Draw("apz");
  tge_pipi6088dAu->Fit("pol0","","",MINX,MAXX);
  tge_pipi6088dAu->SetMaximum(MAXY);
  tge_pipi6088dAu->SetMinimum(MINY);
  tge_pipi6088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tge_pipi6088dAu->GetYaxis()->SetLabelSize(labelsize);
  tge_pipi6088dAu->GetXaxis()->SetLabelSize(labelsize);
  tge_pipi6088dAu->GetYaxis()->SetNdivisions(505);
  //tge_pipi6088dAu->GetXaxis()->SetNdivisions(505);
  tge_pipi6088dAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tge_pipi6088dAu->GetXaxis()->SetTitleSize(0.15);
  tge_pipi6088dAu->GetXaxis()->CenterTitle();
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi6088dAu,"d+Au 60-88%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->Draw("same");

  // ---



  c1->Print("figures/pipi.gif");
  c1->Print("figures/pipi.eps");



  c1->Clear();
  delete c1;



  tge2_pipi0010AuAu->SetMarkerColor(kBlack);    
  tge2_pipi1020AuAu->SetMarkerColor(kRed);      
  tge2_pipi2040AuAu->SetMarkerColor(kBlue);     
  tge2_pipi4060AuAu->SetMarkerColor(kGreen+2);  
  tge2_pipi6092AuAu->SetMarkerColor(kMagenta+2);

  tge2_pipi0020dAu->SetMarkerColor(kBlack);    
  tge2_pipi2040dAu->SetMarkerColor(kRed);      
  tge2_pipi0088dAu->SetMarkerColor(kBlue);     
  tge2_pipi4060dAu->SetMarkerColor(kGreen+2);  
  tge2_pipi6088dAu->SetMarkerColor(kMagenta+2);



  TCanvas *c2 = new TCanvas("c2","",1200,500);

  c2->cd();
  TPad *c2_1 = new TPad("c2_1","c2_1",0.0,0.0,0.5,1.0);
  c2_1->Draw();
  c2->cd();
  TPad *c2_2 = new TPad("c2_2","c2_2",0.5,0.0,1.0,1.0);
  c2_2->Draw();
  c2->cd();

  c2_1->cd();
  c2_1->SetRightMargin(0);
  c2_1->SetTopMargin(0.05);
  c2_1->SetTicks(1,1);
  TMultiGraph *tmgAuAu = new TMultiGraph();
  tmgAuAu->Add(tge2_pipi0010AuAu);
  tmgAuAu->Add(tge2_pipi1020AuAu);
  tmgAuAu->Add(tge2_pipi2040AuAu);
  tmgAuAu->Add(tge2_pipi4060AuAu);
  tmgAuAu->Add(tge2_pipi6092AuAu);
  tmgAuAu->Draw("apz");
  line->Draw("same");
  tmgAuAu->SetMaximum(2.0);
  tmgAuAu->SetMinimum(0.0);
  tmgAuAu->GetXaxis()->SetLimits(0.0,6.0);
  tmgAuAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgAuAu->GetXaxis()->CenterTitle();
  tmgAuAu->GetYaxis()->SetTitle("Ratio #pi^{-}/#pi^{+}");
  tmgAuAu->GetYaxis()->CenterTitle();
  tmgAuAu->GetYaxis()->SetTitleOffset(1.1);
  tmgAuAu->GetYaxis()->SetTitleSize(0.04);
  tmgAuAu->GetYaxis()->SetLabelSize(0.04);
  tmgAuAu->GetXaxis()->SetTitleSize(0.04);
  tmgAuAu->GetXaxis()->SetLabelSize(0.04);
  TLatex *tlauau = new TLatex(0.3,1.8,"Au+Au #sqrt{s_{NN}}=200 GeV");
  tlauau->SetTextSize(0.05);
  tlauau->Draw();
  TLegend *legauau = new TLegend(0.2,0.2,0.4,0.4);
  legauau->SetBorderSize(0);
  legauau->SetFillColor(kWhite);
  legauau->AddEntry(tge2_pipi0010AuAu,"0-10%","p");
  legauau->AddEntry(tge2_pipi1020AuAu,"10-20%","p");
  legauau->AddEntry(tge2_pipi2040AuAu,"20-40%","p");
  legauau->AddEntry(tge2_pipi4060AuAu,"40-60%","p");
  legauau->AddEntry(tge2_pipi6092AuAu,"60-92%","p");
  legauau->SetTextSize(0.05);
  legauau->Draw();

  c2_2->cd();
  c2_2->SetLeftMargin(0);
  c2_2->SetTopMargin(0.05);
  c2_2->SetTicks(1,1);
  TMultiGraph *tmgdAu = new TMultiGraph();
  tmgdAu->Add(tge2_pipi0020dAu);
  tmgdAu->Add(tge2_pipi2040dAu);
  tmgdAu->Add(tge2_pipi0088dAu);
  tmgdAu->Add(tge2_pipi4060dAu);
  tmgdAu->Add(tge2_pipi6088dAu);
  tmgdAu->Draw("apz");
  line->Draw("same");
  tmgdAu->SetMaximum(2.0);
  tmgdAu->SetMinimum(0.0);
  tmgdAu->GetXaxis()->SetLimits(0.0,6.0);
  tmgdAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgdAu->GetXaxis()->CenterTitle();
  tmgdAu->GetYaxis()->SetLabelSize(0);
  tmgdAu->GetXaxis()->SetTitleSize(0.04);
  tmgdAu->GetXaxis()->SetLabelSize(0.04);
  TLatex *tldau = new TLatex(0.3,1.8,"d+Au #sqrt{s_{NN}}=200 GeV");
  tldau->SetTextSize(0.05);
  tldau->Draw();
  //TLegend *legdau = new TLegend(0.2,0.2,0.4,0.4);
  TLegend *legdau = new TLegend(0.08,0.2,0.38,0.4); // panel is expanded to left by 0.1
  legdau->SetBorderSize(0);
  legdau->SetFillColor(kWhite);
  legdau->AddEntry(tge2_pipi0020dAu,"0-20%","p");
  legdau->AddEntry(tge2_pipi2040dAu,"20-40%","p");
  legdau->AddEntry(tge2_pipi0088dAu,"MinBias","p");
  legdau->AddEntry(tge2_pipi4060dAu,"40-60%","p");
  legdau->AddEntry(tge2_pipi6088dAu,"60-92%","p"); 
  legdau->SetTextSize(0.05);
  legdau->Draw();

  c2->Print("figures/pipi_new.gif");
  c2->Print("figures/pipi_new.eps");



}
