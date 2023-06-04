#include <iostream>
#include <map>

#include "soldier.h"
#include "fight_result.h"

using namespace std;

class Squad {
private:
	map<int, Soldier*> _soldiers;
	unsigned int _victories = 0;
	unsigned int _defeats = 0;

	int removeDeadSoldiers();
public:
	Squad() = default;

	int getSoldiersAmount();
	unsigned int getVictories();
	unsigned int getDefeats();

	void print();
	void printFormation();
	bool addSoldier(Soldier* soldier);
	bool removeSoldier(int id);
	FightResult goIntoBattle(int enemiesAmount);

	~Squad();
};