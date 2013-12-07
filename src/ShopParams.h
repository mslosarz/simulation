/*
 * ShopParams.h
 *
 *  Created on: 7 gru 2013
 */

#ifndef SHOPPARAMS_H_
#define SHOPPARAMS_H_

class ShopParamBuilder;

class ShopParams {
	friend ShopParamBuilder;

public:
	virtual ~ShopParams();

private:
	ShopParams();
};

#endif /* SHOPPARAMS_H_ */
