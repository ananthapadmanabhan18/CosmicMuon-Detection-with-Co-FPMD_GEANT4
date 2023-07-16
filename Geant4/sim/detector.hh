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


class sensitivedetector : public G4VSensitiveDetector{

    public:
        sensitivedetector(G4String);
        ~sensitivedetector();

    private:
        virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

};



#endif