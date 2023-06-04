#include <iostream>
#include <cstdlib>
#include <Windows.h>

#include "soldier.h"
#include "squad.h"

using namespace std;

int main() {

	setlocale(0, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Squad squad;
	int choice = 0, enemiesAmount = 0, id = 0;
	bool isExit = false;

	string name, surname, patronymic;

	do
	{
		cout << "\t������������ �����" << endl;
		cout << "���-�� ������� � ������: " << squad.getSoldiersAmount() << endl;

		if (squad.getSoldiersAmount() != 0)
			squad.printFormation();

		cout << endl << "��������: " << endl;
		cout << " 1 - �������� ���� �����." << endl;
		cout << " 2 - ���������� �����." << endl;
		cout << " 3 - ���������� ���������." << endl;
		cout << " 4 - ����� � ���." << endl;
		cout << " 5 - �������� �������." << endl;
		cout << " 6 - ��������� �������." << endl;
		cout << " 0 - �����." << endl;

		cout << "��� �����: ";
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1:
			cout << "�����:" << endl;
			squad.print();
			break;
		case 2:
			cout << "���-�� �����: " << squad.getVictories() << endl;
			break;
		case 3:
			cout << "���-�� ���������: " << squad.getDefeats() << endl;
			break;
		case 4:
		{
			cout << "���������� �����������: ";
			cin >> enemiesAmount;
			if (enemiesAmount < 0) enemiesAmount = 0;

			cout << "������� � ���: " << endl;

			FightResult result = squad.goIntoBattle(enemiesAmount);
			cout << "���������: " << (result.isVictory ? "������" : "���������") << endl;
			cout << "������ � ������: " << result.woundedAmount << endl;
			cout << "������� � ������: " << result.diedAmount << endl;
		}
		break;
		case 5:
		{
			cout << "���: ";
			cin >> name;

			cout << "�������: ";
			cin >> surname;

			cout << "��������: ";
			cin >> patronymic;

			cout << "���������� �����: ";
			cin >> id;
			if (id < 0) id = 0;

			bool res = false;
			try {
				res = squad.addSoldier(new Soldier(name, surname, patronymic, id));
			}
			catch (invalid_argument exception) {
				cout << exception.what() << endl;
			}

			if (res)
				cout << "C����� ������� ��������" << endl;
			else
				cout << "C����� �� ��� ��������" << endl;
			break;
		}
		case 6:
			cout << "������� ���������� �����: ";
			cin >> id;

			if (squad.removeSoldier(id))
				cout << "C����� ������� ������" << endl;
			else
				cout << "C����� �� ��� ������" << endl;
			break;
		case 0:
			isExit = true;
			break;
		default:
			break;
		}
	} while (!isExit);

	return EXIT_SUCCESS;
}