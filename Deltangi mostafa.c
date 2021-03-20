#include<stdio.h>

int main() {
	long long unsigned int num, count, a, sum = 0;
	long long unsigned int m, x;

	scanf("%llu", &num);
	for (count = 1; count <= num; count++) {
		scanf("%llu", &a);
		if (num >= 1 && a >= 1) {
			m = a;
			for (int r = 1; r <= a; r++) {
				m = a;
				m = m - r;
				sum = 0;
				x = 0;
				while (m != 0) {
					x = m % 10;
					m /= 10;
					sum += x;
				}
				if (sum == r) {
					puts("Yes");
					break;
				}
				if (r == a) {
					puts("No");
					break;
				}

			}
		}
		
	}
}