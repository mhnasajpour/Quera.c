#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	FILE* a;
	FILE* b;
	FILE* x ;
	a = fopen("input1.txt", "r");
	b = fopen("input2.txt", "r");
	x = fopen("output.txt", "w");
	char c1[1000][16] = { '\0' };
	char c2[1000][16] = { '\0' };
	int i = 0, j = 0;
	for (; c1[i - 1][0] != '\0' || i == 0; i++) {
		fscanf(a, "%s", c1[i]);
	}
	for (; c2[j - 1][0] != '\0' || j == 0; j++) {
		fscanf(b, "%s", c2[j]);
	}
	fclose(a);
	fclose(b);
	free(a);
	free(b);
	for (int z1 = 0; z1 < i - 1; z1++) {
		for (int z2 = 0; z2 < j - 1; z2++) {
			if (strcmp(c1[z1], c2[z2]) == 0) {
				fprintf(x, "%s\n", c1[z1]);
			}
		}
	}
	fclose(x);
}