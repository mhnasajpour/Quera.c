#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct str {
	int age;
	float weight;
	char name[20];
	struct str* next;
};

void print(struct str* a) {
	puts("");
	while (a != NULL) {
		printf("%s\t%d\t%f\n", a->name, a->age, a->weight);
		a = a->next;
	}
	puts("");
}

void insert(struct str** current, struct str** start, int* counter) {
	(*counter)++;
	struct str* add = (struct str*)malloc(sizeof(struct str));
	int n;
	printf("jaye zakhireh sazi : ");
	scanf("%d", &n);
	if (n<0 || n>*counter) {
		printf("this index is not exist\n");
		(*counter)--;
		return;
	}
	printf("name : ");
	scanf("%s", add->name);
	getchar();
	printf("age : ");
	scanf("%d", &add->age);
	printf("weight : ");
	scanf("%f", &add->weight);
	
	if ((*counter) == 1) {
		(*start) = add;
		(*start)->next = NULL;
	}
	else if (n == 1) {
		add->next = *start;
		(*start) = add;
		*current = (*start);
	}
	else if (n == (*counter)) {
		while ((*current)->next != NULL) {
			*current = (*current)->next;
		}
		(*current)->next = add;
		add->next = NULL;
	}
	else {
		for (int i = 1; i < n-1; i++) {
			*current = (*current)->next;
		}
		add->next = (*current)->next;
		(*current)->next = add;
	}
	free(add);
	*current = *start;
	print(*current);
}

void _delete(struct str** start,struct str** current, int (*counter)) {
	int n;
	struct str* u = (struct str*)malloc(sizeof(struct str));
	printf("jaye zakhireh sazi : ");
	scanf("%d", &n);
	if (n<0 || n>(*counter)) {
		printf("error\n");
		return;
	}


	if (n == 1) {
		*current = (*current)->next;
		*start = *current;
	}
	else if (n == (*counter)) {
		for (int i = 1; i < (*counter); i++) {
			*current = ((*current)->next);
		}
		(*current)->next = NULL;
	}
	else {
		for (int i = 1; i < n-1; i++) {
			*current = (*current)->next;
		}
		u = (*current);
		*current = ((*current)->next);
		*current = ((*current)->next);
		u->next = *current;
		(*current) = (*start);
	}
	(*counter)--;
	free(u);
	print(*current);
}

void search(struct str* current) {
	char a[20];
	printf("what is his or her name : ");
	scanf("%s", a);
	for (int i = 1; current != NULL; i++) {
		if (strcmp(current->name, a)==0) {
			printf("%d\n", i);
			break;
		}
		current = current->next;
	}
	if (current->next == NULL) {
		printf("this name is not exist\n");
	}
}

void sort(struct str** start, struct str** current) {
	char name[20];
	int age;
	float weight;
	struct str* current1 = (struct str*)malloc(sizeof(struct str));
	current1 = *start;
	while ((*current) != NULL) {
		current1 = (*current);
		while (current1->next != NULL) {
			current1 = current1->next;
			if ((*current)->age < current1->age) {
				age = (*current)->age;
				weight = (*current)->weight;
				strcpy(name, (*current)->name);
				(*current)->age = current1->age;
				(*current)->weight= current1->weight;
				strcpy((*current)->name, (current1)->name);
				current1->age = age;
				current1->weight = weight;
				strcpy((current1)->name, name);
			}
			else if (((*current)->age == current1->age) && ((*current)->weight < current1->weight)) {
				age = (*current)->age;
				weight = (*current)->weight;
				strcpy(name, (*current)->name);
				(*current)->age = current1->age;
				(*current)->weight = current1->weight;
				strcpy((*current)->name, (current1)->name);
				current1->age = age;
				current1->weight = weight;
				strcpy((current1)->name, name);
			}
			else if (((*current)->age == current1->age) && ((*current)->weight == current1->weight) && (((*current)->age == current1->age)) && (strcmp((*current)->name, current1->name))==1) {
				age = (*current)->age;
				weight = (*current)->weight;
				strcpy(name, (*current)->name);
				(*current)->age = current1->age;
				(*current)->weight = current1->weight;
				strcpy((*current)->name, (current1)->name);
				current1->age = age;
				current1->weight = weight;
				strcpy((current1)->name, name);
			}
		}
		(*current) = (*current)->next;
	}
	free(current1);
	*current = (*start);
	print(*start);
}

int main() {
	struct str* start;
	struct str* current;
	char a[7];
	int counter = 0;
	start = (struct str*)malloc(sizeof(struct str));
	printf("1 : insert\n2 : delete\n3 : sort\n4 : search\n5 : finish\n\ninput : ");
	while (1) {
		scanf("%s", a);
		if (strcmp("insert", a) == 0) {
			insert(&current, &start, &counter);
		}
		else if (strcmp("delete", a) == 0) {
			_delete(&start, &current, &counter);
		}
		else if (strcmp("sort", a) == 0) {
			sort(&start, &current);
		}

		else if (strcmp("search", a) == 0) {
			search(current);
		}
		else if (strcmp("finish", a) == 0) {
			break;
		}
		current = start;
	}
	free(start);
	free(current);
}