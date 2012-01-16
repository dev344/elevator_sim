#ifndef PROTOCOLS_H
#define PROTOCOLS_H

#include "macros.h"

using namespace std;

struct PersonMessage{
    int type;
    int val1;
    int val2;
    float val3;
};

struct PersonReply{
    int type;
    int arg;
};

struct ElevatorMessage{
    int type;
};

struct ElevatorReply{
    float floor;
    int direction;
};

struct SimulatorMessage{
    int type;
};

struct SimulatorReply{
    int type;
};
#endif
