#include<stdio.h>

int main()
{
	float a, b, c, d, e;
	scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
	float sum = a + b + c + d + e;
	float prd = a * b * c * d * e;
	float avg = sum / 5;
	printf("SUM: %.2f\n", sum);
	printf("PRD: %.2f\n", prd);
	printf("AVG: %.2f", avg);
}