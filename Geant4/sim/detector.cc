#include "detector.hh"

sensitivedetector::sensitivedetector(G4String name) : G4VSensitiveDetector(name){}
sensitivedetector::~sensitivedetector(){}


G4bool sensitivedetector:: ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist){
    
}