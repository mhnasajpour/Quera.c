#include<stdio.h>

int fac(int a) {
	if (a == 1 || a == 0)
		return 1;
	return a * fac(a - 1);
}
void khaiam(int n) {
	for (int t=1;t<=n; t++) {
		for (int i = 0; i < t; i++) {
			printf("%d ", fac(t - 1) / (fac(i) * fac(t - i - 1)));
		}
		printf("\n");
	}

}

int main() {
	int n;
	scanf("%d", &n);
	khaiam(n);
}