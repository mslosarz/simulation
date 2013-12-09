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
			price(price), sold(false) {
	}

	float getPrice() const {
		return price;
	}

	float getIncome() const {
		if (sold) {
			return price * 0.1f;
		} else {
			return 0.0f;
		}
	}

	bool isSold() {
		return sold;
	}

	void buy(){
		sold = true;
	}

	virtual ~Product() {
	}

private:
	float price;
	bool sold;
};

#endif /* PRODUCT_H_ */
