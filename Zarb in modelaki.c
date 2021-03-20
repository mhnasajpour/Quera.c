#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void read_a(int** a, int i1, int j1_i2) {
	for (int c1 = 0; c1 < i1; c1++)
		for (int c2 = 0; c2 < j1_i2; c2++)
			scanf("%d", &a[c1][c2]);
}

void read_b(int** b, int j1_i2, int j2) {
	for (int c1 = 0; c1 < j1_i2; c1++)
		for (int c2 = 0; c2 < j2; c2++)
			scanf("%d", &b[c1][c2]);
}

int f(int** a, int** b, int i1, int j1_i2, int v1, int t) {
	int sum = 0;

	for (int v2 = 0; v2 < j1_i2; v2++)
		sum += a[v1][v2] * b[v2][t];


	return sum;
}

int main() {
	int i1, j1_i2, j2;
	static int v1 = 0;
	static int t = 0;

	scanf("%d%d%d", &i1, &j1_i2, &j2);

	int** a = (int**)malloc(i1 * sizeof(int*));
	for (int i = 0; i < i1; i++) {
		a[i] = (int*)malloc(j1_i2 * sizeof(int));
	}
	
	int** b = (int**)malloc(j1_i2 * sizeof(int*));
	for (int i = 0; i < j1_i2; i++) {
		b[i] = (int*)malloc(j2 * sizeof(int));
	}
	read_a(a,i1, j1_i2);
	read_b(b, j1_i2, j2);

	int** result = (int**)malloc(i1 * sizeof(int*));
	for (int d = 0; d < i1; d++) {
		result[d] = (int*)malloc(j2 * sizeof(int));
	}

	for (int x = 0; x < i1; x++) {
		for (int y = 0; y < j2; y++) {
			result[x][y] = f(a, b, i1, j1_i2, v1, t);
			t++;
		}
		v1++;
		t = 0;
	}
	free(a);
	free(b);
	for (int x = 0; x < i1; x++) {
		for (int y = 0; y < j2; y++) {
			printf("%d ", result[x][y]);
		}
		puts("");
	}
	free(result);
}