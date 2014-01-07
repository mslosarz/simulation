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

using namespace std;

MTRand mtRand;


float product(){
	float val = abs(mtRand.randNorm(4.8, 5));
	if(val < 0.2){
		return product();
	}
	return val;
}

float balance(){
	float bal = abs(mtRand.randNorm(40, 20));
	if(bal < 2){
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

int decision(){
	double i = abs(mtRand.randNorm(4, 2));
	if(i < 1){
		return 1;
	}
	return int(i);
}

int main() {
	cout << "mrt;prod;lpp;si;" << endl;
	for(int meanResidenceTime = 0; meanResidenceTime < 30; meanResidenceTime++){

		for(int products = 100; products < 5000; products+=100){
			ClientParamBuilder* clientParamsBuilder = ClientParams::create();
			ClientParams* clientParams = clientParamsBuilder //
			->withBalanceDistribution(clientBalanceDistribution) //
			->withDecisionPeriod(decision) //
			->withDecisionProbability(0.1) //
			->build(); //
			ShopParamBuilder* shopParamBuilder = ShopParams::create();
			ShopParams* shopParams = shopParamBuilder //
			->withMeanResidenceTime(meanResidenceTime) //
			->withProducts(products) //
			->withPriceDistribution(shopPriceDistribution) //
			->build();
			SimulationBuilder* simulationBuilder = Simulation::create();
			Simulation* simulation = simulationBuilder //
			->withClients(100, clientParams) //
			->withShop(shopParams) //
			->withTime(480)//
			->build();

			Environment* env = new Environment(simulation);
//			cout << "Environment created" << endl;

			env->performSimulation();
//			cout << "Simulation performed" << endl;


			SimulationResult* results = env->getResults();
			cout << meanResidenceTime << ";"
				 << products << ";"
				 << results->getLeftPriceOfProducts() << ";"
				 << results->getShopIncome() << ";" << endl;
//			cout << endl <<
//					"left product price: " << results->getLeftPriceOfProducts() << endl <<
//					"shop income: " << results->getShopIncome() << endl <<
//					/*"---------------------------------------"*/ "" << endl;

			delete env;
			delete clientParamsBuilder;
			delete shopParamBuilder;
			delete simulationBuilder;
		}

	}
	return 0;
}
