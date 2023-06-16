#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}
MyDetectorConstruction::~MyDetectorConstruction()
{}
G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_WATER");
    // G4Box *sbox = new G4Box("sbox",0.5*m,0.05*m,0.1*m);
    G4Tubs* sbox = new G4Tubs("sbox",1*m,5*m,25*m,0,360*deg);
    G4LogicalVolume *lbox = new G4LogicalVolume(sbox, worldMat,"lbox");
    G4VPhysicalVolume *pbox = new G4PVPlacement(0,G4ThreeVector(0,0,0),lbox, "pbox", 0, false,0,true);
    return pbox;
}




