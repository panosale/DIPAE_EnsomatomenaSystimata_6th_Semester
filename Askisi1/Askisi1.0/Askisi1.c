#include <main_.h>

#use standard_io ( A )
#use standard_io ( B )
#use standard_io ( C )
#byte PORTA =0xF80
#byte PORTB =0xF81
#byte PORTC =0xF82
#byte PORTD =0xF83
#byte PORTE =0xF84

void main() {
   set_tris_b(0x00);
   set_tris_d(0xff);
   while (1) {
      PORTB = PORTD;
   }
}
