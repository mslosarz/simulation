/*
 * ClientExitEvent.cpp
 *
 *  Created on: 3 sty 2014
 */

#include "ClientExitEvent.h"

ClientExitEvent::ClientExitEvent(Event* trigger, Client* client) : Event(trigger), client(client) {
}

void ClientExitEvent::execute(){
	client->enterTo(0);
}

ClientExitEvent::~ClientExitEvent() {
}

