#include<stdio.h>
#include<math.h>

int main() {
	int x1, x2, x3, x4, x5;
	int y1, y2, y3, y4, y5;

	scanf("%d%d%d%d%d%d%d%d%d%d",&x1,&y1, &x2, &y2, &x3, &y3, &x4, &y4, &x5, &y5);
	if (x1 == x2 || x1 == x3 || x1 == x4 || x1 == x5 || x3 == x2 || x4 == x2 || x5 == x2 || x3 == x4 || x3 == x5 || x4 == x5)
		puts("Yes");
	else if (y1 == y2 || y1 == y3 || y1 == y4 || y1 == y5 || y3 == y2 || y4 == y2 || y5 == y2 || y3 == y4 || y3 == y5 || y4 == y5)
		puts("Yes");
	else if (abs(x1 - x2) == abs(y1 - y2))		puts("Yes");
	else if (abs(x3 - x2) == abs(y3 - y2))		puts("Yes");
	else if (abs(x1 - x3) == abs(y1 - y3))		puts("Yes");
	else if (abs(x1 - x4) == abs(y1 - y4))		puts("Yes");
	else if (abs(x1 - x5) == abs(y1 - y5))		puts("Yes");
	else if (abs(x4 - x2) == abs(y4 - y2))		puts("Yes");
	else if (abs(x5 - x2) == abs(y5 - y2))		puts("Yes");
	else if (abs(x3 - x4) == abs(y4 - y3))		puts("Yes");
	else if (abs(x3 - x5) == abs(y5 - y3))		puts("Yes");
	else if (abs(x4 - x5) == abs(y4 - y5))		puts("Yes");
	else puts("No");
}