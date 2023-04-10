#include "header.h"


//string search needs to be converted to template to handle all sorting 
int Deck::search(string searchingName, bool print) {
	int i = size();
	string temp;

	node* ptr;

	for (ptr = start; ptr != NULL; ptr = ptr->next) {
		
		temp = ptr->data.name;
		i++;
		if (temp == searchingName) {
			//cout << "Object found at node #" << i << endl;
			if(print) ptr->data.writeStats(cout);
			break;
		}
		if (ptr->next == NULL)
		{
			if(print) cout << "Not found in deck" << endl;
			return 0;
		}
		
	}

	return 1;
}

