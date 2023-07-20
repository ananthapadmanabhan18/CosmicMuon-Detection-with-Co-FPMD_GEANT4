#include "detector.hh"

sensitivedetector::sensitivedetector(G4String name) : G4VSensitiveDetector(name){}
sensitivedetector::~sensitivedetector(){}


G4bool sensitivedetector:: ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist){

    G4Track* track = aStep->GetTrack();
    G4ParticleDefinition* particle = track->GetDefinition();
    
    if(particle==G4MuonMinus::Definition()){
        G4double energyDeposit = aStep->GetTotalEnergyDeposit();
        std::ofstream file("/home/apmnair18/Documents/GitHub/Geant4_ROOT/ROOT/Data_from_geant4/data/soutput_4GeV.txt", std::ios::app);
        file.seekp(0, std::ios::end);
        file <<energyDeposit<< G4endl;
        file.close();
    }  

}