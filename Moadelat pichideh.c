#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)

void result(long long int y, long long int x) {
	if (x == 0) {
		printf("invalid\n");
		return;
	}
	else if (y == 0) {
		printf("0 1");
		return;
	}
	else if (y > 0 && x > 0) {
		long long int z1 = x, z2 = y;
		while (z1 != 0 && z2 != 0) {
			if (z1 >= z2) {
				z1 %= z2;
			}
			else if (z2 > z1) {
				z2 %= z1;
			}
		}
		if (z1 == 0) {
			printf("%lld %lld", y / z2, x / z2);
			return;
		}
		else if (z2 == 0) {
			printf("%lld %lld", y / z1, x / z1);
			return;
		}
	}
	else if (y < 0 && x < 0) {
		long long int z1 = -x, z2 = -y;
		while (z1 != 0 && z2 != 0) {
			if (z1 >= z2) {
				z1 %= z2;
			}
			else if (z2 > z1) {
				z2 %= z1;
			}
		}
		if (z1 == 0) {
			printf("%lld %lld", (-y) / z2, (-x) / z2);
			return;
		}
		else if (z2 == 0) {
			printf("%lld %lld", (-y) / z1, (-x) / z1);
			return;
		}
	}
	else if (x < 0) {
		long long int z1 = -x, z2 = y;
		while (z1 != 0 && z2 != 0) {
			if (z1 >= z2) {
				z1 %= z2;
			}
			else if (z2 > z1) {
				z2 %= z1;
			}
		}
		if (z1 == 0) {
			printf("%lld %lld", (-y) / z2, (-x) / z2);
			return;
		}
		else if (z2 == 0) {
			printf("%lld %lld", (-y) / z1, (-x) / z1);
			return;
		}
	}
	else if (y < 0) {
		long long int z1 = x, z2 = -y;
		while (z1 != 0 && z2 != 0) {
			if (z1 >= z2) {
				z1 %= z2;
			}
			else if (z2 > z1) {
				z2 %= z1;
			}
		}
		if (z1 == 0) {
			printf("%lld %lld", y / z2, x / z2);
			return;
		}
		else if (z2 == 0) {
			printf("%lld %lld", y / z1, x / z1);
			return;
		}
	}

}

int main() {
	int equival;
	long long int n, x = 0, y = 0;
	scanf("%lld", &n);
	char* string = (char*)malloc(sizeof(char) * n);
	char a[1000][20];
	scanf("%s", string);
	int counter = 0;
	int i = 0;


	for (; counter < n; i++) {
		int j = 0;
		if (string[counter] == '=') {
			a[i][0] = string[counter];
			a[i][1] = '\0';
			equival = i;
			counter++;
			continue;
		}
		if (string[counter] == '+' || string[counter] == '-') {
			a[i][j] = string[counter];
			j++;
			counter++;
		}
		for (; string[counter] != '=' && string[counter] != '+' && string[counter] != '-' && counter < n; j++, counter++) {
			a[i][j] = string[counter];
		}
		a[i][j] = '\0';
	}



	for (int r = 0; r < i; r++) {
		if (a[r][strlen(a[r]) - 1] == 'x') {
			if ((a[r][0] == '+' && a[r][1] == 'x') || a[r][0] == 'x') {
				strcpy(a[r], "+1x");
			}
			else if (a[r][0] == '-' && a[r][1] == 'x') {
				strcpy(a[r], "-1x");
			}
			if (r < equival) {
				x += atoi(a[r]);
			}

			else if (r > equival) {
				x -= atoi(a[r]);
			}
		}
		//*****************************************************************
		else {
			if (r > equival) {
				y += atoi(a[r]);
			}

			else if (r < equival) {
				y -= atoi(a[r]);
			}

		}

	}
	result(y, x);
}