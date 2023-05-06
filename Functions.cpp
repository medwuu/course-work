/*
Файл с дополнительными функциями
*/
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Functions.h"

using namespace std;

// узнаём, сколько студентов в файле при запуске программы
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

// проверяем, попадает ли введённое значение в нужный диапазон
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

// "умный" ввод только текста
string getAlpha(string whatToEnter) {
	string output = "";
	char letter = 0;
	while (letter != 13) {
		letter = _getch();
		// проверка на соответствие введённого символа большим или маленькими буквами английского, а затем русского алфавита
		if ((65 <= letter && letter <= 90) || (97 <= letter && letter <= 122) || (-200 <= letter && letter <= -1)) {
			output += letter;
			system("cls");
		}
		// удаление при нажатии backspace
		else if (letter == 8 && output.length() != 0) {
			output.pop_back();
			system("cls");
		}
		else {
			system("cls");
		}
		cout << whatToEnter << output;
	}
	return output;
}

// "умный" ввод только цифр
int getDigit(string whatToEnter) {
	string output = "";
	char letter = 0;
	while (letter != 13) {
		letter = _getch();
		if (48 <= letter && letter <= 57) {
			output += letter;
			system("cls");
		}
		else if (letter == 8 && output.length() != 0) {
			output.pop_back();
			system("cls");
		}
		else {
			system("cls");
		}
		cout << whatToEnter << output;
	}
	return atoi(output.c_str());
}