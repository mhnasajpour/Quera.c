#include<stdio.h>
#pragma warning(disable:4996)

void read(int a[100][100], int i, int j) {
	for (int m = 0; m < i; m++)
		for (int n = 0; n < j; n++)
			scanf("%d", &a[m][n]);
}

int f(int a[100][100], int i, int j) {
	int sum = 0;
	for (int m = 1; m < i - 1; m++) {
		for (int n = 1; n < j - 1; n++) {
			if (a[m][n] < a[m - 1][n] && a[m][n] < a[m + 1][n] && a[m][n] > a[m][n - 1] && a[m][n] > a[m][n + 1])
				sum++;
			else if (a[m][n] > a[m - 1][n] && a[m][n] > a[m + 1][n] && a[m][n] < a[m][n - 1] && a[m][n] < a[m][n + 1])
				sum++;
		}
	}
	return sum;
}

int main() {
	int a[100][100];
	int i, j;
	scanf("%d%d", &i, &j);
	read(a, i, j);
	printf("%d", f(a, i, j));
}