/*
 * SimulationBuilder.h
 *
 *  Created on: 7 gru 2013
 */

#include "ClientParams.h"
#include "ShopParams.h"
#include "Simulation.h"

#ifndef SIMULATIONBUILDER_H_
#define SIMULATIONBUILDER_H_

class SimulationBuilder {
public:
	SimulationBuilder* withClients(int number, ClientParams* params);
	SimulationBuilder* withShop(ShopParams* params);
	Simulation* build();
	~SimulationBuilder();
	static SimulationBuilder* create(){
		return new SimulationBuilder();
	}
private:
	SimulationBuilder();
	Simulation* simulation;
};

#endif /* SIMULATIONBUILDER_H_ */
