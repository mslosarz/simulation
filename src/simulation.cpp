//============================================================================
// Name        : simulation.cpp
// Author      : Marcin Ślósarz
// Version     :
//============================================================================

#include <iostream>
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

float shopPriceDistribution() {
	return 0;
}

float clientBalanceDistribution(){
	return 1000;
}

int main() {
	ClientParams* clientParams = ClientParams::create() //
	->withBalanceDistribution(clientBalanceDistribution) //
	->withDecisionPeriod(4) //
	->withDecisionProbability(0.3) //
	->build(); //
	cout << "Stworzono parametry klienta" << endl;

	ShopParams* shopParams = ShopParams::create() //
	->withMeanResidenceTime(30) //
	->withProducts(10000) //
	->withPriceDistribution(shopPriceDistribution) //
	->build();
	cout << "Stworzono parametry sklepu" << endl;

	Simulation* simulation = Simulation::create() //
	->withClients(100, clientParams) //
	->withShop(shopParams) //
	->withTime(100)//
	->build();
	cout << "Stworzono parametry symulacji" << endl;

	Environment* env = new Environment(simulation);
	cout << "Stworzono środowisko" << endl;

	env->performSimulation();
	cout << "Wykonano symulacje" << endl;

	SimulationResult* results = env->getResults();

	delete env;
	delete clientParams;
	delete shopParams;
	delete simulation;
	return 0;
}
