#include<stdio.h>

int prime(int a) {
	if (a % 2 == 0)
		return 0;
	for (int counter = 3; counter <= a / 2; counter+=2) {
		if (a % counter == 0)
			return 0;
	}
	return 1;
}

int makos(int a) {
	int n = 0, k;
	for (; a > 0;) {
		k = a % 10;
		a = a / 10;
		n = (10 * n) + k;
	}
	return n;
}

int mabna(int a, int b) {
	int i = 0;
	int j = b;
	for (; a >= j * b; j = b * j);
	while (j != 0) {
		i = a / j;
		a %= j;
		j /= b;
		if (j != 0)
			printf("%d", i);
	}
	return i;
}

int main() {
	int n, b;
	int a, i = 1;
	scanf("%d%d", &n, &b);
	for (a = 3; 1; a+=2) {
		if (prime(a)) {
			if (a == makos(a))
				i++;
		}
		if (i == n) {
			printf("%d", mabna(a, b));
			break;
		}
	}
}