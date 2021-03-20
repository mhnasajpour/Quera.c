#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct information {
	char harf;
	int tedad;
	char result[20];
};

void sort(struct information* b, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (b[i].tedad > b[j].tedad) {
				struct information temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
}

void alphabetical(struct information* s, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (s[i].harf > s[j].harf) {
				struct information temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

void fun(struct information* c, int num, int x) {
	sort(c, num);
	for (int i = 0; i < num; i++) {
		do {
			char w[20];
			strcpy(w, "0");
			strcat(w, c[i].result);
			strcpy(c[i].result, w);
			i++;
		} while ((c[i].tedad == c[0].tedad));
		int n = c[i - 1].tedad;
		int j = i;

		if (j == num) {
			c[i - 1].result[0] = '1';
		}
		else do {
			char w[20];
			strcpy(w, "1");
			strcat(w, c[i].result);
			strcpy(c[i].result, w);
			i++;
		} while ((c[i].tedad == c[j].tedad));
		n += c[i - 1].tedad;

		for (int g = i - 1; g >= 0; g--) {
			c[g].tedad = n;
		}
		if (c[num - 1].tedad == c[0].tedad && c[num - 1].tedad > x) {
			alphabetical(c, num);
			for (int i = 0; i < num; i++) {
				printf("%c: %s\n", c[i].harf, c[i].result);
			}
			exit(0);
		}
		sort(c, num);
		fun(c, num, x);
	}
}

int main() {
	int num;
	scanf("%d", &num);

	struct information* a = (struct information*)malloc(sizeof(struct information) * num);
	getchar();
	for (int i = 0; i < num; i++) {
		scanf("%c", &a[i].harf);
		getchar();
		scanf("%d", &a[i].tedad);
		getchar();
		a[i].result[0] = '\0';
	}
	int x = a[num - 1].tedad;
	fun(a, num, x);
}