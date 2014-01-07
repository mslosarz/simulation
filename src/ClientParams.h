/*
 * ClientParams.h
 *
 *  Created on: 7 gru 2013
 */

#include "ClientParamBuilder.h"

#ifndef CLIENTPARAMS_H_
#define CLIENTPARAMS_H_

class ClientParams {
	friend ClientParamBuilder;
public:
	float getBalanceFromDistribution() {
		return balanceDistribution();
	}

	int getDecisionPeriod() const {
		return decisionPeriod();
	}

	float getDecisionProbability() const {
		return decisionProbability;
	}

	void setBalanceDistribution(float (*balanceDistribution)()) {
		this->balanceDistribution = balanceDistribution;
	}

	void setDecisionPeriod(int (*decisionPeriod)()) {
		this->decisionPeriod = decisionPeriod;
	}

	void setDecisionProbability(float decisionProbability) {
		this->decisionProbability = decisionProbability;
	}

	virtual ~ClientParams() {
	}

	static ClientParamBuilder* create() {
		return new ClientParamBuilder();
	}

private:
	ClientParams() : decisionProbability(.0f) {
		balanceDistribution = 0;
		decisionPeriod = 0;
	}
	float (*balanceDistribution)();
	float decisionProbability;
	int (*decisionPeriod)();
};

#endif /* CLIENTPARAMS_H_ */
