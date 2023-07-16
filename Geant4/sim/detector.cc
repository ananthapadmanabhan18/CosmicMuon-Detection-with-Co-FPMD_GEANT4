#include "detector.hh"

sensitivedetector::sensitivedetector(G4String name) : G4VSensitiveDetector(name){}
sensitivedetector::~sensitivedetector(){}


G4bool sensitivedetector:: ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist){

    G4Track* track = aStep->GetTrack();
    // track->SetTrackStatus(fStopAndKill);
    // G4StepPoint* presteppoint = aStep->GetPreStepPoint();
    // G4StepPoint* poststeppoint = aStep->GetPostStepPoint();
    G4double energyDeposit = aStep->GetTotalEnergyDeposit();
    // G4ThreeVector position = presteppoint->GetPosition();

    G4cout<<"Position:"<<energyDeposit<<G4endl;    
}