#include<stdio.h>
#include<string.h>

#pragma warning(disable:4996)

char a[1000];

int harf_alefba(int i){
	int u = a[i];
	if (u >= 65 && u <= 90) u -= 65;
	else u -= 97;
	return u;
}

int tekrar(int i) {
	int u = a[i];
	int counter = 0;
	for (int p = 0; p < strlen(a); p++)
		if (u == a[p] || u == a[p] - 32 || u == a[p] + 32)
			counter++;
	return counter;
}

int result(int harf_alefba, int tekrar,int i) {
	int u = a[i];
	char c;
	int y = (harf_alefba * tekrar + 1) % 26;
	if (u >= 65 && u <= 90) c = y + 65;
	else c = y + 97;
	return c;
}

int main() {
	char b[1000] = {};
	int i;
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i++)
		b[i] = result(harf_alefba(i), tekrar(i), i);
	printf("%s", b);
}