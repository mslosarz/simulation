/*
 * FinishEvent.cpp
 *
 *  Created on: 31 gru 2013
 */

#include "FinishEvent.h"

#include <iostream>

FinishEvent::FinishEvent(vector<Event*>* events, int time) :
		Event(events, time) {
}

void FinishEvent::execute() {
	while(events->size() > 0) {
		Event* event = *events->begin();
		events->erase(events->begin());
		delete event;
	}
	events->clear();
}

FinishEvent::~FinishEvent() {
}

