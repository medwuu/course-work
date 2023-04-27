/*
Файл с классом Student и функции работы с ним
*/

#pragma once
#include <iostream>

#include "Menu.h"
#include "File.h"

#define line cout << "+"; for (int _ = 0; _ < 100; _++) {cout << "-";} cout << "+\n";

using namespace std;



// фамилия, имя и отчество
struct Fio {
	string surname, name, patronymic;
};

// дата рождения
struct BirthDate {
	unsigned short day, month, year;
};

// год поступления
struct AdmissionYear {
	unsigned short admission_year;
};

// факультет
struct Faculty {
	string faculty;
};

// кафедра
struct Department {
	string department;
};

// номер группы
struct Group {
	string group;
};

// номер зачётной книжки
struct StudentBookNumber {
	string student_book_number;
};

// пол
// true – мужской, false – женский
struct Sex {
	string sex;
};

// сессия
struct Session {
	// оценки
	unsigned short mark[9][10];
};



class Student {
private:
	Fio fio;
	BirthDate birth_date;
	AdmissionYear admission_year;
	Faculty faculty;
	Department department;
	Group group;
	StudentBookNumber studentbook_number;
	Sex sex;
	Session session;
public:
	
	void writeStudent() {
		unsigned short temp;
		cout << "Введите фамилию: ";
		cin >> fio.surname;
		system("cls");
		cout << "Введите имя: ";
		cin >> fio.name;
		system("cls");
		cout << "Введите отчество: ";
		cin >> fio.patronymic;
		system("cls");
		// проверка на вход инпута в допустимый диапазон
		while (true) {
			cout << "Введите дату рождения (число от 1 до 31): ";
			cin >> temp;
			// пусть пока будет 31 день
			if (checkForValue(1, temp, 31)) {
				birth_date.day = temp;
				break;
			}
			system("cls");
		}
		system("cls");
		while (true) {
			cout << "Введите месяц рождения (число от 1 до 12): ";
			cin >> temp;
			if (checkForValue(1, temp, 12)) {
				birth_date.month = temp;
				break;
			}
			system("cls");
		}
		system("cls");
		while (true) {
			cout << "Введите год рождения (число от 1900 до 2004): ";
			cin >> temp;
			if (checkForValue(1900, temp, 2004)) {
				birth_date.year = temp;
				break;
			}
			system("cls");
		}
		system("cls");
		while (true) {
			cout << "Введите год поступления (число от 1900 до 2022): ";
			cin >> temp;
			if (checkForValue(1900, temp, 2022)) {
				admission_year.admission_year = temp;
				break;
			}
			system("cls");
		}
		system("cls");
		cout << "Введите факультет: ";
		cin >> faculty.faculty;
		system("cls");
		cout << "Введите кафедру: ";
		cin >> department.department;
		system("cls");
		cout << "Введите группу: ";
		cin >> group.group;
		system("cls");
		cout << "Введите номер зачётной книжки: ";
		cin >> studentbook_number.student_book_number;
		system("cls");
		while (true) {
			cout << "Введите пол (1 – мужской, 0 – женский): ";
			cin >> temp;
			if (checkForValue(0, temp, 1)) {
				if (temp == 1) {
					sex.sex = "мужской";
				}
				else {
					sex.sex = "женский";
				}
				break;
			}
			system("cls");
		}
		system("cls");
		writeIntoFile(fio.surname, fio.name, fio.patronymic, birth_date.day, birth_date.month, birth_date.year, admission_year.admission_year, faculty.faculty, department.department, group.group, studentbook_number.student_book_number, sex.sex);
		cout << "Данные успешно записаны в файл \"StudentsData.txt\"\n";
		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
	}

	// выводим данные о студенте
	void printStudent() {
		line
		cout.width(30);
		cout << left << "ФИО: ";
		cout << "|\t" << fio.surname << " " << fio.name << " " << fio.patronymic << "\n";
		cout.width(30);
		cout << "Дата рождения: ";
		cout << "|\t" << birth_date.day << "." << birth_date.month << "." << birth_date.year << "\n";
		cout.width(30);
		cout << "Год поступления: ";
		cout << "|\t" << admission_year.admission_year << "\n";
		cout.width(30);
		cout << "Факультет (институт): ";
		cout << "|\t" << faculty.faculty << "\n";
		cout.width(30);
		cout << "Кафедра: ";
		cout << "|\t" << department.department << "\n";
		cout.width(30);
		cout << "Группа: ";
		cout << "|\t" << group.group << "\n";
		cout.width(30);
		cout << "Номер зачётной книжки: ";
		cout << "|\t" << studentbook_number.student_book_number << "\n";
		cout.width(30);
		cout << "Пол: ";
		cout << "|\t" << sex.sex << "\n";
		line

		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
	}
};