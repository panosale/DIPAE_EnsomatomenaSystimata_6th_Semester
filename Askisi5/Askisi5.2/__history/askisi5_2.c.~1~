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
int8 seconds=0;
int8 sec_set_counter = 20;
int8 minute=0;
int8 hour=12;
int8 counter;
int1 flag=0;
int8 table[16] =          {  0b00111111, //0
                     	     0b00000110, //1
                             0b01011011, //2
                             0b01001111, //3
                             0b01100110, //4
                             0b01101101, //5
                             0b01111101, //6
                             0b00000111, //7
                             0b01111111, //8
                             0b01101111, //9
                             0b01101011, //Ω
                             0b00110111, //Π
                             0b00111001, 
                             0b01011110, 
                             0b01111001, 
                             0b01110001};  

int8 dig[3] = {1,2,4};
// Δήλωση συναρτήσεων

void timer0_int(void);
void init (void);

void main()
{
      init(); 
   
     while (1){    	     //  Περιμένει το Interrupt 
      	       }
}

// Ορισμός συναρτήσεων 

#INT_TIMER0    // Διακοπή με μεγάλη προτεραιότητα
void timer0_int(void){
	int16 mon,dec,eka;
	set_timer0(5536); // αρχική τιμή του μετρητή
	sec_set_counter--;
	if ((sec_set_counter == 0)){
		 sec_set_counter = 1;
		  if((bit_test(PORTD,2) == 1) && (bit_test(PORTD,0) == 1)){
		     seconds++; // Αυξάνει κάθε 1/10 sec
		     if (seconds > 59){
			    seconds = 0;
			    minute++;
			    if (minute > 59){
			        minute = 0;
		            hour++;
						        }
				    if (hour >23){
					    hour = 0;
				   		         }
			         	     }
			 												}
			
		 if((bit_test(PORTD,2) == 1) && (bit_test(PORTD,1) == 1)){
		     	seconds--;
		     if (seconds > 59){
		     	seconds = 59;
		     	 minute--;
							  }
		     	 if (minute > 59){ // Μειώνει κάθε 1 sec
		             minute = 59;
		             hour--;
		       					}
		       		if(hour > 23){
		       		      hour = 23;
		       					}      			
			        	                                        }   
                        	    }
    counter--; // Κάθε 200 * 5 msec  = 1 sec
    if (counter%100 == 0){flag^=1;}		        	                                         																               	     
	if (counter == 0){
					counter = 200;
					
		if (bit_test(PORTD,2) == 0){
			 	seconds++; // Αυξάνει κάθε 1 sec
					if (seconds > 59){
									   seconds = 0;
									   minute++;
									   if (minute > 59){
													   minute = 0;
													   hour++;
														}
													if (hour >23){
														hour = 0;
													    }				   
									  }				  
				            	  }	
							}			           	
			
    		if (flag == 0){
						  dec = (int8)minute / 10;
						  mon =  minute - dec * 10;
						  eka = 11;
						}
			if (flag == 1){
						  dec = (int8)hour / 10;
						  mon =  hour - dec * 10;
						  eka = 10;
						}
			
			des = ++des%3;
			
			PORTC = dig[des];
			if (des==0){
						PORTB = table[mon];
		          								
						}			
								
			if (des==1){
						PORTB = table[dec];
		          								
						}				
			if (des==2){
						PORTB = table[eka];
		          		
						}					
}							
void init (void){
		     set_tris_b(0x00);     // Καθορισμός της πόρτας Β ως έξοδος
		     set_tris_c(0x00);     // Καθορισμός της πόρτας C ως έξοδος
		     set_tris_d(0xff);
		     PORTB = 0;
		     PORTC = 0;
		     counter = 200;	    // Αρχική τιμή του counter
			 seconds = 0;
			 sec_set_counter = 1;
			 minute =0;
			 hour = 12;
			 des =0;
			 flag = 0;
		     SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1 );
		     set_timer0(5536);   //  Αρχική τιμή του  hardware μετρητή 
      		 enable_interrupts(INT_TIMER0); // Ενεργοποίηση της 								    // διακοπής του timer0
      		 enable_interrupts(GLOBAL);       // Ενεργοποίηση του γενικού 							   // διακόπτη των διακοπών
				
		}

