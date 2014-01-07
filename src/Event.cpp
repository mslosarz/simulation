/*
 * Event.cpp
 *
 *  Created on: 18 gru 2013
 */

#include "Event.h"

#include <iostream>

Event::Event(vector<Event*>* events) : Event(events, 1) {
}

Event::Event(vector<Event*>* events, int time): id(time){
	this->time = time;
	this->creationTime = time;
	this->events = events;
	this->events->push_back(this);
}

Event::Event(Event* trigger, int timeAfterTrigger) : Event(trigger->getEvents(), trigger->getTime()){
	if(timeAfterTrigger > 0){
		this->time = trigger->getTime() + timeAfterTrigger;
	} else {
		this->time = trigger->getTime() + 1;
	}
}

Event::~Event(){
}

vector<Event*>* Event::getEvents(){
	return events;
}

int Event::getTime() const{
	return time;
}

int Event::getCreationTime() const {
	return creationTime;
}

int Event::getId() const {
	return id;
}
