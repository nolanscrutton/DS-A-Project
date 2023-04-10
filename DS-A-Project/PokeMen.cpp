#include "header.h"

/*  Implementation of Base Card methods  */

PokeMen::PokeMen(string n, int health, int defenseValue, int baseDamageValue)
{
	healthPoints = health;
	defenseStrength = defenseValue;
	baseDamage = baseDamageValue;
	name = n;

}

void PokeMen::writeStats(ostream& out) {
	out << "Name: " << name << endl;

	out << endl << "[---------------------------------------] " << endl;

	if (healthPoints < 10) {
		out << "| Health points: " << healthPoints << "                      |" << endl;
	}else if (healthPoints < 100) {
		out << "| Health points: " << healthPoints << "                     |" << endl;
	}
	else if (healthPoints < 1000) {
		out << "| Health points: " << healthPoints << "                    |" << endl;
	}

	if (defenseStrength < 10) {
		out << "| Defense Value: " << defenseStrength << "                      |" << endl;
	}
	else if (defenseStrength < 100) {
		out << "| Defense Value: " << defenseStrength << "                     |" << endl;
	}
	else if (defenseStrength < 1000) {
		out << "| Defense Value: " << defenseStrength << "                    |" << endl;
	}

	if (baseDamage < 10) {
		out << "| Base damage  : " << baseDamage << "                      |" << endl;
	}
	else if (baseDamage < 100) {
		out << "| Base damage  : " << baseDamage << "                     |" << endl;
	}
	else if (baseDamage < 1000) {
		out << "| Base damage  : " << baseDamage << "                    |" << endl;
	}

	out << "[---------------------------------------]" << endl << endl;
}

void PokeMen::attack(PokeMen& attackedTarget, int baseDamage) {

}

int PokeMen::gethealth(void) {
	return healthPoints;
}

int PokeMen::getdamage(void) {
	return baseDamage;
}

int PokeMen::getdefense(void) {
	return defenseStrength;
}

void PokeMen::sethealth(int val) {
	healthPoints = val;
}

void PokeMen::setdefense(int val) {
	defenseStrength = val;
}

void PokeMen::setdamage(int val) {
	baseDamage = val;
}


/*  Implementation of special type methods  */

//moist type impementation

MoistType::MoistType(string n, int hp, int ds, int bd) : PokeMen(n,hp, ds, bd) {

}

void MoistType::moistSpecial(void) {
	int defense = getdefense();
	defense += 500;
	setdefense(defense);
}

//Thermal type implementation

ThermalType::ThermalType(string n, int hp, int ds, int bd) : PokeMen(n, hp, ds, bd) {

}

void ThermalType::thermalSpecial(void) {
	int damage = getdamage();
	damage += 50;
	setdamage(damage);
}

//Brick Type implementation

BrickType::BrickType(string n, int hp, int ds, int bd) : PokeMen(n, hp, ds, bd) {

}

void BrickType::brickSpecial(void) {
	int inc_or_dec = rand() % 2;
	int random_val = rand() % 150;
	int currenthealth = gethealth();

	if (inc_or_dec == 1) {
		currenthealth -= random_val;
		sethealth(currenthealth);
		if (currenthealth < 1) {
			currenthealth = 1;
		}
	}
	else {
		currenthealth += random_val;
		sethealth(currenthealth);
		if (currenthealth > 999) {
			currenthealth = 999;
		}
	}
}
