/* Method Implementations*/

#include "header.h"

/* Implementation of Base Card methods*/
PokeMen::PokeMen(int health, int defenseValue, int baseDamageValue, int specialDamageValue) 
{
	healthPoints = health;
	defenseStrength = defenseValue;
	baseDamage= baseDamageValue;
	specialDamage = specialDamageValue;
}
void PokeMen::writeStats(ostream& out) {
	cout << " hp = " << healthPoints << "defenseValue = " << defenseStrength<< "base damage = " << baseDamage << "special damage = " << specialDamage << endl;
}
/* Implementation of special type methods*/