#include <stdio.h>
#include <iostream>
// Ερώτηση 2 - ΑΡΧΗ
int calculate(int x, int y) {
	if (x > 5)
		x = 5;
	return x * y;
}
// Ερώτηση 2 - ΤΕΛΟΣ

int main() {
// Ερώτηση 1 - ΑΡΧΗ
	int x = 0; 
	int y = 2; 
	switch (y) {
		case 0 : x+=1;
			break;
		case 1 : x+=2;
			break;
		case 2 : x+=4;
			break;
		case 3 : x+=8;
			break;
	}
	printf("EROTISI 1: x = %d\n", x);
// Ερώτηση 1 - ΤΕΛΟΣ

// Ερώτηση 2 - ΑΡΧΗ
	x = calculate(1*2*3, 4*5);
	printf("EROTISI 2: x = %d\n", x);
// Ερώτηση 2 - ΤΕΛΟΣ

// Ερώτηση 3 - ΑΡΧΗ
	printf("EROTISI 3: ");
	int table1[10] = {1, 2};
	unsigned char sum = 0;
	for (int i = 0; i < sizeof(table1); i++)
		sum+=table1[i];
	std::cout << (int)sum;
	printf("\n");
// Ερώτηση 3 - ΤΕΛΟΣ

// Ερώτηση 4 - ΑΡΧΗ
	printf("EROTISI 4: ");
	int table2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 1; i <= 3; i++)
		std::cout <<  table2[i * 3 % 9];
	printf("\n");
// Ερώτηση 4 - ΤΕΛΟΣ

// Ερώτηση 5 - ΑΡΧΗ
	printf("EROTISI 5: ");
	int x2;
	int *p;
	int a[5];
	#locate a = 0x100
	a[0] = 3;
	a[1] = 4;
	p = a;
	x2 = p + 1;
	printf("\n");
// Ερώτηση 5 - ΤΕΛΟΣ

}

