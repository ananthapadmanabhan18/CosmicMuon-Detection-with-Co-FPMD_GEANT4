#include "action.hh"

actioninitialization::actioninitialization(){}

actioninitialization::~actioninitialization(){}


void actioninitialization::BuildForMaster() const {

    runaction* runact = new runaction();
    SetUserAction(runact);

}



void actioninitialization::Build() const
{
    primarygenerator* generator = new primarygenerator();
    SetUserAction(generator);

    runaction* runact = new runaction();
    SetUserAction(runact);


    eventaction* eventact = new eventaction(runact);
    SetUserAction(eventact);

    steppingaction* stepact = new steppingaction(eventact);
    SetUserAction(stepact);
}