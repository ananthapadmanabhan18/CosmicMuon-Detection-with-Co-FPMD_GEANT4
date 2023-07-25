#include "iostream"


#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "construction.hh"
#include "physics.hh"
#include "action.hh"
#include "G4MTRunManager.hh"

int main(int argc, char** argv){

    G4UIExecutive *ui = 0;

    #ifdef G4MULTITHREADED
    G4MTRunManager *runManager = new G4MTRunManager();
    #else
    G4RunManager *runManager = new G4RunManager();
    #endif


    runManager->SetUserInitialization(new detectorconstruction());
    runManager->SetUserInitialization(new physicslist());
    runManager->SetUserInitialization(new actioninitialization());
    runManager->Initialize();


    primarygenerator generator;

    // Loop to generate 10000 particles with different configurations
    int totalLines = 100000;
    for (int i = 0; i < totalLines; ++i) {
        // Generate the primaries with the data from the i-th line
        G4Event* event = new G4Event;
        generator.GeneratePrimaries(event, i);

        // Process your event and do the rest of the simulation

        // Clear the event for the next iteration
        delete event;
    }



    if(argc==1){
        ui = new G4UIExecutive(argc,argv);
    }
    

    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    if(ui){
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    }
    else{
        G4String command = "/control/execute ";
        G4String filename= argv[1];
        UImanager->ApplyCommand(command+filename);
    }


    return 0;
}