//
// CounterCtrl.cpp
//
// implements the Finite State Machine (FSM) of an up/down-Counter as a table
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#include <iostream>
#include "CounterCtrl.h"
#include "Counter.h"
using namespace std;

const CounterCtrl::Transition CounterCtrl::fsm[] =  // this table defines the fsm
{//currentState     checker function              action function               next state
  {idleState,       &CounterCtrl::checkIdleUp,    &CounterCtrl::actionIdleUp,   countUpState},
  {idleState,       &CounterCtrl::checkIdleDown,  &CounterCtrl::actionIdleDown, countDownState},
  {countUpState,    &CounterCtrl::checkUpUp,      &CounterCtrl::actionUpUp,     countUpState},
  {countUpState,    &CounterCtrl::checkUpIdle,    &CounterCtrl::actionUpIdle,   idleState},
  {countDownState,  &CounterCtrl::checkDownDown,  &CounterCtrl::actionDownDown, countDownState},
  {countDownState,  &CounterCtrl::checkDownIdle,  &CounterCtrl::actionDownIdle, idleState}
};

CounterCtrl::CounterCtrl(int initValue) : 
  currentState(idleState),
  myCounter(initValue)
{
}

void CounterCtrl::process(Event e)    // this function never changes
{
  for (size_t i = 0; i < sizeof(fsm) / sizeof(Transition); ++i) // let compiler determine number of transitions
  {
    if (fsm[i].currentState == currentState &&  // is there an entry in the table?
        (this->*fsm[i].pChecker)(e))
    {
      (this->*fsm[i].pAction)();
      currentState = fsm[i].nextState;
      break;
    }
  }
}

// check functions
bool CounterCtrl::checkIdleUp(Event e)
{
  return evUp == e;
}

bool CounterCtrl::checkIdleDown(Event e)
{
  return evDown == e;
}

bool CounterCtrl::checkUpIdle(Event e)
{
  return evStop == e;
}

bool CounterCtrl::checkDownIdle(Event e)
{
  return evStop == e;
}

bool CounterCtrl::checkUpUp(Event e)
{
  return evCount == e;
}

bool CounterCtrl::checkDownDown(Event e)
{
  return evCount == e;
}

// action functions
void CounterCtrl::actionIdleUp(void)
{
  cout << "State: idleState, counter = " << myCounter.getCounter() << endl;
}

void CounterCtrl::actionIdleDown(void)
{
  cout << "State: idleState, counter = " << myCounter.getCounter() << endl;
}

void CounterCtrl::actionUpIdle(void)
{
}

void CounterCtrl::actionDownIdle(void)
{
}

void CounterCtrl::actionUpUp(void)
{
  myCounter.count(1);
  cout << "State: countUpState, counter = " << myCounter.getCounter() << endl;
}

void CounterCtrl::actionDownDown(void)
{
  myCounter.count(-1);
  cout << "State: countDownState, counter = " << myCounter.getCounter() << endl;
}
