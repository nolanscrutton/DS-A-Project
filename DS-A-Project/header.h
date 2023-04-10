#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <string>
#include <ctime>

using namespace std;

class PokeMen
{
friend class Deck;
private:
	int healthPoints;
	int defenseStrength;
	int baseDamage;
	string name;

public:
	
	PokeMen(string name = "", int healthPoints = 0, int defenseStrength = 0, int baseDamage = 0);
	void attack(PokeMen& attackedTarget, int baseDamage);
	void writeStats(ostream& out);
	int gethealth(void);
	int getdefense(void);
	int getdamage(void);
	void sethealth(int val);
	void setdefense(int val);
	void setdamage(int val);
};

class ThermalType : public PokeMen
{
private:
	
public:
	ThermalType(string name, int hp, int ds, int bd);
	void thermalSpecial(void);
};


class MoistType : public PokeMen
{
private:

public:
	MoistType(string name, int hp, int ds, int bd);
	void moistSpecial(void);
};


class BrickType : public PokeMen
{
private:

public:
	BrickType(string name, int hp, int ds, int bd);
	void brickSpecial(void);
};

class node {
friend class Deck;
friend class PokeStack;
private:
	PokeMen data;
	node* next;
	node* prev;
public:
	node(PokeMen data);
};

class Deck
{
private:
	node* start;
	node* tail;
	int count;

public:
	Deck();
	void add(PokeMen data);
	void remove(bool print = 1);
	void display(ostream& out) const;
	bool empty() const;
	int size(void) const;
	void sort(char type);
	void del();
	int search(string searchingName, bool print = 1);
	void swap(node* ptr1, node* ptr2);
};