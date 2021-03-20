#include <stdio.h>

int main() {
	int x, y, x1, y1;
	scanf("%d", &x);

	if (x<=1000 && x>=-1000)
		scanf("%d", &y);

	if (y <= 1000 && y >= -1000)
		scanf("%d", &x1);

	if (x1 <= 1000 && x1 >= -1000)
		scanf("%d", &y1);

	if (y1 <= 1000 && y1 >= -1000)
		puts(x > x1 ? "Left" : "Right");		
}