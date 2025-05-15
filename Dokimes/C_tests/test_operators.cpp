#include <stdio.h>

main() {
	int i = 51;
	int k = i & 0b00001111; // bitwise operation
	printf("i = %d\nk = %d", i, k);
}
