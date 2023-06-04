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
		cout << "\tНЕСОКРУШИМЫЙ ОТРЯД" << endl;
		cout << "Кол-во человек в отряде: " << squad.getSoldiersAmount() << endl;

		if (squad.getSoldiersAmount() != 0)
			squad.printFormation();

		cout << endl << "Действия: " << endl;
		cout << " 1 - показать весь отряд." << endl;
		cout << " 2 - количество побед." << endl;
		cout << " 3 - количество поражений." << endl;
		cout << " 4 - пойти в бой." << endl;
		cout << " 5 - добавить солдата." << endl;
		cout << " 6 - исключить солдата." << endl;
		cout << " 0 - выход." << endl;

		cout << "Ваш выбор: ";
		cin >> choice;
		system("cls");

		switch (choice) {
		case 1:
			cout << "Отряд:" << endl;
			squad.print();
			break;
		case 2:
			cout << "Кол-во побед: " << squad.getVictories() << endl;
			break;
		case 3:
			cout << "Кол-во поражений: " << squad.getDefeats() << endl;
			break;
		case 4:
		{
			cout << "Количество противников: ";
			cin >> enemiesAmount;
			if (enemiesAmount < 0) enemiesAmount = 0;

			cout << "УЧАСТИЕ В БОЕ: " << endl;

			FightResult result = squad.goIntoBattle(enemiesAmount);
			cout << "Результат: " << (result.isVictory ? "ПОБЕДА" : "ПОРАЖЕНИЕ") << endl;
			cout << "Ранено в отряде: " << result.woundedAmount << endl;
			cout << "Погибло в отряде: " << result.diedAmount << endl;
		}
		break;
		case 5:
		{
			cout << "Имя: ";
			cin >> name;

			cout << "Фамилия: ";
			cin >> surname;

			cout << "Отчество: ";
			cin >> patronymic;

			cout << "Порядковый номер: ";
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
				cout << "Cолдат успешно добавлен" << endl;
			else
				cout << "Cолдат не был добавлен" << endl;
			break;
		}
		case 6:
			cout << "Введите порядковый номер: ";
			cin >> id;

			if (squad.removeSoldier(id))
				cout << "Cолдат успешно удален" << endl;
			else
				cout << "Cолдат не был удален" << endl;
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