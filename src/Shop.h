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

class Shop {
public:
	Shop(ShopParams* param);
	virtual ~Shop();

private:
	vector<Product*> products;
	int meanResidenceTime;
};

#endif /* SHOP_H_ */
