#include "generator.hh"
#include <cmath>




primarygenerator::primarygenerator(){

    fparticlegun = new G4ParticleGun(1);

    ecoMug = new EcoMug();
    ecoMug->SetUseSky();
    ecoMug->SetSkySize({{5*m,5*m}});
    ecoMug->SetSkyCenterPosition({{0*m,0*m,5*m}});


    fparticlegun->SetParticleDefinition(G4MuonMinus::Definition());
    G4ThreeVector pos(0,0,5*m);
    fparticlegun->SetParticlePosition(pos);
    G4double mom = 1*GeV;
    fparticlegun->SetParticleMomentum(mom);
    fparticlegun->SetParticleMomentumDirection(G4ThreeVector(0,0,-1));


     
}

primarygenerator::~primarygenerator(){
    delete fparticlegun;
}


void primarygenerator::GeneratePrimaries(G4Event *anEvent)
{

    // ecoMug->Generate();

    // //Setting the Particle according to charge
    // int particle_charge = ecoMug->GetCharge();
    // if(particle_charge == 1){
    //     fparticlegun->SetParticleDefinition(G4MuonPlus::Definition());
    // }
    // else if(particle_charge == -1){
    //     fparticlegun->SetParticleDefinition(G4MuonMinus::Definition());
    // }
    // else{
    //     G4cout << "Error: Particle charge not recognized" << G4endl;
    // }



    // // Setting the Position
    // std::array<G4double, 3> position = ecoMug->GetGenerationPosition();
    // G4ThreeVector pos(position[0]*mm, position[2]*mm, position[1]*mm);
    // fparticlegun->SetParticlePosition(pos);


    // //Setting the Momentum
    // G4double momentum = ecoMug->GetGenerationMomentum();
    // G4double theta = ecoMug->GetGenerationTheta();
    // G4double phi = ecoMug->GetGenerationPhi();
    // G4ThreeVector mom(momentum*sin(theta)*cos(phi)*GeV, momentum*cos(theta)*GeV, momentum*sin(theta)*sin(phi)*GeV);
    // fparticlegun->SetParticleMomentum(mom);

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



