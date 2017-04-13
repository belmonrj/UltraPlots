void calcrat()
{

  const int number = 19;

  float pt[number], ept[number],
    ppg044[number], eppg044[number],
    ppg054[number], eppg054[number],
    ppg080[number], eppg080[number],
    ratio1[number], eratio1[number],
    ratio2[number], eratio2[number];

  ifstream f044("ppg044_cent0020.dat");
  ifstream f054("ppg054_cent6092.dat");
  ifstream f080("ppg080_cent6092.dat");

  ofstream fout("pi0_aud_ratio.dat");
  for(int i=0; i<number; i++)
    {
      pt[i] = i/2.0+1.25;
      if(i>17)pt[i]=(float)i*2-25;
      float tmp;
      f044>>tmp>>ppg044[i]>>eppg044[i];
      if(fabs(pt[i]-tmp)>0.01){cout<<"pt trouble ppg044"<<pt[i]<<endl;}//break;}
      f054>>tmp>>ppg054[i]>>eppg054[i];
      if(fabs(pt[i]-tmp)>0.01){cout<<"pt trouble ppg054"<<endl;}
      f080>>tmp>>ppg080[i]>>eppg080[i];
      if(fabs(pt[i]-tmp)>0.01){cout<<"pt trouble ppg080"<<pt[i]<<endl;}//break;}
      ept[i] = 0;
      ratio1[i] = ppg054[i]/ppg044[i];
      ratio2[i] = ppg080[i]/ppg044[i];
      eratio1[i] = ratio1[i]*sqrt((eppg054[i]/ppg054[i])**2+(eppg044[i]/ppg044[i])**2);
      eratio2[i] = ratio2[i]*sqrt((eppg080[i]/ppg080[i])**2+(eppg044[i]/ppg044[i])**2);
      ratio1[i] *= (14.5/15.1); // Run2,4 over Run3
      ratio2[i] *= (14.5/15.1); // Run2,4 over Run3
      fout<<pt[i]<<"\t"<<ratio2[i]<<"\t"<<eratio2[i]/*<<"\t"<<ratio1[i]<<"\t"<<eratio1[i]*/<<endl;
    }

  TCanvas *c1 = new TCanvas();

  TGraphErrors *tge1 = new TGraphErrors(number,pt,ratio1,ept,eratio1);
  TGraphErrors *tge2 = new TGraphErrors(number,pt,ratio2,ept,eratio2);

  tge1->SetMarkerColor(kRed);
  tge1->SetMarkerStyle(20);
  tge2->SetMarkerColor(kBlue);
  tge2->SetMarkerStyle(20);

  TMultiGraph *tmg = new TMultiGraph();
  //tmg->Add(tge1);
  tmg->Add(tge2);
  tmg->Draw("ap");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,10.0);

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->AddEntry(tge1,"ppg054/ppg044","p");
  leg->AddEntry(tge2,"ppg080/ppg044","p");
  leg->Draw();

}
