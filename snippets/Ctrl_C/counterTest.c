//
// counterTest.c
//
// Test program for the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2019
//

#include <stdio.h>
#include "counterCtrl.h"

int main(void)
{
  char answer;
  
  cnt_ctrlInit(0);
  
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
        cnt_ctrlProcess(cnt_evUp);
        break;
      case 'd':
        cnt_ctrlProcess(cnt_evDown);
        break;
      case 'c':
        cnt_ctrlProcess(cnt_evCount);
        break;
      case 's':
        cnt_ctrlProcess(cnt_evStop);
        break;
      default:
        break;
    }
  } while (answer != 'q');
  
  return 0;
}

