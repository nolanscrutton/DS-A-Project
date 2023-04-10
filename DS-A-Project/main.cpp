#include "header.h"


void printLogo(int sel);

int main(void) {

	Deck myDeck;
	char ch;
	int health, defense, damage;
	string name;
	char sortType;

	printLogo(1);

	while(true) {
		cout << endl << "[---------------------------------------] " << endl;
		cout << "| Hit b to add a base to the deck       |" << endl;
		cout << "| Hit m to add a moist to the deck      |" << endl;
		cout << "| Hit t to add a thermal to the deck    |" << endl;
		cout << "| Hit k to add a brick to the deck      |" << endl;
		cout << "| Hit d to display the deck             |" << endl;
		cout << "| Hit 3 to test base class              |" << endl;
		cout << "| Hit r to remove a PokeMan             |" << endl;
		cout << "| Hit n for number of PokeMen in deck   |" << endl;
		cout << "| Hit s to search                       |" << endl;
		cout << "| Hit g to sort deck                    |" << endl;
		cout << "| Hit c to clear deck                   |" << endl;
		cout << "[---------------------------------------]" << endl << endl;

		cin >> ch;

		if (ch == 'b') {
			
			/*cout << "input stats" << endl;
			cin >> name >>  health >> defense >> damage;
			PokeMen p(name, health, defense, damage);
			

			myDeck.add(p);*/
			
			PokeMen test4("fargus", 1, 11, 6);
			myDeck.add(test4);
			PokeMen test3("dungus", 4, 5, 3);
			myDeck.add(test3);
			PokeMen test2("garbonzo", 7, 8, 12);
			myDeck.add(test2);
			PokeMen test1("zamn", 10, 2, 9);

			myDeck.add(test1);

		}
		if (ch == 'm') {
			cout << "stats" << endl;
			cin >> name >> health >> defense >> damage;
			MoistType p(name, health, defense, damage);

			p.moistSpecial();

			myDeck.add(p);
		}
		if (ch == 't') {
			cout << "stats" << endl;
			cin >> name >> health >> defense >> damage;
			ThermalType p(name, health, defense, damage);

			p.thermalSpecial();

			myDeck.add(p);
		}
		if (ch == 'k') {
			cout << "stats" << endl;
			cin >> name >> health >> defense >> damage;
			BrickType p(name, health, defense, damage);

			p.brickSpecial();

			myDeck.add(p);
		}

		if(ch == 'r') {
			if (myDeck.empty()) {
				cout << "list is empty" << endl;
			}
			else {
				myDeck.remove();
			}
		}

		if (ch == 'd') {
			myDeck.display(cout);
		}

		if(ch == '3'){
			MoistType x("moist pokemon", 500, 10, 50);
			x.moistSpecial();
			x.writeStats(cout);
		}
		if (ch == 'n') {
			cout << "There are " << myDeck.size() << " PokeMen in your deck" << endl;
		}
		if (ch == 'c') {
			myDeck.del();
		}

		if (ch == 's') {
			string searchingName;

			cout << "Enter the name of the object you'd like to find" << endl;
			cout << endl << "[---------------------------------------] " << endl;
			cout << "| Enter the name of the object you'd    |" << endl;
			cout << "| like to find                          |" << endl;
			cout << "[---------------------------------------]" << endl << endl;

			cin >> searchingName;
			
			myDeck.search(searchingName);
		}
		if (ch == 'g')
		{

			cout << endl << "[---------------------------------------] " << endl;
			cout << "| Choose a statistic to sort by:        |" << endl;
			cout << "| h = sort by health                    |" << endl;
			cout << "| e = sort by defense                   |" << endl;
			cout << "| d = sort by damage                    |" << endl;
			cout << "| n = sort by name                      |" << endl;
			cout << "[---------------------------------------]" << endl << endl;

			cin >> sortType;

			myDeck.sort(sortType);
		}
	}


	return 0;
}

//Prints the PokeMen logo in ascii art, logo selectable with input 1-10
void printLogo(int sel) {

	switch (sel) {
	case 1:
		cout << endl
			<< "      :::::::::   ::::::::  :::    ::: ::::::::::   :::   :::   :::::::::: ::::    :::" << endl
			<< "     :+:    :+:  :+:   :+: :+:   :+:  :+:         :+:+: :+:+:  :+:        :+:+:   :+:" << endl
			<< "    +:+    +:+ +:+    +:+ +:+  +:+   +:+        +:+ +:+:+ +:+ +:+        :+:+:+  +:+" << endl
			<< "   +#++:++#+  +#+    +:+ +#++:++    +#++:++#   +#+  +:+  +#+ +#++:++#   +#+ +:+ +#+" << endl
			<< "  +#+        +#+    +#+ +#+  +#+   +#+        +#+       +#+ +#+        +#+  +#+#+#" << endl
			<< " #+#        #+#    #+# #+#   #+#  #+#        #+#       #+# #+#        #+#   #+#+#" << endl
			<< "###         ########  ###    ### ########## ###       ### ########## ###    ####" << endl;
		break;
	case 2:
		cout << endl
			<< " ________  ________  ___  __    _______   _____ ______   _______   ________       " << endl
			<< "|\\   __  \\|\\   __  \\|\\  \\|\\  \\ |\\  ___ \\ |\\   _ \\  _   \\|\\  ___ \\ |\\   ___  \\     " << endl
			<< "\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\/  /|\\ \\   __/|\\ \\  \\\\\\__\\ \\  \\ \\   __/|\\ \\  \\\\ \\  \\    " << endl
			<< " \\ \\   ____\\ \\  \\\\\\  \\ \\   ___  \\ \\  \\_|/_\\ \\  \\\\|__| \\  \\ \\  \\_|/_\\ \\  \\\\ \\  \\   " << endl
			<< "  \\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\ \\  \\\\ \\  \\  " << endl
			<< "   \\ \\__\\    \\ \\_______\\ \\__\\\\ \\__\\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\ \\__\\\\ \\__\\ " << endl
			<< "    \\|__|     \\|_______|\\|__| \\|__|\\|_______|\\|__|     \\|__|\\|_______|\\|__| \\|__| " << endl;
		break;
	case 3:
		cout << endl
			<< "  ____       _        __  __            " << endl
			<< " |  _ \\ ___ | | _____|  \\/  | ___ _ __  " << endl
			<< " | |_) / _ \\| |/ / _ \\ |\\/| |/ _ \\ '_ \\ " << endl
			<< " |  __/ (_) |   <  __/ |  | |  __/ | | |" << endl
			<< " |_|   \\___/|_|\\_\\___|_|  |_|\\___|_| |_|" << endl;
		break;
	case 4:
		cout << endl
			<< "   ___       __       __  ___        " << endl
			<< "  / _ \\___  / /_____ /  |/  /__ ___  " << endl
			<< " / ___/ _ \\/  '_/ -_) /|_/ / -_) _ \\ " << endl
			<< "/_/   \\___/_/\\_\\\\__/_/  /_/\\__/_//_/ " << endl;
		break;
	case 5:
		cout << endl
			<< "$$$$$$$\\            $$\\                 $$\\      $$\\                     " << endl
			<< "$$  __$$\\           $$ |                $$$\\    $$$ |                    " << endl
			<< "$$ |  $$ | $$$$$$\\  $$ |  $$\\  $$$$$$\\  $$$$\\  $$$$ | $$$$$$\\  $$$$$$$\\  " << endl
			<< "$$$$$$$  |$$  __$$\\ $$ | $$  |$$  __$$\\ $$\\$$\\$$ $$ |$$  __$$\\ $$  __$$\\ " << endl
			<< "$$  ____/ $$ /  $$ |$$$$$$  / $$$$$$$$ |$$ \\$$$  $$ |$$$$$$$$ |$$ |  $$ |" << endl
			<< "$$ |      $$ |  $$ |$$  _$$<  $$   ____|$$ |\\$  /$$ |$$   ____|$$ |  $$ |" << endl
			<< "$$ |      \\$$$$$$  |$$ | \\$$\\ \\$$$$$$$\\ $$ | \\_/ $$ |\\$$$$$$$\\ $$ |  $$ |" << endl
			<< "\\__|       \\______/ \\__|  \\__| \\_______|\\__|     \\__| \\_______|\\__|  \\__|" << endl;
		break;
	case 6:
		cout << endl
			<< "______     _       ___  ___           " << endl
			<< "| ___ \\   | |      |  \\/  |           " << endl
			<< "| |_/ /__ | | _____| .  . | ___ _ __  " << endl
			<< "|  __/ _ \\| |/ / _ \\ |\\/| |/ _ \\ '_ \\ " << endl
			<< "| | | (_) |   <  __/ |  | |  __/ | | |" << endl
			<< "\\_|  \\___/|_|\\_\\___\\_|  |_/\\___|_| |_|" << endl;
		break;
	case 7:
		cout << endl
			<< "8888888b.          888               888b     d888                   " << endl
			<< "888   Y88b         888               8888b   d8888                   " << endl
			<< "888    888         888               88888b.d88888                   " << endl
			<< "888   d88P .d88b.  888  888  .d88b.  888Y88888P888  .d88b.  88888b.  " << endl
			<< "8888888P\" d88\"\"88b 888 .88P d8P  Y8b 888 Y888P 888 d8P  Y8b 888 \"88b " << endl
			<< "888       888  888 888888K  88888888 888  Y8P  888 88888888 888  888 " << endl
			<< "888       Y88..88P 888 \"88b Y8b.     888   \"   888 Y8b.     888  888 " << endl
			<< "888        \"Y88P\"  888  888  \"Y8888  888       888  \"Y8888  888  888 " << endl;
		break;
	case 8:
		cout << endl
			<< "________      ______      ______  ___            " << endl
			<< "___  __ \\________  /_________   |/  /___________ " << endl
			<< "__  /_/ /  __ \\_  //_/  _ \\_  /|_/ /_  _ \\_  __ \\" << endl
			<< "_  ____// /_/ /  ,<  /  __/  /  / / /  __/  / / /" << endl
			<< "/_/     \\____//_/|_| \\___//_/  /_/  \\___//_/ /_/ " << endl;
		break;
	case 9:
		cout << endl
			<< "   _ \\         |            \\  |              " << endl
			<< "  |   |  _ \\   |  /   _ \\  |\\/ |   _ \\  __ \\  " << endl
			<< "  ___/  (   |    <    __/  |   |   __/  |   | " << endl
			<< " _|    \\___/  _|\\_\\ \\___| _|  _| \\___| _|  _| " << endl;
		break;
	case 10:
		cout << endl
			<< " ______      _           _______             " << endl
			<< "(_____ \\    | |         (_______)            " << endl
			<< " _____) )__ | |  _ _____ _  _  _ _____ ____  " << endl
			<< "|  ____/ _ \\| |_/ ) ___ | ||_|| | ___ |  _ \\ " << endl
			<< "| |   | |_| |  _ (| ____| |   | | ____| | | |" << endl
			<< "|_|    \\___/|_| \\_)_____)_|   |_|_____)_| |_|" << endl;
		break;
	default:
		cout << endl
			<< "   ___       __       __  ___        " << endl
			<< "  / _ \\___  / /_____ /  |/  /__ ___  " << endl
			<< " / ___/ _ \\/  '_/ -_) /|_/ / -_) _ \\ " << endl
			<< "/_/   \\___/_/\\_\\\\__/_/  /_/\\__/_//_/ " << endl;
	}

	cout << endl << "Developed by Cameron A., Nader H., Owen K., Nolan S., and Wyatt S." << endl << endl << endl;
}