void do_rcp()
{

  doit(0,4);
  doit(0,3);

}

void doit(int centid1=0, int centid2=4)
{

  char centstring1[5];
  if(centid1==0) sprintf(centstring1,"0010");
  else if(centid1==1) sprintf(centstring1,"1020");
  else if(centid1==2) sprintf(centstring1,"2040");
  else if(centid1==3) sprintf(centstring1,"4060");
  else if(centid1==4) sprintf(centstring1,"6092");
  else {cout<<"you gonna die"<<endl; return;}

  char centstring2[5];
  if(centid2==0) sprintf(centstring2,"0010");
  else if(centid2==1) sprintf(centstring2,"1020");
  else if(centid2==2) sprintf(centstring2,"2040");
  else if(centid2==3) sprintf(centstring2,"4060");
  else if(centid2==4) sprintf(centstring2,"6092");
  else {cout<<"you gonna die"<<endl; return;}

  char filenamecent[100];
  char filenameperi[100];
  char filenameOUT[100];

  float pt[10],
    yieldcent[10], eyieldcent[10], esysyieldcent[10],
    yieldperi[10], eyieldperi[10], esysyieldperi[10],
    ratio[10], eratio[10], esysratio[10];
  float tmp;


  float Ncoll[5] = {955.4,602.6,296.8,90.6,14.5};//AN169 numbers for Run2&4

  sprintf(filenamecent,"phi_spectra_AuAu-%s.dat",centstring1);
  sprintf(filenameperi,"phi_spectra_AuAu-%s.dat",centstring2);
  sprintf(filenameOUT,"phi_RCP_c%d%d.dat",centid1,centid2);

  ifstream fcent(filenamecent);
  ifstream fperi(filenameperi);
  ofstream fout(filenameOUT);
  for(int i=0; i<10; i++)
    {
      fcent>>pt[i]>>yieldcent[i]>>eyieldcent[i]>>esysyieldcent[i];
      tmp=pt[i];
      fperi>>pt[i]>>yieldperi[i]>>eyieldperi[i]>>esysyieldperi[i];
      if(fabs(pt[i]-tmp)>0.01) cout<<"pt trouble "<<pt[i]<<endl;
      ratio[i] = yieldcent[i]/yieldperi[i];
      eratio[i] = ratio[i]*sqrt((eyieldcent[i]/yieldcent[i])**2+(eyieldperi[i]/yieldperi[i])**2);
      esysratio[i] = ratio[i]*sqrt((esysyieldcent[i]/yieldcent[i])**2+(esysyieldperi[i]/yieldperi[i])**2);
      ratio[i] *= Ncoll[centid2]/Ncoll[centid1];
      eratio[i] *= Ncoll[centid2]/Ncoll[centid1];
      esysratio[i] *= Ncoll[centid2]/Ncoll[centid1];
      fout<<pt[i]<<"\t"<<ratio[i]<<"\t"<<eratio[i]<<"\t"<<esysratio[i]<<"\t"<<endl;
    }

}
