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
// #include "EcoMug.h"

class primarygenerator : public G4VUserPrimaryGeneratorAction
{
    public:
        primarygenerator ();
        ~primarygenerator();
        virtual void GeneratePrimaries(G4Event*);
    private:    
        G4ParticleGun* fparticlegun;
};


#endif