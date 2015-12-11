//
// counterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2013
//

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__
#include "counter.h"

class CounterState;  // forward declaration

class CounterCtrl
// this is the 'Context' class of the State pattern
{
  public:
    enum Event{evUp,       // count upwards
               evDown,     // count downwards
               evCount,    // count (up or down)
               evStop};    // stop counting
    CounterCtrl(int initValue = 0);
    void process(Event e);  
    // changes the state of the FSM based on the event 'e'
    
  private:
    Counter entity;
    CounterState* pState;  // holds the current state
};
#endif
