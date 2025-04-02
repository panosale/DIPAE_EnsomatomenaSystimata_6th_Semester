// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Askisi 4.1
#include <main_.h>

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


int1 previous_H_TO_L = 1; // Metavliti gia na mporoume na allazoume to metopo energopoiisis tis diakopis mesa sti routina eksipiretisis
int16 timer_start_value = 18661; // Orismos arxikis timis timer0;
int1 car_in_zone = 0;
int8 counter = 2;
int8 low_counter = 4;
int8 hi_counter = 2;

// Dilosi sinartiseon eksipiretisis
void timer0_int(void);
void ext_int1(void);
void init(void);

void main()
{
   init();
   while (TRUE) {
   }
}   

#INT_EXT1
void ext_int1(void) {
   // Me ton parakato tropo mporoume na allazoume to metopo energopoiisis tis diakopis mesa sti routina eksipiretisis
   if (previous_H_TO_L) // An i proigoumeni katastasi tou metopou L se H itan TRUE...
      ext_int_edge(1, L_TO_H); // ...allazei to metopo tis diakopis apo H se L...
   else
      ext_int_edge(1, H_TO_L); // ...allios allazei to metopo tis diakopis apo L se H
   car_in_zone = previous_H_TO_L;
   previous_H_TO_L = !previous_H_TO_L;
   // car_in_zone = 1;
}

#INT_TIMER0
void timer0_int(void) {
   set_timer0(timer_start_value);
   counter--;
   if ((!car_in_zone) && (counter == 0)) {
      PORTB = PORTB & 0b00010000;
      PORTB = PORTB ^ 0b00010000;
      counter = low_counter;
   }
   if ((car_in_zone) && (counter == 0)) {
      PORTB = PORTB & 0b10000000;
      PORTB = PORTB ^ 0b10000000;
      counter = hi_counter;
   }
}

void init(void) {
   set_tris_b(0x0f); // Orismos ton 4 MSB tou PORTB san eksodo (0) kai ton 4 LSB tou san eisodo (1)
   PORTB = 0x00;
   port_b_pullups(TRUE);
   ext_int_edge(1, L_TO_H); // Gia na mporoume na allazoume to metopo kata tin ektelesi tiw routinas eksiporetisis prepei to interrupt afto na ksekinaei apo L_TO_H 
//   ext_int_edge(1, H_TO_L); 
   SETUP_TIMER_0(T0_INTERNAL | T0_DIV_32);
   set_timer0(timer_start_value);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(INT_EXT1); // Energopoiisi eksoterikis diakopis RB1
   enable_interrupts(GLOBAL); // Energopoiisi genikou diakopti diakopon
}
