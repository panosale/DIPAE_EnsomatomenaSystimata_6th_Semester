#include <main_.h>

#use standard_io ( A )   // Standard είσοδοι και έξοδοι   // Standard είσοδοι και έξοδοι 
#use standard_io ( B)
#use standard_io ( C )
#byte PORTA         =0xF80  //ορισμός των θυρών με την θέση τους στην 	
#byte PORTB         =0xF81
#byte PORTC         =0xF82
#byte PORTD         =0xF83
#byte PORTE         =0xF84
int8  des=0;
int16 seconds=0;
int8 table[16] =          {  0b00111111, 
                     	     0b00000110, 
                             0b01011011, 
                             0b01001111, 
                             0b01100110, 
                             0b01101101, 
                             0b01111101, 
                             0b00000111, 
                             0b01111111, 
                             0b01101111, 
                             0b01110111, 
                             0b01111100, 
                             0b00111001, 
                             0b01011110, 
                             0b01111001, 
                             0b01110001};  

int8 dig[3] = {1,2,4};
// Δήλωση συναρτήσεων

void timer0_int(void);
void init (void);
void ext_int1(void);
void main()
{
      init(); 
   
     while (1){    	     //  Περιμένει το Interrupt 
      	       }
}

// Ορισμός συναρτήσεων 
#INT_EXT1 
void ext_int1(void){
	seconds++;
	disable_interrupts(INT_EXT1);		   		                        
}

#INT_TIMER0    // Διακοπή με μεγάλη προτεραιότητα
void timer0_int(void){
	int16 mon,dec,eka;
	if (seconds >999){
			 seconds = 0;
			         }				  
						
	eka = (int8) (seconds /100);
    dec = (int8) ((seconds - (100*eka))/10);
	mon = (int8) (seconds - (100 * eka) -(10 * dec));
			set_timer0(5536); // αρχική τιμή του μετρητή
			des = ++des%3;
			PORTC = dig[des];
			if (des==0){
						PORTD = table[mon];
		          		CLEAR_INTERRUPT(INT_EXT1);
						enable_interrupts(INT_EXT1);						
						}			
								
			if (des==1){
						PORTD = table[dec];
		          								
						}				
			if (des==2){
						PORTD = table[eka];
		          		
						}					
}							
void init (void){
		     set_tris_b(0xff);     // Καθορισμός της πόρτας Β ως είσοδος
		     set_tris_c(0x00);     // Καθορισμός της πόρτας C ως έξοδος
		     set_tris_d(0x00);     // Καθορισμός της πόρτας D ως έξοδος
		     PORTD = 0;
		     PORTC = 0;
		     seconds = 0;
			 des =0;
			 port_b_pullups(TRUE); 
      		 ext_int_edge(1, H_TO_L);
		     SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1 );
		     set_timer0(5536);   //  Αρχική τιμή του  hardware μετρητή
		     enable_interrupts(INT_EXT1); 
      		 enable_interrupts(INT_TIMER0); // Ενεργοποίηση της 								    // διακοπής του timer0
      		 enable_interrupts(GLOBAL);       // Ενεργοποίηση του γενικού 							   // διακόπτη των διακοπών
				
		}

