#include "EventQueue.h"

int EventQueue::schedule(){
    int i;

    for ( i = 0; i < int(events.size()); i++)
    {
        events[i]->informOccurance();
    }
}

