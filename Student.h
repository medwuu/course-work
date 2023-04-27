#pragma once
#include <iostream>

#define line cout << "+"; for (int _ = 0; _ < 100; _++) {cout << "-";} cout << "+\n";

using namespace std;



// �������, ��� � ��������
struct Fio {
	string surname, name, patronymic;
};

// ���� ��������
struct BirthDate {
	unsigned short day, month, year;
};

// ��� �����������
struct AdmissionYear {
	unsigned short admission_year;
};

// ���������
struct Faculty {
	string faculty;
};

// �������
struct Department {
	string department;
};

// ����� ������
struct Group {
	string group;
};

// ����� �������� ������
struct StudentBookNumber {
	string student_book_number;
};

// ���
// true � �������, false � �������
struct Sex {
	bool sex;
};

// ������
struct Session {
	// ������
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
	
	// ������� ������ � ��������
	void printStudent() {
		line
		cout.width(30);
		cout << left << "���: ";
		cout << "|\t" << fio.surname << " " << fio.name << " " << fio.patronymic << "\n";
		cout.width(30);
		cout << "���� ��������: ";
		cout << "|\t" << birth_date.day << "." << birth_date.month << "." << birth_date.year << "\n";
		cout.width(30);
		cout << "��� �����������: ";
		cout << "|\t" << admission_year.admission_year << "\n";
		cout.width(30);
		cout << "��������� (��������): ";
		cout << "|\t" << faculty.faculty << "\n";
		cout.width(30);
		cout << "�������: ";
		cout << "|\t" << department.department << "\n";
		cout.width(30);
		cout << "������: ";
		cout << "|\t" << group.group << "\n";
		cout.width(30);
		cout << "����� �������� ������: ";
		cout << "|\t" << studentbook_number.student_book_number << "\n";
		cout.width(30);
		cout << "���: ";
		cout << "|\t" << sex.sex << "\n";
		line

		cout << "��� ����������� ������� ����� �������...";
		_getch();
		system("cls");
	}
};