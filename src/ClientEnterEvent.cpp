/*
 * ClientEnterEvent.cpp
 *
 *  Created on: 31 gru 2013
 */

#include "ClientEnterEvent.h"
#include "ClientBuyEvent.h"
#include "Shop.h"

ClientEnterEvent::ClientEnterEvent(Event* trigger, int time, Client* client, Shop* shop) :
		Event(trigger, time), client(client), shop(shop) {
}

void ClientEnterEvent::execute() {
	client->enterTo(shop);
	new ClientBuyEvent(this, client, shop->getMeanResidenceTime());
}

Client* ClientEnterEvent::getClient(){
	return client;
}

Shop* ClientEnterEvent::getShop(){
	return shop;
}

ClientEnterEvent::~ClientEnterEvent() {
}

