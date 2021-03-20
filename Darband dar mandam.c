#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int d;
	scanf("%d", &d);
	char a[1000][1000];
	for (int i = 0; i < d; i++)
		scanf("%s", a[i]);

	for (int i = 0; i < d - 1; i++) {
		printf("%s to %s: ke ba in dar agar dar bande dar manand, dar manand.\n", a[i], a[i + 1]);
		for (int j = i; j >= 0; j--) {
			printf("%s to %s: dar manand?\n", a[j + 1], a[j]);
		}
		for (int m = 0; m <= i; m++) {
			printf("%s to %s: dar manand.\n", a[m], a[m + 1]);
		}
	}
}