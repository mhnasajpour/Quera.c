#include<stdio.h>

int main()
{
	int a, b, n = 0;
	double a1;
	scanf("%lf", &a1);
	a = a1;
	while (a1 != a) {
		a1 = a1 * 10;
		a = a1;
	}
	while (a != 0) {
		b = a % 10;
		a /= 10;
		n = (10 * n) + b;
	}
	if (n == a1) puts("You will be safe");
	else puts("You will die");
}