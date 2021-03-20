#include <stdio.h>

long long int fac(int);

int main() {
	int a;
	scanf("%d", &a);
	printf("%lld", fac(a));
}
long long int fac(int a) {
	if (a == 1) return 1;
	return a * fac(a - 1);
}