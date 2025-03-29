// DIPAE - Enosmatomena Systimata - 6o Eksamino
// Alevropoulos Panagiotis
// AM: 2022005
// Askisi MPLAB_test
#include <main_.h>

#use standard_io (A) // Standard Eisodoi & Eksodoi
#use standard_io (B) // Standard Eisodoi & Eksodoi
#use standard_io (C) // Standard Eisodoi & Eksodoi
#byte PORTA =0xF80 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTB =0xF81 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTC =0xF82 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTD =0xF83 // Orismos ton thiron me ti thesi tous sti mnimi
#byte PORTE =0xF84 // Orismos ton thiron me ti thesi tous sti mnimi

int1 previous_L_TO_H = 1; // Metavliti gia na mporoume na allazoume to metopo energopoiisis tis diakopis mesa sti routina eksipiretisis

// Dilosi sinartiseon Interrupts
void ext_int(void);
void ext_int1(void);
void ext_int2(void);
void init();

void main()
{
	init();
   	while (TRUE) {
		
   	}
}   

// Ylopoioisi sinartiseon Interrupts
#INT_EXT
void ext_int() {
	PORTD = PORTD ^ 0xFF;
	// Me ton parakato tropo mporoume na allazoume to metopo energopoiisis tis diakopis mesa sti routina eksipiretisis
	if (previous_L_TO_H) // An i proigoumeni katastasi tou metopou L se H itan TRUE...
		ext_int_edge(0, H_TO_L); // ...allazei to metopo tis diakopis apo H se L...
	else
		ext_int_edge(0, L_TO_H); // ...allios allazei to metopo tis diakopis apo L se H
	previous_L_TO_H = !previous_L_TO_H;
}
#INT_EXT1
void ext_int1() {
	PORTD = PORTD ^ 0xFF;
}
#INT_EXT2
void ext_int2() {
	PORTD = PORTD ^ 0xFF;
}

void init() {
   	set_tris_b(0xff); // Orismos tou PORTB san eisodo (1)
	set_tris_d(0x00); // Orismos tou PORTD san eksodo (0)
	port_b_pullups(TRUE);
	ext_int_edge(0, L_TO_H);
	ext_int_edge(1, L_TO_H);
	ext_int_edge(2, H_TO_L);
	enable_interrupts(INT_EXT);
	enable_interrupts(INT_EXT1);
	enable_interrupts(INT_EXT2);
	enable_interrupts(GLOBAL);
}