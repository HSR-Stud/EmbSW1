#include <bsl/include/led.h>
#include <bsl/include/switch.h>

int main(void){
  bsl_Led statusIndicator;
  bsl_ledInit(&statusIndicator, bsl_led1);
  bsl_Switch statusSwitch;
  bsl_switchInit(&statusSwitch, bsl_switch1);

  while(1){
    if(bsl_switchPressed(&statusSwitch))
      bsl_ledOn(&statusIndicator);
    else
      bsl_ledOff(&statusIndicator);
  }
  return 0;
}
