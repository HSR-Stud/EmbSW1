//
// counterState.cpp
//
// implements all states of an up/down-Counter
// this file contains all classes of the state machine.
// it may make sense to have separate files for each state
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Nov. 2014
//

#include <iostream>
#include "counterState.h"
using namespace std;


// class CounterState
CounterState* CounterState::changeState(Counter& entity, CounterState* pnewState)
{
  return pnewState;
}

// class IdleState
IdleState IdleState::instance;
IdleState* IdleState::getInstance()
{
  return &instance;
}

CounterState* IdleState::process(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: idleState" << endl;
  if (CounterCtrl::evUp == e)
  {
    // transition actions
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountUpState::getInstance());
  }
  else if (CounterCtrl::evDown == e)
  {
    // transition actions
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountDownState::getInstance());
  }
  return this;
}

// class CountUpState
CountUpState CountUpState::instance;
CountUpState* CountUpState::getInstance()
{
  return &instance;
}

CounterState* CountUpState::process(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countUpState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // transition actions
    entity.count(1);
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountUpState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // transition actions
    // state transition
    return changeState(entity, IdleState::getInstance());
  }
  return this;
}


// class CountDownState
CountDownState CountDownState::instance;
CountDownState* CountDownState::getInstance()
{
  return &instance;
}

CounterState* CountDownState::process(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countDownState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // transition actions
    entity.count(-1);
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountDownState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // transition actions
    // state transition
    return changeState(entity, IdleState::getInstance());
  }
  return this;
}
