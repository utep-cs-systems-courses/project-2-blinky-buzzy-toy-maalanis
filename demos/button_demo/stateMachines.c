#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"

extern char power = 1;

char toggle_red()		/* always toggle! */
{
  static char sound = 0;

  switch (sound) {

  case 0:

    buzzer_set_period(1000);
    sound = 1;
    break;
  case 1:
    buzzer_set_period(2000);
    sound = 2;
    break;
  case 2:
    buzzer_set_period(2500);
    sound = 3;
    break;
  case 3:
    buzzer_set_period(3000);
    sound = 0;
    break;
    
    
  }

  return 1;

  /*
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }

  return 1;			/* always changes an led */
 
}


char toggle_green()	/* only toggle green if red is on!  */
{
  
  /*
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
 */
  buzzer_set_period(0);
  return 1;
}


void state_advance()		/* alternate between toggling red & green */
{

  if(power) {
    toggle_red();
   
  } else {
    toggle_green();
    
  }
  

  
  
}



