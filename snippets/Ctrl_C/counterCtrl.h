//
// counterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2014
//

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__

typedef enum {cntEvUp,       // count upwards
              cntEvDown,     // count downwards
              cntEvCount,    // count (up or down)
              cntEvStop}     // stop counting
             CntEvent;

void cntCtrlInit(int initValue);
// initializes counter FSM

void cntCtrlProcess(CntEvent e);
// changes the state of the FSM based on the event 'e'
// starts the actions

#endif
