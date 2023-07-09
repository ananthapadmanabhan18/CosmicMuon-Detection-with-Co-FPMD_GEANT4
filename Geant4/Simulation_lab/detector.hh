#ifndef DETECTOR_HH
#define DETECTOR_HH
#include "G4VSensitiveDetector.hh"
#include <fstream>
#include "G4MuonMinus.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4MuonMinus.hh"
#include "G4Proton.hh"


class GSD : public G4VSensitiveDetector
{
public:
  GSD(const G4String& name) : G4VSensitiveDetector(name) {}

  G4bool ProcessHits(G4Step* step, G4TouchableHistory*)
  {
    G4Track* track = step->GetTrack();
    G4StepPoint *preStepPoint = step->GetPreStepPoint();
    // G4StepPoint *postStepPoint= step->GetPostStepPoint();
    G4ThreeVector posparticle = preStepPoint->GetPosition();
    G4ParticleDefinition* particle = track->GetDefinition();
    // G4int particleID = particle->GetPDGEncoding();
    if(particle==G4MuonMinus::Definition()){
      G4double energyDeposit = step->GetTotalEnergyDeposit();
      std::ofstream file("output.txt", std::ios::app);
      file.seekp(0, std::ios::end);
      file <<energyDeposit<< G4endl;
      file.close();
    }  

    return true;
  }
};



#endif