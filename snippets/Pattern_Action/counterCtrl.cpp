//
// counterCtrl.cpp
//
// implements the Finite State Machine (FSM) of an up/down-Counter
// CounterCtrl is the Context class in the State pattern
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Nov. 2014
//

#include "counter.h"
#include "counterState.h"
#include "counterCtrl.h"

CounterCtrl::CounterCtrl(int initValue) :
  entity(initValue), 
  pState(IdleState::getInstance()) // initial state
{
  pState = pState->init(entity);
}

void CounterCtrl::process(Event e)
{ // delegates all requests to CounterState
  pState =  pState->process(entity, e);  // entity: reference to entity class object
}
