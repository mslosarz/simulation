/*
 * Environment.h
 *
 *  Created on: 7 gru 2013
 */
#include <vector>

#include "Shop.h"
#include "Clock.h"
#include "Client.h"
#include "Simulation.h"
#include "SimulationResult.h"

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

using namespace std;


class Environment {
public:
	SimulationResult* getResults();

	void performSimulation();

	Environment(Simulation* simulation);

	virtual ~Environment();
private:
	void createShop(ShopParams* shopParams);
	void createClients(Simulation* simulation);
	void putSomeClientIntoShop();

	Shop* shop;
	vector<Client*> clients;
	int simulationPeriod;
	Clock* clock;

};

#endif /* ENVIRONMENT_H_ */
