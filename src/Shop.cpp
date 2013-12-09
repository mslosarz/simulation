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
		products.push_back(new Product(param->getPriceFromDistribution()));
	}
}

Shop::~Shop() {
	for (unsigned int i = 0; i < products.size(); i++) {
		delete products[i];
		products[i] = 0;
	}
}

