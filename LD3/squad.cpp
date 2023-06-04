#include "squad.h"

int Squad::getSoldiersAmount()
{
	return _soldiers.size();
}

unsigned int Squad::getVictories()
{
	return _victories;
}

unsigned int Squad::getDefeats()
{
	return _defeats;
}

void Squad::print()
{
	for (pair<int, Soldier*> pair : _soldiers)
		cout << "Cîëäàò " << pair.second->getId()
		<< " | "
		<< pair.second->getTextRank() << " " << pair.second->getFullName() << endl;
}

void Squad::printFormation()
{
	int maxMorale = Adrenaline * _soldiers.size(),
		currentMorale = 0;

	for (pair<int, Soldier*> pair : _soldiers)
		currentMorale += pair.second->getMorale();

	cout << endl << endl;
	if (currentMorale > maxMorale / 1.5) {
		cout << "    __    __" << endl;
		cout << "   _/\\_  _/\\_\t ÏÎÑÒÐÎÅÍÈÅ:" << endl;
		cout << "  _love__love_\t ËÞÁÎÂÜ ÏÎËÊÎÂÍÈÊÓ" << endl;
		cout << "    _soldier_" << endl;
		cout << "      _\\/_" << endl;
		cout << "       __" << endl;
	}
	else if (currentMorale > maxMorale / 3) {
		cout << " ||||||||| " << endl;
		cout << " ||||||||| \t ÏÎÑÒÐÎÅÍÈÅ:" << endl;
		cout << " ||||||||| \t ÎÁÛÊÍÎÂÅÍÍÎÅ" << endl;
		cout << " ||||||||| " << endl;
		cout << " ||||||||| " << endl;
		cout << " ||||||||| " << endl;
	}
	else {
		cout << "\\    /  " << endl;
		cout << " \\  /\t ÏÎÑÒÐÎÅÍÈÅ:" << endl;
		cout << "  \\/\t ÑÒÐÀÕ ÁÈÒÂÛ" << endl;
		cout << "  /\\" << endl;
		cout << " /  \\ " << endl;
		cout << "/    \\" << endl;
	}

	cout << endl;
}

bool Squad::addSoldier(Soldier* addingSoldier)
{
	for (pair<int, Soldier*> pair : _soldiers)
		if (pair.first == addingSoldier->getId())
			return false;

	_soldiers.insert(make_pair(addingSoldier->getId(), addingSoldier));
	return true;
}

bool Squad::removeSoldier(int id)
{
	if (_soldiers.contains(id)) {
		delete _soldiers.at(id);
		_soldiers.erase(id);

		return true;
	}

	return false;
}

int Squad::removeDeadSoldiers()
{
	int counter = 0;

	for (map<int, Soldier*>::iterator i = _soldiers.begin(); i != _soldiers.cend();)
		if (i->second->getStatus() == Dead) {
			delete i->second;
			i = _soldiers.erase(i);

			counter++;
		}
		else i++;

	return counter;
}

FightResult Squad::goIntoBattle(int enemiesAmount)
{
	FightResult result;
	result.isVictory = (enemiesAmount == 0 ? 0 : rand() % enemiesAmount) < _soldiers.size();

	if (result.isVictory)_victories++;
	else _defeats++;

	for (pair<int, Soldier*> pair : _soldiers)
	{
		int deadChance = rand() % 20;

		if (deadChance > 14)
			result.isVictory ? pair.second->doVictory(InRanks) : pair.second->doDefeat(InRanks);
		else if (deadChance > 4)
		{
			result.isVictory ? pair.second->doVictory(Wounded) : pair.second->doDefeat(Wounded);
			result.woundedAmount++;
		}
		else {
			result.isVictory ? pair.second->doVictory(Dead) : pair.second->doDefeat(Dead);
			result.diedAmount++;
		}
	}

	removeDeadSoldiers();
	return result;
}

Squad::~Squad()
{
	for (map<int, Soldier*>::iterator i = _soldiers.begin(); i != _soldiers.cend();)
	{
		delete i->second;
		i = _soldiers.erase(i);
	}
}
