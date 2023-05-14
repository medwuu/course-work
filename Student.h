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

// факультет (институт)
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
	// название предмета (9 сессий по 10 предметов в каждой)
	string subject[9][10];
	// оценки (9 сессий по 10 предметов в каждой)
	int mark[9][10];
	// проверка, пустое ли значение (9 сессий по 10 предметов в каждой)
	// true – пусто, false – нет
	bool is_empty[9][10];
	float mean;
};


// класс, студента. там прописаны прототипы функций для работы с ним
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
	Student();
	void setSurname();
	void setName();
	void setPatronymic();
	void setBirthDate();
	void setAdmissionYear();
	void setFaculty();
	void setDepartment();
	void setGroup();
	void setStudentbookNumber();
	void setSex();
	void setSession();
	void setMean();

	int getAdmissionYear();
	float getMean();
	int getEmptySessionNumber(int session_num);

	void addStudent();
	void printStudent(int student_num);
	void writeIntoFile(Fio fio_, BirthDate birth_date_, AdmissionYear admission_year_, Faculty faculty_,
					   Department department_, Group group_, StudentBookNumber studentbook_number_,
					   Sex sex_, Session session_);
	void readFromFile(int required_number);
	void editStudent(Student* student, int student_count);
	void editStudentSession(int required_student);
	int deleteStudent(Student* student, int student_count);
	void deleteSession(int required_student);
};