/*
 * Simulation.h
 *
 *  Created on: 7 gru 2013
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

class SimulationBuilder;

class Simulation {
	friend SimulationBuilder;

public:
	virtual ~Simulation();

private:
	Simulation();
};

#endif /* SIMULATION_H_ */
