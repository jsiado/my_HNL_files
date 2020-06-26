#include <TChain.h>

void ana(int sample_id=0)
{
  gROOT->Time();
  gSystem->Load("libDelphes");
  gSystem->CompileMacro("DelAna.C","k0");
  
  TChain *chain = new TChain("Delphes");
  
  DelAna *t = new DelAna(chain);
  
  if(sample_id==0){
	chain->Add("RHN_Mu_13TeV_10k.root");

    t->SetHstFileName("hst_RHN.root");
    t->SetSumFileName("sum_RHN.txt");
  }

  t->Begin();
  t->Loop();
  t->End();

  gROOT->Time();
}
