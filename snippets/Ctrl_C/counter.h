//
// counter.h
//
// implements an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Nov. 2010
//

#ifndef COUNTER_H__
#define COUNTER_H__

void cntInit(int val);
// initializes counter to val

void cntCount(int step);
// counts the counter up (step>0) or down (step<0) by step

int cntGetCounter();
// returns the counter value

void cntSetCounter(int val);
// sets the counter to val

#endif
