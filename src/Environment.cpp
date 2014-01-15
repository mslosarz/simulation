/*
 * Environment.cpp
 *
 *  Created on: 7 gru 2013
 */

#include <algorithm>
#include "Environment.h"
#include "FinishEvent.h"
#include "ClientEnterEvent.h"
#include "StartEvent.h"

using namespace std;

bool sortEvents(Event* e1, Event* e2) {
	return e1->getTime() < e2->getTime();
}

Environment::Environment(Simulation* simulation) :
		simulationPeriod(simulation->getTime()), simulation(simulation), result(new SimulationResult()) {
	shop = new Shop(simulation->getShop());
	start = new StartEvent(&lifetime);
}

SimulationResult* Environment::performSimulation() {
	int time = 1;
	for (int i = 0; i < simulation->getClientNumber();) {
		int clientToEnter = rand.randPoisson(1);
		for (int newClient = 0; newClient < clientToEnter; newClient++) {
			Client* client = new Client(simulation->getClient());
			clients.push_back(client);
			new ClientEnterEvent(start, time, client, shop);
		}
		i+=clientToEnter;
		time+=5;
	}
	for (int i = 0; i < simulationPeriod; i++) {
		if (lifetime.size() > 0) {
			sort(lifetime.begin(), lifetime.end(), sortEvents);
			Event* event = *lifetime.begin();
			lifetime.erase(lifetime.begin());
			event->execute();
			delete event;
		}
	}
	fillResults();
	return result;
}

SimulationResult* Environment::getResults() {
	return result;
}

void Environment::fillResults() {
	result->setShopIncome(shop->calculateIncome());
	result->setLeftPriceOfProducts(shop->calculateProductsPrice());
}

Environment::~Environment() {
	delete result;
	delete shop;
	delete start;
	for (unsigned int i = 0; i < clients.size(); i++) {
		delete clients[i];
		clients[i] = 0;
	}
	for (unsigned int i = 0; i < lifetime.size(); i++) {
		delete lifetime[i];
		lifetime[i] = 0;
	}
}

