#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996);

typedef struct adad {
	long long int data;
	struct adad* next;
}adad;
//----------------------------------------------------------------------------
void push(adad** head, adad** tail) {

	long long int m;
	scanf("%lld", &m);

	adad* z;
	z = (adad*)malloc(sizeof(adad));
	z->data = m;
	z->next = NULL;

	if ((*head) == NULL) {
		*head = (adad*)malloc(sizeof(adad));
		*tail = (adad*)malloc(sizeof(adad));
		(*head)->next = NULL;
		(*tail)->next = NULL;

		(*head)->data = m;
		(*head)->next = NULL;
		*tail = *head;
	}
	else if ((*head)->next == NULL) {
		(*head)->next = z;
		(*tail) = z;
	}
	else {
		(*tail)->next = z;
		*tail = (*tail)->next;
	}
}
//---------------------------------------------------------------------------------
void pop(adad** head) {

	if (*head == NULL) {
		printf("ERROR0\n");
		return;
	}
	else if ((*head)->next == NULL) {
		printf("%lld\n", (*head)->data);
		*head = NULL;
		return;
	}

	printf("%lld\n", (*head)->data);

	*head = (*head)->next;
	return;
}
//-------------------------------------------------------------------------------
void mohtava(adad** head) {
	long long int m;
	scanf("%lld", &m);
	if ((*head) == NULL) {
		printf("ERROR1\n");
		return;
	}
	adad* current;
	current = (adad*)malloc(sizeof(adad));
	current = (*head);
	for (int i = 1; i < m; i++) {
		if (current->next == NULL) {
			printf("ERROR1\n");
			return;
		}
		current = current->next;
	}
	printf("%lld\n",current->data);
}
//----------------------------------------------------------------------------------
void meghdar(adad** head) {
	long long int m;
	scanf("%lld", &m);
	adad* current;
	long int i = 0;
	current = (adad*)malloc(sizeof(adad));
	current = (*head);
	while (current != NULL) {
		i++;
		if (current->data == m) {
			printf("%ld\n", i);
			return;
		}
		current = current->next;
	}
	printf("ERROR2\n");
}
//------------------------------------------------------------------------------------
void fun5(adad** head) {
	long long int m;
	scanf("%lld", &m);
	adad* current;
	current = (adad*)malloc(sizeof(adad));
	current = (*head);
	for (long int i = 1; (i < m - 1) && (current->next != NULL); i++) {
		current = current->next;
	}
	if (current->next != NULL) {
		current->next = current->next->next;
	}
	else {
		printf("ERROR3\n");
	}
}

//------------------------------------------------------------------------------------
void fun6(adad** head) {
	long long int m;
	scanf("%lld", &m);
	adad* current;
	current = (adad*)malloc(sizeof(adad));
	current = (*head);
	long int i = 1;

	if (current->data == m) {
		(*head) = (*head)->next;
		return;
	}

	while(current->next != NULL) {
		if (m == current->next->data) {
			current->next = current->next->next;
			return;
		}
		current = current->next;
	}

	if (current->next == NULL) {
		printf("ERROR4\n");
		return;
	}
}
//--------------------------------------------------------------------------------------
int main() {
	adad* head = NULL;
	adad* tail = NULL;
	
	int n = 0;
	while (n != 7) {
		scanf("%d", &n);
		if (n == 1) {
			push(&head, &tail);
		}
		else if (n == 2) {
			pop(&head);
		}
		else if (n == 3) {
			mohtava(&head);
		}
		else if (n == 4) {
			meghdar(&head);
		}
		else if (n == 5) {
			fun5(&head);
		}
		else if (n == 6) {
			fun6(&head);
		}
	}
}
