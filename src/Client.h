/*
 * Client.h
 *
 *  Created on: 9 gru 2013
 */

#include "Product.h"

#ifndef CLIENT_H_
#define CLIENT_H_

class Client {
public:
	Client();

	bool hasEnoughMoneyFor(Product* product);

	bool buy(Product* product);

	virtual ~Client();
};

#endif /* CLIENT_H_ */
