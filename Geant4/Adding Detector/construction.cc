#include "construction.hh"
#include "G4LogicalVolume.hh"
scintillation1::scintillation1()
{}
scintillation1::~scintillation1()
{}
G4VPhysicalVolume *scintillation1::Construct()
{
    G4double zp[] =  {0,5.0*mm};
    G4double ir[]= {0,5.0*mm};

    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* air = nistManager->FindOrBuildMaterial("G4_Al");
    G4Material* detectorMaterial = nistManager->FindOrBuildMaterial("G4_Ge");

    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2.5*m,2.5*m,2.5*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,true);

    //defining 1st detector
    G4Box* solidDetector1 = new G4Box("Detector1", 1*m,0.05*m,0.1*m);
    G4LogicalVolume* logicalDetector1 = new G4LogicalVolume(solidDetector1, detectorMaterial, "Detector1");
    new G4PVPlacement(nullptr, G4ThreeVector(0, -1*m, 0), logicalDetector1, "Detector1", logicworld, false, 0,true);

    //defining 2nd Detector
    G4Box* solidDetector2 = new G4Box("Detector2", 1*m,0.05*m,0.1*m);
    G4LogicalVolume* logicalDetector2 = new G4LogicalVolume(solidDetector2, detectorMaterial, "Detector2");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 1*m,0), logicalDetector2, "Detector2", logicworld, false, 0,true);

    //defining Honeycomb detector
    // G4Tubs* hcdetector = new G4Tubs("honeycomb",0,5*mm,2.5*mm,0,2*M_PI);
    G4Polyhedra *hcdetector = new G4Polyhedra("DetectorSolid",0,360 * deg,6,2,zp,ir,ir);
    G4LogicalVolume* hclogic = new G4LogicalVolume(hcdetector,detectorMaterial,"hclogic");
    new G4PVPlacement(nullptr, G4ThreeVector(0,0,0), logicalDetector1, "HCdetector", logicworld, false, 0,true);





    // return new G4PVPlacement(nullptr, G4ThreeVector(), logicworld, "World", nullptr, false, 0,true);
    return physicalworld;

}


