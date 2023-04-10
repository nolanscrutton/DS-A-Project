#include "header.h"


void printLogo(int sel);

int main(void) {

	Deck myDeck;
	char ch;
	int health, defense, damage;
	string name;
	srand((unsigned)time(NULL));
	printLogo(1);

	string waterPref[7] = { "moist", "wet", "viscous", "laminar", "gushy", "liquid", "gooey", };
	string firePref[7] = { "pyro", "fire", "solar", "magma", "lava", "plasma", "burner" };
	string brickPref[7] = { "rock", "brick", "granite", "sedimentary", "metamorphic", "cement", "dirt" };
	string suf[7] = { "man", "ball", "box", "beast", "dog", "rhino", "tree" };

	while(true) {
		cout <<endl << "Hit b to add a base to the deck" << endl;
		cout << "Hit m to add a moist to the deck" << endl;
		cout << "Hit t to add a thermal to the deck" << endl;
		cout << "his k to add a brick to the deck" << endl;

		cout << "Hit 2 to display the deck" << endl;
		cout << "Hit 3 to test base class" << endl;
		cout << "Hit r to remove a something for somewhere idk man" << endl;
		cout << "Hit c to count" << endl;
		cout << "Hit s to search" << endl;

		cin >> ch;

		if (ch == 'b') {
			/*
			cout << "input stats" << endl;
			cin >> name >>  health >> defense >> damage;
			PokeMen p(name, health, defense, damage);
			
			myDeck.add(p);
			*/
			PokeMen test4("Test4", 2, 10, 10);
			myDeck.add(test4);
			PokeMen test3("Test3", 3, 10, 10);
			myDeck.add(test3);
			PokeMen test2("Test2", 5, 10, 10);
			myDeck.add(test2);
			PokeMen test1("Test1", 10, 10, 10);
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

		if (ch == '2') {
			myDeck.display(cout);
		}

		if(ch == '3'){
			MoistType x("moist pokemon", 500, 10, 50);
			x.moistSpecial();
			x.writeStats(cout);
		}
		if (ch == 'c') {
			cout << "There are " << myDeck.size() << " PokeMen in your deck" << endl;
		}
		if (ch == 'd') {
			myDeck.del();
		}

		if (ch == 's') {
			string searchingName;

			cout << "Enter the name of the object you'd like to find" << endl;

			cin >> searchingName;
			myDeck.search(searchingName); 
		}
		if (ch == 'g')
		{
			myDeck.sort('1');
		}
		if (ch == 'v') {
			node* m;
			int seed1 = rand() % 3, seed2 = rand() % 7, seed3 = rand() % 7;
			int hp = rand() % 500, ds = rand() % 500, bd = rand() % 500;
			switch (seed1) {
			case 0:
			{
				name = waterPref[seed2] + suf[seed3];
				if (myDeck.search(name, 0) && !myDeck.empty()) {
					cout << "You've already captured " << name << endl;
					break;
				}
				MoistType t(name, hp, ds, bd);
				t.moistSpecial();
				myDeck.add(t);
				break;
			}
			case 1:
			{
				name = firePref[seed2] + suf[seed3];
				if (myDeck.search(name, 0) && !myDeck.empty()) {
					cout << "You've already captured " << name << endl;
						break;
				}
				ThermalType t(name, hp, ds, bd);
				t.thermalSpecial();
				myDeck.add(t);
				break;
			}
			case 2:
			{
				if (myDeck.search(name, 0) && !myDeck.empty()) {
					cout << "You've already captured " << name << endl;
						break;
				}
				name = brickPref[seed2] + suf[seed3];
				BrickType t(name, hp, ds, bd);
				t.brickSpecial(); 
				myDeck.add(t);
				break;
			}
			}
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