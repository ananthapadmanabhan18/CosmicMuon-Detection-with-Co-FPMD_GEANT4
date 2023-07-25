#include "generator.hh"
#include <cmath>




primarygenerator::primarygenerator(){
    fparticlegun = new G4ParticleGun(1);
    fparticlegun->SetParticleDefinition(G4MuonMinus::Definition()); 
}

primarygenerator::~primarygenerator(){
    delete fparticlegun;
}


void primarygenerator::GeneratePrimaries(G4Event *anEvent , int lineIndex)
{
    std::ifstream file("your_data_file.txt");
    if (!file.is_open()) {
        G4cout << "Error opening the data file.\n";
        return;
    }
    std::string line;
    for (int i = 0; i < lineIndex; ++i) {
        std::getline(file, line);
    }
    G4ThreeVector pos, mom;
    G4double particleMomentum;
    std::istringstream iss(line);
    iss >> pos[0] >> pos[1] >> pos[2] >> mom[0] >> mom[1] >> mom[2] >> particleMomentum;

    fparticlegun->SetParticlePosition(pos);
    fparticlegun->SetParticleMomentumDirection(mom);
    fparticlegun->SetParticleMomentum(particleMomentum);
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



