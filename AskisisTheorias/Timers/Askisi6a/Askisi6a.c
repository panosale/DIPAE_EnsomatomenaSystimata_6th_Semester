// Askisi 6a theorias gia timer0
// Anavosvinoun ta led sto PORTB kathe 200ms (20 * 10ms)
#include <main_.h>
#use standard_io ( A )
#use standard_io ( B )
#use standard_io ( C )
#byte PORTA =0xF80
#byte PORTB =0xF81
#byte PORTC =0xF82
#byte PORTD =0xF83
#byte PORTE =0xF84

// Ypologizoume me logo 1/64 tin periodo stin eisodo tou timer0
// 10ms = 10000��
// 64 * 83.33ns = 5333.12ns = 5.3312�s
// (65536 - y) * 5.3312�s = 10000 => 65536 - y = 10000 / 5.3312 =>
// 65536 - y = 1875 => y = 63661
#define TIMER_INITIAL_VALUE 63661 // H ypologismeni periodos apo ton parapano typo. 
#define COUNTER1_VALUE 20 // Timi tou counter prokeimenou na ftasoume sta 200ms. 
// INTERRUPTS HANDLING
void init(void);
void timer0_int(void);
int8 counter1;

void main()
{
   init();
   while(TRUE) {
   }
}

void init(void) {
   set_tris_b(0x00); // �������� �� ���� B ��� ����� (0)
   PORTB = 0x00;   
   counter1 = COUNTER1_VALUE; // Epeidi 200 = counter1 * 10 ara counter1 = 20
   // Arxikopoiisi interrupts
   SETUP_TIMER_0(T0_INTERNAL | T0_DIV_64);
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_TIMER0);
   set_timer0(TIMER_INITIAL_VALUE);
}

// INTERRUPTS HANDLING
#INT_TIMER0
void timer0_int() {
   set_timer0(TIMER_INITIAL_VALUE); // Arxikopoiisi panta tou timer0 me tin arxiki timi poy ypologisame
   counter1--; // Meiosi to counter mexri na ginei 0 oste na ftasoume ta 200ms (20 * 10 = 200ms)
   if (counter1 == 0) { // Otan o counter1 ginei 0, ara eftase sta 200ms
      counter1 = COUNTER1_VALUE; // arxikopoiisi tou pali sto 20
      PORTB = PORTB ^ 0b11111111; // Allagi katastasis ton led sto PORTB
   }
}

