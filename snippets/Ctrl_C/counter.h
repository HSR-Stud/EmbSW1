//
// counter.h
//
// implements an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2019
//

#ifndef COUNTER_H__
#define COUNTER_H__

void cnt_init(int val);
// initializes counter to val

void cnt_count(int step);
// counts the counter up (step>0) or down (step<0) by step

int cnt_getCounter();
// returns the counter value

void cnt_setCounter(int val);
// sets the counter to val

#endif
