#include <main_.h>
#include <keypad_sim.h>
#include <flex_lcd_sim.h>

#byte PORTB=0xf81
#byte PORTD=0xf83

//---------------------------------------------------
int8 state=1;
char N1=0;
char N2=0;

//------------------Function Definition--------------------------------
void init (void);
//---------------------------------------------------------------------

void main() {
   char k;
   init();
   lcd_init();
   kbd_init();
   while(TRUE) {
      switch(state) {
      case 1:
         k=kbd_getc();
         while (k!=0) {
            N1= k & 0b00001111;
            printf (lcd_putc, "%1d+", N1 );
            state = 2;
            break;
         }
      break;
      case 2:
         k=kbd_getc();
         while (k!=0) {
            N2 = k & 0b00001111;
            printf (lcd_putc, "%1d=", N2 );
            N2 = N2 + N1;
            printf (lcd_putc, "%2d", N2 );
            N1=0;
            N2=0;
            state = 1;
            delay_ms(2000);
            printf (lcd_putc, "\f" );
            break;
         }
      }
   }
}
//-----------------------------------------------------------
//------------------Function declaration--------------
//-----------------------------------------------------------
void init (void) {
   set_tris_d(0x00);
}
//-----------------------------------------------------------
