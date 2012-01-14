#include "protocols.h"

class Elevator
{
    private:
    float floor;

    public: 
    ElevatorReply takeMessage(ElevatorMessage);
};
