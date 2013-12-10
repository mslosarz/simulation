/*
 * Product.h
 *
 *  Created on: 9 gru 2013
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

class Product {
public:
	Product(float price) :
			price(price) {
	}

	float getPrice() const {
		return price;
	}

	float getIncome() const {
		return price * 0.1f;
	}

	virtual ~Product() {
	}

private:
	float price;
};

#endif /* PRODUCT_H_ */
