//============================================================================
// Name        : simulation.cpp
// Author      : Marcin Ślósarz
// Version     :
//============================================================================

#include <iostream>
#include "ClientParams.h"
#include "ShopParams.h"
#include "Simulation.h"

using namespace std;

/*
 Temat 1. Symulacja sklepu
 Zadanie polega na zaimplemenotwaniu modelu umożliwiającego symulację pracy sklepu.
 Celem symulacji jest wyznaczenie parametrów dla których sklep będzie przynosił największe zyski.
 Parametrami sklepu są:
 • średni czas przebywania klienta na zakupach
 • ilość produktów
 • ilość produktów promowanych
 */

float distribution() {
	return 0;
}

int main() {
	ClientParams* clientParams = ClientParams::create() //
	->withBalance(10) //
	->withDecisionPeriod(2) //
	->withDecisionProbability(0.3) //
	->build(); //

	ShopParams* shopParams = ShopParams::create() //
	->withMeanResidenceTime(20) //
	->withProducts(10000) //
	->withPriceDistribution(distribution) //
	->build();

	Simulation* simulation = Simulation::create() //
	->withClients(100, clientParams) //
	->withShop(shopParams) //
	->build();

	return 0;
}
