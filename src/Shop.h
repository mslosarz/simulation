/*
 * Shop.h
 *
 *  Created on: 7 gru 2013
 */

#include <vector>
#include "Product.h"
#include "ShopParams.h"
#include "MersenneTwister.h"

#ifndef SHOP_H_
#define SHOP_H_

using namespace std;

class Client;

class Shop {
public:
	Shop(ShopParams* param);

	void addClient(Client* client);
	int hasCheaperThan(float price);
	void sell(int product, Client* client);
	int getMeanResidenceTime();
	float calculateIncome();
	float calculateProductsPrice();

	virtual ~Shop();

private:
	int productNumber;
	int meanResidenceTime;
	float *prices;
	bool *sold;
	MTRand rand;
};

#endif /* SHOP_H_ */
