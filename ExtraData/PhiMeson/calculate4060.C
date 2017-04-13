void calculate4060()
{

  cout<<"Now calculating pi0 spectra for centrality 40-60 "<<endl;

  float content45;
  float content56;
  float content46;

  float contenterror45;
  float contenterror56;
  float contenterror46;

  float contentsyserror45;
  float contentsyserror56;
  float contentsyserror46;

  ifstream f45("phi_spectra_AuAu-4050.dat");
  ifstream f56("phi_spectra_AuAu-5060.dat");
  ofstream f46("phi_spectra_AuAu-4060.dat");

  float pT;
  float tmp;

  for(int i=0; i<10; i++)
    {
      f45>>pT>>content45>>contenterror45>>contentsyserror45;
      f56>>pT>>content56>>contenterror56>>contentsyserror56;
      content46 = (content45+content56)/2;
      contenterror46 = sqrt(contenterror45**2+contenterror56**2)/2;
      contentsyserror46 = sqrt(contentsyserror45**2+contentsyserror56**2)/2;
      f46<<pT<<"\t"<<content46<<"\t"<<contenterror46<<"\t"<<contentsyserror46<<endl;
    }

  cout<<"Done.  Have a nice day!"<<endl;

}
