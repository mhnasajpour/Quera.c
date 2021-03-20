#include<stdio.h>

int main() {
	int a[4], i, s, t, a1, a2, a3, a4;
	a1 = a2 = a3 = a4 = 0;
	for (i = 0; i < 4; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; a[0] && a[1] && a[2] && a[3];i++) {
		s = i % 4;
		a[s]--;
		t = a[0];
		a[0] = a[1];
		a[1] = a[2];
		a[2] = a[3];
		a[3] = t;
		switch (s) {
		case 0:a1++; break;
		case 1:a2++; break;
		case 2:a3++; break;
		case 3:a4++; break;
		}
	}
	printf("%d %d %d %d", a1, a2, a3, a4);
	
}