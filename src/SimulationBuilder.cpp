/*
 * SimulationBuilder.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "SimulationBuilder.h"

SimulationBuilder::SimulationBuilder() {
	simulation = new Simulation();
}

SimulationBuilder* SimulationBuilder::withClients(int number, ClientParams* params){
	return this;
}

SimulationBuilder* SimulationBuilder::withShop(ShopParams* params){
	return this;
}

Simulation* SimulationBuilder::build(){
	return simulation;
}

SimulationBuilder::~SimulationBuilder() {
	delete simulation;
}

