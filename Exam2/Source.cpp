/**
* CS-273 Exam 2 Summer 2018
* Who doesn't like sports ?!
*
* @authors Everyone!
*/
#include <iostream>
#include <string>
#include <typeinfo>
#include "Event.h"
#include "EventTicket.h"
#include "EventFactory.h"

using std::cout;
using std::endl;

const int EVENT_COUNT = 3;

int main()
{

	Event* events[EVENT_COUNT]; //Create a worldcup match and a baseball game
	events[0] = EventFactory::factory("worldcup", "germany", "mexico"); // Create a worldcup match with the event factory
	events[1] = EventFactory::factory("baseball", "everett", "spokane");
	events[2] = EventFactory::factory("cinema", "infinity war");

	//Let's go through and test each one
	for (int i=0; i<EVENT_COUNT-1; i++) {
		// Let's add a couple of people to the match, and store their tickets in variables
		EventTicket *ticket1 = events[i]->add("Mike");
		EventTicket *ticket2 = events[i]->add("Jane");
		EventTicket *ticket3 = events[i]->add("Antonio");
		EventTicket *ticket4 = events[i]->add("Sue");

		cout << "Event before Jane leaves\n";
		events[i]->list(); // List the people currently at the event

		// Jane decides to leave the event. Darn! She was really fun to have around!
		ticket2->leave();

		if (typeid(WorldcupEvent) == typeid(*events[i]))
			dynamic_cast<WorldcupEvent*>(events[i])->chant();
		if (typeid(BaseballEvent) == typeid(*events[i]))
			dynamic_cast<BaseballEvent*>(events[i])->stretch();
		if (typeid(CinemaEvent) == typeid(*events[i]))
			dynamic_cast<CinemaEvent*>(events[i])->eat();

		cout << "Event after Jane leaves:\n";
		events[i]->list(); // List the people remaining
	}
	}