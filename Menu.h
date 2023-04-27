/*
Файл с дополнительными функциями
*/
#pragma once
#include <iostream>
#include "Windows.h"

using namespace std;


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