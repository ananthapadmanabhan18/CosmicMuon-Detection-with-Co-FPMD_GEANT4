#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4MuonMinus.hh"
#include "G4Proton.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleDefinition.hh"

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