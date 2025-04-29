// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Askisi: Test endeikti 8 tomeon
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

const int16 timer_start_value = 5536; // Orismos arxikis timis timer0;

int8 number1=0;
int8 number2=0; 
int16 sum=0;
int8 des=0;

// Dilosi pinaka katastaseon Endeikti 7 tomeon koinis kathodou
int8 table[16] = {0x3f, // 0b00111111 -> 0
                  0x06, // 0b00000110 -> 1
                  0x5b, // 0b01011011 -> 2
                  0x4f, // 0b01001111 -> 3
                  0x66, // 0b01100110 -> 4
                  0x6d, // 0b01101101 -> 5
                  0x7d, // 0b01111101 -> 6
                  0x07, // 0b00000111 -> 7
                  0x7f, // 0b01111111 -> 8
                  0x6f, // 0b01101111 -> 9
                  0x77, // 0b01110111 -> A
                  0x7c, // 0b01111100 -> b
                  0x39, // 0b00111001 -> C
                  0x5e, // 0b01011110 -> d
                  0x79, // 0b01111001 -> E
                  0x71}; // 0b01110001 -> F

// Dilosi pinaka tranzistor gia energopoiisi tou PORTC ton 3 endikton kai tin emfanisi psifion
int8 dig[3] = {1, 2, 4};

// Dilosi sinartiseon eksipiretisis
void timer0_int(void);
void init(void);
int8 number(void);

void main()
{
   init();
   while (TRUE) { //
      while (input(PIN_D7) ==1) { // Elegxos tou RD1 gia logiko 1 
      } 
      number1 =  (int8) number();// Klisi tis function number() µe epistrofi int8
      sum = number1; 
      while (input(PIN_D7) ==0) {
      }
      number2 = (int8) number(); 
      sum = number2;
      delay_ms(500); 
      sum = number1 + number2 ; 
      delay_ms(2000);
      sum = 0;
   }
}   

#INT_TIMER0
void timer0_int(void) {
   int16 mon, dec, eka;
   eka = 0;
   dec = (int8) (sum / 10); // Dekades
   mon = (int8) (sum % 10); // Monades
   set_timer0(timer_start_value); // Arxikopoiisi tou timer0;
   des = ++des % 3; // Module 3 metritis 
                    // pou leitourgei os deiktis 
                    // gia ton pinaka epilogis tou psifiou
                    // pou deixnei kathe stigmi.
   PORTC = dig[des]; // Epilogi enos apo ta 3 psifia
   if (des == 0)
      PORTB = table[mon]; // Deikse tis monades
   if (des == 1)
      PORTB = table[dec]; // Deikse tis dekades
   if (des == 2)
      PORTB = table[eka]; // Deikse tis ekatonades
}

void init(void) {
   set_tris_b(0x00); // Orismos tou PORTB san eksodo (0)
   set_tris_c(0x00); // Orismos tou PORTBC san eksodo (0)
   set_tris_d(0xff); // Orismos tou PORTBD san eisodo (1)
   PORTB = 0;
   PORTC = 0;
   des = 0; // Arxikopoiisi tis epilogis psifiou
   SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1); // Prescaler
   set_timer0(timer_start_value); // Arxikopoiisi tou timer0;
   enable_interrupts(INT_TIMER0); // Arxikopoiisi tou interrupt timer0;
   enable_interrupts(GLOBAL); // Energopoiisi genikou diakopti diakopon
}

int8 number(void) {
   int8 temp;
   delay_ms(30);
   temp = PORTD & 0x0f;
   return(temp);
}
