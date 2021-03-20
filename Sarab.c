#include<stdio.h>

int main(void)
{
	int x;
	int y;
	scanf("%d%d", &x, &y);

	if (x - y == 0 || x - y == 2)
		printf("%d", (2 * x) - (x - y) - (x % 2));
	else puts("-1");	
}
