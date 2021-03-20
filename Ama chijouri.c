#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void rev(char* u, int i) {
	char t;
	if (i % 2 == 0) {
		for (int k = 0; k < i / 2; k++) {
			t = u[k];
			u[k] = u[i - k];
			u[i - k] = t;
		}
	}
	else {
		for (int k = 0; k <= i / 2; k++) {
			t = u[k];
			u[k] = u[i - k];
			u[i - k] = t;
		}
	}
}

int tavan(int x1, int x2) {
	if (x2 == 0)return 1;
	if (x2 == 1)return x1;
	if (x2 > 1) return x1 * tavan(x1, x2 - 1);
}

void amaliat(char* a, char* b2, char* b1, int i) {
	long long int x1, x2, s = 0;
	x1 = atoi(b1);
	x2 = atoi(b2);
	if (a[0] == '+') x1 = x1 + x2;
	if (a[0] == '-') x1 = x1 - x2;
	if (a[0] == '*') x1 = x1 * x2;
	if (a[0] == '/') x1 = x1 / x2;
	if (a[0] == '^') x1 = tavan(x1, x2);
	char t[20];
	if (x1 > 0) {
		int p = 0;
		for (; x1 != 0; p++) {
			t[p] = (x1 % 10) + 48;
			x1 /= 10;
		}
		rev(t, p - 1);
		t[p] = '\0';
		strcpy(a, t);
	}
	else if (x1 == 0) {
		a[0] = '0';
		a[1] = '\0';
	}
	else {
		int y = (-x1);
		int p = 0;
		for (; y != 0; p++) {
			t[p] = (y % 10) + 48;
			y /= 10;
		}
		t[p] = '\0';
		rev(t, p - 1);
		for (int d = p; d >= 0; d--) {
			t[d + 1] = t[d];
		}
		t[0] = '-';
		strcpy(a, t);
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------
void postfix(char** a, int n) {
	int i = 0;
	while (1) {
		for (i = 0; (a[i][0] != '+' && a[i][0] != '-' && a[i][0] != '*' && a[i][0] != '/' && a[i][0] != '^') || a[i][1] != '\0'; i++);
		amaliat(a[i], a[i - 1], a[i - 2], i);
		for (int r = i; r < n; r++) {
			strcpy(a[r - 2], a[r]);
		}
		n -= 2;
		if (n == 1) {
			printf("%s", a[0]);
			exit(0);
		}
	}
}
//--------------------------------------------------------------------------------------------------------------------------------
void prefix(char** a, int n) {
	int i = n - 1;
	while (1) {
		for (i = n - 1; ((a[i][0] != '+' && a[i][0] != '-' && a[i][0] != '*' && a[i][0] != '/' && a[i][0] != '^') || (a[i][1] != '\0')); i--);
		amaliat(a[i], a[i + 2], a[i + 1], i);
		int r = i + 1;
		for (; r < n; r++) {
				strcpy(a[r], a[r + 2]);
		}
		n -= 2;
		if (n == 1) {
			printf("%s", a[0]);
			exit(0);
		}
	}
}


//--------------------------------------------------------------------------------------------------------------------------------
int main() {
	char s[8];
	scanf("%s", s);
	int i = 0, j = 0, counter = 0;
	char p[1000];
	getchar();
	scanf("%[^\n]s", p);
	int cf = 0;
	while (i < strlen(p)) {
		if (p[i] == ' ') {
			cf++;
		}
		i++;
	}
	char** a = (char**)malloc((cf + 3) * sizeof(char*));
	for (int r = 0; r < cf + 3; r++) {
		a[r] = (char*)malloc(20 * sizeof(char));
	}
	for (i = 0; p[counter] != ' ' && counter <= strlen(p); i++) {
		for (j = 0; p[counter] != ' ' && counter <= strlen(p); j++) {
			a[i][j] = p[counter];
			counter++;
		}
		if (p[counter] != '\n')
			counter++;
		a[i][j] = '\0';
	}
	a[i][0] = a[i + 1][0] = '\0';
	if (strcmp("postfix", s) == 0)postfix(a, i);
	if (strcmp("prefix", s) == 0)prefix(a, i);
	free(a);
}