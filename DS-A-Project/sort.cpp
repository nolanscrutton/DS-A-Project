#include "header.h"

void Deck::sort(char type) {

	int i, j;
	node* ptr;
	node* p1;
	node* p2;

	for (i = 0; i < size(); i++)
	{
		ptr = start;
		for (j = 0; j < size()-1; j++)
		{
			p1 = ptr;
			if (p1->next == NULL)
			{
				break;
			}
			p2 = ptr->next;

			if (p1->data.healthPoints > p2->data.healthPoints)
			{
				swap(p1, p2);
				ptr = p1->next;
			}
			else {
				ptr = p2->next;
			}
			if (ptr==NULL)
			{
				break;
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

	ptr2->prev = ptr1->prev;
	ptr1->prev = ptr2;

	ptr2->next = ptr1;
	ptr1->next = temp;
	
}





