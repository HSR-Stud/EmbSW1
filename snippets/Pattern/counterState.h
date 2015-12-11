//
// counterState.h
//
// implements an up/down-Counter
// this file contains all classes of the state machine
// it may make sense to have separate files for each state
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Nov. 2014
//

#ifndef COUNTERSTATE_H__
#define COUNTERSTATE_H__
#include "counterctrl.h"  // Events are defined here

class CounterState  // abstract base class
{
  public:
    virtual CounterState* process(Counter& entity, CounterCtrl::Event e) = 0;
    // returns new state
  protected:    // only inherited classes may use these member functions
    CounterState* changeState(Counter& entity, CounterState* pnewState);
};

class IdleState : public CounterState // it's a singleton
{
  public:
    static IdleState* getInstance();
    virtual CounterState*  process(Counter& entity, CounterCtrl::Event e);
  private:
    IdleState() {};
    static IdleState instance;
};

class CountUpState : public CounterState // it's a singleton
{
  public:
    static CountUpState* getInstance();
    virtual CounterState*  process(Counter& entity, CounterCtrl::Event e);
  private:
    CountUpState() {};
    static CountUpState instance;
};

class CountDownState : public CounterState // it's a singleton
{
  public:
    static CountDownState* getInstance();
    virtual CounterState*  process(Counter& entity, CounterCtrl::Event e);
  private:
    CountDownState() {};
    static CountDownState instance;
};
#endif
