#include "stepping.hh"


steppingaction::steppingaction(eventaction *eventAction){

    fEventAction = eventAction;
}

steppingaction::~steppingaction(){}


void steppingaction::UserSteppingAction(const G4Step *step)
{
    G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    const detectorconstruction *detectorConstruction = static_cast<const detectorconstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    if(volume != fScoringVolume)
        return;
    G4double edep=step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);
}