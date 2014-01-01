/*
 * Event.h
 *
 *  Created on: 18 gru 2013
 */

#include <atomic>
#include <vector>

#ifndef EVENT_H_
#define EVENT_H_

using namespace std;

class Event {
public:
	Event(vector<Event*>* events);
	Event(vector<Event*>* events, int time);
	Event(Event* trigger, int time = 0);
	int getTime() const;
	int getCreationTime() const;
	int getId() const;
	vector<Event*>* getEvents();
	virtual void execute() = 0;
	virtual ~Event();

protected:
	vector<Event*>* events;

private:
	static atomic<int> currId;
	int time;
	int creationTime;
	int id;
};

#endif /* EVENT_H_ */
