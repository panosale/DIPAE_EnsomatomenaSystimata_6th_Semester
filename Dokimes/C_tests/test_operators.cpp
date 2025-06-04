#include <stdio.h>

void printBinary(short num) {
    for (char i = sizeof(char) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}
int bit_test(int num, int bit) { // Xreiazete diorthosi
	return num ^ bit;
}

main() {
	char i = 0b01100110;
	char k = 0b00011100;
	printf("Bitwise AND operation: %d & %d = %d\n", i, k, i & k);
	printf("Bitwise OR operation: %d | %d = %d\n", i, k, i | k);
	printf("Bitwise XOR operation: %d ^ %d = %d\n", i, k, i ^ k);
	printf("Logical NOT operation: !%d = %d\n", i, !i);
	printf("Shift left: %d << %d = %d\n", 5, 2, 5 << 2);
	
	char last_b = 163;
	char port_b = 227;
	char changes = last_b ^ port_b;
	printf("last_b ===> "); printBinary(last_b);
	printf("port_b ===> "); printBinary(port_b);
	printf("last_b ^(XOR) port_b\n" );
	printf("changes ==> "); printBinary(changes);
	printf("bit_test(changes, 4) = "); printBinary(bit_test(changes, 4));
	printf("\n\nsizeof(char): %d bytes\n", sizeof(char));
	printf("sizeof(short): %d bytes\n", sizeof(short));
	printf("sizeof(int): %d bytes\n", sizeof(int));
	printf("sizeof(float): %d bytes\n", sizeof(float));
	printf("sizeof(double): %d bytes\n", sizeof(double));
}
