#include <iostream>
#include <cstdlib>

#include "soldier.h"

using namespace std;

void printSoldierState(Soldier* soldier) {
	cout << "��������� ���: " << soldier->getTextMorale() << endl;
	cout << "������: " << soldier->getRank() << endl;
	cout << "���������: " << soldier->getTextStatus() << endl;
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
	Soldier* soldier = new Soldier("���������", "������������", "����", 1);
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


		cout << "\t\t������" << endl;
		cout << "���: " << soldier->getFullName() << endl;
		cout << "�����: " << soldier->getId() << endl;
		cout << "���������� �����: " << soldier->getVictoriesAmount() << endl;
		cout << "���������� ���������: " << soldier->getDefeatsAmount() << endl;
		printSoldierState(soldier);

		cout << "\t\t��������" << endl;
		cout << "1: �������� � ������" << endl;
		cout << "2: �������� � ������" << endl;
		cout << "3: �������� �������" << endl;
		cout << "4: �������� ������" << endl;
		cout << "5: ������������ � ���������" << endl;
		cout << "0: �����" << endl;
		
		cout << "��� �����: ";
		cin >> choose;

		system("cls");
		switch (choose) {
		case 1:

			if (soldier->raiseRank())
				cout << "���� ������� ��� �������!" << endl;
			else
				cout << "� ������� ��� ������������ ����!" << endl;
			break;
		case 2:
			if (soldier->lowerRank())
				cout << "���� ������� ��� �������!" << endl;
			else
				cout << "���� ������!" << endl;
			break;
		case 3:
			if (soldier->heal())
				cout << "������ ��� �������!" << endl;
			else
				cout << "������ ����." << endl;
			break;
		case 4:
			status = rand() % 3;

			cout << "������ ������� ������";
			if (status == 2)
			{
				cout << " � ������." << endl;
				soldier->doVictory(InRanks);
			}
			else if (status == 1)
			{
				cout << ", �� ��� �����." << endl;
				soldier->doVictory(Wounded);
			}
			else
			{
				cout << ", �� ����." << endl;
				soldier->doVictory(Dead);
			}

			break;
		case 5:
			status = rand() % 3;

			cout << "������ ����� ���������";
			if (status == 2)
			{
				cout << ", �� ������." << endl;
				soldier->doVictory(InRanks);
			}
			else if (status == 1)
			{
				cout << ", � ��� �����." << endl;
				soldier->doVictory(Wounded);
			}
			else
			{
				cout << " � ����." << endl;
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