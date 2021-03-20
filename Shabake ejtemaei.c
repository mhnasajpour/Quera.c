#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct in {
	char username[1000];
	char id[1000];
	char gender[10];
	int age;

};

void fun(struct in in[150],int num){
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; j < num; j++) {
			if (strcmp(in[i].id, in[j].id) > 0) {
				struct in temp = in[i];
				in[i] = in[j];
				in[j] = temp;
			}
		}
	}
}

int main() {
	struct in in[150];
	int dastour, num = 0, adad = 1;
	char add_find[5], kalameh[1000];
	scanf("%d", &dastour);

	for (int i = 0; i < dastour; i++) {
		
		scanf("%s", add_find);
		
		if (strcmp(add_find, "Add") == 0) {
			scanf("%s %s %d %s", in[num].username, in[num].gender, &in[num].age, in[num].id);
			printf("User %s added successfully\n", in[num].id);
			fun(in, num);
			num++;
		}
		
		else if (strcmp(add_find, "Find") == 0) {
			scanf("%s", kalameh);
			int i = 0, l = 0;
			int j = 0, x = 0;
			for (; i < num; i++) {
				j = 0;
				for (; j < strlen(kalameh); j++) {
					if (kalameh[j] != in[i].id[j]) {
						break;
					}
				}
				if (j == strlen(kalameh) && l < 10) {
					printf("%d %s %s %d %s\n", adad, in[i].username, in[i].gender, in[i].age, in[i].id);
					l++;
					x = 1;
				}
			}
			if (i == num && x == 0) {
				printf("%d No user found\n", adad);
			}
			adad++;
		}
	}
}