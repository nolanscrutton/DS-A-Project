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
	out <<"Name: " << name <<endl << "Health points: " << healthPoints << endl << "Defense value: " << defenseStrength << endl << "Base damage:" << baseDamage << endl << endl;
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
	}
	else {
		currenthealth += random_val;
		sethealth(currenthealth);
	}
}
