#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int a[1000];
	int* p;
	p = a;
	int n;
	printf("How many numbers do you want to sort?\n");
	scanf("%d", &n);
	printf("put the numbers\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", (p + i));
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (*(p + i) > *(p + j)) {
				int t = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = t;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", *(p + i));
	}
}