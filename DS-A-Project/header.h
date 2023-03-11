#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class PokeMen 
{
private:
	int healthPoints;
	int defenseStrength;
	int baseDamage;
	int specialDamage;
public:
	
	PokeMen(int healthPoints, int defenseStrength, int baseDamage, int specialDamage);
	void attack(PokeMen& attackedTarget, int baseDamage);
	void writeStats(ostream& out);

};

class ThermalType
{
public:
	ThermalType();
	~ThermalType();

private:

};
