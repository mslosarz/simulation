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
	void tryToSellSomething();
	int clientsInShop();

	virtual ~Shop();

private:
	void sellProduct(Client* client);
	Product* getProduct();

	vector<Product*> available;
	vector<Product*> sold;
	vector<Client*> clients;
	int meanResidenceTime;
};

#endif /* SHOP_H_ */
