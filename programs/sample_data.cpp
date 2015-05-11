// Example root program: simulate events with a gaussian distribution, exp background
// and poisson timing

// c++ includes
#include <iostream>
#include <string>

// root includes we may need
#include <TTree.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TF1.h>

int main()
{
  // Open a file to write out data
  TFile file("data.root", "recreate");
  
  // mono-energetic energy with poisson timing
  double energy, time;

  // TTree of physics events
  TTree datTree("dtree", "data tree");
  // link branches of the tree to variables in the event
  datTree.Branch("energy", &energy);
  datTree.Branch("time", &time);

  unsigned int events = 50000;
  double mean_energy = 6;
  double resolution = 1;
  TF1* evt_energy = new TF1("evt_energy", "[0]*TMath::Gaus(x, [1], [2]) + [4]*TMath::Exp(-[5]*x)", 0, 14);
  evt_energy->SetParameters(1, mean_energy, resolution, 5, 0.5);
  double evt_time = 2.5;
  TF1* evt_timing = new TF1("evt_time", "TMath::Exp(-x/[0])", 0, 100);
  evt_timing->SetParameter(0, evt_time);

  for( unsigned int i=0; i<events; ++i)
  {
    energy = evt_energy->GetRandom();
    time = evt_timing->GetRandom();
    datTree.Fill();
  }

  delete evt_energy;
  delete evt_timing;
  
  file.Write();
  file.Close();
  return 0;
}
