// ����� - ������������ ��������� - 6� �������
// ������������ ���������� - ��: 2022005
// ������ 1.�

#include <stdio.h>
#include <string.h>

/*
#include <main_.h>
#use standard_io(A)
#use standard_io(B)
#use standard_io(C)
#byte PORTA=0xF80
#byte PORTB=0xF81
#byte PORTC=0xF82
#byte PORTD=0xF83
#byte PORTE=0xF84
*/

main()
{
//   set_tris_b(0xff); // �������� �� ���� B ��� ������ (1)
//   set_tris_d(0x00); // �������� �� ���� D ��� ����� (0)
   char eponymo[20] = "Alevropoulos";
   int mikos_eponymou = strlen(eponymo);
   printf("Mikos eponymou: %d\n", mikos_eponymou);
   int a; // ������ �� ��������� ���� ��� while � ������� ��� �����;
   while(1) {
   	
  	printf("Dose enan arithmo: ");
  	scanf("%d", &a); // ���� ��� tmp_portd = PORTD;
//      a = PORTB;
//    set_tris_d(a);
//    PORTD = 6 * mikos_eponymou;
	printf("%d\n", 6 * mikos_eponymou);
    //delay_ms(5000);
   }
}
