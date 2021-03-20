#include<stdio.h>
#pragma warning(disable:4996)

void read(int a[10000], int n) {
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
}

int min1(int a[10000],int n, int i) {
	for (int t = i+1; t <= n+1; t++)
		if (a[t] < a[i]) 
			return (t-1);
	return (n);
}

int min2(int a[10000], int i) {
	for (int t = i-1; t >= 0; t--)
		if (a[t] < a[i]) 
			return (t+1);
	return (1);
}

void check(int a[10000], int n) {
	int x, y, u;
	int max=a[0];
	int i = 0;
	for (; i < n; i++) {
		x = min1(a, n, i);
		y = min2(a, i);
		u= (x-y+1) * a[i];
		if (u > max)
			max = u;
	}
	printf("%d", max);
}

int main() {
	int a[10000] = {};
	int n;
	scanf("%d", &n);
	read(a, n);
	check(a, n);
}