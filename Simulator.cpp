#include "Simulator.h"
#include <stdlib.h>
#include <time.h>

Simulator::Simulator(){
    deque<Person*> temp;
    waiting_people.push_back(temp);
    waiting_people.push_back(temp);
    waiting_people.push_back(temp);
    waiting_people.push_back(temp);

    elevator_occupants.push_back(temp);
    elevator_occupants.push_back(temp);

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

int Simulator::removePerson(Person* person, int deque_type, int arg){
    int i;
    if( deque_type == REMOVE_FROM_ELEVATOR)
    {
        for( i = 0; i < elevator_occupants[arg].size(); i++)
        {
            if(elevator_occupants[arg][i] == person)
            {
                elevator_occupants[arg].erase(elevator_occupants[arg].begin()+i);
                return 0;
            }
        }
    }
    // TODO if the type is REMOVE_FROM_WAITING
    if( deque_type == NOT_WAITING )
    {
        for( i = 0; i < waiting_people[arg].size(); i++)
        {
            if(waiting_people[arg][i] == person)
            {
                waiting_people[arg].erase(waiting_people[arg].begin()+i);
            }
            return 0;
        }
    }
}

SimulatorReply Simulator::takeMessage(SimulatorMessage msg){
    // Check what kind of message it is.
    // If it is from liftmovements, tell the lift 
    // to move.
    Person* temp_person;
    int i, j; 
    SimulatorReply my_reply;

    if(msg.type == LIFTS_MOVEMENT)
    {
        // create message for the elevator.
        ElevatorMessage msg;
        ElevatorReply reply;
        msg.type = LIFTS_MOVEMENT;

        // send message to elevators.
        for ( i = 0; i < int(elevators.size()); i++)
        {

            reply = elevators[i]->takeMessage(msg);

            // get back the reply and inform
            // all(in lift or everyone?) the 
            // people about the lift.

            PersonMessage msg2;
            PersonReply p_reply;

            msg2.type = LIFTS_MOVEMENT;
            msg2.val1 = i;
            msg2.val2 = reply.direction;
            msg2.val3 = reply.floor;

            for( j = 0; j < int(all_people.size()); j++)
            {
                p_reply = all_people[j]->takeMessage(msg2);
                if( p_reply.type == KILL_ME_NOW)
                {
                    // Remove from all_people and also
                    // from elevator occupants.
                    temp_person = all_people[j];
                    removePerson(temp_person, REMOVE_FROM_ELEVATOR, p_reply.arg );
                    all_people.erase(all_people.begin()+j);
                    j--;
                }
                if( p_reply.type == NOT_WAITING)
                {
                    // the person would have put himself 
                    // in the elevator_occupants list
                    temp_person = all_people[j];
                    removePerson( temp_person, REMOVE_FROM_WAITING, p_reply.arg );
                }
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
        cerr << " person creation" << endl;
        //srand(time(NULL));
        temp_person = new Person();

        //waiting_people[rand() % 4].push_back(temp_person);
        all_people.push_back(temp_person);
    }
    return my_reply;
}
