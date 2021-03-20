#include<stdio.h>

void f1(int x, int n) {
	if (n == 0)puts("20");
}
void f2(int x, int n) {
	if (n != 0&& n != 7) {
		if (x - n >= 0)
			printf("%d", x - n);
		else
			puts("0");
	}
}
void f3(int x, int n) {
	if (n == 7)
		printf("%d", x);
}
int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	f1(x, n);
	f2(x, n);
	f3(x, n);
}