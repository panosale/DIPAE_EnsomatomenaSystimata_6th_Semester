#include <main_.h>
#include <keypad_sim.h>

#byte PORTB=0xf81
#byte PORTD=0xf83

//------------------Function Definition------------------------------
void init (void);
//-------------------------------------------------------------------
void main() {
   char k;
   init();
   kbd_init();
   while(TRUE) {
      k=kbd_getc();
      if(k!=0) { // Check if key press
         PORTD = k & 0x0f;
      }
   }
}

//-----------------------------------------------------------
//------------------Function declaration--------------
//-----------------------------------------------------------

void init (void) {
   set_tris_d(0x00);
   PORTD = 0;
}
//-----------------------------------------------------------

