/*
Файл с классом Student и функции работы с ним
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Menu.h"

#define line cout << "+"; for (int _ = 0; _ < 100; _++) {cout << "-";} cout << "+\n";

using namespace std;


// фамилия, имя и отчество
struct Fio {
	string surname, name, patronymic;
};

// дата рождения
struct BirthDate {
	int day, month, year;
};

// год поступления
struct AdmissionYear {
	int admission_year;
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
	int mark[9][10];
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
	//Session session;
public:
	/*Student(Fio fio_, BirthDate birth_date_, AdmissionYear admission_year_, Faculty faculty_,
			Department department_, Group group_, StudentBookNumber studentbook_number_, Sex sex_) {

	}*/

	void writeStudent() {
		int int_temp;
		string str_temp;
		cout << "Введите фамилию: ";
		fio.surname = getAlpha("Введите фамилию: ");
		system("cls");
		cout << "Введите имя: ";
		fio.name = getAlpha("Введите имя: ");
		system("cls");
		cout << "Введите отчество: ";
		fio.patronymic = getAlpha("Введите отчество: ");
		system("cls");
		// проверка на вход инпута в допустимый диапазон
		while (true) {
			cout << "Введите дату рождения (число от 1 до 31): ";
			int_temp = getDigit("Введите дату рождения (число от 1 до 31): ");
			cout << "\n";
			// пусть пока будет 31 день
			if (checkForValue(1, int_temp, 31)) {
				birth_date.day = int_temp;
				break;
			}
			system("cls");
		}
		system("cls");
		while (true) {
			cout << "Введите месяц рождения (число от 1 до 12): ";
			int_temp = getDigit("Введите месяц рождения (число от 1 до 12): ");
			cout << "\n";
			if (checkForValue(1, int_temp, 12)) {
				birth_date.month = int_temp;
				break;
			}
			system("cls");
		}
		system("cls");
		while (true) {
			cout << "Введите год рождения (число от 1900 до 2004): ";
			int_temp = getDigit("Введите год рождения (число от 1900 до 2004): ");
			cout << "\n";
			if (checkForValue(1900, int_temp, 2004)) {
				birth_date.year = int_temp;
				break;
			}
			system("cls");
		}
		system("cls");
		while (true) {
			cout << "Введите год поступления (число от 1900 до 2022): ";
			int_temp = getDigit("Введите год поступления (число от 1900 до 2022): ");
			cout << "\n";
			if (checkForValue(1900, int_temp, 2022)) {
				admission_year.admission_year = int_temp;
				break;
			}
			system("cls");
		}
		system("cls");
		cout << "Введите факультет: ";
		faculty.faculty = getAlpha("Введите факультет: ");
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
			int_temp = getDigit("Введите пол (1 – мужской, 0 – женский): ");
			cout << "\n";
			if (checkForValue(0, int_temp, 1)) {
				if (int_temp == 1) {
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

	string getAlpha(string whatToEnter) {
		string output = "";
		char letter = 0;
		while (letter != 13) {
			letter = _getch();
			// проверка на соответствие введённого символа большим или маленькими буквами английского, а затем русского алфавита
			if ((65 <= letter && letter <= 90) || (97 <= letter && letter <= 122) || (192 <= letter && letter <= 255)) {
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

	// выводим данные о студенте
	void printStudent() {
		line
			cout.width(30);
		cout << left << "|ФИО: ";
		cout << "|\t" << fio.surname << " " << fio.name << " " << fio.patronymic;
		cout.width(71 - fio.surname.length() - fio.name.length() - fio.patronymic.length() - 2);
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Дата рождения: ";
		cout << "|\t";
		if (birth_date.day < 10) {
			cout << 0;
		}
		cout << birth_date.day << ".";
		if (birth_date.month < 10) {
			cout << 0;
		}
		cout << birth_date.month << "." << birth_date.year;
		cout.width(71 - 10);
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Год поступления: ";
		cout << "|\t" << admission_year.admission_year;
		cout.width(71 - 4);
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Факультет (институт): ";
		cout << "|\t" << faculty.faculty;
		cout.width(71 - faculty.faculty.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Кафедра: ";
		cout << "|\t" << department.department;
		cout.width(71 - department.department.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Группа: ";
		cout << "|\t" << group.group;
		cout.width(71 - group.group.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Номер зачётной книжки: ";
		cout << "|\t" << studentbook_number.student_book_number;
		cout.width(71 - studentbook_number.student_book_number.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|Пол: ";
		cout << "|\t" << sex.sex;
		cout.width(71 - sex.sex.length());
		cout << right << "|\n";
		line

	}




	string end_record = "=== END ===";
	// костылии
	int writeIntoFile(string surname_, string name_, string patronymic_, int birth_date_day_,
		int birth_date_month_, int birth_date_year_, int admission_year_,
		string faculty_, string department_, string group_, string studentbook_number_, string sex_) {
		ofstream file("StudentsData.txt", ios_base::app);
		// TODO: обрабатывать эту ошибку
		if (!file.is_open()) {
			cout << "Файл не открыт!";
			_getch();
			return 404;
		}
		file << surname_ << "\n" << name_ << "\n" << patronymic_ << "\n";
		file << birth_date_day_ << "\n" << birth_date_month_ << "\n" << birth_date_year_ << "\n";
		file << admission_year_ << "\n";
		file << faculty_ << "\n";
		file << department_ << "\n";
		file << group_ << "\n";
		file << studentbook_number_ << "\n";
		file << sex_ << "\n";
		file << end_record << "\n";
		file.close();
		return 0;
	}

	int readFromFile() {
		string buffer;
		int f_line = 0;
		ifstream file("StudentsData.txt", ios_base::out);
		// FIXME: выводит "Файл не открыт", но данные читает
		if (!file.is_open()) {
			//cout << "Файл не открыт!\n";
			return 404;
		}
		else {
			while (getline(file, buffer, '\n')) {
				if (buffer != end_record) {
					switch (f_line % 12) {
					case 0:
						fio.surname = buffer;
						break;
					case 1:
						fio.name = buffer;
						break;
					case 2:
						fio.patronymic = buffer;
						break;
					case 3:
						birth_date.day = atoi(buffer.c_str());
						break;
					case 4:
						birth_date.month = atoi(buffer.c_str());
						break;
					case 5:
						birth_date.year = atoi(buffer.c_str());
						break;
					case 6:
						admission_year.admission_year = atoi(buffer.c_str());
						break;
					case 7:
						faculty.faculty = buffer;
						break;
					case 8:
						department.department = buffer;
						break;
					case 9:
						group.group = buffer;
						break;
					case 10:
						studentbook_number.student_book_number = buffer;
						break;
					case 11:
						sex.sex = buffer;
						break;
					default:
						cout << "Возникла непредвиденная ошибка!";
						break;
					}
					f_line++;
				}
				else {
					printStudent();
					f_line = 0;
				}
			}
			file.close();
			cout << "Для продолжения нажмите любую клавишу...";
			_getch();
			system("cls");
			return 0;
		}
	}
};