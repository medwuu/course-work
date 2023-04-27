#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Menu.h"
#include "Student.h"

using namespace std;

// переменная, в которую записывается, что делать (из главного меню)
unsigned short action;

int checkForValue(int min, int value, int max) {
	if (min <= value && value <= max) {
		return 1;
	}
	else {
		// звук ошибки windows
		cout << "\a";
		cout << "Введено неверное значение (" << value << ")! Введите число от " << min << " до " << max << "\n";
		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
		return 0;
	}
}


void mainMenu() {
	cout << "Главное меню:\n";
	cout << "1. Добавить запись\n";
	cout << "2. Вывод данных\n";
	cout << "3. Изменение данных\n";
	cout << "4. Удалить запись\n";
	cout << "5. Выполнить 24 вариант\n";
	cout << "6. Выход\n\n";
	cout << "Выберите действие (число от 1 до 6): ";
	cin >> action;
	system("cls");
	if (!checkForValue(1, action, 6)) {
		mainMenu();
	}
}










int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	Student student;

	while (true) {
		mainMenu();
		switch (action)
		{
		case 1:
			cout << "Case 1";
			break;
		case 2:
			student.printStudent();
			break;
		case 3:
			cout << "Case 3";
			break;
		case 4:
			cout << "Case 4";
			break;
		case 5:
			cout << "Case 5";
			break;
		case 6:
			cout << "Конец работы программы\n\n";
			return 0;
			// в идеале, этот блок никогда не должен срабатывать, потому что есть checkForValue()
		default:
			cout << "Произошла непредвиденная ошибка";
			return 404;
		}
	}
}