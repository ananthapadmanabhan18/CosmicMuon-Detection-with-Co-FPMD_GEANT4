#include "run.hh"




runaction::runaction(){} 


runaction::~runaction(){} 



void runaction::BeginOfRunAction(const G4Run*){

    G4AnalysisManager*man = G4AnalysisManager::Instance();
    man->OpenFile("output.root");
    man->CreateNtuple("index","Energy");
    man->CreateNtupleDColumn("fEvent");
    man->CreateNtupleDColumn("Energy");
    man->FinishNtuple(0);

}

void runaction::EndOfRunAction(const G4Run*){

    G4AnalysisManager*man = G4AnalysisManager::Instance();
    man->Write();
    man->CloseFile();
}