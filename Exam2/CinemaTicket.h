#ifndef CINEMATICKET_H_
#define CINEMATICKET_H_
#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"

class CinemaTicket : public EventTicket
{
private:
	Event * the_event; // the event this ticket is associated with
	std::list<std::string>::iterator me; // an iterator containing the event goer this ticket is associated with

public:
	CinemaTicket(Event *the_event, std::list<std::string>::iterator &me) :
		the_event(the_event), me(me) {}

	void leave();
};
#endif // !1

