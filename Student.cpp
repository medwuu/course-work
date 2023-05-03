/*
Файл с дополнительными функциями
*/
#include <iostream>
#include <fstream>
#include <string>
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


void deleteStudent(Student* student, int student_count) {
	int number;
	if (student_count == 0) {
		cout << "Пока не кого отчислять :(\n";
	}
	while (true) {
		cout << "Введите порядковый номер (на рукаве) студента: ";
		cin >> number;
		if (checkForValue(1, number, student_count)) {
			break;
		}
	}
	// сдвигаем массив на -1
	for (number; number < student_count; number++) {
		student[number] = student[number + 1];
	}
}