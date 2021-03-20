#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int s = 0, i, j, z;
	for (i = 1; i <= n / 2; i++) {
		for (j = i; i + j < n, j <= n / 2; j++) {
			z = n - i - j;
			if (z >= j && i + j > z)
				s++;
		}
	}
	printf("%d", s);
}