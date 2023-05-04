/*
Файл с классом Student и функции работы с ним
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Functions.cpp"



#define line cout << "+"; for (int _ = 0; _ < 100; _++) { if (_ == 35) {cout << "+";} else {cout << "-";}} cout << "+\n";

using namespace std;

// обозначает конец записи в файле
string end_record = "=== END ===";

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
	// TODO
	// Session session;
public:
	// ввод записи с клавиатуры
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

	// вывод данных о студентах
	void printStudent() {
		line
		cout.width(30);
		cout << left << "|\t1. ФИО: ";
		cout << "|\t" << fio.surname << " " << fio.name << " " << fio.patronymic;
		cout.width(63 - fio.surname.length() - fio.name.length() - fio.patronymic.length() - 2);
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t2. Дата рождения: ";
		cout << "|\t";
		if (birth_date.day < 10) {
			cout << 0;
		}
		cout << birth_date.day << ".";
		if (birth_date.month < 10) {
			cout << 0;
		}
		cout << birth_date.month << "." << birth_date.year;
		cout.width(63 - 10);
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t3. Год поступления: ";
		cout << "|\t" << admission_year.admission_year;
		cout.width(63 - 4);
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t4. Факультет (институт): ";
		cout << "|\t" << faculty.faculty;
		cout.width(63 - faculty.faculty.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t5. Кафедра: ";
		cout << "|\t" << department.department;
		cout.width(63 - department.department.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t6. Группа: ";
		cout << "|\t" << group.group;
		cout.width(63 - group.group.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t7. Номер зачётной книжки: ";
		cout << "|\t" << studentbook_number.student_book_number;
		cout.width(63 - studentbook_number.student_book_number.length());
		cout << right << "|\n";
		cout.width(30);
		cout << left << "|\t8. Пол: ";
		cout << "|\t" << sex.sex;
		cout.width(63 - sex.sex.length());
		cout << right << "|\n";
		line
	}

	// запись данных (одной записи) в файл
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

	// чтение данных (одной записи) из файла
	int readFromFile(int requirement_number) {
		int student_number = 0;
		string buffer;
		int f_line = 0;
		ifstream file("StudentsData.txt", ios_base::out);
		if (!file.is_open()) {
			cout << "Файл не открыт!\n";
			return 404;
		}
		else {
			while (getline(file, buffer, '\n')) {
				if (student_number == requirement_number && buffer != end_record) {
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
				else if (buffer == end_record) {
					student_number++;
				}
			}
			file.close();
			return 0;
		}
	}

	// удаление студента
	void deleteStudent(Student* student, int student_count) {
		int number;
		if (student_count == 0) {
			cout << "Пока не кого отчислять :(\n";
		}
		else {
			while (true) {
				cout << "Введите порядковый номер (на рукаве) студента: ";
				cin >> number;
				if (checkForValue(1, number, student_count)) {
					break;
				}
			}
			system("cls");
			// сдвигаем массив на -1
			for (number--; number < student_count; number++) {
				student[number] = student[number + 1];
			}

			// очищаем файл перед записью всех "сдвинутых" значений
			ofstream file("StudentsData.txt", ios_base::trunc);
			file.close();
			for (int i = 0; i < student_count--; i++) {
				writeIntoFile(student[i].fio.surname, student[i].fio.name, student[i].fio.patronymic, student[i].birth_date.day, student[i].birth_date.month, student[i].birth_date.year, student[i].admission_year.admission_year, student[i].faculty.faculty, student[i].department.department, student[i].group.group, student[i].studentbook_number.student_book_number, student[i].sex.sex);
			}
			cout << "Данные успешно обновлены!\n";
		}
		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
	}
};