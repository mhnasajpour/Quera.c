#include <stdio.h>
#include <math.h>

float fac(int);
double e(int, int);

int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	printf("%.3lf", e(x, n));
}
float fac(int a) {
	if (a == 1 || a == 0) return 1;
	return a * fac(a - 1);
}
double e(int x, int n) {
	double sum = 0;
	if (n == 1)return 1;
	for (; n >= 1; n--)
		sum += pow(x, n - 1) / fac(n - 1);
	return sum;
}