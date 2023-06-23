#include "construction.hh"
#include "math.h"
scintillation1::scintillation1()
{}
scintillation1::~scintillation1()
{}
G4VPhysicalVolume *scintillation1::Construct()
{
    // Set up the dimensions of the honey comb detector
    G4double phiStart = - 0 * M_PI;
    G4double phiTotal =  2* M_PI; 
    G4int numZplanes = 2;
    G4int numSides=6;
    G4double rInner[]= {4.8*mm, 4.6*mm};
    G4double rOuter[] = {5*mm, 5*mm};
    G4double zPlanes[]={-2.5*mm,2.5*mm};
    G4double gInner[]= {0.01*mm, 0.01*mm};
    G4double gOuter[] = {4.6*mm, 4.6*mm};
    

    G4double atomicNumber = 29;
    G4double atomicMass = 63.55 * g/mole;
    G4double density1 = 8.96 * g/cm3;

    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    //Defining Elements
    G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* plastic = nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    G4Element* gold = nistManager->FindOrBuildElement("Au");
    G4Element* copper = nistManager->FindOrBuildElement("Cu");
    G4Element* argonGas = nistManager->FindOrBuildElement("Ar");
    //gold material
    G4Material* Au = new G4Material("Gold", 19.32 * g/cm3, 1);
    Au->AddElement(gold,1);
    //copper material
    G4Material* Cu = new G4Material("Copper", 8.96 * g/cm3, 1);
    Cu->AddElement(copper,1);
    //Carbon Monoxide
    G4double density = 1.25*g/L;
    G4Material* CO = new G4Material("CO",1.25*g/L,2);
    CO->AddElement(nistManager->FindOrBuildElement("C"), 1);
    CO->AddElement(nistManager->FindOrBuildElement("O"), 1);
    //Gas Mixture
    G4Material* gasMixture = new G4Material("GasMixture", 1.72 , 2);
    gasMixture->AddElement(argonGas, 0.9);
    gasMixture->AddMaterial(CO, 0.1);



    //Defining colours
    G4VisAttributes* vishc = new G4VisAttributes(G4Colour(1,0.72,0.243));
    vishc->SetForceSolid(true);

    G4VisAttributes* visgold = new G4VisAttributes(G4Colour(1,0.843,0));
    visgold->SetForceSolid(true);

    G4VisAttributes* visscintilation = new G4VisAttributes(G4Colour(0,0,1));
    visscintilation->SetForceSolid(true);

    G4VisAttributes* gas = new G4VisAttributes(G4Colour(0.85,0.85,1,0.3));
    gas->SetForceSolid(true);

    G4VisAttributes* WW = new G4VisAttributes(G4Colour(0.85,0.85,1,0));
    WW->SetForceSolid(true);

    G4bool checkoverlap = false;

    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2.5*m,2.5*m,2.5*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    logicworld->SetVisAttributes(WW);
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,checkoverlap);

    //Defining 2 Scintillation Detectors Detector
    G4Box* solidDetector = new G4Box("Detector1", 16*(30/sqrt(3))*mm,5*cm,1*cm);
    G4LogicalVolume* logicalDetector = new G4LogicalVolume(solidDetector, plastic, "Detector1");
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0*m, -1*m), logicalDetector, "Detector1", logicworld, false, 0,checkoverlap);
    new G4PVPlacement(nullptr, G4ThreeVector(0, 0*m,1*m), logicalDetector, "Detector2", logicworld, false, 0,checkoverlap);


    //Defining Honeycomb detector
    G4Polyhedra *hcdetector = new G4Polyhedra("HCD", phiStart,phiTotal,numSides,numZplanes,zPlanes,rInner, rOuter);
    G4LogicalVolume* hclogic = new G4LogicalVolume(hcdetector,Cu,"hclogic");
    hclogic->SetVisAttributes(vishc);
    for (int i = -15;i<=16;i++){
        for (int j = -15;j<=16;j++){
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3)))*mm,j*10*mm,0), hclogic, "HCdetector", logicworld, false, 0,checkoverlap);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3))-(15/sqrt(3)))*mm,((j*10)-(5))*mm,0), hclogic, "HCdetector", logicworld, false,j+i*100,checkoverlap);
        }
    }


    //Defining the Gold wire 
    G4Tubs *goldwire = new G4Tubs("goldwire",0,0.01*mm,2.5*mm,0,2*M_PI);
    G4LogicalVolume* goldlogic = new G4LogicalVolume(goldwire,Au,"goldlogic");
    goldlogic->SetVisAttributes(visgold);
    for (int i = -15;i<=16;i++){
        for (int j = -15;j<=16;j++){
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3)))*mm,j*10*mm,0), goldlogic, "goldwire", logicworld, false, 0,checkoverlap);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3))-(15/sqrt(3)))*mm,((j*10)-(5))*mm,0), goldlogic, "goldwire", logicworld, false, j+i*100,checkoverlap);
        }
    }

    //Filling the detector with argon/CO mixture
    G4Polyhedra *gassfill = new G4Polyhedra("gas", phiStart,phiTotal,numSides,numZplanes,zPlanes,gInner, gOuter);
    G4LogicalVolume* gaslogic = new G4LogicalVolume(gassfill,air,"gaslogic");
    gaslogic->SetVisAttributes(gas);
    for (int i = -15;i<=16;i++){
        for (int j = -15;j<=16;j++){
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3)))*mm,j*10*mm,0), gaslogic, "gasmix", logicworld, false, i+j*100,checkoverlap);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(30/sqrt(3))-(15/sqrt(3)))*mm,((j*10)-(5))*mm,0), gaslogic, "gasmix", logicworld, false, j+i*100,checkoverlap);
        }
    }

    
    return physicalworld;  
}

