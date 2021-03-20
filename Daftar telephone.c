#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

struct contacts {
	char name[31];
	char num[10];
	struct contacts* next;
};

void copy_of_file(struct contacts** head) {
	FILE* a = fopen("database.txt", "r");
	if (a == NULL) {
		printf("Unable to open the file\n");
		return;
	}
	*head = (struct contacts*)calloc(1, sizeof(struct contacts));
	struct contacts* tail = (struct contacts*)calloc(1, sizeof(struct contacts));
	struct contacts* z = (struct contacts*)calloc(1, sizeof(struct contacts));

	fgets((*head)->name, 31, a);
	(*head)->name[strlen((*head)->name) - 1] = '\0';
	fgets((*head)->num, 10, a);
	(*head)->num[strlen((*head)->num) - 1] = '\0';
	if ((*head)->name[0] == '\0') {
		(*head) = NULL;
		tail = NULL;
		return;
	}

	(*head)->next = tail;
	z = (*head);

	while (z->name[0] != '\0') {
		fgets(tail->name, 31, a);
		tail->name[strlen(tail->name) - 1] = '\0';
		if (tail->name[0] == '\0') {
			break;
		}
		fgets(tail->num, 10, a);
		tail->num[strlen(tail->num) - 1] = '\0';
		z = (struct contacts*)calloc(1, sizeof(struct contacts));
		z = tail;
		tail = (struct contacts*)calloc(1, sizeof(struct contacts));
		z->next = tail;
	}
	z->next = NULL;
	fclose(a);
}

void fun1(struct contacts** head) {
	struct contacts* z = (struct contacts*)calloc(1, sizeof(struct contacts));
	z = (*head);
	char name[31], num[9];
	getchar();
	scanf("%[^\n]s", name);
	getchar();
	scanf("%[^\n]s", num);
	while (z != NULL) {
		if (strcmp(name, z->name) == 0) {
			strcpy(z->num, num);
			printf("Contact was saved\n");
			return;
		}
		z = z->next;
	}
	z = (*head);
	while (z->next != NULL) {
		z = z->next;
	}
	struct contacts* w = (struct contacts*)calloc(1, sizeof(struct contacts));
	z->next = w;
	strcpy(w->name, name);
	strcpy(w->num, num);
	w->next = NULL;
	printf("Contact was saved\n");
	return;
}

void fun2(struct contacts** head) {
	struct contacts* z = (struct contacts*)calloc(1, sizeof(struct contacts));
	z = (*head);
	char name[31];
	getchar();
	scanf("%[^\n]s", name);
	while (z != NULL) {
		if (strcmp(name, z->name) == 0) {
			printf("%s\n", z->num);
			return;
		}
		z = z->next;
	}
	printf("Unknown Contact\n");
}

void fun3(struct contacts** head) {
	struct contacts* z = (struct contacts*)calloc(1, sizeof(struct contacts));
	z = (*head);

	if ((*head) == NULL) {
		printf("No contact found\n");
	}

	while (z != NULL) {
		printf("%s %s\n", z->name, z->num);
		z = z->next;
	}
	
}

void fun4(struct contacts** head) {
	(*head) = NULL;
	printf("All contacts were deleted\n");
}

void copy_to_file(struct contacts** head) {
	FILE* a = fopen("database.txt", "w");
	while ((*head) != NULL) {
		fprintf(a, "%s\n%s\n", (*head)->name, (*head)->num);
		*head = (*head)->next;
	}
	fclose(a);
}

int main() {
	struct contacts* head = NULL;
	copy_of_file(&head);
	int n = 0;
	while (n != 5) {
		scanf("%d", &n);
		if (n == 1) {
			fun1(&head);
		}
		else if (n == 2) {
			fun2(&head);
		}
		else if (n == 3) {
			fun3(&head);
		}
		else if (n == 4) {
			fun4(&head);
		}
	}
	copy_to_file(&head);
}