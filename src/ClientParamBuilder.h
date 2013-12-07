/*
 * ClientParamBuilder.h
 *
 *  Created on: 7 gru 2013
 */

#include "ClientParams.h"

#ifndef CLIENTPARAMBUILDER_H_
#define CLIENTPARAMBUILDER_H_

class ClientParamBuilder {
public:
	~ClientParamBuilder();
	ClientParamBuilder* withBalance(float balance);
	ClientParamBuilder* withDecisionProbability(float probability);
	ClientParamBuilder* withDecisionPeriod(int decisionPeriod);
	ClientParams* build();
	static ClientParamBuilder* create(){
		return new ClientParamBuilder();
	}
private:
	ClientParamBuilder();
	ClientParams* params;
};

#endif /* CLIENTPARAMBUILDER_H_ */
