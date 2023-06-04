#include "soldier.h"

#include <iostream>
#include <format>

using namespace std;

Soldier::Soldier(string _name, string _surname, string _patronymic, unsigned int _id)
{
	if (_name == "" && _name == " ")throw invalid_argument("Имя не задано");
	else if (_surname == "" && _surname == " ")throw invalid_argument("Фамилия не задана");
	else if (_patronymic == "" && _patronymic == " ")throw invalid_argument("Отчество не задано");

	this->_name = _name;
	this->_surname = _surname;
	this->_patronymic = _patronymic;
	this->_id = _id;

	_morale = Raised;
	_victories = 0;
	_defeats = 0;
	_rank = Private;
	_status = InRanks;
}

string Soldier::getFullName()
{
	return format("{} {} {}", _name, _surname, _patronymic);
}

string Soldier::getTextRank()
{
	switch (_rank)
	{
	case Private: return "Рядовой";
	case Sergeant: return "Сержант";
	case Lieutenant: return "Лейтенант";
	case Major: return "Майор";
	case Colonel: return "Полковник";
	}
}

string Soldier::getTextStatus()
{
	switch (_status)
	{
	case InRanks: return "В строю";
	case Wounded: return "Ранен";
	case Dead: return "Убит";
	}
}

string Soldier::getTextMorale() {
	switch (_morale)
	{
	case Adrenaline: return "Полон адреналина";
	case Inspired: return "Воодушевлен";
	case Raised: return "Приподнятое состояние";
	case Neutral: return "Нейтральный";
	case Drooping: return "Поникший";
	case Deserter: return "Близок в дезертирству";
	}
}

Morale Soldier::getMorale()
{
	return _morale;
}

Status Soldier::getStatus()
{
	return _status;
}

unsigned int Soldier::getId()
{
	return _id;
}

int Soldier::getVictoriesAmount()
{
	return _victories;
}

int Soldier::getDefeatsAmount()
{
	return _defeats;
}

bool Soldier::raiseRank()
{
	if (_rank == Colonel)return false;

	_rank = (Rank)(_rank + 1);

	if (_morale != Adrenaline)
		_morale = (Morale)(_morale + 1);

	return true;
}

bool Soldier::lowerRank()
{
	if (_rank == Private)return false;

	_rank = (Rank)(_rank - 1);

	if (_morale != Deserter)
		_morale = (Morale)(_morale - 1);

	return true;
}

void Soldier::doVictory(Status status)
{
	if (_status == Dead)return;

	raiseRank();

	if (status == InRanks && _status == Wounded)return;
	else if (status == InRanks) {
		int temp = Adrenaline - _morale;
		if (temp > 1) _morale = (Morale)(_morale + 2);
		else if (temp == 1) _morale = (Morale)(_morale + 1);
	}
	else if (status == Wounded) {
		if (_morale != Adrenaline)
			_morale = (Morale)(_morale + 1);
	}

	_status = status;
}

void Soldier::doDefeat(Status status)
{
	if (_status == Dead)return;

	lowerRank();

	if (status == InRanks && _status == Wounded)return;
	else if (status == InRanks) {
		if (_morale != Deserter)
			_morale = (Morale)(_morale - 1);
	}
	else if (status == Wounded) {
		if (_morale > 1) _morale = (Morale)(_morale - 2);
		else if (_morale == 1) _morale = (Morale)(_morale - 1);
	}

	_status = status;
}

bool Soldier::heal()
{
	if (_status == Dead) return false;
	else if (_morale != Adrenaline)
		_morale = (Morale)(_morale + 1);

	_status = InRanks;

	return true;
}
