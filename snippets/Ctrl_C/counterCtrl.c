//
// counterCtrl.c
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2011
//

#include <stdio.h>
#include "counterCtrl.h"
#include "counter.h"

typedef enum {idleState,        // idle state
              countUpState,     // counting up at each count event
              countDownState}   // counting down at each count event
             State;

static State currentState = idleState; // holds the current state of the FSM

void cntCtrlInit(int initValue)
{
  currentState = idleState;
  cntInit(initValue);
}


void cntCtrlProcess(CntEvent e)
{
  switch (currentState)
  {
    case idleState:
      printf("State: idleState\n");
      if (cntEvUp == e)
      {
        // actions
        printf("State: idleState, counter = %d\n", cntGetCounter());
        // state transition
        printf("Changing to State: countUpState\n");
        currentState = countUpState;
      }
      else if (cntEvDown == e)
      {
        // actions
        printf("State: idleState, counter = %d\n", cntGetCounter());
        // state transition
        printf("Changing to State: countDownState\n");
        currentState = countDownState;
      }
      break;
      
    case countUpState:
      printf("State: countUpState\n");
      if (cntEvCount == e)
      {
        // actions
        cntCount(1);
        printf("State: countUpState, counter = %d\n", cntGetCounter());
        // state transition
      }
      else if (cntEvStop == e)
      {
        // actions
        // state transition
        printf("Changing to State: idleState\n");
        currentState = idleState;
      }
      break;
      
    case countDownState:
      printf("State: countDownState\n");
      if (cntEvCount == e)
      {
        // actions
        cntCount(-1);
        printf("State: countDownState, counter = %d\n", cntGetCounter());
        // state transition
      }
      else if (cntEvStop == e)
      {
        // actions
        // state transition
        printf("Changing to State: idleState\n");
        currentState = idleState;
      }
      break;
      
    default:
      break;
  }
}

