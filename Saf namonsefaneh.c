#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct information {
	int a;
	struct information* next;
};

void add_to_end(struct information** head, struct information** tail) {
	struct information* w;
	w = *head;
	*head = (*head)->next;
	w->next = NULL;
	(*tail)->next = w;
	*tail = (*tail)->next;
}

void add_to_start(struct information** head, struct information** temp, struct information** z) {
	*temp = (*temp)->next->next;
	struct information* t = (struct information*)malloc(sizeof(struct information));
	t->a = (*z) -> a;
	t->next = (*head);
	(*head) = (t);
}

int main() {
	struct information* head = NULL;
	struct information* temp = NULL;
	struct information* tail = NULL;
	struct information* z = NULL;
	int tedad, dastour;
	scanf("%d %d", &tedad, &dastour);
	
	for (int i = 0; i < tedad; i++) {

		if (head == NULL) {
			temp = (struct information*)malloc(sizeof(struct information));
			temp->next = NULL;
			temp->a = i + 1;
			head = temp;
			continue;
		}
		

		z = (struct information*)malloc(sizeof(struct information));
		temp->next = z;
		temp = temp->next;
		temp->a = i + 1;
		temp->next = NULL;
	}
	tail = temp;

	int x;
	temp = head;
	for (int i = 0; i < dastour; i++) {
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", head->a);
			add_to_end(&head,&tail);
		}
		else {
			while (1) {
				if (temp->a == x) {
					break;
				}
				else if (temp->next->a == x) {
					z = temp->next;
					add_to_start(&head, &temp, &z);
					break;
				}
				temp = temp->next;
			}
		}
		temp = head;
	}
}