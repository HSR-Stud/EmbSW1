//
// counter.c
//
// implements an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Nov. 2010
//

#include "counter.h"

static int countValue;

void cntInit(int val)
{
  countValue = val;
}

void cntCount(int step)
{
  countValue += step;
}

int cntGetCounter()
{
  return countValue;
}

void cntSetCounter(int val)
{
  countValue = val;
}
