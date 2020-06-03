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
	float totP = 0;
	int numpar = 0;
	float fiW = 0;
	int numpar2 = 0;
	// Loop over all events
	for(Int_t entry = 0; entry < numberOfEntries; ++entry)
	{
		// Load selected branches with data from specified event
		treeReader->ReadEntry(entry);
    
// 		if(entry>10) break;
    
// 		cout<<"" <<endl;
		cout<<"--------- New Event ---------" <<endl;
// 		cout<<"" <<endl;
 
		// loop over all input particles in the event
		for(Int_t i=0; i < branchParticle->GetEntriesFast(); i++)
		{    
			GenParticle *gen = (GenParticle*) branchParticle->At(i);
			GenParticle *genM = (GenParticle*) branchParticle->At(gen->M1);
			
			if (abs(gen->PID) == 13 && abs(genM->PID) == 66)
			{
				numpar++;
// 				cargar el momemtun:
// 				comentar la linea
// 				cout<<" PID: "<<gen->PID<<", M1: "<<genM->PID<<endl;
				GenParticle *daug1 = (GenParticle*) branchParticle->At(genM->D1);
				GenParticle *daug2 = (GenParticle*) branchParticle->At(genM->D2);
				if (abs(daug1->PID) == 13 && abs(daug2->PID) == 14)
				{
					totP = totP + daug1->PT+daug2->PT;
					cout<<" PID: "<<gen->PID<<", M1: "<<genM->PID<<", D1 "<<daug1->PID<<", D2: "<<daug2->PID<<" Pt "<<daug1->PT+daug2->PT<<" ";
				}
				
				GenParticle *Gr = (GenParticle*) branchParticle->At(genM->M1);
				if (abs(Gr->PID) == 24)//13 && abs(daug2->PID) == 14)
				{
					fiW = fiW + Gr->PT + daug1->PT + daug2->PT;
					numpar2++;
					cout<<Gr->PID<<endl;
				}
				cout<<endl;
			}
		}
// 		cout<<numpar<<endl;
		cout<<totP/numpar<<"  "<<fiW/numpar2<<endl;
	}
}
