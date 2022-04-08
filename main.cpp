#include <iostream>
#include "List.h"
#include "Time.h"

using namespace std;

void showMenu();
void showMenu2();
void showMenuAddTime();
void showMenuRemoveTime();
void showMenuCompareTime();

int main()
{
	setlocale(LC_ALL, "ru");
	int choice, choiceMenu2, flag, value, mod = 0;
	bool res;
	while (mod != 3)
	{
		flag = 1;
		cout << "Выберите номер задания\n";
		cout << "1 - Задание 1. Унарная операция\n";
		cout << "2 - Задание 2. Бинарная операция\n";
		cout << "3 - Выход из программы\n";
		cin >> mod;
		system("cls");

		if (mod == 1) {
			List lst = List();

			system("cls");
			showMenu();

			while (flag == 1)
			{
				cout << "Введите действие:\n>> ";
				cin >> choice;
				system("cls");
				showMenu();
				switch (choice)
				{
				case 1:
					cout << "Введите значение:\n>> ";
					lst = ++lst;
					break;
				case 2:
					lst = lst++;
					break;
				case 3:
					lst = --lst;
					break;
				case 4:
					lst = lst--;
					break;
				case 5:
					lst.print();
					break;
				case 6:
					lst.clearList();
					break;
				case 7:
					flag = 0;
					system("cls");
					break;
				}
			}
		}
		else
		{
			if (mod == 2) {
				Time timeSelected = Time();
				Time timeNom2 = Time();
				Time time1 = Time();
				Time time2 = Time();
				timeSelected = time1;
				timeNom2 = time2;
				int choiceTime = 1;

				system("cls");
				showMenu2();

				while (flag == 1)
				{
					cout << "\nВведите действие:\n>> ";
					cin >> choice;
					system("cls");
					showMenu2();
					switch (choice)
					{
					case 1:
						showMenuAddTime();
						cout << "Введите действие:\n>> ";
						cin >> choiceMenu2;
						cout << "Введите значение:\n>> ";
						cin >> value;
						switch (choiceMenu2) {
						case 1:
							timeSelected = timeSelected + value;
							break;
						case 2:
							value = value * 60;
							timeSelected = timeSelected + value;
							break;
						case 3:
							value = value * 3600;
							timeSelected = timeSelected + value;
							break;
						}
						break;
					case 2:
						showMenuRemoveTime();
						cout << "Введите действие:\n>> ";
						cin >> choiceMenu2;
						cout << "Введите значение:\n>> ";
						cin >> value;
						switch (choiceMenu2) {
						case 1:
							timeSelected = timeSelected - value;
							break;
						case 2:
							value *= 60;
							timeSelected = timeSelected - value;
							break;
						case 3:
							value *= 3600;
							timeSelected = timeSelected - value;
							break;
						}
						break;
					case 3:
						showMenuCompareTime();
						cout << "Введите действие:\n>> ";
						cin >> choiceMenu2;
						switch (choiceMenu2) {
						case 1:
							timeSelected.print();
							cout << " > ";
							timeNom2.print();
							cout << "\n";
							res = timeSelected > timeNom2;
							if (res) {
								cout << "Верно\n";
							}
							else
							{
								cout << "Неверно\n";
							}
							break;
						case 2:
							timeSelected.print();
							cout << " < ";
							timeNom2.print();
							cout << "\n";
							res = timeSelected < timeNom2;
							if (res) {
								cout << "Верно\n";
							}
							else
							{
								cout << "Неверно\n";
							}
							break;
						case 3:
							timeSelected.print();
							cout << " >= ";
							timeNom2.print();
							cout << "\n";
							res = timeSelected >= timeNom2;
							if (res) {
								cout << "Верно\n";
							}
							else
							{
								cout << "Неверно\n";
							}
							break;
						case 4:
							timeSelected.print();
							cout << " <= ";
							timeNom2.print();
							cout << "\n";
							res = timeSelected <= timeNom2;
							if (res) {
								cout << "Верно\n";
							}
							else
							{
								cout << "Неверно\n";
							}
							break;
						case 5:
							timeSelected.print();
							cout << " == ";
							timeNom2.print();
							cout << "\n";
							res = timeSelected == timeNom2;
							if (res) {
								cout << "Верно\n";
							}
							else
							{
								cout << "Неверно\n";
							}
							break;
						case 6:
							timeSelected.print();
							cout << " != ";
							timeNom2.print();
							cout << "\n";
							res = timeSelected != timeNom2;
							if (res) {
								cout << "Верно\n";
							}
							else
							{
								cout << "Неверно\n";
							}
							break;
						}
						break;
					case 4:
						if (choiceTime == 1) {
							time1 = timeSelected;
						}
						else
						{
							time2 = timeSelected;
						}
						cout << "1 - ";
						time1.print();
						cout << "\n2 - ";
						time2.print();
						cout << "\n";
						cout << "Выберите элемент:\n>> ";
						cin >> choiceMenu2;
						if (choiceMenu2 == 1) {
							timeSelected = time1;
							timeNom2 = time2;
							choiceTime = 1;
							cout << "Выбран 1-ый элемент:\n";
						}
						else
						{
							timeSelected = time2;
							timeNom2 = time1;
							choiceTime = 2;
							cout << "Выбран 2-ой элемент:\n";
						}
						break;
					case 5:
						timeSelected.print();
						cout << "\n";
						break;
					case 6:
						timeSelected.clearTime();
						break;
					case 7:
						if (choiceTime == 1) {
							time1 = timeSelected;
						}
						else
						{
							time2 = timeSelected;
						}
						cout << "1 - ";
						time1.print();
						cout << "\n2 - ";
						time2.print();
						cout << "\n";
						break;
					case 8:
						flag = 0;
						system("cls");
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}


}

void showMenu() {
	cout << "1 - Добавить элемент в конец списка (Ввод с клавиатуры) (++а)\n";
	cout << "2 - Добавить элемент в начало списка (Случайное число от 0 до 10) (а++)\n";
	cout << "3 - Извлечь элемент из конца списка (--а)\n";
	cout << "4 - Извлечь элемент из начала списка (а--)\n";
	cout << "5 - Вывод списка на экран\n";
	cout << "6 - Очистить список\n";
	cout << "7 - Выбор задания\n\n";
}

void showMenu2() {
	cout << "1 - Добавить секунды/минуты/часы элементу\n";
	cout << "2 - Отнять секунды/минуты/часы от элемента\n";
	cout << "3 - Сравнить время элементов\n";
	cout << "4 - Выбор элемента\n";
	cout << "5 - Вывод выбранного элемента на экран\n";
	cout << "6 - Очистить элемент\n";
	cout << "7 - Вывод всех элементов на экран\n";
	cout << "8 - Выбор задания\n\n";
}

void showMenuAddTime() {
	cout << "1 - Добавить секунды элементу\n";
	cout << "2 - Добавить минуты элементу\n";
	cout << "3 - Добавить часы элементу\n\n";
}

void showMenuRemoveTime() {
	cout << "1 - Отнять секунды от элемента\n";
	cout << "2 - Отнять минуты от элемента\n";
	cout << "3 - Отнять часы от элемента\n\n";
}

void showMenuCompareTime() {
	cout << "1 - Выбранный элемент > Второй элемента\n";
	cout << "2 - Выбранный элемент < Второй элемента\n";
	cout << "3 - Выбранный элемент >= Второй элемента\n";
	cout << "4 - Выбранный элемент <= Второй элемента\n";
	cout << "5 - Выбранный элемент == Второй элемента\n";
	cout << "6 - Выбранный элемент != Второй элемента\n\n";
}