void do_rda()
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
  if(centid==0) sprintf(centstring,"0088");
  else if(centid==1) sprintf(centstring,"0020");
  else if(centid==2) sprintf(centstring,"2040");
  else if(centid==3) sprintf(centstring,"4060");
  else if(centid==4) sprintf(centstring,"6088");
  else {cout<<"you gonna die"<<endl; return;}

  char filenamedAu[100];
  char filenamepp[100];
  char filenameOUT[100];

  float pt[10],
    yielddAu[10], eyielddAu[10], esysyielddAu[10],
    yieldpp[10], eyieldpp[10], esysyieldpp[10],
    ratio[10], eratio[10], esysratio[10];
  float tmp;


  float Ncoll[5] = {8.3,15.4,10.6,7.0,3.1};//numbers from ppg030 (final Run3, see also an900)

  sprintf(filenamedAu,"phi_spectra_dAu-%s.dat",centstring);
  sprintf(filenamepp,"phi_spectra_pp.dat");
  sprintf(filenameOUT,"phi_RdA_cent%s.dat",centstring);

  ifstream fauau(filenamedAu);
  ifstream fpp(filenamepp);
  ofstream fout(filenameOUT);
  for(int i=0; i<10; i++)
    {
      fauau>>pt[i]>>yielddAu[i]>>eyielddAu[i]>>esysyielddAu[i];
      tmp=pt[i];
      fpp>>pt[i]>>yieldpp[i]>>eyieldpp[i]>>esysyieldpp[i];
      if(fabs(pt[i]-tmp)>0.01) cout<<"pt trouble "<<pt[i]<<endl;
      ratio[i] = yielddAu[i]/yieldpp[i];
      eratio[i] = ratio[i]*sqrt((eyielddAu[i]/yielddAu[i])**2+(eyieldpp[i]/yieldpp[i])**2);
      esysratio[i] = ratio[i]*sqrt((esysyielddAu[i]/yielddAu[i])**2+(esysyieldpp[i]/yieldpp[i])**2);
      ratio[i] /= Ncoll[centid];
      eratio[i] /= Ncoll[centid];
      esysratio[i] /= Ncoll[centid];
      fout<<pt[i]<<"\t"<<ratio[i]<<"\t"<<eratio[i]<<"\t"<<esysratio[i]<<"\t"<<endl;
    }

}
