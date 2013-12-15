/*
 * Shop.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "Shop.h"
#include "Client.h"

Shop::Shop(ShopParams* param) :
		meanResidenceTime(param->getMeanResidenceTime()) {
	int productNumber = param->getProductNumber();
	for (int i = 0; i < productNumber; i++) {
		available.push_back(new Product(param->getPriceFromDistribution()));
	}
}

Product* Shop::getProduct(){
	int size = available.size();
	if (size > 0) {
		return available[size - 1];
	}
	return 0;
}

void Shop::sellProduct(Client* client){
	if(Product* product = getProduct()){
		if(client->buy(product)){
			available.pop_back();
			sold.push_back(product);
		} else {
			available.push_back(product);
		}
	}
}

void Shop::addClient(Client* client){
	clients.push_back(client);
}

void Shop::tryToSellSomething(){
	for(unsigned int i = 0; i < clients.size(); i++){
		sellProduct(clients[i]);
	}
}

int Shop::clientsInShop(){
	return clients.size();
}

Shop::~Shop() {
	for (unsigned int i = 0; i < available.size(); i++) {
		delete available[i];
		available[i] = 0;
	}

	for (unsigned int i = 0; i < sold.size(); i++) {
			delete sold[i];
			sold[i] = 0;
		}
}

