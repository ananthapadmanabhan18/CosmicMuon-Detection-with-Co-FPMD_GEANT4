#include "generator.hh"

primarygenerator::primarygenerator(){

    fparticlegun = new G4ParticleGun(1);
    G4ParticleTable *particletable = G4ParticleTable::GetParticleTable();
    G4String particlename = "mu+";
    G4ParticleDefinition *particle = particletable->FindAntiParticle(particlename);
    G4ThreeVector pos(0.01*mm,0.01*mm,2.5*m);
    G4ThreeVector mom(0,0,-1);
    fparticlegun->SetParticlePosition(pos);
    fparticlegun->SetParticleMomentumDirection(mom);
    fparticlegun->SetParticleMomentum(0.08*GeV);
    fparticlegun->SetParticleDefinition(particle);    
}

primarygenerator::~primarygenerator(){
    delete fparticlegun;
}


void primarygenerator::GeneratePrimaries(G4Event *anEvent)
{

    fparticlegun->GeneratePrimaryVertex(anEvent);

}    