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
    Event* temp_event;
    temp_event = new PersonCreation();
    simulator.events_scheduler.events.push_front(temp_event);
    temp_event = new PersonCreation();
    simulator.events_scheduler.events.push_front(temp_event);
    temp_event = new PersonCreation();
    simulator.events_scheduler.events.push_front(temp_event);
    temp_event = new PersonCreation();
    simulator.events_scheduler.events.push_front(temp_event);
    temp_event = new LiftsMovement();
    simulator.events_scheduler.events.push_front(temp_event);
    return 0;
}

