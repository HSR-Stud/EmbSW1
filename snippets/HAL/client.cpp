#include <bsl/include/Led.h>
#include <bsl/include/Switch.h>

using bsl::Led;
using bsl::Switch;

int main(){
  Led statusIndicator(Led::led1);
  Switch statusSwitch(Switch::switch1);
  // ledInit(), switchInit() gone

  while (1){
    if(statusSwitch.pressed())
      statusIndicator.on();
    else
      statusIndicator.off();
  }
  return 0;
}
