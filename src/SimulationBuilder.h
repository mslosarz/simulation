/*
 * SimulationBuilder.h
 *
 *  Created on: 7 gru 2013
 */

#include "ClientParams.h"
#include "ShopParams.h"

#ifndef SIMULATIONBUILDER_H_
#define SIMULATIONBUILDER_H_

class Simulation;

class SimulationBuilder {
public:
	SimulationBuilder();
	SimulationBuilder* withClients(int number, ClientParams* params);
	SimulationBuilder* withShop(ShopParams* params);
	SimulationBuilder* withTime(int time);
	Simulation* build();
	~SimulationBuilder();
private:
	Simulation* simulation;
};

#endif /* SIMULATIONBUILDER_H_ */
