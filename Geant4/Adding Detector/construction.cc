#include "construction.hh"
#include "G4LogicalVolume.hh"
scintillation1::scintillation1()
{}
scintillation1::~scintillation1()
{}
G4VPhysicalVolume *scintillation1::Construct()
{
    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* detectorMaterial = nistManager->FindOrBuildMaterial("G4_Ge");

    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2*m,2*m,2*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,true);
    return physicalworld;

    //defining 1st detector
    G4Box* solidDetector1 = new G4Box("Detector1", 1*m,0.05*m,0.1*m);
    G4LogicalVolume* logicalDetector1 = new G4LogicalVolume(solidDetector1, detectorMaterial, "Detector1");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0, 0), logicalDetector1, "Detector1", logicworld, false, 0);

    //defining 2nd Detector
    G4Box* solidDetector2 = new G4Box("Detector2", 1*m,0.05*m,0.1*m);
    G4LogicalVolume* logicalDetector2 = new G4LogicalVolume(solidDetector2, detectorMaterial, "Detector2");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0,1*m), logicalDetector2, "Detector2", logicworld, false, 0);
    // SetLogicalVolume(logicworld);
    return physicalworld;

}


