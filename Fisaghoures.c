#include<stdio.h>

int main() {
	int a;
	int b;
	int c;
	scanf("%d%d%d", &a, &b, &c);

	if (a * a == b * b + c * c) 
		puts("YES");
	else if (b * b == a * a + c * c)
		puts("YES");
	else if (c * c == b * b + a * a)
		puts("YES");
	else
		puts("NO");
}