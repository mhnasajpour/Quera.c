#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	char a[4000];
	scanf("%[^\n]s", a);
	for (int z = 1; z < 26; z++) {
		if (strstr(a, "zozagtoor") != NULL) {
			break;
		}
		for (int i = 0; a[i] != '\0'; i++) {
			if (a[i] == ' ') {
				continue;
			}
			a[i] = (((a[i] - 97) + 1) % 26) + 97;
		}
	}
	printf("%s", a);
}