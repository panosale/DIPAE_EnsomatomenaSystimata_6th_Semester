#include <stdio.h>

main() {
	int k;
	int i = 50;
	k = i & 0b00001111; // bitwise AND operation
	printf("%d AND(&) 0b00001111 = %d\n", i, k);
	k = i | 0b00001111; // bitwise OR operation
	printf("%d OR(|) 0b00001111 = %d\n", i, k);
	k = i ^ 0b00001111; // bitwise XOR operation
	printf("%d XOR(^) 0b00001111 = %d\n", i, k);
	k = ~i; // bitwise XOR operation
	printf("%d 1st COMPLEMENT(~) = %d\n", i, k);
}
