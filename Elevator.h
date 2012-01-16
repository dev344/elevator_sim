#ifndef ELEVATOR_H
#define  ELEVATOR_H
#include "protocols.h"

class Elevator
{
    private:
    float floor;
    int direction;
    int findNextRequestingFloor(int);

    /*
     * Responsible for moving the lift.
     * Checks the simulator's waiting_people list 
     * and decides where to go.
     */
    int move();

    public: 
    ElevatorReply takeMessage(ElevatorMessage);
};
#endif
