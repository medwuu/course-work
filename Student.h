/*
Файл класса Student и прототипами его функций
*/
#pragma once
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
	// TODO
	// Session session;
public:
	void getSurname();
	void getName();
	void getPatronymic();
	void getBirthDate();
	void getAdmissionYear();
	void getFaculty();
	void getDepartment();
	void getGroup();
	void getStudentbookNumber();
	void getSex();

	void writeStudent();
	void printStudent();
	int writeIntoFile(string surname_, string name_, string patronymic_, int birth_date_day_,
		int birth_date_month_, int birth_date_year_, int admission_year_,
		string faculty_, string department_, string group_, string studentbook_number_, string sex_);
	int readFromFile(int required_number);
	void editStudent(Student* student, int student_count);
	void deleteStudent(Student* student, int student_count);
};