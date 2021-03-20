#include<stdio.h>

int main() {
	int n;
	int counter;
	int sum = 0;
	scanf("%d", &n);
	for (counter = 1; counter < n; counter++) {
		if (n % counter == 0)
			sum += counter;
	}
	if (n == sum) printf("Yea babe");
	else printf("No my dear");
}