//
// counterTest.c
//
// Test program for the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2014
//

#include <stdio.h>
#include "counterCtrl.h"

int main(void)
{
  char answer;
  
  cntCtrlInit(0);
  
  do
  {
    printf("\n-------------------------------------------\n");
    printf("    u   Count up\n");
    printf("    d   Count down\n");
    printf("    c   Count\n");
    printf("    s   Stop counting\n");
    printf("    q   Quit\n");

    printf("\nPlease press key: ");
    scanf("%c", &answer);
    getchar();  // nach scanf() ist noch ein '\n' im Inputbuffer: auslesen und wegwerfen
    printf("\n");
    
    switch (answer)
    {
      case 'u':
        cntCtrlProcess(cntEvUp);
        break;
      case 'd':
        cntCtrlProcess(cntEvDown);
        break;
      case 'c':
        cntCtrlProcess(cntEvCount);
        break;
      case 's':
        cntCtrlProcess(cntEvStop);
        break;
      default:
        break;
    }
  } while (answer != 'q');
  
  return 0;
}

