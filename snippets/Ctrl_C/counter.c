//
// counter.c
//
// implements an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2019
//

#include "counter.h"

static int countValue;

void cnt_init(int val)
{
  countValue = val;
}

void cnt_count(int step)
{
  countValue += step;
}

int cnt_getCounter()
{
  return countValue;
}

void cnt_setCounter(int val)
{
  countValue = val;
}
