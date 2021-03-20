#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	char joz[3000];
	char kol[1000];
	char f[3000];
	int counter;
	scanf("%s", joz);
	scanf("%s", kol);
	strcpy(f, joz);
	while (strlen(joz) < 3000)
		strcat(joz, f);
	joz[2999] = '\0';
	if (strstr(joz, kol) == NULL)
		puts("No");
	else puts("Yes");
}