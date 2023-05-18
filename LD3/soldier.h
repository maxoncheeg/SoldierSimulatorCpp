#pragma once

#include <iostream>

#include "rank.h"
#include "status.h"
#include "morale.h"

using namespace std;

class Soldier {
private:
	string _name;
	string _surname;
	string _patronymic;
	int _victories;
	int _defeats;
	unsigned int _id;
	Morale _morale;
	Rank _rank;
	Status _status;
public:
	Soldier(string, string, string, unsigned int);
	string getFullName();
	string getRank();
	string getTextStatus();
	string getTextMorale();
	Morale getMorale();
	Status getStatus();
	unsigned int getId();
	int getVictoriesAmount();
	int getDefeatsAmount();
	bool raiseRank();
	bool lowerRank();
	void doVictory(Status);
	void doDefeat(Status);
	bool heal();
};