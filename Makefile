CFLAGS = -Wall -pedantic -g

all: bin/ElevatorSimulation 
	echo "Done!"

bin/ElevatorSimulation: obj/ElevatorSimulation.o \
                  obj/Person.o \
                  obj/EventQueue.o \
                  obj/Elevator.o \
                  obj/Simulator.o \
                  obj/LiftsMovement.o \
                  obj/PersonCreation.o
	if [ ! -e bin ]; then mkdir bin; fi;
	g++ -o $@ $^ $(CFLAGS) $(MACROS)

obj/ElevatorSimulation.o: ElevatorSimulation.cpp \
				Simulator.h \
				protocols.h
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)

obj/Person.o: Person.cpp \
				Person.h \
				protocols.h
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)

obj/EventQueue.o: EventQueue.cpp \
			EventQueue.h 
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)

obj/Elevator.o: Elevator.cpp \
			Elevator.h 
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)


obj/Simulator.o: Simulator.cpp \
				Simulator.h \
				protocols.h
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)

obj/PersonCreation.o: PersonCreation.cpp \
			PersonCreation.h
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)

obj/LiftsMovement.o: LiftsMovement.cpp \
			LiftsMovement.h
	if [ ! -e obj ]; then mkdir obj; fi;
	g++ -o $@ -c $< $(CFLAGS)


clean:
	rm ./obj/*.o ./src/*~ ./include/*~ -f
