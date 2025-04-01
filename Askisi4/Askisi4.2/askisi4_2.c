// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Askisi 4 - Test timer
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

const int8 RB7_init_val_counter = 2;
const int8 RB6_init_val_counter = 5;
const int8 RB5_init_val_counter = 10;
const int8 RB4_init_val_counter = 20;
const int8 RB3_init_val_counter = 80;

int16 timer_start_value = 56161; // Orismos arxikis timis timer0;
int8 RB7_counter = RB7_init_val_counter; // Led on RB7 counter
int8 RB6_counter = RB6_init_val_counter; // Led on RB6 counter
int8 RB5_counter = RB5_init_val_counter; // Led on RB5 counter
int8 RB4_counter = RB4_init_val_counter; // Led on RB4 counter
int8 RB3_counter = RB3_init_val_counter; // Led on RB3 counter

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

#INT_TIMER0
void timer0_int(void) {
   set_timer0(timer_start_value);
   // Led on RB7 flashing
   RB7_counter--;
   if (RB7_counter == 0) {
      PORTB = PORTB ^ 0b10000000;
      RB7_counter = RB7_init_val_counter;
   }
   // Led on RB6 flashing
   RB6_counter--;
   if (RB6_counter == 0) {
      PORTB = PORTB ^ 0b01000000;
      RB6_counter = RB6_init_val_counter;
   }
   // Led on RB5 flashing
   RB5_counter--;
   if (RB5_counter == 0) {
      PORTB = PORTB ^ 0b00100000;
      RB5_counter = RB5_init_val_counter;
   }
   // Led on RB4 flashing
   RB4_counter--;
   if (RB4_counter == 0) {
      PORTB = PORTB ^ 0b00010000;
      RB4_counter = RB4_init_val_counter;
   }
   // Led on RB3 flashing
   RB3_counter--;
   if (RB3_counter == 0) {
      PORTB = PORTB ^ 0b00001000;
      RB3_counter = RB3_init_val_counter;
   }
}

void init(void) {
   set_tris_b(0x00); // Orismos ton 4 MSB tou PORTB san eksodo (0) kai ton 4 LSB tou san eisodo (1)
//   PORTB = 0x00;
   port_b_pullups(TRUE);
//   ext_int_edge(1, L_TO_H); // Gia na mporoume na allazoume to metopo kata tin ektelesi tiw routinas eksiporetisis prepei to interrupt afto na ksekinaei apo L_TO_H 
//   ext_int_edge(1, H_TO_L); 
   SETUP_TIMER_0(T0_INTERNAL | T0_DIV_128);
   set_timer0(timer_start_value);
   enable_interrupts(INT_TIMER0);
//   enable_interrupts(INT_EXT1); // Energopoiisi eksoterikis diakopis RB1
   enable_interrupts(GLOBAL); // Energopoiisi genikou diakopti diakopon
}
