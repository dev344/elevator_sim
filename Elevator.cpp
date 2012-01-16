#include "Elevator.h"
#include "Simulator.h"
#include "protocols.h"
#include <iostream>

extern Simulator simulator;

int Elevator::findNextRequestingFloor(int direction){
    int i;
    if((int(floor) == simulator.waiting_people.size()) && (direction == UP))
        return -1;
    if( (floor == 0.0) && (direction == DOWN) )
        return -1;

    for(i = int(floor); (i < simulator.waiting_people.size() + 1) && ( i > -1);
            i += ( 2*direction -1))
    {
        if(simulator.waiting_people[i].size() > 0)
            return i;
    }
    return -1;
}

int Elevator::move(){
    // TODO proper lift movement$
    int next_requesting_floor;
    if((floor - float(int(floor))) == 0.0)
    {
        // decide something
        next_requesting_floor = findNextRequestingFloor(direction);
        if(next_requesting_floor == -1)
        {
            direction = (direction + 1 )% 2 ;
            next_requesting_floor = findNextRequestingFloor(direction);
            if(next_requesting_floor == -1)
            {
                return 0;
            }
        }
    }

    // At this point the direction will be set.
    // So, we just have to go in that direction.
    if( direction == UP ) 
    {

        floor+= 0.5;
    }
    else 
    {
        floor -= 0.5;
    }
    cout << " Moved to " << floor << endl;
    return 0;
}

ElevatorReply Elevator::takeMessage(ElevatorMessage msg){
    ElevatorReply reply;
    if(msg.type == LIFTS_MOVEMENT)
    {
        move();
    }
    else
    {
    cout << " i got a message ... duda duda!!" << endl;
    }
    reply.floor = floor;
    reply.direction = direction;
    return reply;
}
