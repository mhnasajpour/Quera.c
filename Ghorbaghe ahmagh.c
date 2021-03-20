#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

char a[1000][1000][10];
static int i = 0, j = 0, energy = 0;
int n, m;

void read(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%s", a[i][j]);
		}
	}
}
//**************************************************************************************************
int int_energy(char g[20]) {
	for (int i = 0; i < strlen(g) - 1; i++) {
		g[i] = g[i + 2];
	}
	g[strlen(g) + 3] = '\0';
	return atoi(g);
}
//********************************************************************************************************
int jahesh(char a[1000][1000][10]) {
	char g[10];
	strcpy(g, a[i][j]);
	char k[5], r[5];
	int d = 0;
	for (; g[d + 2] != ','; d++) {
		k[d] = g[d + 2];
	}
	d++;
	for (int t = 0; d < strlen(g); d++, t++) {
		r[t] = g[d + 2];
	}
	if (atoi(k) > n-1 || atoi(r) > m-1|| atoi(r) < 0|| atoi(k) < 0) {
		printf("Impossible place!\n");
		return 0;
	}
	i = atoi(k);
	j = atoi(r);
	printf("Jump to (%d,%d)\n", i, j);
	if (a[i][j][0] == 'J') {
		jahesh(a);
		return 1;
	}
	if (a[i][j][0] == 'C') {
		printf("Frog hunted by crocodile :-/! Energy %d!\n", energy);
		exit(0);
	}
	if (a[i][j][0] == 'E') {
		char g[20];
		strcpy(g, a[i][j]);
		energy += int_energy(g);
		if (energy <= 0) {
			printf("Frog died! Energy %d!\n", energy);
			exit(0);
		}
		else
			printf("Energy %d!\n", energy);
	}
	return 1;
}
//***************************************************************************************************
void harekat_aval() {
	if (a[0][0][0] == 'C') {
		printf("Frog hunted by crocodile :-/! Energy %d!\n", energy);
		exit(0);
	}

	if (a[0][0][0] == 'E') {
		char g[20];
		strcpy(g, a[0][0]);
		energy += int_energy(g);
		if (energy <= 0) {
			printf("Frog died! Energy %d!\n", energy);
			exit(0);
		}
		else
			printf("Energy %d!\n", energy);
	}

	if (a[0][0][0] == 'J') {
		if (jahesh(a) == 0) {
			i = 0;
			j = 0;
		}
	}

}
//****************************************************************************************************
void up() {

	if (i > 0) i--;
	else {
		printf("Impossible place!\n");
		return;
	}
	if (a[i][j][0] == 'C') {
		printf("Frog hunted by crocodile :-/! Energy %d!\n", energy);
		exit(0);
	}

	if (a[i][j][0] == 'E') {
		char g[20];
		strcpy(g, a[i][j]);
		energy += int_energy(g);
		if (energy <= 0) {
			printf("Frog died! Energy %d!\n", energy);
			exit(0);
		}
		else
			printf("Energy %d!\n", energy);
	}

	if (a[i][j][0] == 'J') {
		if (jahesh(a) == 0)i++;
	}

}
//*********************************************************************************************************
void down(int n) {

	if (i < n - 1) i++;
	else {
		printf("Impossible place!\n");
		return;
	}
	if (a[i][j][0] == 'C') {
		printf("Frog hunted by crocodile :-/! Energy %d!\n", energy);
		exit(0);
	}

	if (a[i][j][0] == 'E') {
		char g[20];
		strcpy(g, a[i][j]);
		energy += int_energy(g);
		if (energy <= 0) {
			printf("Frog died! Energy %d!\n", energy);
			exit(0);
		}
		else
			printf("Energy %d!\n", energy);
	}

	if (a[i][j][0] == 'J') {
		if (jahesh(a) == 0)i--;
	}

}
//*********************************************************************************************************
void right(int m) {

	if (j < m-1) j++;
	else {
		printf("Impossible place!\n");
		return;
	}
	if (a[i][j][0] == 'C') {
		printf("Frog hunted by crocodile :-/! Energy %d!\n", energy);
		exit(0);
	}

	if (a[i][j][0] == 'E') {
		char g[20];
		strcpy(g, a[i][j]);
		energy += int_energy(g);
		if (energy <= 0) {
			printf("Frog died! Energy %d!\n", energy);
			exit(0);
		}
		else
			printf("Energy %d!\n", energy);
	}

	if (a[i][j][0] == 'J') {
		if (jahesh(a) == 0)j--;
	}

}
//*********************************************************************************************************
void left() {

	if (j > 0) j--;
	else {
		printf("Impossible place!\n");
		return;
	}

	if (a[i][j][0] == 'C') {
		printf("Frog hunted by crocodile :-/! Energy %d!\n", energy);
		exit(0);
	}

	if (a[i][j][0] == 'E') {
		char g[20];
		strcpy(g, a[i][j]);
		energy += int_energy(g);
		if (energy <= 0) {
			printf("Frog died! Energy %d!\n", energy);
			exit(0);
		}
		else
			printf("Energy %d!\n", energy);
	}

	if (a[i][j][0] == 'J') {
		if (jahesh(a) == 0)j++;
	}
	
}
//*********************************************************************************************************

int main() {
	char k[20];
	char v;
	scanf("%d%c%d", &n, &v, &m);
	read(n, m);
	i = j = 0;
	harekat_aval();
	while (1) {
		scanf("%s", k);

		if (strcmp(k, "Up") == 0) up();
		if (strcmp(k, "Down") == 0) down(n);
		if (strcmp(k, "Left") == 0) left();
		if (strcmp(k, "Right") == 0) right(m);
		if (strcmp(k, "Finish") == 0) { 
			printf("Energy %d!", energy);
			break; 
		}
		if (strcmp(k, "Location") == 0) printf("Location (%d,%d)\n", i, j);
		if (energy < 0) {
			printf("Frog died! Energy %d!\n",energy);
			exit(0);
		}
	}
}