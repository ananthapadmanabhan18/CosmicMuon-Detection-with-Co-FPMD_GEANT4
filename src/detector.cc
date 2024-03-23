#include "detector.hh"

sensitivedetector::sensitivedetector(G4String name) : G4VSensitiveDetector(name){}
sensitivedetector::~sensitivedetector(){}


G4bool sensitivedetector:: ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist){

    G4Track* track = aStep->GetTrack();
    G4ParticleDefinition* particle = track->GetDefinition();
 
    // if(particle==G4MuonMinus::Definition()){
    //     G4double edep= aStep->GetTotalEnergyDeposit();
    //     G4double time = aStep->GetPreStepPoint()->GetGlobalTime();
    //     std::ofstream file("output.txt", std::ios::app);
    //     file.seekp(0, std::ios::end);
    //     file << edep << "\t" << time/s<<G4endl;
    //     file.close();
    // }  
    return true;

}
