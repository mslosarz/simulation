/*
 * Environment.h
 *
 *  Created on: 7 gru 2013
 */

#include "Simulation.h"
#include "SimulationResult.h"

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

class Environment {
public:
	SimulationResult* getResults() {
		return 0;
	}

	void performSimulation() {
	}

	Environment(Simulation* simulation): simulation(simulation) {
	}

	Environment();
	virtual ~Environment();
private:
	Simulation* simulation;
};

#endif /* ENVIRONMENT_H_ */
