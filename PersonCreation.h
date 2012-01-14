#include "Event.h"
#include "protocols.h"

class PersonCreation: public Event {
    public:
    PersonCreation()
    {
    }

    int informOccurance();
};

