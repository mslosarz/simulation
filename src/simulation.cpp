//============================================================================
// Name        : simulation.cpp
// Author      : Marcin Ślósarz
// Version     :
//============================================================================

#include <iostream>
#include "MersenneTwister.h"
#include "ClientParams.h"
#include "ShopParams.h"
#include "Simulation.h"
#include "Environment.h"
#include "omp.h"

using namespace std;

MTRand mtRand;

float product() {
	float val = abs(mtRand.randNorm(4.8, 5));
	if (val < 0.2) {
		return product();
	}
	return val;
}

float balance() {
	float bal = abs(mtRand.randNorm(40, 20));
	if (bal < 2) {
		return balance();
	}
	return bal;
}

float shopPriceDistribution() {
	return product();
}

float clientBalanceDistribution() {
	return balance();
}

int decision() {
	double i = abs(mtRand.randNorm(4, 2));
	if (i < 1) {
		return 1;
	}
	return int(i);
}

int main() {
	cout << "mrt;prod;lpp;si;" << endl;

	for (int i = 0; i < 5e4; i++) {
		int meanResidenceTime = mtRand.rand() * 80;
		int products = mtRand.rand() * 1600;
		ClientParamBuilder* clientParamsBuilder = ClientParams::create();
		ClientParams* clientParams = clientParamsBuilder //
		->withBalanceDistribution(clientBalanceDistribution) //
		->withDecisionPeriod(decision) //
		->withDecisionProbability(0.5) //
		->build(); //
		ShopParamBuilder* shopParamBuilder = ShopParams::create();
		ShopParams* shopParams = shopParamBuilder //
		->withMeanResidenceTime(meanResidenceTime) //
		->withProducts(products) //
		->withPriceDistribution(shopPriceDistribution) //
		->build();
		SimulationBuilder* simulationBuilder = Simulation::create();
		Simulation* simulation = simulationBuilder //
		->withClients(30, clientParams) //
		->withShop(shopParams) //
		->withTime(480) //
		->build();

		Environment* env = new Environment(simulation);

		env->performSimulation();

		SimulationResult* results = env->getResults();
		cout << meanResidenceTime << ";" << products << ";" << results->getLeftPriceOfProducts() << ";" << results->getShopIncome() << ";"
				<< endl;
		delete env;
		delete clientParamsBuilder;
		delete shopParamBuilder;
		delete simulationBuilder;
	}
	return 0;
}
