/*
 * ClientParams.h
 *
 *  Created on: 7 gru 2013
 */

#ifndef CLIENTPARAMS_H_
#define CLIENTPARAMS_H_

class ClientParamBuilder;

class ClientParams {
	friend ClientParamBuilder;

public:
	virtual ~ClientParams();

private:
	ClientParams();
};

#endif /* CLIENTPARAMS_H_ */
