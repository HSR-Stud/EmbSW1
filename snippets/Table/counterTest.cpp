//
// counterTest.cpp
//
// Test program for the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Nov. 2010
//

#include <iostream>
#include "counterCtrl.h"
using namespace std;

int main(void)
{
  char answer;
  CounterCtrl myFsm(0);
  
  do
  {
    cout << endl << "-------------------------------------------" << endl;
    cout << "    u   Count up" << endl;
    cout << "    d   Count down" << endl;
    cout << "    c   Count" << endl;
    cout << "    s   Stop counting" << endl;
    cout << "    q   Quit" << endl;

    cout << endl << "Please press key: ";
    cin >> answer;
    cout << endl;
    
    switch (answer)
    {
      case 'u':
        myFsm.process(CounterCtrl::evUp);
        break;
      case 'd':
        myFsm.process(CounterCtrl::evDown);
        break;
      case 'c':
        myFsm.process(CounterCtrl::evCount);
        break;
      case 's':
        myFsm.process(CounterCtrl::evStop);
        break;
      default:
        break;
    }
  } while (answer != 'q');
  
  return 0;
}

