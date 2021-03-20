#include<stdio.h>
#pragma warning(disable:4996)

void read(int a[100],int n) {
	for (int i = 1; i <= n; i++)
	scanf("%d", &a[i]);
}

void check(int a[100], int n) {
	int max = 0;
	for(int i=1;i<=n;i++)
		for (int j = i; j <= n; j++) {
			int sum = 0;
			int counter;
			for (counter = i; counter <= j; counter++)
				sum += a[counter];
			if (sum > max)
				max = sum;
		}
	printf("%d", max);
}

int main() {
	int a[100];
	int n;
	scanf("%d", &n);
	read(a,n);
	check(a, n);
}