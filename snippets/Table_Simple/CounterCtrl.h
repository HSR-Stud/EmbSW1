//
// CounterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter as a simple table
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__
#include "Counter.h"

class CounterCtrl
{
  public:
    enum Event{evUp,       // count upwards
               evDown,     // count downwards
               evCount,    // count (up or down)
               evStop};    // stop counting
    CounterCtrl(int initValue = 0);
    void process(Event e);
    // changes the state of the FSM based on the event 'e'
    // starts the actions

  private:
    enum State{idleState,         // idle state
               countUpState,      // counting up at each count event
               countDownState};   // counting down at each count event

    State currentState;           // holds the current state of the FSM
    Counter myCounter;
    
    typedef void (CounterCtrl::*Action)(void);   // function ptr for action function
  
    // action functions
    void actionIdleUp(void);
    void actionIdleDown(void);
    void actionDoNothing(void);
    void actionUpUp(void);
    void actionDownDown(void);
    
    struct Transition
    {
      State currentState;   // current state
      Event ev;             // event triggering the transition
      Action pAction;       // pointer to action function
      State nextState;      // next state
    };
    static const Transition fsm[];
};
#endif
