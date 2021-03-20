//In the name of GOD
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void hazf(char a[20000][70], int j,int n) {
	for (; j < n; j++) {
		strcpy(a[j], a[j + 1]);
	}
}


int main() {
	char a[14000][70];
	int n, p, q, counter = 0;
	scanf("%d %d %d", &n, &p, &q);
	for (int i = 0; i < n; i++) {
		scanf("%s",a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strncmp(a[i], a[j], p) == 0) {
				counter = 0;
				for (int z = 0; z < q; z++) {
					if (a[i][strlen(a[i]) - z-1] != a[j][strlen(a[j]) - z-1])
						break;
					else
						counter++;
				}
				if (counter == q) {
					hazf(a, j, n);
					n--;
					j--;
				}
			}
		}
	}
	printf("%d", n);
}