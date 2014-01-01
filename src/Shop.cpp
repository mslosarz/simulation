/*
 * Shop.cpp
 *
 *  Created on: 7 gru 2013
 */

#include <algorithm>

#include "Shop.h"
#include "Client.h"

bool sortProducts(Product* p1, Product* p2){
	return p1->getPrice() < p2->getPrice();
}

Shop::Shop(ShopParams* param) :
		meanResidenceTime(param->getMeanResidenceTime()) {
	int productNumber = param->getProductNumber();
	for (int i = 0; i < productNumber; i++) {
		available.push_back(new Product(param->getPriceFromDistribution()));
	}
	sort(available.begin(), available.end(), sortProducts);
}

Product* Shop::hasCheaperThan(float price){
	Product* p = new Product(price);
	vector<Product*>::iterator lower = lower_bound(available.begin(), available.end(), p, sortProducts);
	delete p;
	int lowerBoundIndex = lower - available.begin();
	if(lowerBoundIndex){
		return available[lowerBoundIndex - 1];
	}
	return 0;
}

int Shop::getMeanResidenceTime(){
	return meanResidenceTime;
}


float Shop::calculateIncome(){
	float income = 0;
	for(unsigned int i = 0; i < sold.size(); i++){
		income += sold[i]->getIncome();
	}
	return income;
}

float Shop::calculateProductsPrice(){
	float leftProductPrice = 0;
	for(unsigned int i = 0; i < available.size(); i++){
		leftProductPrice += available[i]->getPrice();
	}
	return leftProductPrice;
}

void Shop::sell(Product* product, Client* client){
	vector<Product*>::iterator position = find(available.begin(), available.end(), product);
	if (position != available.end()){
		available.erase(position);
	}
	sold.push_back(*position);
	client->subBalance((*position)->getPrice());
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

