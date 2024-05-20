#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "Randomize.hh"
#include "EcoMug.h"
#include "G4MuonMinus.hh"
#include "G4MuonPlus.hh"


class PrimaryGenerator:public G4VUserPrimaryGeneratorAction{
    public:
        PrimaryGenerator();
        ~PrimaryGenerator();

        virtual void GeneratePrimaries(G4Event*);

    private:
        G4ParticleGun* fParticleGun;
        EcoMug* ecoMug;

};



#endif