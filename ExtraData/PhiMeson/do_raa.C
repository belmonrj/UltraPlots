void do_raa()
{

  doit(0);
  doit(1);
  doit(2);
  doit(3);
  doit(4);

}

void doit(int centid=0)
{

  char centstring[5];
  if(centid==0) sprintf(centstring,"0010");
  else if(centid==1) sprintf(centstring,"1020");
  else if(centid==2) sprintf(centstring,"2040");
  else if(centid==3) sprintf(centstring,"4060");
  else if(centid==4) sprintf(centstring,"6092");
  else {cout<<"you gonna die"<<endl; return;}

  char filenameAuAu[100];
  char filenamepp[100];
  char filenameOUT[100];

  float pt[10],
    yieldAuAu[10], eyieldAuAu[10], esysyieldAuAu[10],
    yieldpp[10], eyieldpp[10], esysyieldpp[10],
    ratio[10], eratio[10], esysratio[10];
  float tmp;


  float Ncoll[5] = {955.4,602.6,296.8,90.6,14.5};//AN169 numbers for Run2&4

  sprintf(filenameAuAu,"phi_spectra_AuAu-%s.dat",centstring);
  sprintf(filenamepp,"phi_spectra_pp.dat");
  sprintf(filenameOUT,"phi_RAA_cent%s.dat",centstring);

  ifstream fauau(filenameAuAu);
  ifstream fpp(filenamepp);
  ofstream fout(filenameOUT);
  for(int i=0; i<10; i++)
    {
      fauau>>pt[i]>>yieldAuAu[i]>>eyieldAuAu[i]>>esysyieldAuAu[i];
      tmp=pt[i];
      fpp>>pt[i]>>yieldpp[i]>>eyieldpp[i]>>esysyieldpp[i];
      if(fabs(pt[i]-tmp)>0.01) cout<<"pt trouble "<<pt[i]<<endl;
      ratio[i] = yieldAuAu[i]/yieldpp[i];
      eratio[i] = ratio[i]*sqrt((eyieldAuAu[i]/yieldAuAu[i])**2+(eyieldpp[i]/yieldpp[i])**2);
      esysratio[i] = ratio[i]*sqrt((esysyieldAuAu[i]/yieldAuAu[i])**2+(esysyieldpp[i]/yieldpp[i])**2);
      ratio[i] /= Ncoll[centid];
      eratio[i] /= Ncoll[centid];
      esysratio[i] /= Ncoll[centid];
      fout<<pt[i]<<"\t"<<ratio[i]<<"\t"<<eratio[i]<<"\t"<<esysratio[i]<<"\t"<<endl;
    }

}
