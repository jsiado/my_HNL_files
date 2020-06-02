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
  TH1 *fJetPT[2];
  TH1 *fMissingET;
  TH1 *fElectronPT;
  TH1 *fMuonPT[3];
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
	plots->fJetPT[0] = result->AddHist1D("jet_pt_0", "leading jet P_{T}",  "jet P_{T} GeV/c", "number of jets", 50, 0.0, 100.0);
	plots->fJetPT[1] = result->AddHist1D("jet_pt_1", "2nd leading jet P_{T}", "jet P_{T} GeV/c", "number of jets", 50, 0.0, 100.0);

	plots->fJetPT[0]->SetLineColor(kRed);
	plots->fJetPT[1]->SetLineColor(kBlue);

	stack = result->AddHistStack("jet_pt_all", "1st and 2nd jets P_{T}");
	stack->Add(plots->fJetPT[0]);
	stack->Add(plots->fJetPT[1]);

	legend = result->AddLegend(0.72, 0.86, 0.98, 0.98);
	legend->AddEntry(plots->fJetPT[0], "leading jet", "l");
	legend->AddEntry(plots->fJetPT[1], "second jet", "l");
	result->Attach(stack, legend);

	// book 2 histograms for PT of muons
	plots->fMuonPT[0] = result->AddHist1D("muon_pt_0", "leading muon P_{T}",  "muon P_{T} GeV/c", "number of muons", 50, 0.0, 140.0);
	plots->fMuonPT[1] = result->AddHist1D("muon_pt_1", "2nd leading muon P_{T}",  "muon P_{T} GeV/c", "number of muons", 50, 0.0, 140.0);
	plots->fMuonPT[2] = result->AddHist1D("muon_pt_2", "third leading muon P_{T}",  "muon P_{T} GeV/c", "number of muons", 50, 0.0, 140.0);
	
	plots->fMuonPT[0]->SetLineColor(kRed);
	plots->fMuonPT[1]->SetLineColor(kBlue);
	plots->fMuonPT[2]->SetLineColor(kYellow);
	
	stack = result->AddHistStack("Muon_pt_all", "Muon P_{T} Dist");
	stack->Add(plots->fMuonPT[0]);
	stack->Add(plots->fMuonPT[1]);
	stack->Add(plots->fMuonPT[2]);
	
	legend = result->AddLegend(0.72, 0.86, 0.98, 0.98);
	legend->AddEntry(plots->fMuonPT[0], "leading muon", "l");
	legend->AddEntry(plots->fMuonPT[1], "second muon", "l");
	legend->AddEntry(plots->fMuonPT[2], "Third muon", "l");
	result->Attach(stack, legend);
	
	// book more histograms
	plots->fElectronPT = result->AddHist1D("electron_pt", "electron P_{T}", "electron P_{T} GeV/c", "number of electrons", 50, 0.0, 100.0);
	plots->fMissingET = result->AddHist1D("missing_et", "Missing E_{T}", "Missing E_{T} GeV", "number of events", 60, 0.0, 140.0);

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
}

//------------------------------------------------------------------------------

void AnalyseEvents(ExRootTreeReader *treeReader, MyPlots *plots)
{
	TClonesArray *branchJet = treeReader->UseBranch("Jet");
	TClonesArray *branchElectron = treeReader->UseBranch("Electron");
	TClonesArray *branchMissingET = treeReader->UseBranch("MissingET");
	TClonesArray *branchMuon = treeReader->UseBranch("Muon");
	
	Long64_t allEntries = treeReader->GetEntries();
	
	cout << "** Chain contains " << allEntries << " events" << endl;
	
	Jet *jet[2];
	MissingET *met;
	Electron *electron;
	Muon *muon[3];
	
	Long64_t entry;
	
	Int_t i;
	
	// Loop over all events
	for(entry = 0; entry < allEntries; ++entry)
	{
    // Load selected branches with data from specified event
		treeReader->ReadEntry(entry);

    // Analyse two leading jets
		if(branchJet->GetEntriesFast() >= 2)
		{
			jet[0] = (Jet*) branchJet->At(0);
			jet[1] = (Jet*) branchJet->At(1);

			plots->fJetPT[0]->Fill(jet[0]->PT);
			plots->fJetPT[1]->Fill(jet[1]->PT);
		}
    
		if(branchMuon->GetEntriesFast() >= 1)
		{
			muon[0] = (Muon*) branchMuon->At(0);
			plots->fMuonPT[0]->Fill(muon[0]->PT);
			if(branchMuon->GetEntriesFast() >= 2)
			{
				muon[1] = (Muon*) branchMuon->At(1);
				plots->fMuonPT[1]->Fill(muon[1]->PT);
				if(branchMuon->GetEntriesFast() >= 3)
				{
					muon[2] = (Muon*) branchMuon->At(2);
					plots->fMuonPT[2]->Fill(muon[2]->PT);
				}
			}
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
			plots->fElectron->Fill(elec->MET);
		}


    // Loop over all electrons in event
//     for(i = 0; i < branchElectron->GetEntriesFast(); ++i)
//     {
//       electron = (Electron*) branchElectron->At(i);
//       plots->fElectronPT->Fill(electron->PT);
//     }
	}
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
