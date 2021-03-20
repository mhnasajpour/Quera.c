#include<stdio.h>
#include<math.h>

#ifdef _MSC_BUILD
#define scanf scanf_s
#endif
///////////////////////////////////////////////////////////////
int main() {
	int	a, x, i = 1, j = 1;
	scanf("%d", &a);
	if (a == 1)puts("#");
	else {
		for (j = 1; j <= a; j++, printf("#"));
		printf("\n");
		i++;
		//////////////////////////////////////////////////////////////
		for (i = 2; i < a / 2 + 1; i++) {

			printf("#");
			for (x = i; x - 2 > 0; x--) printf(" ");
			printf("#");
			x = i;
			int b = a - 2 * x;
			for (; b > 0; b--) printf(" ");
			for (x = i; x - 1 >= 0; x--) printf("#");
			printf("\n");
		}
		//////////////////////////////////////////////////////
		printf("#");
		i++;
		for (x = i; x - 2 > 1; x--) printf(" ");
		for (x = i; x > 1; x--)printf("#");
		i++;
		printf("\n");
		///////////////////////////////////////////////////////
		for (i = a / 2; i > 1; i--) {

			printf("#");
			for (x = i; x - 2 > 0; x--) printf(" ");
			printf("#");
			x = i;
			int b = a - 2 * x;
			for (; b > 0; b--) printf(" ");
			for (x = i; x - 1 >= 0; x--) printf("#");
			printf("\n");
		}
		/////////////////////////////////////////////////////////////
		for (j = 1; j <= a; j++, printf("#"));
	}

}