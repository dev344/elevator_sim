#ifndef PERSON_H
#define PERSON_H

#include "protocols.h"

class Person
{
    private:
    int destinationFloor;
    int startFloor;
    int in_elevator;

    public: 
    /*
     * A constructor.
     * Generates a random destination and enques 
     * the person into a random floor.
     */
    Person();

    /*
     *
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
    */
    PersonReply takeMessage(PersonMessage);
};

#endif
