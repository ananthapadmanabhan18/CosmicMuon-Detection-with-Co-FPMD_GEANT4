#ifndef DETECTOR_HH
#define DETECTOR_HH
#include "G4VSensitiveDetector.hh"


class GSD : public G4VSensitiveDetector
{
public:
  GSD(const G4String& name) : G4VSensitiveDetector(name) {}

  G4bool ProcessHits(G4Step* step, G4TouchableHistory*)
  {
    G4Track* track = step->GetTrack();
    G4StepPoint *preStepPoint = step->GetPreStepPoint();
    G4StepPoint *postStepPoint= step->GetPostStepPoint();
    G4ThreeVector posparticle = preStepPoint->GetPosition();
    G4cout<<"Position on the gas:"<<posparticle<<G4endl;    
    G4double energyDeposit = step->GetTotalEnergyDeposit();
    G4cout << "Energy deposit on the gas: " << energyDeposit << " MeV" << G4endl;
    return true;
  }
};



#endif