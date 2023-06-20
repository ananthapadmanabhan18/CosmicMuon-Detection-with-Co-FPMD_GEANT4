#include "construction.hh"
#include "G4LogicalVolume.hh"
#include "math.h"
scintillation1::scintillation1()
{}
scintillation1::~scintillation1()
{}
G4VPhysicalVolume *scintillation1::Construct()
{
    // Set up the dimensions of the detector
    G4double phiStart = - 0 * M_PI;
    G4double phiTotal =  2* M_PI; // Change this value as needed
    G4int numSide = 6;
    G4int numZplanes = 2;
    G4double rInner[]= {4.95*mm, 4.95*mm};
    G4double rOuter[] = {5*mm, 5*mm};
    G4double zPlanes[]={-2.5*mm,2.5*mm};


    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* air = nistManager->FindOrBuildMaterial("G4_Al");
    G4Material* detectorMaterial = nistManager->FindOrBuildMaterial("G4_Ge");

    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2.5*m,2.5*m,2.5*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,true);

    //defining 1st Detector
    G4Box* solidDetector1 = new G4Box("Detector1", 1*m,0.1*m,0.05*m);
    G4LogicalVolume* logicalDetector1 = new G4LogicalVolume(solidDetector1, detectorMaterial, "Detector1");
    new G4PVPlacement(nullptr, G4ThreeVector(0, -0*m, -1*m), logicalDetector1, "Detector1", logicworld, false, 0,true);

    //defining 2nd Detector
    G4Box* solidDetector2 = new G4Box("Detector2", 1*m,0.1*m,0.05*m);
    G4LogicalVolume* logicalDetector2 = new G4LogicalVolume(solidDetector2, detectorMaterial, "Detector2");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0*m,1*m), logicalDetector2, "Detector2", logicworld, false, 0,true);




    //defining Honeycomb detector
    G4Polyhedra *hcdetector = new G4Polyhedra("HCD", phiStart,phiTotal,numSide,numZplanes,zPlanes,rInner, rOuter);
    G4LogicalVolume* hclogic = new G4LogicalVolume(hcdetector,detectorMaterial,"hclogic");

    for (int i = -24;i<=23;i++){
        for (int j = -48;j<=47;j++){
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3)))*mm,j*10*mm,0), hclogic, "HCdetector", logicworld, false, 0,true);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3))-(15/sqrt(3)))*mm,((j*10)-(5))*mm,0), hclogic, "HCdetector", logicworld, false, 0,true);
        }
    }



    // new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), hclogic, "HCdetector", logicworld, false, 0,true);

    return physicalworld;

}


