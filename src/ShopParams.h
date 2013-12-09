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
	virtual ~ShopParams(){

	}

	static ShopParamBuilder* create() {
		return new ShopParamBuilder();
	}

	float getPriceFromDistribution(){
		return distribution();
	}

	void setDistribution(float (*distribution)()) {
		this->distribution = distribution;
	}

	int getMeanResidenceTime() const {
		return meanResidenceTime;
	}

	void setMeanResidenceTime(int meanResidenceTime) {
		this->meanResidenceTime = meanResidenceTime;
	}

	int getProductNumber() const {
		return productNumber;
	}

	void setProductNumber(int productNumber) {
		this->productNumber = productNumber;
	}

private:
	ShopParams() :
			productNumber(0), distribution(0), meanResidenceTime(0) {
	}
	int productNumber;
	float (*distribution)();
	int meanResidenceTime;

};

#endif /* SHOPPARAMS_H_ */
