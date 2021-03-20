#include<stdio.h>
#include<math.h>
int main()
{
	int l = 4;
	int n;
	float result = 1;
	int x = -1;

	scanf("%d", &n);
	unsigned int counter = 1;
 
	if(n%2==1){
		while (counter <= n/2) {
			counter++;
			result = result + (l / pow(2, x = x + 2));
		}
	}
	else {
		while (counter <= n/2-1) {
			counter++;
			result = result + (l / pow(2, x = x + 2));
		}
		result = result + (l / pow(2, n - 2));
	}
	printf("%f", result);
}