#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int m;
	int j = 1, i = -10;
	int sum = 0;
	scanf("%d%d", &n, &m);

	if (m >= 0 && m <= 10 && n >= 0 && n <= 10) {
		for (j = 1; j <= n; j++) {
			for (i = -10; i <= m; i++)
				sum += (i + j) * (i + j) * (i + j) / (j * j);
		}
	}
	printf("%d", sum);
}