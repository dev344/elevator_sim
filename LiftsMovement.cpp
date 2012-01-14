#include "LiftsMovement.h"
#include "Simulator.h"

extern Simulator simulator;

int LiftsMovement::informOccurance(){
    SimulatorMessage msg;
    msg.type = LIFTS_MOVEMENT;
    simulator.takeMessage(msg);
    return 0;
}
