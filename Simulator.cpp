#include "Simulator.h"
#include <stdlib.h>
#include <time.h>

Simulator::Simulator(){
    deque<Person*> temp;
    waiting_people.push_back(temp);
    waiting_people.push_back(temp);
    waiting_people.push_back(temp);
    waiting_people.push_back(temp);

    Elevator* temp_elevator;
    temp_elevator = new Elevator();
    elevators.push_back(temp_elevator);
    temp_elevator = new Elevator();
    elevators.push_back(temp_elevator);
}

int Simulator::startSimulation(){
    while(1)
    {
        events_scheduler.schedule();
        sleep(1);
    } 
    return 0;
}

SimulatorReply Simulator::takeMessage(SimulatorMessage msg){
    // Check what kind of message it is.
    // If it is from liftmovements, tell the lift 
    // to move.
    Person* temp_person;
    SimulatorReply my_reply;

    if(msg.type == LIFTS_MOVEMENT)
    {
        // create message for the elevator.
        cout << " lifts movement" << endl;
        ElevatorMessage msg;
        ElevatorReply reply;
        msg.type = LIFTS_MOVEMENT;

        // send message to elevators.
        int i; 
        for ( i = 0; i < elevators.size(); i++)
        {

            reply = elevators[i]->takeMessage(msg);

            // get back the reply and inform
            // all(in lift or everyone?) the 
            // people about the lift.
            deque<Person*>::iterator it;
            it = all_people.begin();

            PersonMessage msg2;

            msg2.type = LIFTS_MOVEMENT;
            msg2.val1 = i;
            msg2.val2 = reply.floor;

            // TODO initialize the message.
            while(it != all_people.end())
            {
                (*it)->takeMessage(msg2);
                it++;
            }
        }

    }
    if(msg.type == ELEVATOR)
    {
        // do what??
    }
    if(msg.type == PERSON_CREATION )
    {
        // create a person and add him to the
        // waiting deque of a floor and all ppl 
        // list.
        //
        cout << " person creation" << endl;
        srand(time(NULL));
        temp_person = new Person();

        waiting_people[rand() % 4].push_back(temp_person);
        all_people.push_back(temp_person);
    }
    return my_reply;
}
