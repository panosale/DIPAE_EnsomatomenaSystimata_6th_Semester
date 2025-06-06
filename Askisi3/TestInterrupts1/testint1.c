// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Test Interrupts #1
#include <main_.h>

#use standard_io (A) // Standard Eisodoi & Eksodoi
#use standard_io (B) // Standard Eisodoi & Eksodoi
#use standard_io (C) // Standard Eisodoi & Eksodoi
#byte PORTA =0xF80 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTB =0xF81 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTC =0xF82 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTD =0xF83 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTE =0xF84 // Orismos ton thiron me ti thesi tous sti mnimi

// Dilosi global metavliton
int8 counter = 0x30;

// Dilosi sinartiseon
void ext_int0(void);
void init(void);

void main()
{
   init();
   while (TRUE) {

   }
}   

// Ylopoiisi synartiseon
#INT_EXT // Diakopi me megali proteraiotita
void ext_int0(void) {
   counter--;
   if (counter == 0)
      counter = 0x30;
   PORTD = counter;
   delay_ms(300); // Gia na apofygoume tis anapidiseis tou diakopti
}

void init(void) {
   set_tris_b(0xff); // Orismos tou PORTB san eisodo (1)
   set_tris_d(0x00); // Orismos tou PORTD san eksodo (0)
   PORTD = counter;
   port_b_pullups(TRUE);
   ext_int_edge(0, H_TO_L);
   enable_interrupts(INT_EXT); // Energopoiisi eksoterikis diakopis RB0
   enable_interrupts(GLOBAL); // Energopoiisi genikou diakopti diakopon
}
