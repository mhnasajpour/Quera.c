#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int islower(char a) {
	if (a >= 65 && a <= 90)return 0;
	else  return 1;
}
void rev(char a[100][100],int i,int j) {
	char temp[1000];
	strcpy(temp, a[j]);
	for (int p = j; p > i; p--)
		strcpy(a[p], a[p - 1]);
	strcpy(a[i], temp);
}

int main() {
	char a[100][100];
	int t = 0;
	for (; a[t - 1][0] != '0'; t++) {
		scanf("%s", a[t]);
	}
	for (int i = 0; i < t - 2; i++) {
		for (int j = i + 1; j < t - 1; j++) {

			if (islower(a[j][0]) == 0 && islower(a[i][0]) != 0) {
				if (a[i][0] >= a[j][0] + 32) rev(a, i, j);
			}
			

			else if (islower(a[j][0]) != 0 && islower(a[i][0]) == 0) {
				if (a[i][0] + 32 > a[j][0]) rev(a, i, j);
			}
			

			else {
				if (a[i][0] > a[j][0]) 
					rev(a, i, j);
				if (a[i][0] == a[j][0]) {
					if (a[i][1] > a[j][1]) {
						rev(a, i, j);
					}
				}
			}
		}
	}
	for (int y = 0; y < t - 1; y++) {
		printf("%s ", a[y]);
	}
}