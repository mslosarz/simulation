/*
 * Environment.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "Environment.h"

void Environment::createShop(ShopParams* shopParams) {
	shopParams->setClock(clock);
	shop = new Shop(shopParams);
}

void Environment::createClients(Simulation* simulation) {
	int clientNumber = simulation->getClientNumber();
	ClientParams* param = simulation->getClient();
	param->setClock(clock);
	for (int i = 0; i < clientNumber; i++) {
		Client* client = new Client(param);
		clients.push_back(client);
	}
}

Environment::Environment(Simulation* simulation) :
		simulationPeriod(simulation->getTime()), clock(new Clock()) {
	createShop(simulation->getShop());
	createClients(simulation);
}

void Environment::performSimulation() {
	for (; clock->getTime() < simulationPeriod; clock->incTime()) {
		putSomeClientIntoShop();
		shop->tryToSellSomething();
	}
}

void Environment::putSomeClientIntoShop() {
	// rozkład gamma?
	int clientsInShop = shop->clientsInShop();
	if (clientsInShop < (int) clients.size()) {
		for (int i = 0; i < 23; i++) {
			clients[clientsInShop]->enterToShop(shop);
		}
	}

}

SimulationResult* Environment::getResults() {
	return 0;
}

Environment::~Environment() {
	delete shop;
	for (unsigned int i = 0; i < clients.size(); i++) {
		delete clients[i];
		clients[i] = 0;
	}
	delete clock;
}

