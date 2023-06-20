#include "construction.hh"
#include "G4LogicalVolume.hh"
#include "math.h"
scintillation1::scintillation1()
{}
scintillation1::~scintillation1()
{}
G4VPhysicalVolume *scintillation1::Construct()
{
    // Set up the dimensions of the honey comb detector
    G4double phiStart = - 0 * M_PI;
    G4double phiTotal =  2* M_PI; // Change this value as needed
    G4int numSide = 6;
    G4int numZplanes = 2;
    G4double rInner[]= {4.8*mm, 4.6*mm};
    G4double rOuter[] = {5*mm, 5*mm};
    G4double zPlanes[]={-2.5*mm,2.5*mm};


    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* air = nistManager->FindOrBuildMaterial("G4_Al");
    G4Material* detectorMaterial = nistManager->FindOrBuildMaterial("G4_Ge");
    G4Material* gold = nistManager->FindMaterial("G4_Au");
    G4Material* copper = nistManager->FindOrBuildMaterial("G4_Cu");

    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2.5*m,2.5*m,2.5*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,true);

    //defining 2 Scintillation Detectors Detector
    G4Box* solidDetector = new G4Box("Detector1", 16*(30/sqrt(3))*mm,16*(10)*mm,0.05*m);
    G4LogicalVolume* logicalDetector = new G4LogicalVolume(solidDetector, detectorMaterial, "Detector1");
    new G4PVPlacement(nullptr, G4ThreeVector(0, -0*m, -1*m), logicalDetector, "Detector1", logicworld, false, 0,true);
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0*m,1*m), logicalDetector, "Detector2", logicworld, false, 0,true);



    //defining Honeycomb detector
    G4Polyhedra *hcdetector = new G4Polyhedra("HCD", phiStart,phiTotal,numSide,numZplanes,zPlanes,rInner, rOuter);
    G4LogicalVolume* hclogic = new G4LogicalVolume(hcdetector,copper,"hclogic");

    for (int i = -15;i<=16;i++){
        for (int j = -15;j<=16;j++){
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3)))*mm,j*10*mm,0), hclogic, "HCdetector", logicworld, false, 0,true);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3))-(15/sqrt(3)))*mm,((j*10)-(5))*mm,0), hclogic, "HCdetector", logicworld, false, 0,true);
        }
    }


    //Defining the gold wire 
    G4Tubs *goldwire = new G4Tubs("goldwire",0,0.01*mm,5*mm,0,2*M_PI);
    G4LogicalVolume* goldlogic = new G4LogicalVolume(goldwire,gold,"hclogic");
    for (int i = -15;i<=16;i++){
        for (int j = -15;j<=16;j++){
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3)))*mm,j*10*mm,0), goldlogic, "goldwire", logicworld, false, 0,true);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3))-(15/sqrt(3)))*mm,((j*10)-(5))*mm,0), goldlogic, "goldwire", logicworld, false, 0,true);
        }
    }

    return physicalworld;
}


