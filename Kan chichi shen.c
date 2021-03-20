#include<stdio.h>

void read(int a[6][6]) {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			scanf("%d", &a[i][j]);
}

int f3_3(int a[6][6], int i, int j) {
	int c[3][3] = { {1,0,-1},{1,0,-1},{1,0,-1} };
	int sum = 0;

	for (int c1 = 0; c1 < 3; c1++) {
		for (int c2 = 0; c2 < 3; c2++) {
			sum += a[i + c1][j + c2] * c[c1][c2];
		}
	}
	return sum;
}

int main() {
	int a[6][6], i, j;

	read(a);

	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= 3; j++) {
			printf("%d ", f3_3(a, i, j));
		}
		puts("");
	}
}