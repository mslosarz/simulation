/*
 * Params.cpp
 *
 *  Created on: 11 gru 2013
 */

#include "Params.h"
#include "Clock.h"

Params::Params() : clock(0) {

}

void Params::setClock(Clock* clock){
	this->clock = clock;
}

Params::~Params() {
}

