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
	
	//variables
// 	Muon *muon1, *muon2, *muon3;
// 	MissingET *neu1, *neu2;
// 	int count = 0;
// 	int count2 = 0;
	int numZ=0;
	for(Int_t entry = 0; entry < numberOfEntries; ++entry)
	{
		treeReader->ReadEntry(entry);
// 		if (entry>10) break;
		for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
		{
			GenParticle *gen = (GenParticle*) branchParticle->At(i);
			GenParticle *genm = (GenParticle*) branchParticle->At(gen->M1);
// 			
			if (abs(gen->PID) == 13 && abs(genm->PID) == 24)
			{
// 				cout<<" "<<gen->PID<<" "<<genm->PID<<" "<<gen->PT<<" "<<genm->PT<<endl;
				
				
// 				count2 = count2 + 1;
// 				for (int j=0; j<branchParticle->GetEntriesFast(); j++)
// 				{
					GenParticle *hija1 = (GenParticle*) branchParticle->At(genm->D1);
					GenParticle *hija2 = (GenParticle*) branchParticle->At(genm->D1+1);
// 					cout<<j<<endl;
// 					if (((abs(gen->PID)==14) && (abs(hija2->PID)==13)) ||  ((abs(gen->PID)==13) && (abs(hija1->PID)==14)))
// 					{
// 						cout<<" p "<<gen->PID<<" m "<<genm->PID<<" d1 "<<hija1->PID<<" d2 "<<hija2->PID<<" pt "<<hija1->PT + hija2->PT<<endl;
					hist_Wmass2->Fill( ((hija1->P4()) + (hija2->P4())).M());
			}
// 			if (abs(gen->PID) == 13 && abs(genm->PID) == 23)
// 			{
// 				numZ++;
// 			}
// 				if ((abs(genm->D1) == 13 && abs(genm->D2) == 14) || (abs(genm->D1) == 14 && abs(genm->D2) == 13))
// 				{
// 					count = count + 1;
// 					cout<<i<<"one more"<<endl;
// 					hist_Wmass2->Fill( ((neu1->P4()) + (muon2->P4())).M());
// 				}
			}
		}
// 		cout<<count<<" "<<count2<<endl;
// 	}
// 						if(abs(genm->PID) == 13)
// 						{
// 							genm->D1
// 							GenParticle *genm2 = (GenParticle*) branchParticle->At(gen->M1);
// 						}
						
// 						cout<<i<<endl;
// 						cout<<i<<" pid "<<gen->PID<<" pidm "<<genm->PID<<endl;
// 						hist_Wmass2->Fill( ((neu1->P4()) + (muon3->P4())).M());
// 					}
// 					if(abs(gen->PID) == 13 && abs(genm->PID) == 13)
// 					{
						
// 					}
// 				}
// 				cout<<i<<endl;
// 			}
// 		}
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
