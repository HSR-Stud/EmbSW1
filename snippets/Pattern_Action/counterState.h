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
#include "counterctrl.h"

class CounterState  // abstract base class
{
  public:
    CounterState* init(Counter& entity);
    // should be called first, returns new state
    virtual CounterState* process(Counter& entity, CounterCtrl::Event e) = 0;
    // returns new state
  protected:
    virtual void entryAction(Counter& entity) {};
    virtual void exitAction(Counter& entity) {};
    typedef void (CounterState::*Action)(Counter& entity);   // ptr to action function
    CounterState* changeState(Counter& entity, Action ptransAction, CounterState* pnewState);

    // transition actions
    void emptyAction(Counter& entity) {};
    void showCounter(Counter& entity);
    void countUp(Counter& entity);
    void countDown(Counter& entity);
};

class IdleState : public CounterState // it's a singleton
{
  public:
    static IdleState* getInstance();
    virtual CounterState*  process(Counter& entity, CounterCtrl::Event e);
  protected:
    virtual void entryAction(Counter& entity);
    virtual void exitAction(Counter& entity);
  private:
    IdleState() {};
    static IdleState instance;
};

class CountUpState : public CounterState // it's a singleton
{
  public:
    static CountUpState* getInstance();
    virtual CounterState*  process(Counter& entity, CounterCtrl::Event e);
  protected:
    virtual void entryAction(Counter& entity);
    virtual void exitAction(Counter& entity);
  private:
    CountUpState() {};
    static CountUpState instance;
};

class CountDownState : public CounterState // it's a singleton
{
  public:
    static CountDownState* getInstance();
    virtual CounterState*  process(Counter& entity, CounterCtrl::Event e);
  protected:
    virtual void entryAction(Counter& entity);
    virtual void exitAction(Counter& entity);
  private:
    CountDownState() {};
    static CountDownState instance;
};
#endif
