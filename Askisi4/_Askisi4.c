A.
// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Erotisi A
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
   set_tris_b(0x00); // Orismos ton tou PORTB san eksodo (0)
   set_tris_a(0xff); // Orismos ton tou PORTA san eisodo (1)
   PORTB = 0;
   while (TRUE) {
      output_bit(PIN_B0, bit_test(PORTA, 1));
   }
}   

void init(void) {
}



B.
#include <main.h> 
#byte PORTC =0xF81 
#define Toggle_Led0 PORTC^=0x02; // αντιστροφή του bit RC0 

// Δήλωση συναρτήσεων
void timer0_int(void); 
void init (void);
// Κύρια ρουτίνα
void main()
{
	init();
	while (1); // Περιμένει το Interruptinit();
}
// Κύρια ρουτίνα
while (1); // Περιμένει το Interrupt
// Ορισμός συναρτήσεων #INT_TIMER0 HIGH // Διακοπή με μεγάλη προτεραιότητα void timer0_int(void){
set_timer0(20); // αρχική τιμή του μετρητή Toggle_Led0; // Αλλαγή στην κατάσταση του Led0
}

void init (void){
}
set_tris_c(0x00); // Καθορισμός της πόρτας Β ως έξοδος SETUP_TIMER_0(T0_INTERNAL | T0_DIV_256 );
set_timer0(20); // Αρχική τιμή του hardware μετρητή enable_interrupts(INT_TIMER0); // Ενεργοποίηση της
// διακοπής του timer0
enable_interrupts(GLOBAL); // Ενεργοποίηση του γενικού
// διακόπτη των διακοπών

