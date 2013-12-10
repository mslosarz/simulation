/*
 * Environment.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "Environment.h"

Environment::Environment(Simulation* simulation) {
	shop = new Shop(simulation->getShop());
	int clientNumber = simulation->getClientNumber();
	for (int i = 0; i < clientNumber; i++) {
		clients.push_back(new Client());
	}
}

Environment::~Environment() {
	delete shop;
	for (unsigned int i = 0; i < clients.size(); i++) {
		delete clients[i];
		clients[i] = 0;
	}
}

