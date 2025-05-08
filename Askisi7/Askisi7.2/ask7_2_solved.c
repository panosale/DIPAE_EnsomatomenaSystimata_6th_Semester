#include <main_.h>
#include <flex_lcd_sim.h>
#use standard_io ( A )   // Standard ������� ��� ������   // Standard ������� ��� ������ 
#use standard_io ( B)
#use standard_io ( C )
#byte PORTA         =0xF80  //������� ��� ����� �� ��� ���� ���� ���� 	
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

// ������ �����������

void timer0_int(void);
void init (void);

void main()
{
      init();
      lcd_gotoxy(6,1);
      lcd_putc("Clock");
     while (1){ 
	    if (flag){     							     // a? ????? a????e? ta de?te???epta e??�???se t? LCD
		lcd_gotoxy(4,2);       //???a?? ??a��?? st? LCD
    	printf (lcd_putc, "%02d:%02d:%02d",hour,minute,seconds );  // ??p?se st? LCD t?? ??a , ?ept? , dee?te???epta
		flag = 0;
		}   	    
      	       }
}

// ������� ����������� 

#INT_TIMER0    // ������� �� ������ �������������
void timer0_int(void){
	set_timer0(5536); // ������ ���� ��� �������
	sec_set_counter--;
	if ((sec_set_counter == 0)){
		 sec_set_counter = 1;
		  if((bit_test(PORTD,2) == 1) && (bit_test(PORTD,0) == 1)){
		     seconds++; // ������� ���� 1/10 sec
		     flag = 1;
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
		     	flag = 1;
		     if (seconds > 59){
		     	seconds = 59;
		     	 minute--;
							  }
		     	 if (minute > 59){ // ������� ���� 1 sec
		             minute = 59;
		             hour--;
		       					}
		       		if(hour > 23){
		       		      hour = 23;
		       					}      			
			        	                                        }   
                        	    }
    counter--; // ���� 200 * 5 msec  = 1 sec
            	                                         																               	     
	if (counter == 0){
					counter = 200;
					
		if (bit_test(PORTD,2) == 0){
			 	seconds++; // ������� ���� 1 sec
			 	flag = 1;
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
			
    						
}							
void init (void){
		     set_tris_b(0x00);     // ���������� ��� ������ � �� ������
		     set_tris_d(0xff);
		     lcd_init();
		     counter = 200;	    // ������ ���� ��� counter
			 seconds = 0;
			 sec_set_counter = 1;
			 minute =0;
			 hour = 12;
			 des =0;
			 flag = 0;
		     SETUP_TIMER_0(T0_INTERNAL | T0_DIV_1 );
		     set_timer0(5536);   //  ������ ���� ���  hardware ������� 
      		 enable_interrupts(INT_TIMER0); // ������������ ��� 								    // �������� ��� timer0
      		 enable_interrupts(GLOBAL);       // ������������ ��� ������� 							   // �������� ��� ��������
				
		}

