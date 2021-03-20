#include <stdio.h>

void read_a(int a[10][10], int i1, int j1_i2) {
	for (int c1 = 1; c1 <= i1; c1++)
		for (int c2 = 1; c2 <= j1_i2; c2++)
			scanf("%d", &a[c1][c2]);
}

void read_b(int b[10][10], int j1_i2, int j2) {
	for (int c1 = 1; c1 <= j1_i2; c1++)
		for (int c2 = 1; c2 <= j2; c2++)
			scanf("%d", &b[c1][c2]);
}

 int f(int a[10][10], int b[10][10], int i1, int j1_i2, int v1,int t) {
	int sum = 0;

	for (int v2 = 1; v2 <= j1_i2; v2++)
		sum += a[v1][v2] * b[v2][t];


	return sum;
}

int main() {
	int a[10][10];
	int b[10][10];
	int result[10][10];
	int i1, j1_i2, j2;
	static int v1 = 1;
	static int t = 1;

	scanf("%d%d%d", &i1, &j1_i2, &j2);

	read_a(a, i1, j1_i2);
	read_b(b, j1_i2, j2);

	for (int x = 1; x <= i1; x++) {
		for (int y = 1; y <= j2; y++) {
			result[x][y] = f(a, b, i1, j1_i2, v1, t);
			t++;
		}
		v1++;
		t = 1;
	}

	for (int x = 1; x <= i1; x++) {
		for (int y = 1; y <= j2; y++) {
			printf("%d ", result[x][y]);
		}
		puts("");
	}
}