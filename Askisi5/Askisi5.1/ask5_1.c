#include <main_.h>
#use standard_io ( A )   // Standard ������� ��� ������   // Standard ������� ��� ������ 
#use standard_io ( B)
#use standard_io ( C )
#byte PORTA         =0xF80  //������� ��� ����� �� ��� ���� ���� ���� 	
#byte PORTB         =0xF81
#byte PORTC         =0xF82
#byte PORTD         =0xF83
#byte PORTE         =0xF84
int8  des=0;
int16 seconds=300;
int16 counter=200;
int1 flag1=0;
int1 flag2=0;
int8 aux_counter=5;
int8 var_counter=5;
int16 temp_var=0;
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
// ������ �����������

void timer0_int(void);
void init (void);

void main()
{
      init(); 
   
     while (1){    	      
      	  if (bit_test(PORTD,1)== 1){
	      	  flag1 = 1; 
      	                            }
      	    else{
      	    	flag1 = 0;
      	    	}
              if (bit_test(PORTD,3)== 0){
	      	      seconds = 300; 
      	                                } 
      	          if (bit_test(PORTD,0)== 0){
	      	          temp_var = seconds;
	      	                                }
	          }  	     
}

// ������� ����������� 

#INT_TIMER0 // ������� �� ������ �������������
void timer0_int(void){
	int16 mon,dec,eka;
	counter--; // ���� 200 * 5 msec  = 1 sec
	if ((counter == 0)) {
			counter = 200;//200
			  if((flag1 == 0) && (flag2 == 0)){
			  seconds--; // ������� ���� 1 sec
			  				}				
			     if((seconds == 280) && (aux_counter > 0)){
					    	seconds = 280;
						    aux_counter--;
						  	flag2 = 1;
						  								}  
						    if (aux_counter == 0){
								var_counter--;
								seconds = temp_var;
												 }
								if (var_counter == 0){ 
								 aux_counter = 5;
								 var_counter = 5;
								 flag2 = 0;
								 seconds = 300;
													}   					
										      	 			   
					      }     				  
							
	eka = (int8) (seconds /100);
    dec = (int8) ((seconds - (100*eka))/10);
	mon = (int8) (seconds - (100 * eka) -(10 * dec));
			set_timer0(5536); // ������ ���� ��� �������
			
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
		     set_tris_b(0x00);     // ���������� ��� ������ � �� ������
		     set_tris_c(0x00);     // ���������� ��� ������ C �� ������
		     set_tris_d(0xff);     // ���������� ��� ������ D �� �������
		     PORTB = 0;
		     PORTC = 0;
		     counter = 200;//200	    // ������ ���� ��� counter
			 seconds = 300;
			 aux_counter=5;
			 var_counter=5;
			 des =0;
		     SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1 );
		     set_timer0(5536);   //  ������ ���� ���  hardware ������� 
      		 enable_interrupts(INT_TIMER0); // ������������ ��� 								    // �������� ��� timer0
      		 enable_interrupts(GLOBAL);       // ������������ ��� ������� 							   // �������� ��� ��������
				
		}

