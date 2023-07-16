#include "physics.hh"


physicslist::physicslist(){
        RegisterPhysics(new G4EmStandardPhysics());
        RegisterPhysics(new G4OpticalPhysics());
}


physicslist::~physicslist(){}