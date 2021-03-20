#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	int b[1000][2];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int counter = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j] && a[i] != 0) {
				b[counter][0] = i + 1;
				b[counter][1] = j + 1;
				a[i] = a[j] = 0;
				counter++;
				break;
			}
		}
	}
	printf("%d\n", counter);
	for (int i = 0; i < counter; i++) {
		printf("%d %d\n", b[i][0], b[i][1]);
	}
}