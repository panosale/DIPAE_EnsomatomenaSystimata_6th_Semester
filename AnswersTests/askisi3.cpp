#include <stdio.h>

// Ερώτηση 6
main(void) {
	// 2.
//	printf("%d", 2+3*5);

	// 3.
	int value;
	char c1, c2, c3;
	c1 = '3';
	c2 = '2';
	c3 = '1';
	printf("%d\n", (c1 - '0') * 100);
	printf("%d\n", (c2 - '0') *10 );
	printf("%d\n", (c3 - '0'));
	value = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0');
	printf("%d\n", value);

	// 4.
//	short x = 128;
//	printf("x % 8 = %d\n", x % 8);
//	printf("x & 7 = %d\n", x & 7);
//	printf("(x<<5)>>5 = %d\n", (x<<5)>>5);
//	printf("(x>7 ? x-8:x = %d\n", x>7 ? x-8:x);

	// 5.
//	int x = 0;
//	printf("++++++--x = %d", ++++++--x);

	// 6.
//	int aa, bb, cc, dd;
//	if (aa) {
//		printf("road 1\n");
//		if (bb) {
//			cc = 1;
//			printf("road 2\n");
//		}
//		else
//			if (dd) {
//				cc = 2;
//				printf("road 3\n");
//			}
//			else {
//				cc = 3;
//				printf("road 3\n");
//			}
//	}
//	printf("\n");
//	printf("aa = %d\nbb = %d\ncc = %d\ndd = %d\n", aa, bb, cc, dd);

	// 7.
//	int i, j, x = 0;
//	for (i = 1; i <= 5; i++)
//		for (j=1; j <= 5; j++, x++) {
//			if (j == i) {
//				printf("break\n");
//				printf("\n");
//				break;
//			}
//			else
//				printf("i = %d, j = %d\n", i, j);
//		}
//	printf("x = %d\n", x);
}

