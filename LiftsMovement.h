#include "Event.h"
#include "protocols.h"

class LiftsMovement: public Event {
    public:
    LiftsMovement()
    {
    }

    int informOccurance();
};
