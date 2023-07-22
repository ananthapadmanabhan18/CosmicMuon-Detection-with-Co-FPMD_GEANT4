#include "action.hh"

actioninitialization::actioninitialization(){}

actioninitialization::~actioninitialization(){}


void actioninitialization::BuildForMaster() const {

    runaction* runact = new runaction();
    SetUserAction(runact);
    
    //primarygenerator* generator = new primarygenerator();
    //SetUserAction(generator);
}



void actioninitialization::Build() const
{
    primarygenerator* generator = new primarygenerator();
    SetUserAction(generator);

    runaction* runact = new runaction();
    SetUserAction(runact);
}
