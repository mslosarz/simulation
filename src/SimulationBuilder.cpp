/*
 * SimulationBuilder.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "SimulationBuilder.h"
#include "Simulation.h"

SimulationBuilder::SimulationBuilder() {
	simulation = new Simulation();
}

SimulationBuilder* SimulationBuilder::withClients(int number,
		ClientParams* params) {
	simulation->setClientNumber(number);
	simulation->setClient(params);
	return this;
}

SimulationBuilder* SimulationBuilder::withShop(ShopParams* params) {
	simulation->setShop(params);
	return this;
}

Simulation* SimulationBuilder::build() {
	return simulation;
}

SimulationBuilder::~SimulationBuilder() {
	delete simulation;
}

