// #include <TTree.h>
// #include <TFile.h>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
// #include <TH2F.h>
#include <TMath.h>
#include "Math/LorentzVector.h"
#include "TLorentzVector.h"
#include "TVector.h"
#include "TVector2.h"
#include "TVector3.h"
// // Header file for the classes stored in the TTree if any.
#include <vector>
#include <fstream>
#include <iostream>
// Header file for the classes stored in the TTree if any.
#include "TClonesArray.h"
#include "TObject.h"
#include "TVector3.h"

#include "TGraph.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TF1.h"


void myplotter()
{
	
	TFile* file2 = TFile::Open("hst_RHN_13TeV_2GeV.root");
	TFile* file5 = TFile::Open("hst_RHN_13TeV_5GeV.root");
	TFile* file10 = TFile::Open("hst_RHN_13TeV_10GeV.root");
	TFile* file15 = TFile::Open("hst_RHN_13TeV_15GeV.root");
	TFile* file20 = TFile::Open("hst_RHN_13TeV_20GeV.root");
	TFile* file30 = TFile::Open("hst_RHN_13TeV_30GeV.root");
	
// 	//////////////////////////////////////////////////////////////
// 	First_Lepton Variables
// 	/////////////////////////////////////////////////
	TH1 *Lep1_2Pt = (TH1*)file2->Get("First_Lepton_Pt");
	TH1 *Lep1_5Pt = (TH1*)file5->Get("First_Lepton_Pt");
	TH1 *Lep1_10Pt = (TH1*)file10->Get("First_Lepton_Pt");
	TH1 *Lep1_15Pt = (TH1*)file15->Get("First_Lepton_Pt");
	TH1 *Lep1_20Pt = (TH1*)file20->Get("First_Lepton_Pt");
	TH1 *Lep1_30Pt = (TH1*)file30->Get("First_Lepton_Pt");
	
	Lep1_2Pt -> SetLineColor(1);
	Lep1_5Pt -> SetLineColor(2);
	Lep1_10Pt -> SetLineColor(3);
	Lep1_15Pt -> SetLineColor(4);
	Lep1_20Pt -> SetLineColor(5);
	Lep1_30Pt -> SetLineColor(6);
	
	
	TCanvas * canLep1Pt = new TCanvas("canLep1Pt");	
	canLep1Pt->cd();
	Lep1_2Pt->SetTitle("First_Lepton_Pt");
	Lep1_2Pt -> SetStats(kFALSE);
	Lep1_2Pt -> Draw("hist");
	Lep1_5Pt -> Draw("same,hist");
	Lep1_10Pt -> Draw("Same,hist");
	Lep1_15Pt -> Draw("Same,hist");
	Lep1_20Pt -> Draw("Same,hist");
	Lep1_30Pt -> Draw("Same,hist");
	
	TLegend *leglep1pt = new TLegend(0.85, 0.75, .75, .89);
	leglep1pt->SetBorderSize(0);
// 	leg->SetLineColor(1);
// 	gStyle->SetFillColor(0);
// 	gStyle->SetCanvasColor(10);
	leglep1pt->AddEntry(Lep1_2Pt, "2 GeV", "L");
	leglep1pt->AddEntry(Lep1_5Pt, "5 GeV", "L");
	leglep1pt->AddEntry(Lep1_10Pt, "10 GeV", "L");
	leglep1pt->AddEntry(Lep1_15Pt, "10 GeV", "L");
	leglep1pt->AddEntry(Lep1_20Pt, "10 GeV", "L");
	leglep1pt->AddEntry(Lep1_30Pt, "10 GeV", "L");
	leglep1pt->Draw();
	canLep1Pt->SaveAs("First_Lepton_Pt.png");
	
	
	
// 	//////////////////////////////////////////////
// 	Second lepton variables
// 	/////////////////////////////////////////////
	TH1 *Lep2_2Pt = (TH1*)file2->Get("Second_Lepton_Pt");//repeat for every mass point
	TH1 *Lep2_5Pt = (TH1*)file5->Get("Second_Lepton_Pt");
	TH1 *Lep2_10Pt = (TH1*)file10->Get("Second_Lepton_Pt");
	TH1 *Lep2_15Pt = (TH1*)file15->Get("Second_Lepton_Pt");
	TH1 *Lep2_20Pt = (TH1*)file20->Get("Second_Lepton_Pt");
	TH1 *Lep2_30Pt = (TH1*)file30->Get("Second_Lepton_Pt");
	
	Lep2_2Pt -> SetLineColor(1);//repeat for every mass point
	Lep2_5Pt -> SetLineColor(2);
	Lep2_10Pt -> SetLineColor(3);
	Lep2_15Pt -> SetLineColor(4);
	Lep2_20Pt -> SetLineColor(5);
	Lep2_30Pt -> SetLineColor(6);
	
	TCanvas * canLep2Pt = new TCanvas("canLep2Pt");
	canLep2Pt->cd();
	Lep2_2Pt->SetTitle("Second_Lepton_Pt");
	Lep2_2Pt->SetStats(kFALSE);
	Lep2_2Pt -> Draw("hist");//repeat for each mass point
	Lep2_5Pt -> Draw("same,hist");
	Lep2_10Pt -> Draw("same,hist");
	Lep2_15Pt -> Draw("same,hist");
	Lep2_20Pt -> Draw("same,hist");
	Lep2_30Pt -> Draw("same,hist");
	
	TLegend* leglep2Pt = new TLegend(0.85, 0.75, .75, .89);
	leglep2Pt->SetBorderSize(0);
	leglep2Pt->AddEntry(Lep2_2Pt, "2 GeV", "L");//repeat for every mass point
	leglep2Pt->AddEntry(Lep2_5Pt, "5 GeV", "L");
	leglep2Pt->AddEntry(Lep2_10Pt, "10 GeV", "L");
	leglep2Pt->AddEntry(Lep2_15Pt, "15 GeV", "L");
	leglep2Pt->AddEntry(Lep2_20Pt, "20 GeV", "L");
	leglep2Pt->AddEntry(Lep2_30Pt, "30 GeV", "L");
	leglep2Pt->Draw();
	canLep2Pt->SaveAs("Second_Lepton_Pt.png");
	


// 	//////////////////////////////////////////////////////////////
// 	Transverse_Impact_Parameter
// 	/////////////////////////////////////////////////////////////
	TH1 *TrImPa2 = (TH1*)file2->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa5 = (TH1*)file5->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa10 = (TH1*)file10->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa15 = (TH1*)file15->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa20 = (TH1*)file20->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa30 = (TH1*)file30->Get("Transverse_Impact_Parameter");
	
	TrImPa2 -> SetLineColor(1);
	TrImPa5 -> SetLineColor(2);
	TrImPa10 -> SetLineColor(3);
	TrImPa15 -> SetLineColor(4);
	TrImPa20 -> SetLineColor(5);
	TrImPa30 -> SetLineColor(6);
	
	TCanvas *TrImPa = new TCanvas("TrImPa");
	TrImPa->cd();
	TrImPa2->SetTitle("Transverse Impact Parameter");
	TrImPa2->SetStats(kFALSE);
	TrImPa2 -> Draw("hist");
	TrImPa5 -> Draw("same,hist");
	TrImPa10 -> Draw("same,hist");
	TrImPa15 -> Draw("same,hist");
	TrImPa20 -> Draw("same,hist");
	TrImPa30 -> Draw("same,hist");
	
	TLegend* leg1 = new TLegend(0.85, 0.75, .75, .89);
	leg1->SetBorderSize(0);
// 	leg1->SetLineColor(0);
// 	gStyle->SetFillColor(0);
// 	gStyle->SetCanvasColor(10);
	leg1->AddEntry(TrImPa2, "2 GeV", "L");
	leg1->AddEntry(TrImPa5, "5 GeV", "L");
	leg1->AddEntry(TrImPa10, "10 GeV", "L");
	leg1->AddEntry(TrImPa15, "15 GeV", "L");
	leg1->AddEntry(TrImPa20, "20 GeV", "L");
	leg1->AddEntry(TrImPa30, "30 GeV", "L");
	leg1->Draw();
	TrImPa->SaveAs("Trans_Impa_Par.png");
	
	
// 	////////////////////////////////////////////////////////////
// 	Long_Impact_Parameter
// 	///////////////////////////////////////////////////////////
	TH1 *LoImPa2 = (TH1*)file2->Get("Long_Impact_Parameter");//repeat for every mass point
	TH1 *LoImPa5 = (TH1*)file5->Get("Long_Impact_Parameter");
	TH1 *LoImPa10 = (TH1*)file10->Get("Long_Impact_Parameter");
	TH1 *LoImPa15 = (TH1*)file15->Get("Long_Impact_Parameter");
	TH1 *LoImPa20 = (TH1*)file20->Get("Long_Impact_Parameter");
	TH1 *LoImPa30 = (TH1*)file30->Get("Long_Impact_Parameter");
	
	LoImPa2 -> SetLineColor(1);//repeat for every mass point
	LoImPa5 -> SetLineColor(2);
	LoImPa10 -> SetLineColor(3);
	LoImPa15 -> SetLineColor(4);
	LoImPa20 -> SetLineColor(5);
	LoImPa30 -> SetLineColor(6);
	
	TCanvas * canLoImPa = new TCanvas("canLoImPa");
	canLoImPa->cd();
	LoImPa2->SetTitle("Long Impact Parameter");
	LoImPa2->SetStats(kFALSE);
	LoImPa2 -> Draw("hist");//repeat for each mass point
	LoImPa5 -> Draw("same,hist");
	LoImPa10 -> Draw("same,hist");
	LoImPa15 -> Draw("same,hist");
	LoImPa20 -> Draw("same,hist");
	LoImPa30 -> Draw("same,hist");
	
	
	TLegend* legLip = new TLegend(0.85, 0.75, .75, .89);
	legLip->SetBorderSize(0);
	legLip->AddEntry(LoImPa2, "2 GeV", "L");//repeat for every mass point
	legLip->AddEntry(LoImPa5, "5 GeV", "L");
	legLip->AddEntry(LoImPa10, "10 GeV", "L");
	legLip->AddEntry(LoImPa15, "15 GeV", "L");
	legLip->AddEntry(LoImPa20, "20 GeV", "L");
	legLip->AddEntry(LoImPa30, "30 GeV", "L");
	legLip->Draw();
	canLoImPa->SaveAs("Long_Impact_Parameter.png");
	

	
	
// 	//////////////////////////////////////////////
// 	Neutrino Variables
// 	/////////////////////////////////////////////
	TH1 *Nu_2Pt = (TH1*)file2->Get("Neutrino_Met");//repeat for every mass point
	TH1 *Nu_5Pt = (TH1*)file5->Get("Neutrino_Met");
	TH1 *Nu_10Pt = (TH1*)file10->Get("Neutrino_Met");
	TH1 *Nu_15Pt = (TH1*)file15->Get("Neutrino_Met");
	TH1 *Nu_20Pt = (TH1*)file20->Get("Neutrino_Met");
	TH1 *Nu_30Pt = (TH1*)file30->Get("Neutrino_Met");
	
	Nu_2Pt -> SetLineColor(1);//repeat for every mass point
	Nu_5Pt -> SetLineColor(2);
	Nu_10Pt -> SetLineColor(3);
	Nu_15Pt -> SetLineColor(4);
	Nu_20Pt -> SetLineColor(5);
	Nu_30Pt -> SetLineColor(6);
	
	TCanvas * canNuPt = new TCanvas("canNuPt");
	canNuPt->cd();
	Nu_2Pt->SetTitle("Neutrino_Met");
	Nu_2Pt->SetStats(kFALSE);
	Nu_2Pt -> Draw("hist");//repeat for each mass point
	Nu_5Pt -> Draw("same,hist");
	Nu_10Pt -> Draw("same,hist");
	Nu_15Pt -> Draw("same,hist");
	Nu_20Pt -> Draw("same,hist");
	Nu_30Pt -> Draw("same,hist");
	
	TLegend* legNuPt = new TLegend(0.85, 0.75, .75, .89);
	legNuPt->SetBorderSize(0);
	legNuPt->AddEntry(Nu_2Pt, "2 GeV", "L");//repeat for every mass point
	legNuPt->AddEntry(Nu_5Pt, "5 GeV", "L");
	legNuPt->AddEntry(Nu_10Pt, "10 GeV", "L");
	legNuPt->AddEntry(Nu_15Pt, "15 GeV", "L");
	legNuPt->AddEntry(Nu_20Pt, "20 GeV", "L");
	legNuPt->AddEntry(Nu_30Pt, "30 GeV", "L");
	legNuPt->Draw();
	canNuPt->SaveAs("Neutrino_Met.png");
	
	
	
// 	//////////////////////////////////////////////
// 	Heavy Neutrino Variables
// 	/////////////////////////////////////////////
	TH1 *NRM_2Pt = (TH1*)file2->Get("NR_Mass");//repeat for every mass point
	TH1 *NRM_5Pt = (TH1*)file5->Get("NR_Mass");
	TH1 *NRM_10Pt = (TH1*)file10->Get("NR_Mass");
	TH1 *NRM_15Pt = (TH1*)file15->Get("NR_Mass");
	TH1 *NRM_20Pt = (TH1*)file20->Get("NR_Mass");
	TH1 *NRM_30Pt = (TH1*)file30->Get("NR_Mass");
	
	NRM_2Pt -> SetLineColor(1);//repeat for every mass point
	NRM_5Pt -> SetLineColor(2);
	NRM_10Pt -> SetLineColor(3);
	NRM_15Pt -> SetLineColor(4);
	NRM_20Pt -> SetLineColor(5);
	NRM_30Pt -> SetLineColor(6);
	
	TCanvas * canNRM = new TCanvas("canNRM");
	canNRM->cd();
	NRM_2Pt->SetTitle("Heavy Neutrino Mass");
	NRM_2Pt->SetStats(kFALSE);
	NRM_2Pt -> Draw("hist");//repeat for each mass point
	NRM_5Pt -> Draw("same,hist");
	NRM_10Pt -> Draw("same,hist");
	NRM_15Pt -> Draw("same,hist");
	NRM_20Pt -> Draw("same,hist");
	NRM_30Pt -> Draw("same,hist");
	
	TLegend* legNRM = new TLegend(0.85, 0.75, .75, .89);
	legNRM->SetBorderSize(0);
	legNRM->AddEntry(NRM_2Pt, "2 GeV", "L");//repeat for every mass point
	legNRM->AddEntry(NRM_5Pt, "5 GeV", "L");
	legNRM->AddEntry(NRM_10Pt, "10 GeV", "L");
	legNRM->AddEntry(NRM_15Pt, "15 GeV", "L");
	legNRM->AddEntry(NRM_20Pt, "20 GeV", "L");
	legNRM->AddEntry(NRM_30Pt, "30 GeV", "L");
	legNRM->Draw();
	canNRM->SaveAs("Heavy_Neutrino_Mass.png");
	
	
///////////////////////////////////////////////////////////////////////////////////////////////
//new method
///////////////////////////////////////////////////////////////////////////////////////////////
	
	
	/*TLegend* leglep1Pt = new TLegend(0.5, 0.5, 0.9, 0.9);
	leglep1Pt->SetBorderSize(0);
	leglep1Pt->SetLineColor(0);
	for (int i=1;i<7;i++)
	{
		TFile *f = TFile::Open(Form("file%i.root",i));
		
		TH1 *lep1Pt = (TH1*)f->Get("First_Lepton_Pt");
		lep1Pt -> SetLineColor(i);
		lep1Pt->SetStats(kFALSE);
		
		if (i==1)
		{
			TCanvas *canvas = new TCanvas("canvas");
			canvas->cd();
			lep1Pt->Draw("hist");
			leglep1Pt->AddEntry(lep1Pt, "2 GeV", "P");
		}
			else
			{
				lep1Pt->Draw("SAME,hist	");
				leglep1Pt->AddEntry(lep1Pt, "5 GeV", "P");
			}
	}*/
}








