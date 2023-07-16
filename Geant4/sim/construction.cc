#include "construction.hh"

detectorconstruction::detectorconstruction(){}

detectorconstruction::~detectorconstruction(){}


G4VPhysicalVolume *detectorconstruction::Construct(){

    // Define materials
    G4NistManager* nistManager = G4NistManager::Instance();
    //Defining Elements
    G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");
    G4Material* plastic = nistManager->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    G4Element* gold = nistManager->FindOrBuildElement("Au");
    G4Element* copper = nistManager->FindOrBuildElement("Cu");
    G4Element* argonGas = nistManager->FindOrBuildElement("Ar");
    G4Element* Aluminium = nistManager->FindOrBuildElement("Al");
    G4Element* Hydrogen = nistManager->FindOrBuildElement("H");
    G4Element* Silicon = nistManager->FindOrBuildElement("Si");
    G4Element* carbon = nistManager->FindOrBuildElement("C");
    G4Element* oxygen = nistManager->FindOrBuildElement("O");

    //Aluminium
    G4Material* Al = new G4Material("Aluminium", 2.7 * g/cm3, 1);
    Al->AddElement(Aluminium,1);    
    //gold material
    G4Material* Au = new G4Material("Gold", 19.32 * g/cm3, 1);
    Au->AddElement(gold,1);
    //copper material
    G4Material* Cu = new G4Material("Copper", 8.96 * g/cm3, 1);
    Cu->AddElement(copper,1);
    //Carbon Monoxide
    G4Material* CO = new G4Material("CO",1.25*g/L,2);
    CO->AddElement(nistManager->FindOrBuildElement("C"), 1);
    CO->AddElement(nistManager->FindOrBuildElement("O"), 1);
    //Gas Mixture
    G4Material* gasMixture = new G4Material("GasMixture", 1.72*g/L , 2);
    gasMixture->AddElement(argonGas, 0.9);
    gasMixture->AddMaterial(CO, 0.1);
    //FR4
    G4Material* fr4 = new G4Material("fr4", 1.85*g/cm3 , 4);
    fr4->AddElement(Hydrogen, 0.475);
    fr4->AddElement(carbon, 0.285);
    fr4->AddElement(oxygen, 0.175);
    fr4->AddElement(Silicon, 0.065);


    //Defining colours
    G4VisAttributes* vishc = new G4VisAttributes(G4Colour(1,0.72,0.243));
    vishc->SetForceSolid(true);

    G4VisAttributes* visstandplane = new G4VisAttributes(G4Colour(105/173,1,45/173));
    visstandplane->SetForceSolid(true);


    G4VisAttributes* visgold = new G4VisAttributes(G4Colour(1,0.843,0));
    visgold->SetForceSolid(true);

    G4VisAttributes* visstand = new G4VisAttributes(G4Colour(.7922,0.8,0.8078));
    visstand->SetForceSolid(true);

    G4VisAttributes* visPCB = new G4VisAttributes(G4Colour(1.0, 0.9, 0.6));
    visPCB->SetForceSolid(true);
    G4VisAttributes* viselect = new G4VisAttributes(G4Colour(0.7, 0.7, 0.0));
    viselect->SetForceSolid(true);

    G4VisAttributes* visscintilation = new G4VisAttributes(G4Colour(0.4, 0.2, 0.0));
    visscintilation->SetForceSolid(true);

    G4VisAttributes* gas = new G4VisAttributes(G4Colour(0.85,0.85,1,0.3));
    gas->SetForceSolid(true);

    G4VisAttributes* WW = new G4VisAttributes(G4Colour(0.85,0.85,1,0));
    WW->SetForceSolid(true);

    G4bool checkoverlap = false;


    //Defining World Volume
    G4Box *solidworld = new G4Box("world",2.5*m,2.5*m,2.5*m);
    G4LogicalVolume *logicworld = new G4LogicalVolume(solidworld, air,"logicalworld");
    G4VPhysicalVolume *physicalworld = new G4PVPlacement(nullptr,G4ThreeVector(0,0,0),logicworld, "physicalworld", nullptr, false,0,checkoverlap);
    // logicworld->SetVisAttributes(WW);



    // //Defining 2 Scintillation Detectors Detector
    // G4Box* solidDetector = new G4Box("Detector1", 1.15*cm,11.25*cm,0.5*cm);
    // G4LogicalVolume* logicalDetector = new G4LogicalVolume(solidDetector, plastic, "Detector1");
    // new G4PVPlacement(nullptr, G4ThreeVector(0, 15*mm, -11.5*cm), logicalDetector, "Detector1", logicworld, false, 0,checkoverlap);
    // new G4PVPlacement(nullptr, G4ThreeVector(0, 15*mm,11.5*cm), logicalDetector, "Detector2", logicworld, false, 0,checkoverlap);
    // logicalDetector->SetVisAttributes(visscintilation);

    // Set up the dimensions of the honey comb detector
    G4double phiStart = - 0 * M_PI;
    G4double phiTotal =  2* M_PI; 
    G4int numZplanes = 2;
    G4int numSides=6;
    G4double rInner[]= {2.4*mm, 2.4*mm};
    G4double rOuter[] = {2.5*mm, 2.5*mm};
    G4double zPlanes[]={-2.5*mm,2.5*mm};
    G4double gInner[]= {0.01*mm, 0.01*mm};
    G4double gOuter[] = {2.4*mm, 2.4*mm};



    //Defining Honeycomb detector
    G4Polyhedra *hcdetector = new G4Polyhedra("HCD", phiStart,phiTotal,numSides,numZplanes,zPlanes,rInner, rOuter);
    G4LogicalVolume* hclogic = new G4LogicalVolume(hcdetector,Cu,"hclogic");
    hclogic->SetVisAttributes(vishc);



    //Defining the Gold wire 
    G4Tubs *goldwire = new G4Tubs("goldwire",0,0.01*mm,2.5*mm,0,2*M_PI);
    G4LogicalVolume* goldlogic = new G4LogicalVolume(goldwire,Au,"goldlogic");
    goldlogic->SetVisAttributes(visgold);


    //Filling the detector with argon/CO mixture
    G4Polyhedra *gassfill = new G4Polyhedra("gas", phiStart,phiTotal,numSides,numZplanes,zPlanes,gInner, gOuter);
    gaslogic = new G4LogicalVolume(gassfill,air,"gaslogic");
    gaslogic->SetVisAttributes(gas);
    
    
    //Placing the logic volumes of HoneyComb
    for (int i = -23;i<=24;i++){
        for (int j = -23;j<=24;j++){

            // new G4PVPlacement(nullptr, G4ThreeVector(i*(15/sqrt(3))*mm,j*(5)*mm,0), hclogic, "HCdetector", logicworld, false, 0,checkoverlap);
            // new G4PVPlacement(nullptr, G4ThreeVector((i*(15/sqrt(3))-(7.5/sqrt(3)))*mm,((j*5)-(2.5))*mm,0), hclogic, "HCdetector", logicworld, false,j+i*100,checkoverlap);

            // new G4PVPlacement(nullptr, G4ThreeVector(i*(15/sqrt(3))*mm,j*(5)*mm,0), goldlogic, "goldwire", logicworld, false, 0,checkoverlap);
            // new G4PVPlacement(nullptr, G4ThreeVector((i*(15/sqrt(3))-(7.5/sqrt(3)))*mm,((j*5)-(2.5))*mm,0), goldlogic, "goldwire", logicworld, false, j+i*100,checkoverlap);


            new G4PVPlacement(nullptr, G4ThreeVector(i*(15/sqrt(3))*mm,j*(5)*mm,0), gaslogic, "gasmix", logicworld, false, i+j*100,checkoverlap);
            new G4PVPlacement(nullptr, G4ThreeVector((i*(15/sqrt(3))-(7.5/sqrt(3)))*mm,((j*5)-(2.5))*mm,0), gaslogic, "gasmix", logicworld, false, j+i*100,checkoverlap);
        }

    }


    // //The Round things
    // G4Tubs *round1 = new G4Tubs("round",0,1.15*cm,2*cm,0,2*M_PI);    
    // G4RotationMatrix* rotmat = new G4RotationMatrix;
    // rotmat->rotateX(90*deg);
    // G4LogicalVolume* round1logic = new G4LogicalVolume(round1,plastic,"roundlogic");
    // new G4PVPlacement(rotmat, G4ThreeVector(0,-12.75*cm+1*cm,11.5*cm), round1logic, "bleh", logicworld, false, 0,checkoverlap);
    // new G4PVPlacement(rotmat, G4ThreeVector(0,-12.75*cm+1*cm,-11.5*cm), round1logic, "bleh", logicworld, false, 0,checkoverlap);

    // G4Tubs *round2 = new G4Tubs("round",0,1.65*cm,1.6*cm,0,2*M_PI);  
    // G4LogicalVolume* round2logic = new G4LogicalVolume(round2,plastic,"roundlogic");
    // new G4PVPlacement(rotmat, G4ThreeVector(0,-16.35*cm+1*cm,11.5*cm), round2logic, "bleh", logicworld, false, 0,checkoverlap);
    // new G4PVPlacement(rotmat, G4ThreeVector(0,-16.35*cm+1*cm,-11.5*cm), round2logic, "bleh", logicworld, false, 0,checkoverlap);


    // G4Tubs *round3 = new G4Tubs("round",0,1.15*cm,5.5*cm,0,2*M_PI);  
    // G4LogicalVolume* round3logic = new G4LogicalVolume(round3,plastic,"roundlogic");
    // new G4PVPlacement(rotmat, G4ThreeVector(0,-23.45*cm+1*cm,11.5*cm), round3logic, "bleh", logicworld, false, 0,checkoverlap);
    // new G4PVPlacement(rotmat, G4ThreeVector(0,-23.45*cm+1*cm,-11.5*cm), round3logic, "bleh", logicworld, false, 0,checkoverlap);


    // round1logic->SetVisAttributes(visscintilation);
    // round2logic->SetVisAttributes(visscintilation);
    // round3logic->SetVisAttributes(visscintilation);

    // //Defining the PCB
    // // G4Box* pcb = new G4Box("pcb", ((15/sqrt(3))*24+(7.5/sqrt(3)))*mm,(12.5)*cm,1.25*mm);
    // G4Box* pcb = new G4Box("pcb",245*mm,(12.5)*cm,1.25*mm);
    // G4LogicalVolume* pcblogic = new G4LogicalVolume(pcb, fr4, "PCB");
    // new G4PVPlacement(nullptr, G4ThreeVector(-15/sqrt(3)*0*mm, -5*0*mm, -3.75*mm), pcblogic, "PCB1", logicworld, false, 0,checkoverlap);
    // new G4PVPlacement(nullptr, G4ThreeVector(-15/sqrt(3)*0*mm, -5*0*mm,3.75*mm), pcblogic, "PCB2", logicworld, false, 0,checkoverlap);
    // pcblogic->SetVisAttributes(visPCB);



    // //Defining the Stand  
    // G4double phitotalstand=M_PI;
    // G4int standsidenum=2;
    // G4int planestandno =2;
    // G4double zPlanestand[] = {-15*cm,15*cm};
    // G4double standouter[]={1.25*cm,1.25*cm};
    // G4double standinner[]={0.75*cm,0.75*cm};

    // G4Box* standplane = new G4Box("standplane", 26*cm,15*cm,1.25*mm);
    // G4LogicalVolume* standplanelogic = new G4LogicalVolume(standplane, plastic, "standplane");
    // new G4PVPlacement(nullptr, G4ThreeVector(-15/sqrt(3)*0*mm, -5*0*mm, -6.25*mm), standplanelogic, "standplane", logicworld, false, 0,checkoverlap);
    // standplanelogic->SetVisAttributes(visstandplane);

    // G4Box* standsq = new G4Box("standsq", 26*cm,1*cm,1*cm);
    // G4LogicalVolume* standsqlogic = new G4LogicalVolume(standsq, Al, "standsq");
    // new G4PVPlacement(nullptr, G4ThreeVector(0,-16*cm,-2*cm), standsqlogic, "standsq", logicworld, false, 0,checkoverlap);
    // new G4PVPlacement(nullptr, G4ThreeVector(0,-16*cm,-29.75*cm), standsqlogic, "standsq", logicworld, false, 0,checkoverlap);
    // standsqlogic->SetVisAttributes(visstand);

    // G4Box* standsu = new G4Box("standsu", 1*cm,1*cm,50*cm);
    // G4LogicalVolume* standsulogic = new G4LogicalVolume(standsu, Al, "standsu");
    // new G4PVPlacement(nullptr, G4ThreeVector(-5*cm,-18*cm,19.5*cm), standsulogic, "standsu", logicworld, false, 0,checkoverlap);
  
    // standsulogic->SetVisAttributes(visstand);

    // G4Box* suplane = new G4Box("suplane", 1*mm,15*cm,2*cm);
    // G4LogicalVolume* suplanelogic = new G4LogicalVolume(suplane, Al, "suplane");
    // new G4PVPlacement(nullptr, G4ThreeVector(26.25*cm,0,-2.25*cm), suplanelogic, "suplane", logicworld, false, 0,checkoverlap); 
    // // new G4PVPlacement(nullptr, G4ThreeVector(26.25*cm,0,-26*cm), suplanelogic, "suplane", logicworld, false, 0,checkoverlap);    
    // suplanelogic->SetVisAttributes(visstand);

    // G4Box* suplane1 = new G4Box("suplane1", 25*cm,14*cm,1.25*mm);
    // G4LogicalVolume* suplane1logic = new G4LogicalVolume(suplane1, Al, "suplane1");
    // new G4PVPlacement(nullptr, G4ThreeVector(0*cm,0,-28.75*cm), suplane1logic, "suplane1", logicworld, false, 0,checkoverlap); 
    // suplane1logic->SetVisAttributes(visstand);

    // G4Box* suplane2 = new G4Box("suplane2", 1*mm,15*cm,15*cm);
    // G4LogicalVolume* suplane2logic = new G4LogicalVolume(suplane2,plastic, "suplane2");
    // new G4PVPlacement(nullptr, G4ThreeVector(-26.25*cm,0,-15.5*cm), suplane2logic, "suplane2", logicworld, false, 0,checkoverlap); 
    // suplane2logic->SetVisAttributes(visstandplane);

    // G4Box* bar1 = new G4Box("bar1", 0.5*mm,9.5*cm,6.25*cm);
    // G4LogicalVolume* bar1logic = new G4LogicalVolume(bar1,plastic, "bar1");
    // new G4PVPlacement(nullptr, G4ThreeVector(-3.9*cm,-21*cm,-11.5*cm), bar1logic, "bar1", logicworld, false, 0,checkoverlap); 
    // bar1logic->SetVisAttributes(visstandplane);

    // G4Box* bar2 = new G4Box("bar2", 5*cm,0.5*mm,5*cm);
    // G4LogicalVolume* bar2logic = new G4LogicalVolume(bar2,Al, "bar2");
    // new G4PVPlacement(nullptr, G4ThreeVector(-7.30*cm,-19.05*cm,11.5*cm), bar2logic, "bar2", logicworld, false, 0,checkoverlap); 
    // bar2logic->SetVisAttributes(visstand);

    // // G4Box* elect = new G4Box("elect", ((15/sqrt(3))*24+(7.5/sqrt(3)))*mm,(12.5)*cm,5*mm);
    // G4Box* elect = new G4Box("elect",245*mm,(12.5)*cm,5*mm);
    // G4LogicalVolume* electlogic = new G4LogicalVolume(elect,fr4, "elect");
    // new G4PVPlacement(nullptr, G4ThreeVector(0*mm,0*mm,1*cm), electlogic, "elect", logicworld, false, 0,checkoverlap); 
    // electlogic->SetVisAttributes(viselect);


    // G4Box* pins = new G4Box("pins",1*cm,1.5*mm,2.5*mm);
    // G4LogicalVolume* pinlogic = new G4LogicalVolume(pins,fr4, "pin");
    // for (int n = 1;n<=12;n++){
    //     for (int j = 1;j<=12;j++){
    //     new G4PVPlacement(nullptr, G4ThreeVector((4*n-26)*cm,(-13+2*j)*cm,17.5*mm), pinlogic, "pin", logicworld, false, 0,checkoverlap);
    //     }
    // }
     
    // pinlogic->SetVisAttributes(visscintilation);


    // //defining the stand legs
    // G4Polyhedra *stand1 = new G4Polyhedra("HCD", -45*deg,phitotalstand,standsidenum,planestandno,zPlanestand,standinner, standouter);
    // G4LogicalVolume* stand1logic = new G4LogicalVolume(stand1,Al,"stand1");
    // new G4PVPlacement(nullptr, G4ThreeVector(24.75*cm,13.75*cm,-15.75*cm), stand1logic, "stand1", logicworld, false, 0,checkoverlap);

    // G4Polyhedra *stand2 = new G4Polyhedra("HCD", 45*deg,phitotalstand,standsidenum,planestandno,zPlanestand,standinner, standouter);
    // G4LogicalVolume* stand2logic = new G4LogicalVolume(stand2,Al,"stand2");    
    // new G4PVPlacement(nullptr, G4ThreeVector(-24.75*cm,13.75*cm,-15.75*cm), stand2logic, "stand2", logicworld, false, 0,checkoverlap);


    // G4Polyhedra *stand3 = new G4Polyhedra("HCD", 135*deg,phitotalstand,standsidenum,planestandno,zPlanestand,standinner, standouter);
    // G4LogicalVolume* stand3logic = new G4LogicalVolume(stand3,Al,"stand3");
    // new G4PVPlacement(nullptr, G4ThreeVector(-24.75*cm,-13.75*cm,-15.75*cm), stand3logic, "stand3", logicworld, false, 0,checkoverlap);

    // G4Polyhedra *stand4 = new G4Polyhedra("HCD", 225*deg,phitotalstand,standsidenum,planestandno,zPlanestand,standinner, standouter);
    // G4LogicalVolume* stand4logic = new G4LogicalVolume(stand4,Al,"stand4");    
    // new G4PVPlacement(nullptr, G4ThreeVector(24.75*cm,-13.75*cm,-15.75*cm), stand4logic, "stand4", logicworld, false, 0,checkoverlap);

    // stand1logic->SetVisAttributes(visstand);
    // stand2logic->SetVisAttributes(visstand);
    // stand3logic->SetVisAttributes(visstand);
    // stand4logic->SetVisAttributes(visstand);



    return physicalworld;




}



void detectorconstruction::ConstructSDandField(){
    sensitivedetector *sensdet = new sensitivedetector("SD");
    gaslogic->SetSensitiveDetector(sensdet);
}