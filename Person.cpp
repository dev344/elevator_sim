#include "Person.h"
#include "Simulator.h"
#include <stdlib.h>
#include <time.h>

extern Simulator simulator;


Person::Person(){
    srand(time(NULL));
    destination =  rand() % 4;
}

PersonReply Person::takeMessage(PersonMessage msg){

    cout << "Informed about movement of some lift" << endl;
    PersonReply reply;
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
