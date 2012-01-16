#include <iostream>
#include "protocols.h"
#include "Simulator.h"
#include "PersonCreation.h"
#include "LiftsMovement.h"
#include "Event.h"

int createEvents();

Simulator simulator;

int main(){
    createEvents();
    simulator.startSimulation();
    return 0;
}

int createEvents(){
    Event* temp_event1;
    Event* temp_event2;
    temp_event1 = new PersonCreation();
    temp_event2 = new LiftsMovement();
    simulator.events_scheduler.events.push_front(temp_event1);
    simulator.events_scheduler.events.push_front(temp_event2);
    simulator.events_scheduler.events.push_front(temp_event1);
    simulator.events_scheduler.events.push_front(temp_event2);
    simulator.events_scheduler.events.push_front(temp_event2);
    return 0;
}

