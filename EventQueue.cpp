#include "EventQueue.h"

int EventQueue::schedule(){
    Event* temp_event;
    temp_event = events.front();
    temp_event->informOccurance();
    events.pop_front();
    events.push_back(temp_event);
}

