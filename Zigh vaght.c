#include<stdio.h>

int fibo(int a) {
	return (a >= 3) ? fibo(a - 2) + fibo(a - 1) : 1;
}

int main() {
	int a;
	scanf("%d", &a);
	printf("%d", fibo(a));
}