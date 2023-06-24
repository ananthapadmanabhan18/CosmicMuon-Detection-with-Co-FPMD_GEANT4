#include "detector.hh"



SensitiveDetector::SensitiveDetector(G4String name):G4VSensitiveDetector(name)
{}
SensitiveDetector::~SensitiveDetector()
{}

G4bool SensitiveDetector::ProcessHits(G4Step *aStep,G4TouchableHistory*ROhist)
{
    G4Track* track = aStep->GetTrack();
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint= aStep->GetPostStepPoint();
    G4ThreeVector posparticle = preStepPoint->GetPosition();
    G4cout<<"Position:"<<posparticle<<G4endl;
    return true;
}