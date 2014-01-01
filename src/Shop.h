/*
 * Shop.h
 *
 *  Created on: 7 gru 2013
 */

#include <vector>
#include "Product.h"
#include "ShopParams.h"

#ifndef SHOP_H_
#define SHOP_H_

using namespace std;

class Client;

class Shop {
public:
	Shop(ShopParams* param);

	void addClient(Client* client);
	Product* hasCheaperThan(float price);
	void sell(Product* product, Client* client);
	int getMeanResidenceTime();
	float calculateIncome();
	float calculateProductsPrice();

	virtual ~Shop();

private:
	vector<Product*> available;
	vector<Product*> sold;
	int meanResidenceTime;
};

#endif /* SHOP_H_ */
