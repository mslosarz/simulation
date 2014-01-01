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
		simulationPeriod(simulation->getTime()), simulation(simulation) {
	shop = new Shop(simulation->getShop());
	start = new StartEvent(&timeLine);
	result = new SimulationResult();
	fillTimeLine();
	result->setBeginPriceOfProducts(shop->calculateProductsPrice());
}

void Environment::fillTimeLine() {
	// dodanie klientów z rozkładem poissona
	int time = 1;
	for (int clientEnterd = 0; clientEnterd < simulation->getClientNumber();) {
		int toEnter = rand.randPoisson(18);
		for (int i = 0; i < toEnter && clientEnterd + i < simulation->getClientNumber(); i++) {
			Client* client = new Client(simulation->getClient());
			result->addBeginClientsBalance(client->getBalance());
			clients.push_back(client);
			new ClientEnterEvent(start, time, client, shop);
			clientEnterd++;
		}
		time++;
	}
	new FinishEvent(&timeLine, simulationPeriod);
}

SimulationResult* Environment::performSimulation() {
	while (timeLine.size() > 0) {
		sort(timeLine.begin(), timeLine.end(), sortEvents);
		Event* event = *timeLine.begin();
		timeLine.erase(timeLine.begin());
//		cout << "---> " << "(id=" << event->getId() << "): " << event->getTime() << endl;
		event->execute();
		delete event;
	}
	fillResults();
	return result;
}

SimulationResult* Environment::getResults() {
	return result;
}

void Environment::fillResults(){
	for(unsigned int i = 0; i < clients.size(); i++){
		result->addFinalClientsBalance(clients[i]->getBalance());
	}
	result->setShopIncome(shop->calculateIncome());
	result->setLeftPriceOfProducts(shop->calculateProductsPrice());
}

Environment::~Environment() {
	delete result;
	delete shop;
	for (unsigned int i = 0; i < clients.size(); i++) {
		delete clients[i];
		clients[i] = 0;
	}
}

