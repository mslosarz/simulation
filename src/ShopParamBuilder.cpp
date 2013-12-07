/*
 * ShopParamBuilder.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "ShopParamBuilder.h"
#include "ShopParams.h"

ShopParamBuilder::ShopParamBuilder() {
	param = new ShopParams();
}

ShopParamBuilder* ShopParamBuilder::withProducts(int number){
	return this;
}

ShopParamBuilder* ShopParamBuilder::withPriceDistribution(float(*distribution)()){
	return this;
}

ShopParamBuilder* ShopParamBuilder::withMeanResidenceTime(int iteration){
	return this;
}

ShopParams* ShopParamBuilder::build(){
	return param;
}

ShopParamBuilder::~ShopParamBuilder() {
	delete param;
}

