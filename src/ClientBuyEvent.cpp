/*
 * ClientBuyEvent.cpp
 *
 *  Created on: 1 sty 2014
 */

#include "ClientBuyEvent.h"
#include "ClientExitEvent.h"

ClientBuyEvent::ClientBuyEvent(Event* trigger, Client* client, int remainingTime) :
		Event(trigger, client->getDecisionPeriod()), client(client), remainingTime(remainingTime) {
}

void ClientBuyEvent::execute() {
	client->buy();
	if (remainingTime > 0 && client->hasFinishedShopping() == false) {
		new ClientBuyEvent(this, client, remainingTime - client->getDecisionPeriod());
		return;
	}
	new ClientExitEvent(this, client);
}

ClientBuyEvent::~ClientBuyEvent() {
}

