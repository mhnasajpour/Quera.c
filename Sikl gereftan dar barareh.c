#include <stdio.h>

#pragma warning(disable:4996)

int nomre1(int i) {
	if (i % 6 == 1 || i % 6 == 2) return 3;
	if (i % 6 == 3 || i % 6 == 4) return 1;
	if (i % 6 == 5 || i % 6 == 0) return 2;
}

int nomre2(int i) {
	if (i % 3 == 1) return 1;
	if (i % 3 == 2) return 2;
	if (i % 3 == 0) return 3;
}

int nomre3(int i) {
	if (i % 4 == 1|| i % 4 == 3) return 2;
	if (i % 4 == 2) return 1;
	if (i % 4 == 0) return 3;
}


int main() {
	int soalat, v1 = 0, v2 = 0, v3 = 0;
	char c;
	scanf("%d", &soalat);
	scanf("%c", &c);
	for (int i = 1; i <= soalat;i++) {
		scanf("%c", &c);
		int t = c;
		if (nomre1(i) == t-48)v1++;
		if (nomre2(i) == t-48)v2++;
		if (nomre3(i) == t-48)v3++;
	}
	int max = v1;
	if (v2 > max)max = v2;
	if (v3 > max)max = v3;
	printf("%d\n", max);
	if (max == v1)puts("keyvoon");
	if (max == v2)puts("nezam");
	if (max == v3)puts("shir farhad");
}