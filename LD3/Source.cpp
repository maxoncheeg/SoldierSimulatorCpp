#include <iostream>
#include <cstdlib>

#include "soldier.h"

using namespace std;

void printSoldierState(Soldier* soldier) {
	cout << "Моральный дух: " << soldier->getTextMorale() << endl;
	cout << "Звание: " << soldier->getRank() << endl;
	cout << "Состояние: " << soldier->getTextStatus() << endl;
}

string getSoldierSmile(Morale morale) {
	switch (morale)
	{
	case Deserter: return "/--";
	case Drooping: return " ~~";
	case Neutral: return " __";
	case Raised: return "\\__";
	case Inspired: return "\\\\_";
	case Adrenaline: return " \\O";
	}
}

int main() {
	setlocale(0, "Rus");

	srand(time(NULL));
	Soldier* soldier = new Soldier("Настоящая", "Американская", "Жаба", 1);
	int choose = 0, status;

	do {
		cout << "\t    __________" << endl;
		cout << "\t   /          \\" << endl;
		cout << "\t  /            \\" << endl;
		cout << "\t  |    ________/" << endl;
		cout << "\t  \\___/   o  |" << endl;
		cout << "\t    |         >" << endl;
		cout << "\t    \\   " << getSoldierSmile(soldier->getMorale()) << "  | " << endl;
		cout << "\t     \\______/" << endl << endl;


		cout << "\t\tСОЛДАТ" << endl;
		cout << "Имя: " << soldier->getFullName() << endl;
		cout << "Номер: " << soldier->getId() << endl;
		cout << "Количество побед: " << soldier->getVictoriesAmount() << endl;
		cout << "Количество поражений: " << soldier->getDefeatsAmount() << endl;
		printSoldierState(soldier);

		cout << "\t\tДЕЙСТВИЯ" << endl;
		cout << "1: Повысить в звании" << endl;
		cout << "2: Понизить в звании" << endl;
		cout << "3: Вылечить солдата" << endl;
		cout << "4: Одержать победу" << endl;
		cout << "5: Учавствовать в поражении" << endl;
		cout << "0: Выйти" << endl;
		
		cout << "Ваш выбор: ";
		cin >> choose;

		system("cls");
		switch (choose) {
		case 1:

			if (soldier->raiseRank())
				cout << "Ранг солдата был повышен!" << endl;
			else
				cout << "У солдата уже максимальный ранг!" << endl;
			break;
		case 2:
			if (soldier->lowerRank())
				cout << "Ранг солдата был понижен!" << endl;
			else
				cout << "Ниже некуда!" << endl;
			break;
		case 3:
			if (soldier->heal())
				cout << "Солдат был вылечен!" << endl;
			else
				cout << "Солдат мёртв." << endl;
			break;
		case 4:
			status = rand() % 3;

			cout << "Солдат одержал победу";
			if (status == 2)
			{
				cout << " и уцелел." << endl;
				soldier->doVictory(InRanks);
			}
			else if (status == 1)
			{
				cout << ", но был ранен." << endl;
				soldier->doVictory(Wounded);
			}
			else
			{
				cout << ", но умер." << endl;
				soldier->doVictory(Dead);
			}

			break;
		case 5:
			status = rand() % 3;

			cout << "Солдат понес поражение";
			if (status == 2)
			{
				cout << ", но уцелел." << endl;
				soldier->doVictory(InRanks);
			}
			else if (status == 1)
			{
				cout << ", и был ранен." << endl;
				soldier->doVictory(Wounded);
			}
			else
			{
				cout << " и умер." << endl;
				soldier->doVictory(Dead);
			}
			break;
		default:
			break;
		}


	} while (soldier->getStatus() != Dead || choose == 0);

	delete soldier;

	return EXIT_SUCCESS;
}