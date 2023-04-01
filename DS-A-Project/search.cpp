#include "header.h"



void Deck::search(string searchingName) {
	int i = size();
	string temp;

	node* ptr;

	for (ptr = start; ptr != NULL; ptr = ptr->next) {
		
		temp = ptr->data.name;
		i++;
		if (temp.compare(searchingName) == 0) {
			cout << "Object found at node #" << size()-i << endl;
			break;
		}
		
	}

	ptr->data.writeStats(cout);

}