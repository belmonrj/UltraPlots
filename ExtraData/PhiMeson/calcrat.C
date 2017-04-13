void calcrat()
{

  const int number = 9;

  float pt[number], ept[number],
    ppg096_dAu[number], eppg096_dAu[number],
    ppg096_AuAu[number], eppg096_AuAu[number],
    ratio1[number], eratio1[number];

  ifstream f096_dAu("phi_spectra_dAu-0020.dat");
  ifstream f096_AuAu("phi_spectra_AuAu-6092.dat");

  ofstream fout("phi_aud_ratio.dat");
  for(int i=0; i<number; i++)
    {
      //pt[i] = i/2.0+1.25;
      float tmp, tmp2;
      float esys_dAu, esys_AuAu;
      //f096_dAu>>tmp>>ppg096_dAu[i]>>eppg096_dAu[i]>>tmp2;
      f096_dAu>>tmp>>ppg096_dAu[i]>>eppg096_dAu[i]>>esys_dAu;
      pt[i] = tmp;
      //f096_AuAu>>tmp>>ppg096_AuAu[i]>>eppg096_AuAu[i]>>tmp2;
      f096_AuAu>>tmp>>ppg096_AuAu[i]>>eppg096_AuAu[i]>>esys_AuAu;
      if(fabs(pt[i]-tmp)>0.01) cout<<"pt trouble"<<endl;
      ept[i] = 0;
      ratio1[i] = ppg096_AuAu[i]/ppg096_dAu[i];
      eratio1[i] = ratio1[i]*sqrt((eppg096_AuAu[i]/ppg096_AuAu[i])**2+(eppg096_dAu[i]/ppg096_dAu[i])**2);
      float esys = ratio1[i]*sqrt((esys_AuAu[i]/ppg096_AuAu[i])**2+(esys_dAu[i]/ppg096_dAu[i])**2);
      ratio1[i] /= (14.5/15.1);
      fout<<pt[i]<<"\t"<<ratio1[i]<<"\t"<<eratio1[i]<<"\t"<<esys<<endl;
    }

  TCanvas *c1 = new TCanvas();

  TGraphErrors *tge1 = new TGraphErrors(number,pt,ratio1,ept,eratio1);

  tge1->SetMarkerColor(kRed);
  tge1->SetMarkerStyle(20);

  TMultiGraph *tmg = new TMultiGraph();
  tmg->Add(tge1);
  tmg->Draw("ap");
  tmg->SetMaximum(2.0);
  tmg->SetMinimum(0.0);
  tmg->GetXaxis()->SetLimits(0.0,7.0);

  TLegend *leg = new TLegend(0.68,0.68,0.88,0.88);
  leg->AddEntry(tge1,"ppg096_AuAu/ppg096_dAu","p");
  leg->Draw();

}
