#include<stdio.h>

int main()
{
	int n;
	int a, counter, m, y;
	scanf("%d", &n);
	if (n >= 1 && n <= 1000) {
		for (a = 2; a < n; a++) {
			for (counter = 2; counter < a; counter++) {
				if (a % counter == 0)
					break;
			}
			if (counter == a) {
				y = a;
				while (y != 0) {
					m = y % 10;
					y /= 10;
					if (m == 0 || m == 1 || m == 4 || m == 6 || m == 8 || m == 9)
						break;
					else if (y == 0)
						printf("%d ", a);
				}
			}
		}
	}
}