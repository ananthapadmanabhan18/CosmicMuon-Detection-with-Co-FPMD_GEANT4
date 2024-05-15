#include "stepping.hh"


steppingaction::steppingaction(eventaction *eventAction){

    fEventAction = eventAction;
}

steppingaction::~steppingaction(){}


void steppingaction::UserSteppingAction(const G4Step *step)
{
    G4double edep=step->GetTotalEnergyDeposit();
    G4ParticleDefinition* def =  step->GetTrack()->GetDefinition();
    if(def == G4MuonPlus::Definition() || def == G4MuonMinus::Definition()){
        fEventAction->AddEdep(edep);
        G4cout << " Muon Detected" << G4endl;
        G4cout << "Energy deposited: " << edep/MeV << " MeV" << G4endl;

    }
    
}