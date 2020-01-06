//
// counterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2019
//

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__

typedef enum {cnt_evUp,       // count upwards
              cnt_evDown,     // count downwards
              cnt_evCount,    // count (up or down)
              cnt_evStop}     // stop counting
             cnt_Event;

void cnt_ctrlInit(int initValue);
// initializes counter FSM

void cnt_ctrlProcess(cnt_Event e);
// changes the state of the FSM based on the event 'e'
// starts the actions

#endif
