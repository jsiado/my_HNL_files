/*  Simple macro showing how to access branches from the delphes output root file, loop over events, and plot simple quantities such as the jet pt and the di-electron invariant mass.

root -l examples/RHN_Ana.C'("delphes_output.root")'*/

#ifdef __CLING__
R__LOAD_LIBRARY(libDelphes)
#include "classes/DelphesClasses.h"
#include "external/ExRootAnalysis/ExRootTreeReader.h"
#endif

//------------------------------------------------------------------------------

void RHN_Ana_Try(const char *inputFile)
{
	gSystem->Load("libDelphes");

	// Create chain of root trees
	TChain chain("Delphes");
	chain.Add(inputFile);

	// Create object of class ExRootTreeReader
	ExRootTreeReader *treeReader = new ExRootTreeReader(&chain);
	Long64_t numberOfEntries = treeReader->GetEntries();

	// Get pointers to branches used in this analysis
	TClonesArray *branchParticle = treeReader->UseBranch("Particle");

	// Loop over all events
	for(Int_t entry = 0; entry < numberOfEntries; ++entry)
	{
		// Load selected branches with data from specified event
		treeReader->ReadEntry(entry);
    
		if(entry>10) break;
    
// 		cout<<"" <<endl;
		cout<<"--------- New Event ---------" <<endl;
// 		cout<<"" <<endl;
 
		// loop over all input particles in the event
		for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
		{    
			GenParticle *gen = (GenParticle*) branchParticle->At(i);
// 			GenParticle *genM = (GenParticle*) branchParticle->At(gen->M1);
// 			GenParticle *genM2 = (GenParticle*) branchParticle->At(gen->M2);
			if (abs(gen->PID) == 24)// && abs(gen->M1) == 13)
			{
				cout<<" PID: "<<gen->PID<<", M1: "<<genM->PID<<", M2: "<<gen->M2<<", D1: "<<gen->D1<<", D2: "<<gen->D2<<endl;
			}
		}
	}
}
