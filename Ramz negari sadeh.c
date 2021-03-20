#include<stdio.h>

int main(void) {
	int a;
	int b;
	int c1, c2, c3, c4;

	scanf("%d", &a);
	b = a % 10;
	b = b + 7;
	c1 = b % 10;
	a = a / 10;
	b = 0;

	b = a % 10;
	b = b + 7;
	c2 = b % 10;
	a = a / 10;
	b = 0;

	b = a % 10;
	b = b + 7;
	c3 = b % 10;
	a = a / 10;
	b = 0;

	b = a % 10;
	b = b + 7;
	c4 = b % 10;

	printf("%d%d%d%d", c2, c1, c4, c3);
}