/*
 * Client.cpp
 *
 *  Created on: 9 gru 2013
 */

#include "Client.h"


Client::Client(ClientParams* param) :
		balance(param->getBalanceFromDistribution()), //
		decisionProbability(param->getDecisionProbability()), //
		generator(new MTRand()), //
		timeInShop(0) {
	decisionPeriod = param->getDecisionPeriod();
}

bool Client::buy(Product* product) {
	bool isTimeForShopping = timeInShop % decisionPeriod == 0;
	bool clientDecidedForPurchase = generator->rand() < decisionProbability;
	timeInShop++;
	return isTimeForShopping && clientDecidedForPurchase && hasEnoughMoneyFor(product);
}

void Client::enterToShop(Shop* shop){
	shop->addClient(this);
}

bool Client::hasEnoughMoneyFor(Product* product) {
	return product->getPrice() < balance;
}

Client::~Client() {
	delete generator;
}

