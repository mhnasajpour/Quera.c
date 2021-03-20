#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996);

typedef struct adad {
	long int data;
	struct adad* next;
}adad;
//----------------------------------------------------------------------------
void push(adad** head, adad** tail) {

	long int m;
	scanf("%ld", &m);

	adad* z;
	z = (adad*)malloc(sizeof(adad));
	z->data = m;
	z->next = NULL;

	if ((*head)->next == NULL) {
		(*head)->data = m;
		(*head)->next = z;
		*tail = *head;
	}
	else {
		(*tail)->next = z;
		*tail = (*tail)->next;
	}
}
//---------------------------------------------------------------------------------
void pop(adad** head, adad** tail) {

	if (*head == NULL) {
		printf("stack is empty\n");
		return;
	}
	else if (*head == (*tail)) {
		printf("%ld\n", (*tail)->data);
		*head = (*tail) = NULL;
		return;
	}

	adad* current;
	current = (adad*)malloc(sizeof(adad));
	current = *head;

	while (current->next->next != NULL) {
		current = current->next;
	}
	printf("%ld\n", (*tail)->data);
	current->next = NULL;
	*tail = current;
	return;
}
//-------------------------------------------------------------------------------
void max(adad** tail) {
	if (*tail == NULL) {
		printf("stack is empty\n");
		return;
	}
	printf("%ld\n", (*tail)->data);
}

int main() {
	adad* head = NULL;
	adad* tail = NULL;
	head = (adad*)malloc(sizeof(adad));
	tail = (adad*)malloc(sizeof(adad));
	head->next = NULL;
	tail->next = NULL;
	int n = 0, counter = 0;
	while (n != 4) {
		scanf("%d", &n);
		if (n == 1) {
			if (head == NULL) {
				counter = 0;
				head = (adad*)malloc(sizeof(adad));
				tail = (adad*)malloc(sizeof(adad));
				head->next = tail->next = NULL;
			}
			push(&head, &tail);
			counter = 1;
		}
		if (counter == 0) {
			printf("stack is empty\n");
			continue;
		}
		else if (n == 2) {
			pop(&head, &tail);
		}
		else if (n == 3) {
			max(&tail);
		}
	}
}