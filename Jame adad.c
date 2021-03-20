#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)

int main() {
	char a[30][600];
	int n, t = 0;
	int max_strlen = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}

	for (int u = 0; u < n; u++) {
		if (max_strlen < strlen(a[u]))
			max_strlen = strlen(a[u]);
	}
	int* sum;
	sum = (int*)calloc(max_strlen, sizeof(*sum));
	for (int j = max_strlen - 1; j != -1; j--, t++) {
		for (int i = 0; i < n; i++) {
			if ((int)strlen(a[i]) - 1 - t >= 0)
				sum[j] += a[i][strlen(a[i]) - 1 - t] - 48;
		}
		if (j >= 1)
			sum[j - 1] = sum[j] / 10;

		if (j > 0)
			sum[j] %= 10;
	}
	int r = 0;
	int p = 0;
	for (; sum[p] == 0; p++);
	for (; p < max_strlen; p++) {
		printf("%d", sum[p]);
		r++;
	}
	if (r == 0)printf("0");
}