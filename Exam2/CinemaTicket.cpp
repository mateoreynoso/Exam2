#include "CinemaTicket.h"

void CinemaTicket::leave()
{
	CinemaEvent * actual_event = dynamic_cast<CinemaEvent *>(the_event); // down-cast base class to derived class
	actual_event->remove(me); // call WorldcupEvent remove method to erase event goer identified by "me"
}
