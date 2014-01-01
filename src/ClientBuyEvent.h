/*
 * ClientBuyEvent.h
 *
 *  Created on: 1 sty 2014
 */

#ifndef CLIENTBUYEVENT_H_
#define CLIENTBUYEVENT_H_

#include "Event.h"
#include "Client.h"

class ClientBuyEvent: public Event {
public:
	ClientBuyEvent(Event* trigger, Client* client, int remainingTime);
	void execute();
	virtual ~ClientBuyEvent();
private:
	Client* client;
	int remainingTime;
};

#endif /* CLIENTBUYEVENT_H_ */
