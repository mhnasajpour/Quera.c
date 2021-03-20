#include<stdio.h>
#include<math.h>

int main()
{
	int a;
	int b = 2;
	scanf("%d", &a);
	while (b <= a)
		b = b * 2;
	printf("%d", b);
}