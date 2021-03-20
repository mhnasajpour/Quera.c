#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct information {
	char name[20];
	char family_name[30];
	char age[4];
	char national_code[11];
	char father_name[20];
	char phone_num[12];
	char address[150];
	struct information* next;
};

void input(struct information** head, struct information** tail) {
	FILE* a;
	a = fopen("input.txt", "r");

	fscanf(a, "%[^\n]s", (*head)->name);
	fgetc(a);
	fscanf(a, "%[^\n]s", (*head)->family_name);
	fgetc(a);
	fscanf(a, "%s", (*head)->age);
	fscanf(a, "%s", (*head)->national_code);
	fgetc(a);
	fscanf(a, "%[^\n]s", (*head)->father_name);
	fscanf(a, "%s", (*head)->phone_num);
	fscanf(a, "%s", (*head)->address);
	(*head)->next = (*tail);
	struct information* z;
	z = (struct information*)calloc(1, sizeof(struct information));

	for (int i = 1; 1; i++) {
		fgetc(a);
		fscanf(a, "%[^\n]s", (*tail)->name);
		fgetc(a);
		if ((*tail)->name[0] == '\0') {
			(*tail)->next = NULL;
			break;
		}
		fscanf(a, "%[^\n]s", (*tail)->family_name);
		fgetc(a);
		fscanf(a, "%s", (*tail)->age);
		fscanf(a, "%s", (*tail)->national_code);
		fgetc(a);
		fscanf(a, "%[^\n]s", (*tail)->father_name);
		fscanf(a, "%s", (*tail)->phone_num);
		fscanf(a, "%s", (*tail)->address);
		(*tail)->next = z;
		(*tail) = (*tail)->next;
		z = (struct information*)calloc(1, sizeof(struct information));
	}
	fclose(a);
	*tail = (*head);
	while ((*tail)->next->next != NULL) {
		*tail = (*tail)->next;
	}
	(*tail)->next = NULL;
}

void output(struct information** head) {
	struct information* current;
	current = (struct information*)malloc(sizeof(struct information));
	current = (*head);

	FILE* a;
	a = fopen("output.txt", "w");
	fprintf(a, "%-20s  %-30s  %-4s  %-11s  %-20s  %-12s  %-150s\n\n", "name", "family name", "age", "code melli", "father name", "phone num", "address");
	while (current != NULL) {
		fprintf(a, "%-20s  %-30s  %-4s  %-11s  %-20s  %-12s  %-150s\n", current->name, current->family_name, current->age, current->national_code, current->father_name, current->phone_num, current->address);
		current = current->next;
	}
	fclose(a);
}

void swap(struct information** a, struct information** b) {
	char name[20];
	char family_name[30];
	char age[4];
	char national_code[11];
	char father_name[20];
	char phone_num[12];
	char address[150];

	strcpy(name, (*a)->name);
	strcpy(family_name, (*a)->family_name);
	strcpy(age, (*a)->age);
	strcpy(national_code, (*a)->national_code);
	strcpy(father_name, (*a)->father_name);
	strcpy(phone_num, (*a)->phone_num);
	strcpy(address, (*a)->address);

	strcpy((*a)->name, (*b)->name);
	strcpy((*a)->family_name, (*b)->family_name);
	strcpy((*a)->age, (*b)->age);
	strcpy((*a)->national_code, (*b)->national_code);
	strcpy((*a)->father_name, (*b)->father_name);
	strcpy((*a)->phone_num, (*b)->phone_num);
	strcpy((*a)->address, (*b)->address);

	strcpy((*b)->name, name);
	strcpy((*b)->family_name, family_name);
	strcpy((*b)->age, age);
	strcpy((*b)->national_code, national_code);
	strcpy((*b)->father_name, father_name);
	strcpy((*b)->phone_num, phone_num);
	strcpy((*b)->address, address);
}


void sort(struct information** head) {
	struct information* current1;
	struct information* current2;
	current1 = (struct information*)malloc(sizeof(struct information));
	current2 = (struct information*)malloc(sizeof(struct information));
	current1 = current2 = (*head);
	for (; current1 != NULL; current1 = current1->next) {
		for (current2 = current1; current2 != NULL; current2 = current2->next) {
			if (strcmp(current1->name, current2->name) == 1) {
				swap(&current1, &current2);
			}
			else if (strcmp(current1->name, current2->name) == 0 && strcmp(current1->family_name, current2->family_name) == 1) {
				swap(&current1, &current2);
			}
			else if (strcmp(current1->name, current2->name) == 0 && strcmp(current1->family_name, current2->family_name) == 0 && strcmp(current1->father_name, current2->father_name) == 1) {
				swap(&current1, &current2);
			}
		}
	}
}


int main() {
	struct information* head;
	struct information* tail;
	head = (struct information*)calloc(1, sizeof(struct information));
	tail = (struct information*)calloc(1, sizeof(struct information));

	head->next = tail->next = NULL;

	input(&head, &tail);
	sort(&head);
	output(&head);
}