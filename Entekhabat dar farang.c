#include<stdio.h>
#include<math.h>

int main()
{
	int a, n = 1;
	scanf("%d", &a);
	a = a - 1;
	while (a >= n-1) {
		n *= 2;
	}
	int m = a - n / 2;
	if (m == -1)
		puts("1");
	else if (m == 0)
		puts("3");
	else printf("%d", 2 * m + 3);
}