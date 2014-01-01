/*
 * ClientExitEvent.h
 *
 *  Created on: 3 sty 2014
 */

#ifndef CLIENTEXITEVENT_H_
#define CLIENTEXITEVENT_H_

#include "Event.h"
#include "Client.h"

class ClientExitEvent: public Event {
public:
	ClientExitEvent(Event* trigger, Client* client);
	void execute();
	virtual ~ClientExitEvent();
private:
	Client* client;
};

#endif /* CLIENTEXITEVENT_H_ */
