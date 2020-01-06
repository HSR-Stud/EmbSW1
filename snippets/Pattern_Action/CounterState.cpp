//
// CounterState.cpp
//
// implements all states of an up/down-Counter
// this file contains all classes of the state machine.
// it may make sense to have separate files for each state
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2018
//

#include <iostream>
#include "CounterState.h"
using namespace std;


//class CounterState
CounterState* CounterState::init(Counter& entity)  // is static
{
  CounterState* initState = IdleState::getInstance();
  initState->entryAction(entity);      // executes entry action into init state
  return initState;
}

CounterState* CounterState::changeState(Counter& entity, 
                                        Action ptransAction, 
                                        CounterState* pnewState)
{
  exitAction(entity);              // polymorphic call of exit action
  (this->*ptransAction)(entity);   // call of transition action
  pnewState->entryAction(entity);  // polymorphic call of entry action
  return pnewState;
}

void CounterState::showCounter(Counter& entity)
{
  cout << "counter = " << entity.getCounter() << endl;
}

void CounterState::countUp(Counter& entity)
{
  entity.count(1);
  cout << "counter = " << entity.getCounter() << endl;
}

void CounterState::countDown(Counter& entity)
{
  entity.count(-1);
  cout << "counter = " << entity.getCounter() << endl;
}


// class IdleState
IdleState IdleState::instance;
IdleState* IdleState::getInstance()
{
  return &instance;
}

CounterState* IdleState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: idleState" << endl;
  if (CounterCtrl::evUp == e)
  {
    // state transition
    return changeState(entity, &IdleState::showCounter, CountUpState::getInstance());
  }
  else if (CounterCtrl::evDown == e)
  {
    // state transition
    return changeState(entity, &IdleState::showCounter, CountDownState::getInstance());
  }
  return this;
}

void IdleState::entryAction(Counter& entity)
{
  cout << "Entering idleState" << endl;
}

void IdleState::exitAction(Counter& entity)
{
  cout << "Exiting from idleState" << endl;
}


// class CountUpState
CountUpState CountUpState::instance;
CountUpState* CountUpState::getInstance()
{
  return &instance;
}

CounterState* CountUpState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countUpState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // state transition
    return changeState(entity, &CountUpState::countUp, CountUpState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // state transition
    return changeState(entity, &CountUpState::emptyAction, IdleState::getInstance());
  }
  return this;
}

void CountUpState::entryAction(Counter& entity)
{
  cout << "Entering countUpState" << endl;
}

void CountUpState::exitAction(Counter& entity)
{
  cout << "Exiting from countUpState" << endl;
}

// class CountDownState
CountDownState CountDownState::instance;
CountDownState* CountDownState::getInstance()
{
  return &instance;
}

CounterState* CountDownState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countDownState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // state transition
    return changeState(entity, &CountDownState::countDown, CountDownState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // state transition
    return changeState(entity, &CountDownState::emptyAction, IdleState::getInstance());
  }
  return this;
}

void CountDownState::entryAction(Counter& entity)
{
  cout << "Entering countDownState" << endl;
}

void CountDownState::exitAction(Counter& entity)
{
  cout << "Exiting from countDownState" << endl;
}
