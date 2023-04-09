#include "header.h"


//string search needs to be converted to template to handle all sorting 
void Deck::search(string searchingName) {
	int i = size();
	string temp;

	node* ptr;

	for (ptr = start; ptr != NULL; ptr = ptr->next) {
		
		temp = ptr->data.name;
		i++;
		if (temp == searchingName) {
			cout << "Object found at node #" << i << endl;
			break;
		}
		if (ptr->next == NULL)
		{
			cout << "Not found in deck" << endl;
			return;
		}
		
	}

	ptr->data.writeStats(cout);
}

