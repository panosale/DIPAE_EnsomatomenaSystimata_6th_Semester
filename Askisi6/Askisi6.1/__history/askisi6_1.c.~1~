#include <main_.h>

#use standard_io ( A )   // Standard e?s?d?? ?a? ???d??   
#use standard_io ( B)    // Standard e?s?d?? ?a? 	???d??
#use standard_io ( C )   // Standard e?s?d?? ?a? 	???d??

#byte PORTA         =0xF80  //???sµ?? t?? ????? µe t?? ??s? t??? st?? 
#byte PORTB         =0xF81  // µ??µ?
#byte PORTC         =0xF82
#byte PORTD         =0xF83
#byte PORTE         =0xF84
//  (Variable definition )
int8 number1=0;
int8 number2=0;
int8 number3=0;
int16 eka=0;
int16 sum=0;
int8  des=0;
char state = 1;
int8 table[16] =   {         0x3f,  // 0  Ğßíáêáò ìåôáôñïğŞò ãéá åíäåßêôç //                                7 ôïìİùí
                     	     0x06,  // 1  Ïé 10 ôéìİò ôïõ ğßíáêá
                             0x5b,  // 2
                             0x4f,  // 3
                             0x66,  // 4
                             0x6d,  // 5
                             0x7d,  // 6
                             0x07,  // 7
                             0x7f,  // 8
                             0x6f,  // 9
                             0x40,  // -
                             0x79,  // E
                             0x39, 
                             0x5e, 
                             0x79, 
                             0x71};  

int8 dig[3] = {1,2,4};     // ???a?a? µetat??p?? ??a t?? ep????? t?? ??f???

// 

void timer0_int(void);
void init (void);
int8 number(void);

//   (Main program)

void main()
{
      init(); 
   
     while (true){    	      
		    switch(state){
   case 1:
			if ((input(PIN_D7)== 0) && (input(PIN_D6)== 0)){
						
		 	number1 = (int8) number();
		 	sum = number1;
		 	delay_ms(100);
		 	state = 2;
		 	}
		 	break;
		 		
	case 2: 
		  	if ((input(PIN_D7) == 1) && (input(PIN_D6) == 1)){	
			number2 = (int8) number(); 
			sum = number2;
			delay_ms(100);
			state = 3;
			}
			break;
	case 3:
		    if ((input(PIN_D7) == 0) && (input(PIN_D6) == 1)){
						
		 	number3 = (int8) number();
		 	sum = number3;
		 	delay_ms(100);
			state = 4;
			}
			break;
	case 4:            
			delay_ms(1000);
			if (number1 == 1){
				    sum = number2 + number3;
				    eka = 0;
			                 }
			if (number1 == 2){
					if (number2 >= number3){
				    	sum = number2 - number3;
				    	eka = 0;
			                 }
					if (number2 < number3){	    
						sum = number3 - number2;
						eka = 10;
						}
							}
			if (number1 == 3){
					   	sum = (number2 * number3)%100;
				    	eka = (int8)((number2 * number3)/100);
			                 }
			if ((number1 > 3) || (number1<1)) {
						sum = 1;
						eka = 11;
							 }		
			
		   delay_ms(2000);
		   sum = 0;
		   eka = 0;
		   state = 1;
		   break;
		}
    }	
}

// ???sµ?? s??a?t?se??  (Function definition)

// ???t??a e??p???t?s?? t?? d?a??p?? (Interrupt service routine)

#INT_TIMER0  HIGH   // ??a??p? µe µe???? p??te?a??t?ta
void timer0_int(void){
	int16 mon,dec;
	
           	dec = (int8)(sum / 10); // t?? de??d??
			mon = (int8) (sum % 10);// t?? µ???d??
			set_timer0(5536); // ?????? t?µ? t?? Hardware µet??t?
			des = ++des%3;  // Modulo 3 µet??t?? p?? ?e?t????e? ?? 					      //  de??t?? ??a t?? p??a?a ep?????? 						      //  t?? ??f??? p?? de???e? ???e st??µ?
			
			PORTC = dig[des]; // ?p????? e??? ap? ta 3 ??f?a 
			if (des==0){
		          	PORTB = table[mon];// ?e??e t?? µ???de?
		               }			
								
			if (des==1){
					PORTB = table[dec];// ?e??e t?? de??de?
		       		   }				
			if (des==2){
					PORTB = table[eka];// ?e??e t?? e?at??t?de?
		       		   }					
              		}							
// ???t??a a?????p???s?? (Initialization routine)
void init (void){
		     set_tris_b(0x00);     // ?a????sµ?? t?? p??ta? ? ?? ???d??
		     set_tris_c(0x00);     // ?a????sµ?? t?? p??ta? C ?? ???d??
		     set_tris_d(0xff);      // ?a????sµ?? t?? p??ta? D ??  e?s?d??
		     PORTB = 0;
		     PORTC = 0;
		     des =0;		   // ?????? t?µ? ep?????? ??f???
		     SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1 ); // Prescaler 									         //  /1
		     set_timer0(5536);   //  ?????? t?µ? t??  hardware µet??t? 
      	     enable_interrupts(INT_TIMER0); // ??e???p???s? t?? 								    // d?a??p?? t?? timer0
      	     enable_interrupts(GLOBAL);       // ??e???p???s? t?? ?e????? 							   // d?a??pt? t?? d?a??p??
				
		}

	
Int8 number(void){
			int8 temp;
			delay_ms(30);
			temp = PORTD & 0x0F;
			return(temp);	
			}