#include "action.hh"

actioninitialization::actioninitialization(){}

actioninitialization::~actioninitialization(){}


void actioninitialization::Build() const
{
    primarygenerator* generator = new primarygenerator();
    SetUserAction(generator);

    runaction* runact = new runaction();
    SetUserAction(runact);
}