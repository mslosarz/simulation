/*
 * ClientParamBuilder.cpp
 *
 *  Created on: 7 gru 2013
 */

#include "ClientParamBuilder.h"

ClientParamBuilder::ClientParamBuilder() {
	params = new ClientParams();
}

ClientParamBuilder* ClientParamBuilder::withBalance(float balance){
	return this;
}

ClientParamBuilder* ClientParamBuilder::withDecisionProbability(float probability){
	return this;
}

ClientParamBuilder* ClientParamBuilder::withDecisionPeriod(int period){
	return this;
}

ClientParams* ClientParamBuilder::build(){
	return params;
}

ClientParamBuilder::~ClientParamBuilder() {
	delete params;
}

