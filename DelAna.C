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
    for (Long64_t jentry=0; jentry<nentries;jentry++)
    {
     //for (Long64_t jentry=0; jentry<1000;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

        nEvtTotal++;
        //Gives you the status of the event analysis
        if (nEvtTotal%1000==0)
		{
			cout<<nEvtTotal<<" Events processed so far"<<endl;
		}
// 		START MY CODE        
// 		cout<<"I am running "<<endl;    
// 		particles.clear();
		ob particles[Particle_];
// 		cout<<Particle_<<endl;
		for(int i =0;i<Particle_;i++)
		{
// 			if(abs(Particle_PID[i])==13 and Particle_Status[i]==1) 
// 			cout<<" found muon  with mother "<<Particle_PID[Particle_M1[i]] <<endl;

			ob temp;
			temp.v.SetPtEtaPhiM(Particle_PT[i],Particle_Eta[i], Particle_Phi[i], Particle_Mass[i]);
			temp.pid = Particle_PID[i];
			temp.status = Particle_Status[i];
			temp.index = i;
			temp.M1 = Particle_M1[i];
			temp.M2 = Particle_M2[i];
// 			temp.D1 = Particle_D1[i];
// 			temp.D2 = Particle_D2[i];
// 			particles.push_back(temp);
			particles[i]=temp;
		}
    //cout<<"p size "<<(int)particles.size()<<endl;
	
	
//		Reco NR mass
		vector<ob> NW;
        NW.clear();
		for(int i =0;i<Particle_;i++)
		{
			ob m = GetMother(particles[i],particles);
			if(abs(particles[i].pid)==13 or abs(particles[i].pid)==14)
			{
				if(particles[i].status==1 and m.pid==66)
				{
					NW.push_back(particles[i]);
				}
			}
		}
		h.Mu1Pt->Fill(NW[1].v.Pt());
		h.Mu1Eta->Fill(NW[1].v.Eta());
		h.Mu1Phi->Fill(NW[1].v.Phi());
		
		if(abs(NW[0].pid == 13))
		{
			h.Mu2Pt->Fill(NW[0].v.Pt());
			h.Mu2Eta->Fill(NW[0].v.Eta());
			h.Mu2Phi->Fill(NW[0].v.Phi());
			h.NuMet->Fill(NW[2].v.Pt());
			h.NuEta->Fill(NW[2].v.Eta());
			h.NuPhi->Fill(NW[2].v.Phi());
		}
		else
		{
			h.Mu2Pt->Fill(NW[2].v.Pt());
			h.Mu2Eta->Fill(NW[2].v.Eta());
			h.Mu2Phi->Fill(NW[2].v.Phi());
			h.NuMet->Fill(NW[0].v.Pt());
			h.NuEta->Fill(NW[0].v.Eta());
			h.NuPhi->Fill(NW[0].v.Phi());
		}
		
// 		cout<<NW.size()<<" d1 "<<NW[0].pid<<" Pt "<<NW[0].v.Pt()<<" d2 "<<NW[1].pid<<" Pt "<<NW[1].v.Pt()<<" d3 "<<NW[2].pid<<" Pt "<<NW[2].v.Pt()<<endl;
		h.NMass->Fill((NW[0].v+NW[1].v+NW[2].v).M());

		
// 		Reco W Mass
		/*vector<ob> NW2;
		NW2.clear();
		for(int i =0;i<Particle_;i++)
		{
			ob m = GetMother(particles[i],particles);
// 			if(particles[i].pid==13)cout<<" pid "<<particles[i].pid<<" mother pid "<<m.pid<<endl;
			if(abs(particles[i].pid)==13)
			{
				if(particles[i].status==1 and m.pid==24)
				{
					NW2.push_back(particles[i]);
				}
			}
		}
// 		if (NW2.size()>0)
// 		{
// 			cout<<"size "<<NW2.size()<<" d1 "<<NW2[0].pid<<endl;
// 		}
// 		cout<<"d1 "<<NW2[0].pid<<endl" d2 "<<NW[1].pid<<" d3 "<<NW[2].pid<<endl
		if (NW2.size()>0) h.WMass->Fill( (NW[0].v+NW[1].v+NW[2].v + NW2[0].v).M());*/
	}
}


void DelAna::BookHistograms()
{
	h.NMass  = new TH1F("NR Mass","NR Mass",100,0.0,50.0); //h.NMass->Sumw2();
	h.NMass->GetXaxis()->SetTitle("Mass [GeV]");
	h.NMass->GetYaxis()->SetTitle("# of RHN ");
	h.NMass->SetTitle("Mass of RHN ");
	
	h.WMass  = new TH1F("W Mass","W Mass", 100,0.0,140.0); //h.WMass->Sumw2();
	h.WMass->GetXaxis()->SetTitle("Mass [GeV]");
	h.WMass->GetYaxis()->SetTitle("# of W bosons");
	h.WMass->SetTitle("Mass of the W bosons");
	
    h.LeaMPt  = new TH1F("Lead Muon P_{T}","Lead Muon P_{T}",100.0,0.0,100); //h.NMass->Sumw2();
	h.LeaMPt->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.LeaMPt->GetYaxis()->SetTitle("# of Muons");
	h.LeaMPt->SetTitle("Leading Muon P_{T}");
	
	h.LeaMEta  = new TH1F("Lead Muon Eta","Lead Muon Eta",100.0,-10.,10.0); //h.NMass->Sumw2();
	h.LeaMEta->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.LeaMEta->GetYaxis()->SetTitle("# of Muons");
	h.LeaMEta->SetTitle("Leading Muon P_{T}");
	
	h.LeaMPhi  = new TH1F("Lead Muon Phi","Lead Muon Phi",100.0,0.0,100); //h.NMass->Sumw2();
	h.LeaMPhi->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.LeaMPhi->GetYaxis()->SetTitle("# of Muons");
	h.LeaMPhi->SetTitle("Leading Muon Phi");
	
	h.Mu1Pt  = new TH1F("Muon 1 P_{T}","Muon 1 P_{T}",100.0,0.0,100); //h.NMass->Sumw2();
	h.Mu1Pt->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.Mu1Pt->GetYaxis()->SetTitle("# of Muons");
	h.Mu1Pt->SetTitle("Muon 1 P_{T}");
	
    h.Mu1Eta  = new TH1F("Muon 1 eta","Muon 1 eta", 100.0,-10.0,10.0); //h.WMass->Sumw2();
	h.Mu1Eta->GetXaxis()->SetTitle("Eta");
	h.Mu1Eta->GetYaxis()->SetTitle("# of Muons");
	h.Mu1Eta->SetTitle("Muon 1 eta");
	
    h.Mu1Phi  = new TH1F("Muon 1 Phi","Muon 1 Phi", 100.0,-5.0,5.0); //h.WMass->Sumw2();
	h.Mu1Phi->GetXaxis()->SetTitle("Phi");
	h.Mu1Phi->GetYaxis()->SetTitle("# of Muons");
	h.Mu1Phi->SetTitle("Muon 1 Phi");
	
	h.Mu2Pt  = new TH1F("Muon 2 P_{T}","Muon 2 P_{T}",100.0,0.0,100.0); //h.NMass->Sumw2();
	h.Mu2Pt->GetXaxis()->SetTitle("P_{T} [GeV]");
	h.Mu2Pt->GetYaxis()->SetTitle("# of Muons");
	h.Mu2Pt->SetTitle("Muon 2 P_{T}");
	
    h.Mu2Eta  = new TH1F("Muon 2 eta","Muon 2 eta", 100.0,-10.0,10.0); //h.WMass->Sumw2();
	h.Mu2Eta->GetXaxis()->SetTitle("Eta");
	h.Mu2Eta->GetYaxis()->SetTitle("# of Muons");
	h.Mu2Eta->SetTitle("Muon 2 eta");
	
    h.Mu2Phi  = new TH1F("Muon 2 Phi","Muon 2 Phi", 100.0,-5.0,5.0); //h.WMass->Sumw2();
	h.Mu2Phi->GetXaxis()->SetTitle("Phi");
	h.Mu2Phi->GetYaxis()->SetTitle("# of Muons");
	h.Mu2Phi->SetTitle("Muon 2 Phi");
	
	h.NuMet  = new TH1F("Neutrino Met","Neutrino Eta", 100.0,0.0,100.0); //h.WMass->Sumw2();
	h.NuMet->GetXaxis()->SetTitle("Met");
	h.NuMet->GetYaxis()->SetTitle("# of Neutrinos");
	h.NuMet->SetTitle("Neutrinos Met");
	
	h.NuEta  = new TH1F("Neutrino_Eta","Neutrino Eta", 100.0,-10.0,10.0); //h.WMass->Sumw2();
	h.NuEta->GetXaxis()->SetTitle("Eta");
	h.NuEta->GetYaxis()->SetTitle("# of Neutrinos");
	h.NuEta->SetTitle("Neutrinos Eta");
	
	h.NuPhi  = new TH1F("Neutrino Phi","Neutrino Phi", 100.0,-5.0,5.0); //h.WMass->Sumw2();
	h.NuPhi->GetXaxis()->SetTitle("Phi");
	h.NuPhi->GetYaxis()->SetTitle("# of Neutrinos");
	h.NuPhi->SetTitle("Neutrinos Phi");
}

ob DelAna::GetMother(ob j, ob pa[])
{
	ob mo;
	mo = j;
	if(j.M1 == -1) return mo;
	if(pa[j.M1].pid!=j.pid)
	{
		mo = pa[j.M1];
		return mo;
	}
	if(pa[j.M1].pid==j.pid)
	{
		mo =GetMother(pa[j.M1], pa);
	}
   return mo;
 }
