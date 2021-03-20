#include <stdio.h>
#include<math.h>
int main()
{
	float a1, an, num, sum = 0;
	float max=pow(-10,5), min=pow(10,6), avg;
	scanf("%f", &num);

	for (int count = 1; count <= num; count++) {
		scanf("%f", &an);
		sum += an;

		if (an > max)
			max = an;
		if (an < min)
			min = an;
	}
	avg = sum / num;
	printf("Max: %.3f\n", max);
	printf("Min: %.3f\n", min);
	printf("Avg: %.3f", avg);
}