#include "generator.hh"
#include <cmath>

primarygenerator::primarygenerator():fparticlegun(0),muon_minus(0),muon_plus(0){

    // fMuonGen->SetUseCylinder();
    // fMuonGen->SetCylinderRadius(1*m);
    // fMuonGen->SetCylinderHeight(1*m);

    // fparticlegun=new G4ParticleGun(1);
    // muon_minus = G4MuonMinus::Definition();
    // muon_plus = G4MuonPlus::Definition();
}

primarygenerator::~primarygenerator(){
    delete fparticlegun;
}


void primarygenerator::GeneratePrimaries(G4Event *anEvent)
{
    // fMuonGen->Generate();
    // std::array<double,3> muon_pos = fMuonGen->GetGenerationPosition();
    // G4double muon_mom= fMuonGen->GetGenerationMomentum();
    // G4double muon_theta = fMuonGen->GetGenerationTheta();
    // G4double muon_phi = fMuonGen->GetGenerationPhi();
    // fparticlegun->SetParticlePosition(G4ThreeVector(muon_pos[0]*mm,muon_pos[1]*mm,muon_pos[2]*mm));
    // fparticlegun->SetParticleMomentum(G4ParticleMomentum(muon_mom*sin(muon_theta)*cos(muon_phi)*GeV,muon_mom*sin(muon_theta)*sin(muon_phi)*GeV,muon_mom*cos(muon_phi)*GeV));
    
    // if(fMuonGen->GetCharge()<0)
    // {
    //     fparticlegun->SetParticleDefinition(muon_minus);
    // }
    // else
    // {
    //     fparticlegun->SetParticleDefinition(muon_plus);
    // }
    
    
    // fparticlegun->GeneratePrimaryVertex(anEvent);
}    
