#include "construction.hh"
#include "G4Tubs.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}
MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    // Create the detector material
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* detectorMaterial = nistManager->FindOrBuildMaterial("G4_AIR");

    // Set detector dimensions
    G4double cellThickness = 5.0 * mm;
    G4double cellSide = 5.0 * mm;
    G4int numCellsX = 96;
    G4int numCellsY = 48;

    // Calculate detector dimensions
    G4double detectorWidth = numCellsX * cellSide;
    G4double detectorHeight = numCellsY * cellSide;
    G4double detectorThickness = cellThickness;

    // Create the detector solid volume
    G4Box* detectorSolid = new G4Box("Detector", detectorWidth / 2, detectorHeight / 2, detectorThickness / 2);

    // Create the detector logical volume
    G4LogicalVolume* detectorLogical = new G4LogicalVolume(detectorSolid, detectorMaterial, "DetectorLogical");

    // Create the honeycomb cell solid volume
    G4Tubs* cellSolid = new G4Tubs("Cell", 0, cellSide / 2, detectorThickness / 2, 0, 2 * M_PI);

    // Create the honeycomb cell logical volume
    G4LogicalVolume* cellLogical = new G4LogicalVolume(cellSolid, detectorMaterial, "CellLogical");

    // Place the cells in a honeycomb pattern
    for (int i = 0; i < numCellsX; ++i) {
        for (int j = 0; j < numCellsY; ++j) {
        G4double x = (i + 0.5 * (j % 2)) * cellSide - 0.5 * detectorWidth;
        G4double y = j * cellSide - 0.5 * detectorHeight;
        G4double z = 0.0;

        G4VPhysicalVolume* cellPhysical = new G4PVPlacement(nullptr, G4ThreeVector(x, y, z), cellLogical, "CellPhysical", detectorLogical, false, 0);
        }
    }

    // Set the logical volume as the world volume
    G4LogicalVolume* worldLogical = detectorLogical;
    G4VPhysicalVolume* worldPhysical = new G4PVPlacement(nullptr, G4ThreeVector(), worldLogical, "WorldPhysical", nullptr, false, 0);

}





// G4VPhysicalVolume *MyDetectorConstruction::Construct()
// {
//     G4NistManager *nist = G4NistManager::Instance();
//     G4Material *worldMat = nist->FindOrBuildMaterial("G4_WATER");
//     G4Box *solidWorld = new G4Box("solidWorld",0.5*m,0.05*m,0.1*m);
//     G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat,"logicWorld");
//     G4VPhysicalVolume *physWorld = new G4PVPlacement(0,G4ThreeVector(0,0,0),logicWorld, "physWorld", 0, false,0,true);
//     return physWorld;
// }