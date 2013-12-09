/*
 * ShopParams.h
 *
 *  Created on: 7 gru 2013
 */

#include "ShopParamBuilder.h"

#ifndef SHOPPARAMS_H_
#define SHOPPARAMS_H_

class ShopParams {
	friend ShopParamBuilder;

public:
	virtual ~ShopParams() {

	}

	static ShopParamBuilder* create() {
		return new ShopParamBuilder();
	}

	float getFromDistribution() {
		return distribution();
	}

	void setDistribution(float (*distribution)()) {
		this->distribution = distribution;
	}

	int getIteration() const {
		return iteration;
	}

	void setIteration(int iteration) {
		this->iteration = iteration;
	}

	int getProductNumber() const {
		return productNumber;
	}

	void setProductNumber(int productNumber) {
		this->productNumber = productNumber;
	}

private:
	ShopParams() :
			productNumber(0), distribution(0), iteration(0) {
	}
	int productNumber;
	float (*distribution)();
	int iteration;

};

#endif /* SHOPPARAMS_H_ */
