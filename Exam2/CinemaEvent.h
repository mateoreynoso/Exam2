#ifndef CINEMAEVENT_H_
#define CINEMAEVENT_H_
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "CinemaTicket.h"

class CinemaEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this worldcup event
	std::string movie;

	/**
	* Constructor for creating a WorldcupEvent
	*/
	CinemaEvent(std::string movie) : movie(movie) {}

	friend class EventFactory;

public:

	EventTicket * add(std::string name)
	{
		stadium.push_front(name);
		std::list<std::string>::iterator me = stadium.begin();
		return new CinemaTicket(this, me);
	}

	void list()
	{
		std::cout << "The movie is: " << movie << std::endl;
		std::cout << "Attendees: " << std::endl;
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++)
		{
			std::cout << *i << std::endl;
		}
	}


	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it)
	{
		it = stadium.erase(it);
	}

	void eat()
	{
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++)
		{
			std::cout << '\t' << *i << " *eats pop corn*" << std::endl;
		}
	}

};
#endif // !CINEMAEVENT_H_
