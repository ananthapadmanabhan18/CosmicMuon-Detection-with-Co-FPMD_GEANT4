#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Material.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Polyhedra.hh"
#include "G4Colour.hh"
#include "G4OpenGLImmediateX.hh"
#include "G4Element.hh"
#include "G4SDManager.hh"





class scintillation1 : public G4VUserDetectorConstruction
{
    public:
        scintillation1();
        ~scintillation1();

        virtual G4VPhysicalVolume *Construct();
    private:
        G4LogicalVolume*gaslogic;   
        G4LogicalVolume*logicalDetector; 
        virtual void ConstructSDandFields();
};


#endif