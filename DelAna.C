#define DelAna_cxx
#include "DelAna.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
//to read

void DelAna::Begin()
{
  GEV = 1000.;
  MEV2GEV = .001;
  nEvtTotal = 0;

  _HstFile = new TFile(_HstFileName,"recreate");

  BookHistograms();
}

void DelAna::End()
{
  _HstFile->Write();
  _HstFile->Close();
  cout<<"Total events = "<<nEvtTotal<<endl;
  ofstream fout(_SumFileName);
  fout<<"Total events = "<<nEvtTotal<<endl;

}

void DelAna::Loop()
{
//   In a ROOT session, you can do:
//      root> .L DelAna.C
//      root> DelAna t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //for (Long64_t jentry=0; jentry<1000;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      nEvtTotal++;
    //Gives you the status of the event analysis
    if (nEvtTotal%1000==0)
      cout<<nEvtTotal<<" Events processed so far"<<endl;
<<<<<<< HEAD
   
=======
    
>>>>>>> 46b1ab86e9a494d344b57dce63a565de1331404c
    // START MY CODE        
    //cout<<"I am running "<<endl;    
    //particles.clear();
    ob particles[Particle_];
    for(int i =0;i<Particle_;i++){
      //if(abs(Particle_PID[i])==13 and Particle_Status[i]==1) cout<<" found muon with mother "<< Particle_PID[Particle_M1[i]] <<endl;
      ob temp;
      temp.v.SetPtEtaPhiM(Particle_PT[i],Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
      temp.pid = Particle_PID[i];
      temp.status = Particle_Status[i];
      temp.index = i;
      temp.M1 = Particle_M1[i];
      temp.M2 = Particle_M2[i];
      // temp.D1 = Particle_D1[i];
      // temp.D2 = Particle_D2[i];
      //particles.push_back(temp);
      particles[i]=temp;
    }
    //cout<<"p size "<<(int)particles.size()<<endl;

    vector<ob> NW;
    NW.clear();
    for(int i =0;i<Particle_;i++){
      ob m = GetMother(particles[i],particles);
      //if(particles[i].pid==13)cout<<" pid "<<particles[i].pid<<" mother pid "<<m.pid<<endl;
      
      if(abs(particles[i].pid)==13 or abs(particles[i].pid)==14){
	if(particles[i].status==1 and m.pid==66) NW.push_back(particles[i]);
	
      }
      
    }
    //cout<<"dau size "<<NW.size()<<endl;
    //cout<<"d1 "<<NW[0].pid<<" d2 "<<NW[1].pid<<" d3 "<<NW[2].pid<<endl;
    
    h.NMass->Fill((NW[0].v+NW[1].v+NW[2].v).M());
        
   }
}


void DelAna::BookHistograms()
{
  h.NMass  = new TH1F("NMass","NMass",20,20,40); h.NMass->Sumw2();

}

ob DelAna::GetMother(ob j, ob pa[])
 {
   ob mo;
   mo = j;
   if(j.M1 == -1) return mo;
   if(pa[j.M1].pid!=j.pid){
     mo = pa[j.M1];
     return mo;
   }
   if(pa[j.M1].pid==j.pid){
     mo =GetMother(pa[j.M1], pa);
     
   }
   
   return mo;
 }
