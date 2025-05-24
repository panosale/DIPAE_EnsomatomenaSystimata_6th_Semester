#include <main.h>
#include <lcd.h>
#byte PORTA         =0xF80
#byte PORTB         =0xF81
#byte PORTC         =0xF82
#byte PORTD         =0xF83
#byte PORTE         =0xF84
#use standard_io ( A )
#use standard_io ( B )
#use standard_io ( C )

#define motor_gnd  PIN_D4
#define sw1 ((PORTE & 0x01) > 0)
#define sw2 ((PORTE & 0x02) > 0)
#define sw3 ((PORTE & 0x04) > 0)

byte const POSITIONS[8] =
			    {0b0101,
                           0b0001,
                           0b1001,
                           0b1000,
                           0b1010,
                           0b0010,
                           0b0110,
                           0b0100};
int8 dir;
static BYTE stepper_state = 0;
void init( void );                      
void drive_stepper(int16 speed, int8 dir, int16 steps);
void main()
{ 
       delay_ms ( 1000 );
	init();
       LCD_Init();
       LCD_PutCmd ( CLEAR_DISP );
       LCD_SetPosition ( LINE_1 + 2 );
       printf ( LCD_PutChar, "MOTOR TESTER    " );
       LCD_SetPosition ( LINE_2 + 0 );
       printf ( LCD_PutChar, "TMH HLEKTRONIKHS" );
    	delay_ms(2000);
   while (TRUE) 
   {      
      if (sw1){
      LCD_SetPosition ( LINE_1 + 2 );
       printf ( LCD_PutChar, "ROTATE LEFT    " );
      dir=1;
      drive_stepper(2500,dir,200);
      
      }
      if (sw2){
      LCD_SetPosition ( LINE_1 + 2 );
       printf ( LCD_PutChar, "ROTATE RIGHT   " );
      dir=0;
      drive_stepper(2500,dir,200);
      
      
      }
      if (sw3){
      LCD_SetPosition ( LINE_1 + 2 );
      printf ( LCD_PutChar, "ROTATE RIGHT   " );
      dir=0;
      drive_stepper(2500,dir,400);
      LCD_SetPosition ( LINE_1 + 2 );
      printf ( LCD_PutChar, "ROTATE LEFT    " );
      dir=1;
      drive_stepper(2500,dir,400);
      
      }
	delay_ms(1000);
   } 
}

    
void init( void )
   {
  
   set_tris_b(0x00);
   set_tris_d(0x00);
   set_tris_e(0x0f);
   output_low (motor_gnd);
   
   }
void drive_stepper(int16 speed, int8 dir, int16 steps)
 {
   
   int16 i;

   for(i=0; i<steps; ++i) {
      			delay_us(speed);
      			PORTD = POSITIONS[ stepper_state ];
      			if(dir== 1){
      					stepper_state=(stepper_state+1)&(sizeof(POSITIONS)-1);
      					 }
     			 if (dir == 0){
       					stepper_state=(stepper_state-1)&(sizeof(POSITIONS)-1);
             				 }
   				}
      			LCD_SetPosition ( LINE_1 + 2 );
      			printf ( LCD_PutChar, "ROTATE STOP   " );
}