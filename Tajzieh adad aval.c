#include<stdio.h>

int main() {
	int a;
	int b = 1;
	int n = 0;
	int t, count;

	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		scanf("%d", &a);
		count = 1;
		if (a > 0) {
			while (a != 1) {
				b++;
				while (a % b == 0) {
					a = a / b;
					n++;
				}
				if (count == 2) {
					if (n > 1) printf("*%d^%d", b, n);
					else if (n == 1) printf("*%d", b);
				}
				if (count == 1) {
					if (n > 1) printf("%d^%d", b, n), count++;
					else if (n == 1) printf("%d", b), count++;

				}
				n = 0;
			}
			b = 1;
			printf("\n");
		}
	}
}