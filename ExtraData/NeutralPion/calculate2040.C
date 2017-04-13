void calculate2040()
{

  cout<<"Now calculating pi0 spectra for centrality 20-40 "<<endl;

  float content23;
  float content34;
  float content24;

  float contenterror23;
  float contenterror34;
  float contenterror24;

  float syscontenterror23;
  float syscontenterror34;
  float syscontenterror24;

  ifstream f23("ppg080_RAA2030.dat");
  ifstream f34("ppg080_RAA3040.dat");
  ofstream f24("ppg080_RAA2040.dat");

  float pT;
  float tmp;

  for(int i=0; i<18; i++)
    {
      f23>>pT>>content23>>contenterror23>>syscontenterror23;
      f34>>pT>>content34>>contenterror34>>syscontenterror34;
      content24 = (content23+content34)/2;
      contenterror24 = sqrt(contenterror23**2+contenterror34**2)/2;
      syscontenterror24 = sqrt(syscontenterror23**2+syscontenterror34**2)/2;
      f24<<pT<<"\t"<<content24<<"\t"<<contenterror24<<"\t"<<syscontenterror24<<endl;
    }

  cout<<"Done.  Have a nice day!"<<endl;

}
