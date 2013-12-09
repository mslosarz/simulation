/*
 * ShopParamBuilder.h
 *
 *  Created on: 7 gru 2013
 */

#ifndef SHOPPARAMBUILDER_H_
#define SHOPPARAMBUILDER_H_

class ShopParams;

class ShopParamBuilder {
public:
	ShopParamBuilder* withProducts(int number);
	ShopParamBuilder* withPriceDistribution(float (*distribution)());
	ShopParamBuilder* withMeanResidenceTime(int iteration);
	ShopParams* build();
	~ShopParamBuilder();
	ShopParamBuilder();
private:
	ShopParams* params;
};

#endif /* SHOPPARAMBUILDER_H_ */
