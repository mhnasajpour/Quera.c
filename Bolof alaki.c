#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int result(char a[1000000], char b[1000000]) {

	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == ' ') {
			for (int j = i; j < strlen(a); j++) {
				a[j] = a[j + 1];
			}
		}
	}

	for (int i = 0; i < strlen(b); i++) {
		if (b[i] == ' ') {
			for (int j = i; j < strlen(b); j++) {
				b[j] = b[j + 1];
			}
		}
	}
	if (strcmp(a, b) == 0)return 0;
	else return 1;
}

int main() {
	int q, p = 0;
	char a[1000000];
	char b[1000000];
	scanf("%d", &q);
	getchar();
	for (int i = 0; i < q; i++) {
		gets(a);
		gets(b);
		if (strlen(a) < 100000 && strlen(b) < 100000)
			p += result(a, b);
	}
	printf("%d", p);
}