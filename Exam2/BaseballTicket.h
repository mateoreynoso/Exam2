#ifndef _BASEBALL_TICKET_H_
#define _BASEBALL_TICKET_H_

#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"

class BaseballTicket : public EventTicket
{
private:
	Event * the_event; // the event this ticket is associated with
	std::list<std::string>::iterator me; // an iterator containing the event goer this ticket is associated with

public:
	BaseballTicket(Event *the_event, std::list<std::string>::iterator &me) :
		the_event(the_event), me(me) {}

	void leave();
};

#endif