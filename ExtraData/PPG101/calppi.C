void calppi()
{

  ifstream fin1;
  ifstream fin2;
  float dummy;
  const int nbin = 25;
  float tmp1pt[nbin], tmp1yield[nbin], tmp1eyield[nbin];
  float tmp2pt[nbin], tmp2yield[nbin], tmp2eyield[nbin];
  float pt[nbin], ratio[nbin], eratio[nbin];
  fin1.open("posproton.dat");
  fin2.open("pospion.dat");
  fin2>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy;
  fin2>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy;
  for(int i=0; i<nbin; i++)
    {
      fin1>>tmp1pt[i]>>tmp1yield[i]>>tmp1eyield[i]>>dummy>>dummy>>dummy>>dummy;
      fin2>>tmp2pt[i]>>tmp2yield[i]>>tmp2eyield[i]>>dummy>>dummy>>dummy>>dummy;
      if(fabs(tmp1pt[i]-tmp2pt[i])>0.01)
	{
	  cout<<"pt mismatch, fucking breaking "<<tmp1pt[i]<<" "<<tmp2pt[i]<<endl;
	  cout<<tmp1yield[i]<<" "<<tmp2yield[i]<<endl;
	  break;
	}
      pt[i] = tmp1pt[i];
      ratio[i] = tmp1yield[i]/tmp2yield[i];
      eratio[i] = ratio[i]*sqrt((tmp1eyield[i]/tmp1yield[i])**2+(tmp2eyield[i]/tmp2yield[i])**2);
      //cout<<i<<" "<<pt[i]<<" "<<ratio[i]<<endl;
    }
  fin1.close();
  fin2.close();
  TGraphErrors *tge_ppi_A = new TGraphErrors(nbin,pt,ratio,0,eratio);
  tge_ppi_A->SetMarkerStyle(kFullCircle);
  tge_ppi_A->SetMarkerColor(kBlack);

  for(int i=0; i<5; i++)
    {
      int j = i+15;
      int k1 = i*2+15;
      int k2 = i*2+16;
      pt[j] = (pt[k1]+pt[k2])/2.0;
      ratio[j] = (tmp1yield[k1]+tmp1yield[k2])/(tmp2yield[k1]+tmp2yield[k2]);
      eratio[j] = sqrt(eratio[k1]**2+eratio[k2]**2)/2.0;
    }
  for(int i=20; i<25; i++)
    {
      ratio[i] = -9;
    }
  TGraphErrors *tge_ppi_A2 = new TGraphErrors(nbin,pt,ratio,0,eratio);
  tge_ppi_A2->SetMarkerStyle(kFullCircle);
  tge_ppi_A2->SetMarkerColor(kBlack);


  fin1.open("ppi.dat");
  for(int i=0; i<25; i++)
    {
      fin1>>pt[i]>>ratio[i]>>eratio[i]>>dummy>>dummy>>dummy>>dummy;
      //eratio[i] *= 2; // temp!!
    }
  fin1.close();
  TGraphErrors *tge_ppi_T = new TGraphErrors(nbin,pt,ratio,0,eratio);
  tge_ppi_T->SetMarkerStyle(kOpenCircle);
  tge_ppi_T->SetMarkerColor(kRed);
  for(int i=0; i<5; i++)
    {
      int j = i+15;
      int k1 = i*2+15;
      int k2 = i*2+16;
      pt[j] = (pt[k1]+pt[k2])/2.0;
      ratio[j] = (ratio[k1]+ratio[k2])/2.0;
      eratio[j] = sqrt(eratio[k1]**2+eratio[k2]**2)/2.0;
    }
  for(int i=20; i<25; i++)
    {
      ratio[i] = -9;
    }
  TGraphErrors *tge_ppi_T2 = new TGraphErrors(nbin,pt,ratio,0,eratio);
  tge_ppi_T2->SetMarkerStyle(kOpenCircle);
  tge_ppi_T2->SetMarkerColor(kRed);

  TMultiGraph *tmg = new TMultiGraph();
  //tmg->Add(tge_ppi_A);
  tmg->Add(tge_ppi_A2);
  //tmg->Add(tge_ppi_T);
  tmg->Add(tge_ppi_T2);
  tmg->Draw("ap");
  tmg->SetMinimum(0.0);
  tmg->SetMaximum(0.35);
  tmg->GetXaxis()->SetLimits(0.0,3.5);

  c1->Print("test_ppi_v1.gif");

}
