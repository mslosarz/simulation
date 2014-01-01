/*
 * FinishEvent.h
 *
 *  Created on: 31 gru 2013
 */

#ifndef FINISHEVENT_H_
#define FINISHEVENT_H_

#include "Event.h"

class FinishEvent: public Event {
public:
	FinishEvent(vector<Event*>* events, int time);
	virtual void execute();
	virtual ~FinishEvent();
};

#endif /* FINISHEVENT_H_ */
