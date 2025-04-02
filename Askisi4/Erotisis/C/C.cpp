#include <stdio.h>
// Ερώτηση C
int main() {
	int x; 
	char s[20] = "000000"; 
	for (int i=0; i<=4; i++) {
		s[i] = '0' + i + 1;
	}
	s >> x;
}

