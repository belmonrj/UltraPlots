void calcratnew()
{

  const int number = 16;

  float pt[number], ept[number],
    ppg044[number], eppg044[number], esysppg044[number],
    ppg080[number], eppg080[number], esysppg080[number],
    ratio[number], eratio[number], esysratio[number];

  ifstream f044("ppg044_x_cent0020.dat");
  ifstream f080("ppg080_cent6092.dat");

  ofstream fout("pi0_aud_ratio.dat");
  for(int i=0; i<number; i++)
    {
      pt[i] = i/2.0+1.25;
      if(i>17)pt[i]=(float)i*2-25;
      float tmp;
      f044>>tmp>>ppg044[i]>>eppg044[i]>>esysppg044[i];
      if(fabs(pt[i]-tmp)>0.01){cout<<"pt trouble ppg044 "<<pt[i]<<endl;}//break;}
      f080>>tmp>>ppg080[i]>>eppg080[i]>>esysppg080[i];
      if(fabs(pt[i]-tmp)>0.01){cout<<"pt trouble ppg080 "<<i<<" "<<tmp<<" "<<pt[i]<<endl;}//break;}
      ept[i] = 0;
      ratio[i] = ppg080[i]/ppg044[i];
      eratio[i] = ratio[i]*sqrt((eppg080[i]/ppg080[i])**2+(eppg044[i]/ppg044[i])**2);
      esysratio[i] = ratio[i]*sqrt((esysppg080[i]/ppg080[i])**2+(esysppg044[i]/ppg044[i])**2);
      ratio[i] *= (14.5/15.1); // Run2,4 over Run3
      fout<<pt[i]<<"\t"<<ratio[i]<<"\t"<<eratio[i]<<"\t"<<esysratio[i]/*<<"\t"<<ratio[i]<<"\t"<<eratio[i]*/<<endl;
    }

  TCanvas *c1 = new TCanvas();

  TGraphErrors *tge1 = new TGraphErrors(number,pt,ratio,ept,eratio);

  tge1->SetMarkerColor(kRed);
  tge1->SetMarkerStyle(20);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge1);
  tmg->Draw("ap");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,10.0);

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->AddEntry(tge1,"ppg080/ppg044","p");
  leg->Draw();

}
