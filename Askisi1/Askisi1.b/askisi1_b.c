// ����� - ������������ ��������� - 6� �������
// ������������ ���������� - ��: 2022005
// ������ 1.�

#include <main_.h>
#include <string.h>

#use standard_io(A)
#use standard_io(B)
#use standard_io(C)
#byte PORTA=0xF80
#byte PORTB=0xF81
#byte PORTC=0xF82
#byte PORTD=0xF83
#byte PORTE=0xF84

void main()
{
   set_tris_b(0xff); // �������� �� ���� B ��� ������ (1)
   set_tris_d(0x00); // �������� �� ���� D ��� ����� (0)
   char eponymo[20] = "Alevropoulos";
   int mikos_eponymou = strlen(eponymo);
   int a; // ������ �� ��������� ���� ��� while � ������� ��� �����;
   while(TRUE) {
      a = PORTB;
      set_tris_d(a);
      PORTD = 6 * mikos_eponymou;
      //delay_ms(5000);
   }
}
