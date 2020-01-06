//
// CounterCtrl.cpp
//
// implements the Finite State Machine (FSM) of an up/down-Counter
// CounterCtrl is the Context class in the State pattern
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2018
//

#include "Counter.h"
#include "CounterState.h"
#include "CounterCtrl.h"

CounterCtrl::CounterCtrl(int initValue) :
  entity(initValue), 
  pState(CounterState::init(entity)) // initial state
{
}

void CounterCtrl::process(Event e)
{ // delegates all requests to CounterState
  pState =  pState->handle(entity, e);  // entity: reference to entity class object
}
