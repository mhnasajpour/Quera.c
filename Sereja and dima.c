#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void hazf_aval(int* a, int n) {
	for (int t = 0; t < n; t++) {
		a[t] = a[t + 1];
	}
	a = (int*)realloc(a, (n - 1) * sizeof(int*));

}

void hazf_akhar(int* a, int n) {
	a = (int*)realloc(a,(n-1)*sizeof(int*));
}

int main() {
	int n, sum1 = 0, sum2 = 0;
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int counter = n;
	for (int k = 0; k < counter; k++) {
		if (k % 2 == 0) {
			if (a[0] < a[n - 1]) {
				sum1 += a[n - 1];
				hazf_akhar(a,n);
			}
			else {
				sum1 += a[0];
				hazf_aval(a,n);
			}
		}
		//**********************************
		else {
			if (a[0] < a[n - 1]) {
				sum2 += a[n - 1];
				hazf_akhar(a, n);
			}
			else {
				sum2 += a[0];
				hazf_aval(a, n);
			}
		}
		n--;
	}
	printf("%d %d", sum1, sum2);
}