#include "header.h"

Deck::Deck() {
	start = NULL;
	tail = NULL;
	count = 0;
}

void Deck::add(PokeMen data) {
	node* ptr = new node(data);

	if (!empty()) {
		ptr->next = start;
		start->prev = ptr;
		start = ptr;
	}
	else {
		start = ptr;
		tail = ptr;
	}
	count++;
}

void Deck::remove() {
	if (count > 0) {
		node* ptr = start;
		start = start->next;
		count--;
		delete ptr;
	}
	else {
		cout << endl << "[---------------------------------------] " << endl;
		cout << "| The PokeDeck is empty                 |" << endl;
		cout << "[---------------------------------------]" << endl << endl;
	}
}

void Deck::display(ostream& out) const {

	if (count == 0) {
		out << endl << "[---------------------------------------] " << endl;
		out << "| The Deck has no PokeMen               |" << endl;
		out << "[---------------------------------------]" << endl << endl;
	}
	else {
		int i = 0;
		for (node* ptr = start; ptr != NULL; ptr = ptr->next) {
			ptr->data.writeStats(cout);
			//out << "Health for object " << i << "is" << ptr->data.healthPoints << endl;
			//out << "Damage for object " << i << "is" << ptr->data.baseDamage<< endl;

			i++;
		}
	}
}

bool Deck::empty() const {

	return (count == 0);
}

int Deck::size() const {
	return count;
}

void Deck::del() {
	
	int temp = count;
	if (count == 0) {
		cout << endl << "[---------------------------------------] " << endl;
		cout << "| The PokeDeck is empty                 |" << endl;
		cout << "[---------------------------------------]" << endl << endl;
	}
	else {
		for (int i = 0; i <= temp; i++) {
			remove();
		}
	}
}