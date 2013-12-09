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
	float getBalance() const {
		return balance;
	}

	int getDecisionPeriod() const {
		return decisionPeriod;
	}

	float getDecisionProbability() const {
		return decisionProbability;
	}

	void setBalance(float balance) {
		this->balance = balance;
	}

	void setDecisionPeriod(int decisionPeriod) {
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
	ClientParams() :
			balance(.0f), decisionProbability(.0f), decisionPeriod(0) {
	}
	float balance;
	float decisionProbability;
	int decisionPeriod;
};

#endif /* CLIENTPARAMS_H_ */
