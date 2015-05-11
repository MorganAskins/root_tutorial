// Write to two files to demo TChains

#include <TFile.h>
#include <TTree.h>
#include <TF1.h>

int main()
{

  TF1 signal("signal", "TMath::Gaus(x, 10, 3)", 0, 20);
  TF1 bkg("background", "TMath::Exp(-x/3)", 0, 20);

  unsigned int evt_signal = 100000;
  unsigned int evt_bkg = evt_signal*2;

  double energy;

  // File 1
  TFile fone("tone.root", "recreate");
  TTree tr("atree", "t chain tree");
  tr.Branch("energy", &energy);
  
  for(unsigned int i=0; i<evt_signal; i++)
  {
    energy = signal.GetRandom();
    tr.Fill();
  }
  fone.Write();
  fone.Close();

  // File 2
  TFile ftwo("ttwo.root", "recreate");
  TTree tr2("atree", "t chain tree");
  tr2.Branch("energy", &energy);

  for(unsigned int i=0; i<evt_bkg; i++)
  {
    energy = bkg.GetRandom();
    tr2.Fill();
  }
  ftwo.Write();
  ftwo.Close();

  return 0;
}
  
