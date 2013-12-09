/*
 * ShopParamBuilder.cpp
 *
 *  Created on: 7 gru 2013
 */
#include "ShopParamBuilder.h"
#include "ShopParams.h"

ShopParamBuilder::ShopParamBuilder() {
	params = new ShopParams();
}

ShopParamBuilder* ShopParamBuilder::withProducts(int number) {
	params->setProductNumber(number);
	return this;
}

ShopParamBuilder* ShopParamBuilder::withPriceDistribution(
		float (*distribution)()) {
	params->setDistribution(distribution);
	return this;
}

ShopParamBuilder* ShopParamBuilder::withMeanResidenceTime(int iteration) {
	params->setIteration(iteration);
	return this;
}

ShopParams* ShopParamBuilder::build() {
	return params;
}

ShopParamBuilder::~ShopParamBuilder() {
	delete params;
	params = 0;
}

