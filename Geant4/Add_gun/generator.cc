#include "generator.hh"
#include "math.h"



PrimaryGenerator::PrimaryGenerator()
{
    fParticleGun=new G4ParticleGun(1);
}
PrimaryGenerator::~PrimaryGenerator()
{
    delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event*anEvent)
{
    G4ParticleTable *ptable = G4ParticleTable::GetParticleTable();
    G4ThreeVector pos(0.1,0.1,2.5);
    G4ThreeVector mom(0,0,1);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(4*GeV);
    fParticleGun->SetParticleDefinition(G4MuonMinus::Definition());
    fParticleGun->GeneratePrimaryVertex(anEvent);
}