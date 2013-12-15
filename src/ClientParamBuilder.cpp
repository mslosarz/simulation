/*
 * ClientParamBuilder.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "ClientParamBuilder.h"
#include "ClientParams.h"

ClientParamBuilder::ClientParamBuilder() {
	params = new ClientParams();
}

ClientParamBuilder* ClientParamBuilder::withBalanceDistribution(float (*balanceDistribution)()){
	params->setBalanceDistribution(balanceDistribution);
	return this;
}

ClientParamBuilder* ClientParamBuilder::withDecisionProbability(float probability) {
	params->setDecisionProbability(probability);
	return this;
}

ClientParamBuilder* ClientParamBuilder::withDecisionPeriod(int period) {
	params->setDecisionPeriod(period);
	return this;
}

ClientParams* ClientParamBuilder::build() {
	return params;
}

ClientParamBuilder::~ClientParamBuilder() {
	delete params;
	params = 0;
}

