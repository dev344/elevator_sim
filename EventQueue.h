#include <deque>
#include "protocols.h"
#include "Event.h"


class EventQueue{
    public:
    deque<Event*> events;
    int schedule();
};
