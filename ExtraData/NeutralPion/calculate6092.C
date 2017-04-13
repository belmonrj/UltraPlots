void calculate6092()
{

  cout<<"Now calculating pi0 spectra for centrality 60-92 "<<endl;

  float content67;
  float content78;
  float content89;
  float content69;

  float contenterror67;
  float contenterror78;
  float contenterror89;
  float contenterror69;

  float syscontenterror67;
  float syscontenterror78;
  float syscontenterror89;
  float syscontenterror69;

  ifstream f67("ppg080_RAA6070.dat");
  ifstream f78("ppg080_RAA7080.dat");
  ifstream f89("ppg080_RAA8092.dat");
  ofstream f69("ppg080_RAA6092.dat");

  float pT;
  float tmp;

  for(int i=0; i<14; i++)
    {
      f67>>pT>>content67>>contenterror67>>syscontenterror67;
      f78>>pT>>content78>>contenterror78>>syscontenterror78;
      f89>>pT>>content89>>contenterror89>>syscontenterror89;
      content69 = (content67+content78+1.2*content89)/3.2;
      contenterror69 = sqrt(contenterror67**2+contenterror78**2+(1.2*contenterror89)**2)/3.2;
      syscontenterror69 = sqrt(syscontenterror67**2+syscontenterror78**2+(1.2*syscontenterror89)**2)/3.2;
      f69<<pT<<"\t"<<content69<<"\t"<<contenterror69<<"\t"<<syscontenterror69<<endl;
    }

  cout<<"Done.  Have a nice day!"<<endl;

}
