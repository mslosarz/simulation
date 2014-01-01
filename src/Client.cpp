/*
 * Client.cpp
 *
 *  Created on: 9 gru 2013
 */

#include "Client.h"


Client::Client(ClientParams* param) :
		balance(param->getBalanceFromDistribution()), //
		decisionPeriod(param->getDecisionPeriod()),//
		decisionProbability(param->getDecisionProbability()), //
		generator(new MTRand()), //
		finishedShopping(false),
		shop(0) {
}

bool Client::buy() {
	if(Product* product = shop->hasCheaperThan(balance)){
		bool clientDecidedForPurchase = generator->rand() < decisionProbability;
		if(clientDecidedForPurchase){
			shop->sell(product, this);
			return true;
		}
	} else {
		finishedShopping = true;
	}
	return false;
}

void Client::subBalance(float value){
	balance -= value;
}

float Client::getBalance() const{
	return balance;
}

int Client::getDecisionPeriod(){
	return decisionPeriod;
}

bool Client::hasFinishedShopping(){
	return finishedShopping;
}

void Client::enterTo(Shop* shop){
	this->shop = shop;
}

Client::~Client() {
	delete generator;
}

