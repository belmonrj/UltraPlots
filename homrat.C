TMultiGraph *tmg_pipiAuAu;
TMultiGraph *tmg_kakaAuAu;
TMultiGraph *tmg_pbarpAuAu;
TMultiGraph *tmg_pipidAu;
TMultiGraph *tmg_kakadAu;
TMultiGraph *tmg_pbarpdAu;

void homrat()
{

  doit("pipi",2,1);
  doit("kaka",4,3);
  doit("pbarp",8,5);

  doit3x2(tmg_pipiAuAu,tmg_kakaAuAu,tmg_pbarpAuAu,tmg_pipidAu,tmg_kakadAu,tmg_pbarpdAu);

}

void doit3x2(TMultiGraph *tmg_pipiAuAu,
	     TMultiGraph *tmg_kakaAuAu,
	     TMultiGraph *tmg_pbarpAuAu,
	     TMultiGraph *tmg_pipidAu,
	     TMultiGraph *tmg_kakadAu,
	     TMultiGraph *tmg_pbarpdAu)
{




  TCanvas *c1 = new TCanvas("c1","c1",1000,700);

  float left = 0.07;
  float bottom = 0.09;
  float width = 0.3;
  float height = 0.43;

  float xmin = 0.0;
  float xmax = 6.0;
  float ymin = 0.0;
  float ymax = 1.5;
  float labelsize = 0.07;
  float textsize = 0.065;
  int divisions = 510;


  TLine *line = new TLine(xmin,1.0,xmax,1.0);
  line->SetLineStyle(2);

  TLine *lineC = new TLine(xmin,1.0,xmax,1.0);
  lineC->SetLineColor(kGray);

  c1->cd();
  TPad *c1_1 = new TPad("c1_1","c1_1",left+0*width,bottom+1*height,left+1*width,bottom+2*height);
  c1_1->Draw();
  c1->cd();
  TPad *c1_2 = new TPad("c1_2","c1_2",left+1*width,bottom+1*height,left+2*width,bottom+2*height);
  c1_2->Draw();
  c1->cd();
  TPad *c1_3 = new TPad("c1_3","c1_3",left+2*width,bottom+1*height,left+3*width,bottom+2*height);
  c1_3->Draw();
  c1->cd();
  TPad *c1_4 = new TPad("c1_4","c1_4",left+0*width,bottom+0*height,left+1*width,bottom+1*height);
  c1_4->Draw();
  c1->cd();
  TPad *c1_5 = new TPad("c1_5","c1_5",left+1*width,bottom+0*height,left+2*width,bottom+1*height);
  c1_5->Draw();
  c1->cd();
  TPad *c1_6 = new TPad("c1_6","c1_6",left+2*width,bottom+0*height,left+3*width,bottom+1*height);
  c1_6->Draw();


  // --- now using TGaxis --- //
  // x1,  y1,x2, y2 are canvas coordinate is standard root convention
  // 0 is min, 3.0 is max, 510 is divisions, "" is no option
  c1->cd();
  float scale = 2.4;
  float titleoff = 1.1;
  //TGaxis *yaxis0 = new TGaxis(left,bottom+0*height,left,bottom+1*height,ymin,ymax,divisions,"");
  TGaxis *yaxis0 = new TGaxis(left,bottom+0*height,left,bottom+1*height,ymin,ymax-1e-4,divisions,"");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("R_{dA}");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(labelsize/scale);
  yaxis0->SetTitleSize(labelsize/scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->Draw();
  TGaxis *yaxis1 = new TGaxis(left,bottom+1*height,left,bottom+2*height,ymin,ymax,divisions,"");
  yaxis1->SetName("yaxis1");
  yaxis1->SetTitle("R_{dA}");
  yaxis1->CenterTitle();
  yaxis1->SetLabelSize(labelsize/scale);
  yaxis1->SetTitleSize(labelsize/scale);
  yaxis1->SetTitleOffset(titleoff);
  yaxis1->Draw();
  //TGaxis *xaxis0 = new TGaxis(left+0*width,bottom+0*height,left+1*width,bottom+0*height,xmin,xmax,divisions,"");
  TGaxis *xaxis0 = new TGaxis(left+0*width,bottom+0*height,left+1*width,bottom+0*height,xmin,xmax-1e-4,divisions,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(labelsize/scale);
  xaxis0->SetTitleSize(labelsize/scale);
  xaxis0->SetTitleOffset(titleoff);
  xaxis0->Draw();
  //TGaxis *xaxis1 = new TGaxis(left+1*width,bottom+0*height,left+2*width,bottom+0*height,xmin,xmax,divisions,"");
  TGaxis *xaxis1 = new TGaxis(left+1*width,bottom+0*height,left+2*width,bottom+0*height,xmin,xmax-1e-4,divisions,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(labelsize/scale);
  xaxis1->SetTitleSize(labelsize/scale);
  xaxis1->SetTitleOffset(titleoff);
  xaxis1->Draw();
  TGaxis *xaxis2 = new TGaxis(left+2*width,bottom+0*height,left+3*width,bottom+0*height,xmin,xmax,divisions,"");
  xaxis2->SetName("xaxis2");
  xaxis2->SetTitle("p_{T} (GeV/c)");
  xaxis2->CenterTitle();
  xaxis2->SetLabelSize(labelsize/scale);
  xaxis2->SetTitleSize(labelsize/scale);
  xaxis2->SetTitleOffset(titleoff);
  xaxis2->Draw();



  c1->cd();
  c1_1->cd();
  c1_1->SetTopMargin(0);
  c1_1->SetLeftMargin(0);
  c1_1->SetRightMargin(0);
  c1_1->SetBottomMargin(0);
  c1_1->SetTicks(1,1);
  tmg_pipiAuAu->Draw("apz");
  tmg_pipiAuAu->SetMaximum(ymax);
  tmg_pipiAuAu->SetMinimum(ymin);
  tmg_pipiAuAu->GetXaxis()->SetLimits(xmin,xmax);
  TLine *line1 = new TLine(xmin,1.0,xmax,1.0);
  line1->SetLineStyle(2);
  line1->Draw();

  c1->cd();
  c1_4->cd();
  c1_4->SetTopMargin(0);
  c1_4->SetLeftMargin(0);
  c1_4->SetRightMargin(0);
  c1_4->SetBottomMargin(0);
  c1_4->SetTicks(1,1);
  tmg_pipidAu->Draw("apz");
  tmg_pipidAu->SetMaximum(ymax);
  tmg_pipidAu->SetMinimum(ymin);
  tmg_pipidAu->GetXaxis()->SetLimits(xmin,xmax);
  line1->Draw();

  c1->cd();
  c1_2->cd();
  c1_2->SetTopMargin(0);
  c1_2->SetLeftMargin(0);
  c1_2->SetRightMargin(0);
  c1_2->SetBottomMargin(0);
  c1_2->SetTicks(1,1);
  tmg_kakaAuAu->Draw("apz");
  tmg_kakaAuAu->SetMaximum(ymax);
  tmg_kakaAuAu->SetMinimum(ymin);
  tmg_kakaAuAu->GetXaxis()->SetLimits(xmin,xmax);
  TLine *line2 = new TLine(xmin,0.93,xmax,0.93);
  line2->SetLineStyle(2);
  line2->Draw();
  lineC->Draw();

  c1->cd();
  c1_5->cd();
  c1_5->SetTopMargin(0);
  c1_5->SetLeftMargin(0);
  c1_5->SetRightMargin(0);
  c1_5->SetBottomMargin(0);
  c1_5->SetTicks(1,1);
  tmg_kakadAu->Draw("apz");
  tmg_kakadAu->SetMaximum(ymax);
  tmg_kakadAu->SetMinimum(ymin);
  tmg_kakadAu->GetXaxis()->SetLimits(xmin,xmax);
  line2->Draw();
  lineC->Draw();

  c1->cd();
  c1_3->cd();
  c1_3->SetTopMargin(0);
  c1_3->SetLeftMargin(0);
  c1_3->SetRightMargin(0);
  c1_3->SetBottomMargin(0);
  c1_3->SetTicks(1,1);
  tmg_pbarpAuAu->Draw("apz");
  tmg_pbarpAuAu->SetMaximum(ymax);
  tmg_pbarpAuAu->SetMinimum(ymin);
  tmg_pbarpAuAu->GetXaxis()->SetLimits(xmin,xmax);
  TLine *line3 = new TLine(xmin,0.74,xmax,0.74);
  line3->SetLineStyle(2);
  line3->Draw();
  lineC->Draw();

  c1->cd();
  c1_6->cd();
  c1_6->SetTopMargin(0);
  c1_6->SetLeftMargin(0);
  c1_6->SetRightMargin(0);
  c1_6->SetBottomMargin(0);
  c1_6->SetTicks(1,1);
  tmg_pbarpdAu->Draw("apz");
  tmg_pbarpdAu->SetMaximum(ymax);
  tmg_pbarpdAu->SetMinimum(ymin);
  tmg_pbarpdAu->GetXaxis()->SetLimits(xmin,xmax);
  line3->Draw();
  lineC->Draw();



  c1->cd();
  c1->Print("figures/homrat_X.gif");
  c1->Print("figures/homrat_X.eps");


}

void doit(char *handle="pipi", int r7pid=2, int r8pid=1)
{

  // float MAXY = 2.0;
  // if(r7pid>=6) MAXY = 1.5;
  float MAXY = 1.4;
  float MINY = 0.0;

  float MAXX = 6.0;
  float MINX = 0.0;

  float RVAL = 1.0;
  //if(r7pid==4||r7pid==5) RVAL = 0.95;
  if(r7pid==4||r7pid==5) RVAL = 0.93;
  if(r7pid>=6) RVAL = 0.73;


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

  char filename[100];
  sprintf(filename,"../Run7AuAu/Ratios/regular/%s_%d_cent0010.txt",handle,r7pid);
  ifstream fpipi0010AuAu(filename);
  sprintf(filename,"../Run7AuAu/Ratios/regular/%s_%d_cent1020.txt",handle,r7pid);
  ifstream fpipi1020AuAu(filename);
  sprintf(filename,"../Run7AuAu/Ratios/regular/%s_%d_cent2040.txt",handle,r7pid);
  ifstream fpipi2040AuAu(filename);
  sprintf(filename,"../Run7AuAu/Ratios/regular/%s_%d_cent4060.txt",handle,r7pid);
  ifstream fpipi4060AuAu(filename);
  sprintf(filename,"../Run7AuAu/Ratios/regular/%s_%d_cent6092.txt",handle,r7pid);
  ifstream fpipi6092AuAu(filename);

  float pT_pipi0010AuAu[44], epT_pipi0010AuAu[44], ratio_pipi0010AuAu[44], eratio_pipi0010AuAu[44], esysratio_pipi0010AuAu[44];
  float pT_pipi1020AuAu[44], epT_pipi1020AuAu[44], ratio_pipi1020AuAu[44], eratio_pipi1020AuAu[44], esysratio_pipi1020AuAu[44];
  float pT_pipi2040AuAu[44], epT_pipi2040AuAu[44], ratio_pipi2040AuAu[44], eratio_pipi2040AuAu[44], esysratio_pipi2040AuAu[44];
  float pT_pipi4060AuAu[44], epT_pipi4060AuAu[44], ratio_pipi4060AuAu[44], eratio_pipi4060AuAu[44], esysratio_pipi4060AuAu[44];
  float pT_pipi6092AuAu[44], epT_pipi6092AuAu[44], ratio_pipi6092AuAu[44], eratio_pipi6092AuAu[44], esysratio_pipi6092AuAu[44];

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
      esysratio_pipi0010AuAu[i] = 0.05*ratio_pipi0010AuAu[i];
      esysratio_pipi1020AuAu[i] = 0.05*ratio_pipi1020AuAu[i];
      esysratio_pipi2040AuAu[i] = 0.05*ratio_pipi2040AuAu[i];
      esysratio_pipi4060AuAu[i] = 0.05*ratio_pipi4060AuAu[i];
      esysratio_pipi6092AuAu[i] = 0.05*ratio_pipi6092AuAu[i];
    }
  fpipi0010AuAu.close();
  fpipi1020AuAu.close();
  fpipi2040AuAu.close();
  fpipi4060AuAu.close();
  fpipi6092AuAu.close();

  // --- now dAu --- //

  sprintf(filename,"../Run8dAu/Ratios/regular/%s_%d_cent0088.txt",handle,r8pid);
  ifstream fpipi0088dAu(filename);
  sprintf(filename,"../Run8dAu/Ratios/regular/%s_%d_cent0020.txt",handle,r8pid);
  ifstream fpipi0020dAu(filename);
  sprintf(filename,"../Run8dAu/Ratios/regular/%s_%d_cent2040.txt",handle,r8pid);
  ifstream fpipi2040dAu(filename);
  sprintf(filename,"../Run8dAu/Ratios/regular/%s_%d_cent4060.txt",handle,r8pid);
  ifstream fpipi4060dAu(filename);
  sprintf(filename,"../Run8dAu/Ratios/regular/%s_%d_cent6088.txt",handle,r8pid);
  ifstream fpipi6088dAu(filename);

  float pT_pipi0088dAu[36], epT_pipi0088dAu[36], ratio_pipi0088dAu[36], eratio_pipi0088dAu[36], esysratio_pipi0088dAu[36];
  float pT_pipi0020dAu[36], epT_pipi0020dAu[36], ratio_pipi0020dAu[36], eratio_pipi0020dAu[36], esysratio_pipi0020dAu[36];
  float pT_pipi2040dAu[36], epT_pipi2040dAu[36], ratio_pipi2040dAu[36], eratio_pipi2040dAu[36], esysratio_pipi2040dAu[36];
  float pT_pipi4060dAu[36], epT_pipi4060dAu[36], ratio_pipi4060dAu[36], eratio_pipi4060dAu[36], esysratio_pipi4060dAu[36];
  float pT_pipi6088dAu[36], epT_pipi6088dAu[36], ratio_pipi6088dAu[36], eratio_pipi6088dAu[36], esysratio_pipi6088dAu[36];

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
      esysratio_pipi0088dAu[i] = 0.05*ratio_pipi0088dAu[i];
      esysratio_pipi0020dAu[i] = 0.05*ratio_pipi0020dAu[i];
      esysratio_pipi2040dAu[i] = 0.05*ratio_pipi2040dAu[i];
      esysratio_pipi4060dAu[i] = 0.05*ratio_pipi4060dAu[i];
      esysratio_pipi6088dAu[i] = 0.05*ratio_pipi6088dAu[i];
    }
  fpipi0088dAu.close();
  fpipi0020dAu.close();
  fpipi2040dAu.close();
  fpipi4060dAu.close();
  fpipi6088dAu.close();

  int number7 = 31; // old binning would have been 36
  int number8 = 29; // old binning would have been 34
  //---
  TGraphErrors *tgeS_pipi0010AuAu = new TGraphErrors(number7,pT_pipi0010AuAu,ratio_pipi0010AuAu,epT_pipi0010AuAu,esysratio_pipi0010AuAu);
  TGraphErrors *tgeS_pipi1020AuAu = new TGraphErrors(number7,pT_pipi1020AuAu,ratio_pipi1020AuAu,epT_pipi1020AuAu,esysratio_pipi1020AuAu);
  TGraphErrors *tgeS_pipi2040AuAu = new TGraphErrors(number7,pT_pipi2040AuAu,ratio_pipi2040AuAu,epT_pipi2040AuAu,esysratio_pipi2040AuAu);
  TGraphErrors *tgeS_pipi4060AuAu = new TGraphErrors(number7,pT_pipi4060AuAu,ratio_pipi4060AuAu,epT_pipi4060AuAu,esysratio_pipi4060AuAu);
  TGraphErrors *tgeS_pipi6092AuAu = new TGraphErrors(number7,pT_pipi6092AuAu,ratio_pipi6092AuAu,epT_pipi6092AuAu,esysratio_pipi6092AuAu);
  TGraphErrors *tgeS_pipi0020dAu = new TGraphErrors(number8,pT_pipi0020dAu,ratio_pipi0020dAu,epT_pipi0020dAu,esysratio_pipi0020dAu);
  TGraphErrors *tgeS_pipi2040dAu = new TGraphErrors(number8,pT_pipi2040dAu,ratio_pipi2040dAu,epT_pipi2040dAu,esysratio_pipi2040dAu);
  TGraphErrors *tgeS_pipi0088dAu = new TGraphErrors(number8,pT_pipi0088dAu,ratio_pipi0088dAu,epT_pipi0088dAu,esysratio_pipi0088dAu);
  TGraphErrors *tgeS_pipi4060dAu = new TGraphErrors(number8,pT_pipi4060dAu,ratio_pipi4060dAu,epT_pipi4060dAu,esysratio_pipi4060dAu);
  TGraphErrors *tgeS_pipi6088dAu = new TGraphErrors(number8,pT_pipi6088dAu,ratio_pipi6088dAu,epT_pipi6088dAu,esysratio_pipi6088dAu);
  tgeS_pipi0010AuAu->SetMarkerColor(kGray);
  tgeS_pipi1020AuAu->SetMarkerColor(kGray);
  tgeS_pipi2040AuAu->SetMarkerColor(kGray);
  tgeS_pipi4060AuAu->SetMarkerColor(kGray);
  tgeS_pipi6092AuAu->SetMarkerColor(kGray);
  tgeS_pipi0020dAu->SetMarkerColor(kGray);
  tgeS_pipi2040dAu->SetMarkerColor(kGray);
  tgeS_pipi0088dAu->SetMarkerColor(kGray);
  tgeS_pipi4060dAu->SetMarkerColor(kGray);
  tgeS_pipi6088dAu->SetMarkerColor(kGray);
  tgeS_pipi0010AuAu->SetLineColor(kGray);
  tgeS_pipi1020AuAu->SetLineColor(kGray);
  tgeS_pipi2040AuAu->SetLineColor(kGray);
  tgeS_pipi4060AuAu->SetLineColor(kGray);
  tgeS_pipi6092AuAu->SetLineColor(kGray);
  tgeS_pipi0020dAu->SetLineColor(kGray);
  tgeS_pipi2040dAu->SetLineColor(kGray);
  tgeS_pipi0088dAu->SetLineColor(kGray);
  tgeS_pipi4060dAu->SetLineColor(kGray);
  tgeS_pipi6088dAu->SetLineColor(kGray);
  tgeS_pipi0010AuAu->SetLineWidth(15);
  tgeS_pipi1020AuAu->SetLineWidth(15);
  tgeS_pipi2040AuAu->SetLineWidth(15);
  tgeS_pipi4060AuAu->SetLineWidth(15);
  tgeS_pipi6092AuAu->SetLineWidth(15);
  tgeS_pipi0020dAu->SetLineWidth(15);
  tgeS_pipi2040dAu->SetLineWidth(15);
  tgeS_pipi0088dAu->SetLineWidth(15);
  tgeS_pipi4060dAu->SetLineWidth(15);
  tgeS_pipi6088dAu->SetLineWidth(15);


  // ---

  TGraphErrors *tge_pipi0010AuAu = new TGraphErrors(number7,pT_pipi0010AuAu,ratio_pipi0010AuAu,epT_pipi0010AuAu,eratio_pipi0010AuAu);
  tge_pipi0010AuAu->SetMarkerColor(kBlack);
  tge_pipi0010AuAu->SetMarkerStyle(kFullCircle);
  TGraphErrors *tge_pipi1020AuAu = new TGraphErrors(number7,pT_pipi1020AuAu,ratio_pipi1020AuAu,epT_pipi1020AuAu,eratio_pipi1020AuAu);
  tge_pipi1020AuAu->SetMarkerColor(kBlack);
  tge_pipi1020AuAu->SetMarkerStyle(kFullSquare);
  TGraphErrors *tge_pipi2040AuAu = new TGraphErrors(number7,pT_pipi2040AuAu,ratio_pipi2040AuAu,epT_pipi2040AuAu,eratio_pipi2040AuAu);
  tge_pipi2040AuAu->SetMarkerColor(kBlack);
  tge_pipi2040AuAu->SetMarkerStyle(kFullTriangleUp);
  TGraphErrors *tge_pipi4060AuAu = new TGraphErrors(number7,pT_pipi4060AuAu,ratio_pipi4060AuAu,epT_pipi4060AuAu,eratio_pipi4060AuAu);
  tge_pipi4060AuAu->SetMarkerColor(kBlack);
  tge_pipi4060AuAu->SetMarkerStyle(kFullTriangleDown);
  TGraphErrors *tge_pipi6092AuAu = new TGraphErrors(number7,pT_pipi6092AuAu,ratio_pipi6092AuAu,epT_pipi6092AuAu,eratio_pipi6092AuAu);
  tge_pipi6092AuAu->SetMarkerColor(kBlack);
  tge_pipi6092AuAu->SetMarkerStyle(kFullDiamond);

  TGraphErrors *tge_pipi0020dAu = new TGraphErrors(number8,pT_pipi0020dAu,ratio_pipi0020dAu,epT_pipi0020dAu,eratio_pipi0020dAu);
  tge_pipi0020dAu->SetMarkerColor(kBlack);
  tge_pipi0020dAu->SetMarkerStyle(kOpenCircle);
  TGraphErrors *tge_pipi2040dAu = new TGraphErrors(number8,pT_pipi2040dAu,ratio_pipi2040dAu,epT_pipi2040dAu,eratio_pipi2040dAu);
  tge_pipi2040dAu->SetMarkerColor(kBlack);
  tge_pipi2040dAu->SetMarkerStyle(kOpenSquare);
  TGraphErrors *tge_pipi0088dAu = new TGraphErrors(number8,pT_pipi0088dAu,ratio_pipi0088dAu,epT_pipi0088dAu,eratio_pipi0088dAu);
  tge_pipi0088dAu->SetMarkerColor(kBlack);
  tge_pipi0088dAu->SetMarkerStyle(kOpenTriangleUp);
  TGraphErrors *tge_pipi4060dAu = new TGraphErrors(number8,pT_pipi4060dAu,ratio_pipi4060dAu,epT_pipi4060dAu,eratio_pipi4060dAu);
  tge_pipi4060dAu->SetMarkerColor(kBlack);
  tge_pipi4060dAu->SetMarkerStyle(kOpenTriangleDown);
  TGraphErrors *tge_pipi6088dAu = new TGraphErrors(number8,pT_pipi6088dAu,ratio_pipi6088dAu,epT_pipi6088dAu,eratio_pipi6088dAu);
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
  TMultiGraph *tmg_pipi0010AuAu = new TMultiGraph();
  tmg_pipi0010AuAu->Add(tgeS_pipi0010AuAu);
  tmg_pipi0010AuAu->Add(tge_pipi0010AuAu);
  tmg_pipi0010AuAu->Draw("apz");
  //tmg_pipi0010AuAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi0010AuAu->SetMaximum(MAXY);
  tmg_pipi0010AuAu->SetMinimum(MINY);
  tmg_pipi0010AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tmg_pipi0010AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi0010AuAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi0010AuAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi0010AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0010AuAu,"Au+Au 0-10%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_3->cd();
  //  c1_3->Draw();
  c1_3->SetTopMargin(0);
  c1_3->SetBottomMargin(0);
  c1_3->SetRightMargin(0);
  TMultiGraph *tmg_pipi1020AuAu = new TMultiGraph();
  tmg_pipi1020AuAu->Add(tgeS_pipi1020AuAu);
  tmg_pipi1020AuAu->Add(tge_pipi1020AuAu);
  tmg_pipi1020AuAu->Draw("apz");
  //tmg_pipi1020AuAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi1020AuAu->SetMaximum(MAXY);
  tmg_pipi1020AuAu->SetMinimum(MINY);
  tmg_pipi1020AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tmg_pipi1020AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi1020AuAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi1020AuAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi1020AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi1020AuAu,"Au+Au 10-20%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_5->cd();
  //  c1_5->Draw();
  c1_5->SetTopMargin(0);
  c1_5->SetBottomMargin(0);
  c1_5->SetRightMargin(0);
  TMultiGraph *tmg_pipi2040AuAu = new TMultiGraph();
  tmg_pipi2040AuAu->Add(tgeS_pipi2040AuAu);
  tmg_pipi2040AuAu->Add(tge_pipi2040AuAu);
  tmg_pipi2040AuAu->Draw("apz");
  //tmg_pipi2040AuAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi2040AuAu->SetMaximum(MAXY);
  tmg_pipi2040AuAu->SetMinimum(MINY);
  tmg_pipi2040AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tmg_pipi2040AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi2040AuAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi2040AuAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi2040AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi2040AuAu,"Au+Au 20-40%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_7->cd();
  //  c1_7->Draw();
  c1_7->SetTopMargin(0);
  c1_7->SetBottomMargin(0);
  c1_7->SetRightMargin(0);
  TMultiGraph *tmg_pipi4060AuAu = new TMultiGraph();
  tmg_pipi4060AuAu->Add(tgeS_pipi4060AuAu);
  tmg_pipi4060AuAu->Add(tge_pipi4060AuAu);
  tmg_pipi4060AuAu->Draw("apz");
  //tmg_pipi4060AuAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi4060AuAu->SetMaximum(MAXY);
  tmg_pipi4060AuAu->SetMinimum(MINY);
  tmg_pipi4060AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tmg_pipi4060AuAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi4060AuAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi4060AuAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi4060AuAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi4060AuAu,"Au+Au 40-60%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_9->cd();
  //  c1_9->Draw();
  c1_9->SetTopMargin(0);
  c1_9->SetRightMargin(0);
  c1_9->SetBottomMargin(0); // NEW!
  TMultiGraph *tmg_pipi6092AuAu = new TMultiGraph();
  tmg_pipi6092AuAu->Add(tgeS_pipi6092AuAu);
  tmg_pipi6092AuAu->Add(tge_pipi6092AuAu);
  tmg_pipi6092AuAu->Draw("apz");
  //tmg_pipi6092AuAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi6092AuAu->SetMaximum(MAXY);
  tmg_pipi6092AuAu->SetMinimum(MINY);
  tmg_pipi6092AuAu->GetXaxis()->SetLimits(MINX,MAXX);
  tmg_pipi6092AuAu->GetYaxis()->SetLabelSize(labelsize);
  tmg_pipi6092AuAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi6092AuAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi6092AuAu->GetXaxis()->SetNdivisions(505);
  tmg_pipi6092AuAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pipi6092AuAu->GetXaxis()->SetTitleSize(0.15);
  tmg_pipi6092AuAu->GetXaxis()->CenterTitle();
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi6092AuAu,"Au+Au 60-92%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  // ---

  c1_2->cd();
  //  c1_2->Draw();
  c1_2->SetTopMargin(0); // NEW
  c1_2->SetBottomMargin(0);
  c1_2->SetLeftMargin(0);
  TMultiGraph *tmg_pipi0020dAu = new TMultiGraph();
  tmg_pipi0020dAu->Add(tgeS_pipi0020dAu);
  tmg_pipi0020dAu->Add(tge_pipi0020dAu);
  tmg_pipi0020dAu->Draw("apz");
  //tmg_pipi0020dAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi0020dAu->SetMaximum(MAXY);
  tmg_pipi0020dAu->SetMinimum(MINY);
  tmg_pipi0020dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tmg_pipi0020dAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi0020dAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi0020dAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi0020dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0020dAu,"d+Au 0-20%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_4->cd();
  //  c1_4->Draw();
  c1_4->SetTopMargin(0);
  c1_4->SetBottomMargin(0);
  c1_4->SetLeftMargin(0);
  TMultiGraph *tmg_pipi2040dAu = new TMultiGraph();
  tmg_pipi2040dAu->Add(tgeS_pipi2040dAu);
  tmg_pipi2040dAu->Add(tge_pipi2040dAu);
  tmg_pipi2040dAu->Draw("apz");
  //tmg_pipi2040dAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi2040dAu->SetMaximum(MAXY);
  tmg_pipi2040dAu->SetMinimum(MINY);
  tmg_pipi2040dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tmg_pipi2040dAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi2040dAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi2040dAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi2040dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi2040dAu,"d+Au 20-40%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_6->cd();
  //  c1_6->Draw();
  c1_6->SetTopMargin(0);
  c1_6->SetBottomMargin(0);
  c1_6->SetLeftMargin(0);
  TMultiGraph *tmg_pipi0088dAu = new TMultiGraph();
  tmg_pipi0088dAu->Add(tgeS_pipi0088dAu);
  tmg_pipi0088dAu->Add(tge_pipi0088dAu);
  tmg_pipi0088dAu->Draw("apz");
  //tmg_pipi0088dAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi0088dAu->SetMaximum(MAXY);
  tmg_pipi0088dAu->SetMinimum(MINY);
  tmg_pipi0088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tmg_pipi0088dAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi0088dAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi0088dAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi0088dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi0088dAu,"d+Au 0-88%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_8->cd();
  //  c1_8->Draw();
  c1_8->SetTopMargin(0);
  c1_8->SetBottomMargin(0);
  c1_8->SetLeftMargin(0);
  TMultiGraph *tmg_pipi4060dAu = new TMultiGraph();
  tmg_pipi4060dAu->Add(tgeS_pipi4060dAu);
  tmg_pipi4060dAu->Add(tge_pipi4060dAu);
  tmg_pipi4060dAu->Draw("apz");
  //tmg_pipi4060dAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi4060dAu->SetMaximum(MAXY);
  tmg_pipi4060dAu->SetMinimum(MINY);
  tmg_pipi4060dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tmg_pipi4060dAu->GetYaxis()->SetLabelSize(labelsize);
  //tmg_pipi4060dAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi4060dAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi4060dAu->GetXaxis()->SetNdivisions(505);
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi4060dAu,"d+Au 40-60%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  c1_10->cd();
  //  c1_10->Draw();
  c1_10->SetTopMargin(0);
  c1_10->SetLeftMargin(0);
  c1_10->SetBottomMargin(0); // NEW!
  TMultiGraph *tmg_pipi6088dAu = new TMultiGraph();
  tmg_pipi6088dAu->Add(tgeS_pipi6088dAu);
  tmg_pipi6088dAu->Add(tge_pipi6088dAu);
  tmg_pipi6088dAu->Draw("apz");
  //tmg_pipi6088dAu->Fit("pol0","","",MINX,MAXX);
  tmg_pipi6088dAu->SetMaximum(MAXY);
  tmg_pipi6088dAu->SetMinimum(MINY);
  tmg_pipi6088dAu->GetXaxis()->SetLimits(MINX,MAXX);
  //tmg_pipi6088dAu->GetYaxis()->SetLabelSize(labelsize);
  tmg_pipi6088dAu->GetXaxis()->SetLabelSize(labelsize);
  tmg_pipi6088dAu->GetYaxis()->SetNdivisions(505);
  //tmg_pipi6088dAu->GetXaxis()->SetNdivisions(505);
  tmg_pipi6088dAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmg_pipi6088dAu->GetXaxis()->SetTitleSize(0.15);
  tmg_pipi6088dAu->GetXaxis()->CenterTitle();
  leg = new TLegend(LX1,LY1,LX2,LY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(kWhite);
  leg->AddEntry(tge_pipi6088dAu,"d+Au 60-88%","p");
  leg->Draw("same");
  leg->SetTextSize(legtextsize);
  line = new TLine(MINX,RVAL,MAXX,RVAL);
  line->SetLineStyle(2);
  line->Draw("same");

  // ---



  char figname[100];
  // sprintf(figname,"figures/%s_X.gif",handle);
  // c1->Print(figname);
  // sprintf(figname,"figures/%s_X.eps",handle);
  // c1->Print(figname);



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



  //TCanvas *c2 = new TCanvas("c2","",1200,500);
  TCanvas *c2 = new TCanvas("c2","",1200,600);

  c2->cd();
  TPad *c2_1 = new TPad("c2_1","c2_1",0.0,0.0,0.5,1.0);
  c2_1->Draw();
  c2->cd();
  TPad *c2_2 = new TPad("c2_2","c2_2",0.5,0.0,1.0,1.0);
  c2_2->Draw();
  c2->cd();

  TLine *lineC = new TLine(0.0,1.0,6.0,1.0);
  lineC->SetLineStyle(3);

  // COME BACK HERE TO INSERT TGAXIS STUFF

  float size = 0.05; // very, very close to previous settings before using TGaxis...
  float scale = 1.0;
  float titleoff = 0.7;

  TGaxis *yaxis0 = new TGaxis(0.075,0.15,0.075,0.95,0.0,1.4,510,"S");
  yaxis0->SetName("yaxis0");
  yaxis0->SetTitle("Ratio");
  yaxis0->CenterTitle();
  yaxis0->SetLabelSize(size*scale);
  yaxis0->SetTitleSize(size*scale);
  yaxis0->SetTitleOffset(titleoff);
  yaxis0->SetTickSize(0.01);
  yaxis0->Draw();

  TGaxis *xaxis0 = new TGaxis(0.075,0.15,0.5,0.15,0.0,5.9999,510,"");
  xaxis0->SetName("xaxis0");
  xaxis0->SetTitle("p_{T} (GeV/c)");
  xaxis0->CenterTitle();
  xaxis0->SetLabelSize(size*scale);
  xaxis0->SetTitleSize(size*scale);
  xaxis0->SetTitleOffset(1.1);
  xaxis0->Draw();

  TGaxis *xaxis1 = new TGaxis(0.5,0.15,0.925,0.15,0.0,6.0,510,"");
  xaxis1->SetName("xaxis1");
  xaxis1->SetTitle("p_{T} (GeV/c)");
  xaxis1->CenterTitle();
  xaxis1->SetLabelSize(size*scale);
  xaxis1->SetTitleSize(size*scale);
  xaxis1->SetTitleOffset(1.1);
  xaxis1->Draw();


  c2_1->cd();
  c2_1->SetRightMargin(0);
  c2_1->SetTopMargin(0.05);
  c2_1->SetLeftMargin(0.15);
  c2_1->SetBottomMargin(0.15);
  c2_1->SetTicks(1,1);
  TMultiGraph *tmgAuAu = new TMultiGraph();
  tmgAuAu->Add(tgeS_pipi0010AuAu);
  tmgAuAu->Add(tgeS_pipi1020AuAu);
  tmgAuAu->Add(tgeS_pipi2040AuAu);
  tmgAuAu->Add(tgeS_pipi4060AuAu);
  tmgAuAu->Add(tgeS_pipi6092AuAu);
  tmgAuAu->Add(tge2_pipi0010AuAu);
  tmgAuAu->Add(tge2_pipi1020AuAu);
  tmgAuAu->Add(tge2_pipi2040AuAu);
  tmgAuAu->Add(tge2_pipi4060AuAu);
  tmgAuAu->Add(tge2_pipi6092AuAu);
  tmgAuAu->Draw("apz");
  line->Draw("same");
  lineC->Draw();
  tmgAuAu->SetMaximum(MAXY);
  tmgAuAu->SetMinimum(0.0);
  tmgAuAu->GetXaxis()->SetLimits(0.0,6.0);
  tmgAuAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgAuAu->GetXaxis()->CenterTitle();
  tmgAuAu->GetYaxis()->SetTitle("Ratio");
  tmgAuAu->GetYaxis()->CenterTitle();
  tmgAuAu->GetYaxis()->SetTitleOffset(1.3);
  tmgAuAu->GetYaxis()->SetTitleSize(0.0);
  tmgAuAu->GetYaxis()->SetLabelSize(0.0);
  tmgAuAu->GetXaxis()->SetTitleSize(0.0);
  tmgAuAu->GetXaxis()->SetLabelSize(0.0);
  // tmgAuAu->GetYaxis()->SetTitleSize(0.05);
  // tmgAuAu->GetYaxis()->SetLabelSize(0.05);
  // tmgAuAu->GetXaxis()->SetTitleSize(0.05);
  // tmgAuAu->GetXaxis()->SetLabelSize(0.05);
  TLatex *tlauau = new TLatex(0.3,0.9*MAXY,"Au+Au #sqrt{s_{NN}}=200 GeV");
  tlauau->SetTextSize(0.05);
  tlauau->Draw();
  char rationame[100];
  if(r7pid<=3) sprintf(rationame,"#pi^{-}/#pi^{+}");
  else if(r7pid<=5) sprintf(rationame,"K^{-}/K^{+}");
  else if(r7pid>=6) sprintf(rationame,"#bar{p}/p");
  //cout<<rationame<<endl;
  //TLatex *tlratio = new TLatex(4.0,0.15,rationame);
  TLatex *tlratio = new TLatex(3.0,0.3,rationame);
  tlratio->SetTextSize(0.075);
  tlratio->Draw();
  //TLegend *legauau = new TLegend(0.2,0.2,0.4,0.4);
  TLegend *legauau = new TLegend(0.24,0.2,0.53,0.47);
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
  c2_2->SetRightMargin(0.15);
  c2_2->SetBottomMargin(0.15);
  c2_2->SetTicks(1,1);
  TMultiGraph *tmgdAu = new TMultiGraph();
  tmgdAu->Add(tgeS_pipi0020dAu);
  tmgdAu->Add(tgeS_pipi2040dAu);
  tmgdAu->Add(tgeS_pipi0088dAu);
  tmgdAu->Add(tgeS_pipi4060dAu);
  tmgdAu->Add(tgeS_pipi6088dAu);
  tmgdAu->Add(tge2_pipi0020dAu);
  tmgdAu->Add(tge2_pipi2040dAu);
  tmgdAu->Add(tge2_pipi0088dAu);
  tmgdAu->Add(tge2_pipi4060dAu);
  tmgdAu->Add(tge2_pipi6088dAu);
  tmgdAu->Draw("apz");
  line->Draw("same");
  lineC->Draw();
  tmgdAu->SetMaximum(MAXY);
  tmgdAu->SetMinimum(0.0);
  tmgdAu->GetXaxis()->SetLimits(0.0,6.0);
  tmgdAu->GetXaxis()->SetTitle("p_{T} (GeV/c)");
  tmgdAu->GetXaxis()->CenterTitle();
  tmgdAu->GetYaxis()->SetLabelSize(0);
  tmgdAu->GetXaxis()->SetTitleSize(0.0);
  tmgdAu->GetXaxis()->SetLabelSize(0.0);
  // tmgdAu->GetXaxis()->SetTitleSize(0.05);
  // tmgdAu->GetXaxis()->SetLabelSize(0.05);
  TLatex *tldau = new TLatex(0.3,0.9*MAXY,"d+Au #sqrt{s_{NN}}=200 GeV");
  tldau->SetTextSize(0.05);
  tldau->Draw();
  // char rationame[100];
  // if(r7pid<=3) sprintf(rationame,"#pi^{-}/#pi^{+}");
  // else if(r7pid<=5) sprintf(rationame,"K^{-}/K^{+}");
  // else if(r7pid>=6) sprintf(rationame,"#bar{p}/p");
  // cout<<rationame<<endl;
  //TLatex *tlratio = new TLatex(4.0,0.15,rationame);
  //TLatex *tlratio = new TLatex(4.0,0.15,rationame);
  //tlratio->SetTextSize(0.075);
  tlratio->Draw();
  //TLegend *legdau = new TLegend(0.2,0.2,0.4,0.4);
  //TLegend *legdau = new TLegend(0.08,0.2,0.38,0.4); // panel is expanded to left by 0.1
  TLegend *legdau = new TLegend(0.08,0.2,0.41,0.47); // panel is expanded to left by 0.1
  legdau->SetBorderSize(0);
  legdau->SetFillColor(kWhite);
  legdau->AddEntry(tge2_pipi0020dAu,"0-20%","p");
  legdau->AddEntry(tge2_pipi2040dAu,"20-40%","p");
  //legdau->AddEntry(tge2_pipi0088dAu,"min. bias","p");
  legdau->AddEntry(tge2_pipi0088dAu,"0-100%","p");
  legdau->AddEntry(tge2_pipi4060dAu,"40-60%","p");
  legdau->AddEntry(tge2_pipi6088dAu,"60-88%","p"); 
  legdau->SetTextSize(0.05);
  legdau->Draw();


  sprintf(figname,"figures/%s_X_new.gif",handle);
  c2->Print(figname);
  sprintf(figname,"figures/%s_X_new.eps",handle);
  c2->Print(figname);


  c2->Clear();
  delete c2;


  if(r7pid<=3)      {tmg_pipiAuAu = (TMultiGraph *)tmgAuAu->Clone(); tmg_pipidAu = (TMultiGraph *)tmgdAu->Clone(); }
  else if(r7pid>=6) {tmg_pbarpAuAu = (TMultiGraph *)tmgAuAu->Clone();tmg_pbarpdAu = (TMultiGraph *)tmgdAu->Clone();}
  else              {tmg_kakaAuAu = (TMultiGraph *)tmgAuAu->Clone(); tmg_kakadAu = (TMultiGraph *)tmgdAu->Clone(); }


}
