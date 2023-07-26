#include "detector.hh"

sensitivedetector::sensitivedetector(G4String name) : G4VSensitiveDetector(name){}
sensitivedetector::~sensitivedetector(){}


G4bool sensitivedetector:: ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist){

    G4Track* track = aStep->GetTrack();
    G4ParticleDefinition* particle = track->GetDefinition();
 
    if(particle==G4MuonMinus::Definition()){
        G4double edep= aStep->GetTotalEnergyDeposit();
        std::ofstream file("/home/apmnair18/Documents/GitHub/Geant4_ROOT/ROOT/Final_Analysis/Multi_Energy/datas/6GeV.txt", std::ios::app);
        file.seekp(0, std::ios::end);
        file <<edep<< G4endl;
        file.close();
    }  

}



        // G4StepPoint *presteppoint = aStep->GetPreStepPoint();
        // G4StepPoint *poststeppoint = aStep->GetPostStepPoint();
        // G4ThreeVector posMuon = presteppoint->GetPosition();
        // G4cout<<"Muon Position"<<posMuon<<G4endl;

        // const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
        // G4int copyNo = touchable->GetCopyNumber();
        // G4cout<<"CopyNumber:"<<copyNo<<G4endl;
        // G4VPhysicalVolume *physVol = touchable->GetVolume();
        // G4ThreeVector posDetector = physVol->GetTranslation();
        // G4cout << "Detector position: " << posDetector << G4endl;