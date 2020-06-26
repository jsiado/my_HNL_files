/*
Simple macro showing how to access branches from the delphes output root file,
loop over events, store histograms in a root file and print them as image files.

root -l examples/Example2.C'("delphes_output.root")'
*/

#include "TH1.h"
#include "TSystem.h"

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#include "external/ExRootAnalysis/ExRootResult.h"
#endif

//------------------------------------------------------------------------------

struct MyPlots
{
  TH1 *fJetPT1;
  TH1 *fJetPT2;
  TH1 *fMissingET;
  TH1 *fElectronPT;
  TH1 *fMuonPT1;
  TH1 *fMuonPT2;
  TH1 *fMuonPT3;
  TH1 *fNRMass;
  TH1 *fWMass;
};

//------------------------------------------------------------------------------

class ExRootResult;
class ExRootTreeReader;

//------------------------------------------------------------------------------

void BookHistograms(ExRootResult *result, MyPlots *plots)
{
	THStack *stack;
	TLegend *legend;
	TPaveText *comment;

	// book 2 histograms for PT of 1st and 2nd leading jets
	plots->fJetPT1 = result->AddHist1D("Jet_pt_0", "Leading jet P_{T}",  "Jet P_{T} GeV/c", "Number of jets", 50, 0.0, 100.0);
	plots->fJetPT2 = result->AddHist1D("Jet_pt_1", "2nd leading jet P_{T}", "Jet P_{T} GeV/c", "Number of jets", 50, 0.0, 100.0);

	plots->fJetPT1->SetLineColor(kRed);
	plots->fJetPT2->SetLineColor(kBlue);

	stack = result->AddHistStack("Jet_pt_all", "1st and 2nd jets P_{T}");
	stack->Add(plots->fJetPT1);
	stack->Add(plots->fJetPT2);

	legend = result->AddLegend(0.72, 0.86, 0.98, 0.98);
	legend->AddEntry(plots->fJetPT1, "Leading jet", "l");
	legend->AddEntry(plots->fJetPT2, "Second jet", "l");
	result->Attach(stack, legend);

	// book 2 histograms for PT of muons
	plots->fMuonPT1 = result->AddHist1D("Muon_pt_0", "Leading muon P_{T}",  "Muon P_{T} GeV/c", "Number of muons", 50, 0.0, 140.0);
	plots->fMuonPT2 = result->AddHist1D("Muon_pt_1", "2nd leading muon P_{T}",  "Muon P_{T} GeV/c", "Number of muons", 50, 0.0, 140.0);
	plots->fMuonPT3 = result->AddHist1D("Muon_pt_2", "3rd leading muon P_{T}",  "Muon P_{T} GeV/c", "Number of muons", 50, 0.0, 140.0);
	
	plots->fMuonPT1->SetLineColor(kRed);
	plots->fMuonPT2->SetLineColor(kBlue);
	plots->fMuonPT3->SetLineColor(kYellow);
	
	stack = result->AddHistStack("Muon_pt_all", "Muon P_{T} Dist");
	stack->Add(plots->fMuonPT1);
	stack->Add(plots->fMuonPT2);
	stack->Add(plots->fMuonPT3);
	
	legend = result->AddLegend(0.72, 0.86, 0.98, 0.98);
	legend->AddEntry(plots->fMuonPT1, "Leading muon", "l");
	legend->AddEntry(plots->fMuonPT2, "Second muon", "l");
	legend->AddEntry(plots->fMuonPT3, "Third muon", "l");
	result->Attach(stack, legend);
	
	// book more histograms
	plots->fElectronPT = result->AddHist1D("Electron_pt", "Electron P_{T}", "Electron P_{T} GeV/c", "Number of electrons", 50, 0.0, 100.0);
	plots->fMissingET = result->AddHist1D("Missing_et", "Missing E_{T}", "Missing E_{T} GeV", "Number of events", 60, 0.0, 140.0);
	plots->fNRMass = result->AddHist1D("NR Mass ", "NR Mass GeV", "NR Mass (GeV)", "number of events", 60, 0.0, 80.0);
	plots->fWMass = result->AddHist1D("W Mass ", "W Mass", "W Mass (GeV)", "number of events", 60, 0.0, 140.0);


  // book general comment
//   comment = result->AddComment(0.64, 0.86, 0.98, 0.98);
//   comment->AddText("demonstration plot");
//   comment->AddText("produced by Example2.C");

  // attach comment to single histograms

//   result->Attach(plots->fJetPT[0], comment);
//   result->Attach(plots->fJetPT[1], comment);
//   result->Attach(plots->fElectronPT, comment);

  // show histogram statisics for MissingET
  plots->fMissingET->SetStats();
  plots->fNRMass->SetStats();
  plots->fWMass->SetStats();
}



//------------------------------------------------------------------------------

void AnalyseEvents(ExRootTreeReader *treeReader, MyPlots *plots)
{
	TClonesArray *branchJet = treeReader->UseBranch("Jet");
	TClonesArray *branchElectron = treeReader->UseBranch("Electron");
	TClonesArray *branchMissingET = treeReader->UseBranch("MissingET");
	TClonesArray *branchMuon = treeReader->UseBranch("Muon");
	TClonesArray *branchParticle = treeReader->UseBranch("Particle");
	
	Long64_t allEntries = treeReader->GetEntries();
	
	cout << "** Chain contains " << allEntries << " events" << endl;
	
	
	Jet *jet1;
	Jet *jet2;
	MissingET *met;
	Electron *electron;
	Muon *muon1;
	Muon *muon2;
	Muon *muon3;
	
	
	
	Long64_t entry;
	
	Int_t i;
	
	// Loop over all events
	for(entry = 0; entry < allEntries; ++entry)
	{
		if (entry%1000==0){	cout<<entry<<" Events processed so far"<<endl;}
    
    // Load selected branches with data from specified event
		treeReader->ReadEntry(entry);

    // Analyse two leading jets
		if(branchJet->GetEntriesFast() >= 2)
		{
			jet1 = (Jet*) branchJet->At(0);
			jet2 = (Jet*) branchJet->At(1);

			plots->fJetPT1->Fill(jet1->PT);
			plots->fJetPT2->Fill(jet2->PT);
		}
		
		//Analyse three leading muons
		if(branchMuon->GetEntriesFast() >= 1)
		{
			muon1 = (Muon*) branchMuon->At(0);
			plots->fMuonPT1->Fill(muon1->PT);
			
			if(branchMuon->GetEntriesFast() >= 2)
			{
				muon2 = (Muon*) branchMuon->At(1);
				plots->fMuonPT2->Fill(muon2->PT);
				
				if(branchMuon->GetEntriesFast() >= 3)
				{
					muon3 = (Muon*) branchMuon->At(2);
					plots->fMuonPT3->Fill(muon3->PT);
				}
			}
		}
		
		if(branchMuon->GetEntriesFast() >= 3 && branchMissingET->GetEntriesFast() > 0)
		{
			muon1 = (Muon*) branchMuon->At(0);
			muon2 = (Muon*) branchMuon->At(1);
			muon3 = (Muon*) branchMuon->At(2);
			met = (MissingET*) branchMissingET->At(0);
			
// 			plots->fNRMass->Fill(((muon2->P4()) + (muon3->P4()) + (met->P4())).M());
			plots->fNRMass->Fill( sqrt( muon3->PT*muon3->PT + met->MET*met->MET + muon2->PT*muon2->PT));
// 			plots->fWMass->Fill( ( (muon1->P4()) + (muon2->P4()) + (muon3->P4()) + (met->P4()) ).M());
		}

    // Analyse missing ET
		if(branchMissingET->GetEntriesFast() > 0)
		{
			met = (MissingET*) branchMissingET->At(0);
			plots->fMissingET->Fill(met->MET);
		}
		
		if(branchElectron->GetEntriesFast() > 0)
		{
			elec = (Electron*) branchElectron->At(0);
			plots->fElectron->Fill(electron->PT);
		}
	}
	for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
	{
		GenParticle *gen = (GenParticle*) branchParticle->At(i);
		m = findMother(i)
	}
}

void findMother(int part)
{
//    ob mo;
   mo = part;
   GenParticle *mother = (GenParticle*) branchParticle->At(gen->M1);
   
   if(mother->PID == -1) return part;
   if(pa[j.M1].pid!=j.pid){
     mo = pa[j.M1];
     return mo;
   }
   if(pa[j.M1].pid==j.pid){
     mo =GetMother(pa[j.M1], pa);
     
   }
   
   return mo;
 }

//------------------------------------------------------------------------------

void PrintHistograms(ExRootResult *result, MyPlots *plots)
{
  result->Print("png");
}



//------------------------------------------------------------------------------

void Example2_Copy(const char *inputFile)
{
  gSystem->Load("libDelphes");

  TChain *chain = new TChain("Delphes");
  chain->Add(inputFile);

  ExRootTreeReader *treeReader = new ExRootTreeReader(chain);
  ExRootResult *result = new ExRootResult();

  MyPlots *plots = new MyPlots;

  BookHistograms(result, plots);

  AnalyseEvents(treeReader, plots);

  PrintHistograms(result, plots);

  result->Write("results.root");

  cout << "** Exiting..." << endl;

  delete plots;
  delete result;
  delete treeReader;
  delete chain;
}

//------------------------------------------------------------------------------
