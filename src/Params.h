/*
 * Params.h
 *
 *  Created on: 11 gru 2013
 */


#ifndef PARAMS_H_
#define PARAMS_H_

class Clock;

class Params {
public:
	Params();
	void setClock(Clock* clock);
	virtual ~Params();
protected:
	Clock* clock;
};

#endif /* PARAMS_H_ */
