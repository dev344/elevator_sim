#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <deque>

#include "protocols.h"
#include "macros.h"
#include "Person.h"
#include "Elevator.h"
#include "EventQueue.h"

class Simulator{
    public:
    deque<Person*> all_people;
    deque< deque<Person*> > waiting_people;
    deque< deque<Person*> > elevator_occupants;
    EventQueue events_scheduler;
    deque<Elevator*> elevators;
    
    /*
     * A constuctor.
     */
    Simulator();

    /*
     * Main function which starts the simulation
     * and whose each loop is equivalent to 1 sec.
     */
    int startSimulation();
    SimulatorReply takeMessage(SimulatorMessage);
};

#endif
