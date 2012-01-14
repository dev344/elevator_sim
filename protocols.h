#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include "macros.h"

using namespace std;

struct PersonMessage{
    int type;
    int val1;
    int val2;
};

struct PersonReply{
    int type;
};

struct ElevatorMessage{
    int type;
};

struct ElevatorReply{
    int floor;
};

struct SimulatorMessage{
    int type;
};

struct SimulatorReply{
    int type;
};
#endif
