#include "construction.hh"

scintillation1::scintillation1()
{}
scintillation1::~scintillation1()
{}
G4VPhysicalVolume *scintillation1::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_WATER");
    G4Box *sbox1 = new G4Box("sbox1",1*m,0.05*m,0.1*m);
    G4LogicalVolume *lbox1 = new G4LogicalVolume(sbox1, worldMat,"lbox1");
    G4VPhysicalVolume *pbox1 = new G4PVPlacement(0,G4ThreeVector(0,0,0),lbox1, "pbox1", 0, false,0,true);
    return pbox1;
}

// scintillation2::scintillation2()
// {}
// scintillation2::~scintillation2()
// {}
// G4VPhysicalVolume *scintillation2::Construct()
// {
//     G4NistManager *nist1 = G4NistManager::Instance();
//     G4Material *worldMat = nist1->FindOrBuildMaterial("G4_WATER");
//     G4Box *sbox2 = new G4Box("sbox2",2*m,0.1*m,0.2*m);
//     G4LogicalVolume *lbox2 = new G4LogicalVolume(sbox2, worldMat,"lbox2");
//     G4VPhysicalVolume *pbox2 = new G4PVPlacement(0,G4ThreeVector(0,0,0),lbox2, "pbox2", 0, false,0,true);
//     return pbox2;
// }

