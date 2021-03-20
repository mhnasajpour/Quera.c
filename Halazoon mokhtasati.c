#include<stdio.h>

int main(){
	long int a;
	scanf("%ld", &a);
	if (a >= 1) {
		if (a % 4 == 0)
			printf("%d %d", -a / 4, a / 4);
		else if (a % 4 == 1)
			printf("%d %d", -a / 4, -a / 4);
		else if (a % 4 == 2)
			printf("%d %d", (a / 4) + 1, -a / 4);
		else if (a % 4 == 3)
			printf("%d %d", a / 4 + 1, a / 4 + 1);
	}
	return 0;
}