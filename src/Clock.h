/*
 * Clock.h
 *
 *  Created on: 11 gru 2013
 */

#ifndef CLOCK_H_
#define CLOCK_H_

#include "Environment.h"

class Clock {
	friend Environment;
public:
	Clock() :
			time(0) {
	}

	int getTime() {
		return time;
	}

	void incTime(){
		time++;
	}

private:
	int time;
};

#endif /* CLOCK_H_ */
