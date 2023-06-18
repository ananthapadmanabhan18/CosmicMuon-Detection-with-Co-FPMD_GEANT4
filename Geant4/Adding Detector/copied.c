// DetectorConstruction.cc

// #include "DetectorConstruction.hh"

// #include "G4NistManager.hh"
// #include "G4LogicalVolume.hh"
// #include "G4PVPlacement.hh"
// #include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction(G4double detector1Width, G4double detector1Height, G4double detector1Length,
                                           G4double detector2Width, G4double detector2Height, G4double detector2Length)
    : G4VUserDetectorConstruction(),
      detector1Width(detector1Width),
      detector1Height(detector1Height),
      detector1Length(detector1Length),
      detector2Width(detector2Width),
      detector2Height(detector2Height),
      detector2Length(detector2Length) {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* detectorMaterial = nistManager->FindOrBuildMaterial("G4_Ge");

    // Define the world volume
    G4double worldSize = 2.0*m;
    G4Box* solidWorld = new G4Box("World", 0.5*worldSize, 0.5*worldSize, 0.5*worldSize);
    G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physicalWorld = new G4PVPlacement(nullptr, G4ThreeVector(), logicalWorld, "World", nullptr, false, 0);

    // Define detector 1 volume
    G4Box* solidDetector1 = new G4Box("Detector1", 0.5*detector1Width, 0.5*detector1Height, 0.5*detector1Length);
    G4LogicalVolume* logicalDetector1 = new G4LogicalVolume(solidDetector1, detectorMaterial, "Detector1");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0, 0), logicalDetector1, "Detector1", logicalWorld, false, 0);

    // Define detector 2 volume
    G4Box* solidDetector2 = new G4Box("Detector2", 0.5*detector2Width, 0.5*detector2Height, 0.5*detector2Length);
    G4LogicalVolume* logicalDetector2 = new G4LogicalVolume(solidDetector2, detectorMaterial, "Detector2");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0, detector1Length + 1.0*m + 0.5*detector2Length), logicalDetector2, "Detector2", logicalWorld, false, 0);

    // Set the logical world volume as the user detector
    SetLogicalVolume(logicalWorld);

    return physicalWorld;
}






    G4NistManager *nist = G4NistManager::Instance();
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_WATER");

    //Defining World Volume
    G4Box *sbox1 = new G4Box("world",1*m,0.05*m,0.1*m);
    G4LogicalVolume *lbox1 = new G4LogicalVolume(sbox1, worldMat,"lbox1");
    G4VPhysicalVolume *pbox1 = new G4PVPlacement(0,G4ThreeVector(0,0,0),lbox1, "pbox1", 0, false,0,true);
    return pbox1;