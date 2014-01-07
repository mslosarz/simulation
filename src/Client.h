/*
 * Client.h
 *
 *  Created on: 9 gru 2013
 */

#include "Shop.h"
#include "Product.h"
#include "ClientParams.h"
#include "MersenneTwister.h"

#ifndef CLIENT_H_
#define CLIENT_H_

class Client {
public:
	Client(ClientParams* param);
	void enterTo(Shop* shop);
	bool buy();
	int getDecisionPeriod();
	bool hasFinishedShopping() const;
	float getBalance() const;
	void subBalance(float value);
	virtual ~Client();

private:

	float balance;
	int decisionPeriod;
	float decisionProbability;
	bool finishedShopping;
	MTRand generator;
	Shop* shop;
};

#endif /* CLIENT_H_ */
