#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4MuonMinus.hh"
#include "G4MuonPlus.hh"
#include "G4Proton.hh"
#include "Randomize.hh"
#include <array>

class primarygenerator : public G4VUserPrimaryGeneratorAction
{
    public:
        primarygenerator ();
        ~primarygenerator();
        virtual void GeneratePrimaries(G4Event*,int lineIndex);
    private:    
        G4ParticleGun* fparticlegun;
        G4ParticleDefinition *muon_minus, *muon_plus;
        // EcoMug *fMuonGen;
    
};


#endif