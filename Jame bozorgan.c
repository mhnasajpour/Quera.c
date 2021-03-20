#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void) {
	char a[100], b[100], c;
	scanf("%s %c %s",a, &c, b);
	if (c == '*') {
		for (int i = 0; i < strlen(b); i++) {
			b[i] = b[i + 1];
		}		
		printf("%s", strcat(a, b));
	}

	if (c == '+') {
		if (strlen(b) == strlen(a)) {
			a[0] = '2';
			printf("%s", a);
		}
		else if (strlen(b) < strlen(a)) {
			a[strlen(a) - strlen(b)] = '1';
			printf("%s", a);
		}
		else {
			b[strlen(b) - strlen(a)] = '1';
			printf("%s", b);
		}
	}
}