#include<stdio.h>
#include<math.h>

int main()
{
	int a, b, counter, n;
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		scanf("%d%d", &a, &b);

		if (a > b) {
			for (counter = 1; a - b > 10; counter++)
				a = a - 10;
			printf("%d\n", counter);
		}

		if (a < b) {
			for (counter = 1; b - a > 10; counter++)
				a = a + 10;
			printf("%d\n", counter);
		}
		if (a == b) puts("0");
	}
}