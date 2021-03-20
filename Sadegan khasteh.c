#include <stdio.h>

int Reverse(int input) {
	int reverse = 0;
	while (input != 0) {
		reverse = reverse * 10 + input % 10;
		input /= 10;
	}
	return reverse;
}

int main() {

	int a, b;
	scanf("%d%d", &a, &b);
	int ra = Reverse(a);
	int rb = Reverse(b);
	if (ra < rb) {
		printf("%d < %d", a, b);
	}
	else if (ra > rb) {
		printf("%d < %d", b, a);
	}
	else if (ra == rb) {
		printf("%d = %d", b, a);
	}

	return 0;
}