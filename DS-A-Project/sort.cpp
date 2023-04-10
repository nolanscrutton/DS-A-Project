#include "header.h"

void Deck::sort(char type) {
	if (type == ('h' | 'H')) {
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
	else if (type == ('d' | 'D')) {
		int i;
		node* ptr;
		node* p1;
		node* p2;

		for (i = 0; i < size(); i++)
		{
			p1 = start;
			p2 = p1->next;
			while (p1->next != NULL) {
				if (p1->data.baseDamage > p2->data.baseDamage) {
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
	else if (type == ('e' | 'E')) {
		int i;
		node* ptr;
		node* p1;
		node* p2;

		for (i = 0; i < size(); i++)
		{
			p1 = start;
			p2 = p1->next;
			while (p1->next != NULL) {
				if (p1->data.defenseStrength > p2->data.defenseStrength) {
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
	else if (type == ('n' | 'N')) {
		int i;
		node* ptr;
		node* p1;
		node* p2;

		for (i = 0; i < size(); i++)
		{
			p1 = start;
			p2 = p1->next;
			while (p1->next != NULL) {
				if (p1->data.name > p2->data.name) {
					swap(p1, p2);
					p2 = p1->next;
				}
				else {
					p1 = p2;
					p2 = p2->next;
				}
			}
		}
	}else{
		cout << endl << "[---------------------------------------] " << endl;
		cout << "| Invalid Type Entered!                 |" << endl;
		cout << "[---------------------------------------]" << endl << endl;
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





