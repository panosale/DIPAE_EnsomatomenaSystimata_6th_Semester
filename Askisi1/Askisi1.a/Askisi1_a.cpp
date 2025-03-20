// ΔΙΠΑΕ - Ενσωματωμένα Συστήματα - 6ο Εξάμηνο
// Αλευρόπουλος Παναγιώτης - ΑΜ: 2022005
// ’σκηση 1.α
/*
#include <main_.h>

#use standard_io ( A )
#use standard_io ( B )
#use standard_io ( C )
#byte PORTA =0xF80
#byte PORTB =0xF81
#byte PORTC =0xF82
#byte PORTD =0xF83
#byte PORTE =0xF84
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int checkDigits(int n) {
	int i, tmp = 0;
	int digit1 = 1;
  	for(i = 0; i < 8; i++) {
     	if ((((digit1<<i) & n)>>i) == 1){
     		tmp++;
    	}
  	}
	return tmp;
}

main() {
	char patronymo[20] = "Vasilios";
	int mikos_patronymou = strlen(patronymo);
	int PORTB =0xF81;

	printf("Mikos patronymou: %d\n", mikos_patronymou);
	printf("PORTB: %x\n", PORTB);
/*	TESTS - START
//	int t = 1;
//	int newt;
//	printf("SIZE OF int type: %d\n", INT_MIN);
//	printf("t = %d\n", t);
//	newt = t;
//	for (int i=1; i<=32; i++) {
//		newt = newt<<1;
//		printf("i: %d -> t = %d - newt = %d\n", i, t, newt);
//	}
//	return 0;
TESTS - END */	

   	while(1) {
      	int logical1 = 0;
      	int i, tmp_portd;
//      	int digit1 = 1;
      	printf("Dose enan arithmo: ");
      	scanf("%d", &tmp_portd); // Αντί της tmp_portd = PORTD;
      	tmp_portd = tmp_portd + mikos_patronymou;
      	printf("Neo mikos patronymou: %d\n", tmp_portd);
		if (tmp_portd % 2 == 0)
			printf("To mikos tou patronymou (%d) einai zygo.\n", tmp_portd);
		else
			printf("To mikos tou patronymou (%d) einai mono.\n", tmp_portd);
		logical1 = checkDigits(tmp_portd);
		printf("%d\n", logical1);
		if (logical1 % 2 == 0)
			printf("To %d einai zygo.\n", logical1);
		else
			printf("To %d einai mono.\n", logical1);
	}
}

