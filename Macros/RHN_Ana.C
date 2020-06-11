/*  Simple macro showing how to access branches from the delphes output root file, loop over events, 
 * and plot simple quantities such as the  and the di-electron invariant mass.
 * Modified by Joaquin Siado to use the SM_RHL model

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
// 	TClonesArray *branchElectron = treeReader->UseBranch("Electron");
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
	
	TH1 *hist_WM1 = new TH1F("W1 mass ", "W1 mass", 100, 0.0, 140.0);
	TH1 *hist_WM2 = new TH1F("W2 mass ", "W2 mass", 100, 0.0, 140.0);
	TH1 *hist_WM3 = new TH1F("W3 mass ", "W3 mass", 100, 0.0, 140.0);
	
	TH1 *hist_muon12 = new TH1F("12 NR mass ","NR mass ", 100, 0.0, 140.0);
	TH1 *hist_muon13 = new TH1F("13 NR mass ","NR mass ", 100, 0.0, 140.0);
	TH1 *hist_muon23 = new TH1F("23 NR mass ","NR mass ", 100, 0.0, 140.0);
	TH1 *hist_all = new TH1F("all ","NR mass ", 100, 0.0, 140.0);
	
	//variables
// 	Muon *muon1, *muon2, *muon3;
// 	MissingET *neu1, *neu2;
	int count1W = 0;
	int count2W = 0;
	int countNR = 0;
// 	int numZ=0;
	for(Int_t entry = 0; entry < numberOfEntries; ++entry)
	{
		treeReader->ReadEntry(entry);
// 		if (entry>2000) break;
		
		for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
		{
			GenParticle *gen = (GenParticle*) branchParticle->At(i);
// 			GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
			
// 			cout<<gen->PID<<" "<<genm->PID<<" "<<endl;
// 			cout<<gen->PID<<endl;
// 			cout<<" p "<<gen->PID<<" m "<<genm->PID<<endl;
// 	
			/*if (abs(gen->PID) == 24 && abs(genm->PID) == 66)
			{
				count2W++;
				cout<<"bla"<<endl;
			}*/
			
			/*if (abs(gen->PID) == 24 )
			{
				count2W++;
				cout<<genm->PID<<" ";
				if (abs(genm->PID) == 24)
				{
					GenParticle *genm2 = (GenParticle*) branchParticle->At(genm->M1);
					cout<<genm2->PID<<endl;
					if (abs(mother2->PID) == 24)
					{
						GenParticle *mother3 = (GenParticle*) branchParticle->At(mother2->M1);
						cout<<mother3->PID<<" ";
					}
				}
				cout<<endl;
			}*/
			/*if (abs(gen->PID) == 13 && abs(genm->PID) == 24)
			{
				
// 				count1W++;
				GenParticle *daug1 = (GenParticle*) branchParticle->At(genm->D1);
				GenParticle *daug2 = (GenParticle*) branchParticle->At(genm->D1+1);
// 				cout<<j<<endl;
// 				if (((abs(gen->PID)==14) && (abs(hija2->PID)==13)) ||  ((abs(gen->PID)==13) && (abs(hija1->PID)==14)))
// 				{
// 				cout<<" p "<<gen->PID<<" m "<<genm->PID<<" d1 "<<hija1->PID<<" d2 "<<hija2->PID<<" pt "<<hija1->PT + hija2->PT<<endl;
				hist_Wmass2->Fill( ((daug1->P4()) + (daug2->P4())).M());
				
				GenParticle *gr1 = (GenParticle*) branchParticle->At(genm->M1);
				GenParticle *gra = (GenParticle*) branchParticle->At(genm->M2);
				cout<<"part "<<gen->PID<<" moth "<<genm->PID<<" gran  "<<gr1->PID<<" grgran "<<gra->PID<<endl;
				if (abs(gra->PID) == 24)
				{
					int sw = 0;
					while(sw == 0)
					{
						
						GenParticle *grb = (GenParticle*) branchParticle->At(gra->M1);
// 						cout<<"in the while loop "<<grb->PID<<endl;
						if (abs(grb->PID) == 66)
						{
							sw = 1;
							cout<<"part "<<gen->PID<<" moth "<<genm->PID<<" gran  "<<gra->PID<<" grgran "<<grb->PID<<endl;
						}
						else if(abs(grb->PID) == 24)
						{
							GenParticle *gra = (GenParticle*) branchParticle->At(gra->M1);
							cout<<"part "<<gen->PID<<" moth "<<genm->PID<<" gran  "<<gra->PID<<" grgran "<<grb->PID<<endl;
						}
					}
				}
			}*/
			/*if (abs(gen->PID) == 13 && abs(genm->PID) == 24)
			{
				GenParticle *gr1 = (GenParticle*) branchParticle->At(genm->M1);
				cout<<"  "<<gen->PID<<"  "<<genm->PID<<"  "<<gr1->PID<<"  ";
				if (abs(gr1->PID) == 24)
				{
					GenParticle *gr2 = (GenParticle*) branchParticle->At(gr1->M1);
					cout<<gr2->PID<<"  ";
					if (abs(gr2->PID) == 24)
					{
						GenParticle *gr3 = (GenParticle*) branchParticle->At(gr2->M1);
						cout<<gr3->PID<<"  ";
						if (abs(gr3->PID) == 24)
						{
							GenParticle *gr4 = (GenParticle*) branchParticle->At(gr3->M1);
							cout<<gr4->PID<<"  "<<endl;
						}
					}
				}
			}*/
			if(branchMuon->GetEntriesFast() >= 3 && branchMissingET->GetEntriesFast() > 0)
			{
				muon1 = (Muon*) branchMuon->At(0);
				muon2 = (Muon*) branchMuon->At(1);
				muon3 = (Muon*) branchMuon->At(2);
				met = (MissingET*) branchMissingET->At(0);
				
// 				hist_muon12->Fill(((muon1->P4()) + (muon2->P4())).M());
				hist_muon23->Fill(( (muon2->P4()) + (met->P4()) + (muon3->P4())   ).M());
				hist_WM1->Fill(( (muon1->P4()) + (met->P4())  ).M());
				hist_WM2->Fill(( (muon2->P4()) + (met->P4())  ).M());
				hist_WM3->Fill(( (muon3->P4()) + (met->P4())  ).M());
				
				hist_all->Fill(muon1->PT + muon2->PT+ muon3->PT + met->MET  );
				
				
// 				hist_Wmass->Fill(( (muon1->P4()) + (met->P4())  ).M());
			}
			
// 				muon[0] = (Muon*) branchMuon->At(0);
// 			cout<<"  "<<gen->PID<<"  "<<genm->PID<<"  ";
// 			if (abs(gen->PID) == 13 && abs(genm->PID) == 24)
// 			{
// 				GenParticle *gr1 = (GenParticle*) branchParticle->At(genm->M1);
// 				cout<<gr1->PID<<"  ";
// 				if (abs(gr1->PID) == 24)
// 				{
// 					GenParticle *gr2 = (GenParticle*) branchParticle->At(gr1->M1);
// 					cout<<gr2<<" ";
// 					if (abs(gr1->PID) == 24)
// 					{
// 						GenParticle *gr3 = (GenParticle*) branchParticle->At(gr2->M1);
// 						cout<<gr3<<" ";
// 					}
// 				}
// 			}	
		}//loop of particles
// 		cout<<"new event"<<endl;
	}//loo of events
// 	cout<<count2W<<endl;
	TCanvas * canvas1 = new TCanvas("canvas1");
	TCanvas * canvas2 = new TCanvas("canvas2");	
	TCanvas * canvas3 = new TCanvas("canvas3");
	TCanvas * canvas4 = new TCanvas("canvas4");
	

	canvas1->cd(); hist_WM1->Draw();
	canvas2->cd(); hist_WM2->Draw();
	canvas3->cd(); hist_WM3->Draw();
	canvas4->cd(); hist_all->Draw();
	
	
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
