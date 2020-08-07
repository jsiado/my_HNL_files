#define DelAna_cxx
#include "DelAna.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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
      Long64_t ientry = LoadTree(jentry);      
      if (ientry < 0) break;      
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      nEvtTotal++;
    //Gives you the status of the event analysis
    if (nEvtTotal%1000==0)
      cout<<nEvtTotal<<" Events processed so far"<<endl;

    // START MY CODE         
    //particles.clear();
    ob particles[Particle_];
	for(int i =0;i<Particle_;i++)
	{
		ob temp;
		temp.v.SetPtEtaPhiM(Particle_PT[i],Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
		temp.pid = Particle_PID[i];
		temp.status = Particle_Status[i];
		temp.index = i;
		temp.M1 = Particle_M1[i];
		//temp.M2 = Particle_M2[i];
		// temp.D1 = Particle_D1[i];
		// temp.D2 = Particle_D2[i];
		temp.Dxy = Particle_D0[i];
		temp.Dz = Particle_DZ[i];
		//cout<<" D0 "<<temp.D0<<endl;
		particles[i]=temp;
	}
    //cout<<"p size "<<(int)particles.size()<<endl;

    vector<ob> NW;
    NW.clear();
	vector<ob> NW2;
    NW2.clear();
    for(int i =0;i<Particle_;i++)
	{
		ob m = GetMother(particles[i],particles);
		//if(particles[i].pid==13)cout<<" pid "<<particles[i].pid<<" mother pid "<<m.pid<<endl;      
		if(abs(particles[i].pid)==13 or abs(particles[i].pid)==14)
		{
			if(particles[i].status==1 and m.pid==66)
				NW.push_back(particles[i]);
		}
		if(abs(particles[i].pid)==13)
		{
			if(particles[i].status==1 and abs(m.pid)==24)
				NW2.push_back(particles[i]);
		}
		
	}
	
	/*for(int i =0;i<Particle_;i++)  //same result
	{
		ob m = GetMother(particles[i],particles);
		//if(particles[i].pid==13)cout<<" pid "<<particles[i].pid<<" mother pid "<<m.pid<<endl;      
		if(abs(particles[i].pid)==13)
		{
			if(particles[i].status==1 and m.pid==66)
				NW.push_back(particles[i]);
			if(particles[i].status==1 and abs(m.pid)==24)
				NW2.push_back(particles[i]);
		}
		if(abs(particles[i].pid)==14)
		{
			if(particles[i].status==1 and m.pid==66)
				NW.push_back(particles[i]);
		}
		
	}*/
	
	
	
	
	
	//cout<<"dau size "<<NW.size()<<endl;
	//cout<<"d1 "<<NW[0].v.Pt()<<" d2 "<<NW[1].pid<<" d3 "<<NW[2].pid<<endl;
//     cout<<NW2.size();
	h.NMass->Fill((NW[0].v+NW[1].v+NW[2].v).M());
	if (NW2.size()>0) 
	{
		h.WMass->Fill((NW[0].v+NW[1].v+NW[2].v+NW2[0].v).M());
		h.L1Pt->Fill(NW[0].v.Pt());
		h.L1Eta->Fill(NW[0].v.Eta());
		h.L1Phi->Fill(NW[0].v.Phi());
	}
	h.Dxy->Fill(NW[0].Dxy);
	h.Dz->Fill(NW[0].Dz);
	
	h.L2Pt->Fill(NW[1].v.Pt());
	h.L2Eta->Fill(NW[1].v.Eta());
	h.L2Phi->Fill(NW[1].v.Phi());
	
	if(abs(NW[0].pid) == 13)
	{
		h.L3Pt->Fill(NW[0].v.Pt());
		h.L3Eta->Fill(NW[0].v.Eta());
		h.L3Phi->Fill(NW[0].v.Phi());
		h.NuMet->Fill(NW[2].v.Pt());
		h.NuEta->Fill(NW[2].v.Eta());
		h.NuPhi->Fill(NW[2].v.Phi());
	}
	else
	{
		h.L3Pt->Fill(NW[2].v.Pt());
		h.L3Eta->Fill(NW[2].v.Eta());
		h.L3Phi->Fill(NW[2].v.Phi());
		h.NuMet->Fill(NW[0].v.Pt());
		h.NuEta->Fill(NW[0].v.Eta());
		h.NuPhi->Fill(NW[0].v.Phi());
	}	
   }
}


void DelAna::BookHistograms()
{
	h.NMass  = new TH1F("NR_Mass","NR Mass",20,-5,50); h.NMass->Sumw2();
	h.NMass->GetXaxis()->SetTitle("Mass [GeV]");
	h.NMass->GetYaxis()->SetTitle("# of RHN ");
	h.NMass->SetTitle("NR Mass");
	
	h.WMass  = new TH1F("W_Mass","W Mass",100,0,120); h.WMass->Sumw2();
	h.WMass->GetXaxis()->SetTitle("Mass [GeV]");
	h.WMass->GetYaxis()->SetTitle("# of Events ");
	h.WMass->SetTitle("W Mass");
	
	h.L1Pt  = new TH1F("First_Lepton_Pt","First Lepton P_{T}",100.0,0.0,100); h.L1Pt->Sumw2();
	h.L1Pt->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.L1Pt->GetYaxis()->SetTitle("# of Events");
	h.L1Pt->SetTitle("First Lepton P_{T}");
	
	h.L1Eta  = new TH1F("First_Lepton_Eta","First Lepton Eta",100.0,-10.,10.0); h.L1Eta->Sumw2();
	h.L1Eta->GetXaxis()->SetTitle("Eta");
	h.L1Eta->GetYaxis()->SetTitle("# of Events");
	h.L1Eta->SetTitle("First Lepton Eta");
	
	h.L1Phi  = new TH1F("First_Lepton_Phi","First Lepton Phi",100.0,-5.0,5.0); h.L1Phi->Sumw2();
	h.L1Phi->GetXaxis()->SetTitle("Phi");
	h.L1Phi->GetYaxis()->SetTitle("# of Events");
	h.L1Phi->SetTitle("First Lepton Phi");
	
	h.L2Pt  = new TH1F("Second_Lepton_Pt","Second Lepton P_{T}",100.0,0.0,100); h.L2Pt->Sumw2();
	h.L2Pt->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.L2Pt->GetYaxis()->SetTitle("# of Events");
	h.L2Pt->SetTitle("Second Lepton P_{T}");
	
	h.L2Eta  = new TH1F("Second_Lepton_Eta","Second Lepton Eta", 100.,-10.,10.); h.L2Eta->Sumw2();
	h.L2Eta->GetXaxis()->SetTitle("Eta");
	h.L2Eta->GetYaxis()->SetTitle("# of Events");
	h.L2Eta->SetTitle("Second Lepton Eta");
	
	h.L2Phi  = new TH1F("Second_Lepton_Phi","Second Lepton Phi", 100,-5.,5.); h.L2Phi->Sumw2();
	h.L2Phi->GetXaxis()->SetTitle("Phi");
	h.L2Phi->GetYaxis()->SetTitle("# of Events");
	h.L2Phi->SetTitle("Second Lepton Phi");
	
	h.L3Pt  = new TH1F("Third_Lepton_Pt","Third Lepton P_{T}",100.0,0.0,200.0); h.L3Pt->Sumw2();
	h.L3Pt->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.L3Pt->GetYaxis()->SetTitle("# of Events");
	h.L3Pt->SetTitle("Third Lepton P_{T}");
	
	h.L3Eta  = new TH1F("Third_Lepton_Eta","Third Lepton Eta",100.0,-10.,10.); h.L3Eta->Sumw2();
	h.L3Eta->GetXaxis()->SetTitle("Eta");
	h.L3Eta->GetYaxis()->SetTitle("# of Events");
	h.L3Eta->SetTitle("Third Lepton Eta");
	
	h.L3Phi  = new TH1F("Third_Lepton_Phi","Third Lepton Phi",100.0,-5.0,5.0); h.L3Phi->Sumw2();
	h.L3Phi->GetXaxis()->SetTitle("Phi");
	h.L3Phi->GetYaxis()->SetTitle("# of Events");
	h.L3Phi->SetTitle("Third Lepton Phi");
	
	h.NuMet  = new TH1F("Neutrino_Met","Neutrino Met", 100.0,0.,100.); h.NuMet->Sumw2();
	h.NuMet->GetXaxis()->SetTitle("Met");
	h.NuMet->GetYaxis()->SetTitle("# of Events");
	h.NuMet->SetTitle("Neutrino Met");
	
	h.NuEta  = new TH1F("Neutrino_Eta","Neutrino Eta", 100.0,-10.,10.); h.NuEta->Sumw2();
	h.NuEta->GetXaxis()->SetTitle("Eta");
	h.NuEta->GetYaxis()->SetTitle("# of Events");
	h.NuEta->SetTitle("Neutrino Eta");
	
	h.NuPhi  = new TH1F("Neutrino_Phi","Neutrino Phi", 100.0,-5.,5.); h.NuPhi->Sumw2();
	h.NuPhi->GetXaxis()->SetTitle("Phi");
	h.NuPhi->GetYaxis()->SetTitle("# of Events");
	h.NuPhi->SetTitle("Neutrino Phi");
	
	h.Dxy  = new TH1F("Transverse_Impact_Parameter","Transverse Impact Parameter",100,-5.,5.); h.Dxy->Sumw2();
	h.Dxy->GetXaxis()->SetTitle("Distance (mm)");
	h.Dxy->GetYaxis()->SetTitle("# of Events");
	h.Dxy->SetTitle("Dxy");
	
	h.Dz  = new TH1F("Long_Impact_Parameter","Long Impact Parameter",100,-5.,5.); h.Dz->Sumw2();
	h.Dz->GetXaxis()->SetTitle("Distance (mm)");
	h.Dz->GetYaxis()->SetTitle("# of Events");
	h.Dz->SetTitle("Dz");
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
