#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

void check(char a[3][1000]) {
	for (int i = 0; a[0][i] != '\0'; i+=5) {
		char b[6] = { a[0][i],a[0][i + 1],a[0][i + 2],a[0][i + 3],a[0][i + 4],'\0' };
		if (strcmp(b, "*****") == 0)
			printf("T");
		else if (strcmp(b, "oo*oo") == 0)
			printf("A");
		else if (strcmp(b, "**o**") == 0)
			printf("M");
		else if (strcmp(b, "*ooo*") == 0) {
			if(a[1][i]=='o')
				printf("X");
			else 
				printf("N");
		}
	}
}

int main() {
	char a[3][1000];

	for (int i = 0; i < 3; i++)
		scanf("%s", a[i]);

	check(a);
}