#include "construction.hh"

detectorconstruction::detectorconstruction(){}

detectorconstruction::~detectorconstruction(){}


G4VPhysicalVolume *detectorconstruction::Construct(){

    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* plastic = nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");



    //Defining colours
    G4VisAttributes* ironColour = new G4VisAttributes(G4Colour(0.6314,0.6157,0.5804));
    ironColour->SetForceSolid(true);
    G4VisAttributes* aircolour = new G4VisAttributes(G4Colour(0.85,0.85,1,0.3));
    aircolour->SetForceSolid(true);
    G4VisAttributes* WW = new G4VisAttributes(G4Colour(0.85,0.85,1,0));
    WW->SetForceSolid(true);
    G4bool checkoverlap = true;


    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2.5*m,2.5*m,2.5*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,checkoverlap);



    //Defining the OutSide Detector detector Volmune
    G4Box *outDet = new G4Box("Box",((1.875*mm)+(43.45*cm))/2,((1.875*mm)+(43.45*cm))/2,(1.5/2)*cm);
    G4LogicalVolume* outDetLogic = new G4LogicalVolume(outDet, air, "OutSide");
    new G4PVPlacement(nullptr, G4ThreeVector(0,0,0),outDetLogic , "OutSideLogic", logicworld, false, 0,checkoverlap);
    outDetLogic->SetVisAttributes(aircolour);


    G4Box *FeDet = new G4Box("DetectorCell",(1.975*cm)/2,(1.975*cm)/2,(1.5*cm)/2);
    G4LogicalVolume* FeDetLogic = new G4LogicalVolume(FeDet, air, "FeLogic");
    new G4PVPlacement(nullptr, G4ThreeVector(0,0,0),FeDetLogic , "FeLogic", outDetLogic, false, 0,checkoverlap);
    FeDetLogic->SetVisAttributes(ironColour);







    return physicalworld;
}



void detectorconstruction::ConstructSDandField(){
    // sensitivedetector *sensdet = new sensitivedetector("SD");
    // logicalDetector->SetSensitiveDetector(sensdet);
}
