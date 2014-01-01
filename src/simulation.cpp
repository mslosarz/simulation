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

/*
 Temat 1. Symulacja sklepu
 Zadanie polega na zaimplemenotwaniu modelu umożliwiającego symulację pracy sklepu.

 Celem symulacji jest wyznaczenie parametrów dla których sklep będzie przynosił największe zyski.
 Parametrami sklepu są:
 • średni czas przebywania klienta na zakupach
 • liczba produktów
 */

MTRand mtRand;

float shopPriceDistribution() {
	return 10 + abs(mtRand.randPoisson(12));
}

float clientBalanceDistribution() {
	return mtRand.randNorm(200, 50);
}

int main() {
	ClientParams* clientParams = ClientParams::create() //
	->withBalanceDistribution(clientBalanceDistribution) //
	->withDecisionPeriod(4) //
	->withDecisionProbability(0.1) //
	->build(); //

	ShopParams* shopParams = ShopParams::create() //
	->withMeanResidenceTime(50) //
	->withProducts(2000) //
	->withPriceDistribution(shopPriceDistribution) //
	->build();

	Simulation* simulation = Simulation::create() //
	->withClients(1000, clientParams) //
	->withShop(shopParams) //
	->withTime(100000)//
	->build();

	Environment* env = new Environment(simulation);
	cout << "Environment created" << endl;

	env->performSimulation();
	cout << "Simulation performed" << endl;

	SimulationResult* results = env->getResults();
	cout << endl <<
			"begin clients balance: " << results->getBeginClientsBalance() << endl <<
			"final clients balance: " << results->getFinalClientsBalance() << endl <<
			"begin product price: " << results->getBeginPriceOfProducts() << endl <<
			"left product price: " << results->getLeftPriceOfProducts() << endl <<
			"shop income: " << results->getShopIncome() << endl <<
			"---------------------------------------" << endl;

	delete env;
	delete clientParams;
	delete shopParams;
	delete simulation;
	return 0;
}
