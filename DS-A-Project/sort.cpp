#include "header.h"

void Deck::sort(char type) {

	int i;
	node* ptr;
	node* p1;
	node* p2;

	for (i = 0; i < size(); i++)
	{
		p1 = start;
		p2 = p1->next;
		while (p1->next != NULL) {
			if (p1->data.healthPoints > p2->data.healthPoints) {
				swap(p1, p2);
				p2 = p1->next;
			}
			else {
				p1 = p2;
				p2 = p2->next;
			}
		}
	}
}

void Deck::swap(node* ptr1, node* ptr2) {
	if (ptr1 == start)
	{
		start = ptr2;
	}

	node* temp = ptr2->next;
	node* temp1 = ptr1->prev;

	ptr2->prev = ptr1->prev;
	ptr1->prev = ptr2;

	ptr2->next = ptr1;
	ptr1->next = temp;
	
	if (temp != NULL) temp->prev = ptr1;
	if (temp1 != NULL) temp1->next = ptr2;
}





