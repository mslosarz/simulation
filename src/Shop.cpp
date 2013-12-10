/*
 * Shop.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "Shop.h"

Shop::Shop(ShopParams* param) :
		meanResidenceTime(param->getMeanResidenceTime()) {
	int productNumber = param->getProductNumber();
	for (int i = 0; i < productNumber; i++) {
		available.push_back(new Product(param->getPriceFromDistribution()));
	}
}

void Shop::sellProduct(Client* client){

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

