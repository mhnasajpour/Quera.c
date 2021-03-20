#include<stdio.h>
#include<math.h>


int main() {
	long int a, b, m;
	long int n = 1;
	long long int sum = 0;
	scanf("%ld%ld", &a, &b);

	if (a >= 0 && b >= 0) {
		while (a != 0) {
			m = a % 10;
			a = a / 10;
			sum = sum + m * (long long int)pow(10, n);
			n += 2;
		}
		n = 0;
		while (b != 0) {
			m = b % 10;
			b = b / 10;
			sum = sum + m * (long long int)pow(10, n);
			n += 2;
		}
		printf("%lld", sum);
	}
}