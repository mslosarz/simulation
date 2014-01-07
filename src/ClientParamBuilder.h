/*
 * ClientParamBuilder.h
 *
 *  Created on: 7 gru 2013
 */

#ifndef CLIENTPARAMBUILDER_H_
#define CLIENTPARAMBUILDER_H_

class ClientParams;

class ClientParamBuilder {
public:
	ClientParamBuilder();
	~ClientParamBuilder();
	ClientParamBuilder* withBalanceDistribution(float (*balanceDistribution)());
	ClientParamBuilder* withDecisionProbability(float probability);
	ClientParamBuilder* withDecisionPeriod(int (*decisionPeriod)());
	ClientParams* build();
private:
	ClientParams* params;
};

#endif /* CLIENTPARAMBUILDER_H_ */
