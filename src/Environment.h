/*
 * Environment.h
 *
 *  Created on: 7 gru 2013
 */
#include <vector>

#include "Shop.h"
#include "Client.h"
#include "Simulation.h"
#include "SimulationResult.h"

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

using namespace std;


class Environment {
public:
	SimulationResult* getResults() {
		return 0;
	}

	void performSimulation() {
	}

	Environment(Simulation* simulation);

	virtual ~Environment();
private:
	Shop* shop;
	vector<Client*> clients;

};

#endif /* ENVIRONMENT_H_ */
