/*
 * Event.cpp
 *
 *  Created on: 18 gru 2013
 */

#include "Event.h"

#include <iostream>

atomic<int> Event::currId = {1};

Event::Event(vector<Event*>* events) : Event(events, currId) {
}

Event::Event(vector<Event*>* events, int time): id(currId++){
	this->time = time;
	this->creationTime = time;
	this->events = events;
	this->events->push_back(this);
//	cout << endl << "Event Created! (id = " << id << ") at " << creationTime << endl << endl;
}

Event::Event(Event* trigger, int timeAfterTrigger) : Event(trigger->getEvents(), trigger->getTime()){
	this->time = trigger->getTime() + timeAfterTrigger;
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
