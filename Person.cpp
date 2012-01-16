#include "Person.h"
#include "Simulator.h"
#include <stdlib.h>
#include <time.h>

extern Simulator simulator;


Person::Person(){
    in_elevator = -1;
    srand(time(NULL));
    destinationFloor =  rand() % 4;
    srand(time(NULL));
    startFloor = rand()%4;
    if ( startFloor == destinationFloor)
    {
        startFloor = (destinationFloor + 1 )%4;
    }
    simulator.waiting_people[startFloor].push_back(this);
}

PersonReply Person::takeMessage(PersonMessage msg){
    int my_direction;
    PersonReply reply;
    if((destinationFloor - startFloor) > 0)
        my_direction = 1;
    else
        my_direction = 0;

    if(in_elevator != -1)
    {
        if(in_elevator == msg.val1)
        {
            if(destinationFloor == msg.val3)
            {
                // TODO : get out of the lift 
                // and DIE!!!
                reply.type = KILL_ME_NOW;
                reply.arg = in_elevator;
            }
        }
        return reply;
    }
    if( msg.val2 == my_direction )
    {
        if((msg.val3 - float(startFloor)) == 0.0)
        {
            // TODO get out of the waiting queue
            simulator.elevator_occupants[msg.val1].push_front(this);
            in_elevator = msg.val1;
            cerr << "I am " << this << " and my elev is " << in_elevator << endl;
            cout << "Got a lift" << endl;
            reply.type = NOT_WAITING;
            reply.arg = startFloor;
        }
    }
    return reply;
    // Simulator tells whether lift came or
    // lift floor.
    //
    // next
    //
    // Simulator tells which floor the lift
    // is in. So decide what you want to do
    // depending on that.
    //  
    //  or
    //
    // You reply whether to get on or not.
}
