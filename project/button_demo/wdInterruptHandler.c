#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  if (++blink_count == 125) {
    /*
    if (blink_mode == 1){
      state_advance_flip();
      blink_count = 0;
    }
    if (blink_mode = 0){
      state_advance();
      blink_count = 0;
      
    }
    */

    state_advance();
    blink_count = 0;
  }
}
