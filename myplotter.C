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


void myplotterall()
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
// 	--------------------Pt------------------------------------------------------
	TH1 *L1_2Pt = (TH1*)file2->Get("First_Lepton_Pt");
	TH1 *L1_5Pt = (TH1*)file5->Get("First_Lepton_Pt");
	TH1 *L1_10Pt = (TH1*)file10->Get("First_Lepton_Pt");
	TH1 *L1_15Pt = (TH1*)file15->Get("First_Lepton_Pt");
	TH1 *L1_20Pt = (TH1*)file20->Get("First_Lepton_Pt");
	TH1 *L1_30Pt = (TH1*)file30->Get("First_Lepton_Pt");
	
	L1_2Pt -> SetLineColor(1);
	L1_5Pt -> SetLineColor(2);
	L1_10Pt -> SetLineColor(3);
	L1_15Pt -> SetLineColor(4);
	L1_20Pt -> SetLineColor(5);
	L1_30Pt -> SetLineColor(6);
	
	
	TCanvas * canL1Pt = new TCanvas("canL1Pt");	
	canL1Pt->cd();
	L1_2Pt->SetTitle("First_Lepton_Pt");
	L1_2Pt -> SetStats(kFALSE);
	L1_2Pt -> Draw("hist");
	L1_5Pt -> Draw("same,hist");
	L1_10Pt -> Draw("Same,hist");
	L1_15Pt -> Draw("Same,hist");
	L1_20Pt -> Draw("Same,hist");
	L1_30Pt -> Draw("Same,hist");
	
	TLegend *legL1Pt = new TLegend(.8, .7, 0.9, .898);
	legL1Pt->SetBorderSize(0);
// 	leg->SetLineColor(1);
// 	gStyle->SetFillColor(0);
// 	gStyle->SetCanvasColor(10);
	legL1Pt->AddEntry(L1_2Pt, "2 GeV", "L");
	legL1Pt->AddEntry(L1_5Pt, "5 GeV", "L");
	legL1Pt->AddEntry(L1_10Pt, "10 GeV", "L");
	legL1Pt->AddEntry(L1_15Pt, "15 GeV", "L");
	legL1Pt->AddEntry(L1_20Pt, "20 GeV", "L");
	legL1Pt->AddEntry(L1_30Pt, "30 GeV", "L");
	legL1Pt->Draw();
	canL1Pt->SaveAs("First_Lepton_Pt.png");
// 	--------------------------------------------------------------------------------------
	
// 	----------------------------------Eta-----------------------------------------------------
	TH1 *L1_2Eta = (TH1*)file2->Get("First_Lepton_Eta");
	TH1 *L1_5Eta = (TH1*)file5->Get("First_Lepton_Eta");
	TH1 *L1_10Eta = (TH1*)file10->Get("First_Lepton_Eta");
	TH1 *L1_15Eta = (TH1*)file15->Get("First_Lepton_Eta");
	TH1 *L1_20Eta = (TH1*)file20->Get("First_Lepton_Eta");
	TH1 *L1_30Eta = (TH1*)file30->Get("First_Lepton_Eta");
	
	L1_2Eta -> SetLineColor(1);
	L1_5Eta -> SetLineColor(2);
	L1_10Eta -> SetLineColor(3);
	L1_15Eta -> SetLineColor(4);
	L1_20Eta -> SetLineColor(5);
	L1_30Eta -> SetLineColor(6);
	
	
	TCanvas * canL1Eta = new TCanvas("canL1Eta");	
	canL1Eta->cd();
	L1_2Eta->SetTitle("First_Lepton_Eta");
	L1_2Eta -> SetStats(kFALSE);
	L1_2Eta -> Draw("hist");
	L1_5Eta -> Draw("same,hist");
	L1_10Eta -> Draw("Same,hist");
	L1_15Eta -> Draw("Same,hist");
	L1_20Eta -> Draw("Same,hist");
	L1_30Eta -> Draw("Same,hist");
	
	TLegend *legL1Eta = new TLegend(.8, .7, 0.9, .898);
	legL1Eta->SetBorderSize(0);
	legL1Eta->AddEntry(L1_2Eta, "2 GeV", "L");
	legL1Eta->AddEntry(L1_5Eta, "5 GeV", "L");
	legL1Eta->AddEntry(L1_10Eta, "10 GeV", "L");
	legL1Eta->AddEntry(L1_15Eta, "15 GeV", "L");
	legL1Eta->AddEntry(L1_20Eta, "20 GeV", "L");
	legL1Eta->AddEntry(L1_30Eta, "30 GeV", "L");
	legL1Eta->Draw();
	canL1Eta->SaveAs("First_Lepton_Eta.png");
// 	---------------------------------------------------------------------------------------	

// 	-------------------------------------Phi--------------------------------------------------
	TH1 *L1_2Phi = (TH1*)file2->Get("First_Lepton_Phi");
	TH1 *L1_5Phi = (TH1*)file5->Get("First_Lepton_Phi");
	TH1 *L1_10Phi = (TH1*)file10->Get("First_Lepton_Phi");
	TH1 *L1_15Phi = (TH1*)file15->Get("First_Lepton_Phi");
	TH1 *L1_20Phi = (TH1*)file20->Get("First_Lepton_Phi");
	TH1 *L1_30Phi = (TH1*)file30->Get("First_Lepton_Phi");
	
	L1_2Phi -> SetLineColor(1);
	L1_5Phi -> SetLineColor(2);
	L1_10Phi -> SetLineColor(3);
	L1_15Phi -> SetLineColor(4);
	L1_20Phi -> SetLineColor(5);
	L1_30Phi -> SetLineColor(6);
	
	
	TCanvas * canL1Phi = new TCanvas("canL1Phi");	
	canL1Phi->cd();
	L1_2Phi->SetTitle("First_Lepton_Phi");
	L1_2Phi -> SetStats(kFALSE);
	L1_2Phi -> Draw("hist");
	L1_5Phi -> Draw("same,hist");
	L1_10Phi -> Draw("Same,hist");
	L1_15Phi -> Draw("Same,hist");
	L1_20Phi -> Draw("Same,hist");
	L1_30Phi -> Draw("Same,hist");
	
	TLegend *legL1Phi = new TLegend(.8, .7, 0.9, .898);
	legL1Phi->SetBorderSize(0);
	legL1Phi->AddEntry(L1_2Phi, "2 GeV", "L");
	legL1Phi->AddEntry(L1_5Phi, "5 GeV", "L");
	legL1Phi->AddEntry(L1_10Phi, "10 GeV", "L");
	legL1Phi->AddEntry(L1_15Phi, "15 GeV", "L");
	legL1Phi->AddEntry(L1_20Phi, "20 GeV", "L");
	legL1Phi->AddEntry(L1_30Phi, "30 GeV", "L");
	legL1Phi->Draw();
	canL1Phi->SaveAs("First_Lepton_Phi.png");
// 	---------------------------------------------------------------------------------------

// 	//////////////////////////////////////////////
// 	Second lepton variables
// 	/////////////////////////////////////////////
// 	----------------------------Pt----------------------------------------------------
	TH1 *L2_2Pt = (TH1*)file2->Get("Second_Lepton_Pt");//repeat for every mass point
	TH1 *L2_5Pt = (TH1*)file5->Get("Second_Lepton_Pt");
	TH1 *L2_10Pt = (TH1*)file10->Get("Second_Lepton_Pt");
	TH1 *L2_15Pt = (TH1*)file15->Get("Second_Lepton_Pt");
	TH1 *L2_20Pt = (TH1*)file20->Get("Second_Lepton_Pt");
	TH1 *L2_30Pt = (TH1*)file30->Get("Second_Lepton_Pt");
	
	L2_2Pt -> SetLineColor(1);//repeat for every mass point
	L2_5Pt -> SetLineColor(2);
	L2_10Pt -> SetLineColor(3);
	L2_15Pt -> SetLineColor(4);
	L2_20Pt -> SetLineColor(5);
	L2_30Pt -> SetLineColor(6);
	
	TCanvas * canL2Pt = new TCanvas("canL2Pt");
	canL2Pt->cd();
	L2_2Pt->SetTitle("Second_Lepton_Pt");
	L2_2Pt->SetStats(kFALSE);
	L2_2Pt -> Draw("hist");//repeat for each mass point
	L2_5Pt -> Draw("same,hist");
	L2_10Pt -> Draw("same,hist");
	L2_15Pt -> Draw("same,hist");
	L2_20Pt -> Draw("same,hist");
	L2_30Pt -> Draw("same,hist");
	
	TLegend* legL2Pt = new TLegend(.8, .7, 0.9, .898);
	legL2Pt->SetBorderSize(0);
	legL2Pt->AddEntry(L2_2Pt, "2 GeV", "L");//repeat for every mass point
	legL2Pt->AddEntry(L2_5Pt, "5 GeV", "L");
	legL2Pt->AddEntry(L2_10Pt, "10 GeV", "L");
	legL2Pt->AddEntry(L2_15Pt, "15 GeV", "L");
	legL2Pt->AddEntry(L2_20Pt, "20 GeV", "L");
	legL2Pt->AddEntry(L2_30Pt, "30 GeV", "L");
	legL2Pt->Draw();
	canL2Pt->SaveAs("Second_Lepton_Pt.png");
// 	----------------------------------------------------------------------
	
// 	----------------------------Eta--------------------------------------
	TH1 *L2_2Eta = (TH1*)file2->Get("Second_Lepton_Eta");//repeat for every mass point
	TH1 *L2_5Eta = (TH1*)file5->Get("Second_Lepton_Eta");
	TH1 *L2_10Eta = (TH1*)file10->Get("Second_Lepton_Eta");
	TH1 *L2_15Eta = (TH1*)file15->Get("Second_Lepton_Eta");
	TH1 *L2_20Eta = (TH1*)file20->Get("Second_Lepton_Eta");
	TH1 *L2_30Eta = (TH1*)file30->Get("Second_Lepton_Eta");
	
	L2_2Eta -> SetLineColor(1);//repeat for every mass point
	L2_5Eta -> SetLineColor(2);
	L2_10Eta -> SetLineColor(3);
	L2_15Eta -> SetLineColor(4);
	L2_20Eta -> SetLineColor(5);
	L2_30Eta -> SetLineColor(6);
	
	TCanvas * canL2Eta = new TCanvas("canL2Eta");
	canL2Eta->cd();
	L2_2Eta->SetTitle("Second_Lepton_Eta");
	L2_2Eta->SetStats(kFALSE);
	L2_2Eta -> Draw("hist");//repeat for each mass point
	L2_5Eta -> Draw("same,hist");
	L2_10Eta -> Draw("same,hist");
	L2_15Eta -> Draw("same,hist");
	L2_20Eta -> Draw("same,hist");
	L2_30Eta -> Draw("same,hist");
	
	TLegend* legL2Eta = new TLegend(.8, .7, 0.9, .898);
	legL2Eta->SetBorderSize(0);
	legL2Eta->AddEntry(L2_2Eta, "2 GeV", "L");//repeat for every mass point
	legL2Eta->AddEntry(L2_5Eta, "5 GeV", "L");
	legL2Eta->AddEntry(L2_10Eta, "10 GeV", "L");
	legL2Eta->AddEntry(L2_15Eta, "15 GeV", "L");
	legL2Eta->AddEntry(L2_20Eta, "20 GeV", "L");
	legL2Eta->AddEntry(L2_30Eta, "30 GeV", "L");
	legL2Eta->Draw();
	canL2Eta->SaveAs("Second_Lepton_Eta.png");
// 	---------------------------------------------------------------------
	
// 	-------------------------------Phi------------------------------------
	TH1 *L2_2Phi = (TH1*)file2->Get("Second_Lepton_Phi");//repeat for every mass point
	TH1 *L2_5Phi = (TH1*)file5->Get("Second_Lepton_Phi");
	TH1 *L2_10Phi = (TH1*)file10->Get("Second_Lepton_Phi");
	TH1 *L2_15Phi = (TH1*)file15->Get("Second_Lepton_Phi");
	TH1 *L2_20Phi = (TH1*)file20->Get("Second_Lepton_Phi");
	TH1 *L2_30Phi = (TH1*)file30->Get("Second_Lepton_Phi");
	
	L2_2Phi -> SetLineColor(1);//repeat for every mass point
	L2_5Phi -> SetLineColor(2);
	L2_10Phi -> SetLineColor(3);
	L2_15Phi -> SetLineColor(4);
	L2_20Phi -> SetLineColor(5);
	L2_30Phi -> SetLineColor(6);
	
	TCanvas * canL2Phi = new TCanvas("canL2Phi");
	canL2Phi->cd();
	L2_2Phi->SetTitle("Second_Lepton_Phi");
	L2_2Phi->SetStats(kFALSE);
	L2_2Phi -> Draw("hist");//repeat for each mass point
	L2_5Phi -> Draw("same,hist");
	L2_10Phi -> Draw("same,hist");
	L2_15Phi -> Draw("same,hist");
	L2_20Phi -> Draw("same,hist");
	L2_30Phi -> Draw("same,hist");
	
	TLegend* legL2Phi = new TLegend(.8, .7, 0.9, .898);
	legL2Phi->SetBorderSize(0);
	legL2Phi->AddEntry(L2_2Phi, "2 GeV", "L");//repeat for every mass point
	legL2Phi->AddEntry(L2_5Phi, "5 GeV", "L");
	legL2Phi->AddEntry(L2_10Phi, "10 GeV", "L");
	legL2Phi->AddEntry(L2_15Phi, "15 GeV", "L");
	legL2Phi->AddEntry(L2_20Phi, "20 GeV", "L");
	legL2Phi->AddEntry(L2_30Phi, "30 GeV", "L");
	legL2Phi->Draw();
	canL2Phi->SaveAs("Second_Lepton_Phi.png");
// 	----------------------------------------------------------------------
	
	
// 	//////////////////////////////////////////////
// 	Third lepton variables
// 	/////////////////////////////////////////////
// 	----------------------------Pt----------------------------------------------------
	TH1 *L3_2Pt = (TH1*)file2->Get("Third_Lepton_Pt");//repeat for every mass point
	TH1 *L3_5Pt = (TH1*)file5->Get("Third_Lepton_Pt");
	TH1 *L3_10Pt = (TH1*)file10->Get("Third_Lepton_Pt");
	TH1 *L3_15Pt = (TH1*)file15->Get("Third_Lepton_Pt");
	TH1 *L3_20Pt = (TH1*)file20->Get("Third_Lepton_Pt");
	TH1 *L3_30Pt = (TH1*)file30->Get("Third_Lepton_Pt");
	
	L3_2Pt -> SetLineColor(1);//repeat for every mass point
	L3_5Pt -> SetLineColor(2);
	L3_10Pt -> SetLineColor(3);
	L3_15Pt -> SetLineColor(4);
	L3_20Pt -> SetLineColor(5);
	L3_30Pt -> SetLineColor(6);
	
	TCanvas * canL3Pt = new TCanvas("canL3Pt");
	canL3Pt->cd();
	L3_2Pt->SetTitle("Third_Lepton_Pt");
	L3_2Pt->SetStats(kFALSE);
	L3_2Pt -> Draw("hist");//repeat for each mass point
	L3_5Pt -> Draw("same,hist");
	L3_10Pt -> Draw("same,hist");
	L3_15Pt -> Draw("same,hist");
	L3_20Pt -> Draw("same,hist");
	L3_30Pt -> Draw("same,hist");
	
	TLegend* legL3Pt = new TLegend(.8, .7, 0.9, .898);
	legL3Pt->SetBorderSize(0);
	legL3Pt->AddEntry(L3_2Pt, "2 GeV", "L");//repeat for every mass point
	legL3Pt->AddEntry(L3_5Pt, "5 GeV", "L");
	legL3Pt->AddEntry(L3_10Pt, "10 GeV", "L");
	legL3Pt->AddEntry(L3_15Pt, "15 GeV", "L");
	legL3Pt->AddEntry(L3_20Pt, "20 GeV", "L");
	legL3Pt->AddEntry(L3_30Pt, "30 GeV", "L");
	legL3Pt->Draw();
	canL3Pt->SaveAs("Third_Lepton_Pt.png");
// 	----------------------------------------------------------------------
	
// 	----------------------------Eta--------------------------------------
	TH1 *L3_2Eta = (TH1*)file2->Get("Third_Lepton_Eta");//repeat for every mass point
	TH1 *L3_5Eta = (TH1*)file5->Get("Third_Lepton_Eta");
	TH1 *L3_10Eta = (TH1*)file10->Get("Third_Lepton_Eta");
	TH1 *L3_15Eta = (TH1*)file15->Get("Third_Lepton_Eta");
	TH1 *L3_20Eta = (TH1*)file20->Get("Third_Lepton_Eta");
	TH1 *L3_30Eta = (TH1*)file30->Get("Third_Lepton_Eta");
	
	L3_2Eta -> SetLineColor(1);//repeat for every mass point
	L3_5Eta -> SetLineColor(2);
	L3_10Eta -> SetLineColor(3);
	L3_15Eta -> SetLineColor(4);
	L3_20Eta -> SetLineColor(5);
	L3_30Eta -> SetLineColor(6);
	
	TCanvas * canL3Eta = new TCanvas("canLep3Eta");
	canL3Eta->cd();
	L3_2Eta->SetTitle("Third_Lepton_Eta");
	L3_2Eta->SetStats(kFALSE);
	L3_2Eta -> Draw("hist");//repeat for each mass point
	L3_5Eta -> Draw("same,hist");
	L3_10Eta -> Draw("same,hist");
	L3_15Eta -> Draw("same,hist");
	L3_20Eta -> Draw("same,hist");
	L3_30Eta -> Draw("same,hist");
	
	TLegend* legL3Eta = new TLegend(.8, .7, 0.9, .898);
	legL3Eta->SetBorderSize(0);
	legL3Eta->AddEntry(L3_2Eta, "2 GeV", "L");//repeat for every mass point
	legL3Eta->AddEntry(L3_5Eta, "5 GeV", "L");
	legL3Eta->AddEntry(L3_10Eta, "10 GeV", "L");
	legL3Eta->AddEntry(L3_15Eta, "15 GeV", "L");
	legL3Eta->AddEntry(L3_20Eta, "20 GeV", "L");
	legL3Eta->AddEntry(L3_30Eta, "30 GeV", "L");
	legL3Eta->Draw();
	canL3Eta->SaveAs("Third_Lepton_Eta.png");
// 	---------------------------------------------------------------------
	
// 	-------------------------------Phi------------------------------------
	TH1 *L3_2Phi = (TH1*)file2->Get("Third_Lepton_Phi");//repeat for every mass point
	TH1 *L3_5Phi = (TH1*)file5->Get("Third_Lepton_Phi");
	TH1 *L3_10Phi = (TH1*)file10->Get("Third_Lepton_Phi");
	TH1 *L3_15Phi = (TH1*)file15->Get("Third_Lepton_Phi");
	TH1 *L3_20Phi = (TH1*)file20->Get("Third_Lepton_Phi");
	TH1 *L3_30Phi = (TH1*)file30->Get("Third_Lepton_Phi");
	
	L3_2Phi -> SetLineColor(1);//repeat for every mass point
	L3_5Phi -> SetLineColor(2);
	L3_10Phi -> SetLineColor(3);
	L3_15Phi -> SetLineColor(4);
	L3_20Phi -> SetLineColor(5);
	L3_30Phi -> SetLineColor(6);
	
	TCanvas * canL3Phi = new TCanvas("canLep3Phi");
	canL3Phi->cd();
	L3_2Phi->SetTitle("Third_Lepton_Phi");
	L3_2Phi->SetStats(kFALSE);
	L3_2Phi -> Draw("hist");//repeat for each mass point
	L3_5Phi -> Draw("same,hist");
	L3_10Phi -> Draw("same,hist");
	L3_15Phi -> Draw("same,hist");
	L3_20Phi -> Draw("same,hist");
	L3_30Phi -> Draw("same,hist");
	
	TLegend* legL3Phi = new TLegend(.8, .7, 0.9, .898);
	legL3Phi->SetBorderSize(0);
	legL3Phi->AddEntry(L3_2Phi, "2 GeV", "L");//repeat for every mass point
	legL3Phi->AddEntry(L3_5Phi, "5 GeV", "L");
	legL3Phi->AddEntry(L3_10Phi, "10 GeV", "L");
	legL3Phi->AddEntry(L3_15Phi, "15 GeV", "L");
	legL3Phi->AddEntry(L3_20Phi, "20 GeV", "L");
	legL3Phi->AddEntry(L3_30Phi, "30 GeV", "L");
	legL3Phi->Draw();
	canL3Phi->SaveAs("Third_Lepton_Phi.png");
// 	----------------------------------------------------------------------
	
	
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
	TrImPa2->SetAxisRange(-1.1,1.1);
	TrImPa2 -> Draw("hist");
	TrImPa5 -> Draw("same,hist");
	TrImPa10 -> Draw("same,hist");
	TrImPa15 -> Draw("same,hist");
	TrImPa20 -> Draw("same,hist");
	TrImPa30 -> Draw("same,hist");
	
	TLegend* leg1 = new TLegend(.8, .7, 0.9, .898);
	leg1->SetBorderSize(0);
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
	LoImPa2->SetAxisRange(-1.1,1.1);
	LoImPa2 -> Draw("hist");//repeat for each mass point
	LoImPa5 -> Draw("same,hist");
	LoImPa10 -> Draw("same,hist");
	LoImPa15 -> Draw("same,hist");
	LoImPa20 -> Draw("same,hist");
	LoImPa30 -> Draw("same,hist");
	
	
	TLegend* legLip = new TLegend(.8, .7, 0.9, .898);
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
// 	-----------------------------Met--------------------------------------
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
	Nu_2Pt->SetAxisRange(-1.5,100.);
	Nu_2Pt->SetStats(kFALSE);
	Nu_2Pt -> Draw("hist");//repeat for each mass point
	Nu_5Pt -> Draw("same,hist");
	Nu_10Pt -> Draw("same,hist");
	Nu_15Pt -> Draw("same,hist");
	Nu_20Pt -> Draw("same,hist");
	Nu_30Pt -> Draw("same,hist");
	
	TLegend* legNuPt = new TLegend(.8, .7, 0.9, .898);
	legNuPt->SetBorderSize(0);
	legNuPt->AddEntry(Nu_2Pt, "2 GeV", "L");//repeat for every mass point
	legNuPt->AddEntry(Nu_5Pt, "5 GeV", "L");
	legNuPt->AddEntry(Nu_10Pt, "10 GeV", "L");
	legNuPt->AddEntry(Nu_15Pt, "15 GeV", "L");
	legNuPt->AddEntry(Nu_20Pt, "20 GeV", "L");
	legNuPt->AddEntry(Nu_30Pt, "30 GeV", "L");
	legNuPt->Draw();
	canNuPt->SaveAs("Neutrino_Met.png");
// 	----------------------------------
	
// 	-----------------------Eta----------------------------------------
	TH1 *Nu_2Eta = (TH1*)file2->Get("Neutrino_Eta");//repeat for every mass point
	TH1 *Nu_5Eta = (TH1*)file5->Get("Neutrino_Eta");
	TH1 *Nu_10Eta = (TH1*)file10->Get("Neutrino_Eta");
	TH1 *Nu_15Eta = (TH1*)file15->Get("Neutrino_Eta");
	TH1 *Nu_20Eta = (TH1*)file20->Get("Neutrino_Eta");
	TH1 *Nu_30Eta = (TH1*)file30->Get("Neutrino_Eta");
	
	Nu_2Eta -> SetLineColor(1);//repeat for every mass point
	Nu_5Eta -> SetLineColor(2);
	Nu_10Eta -> SetLineColor(3);
	Nu_15Eta -> SetLineColor(4);
	Nu_20Eta -> SetLineColor(5);
	Nu_30Eta -> SetLineColor(6);
	
	TCanvas * canNuEta = new TCanvas("canNuEta");
	canNuEta->cd();
	Nu_2Eta->SetTitle("Neutrino_Eta");
	Nu_2Eta->SetStats(kFALSE);
	Nu_2Eta -> Draw("hist");//repeat for each mass point
	Nu_5Eta -> Draw("same,hist");
	Nu_10Eta -> Draw("same,hist");
	Nu_15Eta -> Draw("same,hist");
	Nu_20Eta -> Draw("same,hist");
	Nu_30Eta -> Draw("same,hist");
	
	TLegend* legNuEta = new TLegend(.8, .7, 0.9, .898);
	legNuEta->SetBorderSize(0);
	legNuEta->AddEntry(Nu_2Eta, "2 GeV", "L");//repeat for every mass point
	legNuEta->AddEntry(Nu_5Eta, "5 GeV", "L");
	legNuEta->AddEntry(Nu_10Eta, "10 GeV", "L");
	legNuEta->AddEntry(Nu_15Eta, "15 GeV", "L");
	legNuEta->AddEntry(Nu_20Eta, "20 GeV", "L");
	legNuEta->AddEntry(Nu_30Eta, "30 GeV", "L");
	legNuEta->Draw();
	canNuEta->SaveAs("Neutrino_Eta.png");
// 	------------------------------------------------------------------------------
	
// 	--------------------------------Phi----------------------------------------
	TH1 *Nu_2Phi = (TH1*)file2->Get("Neutrino_Phi");//repeat for every mass point
	TH1 *Nu_5Phi = (TH1*)file5->Get("Neutrino_Phi");
	TH1 *Nu_10Phi = (TH1*)file10->Get("Neutrino_Phi");
	TH1 *Nu_15Phi = (TH1*)file15->Get("Neutrino_Phi");
	TH1 *Nu_20Phi = (TH1*)file20->Get("Neutrino_Phi");
	TH1 *Nu_30Phi = (TH1*)file30->Get("Neutrino_Phi");
	
	Nu_2Phi -> SetLineColor(1);//repeat for every mass point
	Nu_5Phi -> SetLineColor(2);
	Nu_10Phi -> SetLineColor(3);
	Nu_15Phi -> SetLineColor(4);
	Nu_20Phi -> SetLineColor(5);
	Nu_30Phi -> SetLineColor(6);
	
	TCanvas * canNuPhi = new TCanvas("canNuPhi");
	canNuPhi->cd();
	Nu_2Phi->SetTitle("Neutrino_Phi");
	Nu_2Phi->SetStats(kFALSE);
	Nu_2Phi->SetAxisRange(-5.0,5);
	Nu_2Phi -> Draw("hist");//repeat for each mass point
	Nu_5Phi -> Draw("same,hist");
	Nu_10Phi -> Draw("same,hist");
	Nu_15Phi -> Draw("same,hist");
	Nu_20Phi -> Draw("same,hist");
	Nu_30Phi -> Draw("same,hist");
	
	TLegend* legNuPhi = new TLegend(.8, .7, 0.9, .898);//Tlegend(X_starts, Y_start, 
	legNuPhi->SetBorderSize(0);
	legNuPhi->AddEntry(Nu_2Phi, "2 GeV", "L");//repeat for every mass point
	legNuPhi->AddEntry(Nu_5Phi, "5 GeV", "L");
	legNuPhi->AddEntry(Nu_10Phi, "10 GeV", "L");
	legNuPhi->AddEntry(Nu_15Phi, "15 GeV", "L");
	legNuPhi->AddEntry(Nu_20Phi, "20 GeV", "L");
	legNuPhi->AddEntry(Nu_30Phi, "30 GeV", "L");
	legNuPhi->Draw();
	canNuPhi->SaveAs("Neutrino_Phi.png");
// 	---------------------------------------------------------------------------
	
	
// 	//////////////////////////////////////////////
// 	Heavy Neutrino Variables
// 	/////////////////////////////////////////////
// ------------------------------------------------------
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
// 	NRM_2Pt->SetRangeUser(-10,60);
	NRM_2Pt->SetStats(kFALSE);
	NRM_2Pt -> Draw("hist");//repeat for each mass point
	NRM_5Pt -> Draw("same,hist");
	NRM_10Pt -> Draw("same,hist");
	NRM_15Pt -> Draw("same,hist");
	NRM_20Pt -> Draw("same,hist");
	NRM_30Pt -> Draw("same,hist");
	
	TLegend* legNRM = new TLegend(.8, .7, 0.9, .898);
	legNRM->SetBorderSize(0);
	legNRM->AddEntry(NRM_2Pt, "2 GeV", "L");//repeat for every mass point
	legNRM->AddEntry(NRM_5Pt, "5 GeV", "L");
	legNRM->AddEntry(NRM_10Pt, "10 GeV", "L");
	legNRM->AddEntry(NRM_15Pt, "15 GeV", "L");
	legNRM->AddEntry(NRM_20Pt, "20 GeV", "L");
	legNRM->AddEntry(NRM_30Pt, "30 GeV", "L");
	legNRM->Draw();
	canNRM->SaveAs("Heavy_Neutrino_Mass.png");
	
	
	// 	//////////////////////////////////////////////
// 	W Mass Variables
// 	/////////////////////////////////////////////
// ------------------------------------------------------
	TH1 *WM_2Pt = (TH1*)file2->Get("W_Mass");//repeat for every mass point
	TH1 *WM_5Pt = (TH1*)file5->Get("W_Mass");
	TH1 *WM_10Pt = (TH1*)file10->Get("W_Mass");
	TH1 *WM_15Pt = (TH1*)file15->Get("W_Mass");
	TH1 *WM_20Pt = (TH1*)file20->Get("W_Mass");
	TH1 *WM_30Pt = (TH1*)file30->Get("W_Mass");
	
	WM_2Pt -> SetLineColor(1);//repeat for every mass point
	WM_5Pt -> SetLineColor(2);
	WM_10Pt -> SetLineColor(3);
	WM_15Pt -> SetLineColor(4);
	WM_20Pt -> SetLineColor(5);
	WM_30Pt -> SetLineColor(6);
	
	TCanvas * canWM = new TCanvas("canWM");
	canWM->cd();
	WM_2Pt->SetTitle("W Mass");
// 	WM_2Pt->SetRangeUser(-10,60);
	WM_2Pt->SetStats(kFALSE);
	WM_2Pt -> Draw("hist");//repeat for each mass point
	WM_5Pt -> Draw("same,hist");
	WM_10Pt -> Draw("same,hist");
	WM_15Pt -> Draw("same,hist");
	WM_20Pt -> Draw("same,hist");
	WM_30Pt -> Draw("same,hist");
	
	TLegend* legWM = new TLegend(.8, .7, 0.9, .898);
	legWM->SetBorderSize(0);
	legWM->AddEntry(WM_2Pt, "2 GeV", "L");//repeat for every mass point
	legWM->AddEntry(WM_5Pt, "5 GeV", "L");
	legWM->AddEntry(WM_10Pt, "10 GeV", "L");
	legWM->AddEntry(WM_15Pt, "15 GeV", "L");
	legWM->AddEntry(WM_20Pt, "20 GeV", "L");
	legWM->AddEntry(WM_30Pt, "30 GeV", "L");
	legWM->Draw();
	canWM->SaveAs("W_Mass.png");
	
	
///////////////////////////////////////////////////////////////////////////////////////////////
//new method
///////////////////////////////////////////////////////////////////////////////////////////////
	
	
	/*TLegend* leglep1Pt = new TLegend(.8, .7, 0.898, .898);
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

void myplotterone()
{
	TFile* file = TFile::Open("hst_val.root");
	TH1 *L1_Pt = (TH1*)file->Get("First_Lepton_Pt");
	TH1 *L1_Eta = (TH1*)file->Get("First_Lepton_Eta");
	TH1 *TrImPa = (TH1*)file->Get("Transverse_Impact_Parameter");
	TH1 *LoImPa = (TH1*)file->Get("Long_Impact_Parameter");
	TCanvas * can1 = new TCanvas("can1");
	can1->cd();
	LoImPa->Draw("hist");
	TCanvas * can2 = new TCanvas("can2");
	TrImPa->Draw("hist");
	
	cout<<"si"<<endl;
}

void myplottermixing()
{
	
	TFile* file1 = TFile::Open("hst_RHN_13TeV_2GeV_1tom5Mix.root");
	TFile* file2 = TFile::Open("hst_RHN_13TeV_2GeV_5tom5Mix.root");
	TFile* file3 = TFile::Open("hst_RHN_13TeV_2GeV_1tom6Mix.root");
	TFile* file4 = TFile::Open("hst_RHN_13TeV_2GeV_5tom6Mix.root");
	TFile* file5 = TFile::Open("hst_RHN_13TeV_2GeV_1tom7Mix.root");
// 	TFile* file6 = TFile::Open("hst_RHN_13TeV_10GeV_10Mix.root");
	
	/*
// 	//////////////////////////////////////////////////////////////
// 	First_Lepton Variables
// 	/////////////////////////////////////////////////
// 	--------------------Pt------------------------------------------------------
	TH1 *L1_2Pt = (TH1*)file2->Get("First_Lepton_Pt");
	TH1 *L1_5Pt = (TH1*)file5->Get("First_Lepton_Pt");
	TH1 *L1_10Pt = (TH1*)file10->Get("First_Lepton_Pt");
		
	L1_2Pt -> SetLineColor(1);
	L1_5Pt -> SetLineColor(2);
	L1_10Pt -> SetLineColor(3);
		
	TCanvas * canL1Pt = new TCanvas("canL1Pt");	
	canL1Pt->cd();
	L1_2Pt->SetTitle("First_Lepton_Pt");
	L1_2Pt -> SetStats(kFALSE);
	L1_2Pt -> Draw("hist");
	L1_5Pt -> Draw("same,hist");
	L1_10Pt -> Draw("Same,hist");
	
	TLegend *legL1Pt = new TLegend(.8, .7, 0.9, .898);
	legL1Pt->SetBorderSize(0);
// 	leg->SetLineColor(1);
// 	gStyle->SetFillColor(0);
// 	gStyle->SetCanvasColor(10);
	legL1Pt->AddEntry(L1_2Pt, "10 ", "L");
	legL1Pt->AddEntry(L1_5Pt, "5 ", "L");
	legL1Pt->AddEntry(L1_10Pt, "1 ", "L");
	legL1Pt->Draw();
	canL1Pt->SaveAs("First_Lepton_Pt_mix.png");
// 	--------------------------------------------------------------------------------------
	
// 	----------------------------------Eta-----------------------------------------------------
	TH1 *L1_2Eta = (TH1*)file2->Get("First_Lepton_Eta");
	TH1 *L1_5Eta = (TH1*)file5->Get("First_Lepton_Eta");
	TH1 *L1_10Eta = (TH1*)file10->Get("First_Lepton_Eta");
	
	L1_2Eta -> SetLineColor(1);
	L1_5Eta -> SetLineColor(2);
	L1_10Eta -> SetLineColor(3);
		
	TCanvas * canL1Eta = new TCanvas("canL1Eta");	
	canL1Eta->cd();
	L1_2Eta->SetTitle("First_Lepton_Eta");
	L1_2Eta -> SetStats(kFALSE);
	L1_2Eta -> Draw("hist");
	L1_5Eta -> Draw("same,hist");
	L1_10Eta -> Draw("Same,hist");
	
	TLegend *legL1Eta = new TLegend(.8, .7, 0.9, .898);
	legL1Eta->SetBorderSize(0);
	legL1Eta->AddEntry(L1_2Eta, "10 ", "L");
	legL1Eta->AddEntry(L1_5Eta, "5 ", "L");
	legL1Eta->AddEntry(L1_10Eta, "1 ", "L");
	legL1Eta->Draw();
	canL1Eta->SaveAs("First_Lepton_Eta_mix.png");
// 	---------------------------------------------------------------------------------------	

// 	-------------------------------------Phi--------------------------------------------------
	TH1 *L1_2Phi = (TH1*)file2->Get("First_Lepton_Phi");
	TH1 *L1_5Phi = (TH1*)file5->Get("First_Lepton_Phi");
	TH1 *L1_10Phi = (TH1*)file10->Get("First_Lepton_Phi");
		
	L1_2Phi -> SetLineColor(1);
	L1_5Phi -> SetLineColor(2);
	L1_10Phi -> SetLineColor(3);
	
	TCanvas * canL1Phi = new TCanvas("canL1Phi");	
	canL1Phi->cd();
	L1_2Phi->SetTitle("First_Lepton_Phi");
	L1_2Phi -> SetStats(kFALSE);
	L1_2Phi -> Draw("hist");
	L1_5Phi -> Draw("same,hist");
	L1_10Phi -> Draw("Same,hist");
	
	TLegend *legL1Phi = new TLegend(.8, .7, 0.9, .898);
	legL1Phi->SetBorderSize(0);
	legL1Phi->AddEntry(L1_2Phi, "10 ", "L");
	legL1Phi->AddEntry(L1_5Phi, "5 ", "L");
	legL1Phi->AddEntry(L1_10Phi, "1 ", "L");
	legL1Phi->Draw();
	canL1Phi->SaveAs("First_Lepton_Phi_mix.png");
// 	---------------------------------------------------------------------------------------
	
// 	//////////////////////////////////////////////
// 	Second lepton variables
// 	/////////////////////////////////////////////
// 	----------------------------Pt----------------------------------------------------
	TH1 *L2_2Pt = (TH1*)file2->Get("Second_Lepton_Pt");//repeat for every mass point
	TH1 *L2_5Pt = (TH1*)file5->Get("Second_Lepton_Pt");
	TH1 *L2_10Pt = (TH1*)file10->Get("Second_Lepton_Pt");
	
	L2_2Pt -> SetLineColor(1);//repeat for every mass point
	L2_5Pt -> SetLineColor(2);
	L2_10Pt -> SetLineColor(3);
	
	TCanvas * canL2Pt = new TCanvas("canL2Pt");
	canL2Pt->cd();
	L2_2Pt->SetTitle("Second_Lepton_Pt");
	L2_2Pt->SetStats(kFALSE);
	L2_2Pt -> Draw("hist");//repeat for each mass point
	L2_5Pt -> Draw("same,hist");
	L2_10Pt -> Draw("same,hist");
	
	TLegend* legL2Pt = new TLegend(.8, .7, 0.9, .898);
	legL2Pt->SetBorderSize(0);
	legL2Pt->AddEntry(L2_2Pt, "10 ", "L");//repeat for every mass point
	legL2Pt->AddEntry(L2_5Pt, "5 ", "L");
	legL2Pt->AddEntry(L2_10Pt, "1 ", "L");
	legL2Pt->Draw();
	canL2Pt->SaveAs("Second_Lepton_Pt_mix.png");
// 	----------------------------------------------------------------------

// 	----------------------------Eta--------------------------------------
	TH1 *L2_2Eta = (TH1*)file2->Get("Second_Lepton_Eta");//repeat for every mass point
	TH1 *L2_5Eta = (TH1*)file5->Get("Second_Lepton_Eta");
	TH1 *L2_10Eta = (TH1*)file10->Get("Second_Lepton_Eta");
	
	L2_2Eta -> SetLineColor(1);//repeat for every mass point
	L2_5Eta -> SetLineColor(2);
	L2_10Eta -> SetLineColor(3);
		
	TCanvas * canL2Eta = new TCanvas("canL2Eta");
	canL2Eta->cd();
	L2_2Eta->SetTitle("Second_Lepton_Eta");
	L2_2Eta->SetStats(kFALSE);
	L2_2Eta -> Draw("hist");//repeat for each mass point
	L2_5Eta -> Draw("same,hist");
	L2_10Eta -> Draw("same,hist");
		
	TLegend* legL2Eta = new TLegend(.8, .7, 0.9, .898);
	legL2Eta->SetBorderSize(0);
	legL2Eta->AddEntry(L2_2Eta, "10 ", "L");//repeat for every mass point
	legL2Eta->AddEntry(L2_5Eta, "5 ", "L");
	legL2Eta->AddEntry(L2_10Eta, "1 ", "L");
	legL2Eta->Draw();
	canL2Eta->SaveAs("Second_Lepton_Eta_mix.png");
// 	---------------------------------------------------------------------
	
// 	-------------------------------Phi------------------------------------
	TH1 *L2_2Phi = (TH1*)file2->Get("Second_Lepton_Phi");//repeat for every mass point
	TH1 *L2_5Phi = (TH1*)file5->Get("Second_Lepton_Phi");
	TH1 *L2_10Phi = (TH1*)file10->Get("Second_Lepton_Phi");
		
	L2_2Phi -> SetLineColor(1);//repeat for every mass point
	L2_5Phi -> SetLineColor(2);
	L2_10Phi -> SetLineColor(3);
		
	TCanvas * canL2Phi = new TCanvas("canL2Phi");
	canL2Phi->cd();
	L2_2Phi->SetTitle("Second_Lepton_Phi");
	L2_2Phi->SetStats(kFALSE);
	L2_2Phi -> Draw("hist");//repeat for each mass point
	L2_5Phi -> Draw("same,hist");
	L2_10Phi -> Draw("same,hist");
		
	TLegend* legL2Phi = new TLegend(.8, .7, 0.9, .898);
	legL2Phi->SetBorderSize(0);
	legL2Phi->AddEntry(L2_2Phi, "10 ", "L");//repeat for every mass point
	legL2Phi->AddEntry(L2_5Phi, "5 ", "L");
	legL2Phi->AddEntry(L2_10Phi, "1 ", "L");
	legL2Phi->Draw();
	canL2Phi->SaveAs("Second_Lepton_Phi_mix.png");
// 	----------------------------------------------------------------------
	
// 	//////////////////////////////////////////////
// 	Third lepton variables
// 	/////////////////////////////////////////////
// 	----------------------------Pt----------------------------------------------------
	TH1 *L3_2Pt = (TH1*)file2->Get("Third_Lepton_Pt");//repeat for every mass point
	TH1 *L3_5Pt = (TH1*)file5->Get("Third_Lepton_Pt");
	TH1 *L3_10Pt = (TH1*)file10->Get("Third_Lepton_Pt");
		
	L3_2Pt -> SetLineColor(1);//repeat for every mass point
	L3_5Pt -> SetLineColor(2);
	L3_10Pt -> SetLineColor(3);
		
	TCanvas * canL3Pt = new TCanvas("canL3Pt");
	canL3Pt->cd();
	L3_2Pt->SetTitle("Third_Lepton_Pt");
	L3_2Pt->SetStats(kFALSE);
	L3_2Pt -> Draw("hist");//repeat for each mass point
	L3_5Pt -> Draw("same,hist");
	L3_10Pt -> Draw("same,hist");
		
	TLegend* legL3Pt = new TLegend(.8, .7, 0.9, .898);
	legL3Pt->SetBorderSize(0);
	legL3Pt->AddEntry(L3_2Pt, "10 ", "L");//repeat for every mass point
	legL3Pt->AddEntry(L3_5Pt, "5 ", "L");
	legL3Pt->AddEntry(L3_10Pt, "1 ", "L");
	legL3Pt->Draw();
	canL3Pt->SaveAs("Third_Lepton_Pt_mix.png");
// 	----------------------------------------------------------------------
	
// 	----------------------------Eta--------------------------------------
	TH1 *L3_2Eta = (TH1*)file2->Get("Third_Lepton_Eta");//repeat for every mass point
	TH1 *L3_5Eta = (TH1*)file5->Get("Third_Lepton_Eta");
	TH1 *L3_10Eta = (TH1*)file10->Get("Third_Lepton_Eta");
	
	L3_2Eta -> SetLineColor(1);//repeat for every mass point
	L3_5Eta -> SetLineColor(2);
	L3_10Eta -> SetLineColor(3);
	
	TCanvas * canL3Eta = new TCanvas("canLep3Eta");
	canL3Eta->cd();
	L3_2Eta->SetTitle("Third_Lepton_Eta");
	L3_2Eta->SetStats(kFALSE);
	L3_2Eta -> Draw("hist");//repeat for each mass point
	L3_5Eta -> Draw("same,hist");
	L3_10Eta -> Draw("same,hist");
	
	TLegend* legL3Eta = new TLegend(.8, .7, 0.9, .898);
	legL3Eta->SetBorderSize(0);
	legL3Eta->AddEntry(L3_2Eta, "10 ", "L");//repeat for every mass point
	legL3Eta->AddEntry(L3_5Eta, "5 ", "L");
	legL3Eta->AddEntry(L3_10Eta, "1 ", "L");
	legL3Eta->Draw();
	canL3Eta->SaveAs("Third_Lepton_Eta_mix.png");
// 	---------------------------------------------------------------------
	
// 	-------------------------------Phi------------------------------------
	TH1 *L3_2Phi = (TH1*)file2->Get("Third_Lepton_Phi");//repeat for every mass point
	TH1 *L3_5Phi = (TH1*)file5->Get("Third_Lepton_Phi");
	TH1 *L3_10Phi = (TH1*)file10->Get("Third_Lepton_Phi");
	
	L3_2Phi -> SetLineColor(1);//repeat for every mass point
	L3_5Phi -> SetLineColor(2);
	L3_10Phi -> SetLineColor(3);
		
	TCanvas * canL3Phi = new TCanvas("canLep3Phi");
	canL3Phi->cd();
	L3_2Phi->SetTitle("Third_Lepton_Phi");
	L3_2Phi->SetStats(kFALSE);
	L3_2Phi -> Draw("hist");//repeat for each mass point
	L3_5Phi -> Draw("same,hist");
	L3_10Phi -> Draw("same,hist");
	
	TLegend* legL3Phi = new TLegend(.8, .7, 0.9, .898);
	legL3Phi->SetBorderSize(0);
	legL3Phi->AddEntry(L3_2Phi, "10 ", "L");//repeat for every mass point
	legL3Phi->AddEntry(L3_5Phi, "5 ", "L");
	legL3Phi->AddEntry(L3_10Phi, "1 ", "L");
	legL3Phi->Draw();
	canL3Phi->SaveAs("Third_Lepton_Phi_mix.png");
// 	----------------------------------------------------------------------
	*/
// 	//////////////////////////////////////////////////////////////
// 	Transverse_Impact_Parameter
// 	/////////////////////////////////////////////////////////////
	TH1 *TrImPa1 = (TH1*)file1->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa2 = (TH1*)file2->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa3 = (TH1*)file3->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa4 = (TH1*)file4->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa5 = (TH1*)file5->Get("Transverse_Impact_Parameter");
	
	TrImPa1 -> SetLineColor(1);
	TrImPa2 -> SetLineColor(2);
	TrImPa3 -> SetLineColor(3);
	TrImPa4 -> SetLineColor(4);
	TrImPa5 -> SetLineColor(6);
	
	TCanvas *TrImPa = new TCanvas("TrImPa");
	TrImPa->cd();
	TrImPa1->SetTitle("Trans Impact Parameter");
	TrImPa1->SetStats(kFALSE);
// 	TrImPa1->SetAxisRange(-.2,.2,"X");
	TrImPa1->SetAxisRange(-10,600,"Y");
	TrImPa1 -> Draw("hist");//repeat for each mass point
	TrImPa2 -> Draw("same,hist");
	TrImPa3 -> Draw("same,hist");
	TrImPa4 -> Draw("same,hist");
	TrImPa5 -> Draw("same,hist");

	TLegend* legTip = new TLegend(.8, .7, 0.9, .89);
	legTip->SetBorderSize(0);
	legTip->SetHeader("Mixing (10^{-7})","C");
	legTip->AddEntry(TrImPa1, "500 ", "L");//repeat for each mass point
	legTip->AddEntry(TrImPa2, "100 ", "L");
	legTip->AddEntry(TrImPa3, "50 ", "L");
	legTip->AddEntry(TrImPa4, "10 ", "L");
	legTip->AddEntry(TrImPa5, "1 ", "L");
	legTip->Draw();
	TrImPa->SaveAs("Trans_Impa_Par_mixing_zoom.png");
	
// 	Long_Impact_Parameter
	TH1 *LoImPa1 = (TH1*)file1->Get("Long_Impact_Parameter");//repeat for every mass point
	TH1 *LoImPa2 = (TH1*)file2->Get("Long_Impact_Parameter");
	TH1 *LoImPa3 = (TH1*)file3->Get("Long_Impact_Parameter");
	TH1 *LoImPa4 = (TH1*)file4->Get("Long_Impact_Parameter");
	TH1 *LoImPa5 = (TH1*)file5->Get("Long_Impact_Parameter");
		
	LoImPa1 -> SetLineColor(1);//repeat for every mass point
	LoImPa2 -> SetLineColor(2);
	LoImPa3 -> SetLineColor(3);
	LoImPa4 -> SetLineColor(4);
	LoImPa5 -> SetLineColor(6);
		
	TCanvas *canLoImPa = new TCanvas("canLoImPa");
	canLoImPa->cd();
	LoImPa1->SetTitle("Long Impact Parameter");
	LoImPa1->SetStats(kFALSE);
// 	LoImPa1->SetAxisRange(-2.5,2.5,"X");
	LoImPa1->SetAxisRange(-10,500,"Y");
	LoImPa1 -> Draw("hist");//repeat for each mass point
	LoImPa2 -> Draw("same,hist");
	LoImPa3 -> Draw("same,hist");
	LoImPa4 -> Draw("same,hist");
	LoImPa5 -> Draw("same,hist");
	
	TLegend* legLip = new TLegend(.8, .7, 0.9, .89);
	legLip->SetBorderSize(0);
	legLip->SetHeader("Mixing (10^{-7})","C");
	legLip->AddEntry(LoImPa1, "500 ", "L");//repeat for every mass point
	legLip->AddEntry(LoImPa2, "100 ", "L");
	legLip->AddEntry(LoImPa3, "50 ", "L");
	legLip->AddEntry(LoImPa4, "10 ", "L");
	legLip->AddEntry(LoImPa5, "1 ", "L");
	legLip->Draw();
	canLoImPa->SaveAs("Long_Impa_Par_mixing_zoom.png");
	
	/*
// 	//////////////////////////////////////////////
// 	Neutrino Variables
// 	/////////////////////////////////////////////
// 	-----------------------------Met--------------------------------------
	TH1 *Nu_2Pt = (TH1*)file2->Get("Neutrino_Met");//repeat for every mass point
	TH1 *Nu_5Pt = (TH1*)file5->Get("Neutrino_Met");
	TH1 *Nu_10Pt = (TH1*)file10->Get("Neutrino_Met");
	
	Nu_2Pt -> SetLineColor(1);//repeat for every mass point
	Nu_5Pt -> SetLineColor(2);
	Nu_10Pt -> SetLineColor(3);
	
	TCanvas * canNuPt = new TCanvas("canNuPt");
	canNuPt->cd();
	Nu_2Pt->SetTitle("Neutrino_Met");
// 	Nu_2Pt->SetAxisRange(-1.5,100.);
	Nu_2Pt->SetStats(kFALSE);
	Nu_2Pt -> Draw("hist");//repeat for each mass point
	Nu_5Pt -> Draw("same,hist");
	Nu_10Pt -> Draw("same,hist");
	
	TLegend* legNuPt = new TLegend(.8, .7, 0.9, .898);
	legNuPt->SetBorderSize(0);
	legNuPt->AddEntry(Nu_2Pt, "10 ", "L");//repeat for every mass point
	legNuPt->AddEntry(Nu_5Pt, "5 ", "L");
	legNuPt->AddEntry(Nu_10Pt, "1 ", "L");
	legNuPt->Draw();
	canNuPt->SaveAs("Neutrino_Met_mix.png");
// 	----------------------------------
	
// 	-----------------------Eta----------------------------------------
	TH1 *Nu_2Eta = (TH1*)file2->Get("Neutrino_Eta");//repeat for every mass point
	TH1 *Nu_5Eta = (TH1*)file5->Get("Neutrino_Eta");
	TH1 *Nu_10Eta = (TH1*)file10->Get("Neutrino_Eta");
	
	Nu_2Eta -> SetLineColor(1);//repeat for every mass point
	Nu_5Eta -> SetLineColor(2);
	Nu_10Eta -> SetLineColor(3);
	
	TCanvas * canNuEta = new TCanvas("canNuEta");
	canNuEta->cd();
	Nu_2Eta->SetTitle("Neutrino_Eta");
	Nu_2Eta->SetStats(kFALSE);
	Nu_2Eta -> Draw("hist");//repeat for each mass point
	Nu_5Eta -> Draw("same,hist");
	Nu_10Eta -> Draw("same,hist");
		
	TLegend* legNuEta = new TLegend(.8, .7, 0.9, .898);
	legNuEta->SetBorderSize(0);
	legNuEta->AddEntry(Nu_2Eta, "10 ", "L");//repeat for every mass point
	legNuEta->AddEntry(Nu_5Eta, "5 ", "L");
	legNuEta->AddEntry(Nu_10Eta, "1 ", "L");
	legNuEta->Draw();
	canNuEta->SaveAs("Neutrino_Eta_mix.png");
// 	------------------------------------------------------------------------------
	
// 	--------------------------------Phi----------------------------------------
	TH1 *Nu_2Phi = (TH1*)file2->Get("Neutrino_Phi");//repeat for every mass point
	TH1 *Nu_5Phi = (TH1*)file5->Get("Neutrino_Phi");
	TH1 *Nu_10Phi = (TH1*)file10->Get("Neutrino_Phi");
	
	Nu_2Phi -> SetLineColor(1);//repeat for every mass point
	Nu_5Phi -> SetLineColor(2);
	Nu_10Phi -> SetLineColor(3);
	
	TCanvas * canNuPhi = new TCanvas("canNuPhi");
	canNuPhi->cd();
	Nu_2Phi->SetTitle("Neutrino_Phi");
	Nu_2Phi->SetStats(kFALSE);
// 	Nu_2Phi->SetAxisRange(-5.0,5);
	Nu_2Phi -> Draw("hist");//repeat for each mass point
	Nu_5Phi -> Draw("same,hist");
	Nu_10Phi -> Draw("same,hist");
	
	TLegend* legNuPhi = new TLegend(.8, .7, 0.9, .898);//Tlegend(X_starts, Y_start, 
	legNuPhi->SetBorderSize(0);
	legNuPhi->AddEntry(Nu_2Phi, "10 ", "L");//repeat for every mass point
	legNuPhi->AddEntry(Nu_5Phi, "5 ", "L");
	legNuPhi->AddEntry(Nu_10Phi, "1 ", "L");
	legNuPhi->Draw();
	canNuPhi->SaveAs("Neutrino_Phi_mix.png");
// 	---------------------------------------------------------------------------
	
// 	//////////////////////////////////////////////
// 	Heavy Neutrino Variables
// 	/////////////////////////////////////////////
// ------------------------------------------------------
	TH1 *NRM_2Pt = (TH1*)file2->Get("NR_Mass");//repeat for every mass point
	TH1 *NRM_5Pt = (TH1*)file5->Get("NR_Mass");
	TH1 *NRM_10Pt = (TH1*)file10->Get("NR_Mass");
	
	NRM_2Pt -> SetLineColor(1);//repeat for every mass point
	NRM_5Pt -> SetLineColor(2);
	NRM_10Pt -> SetLineColor(3);
	
	TCanvas * canNRM = new TCanvas("canNRM");
	canNRM->cd();
	NRM_2Pt->SetTitle("Heavy Neutrino Mass");
// 	NRM_2Pt->SetRangeUser(-10,60);
	NRM_2Pt->SetStats(kFALSE);
	NRM_2Pt -> Draw("hist");//repeat for each mass point
	NRM_5Pt -> Draw("same,hist");
	NRM_10Pt -> Draw("same,hist");
	
	TLegend* legNRM = new TLegend(.8, .7, 0.9, .898);
	legNRM->SetBorderSize(0);
	legNRM->AddEntry(NRM_2Pt, "10 ", "L");//repeat for every mass point
	legNRM->AddEntry(NRM_5Pt, "5 ", "L");
	legNRM->AddEntry(NRM_10Pt, "1 ", "L");
	legNRM->Draw();
	canNRM->SaveAs("Heavy_Neutrino_Mass_mix.png");
	
// 	//////////////////////////////////////////////
// 	W Mass Variables
// 	/////////////////////////////////////////////
// ------------------------------------------------------
	TH1 *WM_2Pt = (TH1*)file2->Get("W_Mass");//repeat for every mass point
	TH1 *WM_5Pt = (TH1*)file5->Get("W_Mass");
	TH1 *WM_10Pt = (TH1*)file10->Get("W_Mass");
	
	WM_2Pt -> SetLineColor(1);//repeat for every mass point
	WM_5Pt -> SetLineColor(2);
	WM_10Pt -> SetLineColor(3);
	
	TCanvas * canWM = new TCanvas("canWM");
	canWM->cd();
	WM_2Pt->SetTitle("W Mass");
// 	WM_2Pt->SetRangeUser(-10,60);
	WM_2Pt->SetStats(kFALSE);
	WM_2Pt -> Draw("hist");//repeat for each mass point
	WM_5Pt -> Draw("same,hist");
	WM_10Pt -> Draw("same,hist");
	
	TLegend* legWM = new TLegend(.8, .7, 0.9, .898);
	legWM->SetBorderSize(0);
	legWM->AddEntry(WM_2Pt, "10 ", "L");//repeat for every mass point
	legWM->AddEntry(WM_5Pt, "5 ", "L");
	legWM->AddEntry(WM_10Pt, "1 ", "L");
	legWM->Draw();
	canWM->SaveAs("W_Mass_mix.png");*/
}

void myplottermass()
{
	/*TFile* file1 = TFile::Open("hst_RHN_13TeV_2GeV_10Mix.root");
	TFile* file2 = TFile::Open("hst_RHN_13TeV_5GeV_10Mix.root");
	TFile* file3 = TFile::Open("hst_RHN_13TeV_10GeV_10Mix.root");
	

// 	Transverse_Impact_Parameter
	TH1 *TrImPa2 = (TH1*)file1->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa5 = (TH1*)file2->Get("Transverse_Impact_Parameter");
	TH1 *TrImPa10 = (TH1*)file3->Get("Transverse_Impact_Parameter");
	TrImPa2 -> SetLineColor(1);
	TrImPa5 -> SetLineColor(2);
	TrImPa10 -> SetLineColor(3);
	TCanvas *TrImPa = new TCanvas("TrImPa2");
	TrImPa->cd();
	TrImPa2->SetTitle("Transverse Impact Parameter");
	TrImPa2->SetStats(kFALSE);
	TrImPa2->SetAxisRange(-.5,.5,"X");
	TrImPa2->SetAxisRange(-5,600,"Y");
	TrImPa2 -> Draw("hist");
	TrImPa5 -> Draw("same,hist");
	TrImPa10 -> Draw("same,hist");
	TLegend* leg1 = new TLegend(.8, .7, 0.9, .898);
	leg1->SetBorderSize(0);
	leg1->SetHeader("Mass (GeV)","C");
	leg1->AddEntry(TrImPa2, "2 ", "L");
	leg1->AddEntry(TrImPa5, "5 ", "L");
	leg1->AddEntry(TrImPa10, "10 ", "L");
	leg1->Draw();
	TrImPa->SaveAs("Trans_Impa_Par_auto.png");
	
// 	Long_Impact_Parameter
	TH1 *LoImPa2 = (TH1*)file2->Get("Long_Impact_Parameter");//repeat for every mass point
	TH1 *LoImPa5 = (TH1*)file5->Get("Long_Impact_Parameter");
	TH1 *LoImPa10 = (TH1*)file10->Get("Long_Impact_Parameter");
	LoImPa2 -> SetLineColor(1);//repeat for every mass point
	LoImPa5 -> SetLineColor(2);
	LoImPa10 -> SetLineColor(3);
	TCanvas * canLoImPa = new TCanvas("canLoImPa2");//define new canva for the plots
	canLoImPa->cd();
	LoImPa2->SetTitle("Long Impact Parameter");
	LoImPa2->SetStats(kFALSE);
	LoImPa2->SetAxisRange(-1.5,1.5,"X");
	LoImPa2->SetAxisRange(-5,500,"Y");
	LoImPa2 -> Draw("hist");//repeat for each mass point
	LoImPa5 -> Draw("same,hist");
	LoImPa10 -> Draw("same,hist");
	TLegend* legLip = new TLegend(.8, .7, 0.9, .898);//define new Legend
	legLip->SetBorderSize(0);
	legLip->SetHeader("Mass (GeV)","C");
	legLip->AddEntry(LoImPa2, "2 ", "L");//repeat for every mass point
	legLip->AddEntry(LoImPa5, "5 ", "L");
	legLip->AddEntry(LoImPa10, "10 ", "L");
	legLip->Draw();
	canLoImPa->SaveAs("Long_Impact_Parameter_auto.png");*/
}

void myplotter()
{
// 	myplotterone();
// 	myplotterall();
// 	myplottermass();
	myplottermixing();
}





