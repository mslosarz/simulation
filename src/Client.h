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
	void enterToShop(Shop* shop);
	bool buy(Product* product);
	virtual ~Client();

private:
	bool hasEnoughMoneyFor(Product* product);

	float balance;
	int decisionPeriod;
	float decisionProbability;
	MTRand* generator;
	int timeInShop;
};

#endif /* CLIENT_H_ */
