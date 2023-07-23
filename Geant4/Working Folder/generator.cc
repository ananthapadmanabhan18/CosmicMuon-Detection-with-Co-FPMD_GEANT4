#include "generator.hh"
#include <cmath>

primarygenerator::primarygenerator(){

    fparticlegun = new G4ParticleGun(1);
    fparticlegun->SetParticleDefinition(G4MuonMinus::Definition());  
    G4Random::setTheSeed(12345);
    G4double rand_angle = M_PI*G4UniformRand()-0.5*M_PI;

    G4ThreeVector pos(50*(cos(rand_angle))*cm,50*(sin(rand_angle))*cm,2.5*m);

    G4ThreeVector mom(0,0,-1);
    // fparticlegun->SetParticleDefinition(particle);
    fparticlegun->SetParticlePosition(pos);
    fparticlegun->SetParticleMomentumDirection(mom);
    fparticlegun->SetParticleMomentum(1*GeV);
    
}

primarygenerator::~primarygenerator(){
    delete fparticlegun;
}


void primarygenerator::GeneratePrimaries(G4Event *anEvent)
{

    fparticlegun->GeneratePrimaryVertex(anEvent);

}    
