#include<stdio.h>

void a(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", i * j);
		}
		puts("");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	a(n);
}