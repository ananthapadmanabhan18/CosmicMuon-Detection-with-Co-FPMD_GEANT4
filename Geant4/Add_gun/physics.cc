#include "physics.hh"




DefaultPhysics::DefaultPhysics()
{
    RegisterPhysics (new G4EmStandardPhysics());
    RegisterPhysics (new G4OpticalPhysics());
}
DefaultPhysics::~DefaultPhysics()
{}





UserPhysicsList::UserPhysicsList() : G4VUserPhysicsList() {}

UserPhysicsList::~UserPhysicsList() {}

void UserPhysicsList::ConstructParticle() {
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = G4MuonMinus::Definition();//particleTable->FindParticle("muonminus");
    particle->SetPDGStable(false);
}

void UserPhysicsList::ConstructProcess() {
    G4Decay* decayProcess = new G4Decay();
    decayProcess->SetVerboseLevel(0);
    auto particleIterator = GetParticleIterator();
    particleIterator->reset();
    while ((*particleIterator)()) {
        G4ParticleDefinition* particle = particleIterator->value();
        G4ProcessManager* processManager = particle->GetProcessManager();
        processManager->RemoveProcess(decayProcess);
    }
}

void UserPhysicsList::SetCuts() {
    G4double cutValue = 0.001*mm;
    SetCutValue(cutValue, "muonminus");
}





