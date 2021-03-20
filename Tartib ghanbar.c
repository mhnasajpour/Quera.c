#include<stdio.h>

int main()
{
	long a;
	long b;
	scanf("%ld%ld", &a, &b);
	if (a >= b) {
		//even
		if (a % 2 == 0) {
			if (b <= a / 2)
				printf("%ld", 2 * b - 1);
			else {
				b = b - a / 2;
				printf("%ld", 2 * b);
			}
		}

		//odd
		if (a % 2 == 1) {
			if (b <= a / 2 + 1)
				printf("%ld", 2 * b - 1);
			else {
				b = b - ((a / 2) + 1);
				printf("%ld", 2 * b);
			}
		}
	}
}	