/*
 * Simulation.h
 *
 *  Created on: 7 gru 2013
 */

#include "ShopParams.h"
#include "ClientParams.h"
#include "SimulationBuilder.h"

#ifndef SIMULATION_H_
#define SIMULATION_H_

class Simulation {
	friend SimulationBuilder;

public:
	ClientParams* getClient() {
		return client;
	}

	void setClient(ClientParams* client) {
		this->client = client;
	}

	int getClientNumber() const {
		return clientNumber;
	}

	void setClientNumber(int clientNumber) {
		this->clientNumber = clientNumber;
	}

	int getTime(){
		return time;
	}

	void setTime(int time){
		this->time = time;
	}

	ShopParams* getShop() {
		return shop;
	}

	static SimulationBuilder* create() {
		return new SimulationBuilder();
	}

	virtual ~Simulation() {
	}

	void setShop(ShopParams* shop) {
		this->shop = shop;
	}

private:
	Simulation() :
			shop(0), clientNumber(0), client(0), time(0) {
	}

	ShopParams* shop;
	int clientNumber;
	ClientParams* client;
	int time;

};

#endif /* SIMULATION_H_ */
