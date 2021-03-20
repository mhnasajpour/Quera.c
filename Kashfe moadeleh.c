#include <stdio.h>
#include<math.h>

int m1(double x, double y) {
	double x1 = x - floor(x);
	if (fabs(y-x1)<=0.2)
		return 1;
	return 0;
}
int m2(double x, double y) {
	double x2 = x * x + x;
	if (fabs(y - x2)<=0.2)
		return 1;
	return 0;
}
int m3(double x, double y) {
	double x3 = fabs(-x * x * x + 1) + x * x * x;
	if (fabs(y -x3 )<=0.2)
		return 1;
	return 0;
}

int main() {
	float x, y;
	int num, sum1 = 0,sum2 = 0, sum3 = 0;
	scanf("%d", &num);
		for (int counter = 1; counter <= num; counter++) {
			scanf("%f%f",&x,&y);
			if (m1(x,y))
				sum1++;
			if (m2(x,y))
				sum2++;
			if (m3(x,y))
				sum3++;
		}
		if (sum1 == num)
			printf("1\n");
		if (sum2 == num)
			printf("2\n");
		if (sum3 == num)
			printf("3\n");
		if (sum1 != num && sum2 != num && sum3 != num)
			puts("No ones");
}