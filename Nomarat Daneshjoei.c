#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void change(int a, char b[10]) {
	int s = a;
	int j = 0;
	if (s == 0) {
		b[0] = '0';
		b[1] = '\0';
	}
	else {
		for (; s != 0; j++) {
			s /= 10;
		}
		for (int i = j - 1; i != -1; i--) {
			b[i] = (a % 10) + 48;
			a /= 10;
		}
		b[j] = '\0';
	}
}

void bin(char nomreh[][6],int t,char counter1[10]) {
	int counter = 0;
	int mabna = 1;
	for (int i = 0; i < strlen(nomreh[t]); i++) {
		counter += mabna * (nomreh[t][strlen(nomreh[t])-1-i]-48);
		mabna *= 2;
	}
	change(counter, counter1);
}
void hex(char nomreh[][6], int t, char counter1[10]) {
	int counter = 0;
	int mabna = 1;
	if (nomreh[t][0] == 'a' || nomreh[t][0] == 'A') counter= 10;
	else if (nomreh[t][0] == 'b' || nomreh[t][0] == 'B')counter = 11;
	else if (nomreh[t][0] == 'c' || nomreh[t][0] == 'C')counter = 12;
	else if (nomreh[t][0] == 'd' || nomreh[t][0] == 'D')counter = 13;
	else if (nomreh[t][0] == 'e' || nomreh[t][0] == 'E')counter = 14;
	else if (nomreh[t][0] == 'f' || nomreh[t][0] == 'F')counter = 15;
	else {
		for (int i = 0; i < strlen(nomreh[t]); i++) {
			counter += mabna * (nomreh[t][strlen(nomreh[t]) - 1 - i] - 48);
			mabna *= 16;
		}
	}
	change(counter, counter1);
}

void oct(char nomreh[][6],int t,char counter1[10]) {
	int counter = 0;
	int mabna = 1;
	for (int i = 0; i < strlen(nomreh[t]); i++) {
		counter += mabna * (nomreh[t][strlen(nomreh[t]) - 1 - i] - 48);
		mabna *= 8;
	}
	change(counter, counter1);
}

int main() {
	int c;
	char shomareh_daneshjoo[1000][10], a[1000][3];
	char nomreh[1000][6];
	char str[1000][4];
	char counter1[10];
	scanf("%d", &c);

	for (int t = 0; t < c; t++) {
		scanf("%s", shomareh_daneshjoo[t]);
		scanf("%s", a[t]);
		scanf("%s", str[t]);
		scanf("%s", nomreh[t]);
	}
	for (int t = 0; t < c; t++) {
		if (str[t][0] == 'B') {
			bin(nomreh, t, counter1);
			if ((strcmp(a[t], counter1) != 0)) 
				printf("%s\n", shomareh_daneshjoo[t]);
		}
		if (str[t][0] == 'H') {
			hex(nomreh, t, counter1);
			if ((strcmp(a[t], counter1) != 0))
				printf("%s\n", shomareh_daneshjoo[t]);
		}
		if (str[t][0] == 'O') {
			oct(nomreh, t, counter1);
			if ((strcmp(a[t], counter1) != 0))
				printf("%s\n", shomareh_daneshjoo[t]);
		}
	}
}