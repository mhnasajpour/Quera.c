#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void shift_right(char a[2000], char b[2000]) {
	for (int i = 0; i < strlen(b); i++) {
		b[i] = b[i + 1];
	}
	int c = atoi(b);
	for (int i = 1; i <= c; i++) {
		char t = a[strlen(a) - 1];
		for (int j = strlen(a) - 1; j >= 0; j--) {
			a[j] = a[j - 1];
		}
		a[0] = t;
	}
	a[strlen(a) + 1] = '\0';
	printf("%s\n", a);
}

void shift_left(char a[2000], char b[2000]) {
	for (int i = 0; i < strlen(b); i++) {
		b[i] = b[i + 1];
	}
	int c = atoi(b);
	for (int i = 1; i <= c; i++) {
		char t = a[0];
		for (int j = 0; j < strlen(a) - 1; j++) {
			a[j] = a[j + 1];
		}
		a[strlen(a) - 1] = t;
	}
	a[strlen(a) + 1] = '\0';
	printf("%s\n", a);
}

void zarb(char a[2000], char b[2000]) {
	char t[2000];
	strcpy(t, a);
	for (int i = 0; i < strlen(b); i++) {
		b[i] = b[i + 1];
	}
	int c = atoi(b);
	for (int i = 2; i <= c; i++)
		strcat(a, t);
	a[strlen(a) + 1] = '\0';
	printf("%s\n", a);
}

void jam(char a[2000], char b[2000]) {
	for (int i = 0; b[i] != '\0'; i++)
		b[i] = b[i + 1];
	strcat(a, b);
	a[strlen(a) + strlen(b) + 1] = '\0';
	printf("%s\n", a);
}

void menha(char a[2000], char b[2000]) {
	for (int i = 0; i < strlen(b); i++) {
		b[i] = b[i + 1];
	}
	for (int h = 0; h < strlen(a); h++) {
		if (a[h] == b[0]) {
			int m = 1;
			for (int w = 1; w < strlen(b); w++) {
				if (a[h + w] == b[w])
					m++;
				else break;
			}
			if (m == strlen(b)) {
				for (int p = 0; p < strlen(a); p++) {
					a[h+p] = a[h+p+ strlen(b)];
				}
				break;
			}
		}
	}
	printf("%s\n", a);
}


int main() {
	char a[2000];
	char b[2000] = {};
	gets(a);
	while (1) {
		gets(b);
		if (b[0] == '+')jam(a, b);
		if (b[0] == '-')menha(a, b);
		if (b[0] == '<')shift_left(a, b);
		if (b[0] == '>')shift_right(a, b);
		if (b[0] == '*')zarb(a, b);
		if (b[0] == 'x')return 0;
	}
}