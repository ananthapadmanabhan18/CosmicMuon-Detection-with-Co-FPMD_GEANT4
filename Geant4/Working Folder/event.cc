#include "event.hh"


eventaction::eventaction(runaction*){

    fEdep = 0;
}
eventaction::~eventaction(){
}



void eventaction::BeginOfEventAction(const G4Event*)
{
    fEdep=0;
}
void eventaction::EndOfEventAction(const G4Event*)
{
    G4cout<<"Energy Deposition:"<< fEdep<<G4endl;
}