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
	if (count == 1) {
		delete tail;
		start = tail = NULL;
		count--;
	}
	else {
		node* ptr = tail->prev;
		ptr->next = NULL;
		delete tail;
		tail = ptr;
		count--;
	}
}

void Deck::display(ostream& out) const {

	if (count == 0) {
		out << "The Deck has no PokeMen" << endl;
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

void Deck::sort(int type) {

}

void Deck::del() {
	for (int i = 0; i <= size(); i++) {
		remove();
	}

	cout << "All Pokemen have been successfully removed from the Deck." << endl;
}