//
// counterCtrl.cpp
//
// implements the Finite State Machine (FSM) of an up/down-Counter as a simple table
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2013
//

#include <iostream>
#include "counterCtrl.h"
#include "counter.h"
using namespace std;

const CounterCtrl::Transition CounterCtrl::fsm[] =  // this table defines the fsm
{//currentState     triggering event  action function                 next state
  {idleState,       evUp,             &CounterCtrl::actionIdleUp,     countUpState},
  {idleState,       evDown,           &CounterCtrl::actionIdleDown,   countDownState},
  {countUpState,    evCount,          &CounterCtrl::actionUpUp,       countUpState},
  {countUpState,    evStop,           &CounterCtrl::actionDoNothing,  idleState},
  {countDownState,  evCount,          &CounterCtrl::actionDownDown,   countDownState},
  {countDownState,  evStop,           &CounterCtrl::actionDoNothing,  idleState}
};

CounterCtrl::CounterCtrl(int initValue) : 
  currentState(idleState),
  myCounter(initValue)
{
}

void CounterCtrl::process(Event e)    // execution engine, this function never changes
{
  for (size_t i = 0; i < sizeof(fsm) / sizeof(Transition); ++i) // determine number of transitions automatically
  {
    if (fsm[i].currentState == currentState &&  fsm[i].ev == e) // is there an entry in the table?
    {
      (this->*fsm[i].pAction)();
      currentState = fsm[i].nextState;
      break;
    }
  }
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

void CounterCtrl::actionDoNothing(void)
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
