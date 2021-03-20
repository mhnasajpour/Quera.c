#include<stdio.h>
#include<math.h>

int bmm(int a, int b) {
	return b==0? a : bmm(b, a % b);
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	
	
	printf("%d", bmm(abs(a), abs(b)));
}