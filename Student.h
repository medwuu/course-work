#pragma once
#include <iostream>

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
	bool sex;
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