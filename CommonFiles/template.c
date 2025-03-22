// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Askisi X.X
#include <main_.h>

#use standard_io (A) // Standard Eisodoi & Eksodoi
#use standard_io (B) // Standard Eisodoi & Eksodoi
#use standard_io (C) // Standard Eisodoi & Eksodoi
#byte PORTA =0xF80 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTB =0xF81 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTC =0xF82 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTD =0xF83 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTE =0xF84 // Orismos ton thiron me ti thesi tous sti mnimi

void main()
{
   set_tris_b(0x00); // Orismos tou PORTB san eksodo (0)
   set_tris_d(0xff); // Orismos tou PORTD san eisodo (1)

   while (TRUE) {

   }
}   

