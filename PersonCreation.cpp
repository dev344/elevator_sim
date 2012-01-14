#include "PersonCreation.h"
#include "Simulator.h"

extern Simulator simulator;

int PersonCreation::informOccurance(){
    // create SimulatorMessage here so that 
    // you inform to create a person.
    SimulatorMessage msg;
    msg.type = PERSON_CREATION;
    simulator.takeMessage(msg);
    return 0;
}
