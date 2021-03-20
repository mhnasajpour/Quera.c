#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	char a[50][20];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		printf("%s ", a[i]);
	}
}