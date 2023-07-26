#include "generator.hh"
#include <cmath>




primarygenerator::primarygenerator(){

    fparticlegun = new G4ParticleGun(1);
    fparticlegun->SetParticleDefinition(G4MuonMinus::Definition());  
    G4ThreeVector pos(0.01*mm,0.01*mm,2.5*m);
    G4ThreeVector mom(0,0,-1);
    fparticlegun->SetParticlePosition(pos);
    fparticlegun->SetParticleMomentumDirection(mom);
    fparticlegun->SetParticleMomentum(4*GeV);
     
}

primarygenerator::~primarygenerator(){
    delete fparticlegun;
}


void primarygenerator::GeneratePrimaries(G4Event *anEvent)
{
    fparticlegun->GeneratePrimaryVertex(anEvent);
}


















// primarygenerator::primarygenerator(){

//     fparticlegun = new G4ParticleGun(1);
//     fparticlegun->SetParticleDefinition(G4MuonMinus::Definition());  
//     G4ThreeVector pos(0.01*mm,0.01*mm,2.5*m);
//     G4ThreeVector mom(0,0,-1);
//     fparticlegun->SetParticlePosition(pos);
//     fparticlegun->SetParticleMomentumDirection(mom);
//     fparticlegun->SetParticleMomentum(1*GeV);
     
// }

// primarygenerator::~primarygenerator(){
//     delete fparticlegun;
// }


// void primarygenerator::GeneratePrimaries(G4Event *anEvent)
// {
//     fparticlegun->GeneratePrimaryVertex(anEvent);
// }    



