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
		finishedShopping(false),//
		shop(0) {

}

bool Client::buy() {
	if(generator.rand() < decisionProbability){
		int index = shop->hasCheaperThan(balance);
		if(index >= 0){
			shop->sell(index, this);
			return true;
		} else {
			finishedShopping = true;
		}
	}
	return false;
}

bool Client::hasFinishedShopping() const {
	return finishedShopping;
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

void Client::enterTo(Shop* shop){
	this->shop = shop;
}

Client::~Client() {
}

