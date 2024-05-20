#include "generator.hh"
#define M_PI 3.14159265358979323846


PrimaryGenerator::PrimaryGenerator(){

    fParticleGun = new G4ParticleGun(1);
    ecoMug = new EcoMug();
    ecoMug->SetUseSky();
    ecoMug->SetSkySize({{5*m,5*m}});
    ecoMug->SetSkyCenterPosition({{0*m,0*m,5*m}});

    fParticleGun->SetParticleDefinition(G4MuonMinus::Definition());
    G4ThreeVector pos(0,0,5*m);
    fParticleGun->SetParticlePosition(pos);
    G4double mom = 1*GeV;
    fParticleGun->SetParticleMomentum(mom);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,-1));


}

PrimaryGenerator::~PrimaryGenerator(){
    delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent){

    ecoMug->Generate();

    //Setting the Particle according to charge
    int particle_charge = ecoMug->GetCharge();
    if(particle_charge == 1){
        fParticleGun->SetParticleDefinition(G4MuonPlus::Definition());
    }
    else if(particle_charge == -1){
        fParticleGun->SetParticleDefinition(G4MuonMinus::Definition());
    }
    else{
        G4cout << "Error: Particle charge not recognized" << G4endl;
    }



    // Setting the Position
    std::array<G4double, 3> position = ecoMug->GetGenerationPosition();
    G4ThreeVector pos(position[0]*mm, position[2]*mm, position[1]*mm);
    fParticleGun->SetParticlePosition(pos);


    //Setting the Momentum
    G4double momentum = ecoMug->GetGenerationMomentum();
    G4double theta = ecoMug->GetGenerationTheta();
    G4double phi = ecoMug->GetGenerationPhi();
    G4ThreeVector mom(momentum*sin(theta)*cos(phi)*GeV, momentum*cos(theta)*GeV, momentum*sin(theta)*sin(phi)*GeV);
    fParticleGun->SetParticleMomentum(mom);

    fParticleGun->GeneratePrimaryVertex(anEvent);
}