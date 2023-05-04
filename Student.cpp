/*
Файл с дополнительными функциями
*/
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "Windows.h"

using namespace std;


bool checkForValue(int min, int value, int max) {
	if (min <= value && value <= max) {
		return true;
	}
	else {
		// звук ошибки windows
		cout << "\a";
		cout << "Введено неверное значение (" << value << ")! Введите число от " << min << " до " << max << "\n";
		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
		return false;
	}
}

int getAmountOfStudents() {
	string buffer;
	int count = 0;
	ifstream file("StudentsData.txt", ios_base::out);
	if (!file.is_open()) {
		cout << "Файл не открыт!\n";
		return 404;
	}
	while (getline(file, buffer, '\n')) {
		if (buffer == "=== END ===") {
			count++;
		}
	}
	return count;
}