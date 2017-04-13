void calculate4060()
{

  cout<<"Now calculating pi0 spectra for centrality 40-60 "<<endl;

  float content45;
  float content56;
  float content46;

  float contenterror45;
  float contenterror56;
  float contenterror46;

  float syscontenterror45;
  float syscontenterror56;
  float syscontenterror46;

  ifstream f45("ppg080_RAA4050.dat");
  ifstream f56("ppg080_RAA5060.dat");
  ofstream f46("ppg080_RAA4060.dat");

  float pT;
  float tmp;

  for(int i=0; i<18; i++)
    {
      f45>>pT>>content45>>contenterror45>>syscontenterror45;
      f56>>pT>>content56>>contenterror56>>syscontenterror56;
      content46 = (content45+content56)/2;
      contenterror46 = sqrt(contenterror45**2+contenterror56**2)/2;
      syscontenterror46 = sqrt(syscontenterror45**2+syscontenterror56**2)/2;
      f46<<pT<<"\t"<<content46<<"\t"<<contenterror46<<"\t"<<syscontenterror46<<endl;
    }

  cout<<"Done.  Have a nice day!"<<endl;

}
