/*
 * StartEvent.cpp
 *
 *  Created on: 1 sty 2014
 */

#include "StartEvent.h"

#include <iostream>

StartEvent::StartEvent(vector<Event*>* events) : Event(events, 0) {
	this->events->pop_back();
}

void StartEvent::execute(){
}

StartEvent::~StartEvent() {
}

