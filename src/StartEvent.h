/*
 * StartEvent.h
 *
 *  Created on: 1 sty 2014
 */

#ifndef EMPTYEVENT_H_
#define EMPTYEVENT_H_

#include "Event.h"

class StartEvent: public Event {
public:
	StartEvent(vector<Event*>* events);
	void execute();
	virtual ~StartEvent();
};

#endif /* EMPTYEVENT_H_ */
