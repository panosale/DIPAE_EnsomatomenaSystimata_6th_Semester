#include <stdio.h>
#include <string.h>
#include <iostream>
// ������� 1 - ����
int erotisi1() {
	char s1[20] = "Hello";
	char s2[15];
	short x;
	strcpy(s2, s1);
	x = strlen(s2);
	printf("EROTISI 1: x = %d\n", x);
}
// ������� 1 - �����

// ������� 2 - ����
int erotisi2() {
	char s1[20] = "This is a test";
	char s2[] = "at";
	strcpy(strstr(s1, "is"), s2);
	printf("EROTISI 2: s1 = ");
	std::cout << s1;
	printf("\n");
}
// ������� 2 - �����

// ������� 3 - ����
int erotisi3() {
	printf("EROTISI 3: ");
	short xx = 1;
	#define xx 2
	#if xx == 1
		std::cout << "one";
	#elif xx == 2
		std::cout << "two";
	#else
		std::cout << "trhee";
	#endif
}
// ������� 3 - �����

int main() {
	erotisi1();
	erotisi2();
	erotisi3();
// ������� 3 - ����
//	printf("EROTISI 3: ");
//	int table1[10] = {1, 2};
//	unsigned char sum = 0;
//	for (int i = 0; i < sizeof(table1); i++)
//		sum+=table1[i];
//	printf("\n");
// ������� 3 - �����

// ������� 4 - ����

// ������� 4 - �����

}

