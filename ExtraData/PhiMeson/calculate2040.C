void calculate2040()
{

  cout<<"Now calculating pi0 spectra for centrality 20-40 "<<endl;

  float content23;
  float content34;
  float content24;

  float contenterror23;
  float contenterror34;
  float contenterror24;

  float contentsyserror23;
  float contentsyserror34;
  float contentsyserror24;

  ifstream f23("phi_spectra_AuAu-2030.dat");
  ifstream f34("phi_spectra_AuAu-3040.dat");
  ofstream f24("phi_spectra_AuAu-2040.dat");

  float pT;
  float tmp;

  for(int i=0; i<10; i++)
    {
      f23>>pT>>content23>>contenterror23>>contentsyserror23;
      f34>>pT>>content34>>contenterror34>>contentsyserror34;
      content24 = (content23+content34)/2;
      contenterror24 = sqrt(contenterror23**2+contenterror34**2)/2;
      contentsyserror24 = sqrt(contentsyserror23**2+contentsyserror34**2)/2;
      f24<<pT<<"\t"<<content24<<"\t"<<contenterror24<<"\t"<<contentsyserror24<<endl;
    }

  cout<<"Done.  Have a nice day!"<<endl;

}
