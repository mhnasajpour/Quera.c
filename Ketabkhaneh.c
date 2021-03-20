#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

struct book {
	char name[134];
	struct book* next;
};

void addright(struct book** current, struct book** b) {
	while ((*current)->next != NULL) {
		*current = (*current)->next;
	}
	(*current)->next = *b;
	(*b)->next = NULL;
}

void addleft(struct book** start, struct book** b) {
	(*b)->next = *start;
	(*start) = (*b);
}

void deleteleft(struct book** start, struct book** current) {
	(*current) = ((*current)->next);
	*start = *current;
}

int main() {
	int n;
	struct book* start;
	struct book* current;
	scanf("%d", &n);
	start = (struct book*)malloc(sizeof(struct book));
	getchar();
	fgets(start->name,134,stdin);
	start->next = NULL;
	current = start;

	for (int i = 1; i < n; i++) {
		while (current->next != NULL) {
			current = current->next;
		}
		struct book* temp = (struct book*)malloc(sizeof(struct book));
		fgets(temp->name,134,stdin);
		temp->next = NULL;
		current->next = temp;
	}

	current = start;
	char f[12];
	while (strcmp(f, "Exit") != 0) {
		struct book* b;
		b = (struct book*)malloc(sizeof(struct book));
		scanf("%s", f);
		if (strcmp(f, "AddRight") == 0) {
			getchar();
			fgets(b->name, 134, stdin);
			addright(&current, &b);
			n++;
		}
		else if (strcmp(f, "AddLeft") == 0) {
			getchar();
			fgets(b->name, 134, stdin);
			addleft(&start, &b);
			n++;
		}
		else if (strcmp(f, "DeleteLeft") == 0) {
			deleteleft(&start, &current);
			n--;
		}
		current = start;
	}
	printf("%d\n", n);
	while (current != NULL) {
		printf("%s", current->name);
		current = current->next;
	}
}