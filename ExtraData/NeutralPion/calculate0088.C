void calculate0088()
{

  cout<<"Now calculating pi0 spectra for centrality 60-92 "<<endl;

  float content02;
  float content24;
  float content46;
  float content68;
  float content08;

  float contenterror02;
  float contenterror24;
  float contenterror46;
  float contenterror68;
  float contenterror08;

  ifstream f02("ppg044_RdA0020.dat");
  ifstream f24("ppg044_RdA2040.dat");
  ifstream f46("ppg044_RdA4060.dat");
  ifstream f68("ppg044_RdA6088.dat");
  ofstream f08("ppg044_RdA0088.dat");

  float pT;
  float tmp;

  for(int i=0; i<14; i++)
    {
      f02>>pT>>content02>>contenterror02;
      f24>>pT>>content24>>contenterror24;
      f46>>pT>>content46>>contenterror46;
      f68>>pT>>content68>>contenterror68;
      content08 = (content02+content24+content46+1.4*content68)/4.4;
      contenterror08 = sqrt(contenterror02**2+contenterror24**2+contenterror46**2+(1.4*contenterror68)**2)/4.4;
      f08<<pT<<"\t"<<content08<<"\t"<<contenterror08<<endl;
    }

  cout<<"Done.  Have a nice day!"<<endl;

}
