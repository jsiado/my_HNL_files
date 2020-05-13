/*  Simple macro showing how to access branches from the delphes output root file, loop over events, 
 * and plot simple quantities such as the jet pt and the di-electron invariant mass.

root -l examples/RHN_Ana.C'("delphes_output.root")'*/

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#endif

//------------------------------------------------------------------------------

void RHN_Ana(const char *inputFile)
{
	 gSystem->Load("libDelphes");
		 
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
	TClonesArray *branchMissingET = treeReader->UseBranch("MissingET");

	// Book histograms
	TH1 *hist_JetPT = new TH1F("Jet PT", "Jet P_{T}", 100, 0.0, 140.0);
	TH1 *hist_Fir_Mu = new TH1F("First muon ", "P_{t} of leading Muon", 100, 0.0, 140.0);
	TH1 *hist_Sec_Mu = new TH1F("Second Muon ", "P_{t} of second muon", 100, 0.0, 140.0);
	TH1 *hist_Thi_Mu = new TH1F("Third muon ", "P_{t} of third muon ",100, 0.0, 140.0);
	TH1 *hist_sumPt = new TH1F("All PT ", "sum of P_{t} in the events ",100, 0.0, 1000.0);
	TH1 *hist_MET = new TH1F("MET ", "MET", 100, 0.0, 140.0);
	TH1 *hist_Wmass = new TH1F("W mass ", "W mass", 100, 0.0, 140.0);
	TH1 *hist_Wmass2 = new TH1F("W mass 2 ", "W mass 2", 100, 0.0, 140.0);
	TH1 *hist_Zmass = new TH1F("Z mass ", "Z mass", 100, 0.0, 140.0);
	TH1 *hist_NRmass = new TH1F("NR mass ","NR mass ", 100, 0.0, 140.0);
	
	//variables
	Muon *muon1, *muon2, *muon3;
	MissingET *neu1;
	
	int noreal = 0;
	int wmuon = 0;
	int hmuon = 0;
	int zmuon = 0;
	int count = 0;
	
	// Loop over all events
	for(Int_t entry = 0; entry < numberOfEntries; ++entry)
	{
// 		if (entry>10) break;
		// Load selected branches with data from specified event
		
		treeReader->ReadEntry(entry);

		//If event contains at least 1 jet
		if(branchJet->GetEntries() > 0)
		{
			Jet *jet = (Jet*) branchJet->At(0);// take first jet
			hist_JetPT->Fill(jet->PT);// Plot jet transverse momentum
		}
		
		//Event contains at least 3 muons
		if(branchMuon->GetEntries() > 2)
		{
			muon1 = (Muon *) branchMuon->At(0);
			muon2 = (Muon *) branchMuon->At(1);
			muon3 = (Muon *) branchMuon->At(2);
			hist_Fir_Mu->Fill(muon1->PT);
			hist_Sec_Mu->Fill(muon2->PT);
			hist_Thi_Mu->Fill(muon3->PT);
			
			/*for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
			{  
				GenParticle *gen = (GenParticle*) branchParticle->At(i);
				GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
				
				if(abs(gen->PID) == 13 && abs(genm->PID) == 23)
				{
					cout<<"a muon from z"<<endl;
					zmuon = zmuon +1;
				}
					
				if(abs(gen->PID) == 13 && abs(genm->PID) == 24)
				{
					cout<<"a muon from w"<<endl;
					wmuon = wmuon +1;
				}
				
				if(abs(gen->PID) == 13 && abs(genm->PID) == 25)
				{
					cout<<"a muon from h"<<endl;
					hmuon = hmuon +1;
				}
				if(abs(gen->PID) == 13 && abs(genm->PID) == 13)
				{
					cout<<"a muon from mu"<<endl;
					noreal = noreal +1;
				}*/
			
			}
		cout<<zmuon<<" "<<wmuon<<" "<<hmuon<<" "<<noreal<<endl;	
			
			//Event contains at least one neutrinos
			/*if(branchMissingET->GetEntries() > 0)
			{
// 				neu1 = (MissingET *) branchMissingET->At(0);
// 				hist_MET->Fill(neu1->MET);
// 				hist_sumPt->Fill(((muon1->P4()) + (neu1->P4()) + (muon3->P4()) + (muon2->P4())).M());
// 				hist_Wmass->Fill( ((neu1->P4()) + (muon3->P4())).M());
				
// 				for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
// 				{  
// 					GenParticle *gen = (GenParticle*) branchParticle->At(i);
// 					GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
					
// 					int &ancestorPID
					//separate muon coming from muons
					if(abs(gen->PID) == 13 && abs(genm->PID) == 13)
					{
						roreal = noreal + 1;
					}
					
					if(abs(gen->PID) == 13){	cout<<genm->PID<<endl;}
						
						
						
					//mass of the w
					if(abs(gen->PID) == 13 && abs(genm->PID) == 24)
					{
// 						cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
						hist_Wmass2->Fill( ((neu1->P4()) + (muon3->P4())).M());
					}
					
					//mass of the z
					if(abs(gen->PID) == 13 && abs(genm->PID) == 23)
					{
// 						cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
						hist_Zmass->Fill( ((muon2->P4()) + (muon3->P4())).M());
					}
					
					//mass of the higgs
// 					if(abs(gen->PID) == 13 && abs(genm->PID) == 24)
// 					{
// // 						cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
// 						hist_Wmass2->Fill( ((neu1->P4()) + (muon3->P4())).M());
// 					}
					
				}
			}*/
		}
// 		cout<<"looking at particles in "<<entry<<" the events"<<endl;
		//loop over all input particles in the event
		/*for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
		{  
			GenParticle *gen = (GenParticle*) branchParticle->At(i);
			GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
			if(abs(gen->PID) == 13 && abs(genm->PID) == 24)
			{
				cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
// 				hist_Wmass2->Fill( ((neu1->P4()) + (muon3->P4())).M());
			}
		}*/
	}

	
	
// 	for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
// 	{
// 	GenParticle *gen = (GenParticle*) branchParticle->At(i);
// 	GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
// 	cout<<"particle "<<gen->PID<<" mother "<<genm->PID<<endl;
// 	cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
// 	}
			
			
		//if(abs(gen->PID)==13)
		//{
			//if (genm->PID==23){cout<<"it is a muon coming from z"<<endl;}
			//else if(abs(genm->PID)==13)
			//{
// 				GenParticle *genm2 = (GenParticle*) branchParticle->At(gen->M2);
			  //cout<<"not coming from z "<<genm->PID<<endl;
			//}
// 			cout<<"pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
			/*if(branchMuon->GetEntries() > 1)
			{
				muon1 = (Muon *) branchMuon->At(0);
				muon2 = (Muon *) branchMuon->At(1);
				histMFromZ->Fill(((muon1->P4()) + (muon2->P4())).M());
			}*/
// 			else if	abs(gen->PID)==13 && abs(genm->PID)==13)
		//}
// 	}
	TFile *file1 = new TFile("out_hist_RHN.root", "RECREATE");
	hist_JetPT->Write();
	hist_Fir_Mu->Write();
	hist_Sec_Mu->Write();
	hist_Thi_Mu->Write();
	hist_sumPt->Write();
	hist_MET->Write();
	hist_Wmass->Write();
	hist_Wmass2->Write();
	hist_Zmass->Write();
	file1->Close();

// 	hist_Wmass2->Draw();
/*/ 	show plots
	TCanvas * canvas1 = new TCanvas("canvas1");	
	TCanvas * canvas2 = new TCanvas("canvas2");
	TCanvas * canvas3 = new TCanvas("canvas3");
	TCanvas * canvas4 = new TCanvas("canvas4");
	TCanvas * canvas5 = new TCanvas("canvas5");
	TCanvas * canvas6 = new TCanvas("canvas6");
	TCanvas * canvas7 = new TCanvas("canvas7");
	
	canvas1->cd();
	hist_JetPT->Draw();
	
	canvas2->cd();
	hist_Fir_Mu->Draw();
	
	canvas3->cd();
	hist_Sec_Mu->Draw();
	
	canvas4->cd();
	hist_Thi_Mu->Draw();
	
	canvas5->cd();
	hist_sumPt->Draw();
	
	canvas6->cd();
	hist_MET->Draw();
	
	canvas7->cd();
	hist_Wmass->Draw();*/
	
}
