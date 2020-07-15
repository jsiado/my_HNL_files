/*  Simple macro showing how to access branches from the delphes output root file, loop over events, and plot simple quantities such as the jet pt and the di-electron invariant mass.

root -l examples/Example1.C'("delphes_output.root")'*/

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#endif





/*
#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"
#else
class ExRootTreeReader;
class ExRootResult;
#endif*/

//------------------------------------------------------------------------------

void MyFirstAna(const char *inputFile)
{
	 gSystem->Load("libDelphes");
	 //Probando, nueva prueba, last chance
		 
	// Create chain of root trees
	TChain chain("Delphes");
	chain.Add(inputFile);

	// Create object of class ExRootTreeReader
	ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
	Long64_t numberOfEntries = treeReader->GetEntries();

	// Get pointers to branches used in this analysis
	TClonesArray *branchJet = treeReader->UseBranch("Jet");
	TClonesArray *branchElectron = treeReader->UseBranch("Electron");
	TClonesArray *branchMuon = treeReader->UseBranch("Muon");
	TClonesArray *branchParticle = treeReader->UseBranch("Particle");

	// Book histograms
	TH1 *histJetPT = new TH1F("jet_pt", "jet P_{T}", 100, 0.0, 100.0);
	TH1 *histMasse1e2 = new TH1F("mass", "M_{inv}(e_{1}, e_{2})", 100, 40.0, 140.0);
	TH1 *histMassm1m2 = new TH1F("muon mass", "M_{inv}(mu_{1}, mu_{2})", 300, 50.0, 140.0);
	TH1 *histMFromZ = new TH1F("muon from Z", "M_{inv}(mu_{1}, mu_{2})", 300, 50.0, 140.0);
	countAll = 0;
	// Loop over all events
	for(Int_t entry = 0; entry < numberOfEntries; ++entry)
	{
// 		if(entry>2) break;
		// Load selected branches with data from specified event
		treeReader->ReadEntry(entry);
// 		GenParticle *gen = (GenParticle*) branchParticle->At(0); //get the particle ID

		// If event contains at least 1 jet
		/*if(branchJet->GetEntries() > 0)
		{
			Jet *jet = (Jet*) branchJet->At(0);// take first jet
			histJetPT->Fill(jet->PT);// Plot jet transverse momentum
			Print jet transverse momentum
			cout << "Jet pt: "<<jet->PT << endl;
		}*/
		
		/*TClonesArray *branchParticle = treeReader->UseBranch("Particle");

		GenParticle *particle, *mother;
		Int_t index, motherPID;
			
		particle = (GenParticle *) branchParticle->At(index);
		mother = (GenParticle *) branchParticle->At(particle->M1);
		motherPID = mother->PID;*/
		
		
		// If event contains at least 2 electrons
		/*Electron *elec1, *elec2;
		if(branchElectron->GetEntries() > 1)
		{
			// Take first two electrons
			elec1 = (Electron *) branchElectron->At(0);
// 			GenParticle *gen = (GenParticle*) branchParticle->At(0);
// 			cout<<"Electron "<<gen->PID<<endl;
			elec2 = (Electron *) branchElectron->At(1);
			histMasse1e2->Fill(((elec1->P4()) + (elec2->P4())).M()); //plot their invariant mass
		}*/
		
		Muon *muon1, *muon2;
		if(branchMuon->GetEntries() > 1)
		{
			muon1 = (Muon *) branchMuon->At(0);
			muon2 = (Muon *) branchMuon->At(1);
			histMassm1m2->Fill(((muon1->P4()) + (muon2->P4())).M());
		}
		
		cout<<"--------- New Event ---------" <<endl;
		cout<<"" <<endl;
 
		// loop over all input particles in the event
// 		int grandma = 0;
		for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
		{
			GenParticle *gen = (GenParticle*) branchParticle->At(i);
			GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
// 			GenParticle *genm2 = (GenParticle*) branchParticle->At(M2);
			if(abs(gen->PID)==13)
			{
				if (genm->PID==23){cout<<"it is a muon coming from z"<<endl;}
				else if(abs(genm->PID)==13)
				{
// 					GenParticle *genm2 = (GenParticle*) branchParticle->At(gen->M2);
					cout<<"not coming from z "<<genm->PID<<endl;
				}
// 					cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
					/*if(branchMuon->GetEntries() > 1)
					{
						muon1 = (Muon *) branchMuon->At(0);
						muon2 = (Muon *) branchMuon->At(1);
						histMFromZ->Fill(((muon1->P4()) + (muon2->P4())).M());
					}*/
// 			else if	abs(gen->PID)==13 && abs(genm->PID)==13)
				
			}
		}
	}
	

// 	show plots
// 	TCanvas * canvas1 = new TCanvas("canvas1");	
// 	TCanvas * canvas2 = new TCanvas("canvas2");
// 	TCanvas * canvas3 = new TCanvas("canvas3");
// 	canvas1->cd();
// 	histJetPT->Draw();
// 	canvas2->cd();
	histMassm1m2->Draw();
// 	canvas3->cd();
// 	histMFromZ->Draw();
}
