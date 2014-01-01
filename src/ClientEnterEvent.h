/*
 * ClientEnterEvent.h
 *
 *  Created on: 31 gru 2013
 */

#ifndef CLIENTENTEREVENT_H_
#define CLIENTENTEREVENT_H_

#include "Event.h"
#include "Client.h"
#include "Shop.h"

class ClientEnterEvent: public Event {
public:
	ClientEnterEvent(Event* trigger, int time, Client* client, Shop* shop);
	void execute();
	virtual ~ClientEnterEvent();

	Client* getClient();
	Shop* getShop();

private:

	Client* client;
	Shop* shop;
};

#endif /* CLIENTENTEREVENT_H_ */
