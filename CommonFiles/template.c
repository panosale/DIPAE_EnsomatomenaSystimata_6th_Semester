// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Askisi X.X
#include <main_.h> // Gia ektelesi se Proteus
//#include <main.h> // Gia ektelesi se PIC

#use standard_io (A) // Standard Eisodoi & Eksodoi
#use standard_io (B) // Standard Eisodoi & Eksodoi
#use standard_io (C) // Standard Eisodoi & Eksodoi
#byte PORTA =0xF80 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTB =0xF81 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTC =0xF82 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTD =0xF83 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTE =0xF84 // Orismos ton thiron me ti thesi tous sti mnimi

#define Toggle_Led0 PORTD^=0x1; // Antrisotrfi tou bit RD0
#define Toggle_Led1 PORTD^=0x2; // Antrisotrfi tou bit RD1
#define Toggle_Led2 PORTD^=0x4; // Antrisotrfi tou bit RD2
#define Toggle_Led3 PORTD^=0x8; // Antrisotrfi tou bit RD3
#define Toggle_Led4 PORTD^=0x10; // Antrisotrfi tou bit RD4
#define Toggle_Led5 PORTD^=0x20; // Antrisotrfi tou bit RD5
#define Toggle_Led6 PORTD^=0x40; // Antrisotrfi tou bit RD6
#define Toggle_Led7 PORTD^=0x80; // Antrisotrfi tou bit RD7

void main()
{
   set_tris_b(0xff); // Orismos tou PORTB san eisodo (1)
   set_tris_d(0x00); // Orismos tou PORTD san eksodo (0)

//   set_tris_b(0x00); // Orismos tou PORTB san eksodo (0)
//   set_tris_d(0xff); // Orismos tou PORTD san eisodo (1)

   while (TRUE) {

   }
}   

