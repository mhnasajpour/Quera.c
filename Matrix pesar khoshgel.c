#include<stdio.h>
#pragma warning(disable:4996)

void read(float a[7][7]) {
	for (int j = 0; j < 7; j++)
		for (int i = 0; i < 7; i++) 
			scanf("%f", &a[i][j]);
}

void sort(float a[7][7]) {
	for (int i = 0; i < 7; i++)
		a[i][3] = a[i][i] + a[i][6 - i];
}

int main() {
	float a[7][7];
	read(a);
	sort(a);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			printf("%.2f ", a[i][j]);
		}
		puts("");
	}
}