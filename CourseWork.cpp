﻿/*
Основной файл курсовой работы
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

// TODO: перенести case 4 в отдельную функцию и убрать это недоразумение
#include <fstream>

#include "Student.h"

using namespace std;

// переменная, в которую записывается, что делать (из главного меню)
int action;




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
	Student student[100];
	int student_count = getAmountOfStudents();

	// инициализируем значения
	for (int i = 0; i < student_count; i++) {
		student[i].readFromFile(i);
	}

	while (true) {
		mainMenu();
		switch (action)
		{
		case 1:
			student[student_count].writeStudent();
			student_count++;
			break;
		case 2:
			for (int i = 0; i < student_count; i++) {
				student[i].printStudent();
			}
			cout << "Для продолжения нажмите любую клавишу...";
			_getch();
			system("cls");
			break;
		case 3:
			cout << "Case 3\n";
			break;
		case 4:
			// TODO: вынести в отдельную функцию
			int number;
			if (student_count == 0) {
				cout << "Пока не кого отчислять :(\n";
			}
			while (true) {
				cout << "Введите порядковый номер (на рукаве) студента: ";
				cin >> number;
				if (checkForValue(1, number, student_count)) {
					// уменьшеем на 1, потому что индексы идут с нуля
					number--;
					break;
				}
			}
			// сдвигаем массив на -1
			for (number; number < student_count; number++) {
				student[number] = student[number + 1];
			}
			student_count--;

			// TODO: заносим изменения в файл
			cout << "Данные успешно обновлены!\n";
			_getch();
			system("cls");
			break;
		case 5:
			cout << "Case 5\n";
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