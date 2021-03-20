#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	char** a = (char**)malloc(x * sizeof(char*));
	for (int i = 0; i < x; i++) {
		a[i] = (char*)malloc(y * sizeof(char));
	}

	for (int i = 0; i < x; i++) {
		getchar();
		for (int j = 0; j < y; j++) {
			scanf("%c", &a[i][j]);
		}
	}

	for (int i = 1; i < x - 1; i++) {
		for (int j = 1; j < y - 1; j++) {
			if (a[i][j] == '+') {
				if (a[i][j + 1] == '+') {
					if (a[i - 1][j + 1] == '+' && a[i - 1][j] != '+') {
						printf("bad wall");
						return 0;
					}
					else if (a[i + 1][j + 1] == '+' && a[i + 1][j] != '+') {
						printf("bad wall");
						return 0;
					}
				}
				
				if (a[i + 1][j] == '+') {
					if (a[i + 1][j + 1] == '+' && a[i][j + 1] != '+') {
						printf("bad wall");
						return 0;
					}
					else if (a[i + 1][j - 1] == '+' && a[i][j - 1] != '+') {
						printf("bad wall");
						return 0;
					}
				}
			}
		}
	}
	printf("good wall");
	return 0;
}