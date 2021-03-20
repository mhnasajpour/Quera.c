#include <stdio.h>

int main() {
	int a = 0, count, count1, n = 0, num, x;
	scanf("%d", &x);
	for (int y = 1; y <= x; y++) {
		scanf("%d", &num);
		n = 0;
		a = 0;
		for (count = 2; 1; count++) {

			for (count1 = 2; count1 <= count; count1++) {
				if (count % count1 == 0) break;
			}

			if (count1 == count) {
				a++;
				for (count1 = 2; count1 <= a; count1++) {
					if (a % count1 == 0) break;
				}
				if (count1 == a)
					n++;
				if (n == num) {
					printf("%d\n", count);
					break;
				}
			}
		}
	}
}