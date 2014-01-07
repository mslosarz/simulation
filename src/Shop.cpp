/*
 * Shop.cpp
 *
 *  Created on: 7 gru 2013
 */

#include <algorithm>

#include "Shop.h"
#include "Client.h"

Shop::Shop(ShopParams* param) :
		productNumber(param->getProductNumber()), meanResidenceTime(param->getMeanResidenceTime()) {
	prices = new float[productNumber];
	sold = new bool[productNumber];
	for (int i = 0; i < productNumber; i++) {
		prices[i] = param->getPriceFromDistribution();
		sold[i] = false;
	}
	sort(prices, prices + productNumber);
}

int Shop::hasCheaperThan(float price) {
	for (int i = productNumber - 1; i >= 0; i--) {
		if (!sold[i] && prices[i] < price) {
			int product = int(rand.rand() * i);
			while (product >= 0 && sold[product]) {
				product--;
			};
			return product;
		}
	}
	return -1;
}

int Shop::getMeanResidenceTime() {
	return meanResidenceTime;
}

void Shop::sell(int product, Client* client) {
	sold[product] = true;
	client->subBalance(prices[product]);
}

float Shop::calculateIncome() {
	float result = 0;
	for (int i = 0; i < productNumber; i++) {
		if (sold[i]) {
			result += prices[i];
		}
	}
	return result;
}

float Shop::calculateProductsPrice() {
	float result = 0;
	for (int i = 0; i < productNumber; i++) {
		result += prices[i];
	}
	return result;
}

Shop::~Shop() {
	delete [] prices;
	prices = 0;
	delete [] sold;
	sold = 0;
}

