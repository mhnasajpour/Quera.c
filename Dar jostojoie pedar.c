#include <stdio.h>
#ifdef _MSC_BUILD
#define scanf scanf_s
#endif

int f1(int a) {
	int sum1 = 0;
	while (a > 0) {
		sum1 += a % 10;
		a /= 10;
	}
	return sum1;
}

int f2(int a) {
	int sum2 = 0;
	int z = a;
	for (int i = 2; i <= a; i++) {
		if (z % i == 0)
			sum2 += i;
		while (z % i == 0)
			z /= i;
	}
	return sum2;
}

int main() {
	int a;
	int i, b;
	scanf("%d", &b);
	for (int x = 1; x <= b; x++) {
		scanf("%d", &a);
		for (i = a; i != 0; ) {
			if (a == i + f1(i) + f2(i)) {
				puts("Yes");
				break;
			}
			i--;
			if (i == 1)puts("No");
		}
	}	
}