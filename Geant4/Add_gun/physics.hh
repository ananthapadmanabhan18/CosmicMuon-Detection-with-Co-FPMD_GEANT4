#ifndef PHYSICS_HH
#define PHYSICS_HH
#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4GenericIon.hh"
#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4Decay.hh"
#include "G4SystemOfUnits.hh"
#include "G4MuonMinus.hh"





class UserPhysicsList : public G4VUserPhysicsList {
public:
    UserPhysicsList();
    virtual ~UserPhysicsList();
    virtual void ConstructParticle();
    virtual void ConstructProcess();
    // virtual void SetCuts();
};





// class MyPhysicsList : public G4VModularPhysicsList
// {
//     public:
//     MyPhysicsList();
//     ~MyPhysicsList();

// };

#endif