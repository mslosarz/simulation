/*
 * Environment.h
 *
 *  Created on: 7 gru 2013
 */
#include <vector>

#include "Event.h"
#include "Shop.h"
#include "Client.h"
#include "Simulation.h"
#include "SimulationResult.h"

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

using namespace std;


class Environment {
public:
	Environment(Simulation* simulation);

	SimulationResult* getResults();

	SimulationResult* performSimulation();

	virtual ~Environment();
private:
	void fillTimeLine();
	void fillResults();

	vector<Event*> timeLine;
	int simulationPeriod;
	Simulation* simulation;
	SimulationResult* result;
	MTRand rand;

	Shop* shop;
	vector<Client*> clients;
	Event* start;
};

#endif /* ENVIRONMENT_H_ */
