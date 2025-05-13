#include <main_.h>
// Gia oso einai patimeno to BUTTON afksanei to PORTB kata 1 mexri na ftasei sto 0xff (255)
// Molis afisoume to BUTTON meionei to PORTB kata 1 mexri na ftasei sto 0x0 (0)
#use standard_io ( A )
//#use standard_io ( B )
#use standard_io ( C )
#byte PORTA =0xF80
#byte PORTB =0xF81
#byte PORTC =0xF82
#byte PORTD =0xF83
#byte PORTE =0xF84

int8 i;

void testASM(int n) {
   n = n /2;
   #asm
   #endasm
}
void push_button(void);

void main()
{
   set_tris_b(0x00); // Ορίζουμε τη θύρα B σαν ΕΞΟΔΟ (0)
   set_tris_d(0xff); // Ορίζουμε τη θύρα D σαν ΕΙΣΟΔΟ(1)
   PORTB = 0;   
   int8 i = 0;
   while(TRUE) {
      if (bit_test(PORTD, 0)) {
         PORTB ^= i;
         if (i>0)
            i--;
         PORTB ^= i;
         //output_low(PIN_B0);            
      }
      else {
         PORTB ^= i;
         if (i<255)
            i++;
         PORTB ^= i;
      }
         //output_high(PIN_B0);
      delay_ms(1000);
   }
}

void push_button(void { // Synartisi elegxou patimatos-apeleftherosis tou BUTTON
   while (input(PIN_B4) == 1) {} // To PORT kai to PIN mporoun na allaksoun analoga tin anagki
   delay_ms(50);
   while (input(PIN_B4) == 0) {} // To PORT kai to PIN mporoun na allaksoun analoga tin anagki
   delay_ms(50);   
}
