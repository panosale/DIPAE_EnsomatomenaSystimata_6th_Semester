#include <main.h>
#byte PORTA         =0xF80
#byte PORTB         =0xF81
#byte PORTC         =0xF82
#byte PORTD         =0xF83
#byte PORTE         =0xF84
byte const Half_step[8] = 
			     {0b0101,
                           0b0001,
                           0b1001,
                           0b1000,
                           0b1010,
                           0b0010,
                           0b0110,
                           0b0100};
                           
byte const Full_step[4] = 
			     {0b0101,
                           0b1001,
                           0b1010,
                           0b0110};

int8 dir = 0;
int16  steps = 0;
int8 mode = 0;
int16 speed = 5000;                          
static BYTE stepper_state=0;
//------------------Function Definition------------------------------
void init (void);
//-------------------------------------------------------------------
void main()
{
init();
 
while(TRUE)
      {
	dir = PORTB & 0b01000000;
	mode = PORTB & 0b10000000;
	steps = (int16) (PORTB & 0b00111111) * 10;
	speed = 5000;
	int16 i;
	
         if(mode == 0x80)         // 
              {
                for(i=0; i<steps; ++i) {
      							delay_us(speed);
      							PORTD = Half_step [ stepper_state ];
     							 if(dir == 0x40){
       									stepper_state=(stepper_state+1)&(sizeof(Half_step)-1);
            						 		}
      							 if (dir == 0){
       									stepper_state=(stepper_state-1)&(sizeof(Half_step)-1);
              								}
   							}
       		 }
	else {
		 for(i=0; i<steps; ++i) {
      							delay_us(speed);
      							PORTD = Full_step [ stepper_state ];
     							 if(dir == 0x40){
       									stepper_state=(stepper_state+1)&(sizeof(Full_step)-1);
            						 		}
      							 if (dir == 0){
       									stepper_state=(stepper_state-1)&(sizeof(Full_step)-1);
              								}
   							}
	       }
	Delay_ms(2000);
     }
}
//-----------------------------------------------------------
//------------------Function declaration---------------------

void init (void){
set_tris_b(0xff);
set_tris_d(0x00);
PORTD=0;
stepper_state=0;
}

//-------------------------------------------------------------
