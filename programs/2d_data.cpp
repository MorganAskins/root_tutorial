// Interesting 2D data

#include <TFile.h>
#include <TTree.h>
#include <TF1.h>
#include <TRandom3.h>

int main()
{

  TFile fname("2d_data.root", "recreate");
  TTree tree("cdata", "correlated data");

  double a, b;
  tree.Branch("one", &a);
  tree.Branch("two", &b);

  TF1 afun("afun", "TMath::Gaus(x, [1], [2])", 0, 20);
  afun.SetParameters(12, 2);
  TF1 bfun("bfun", "TMath::Exp(-[1]*x)", 0, 5);
  bfun.SetParameter(0, 0.5);
  
  unsigned int evts = 100000;
  TRandom3 rndm;

  for( unsigned int i=0; i<evts; i++)
  {
    a = afun.GetRandom();
    b = bfun.GetRandom();
    tree.Fill();
  }

  fname.Write();
  fname.Close();

  return 0;
}
