/*
 * StartEvent.cpp
 *
 *  Created on: 1 sty 2014
 */

#include "StartEvent.h"

#include <iostream>

StartEvent::StartEvent(vector<Event*>* events) : Event(events) {

}

void StartEvent::execute(){
}

StartEvent::~StartEvent() {
}

