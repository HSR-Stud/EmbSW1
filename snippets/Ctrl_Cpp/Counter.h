//
// Counter.h
//
// implements an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#ifndef COUNTER_H__
#define COUNTER_H__

class Counter
{
  public:
    Counter(int val = 0);

    void count(int step);
    // counts the counter up (step>0) or down (step<0) by step

    int getCounter() const;
    // returns the counter value

    void setCounter(int val);
    // sets the counter to val
  private:
    int countValue;
};

#endif
