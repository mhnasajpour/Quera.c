#include<stdio.h>
#include<math.h>

int main() {
	int d1, m1, d2, m2, c1, c2;
	scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
	m1--;
	m2--;
	if (m1 <= 6) {
		c1 = (m1 * 31) + d1;
	}
	if (m2 <= 6) {
		c2 = (m2 * 31) + d2;
	}
	if (m1 > 6) {
		c1 = 186 + ((m1 - 6) * 30) + d1;
	}
	if (m2 > 6) {
		c2 = 186 + ((m2 - 6) * 30) + d2;
	}
	printf("%d", abs(c2 - c1));
}