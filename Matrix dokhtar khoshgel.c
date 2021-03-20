#include<stdio.h>
#pragma warning(disable:4996)

void read(int a[7][7]) {
	for (int i = 0; i < 7; i++) 
		for (int j = 0; j < 7; j++) 
			scanf("%d", &a[i][j]);
}

void sort(int a[7][7]) {
	int t;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i<3 && j>i && i + j < 6) {
				t = a[i][j];
				a[i][j] = a[6 - i][j];
				a[6 - i][j] = t;
			}
			if (j<3 && i>j && i + j < 6) {
				t = a[i][j];
				a[i][j] = a[i][6 - j];
				a[i][6 - j] = t;
			}
		}
	}
}

int main() {
	int a[7][7];
	read(a);
	sort(a);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}