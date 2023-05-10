/*
Файл с функциями класса Student
*/

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "Functions.h"
#include "Student.h"

#define line cout << "+"; for (int _ = 0; _ < 100; _++) { if (_ == 35) {cout << "+";} else {cout << "-";}} cout << "+\n"

using namespace std;

// обозначает конец записи в файле
string end_record = "=== END ===";

Student::Student() {
	fio.surname = fio.name = fio.patronymic = faculty.faculty = department.department = group.group = studentbook_number.student_book_number = sex.sex = "";
	birth_date.day = birth_date.month = birth_date.year = admission_year.admission_year = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			session.subject[i][j] = "";
			session.mark[i][j] = -1;
			session.is_empty[i][j] = true;
		}
	}
}

void Student::getSurname() {
	cout << "Введите фамилию: ";
	string out = getAlpha("Введите фамилию: ");
	system("cls");
	fio.surname = out;
}

void Student::getName() {
	cout << "Введите имя: ";
	string out = getAlpha("Введите имя: ");
	system("cls");
	fio.name = out;
}

void Student::getPatronymic() {
	cout << "Введите отчество: ";
	string out = getAlpha("Введите отчество: ");
	system("cls");
	fio.patronymic = out;
}

void Student::getBirthDate() {
	int out_day;
	int out_month;
	int out_year;
	// проверка на вход инпута в допустимый диапазон
	while (true) {
		cout << "Введите дату рождения (число от 1 до 31): ";
		out_day = getDigit("Введите дату рождения (число от 1 до 31): ");
		cout << "\n";
		// пусть пока будет 31 день
		if (checkForValue(1, out_day, 31)) {
			break;
		}
		system("cls");
	}
	system("cls");

	while (true) {
		cout << "Введите месяц рождения (число от 1 до 12): ";
		out_month = getDigit("Введите месяц рождения (число от 1 до 12): ");
		cout << "\n";
		if (checkForValue(1, out_month, 12)) {
			break;
		}
		system("cls");
	}
	system("cls");

	while (true) {
		cout << "Введите год рождения (число от 1900 до 2004): ";
		out_year = getDigit("Введите год рождения (число от 1900 до 2004): ");
		cout << "\n";
		if (checkForValue(1900, out_year, 2004)) {
			break;
		}
		system("cls");
	}
	system("cls");

	birth_date.day = out_day;
	birth_date.month = out_month;
	birth_date.year = out_year;
}

void Student::getAdmissionYear() {
	int out;
	while (true) {
		cout << "Введите год поступления (число от 1900 до 2022): ";
		out = getDigit("Введите год поступления (число от 1900 до 2022): ");
		cout << "\n";
		if (checkForValue(1900, out, 2022)) {
			break;
		}
		system("cls");
	}
	system("cls");
	admission_year.admission_year = out;
}

void Student::getFaculty() {
	cout << "Введите факультет: ";
	string out = getAlpha("Введите факультет: ");
	system("cls");
	faculty.faculty = out;
}

void Student::getDepartment() {
	string out;
	cout << "Введите кафедру: ";
	cin >> out;
	system("cls");
	department.department = out;
}

void Student::getGroup() {
	string out;
	cout << "Введите группу: ";
	cin >> out;
	system("cls");
	group.group = out;
}

void Student::getStudentbookNumber() {
	string out;
	cout << "Введите номер зачётной книжки: ";
	cin >> out;
	system("cls");
	studentbook_number.student_book_number = out;
}

void Student::getSex() {
	int out;
	while (true) {
		cout << "Введите пол (1 – мужской, 0 – женский): ";
		out = getDigit("Введите пол (1 – мужской, 0 – женский): ");
		cout << "\n";
		if (checkForValue(0, out, 1)) {
			if (out == 1) {
				system("cls");
				sex.sex = "мужской";
				break;
			}
			else {
				system("cls");
				sex.sex = "женский";
				break;
			}
		}
		system("cls");
	}
}

void Student::getSession() {
	int session_num, out_mark;
	string out_subject;
	while (true) {
		// ввод номера сессии
		cout << "Введите номер сессии (число от 1 до 9) или \"0\" чтобы пропустить: ";
		while (true) {
			session_num = getDigit("Введите номер сессии (число от 1 до 9) или \"0\" чтобы пропустить: ");
			cout << "\n";
			if (checkForValue(0, session_num, 9)) {
				break;
			}
		}
		// while с условием не получался :с
		if (session_num == 0) { break; }
		// потому что индексы
		session_num--;
		system("cls");
		// ввод названия предмета
		cout << "Введите название предмета: ";
		cin >> out_subject;
		system("cls");
		// ввод оценки или зачёт/незачёт
		while (true) {
			cout << "Теперь введите оценку для предмета.\n" <<
				"0-незачёт\n" <<
				"1-зачёт\n" <<
				"2-неудовлетворительно\n" <<
				"3-удовлетворительно\n" <<
				"4-хорошо\n" <<
				"5-отлично\n\n" <<
				"Ваш выбор: ";
			out_mark = getDigit("Теперь введите оценку для предмета.\n0-незачёт\n1-зачёт\n2-неудовлетворительно\n3-удовлетворительно\n4-хорошо\n5-отлично\n\nВаш выбор: ");
			cout << "\n";
			if (checkForValue(0, out_mark, 5)) {
				break;
			}
		}
		cout << "\n";
		// проверка на то, какой предмет будет по номеру
		int subject_num = getEmptySessionNumber(session_num);
		if (subject_num == -1) {
			cout << "В сессии " << session_num << " уже нет доступных мест для добавления";
			break;
		}
		else {
			session.subject[session_num][subject_num] = out_subject;
			session.mark[session_num][subject_num] = out_mark;
			session.is_empty[session_num][subject_num] = false;
			cout << "Сессия успешно добавлена!\nДля продолжения нажмите любую клавишу. . .";
			_getch();
			system("cls");
		}
	}
}


// узнать, сколько предметов записано в одной сессии
int Student::getEmptySessionNumber(int session_num) {
	for (int i = 0; i < 10; i++) {
		if (session.is_empty[session_num][i]) {
			return i;
		}
	}
	return -1;
}


// ввод записи с клавиатуры
void Student::addStudent() {
	getSurname();
	getName();
	getPatronymic();
	getBirthDate();
	getAdmissionYear();
	getFaculty();
	getDepartment();
	getGroup();
	getStudentbookNumber();
	getSex();
	getSession();	
	writeIntoFile(fio, birth_date, admission_year, faculty, department, group, studentbook_number, sex, session);
	cout << "Данные успешно записаны в файл \"StudentsData.txt\"\n";
	cout << "Для продолжения нажмите любую клавишу. . .";
	_getch();
	system("cls");
}


// вывод данных о студентах
void Student::printStudent(int student_num) {
	line;
	cout << left << "| " << student_num + 1;
	cout.width(30);
	cout << ".\t1. ФИО: ";
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
	line;
	cout.width(30);
	cout << left << "|\t9. Результаты сессий: ";
	cout << "|\t";
	for (int session_num = 0; session_num < 9; session_num++) {
		if (session_num != 0) { cout.width(36); cout << left << "|"; cout << "|\t"; }

		cout << session_num + 1 << " сессия: ";
		// в записи есть хоть один результат сессии
		if (getEmptySessionNumber(session_num) != 0) {
			for (int subject_num = 0; subject_num < 10; subject_num++) {
				if (!session.is_empty[session_num][subject_num]) {
					if (subject_num != 0) {
						cout.width(36);
						cout << left << "|";
						cout << "|\t\t  ";
					}
					cout << session.subject[session_num][subject_num] << " – ";

					if (session.mark[session_num][subject_num] == 0) {
						cout << "незачёт";
						cout.width(63 - 9 - session.subject[session_num][subject_num].length() - 3 - 8);
					}
					else if (session.mark[session_num][subject_num] == 1) {
						cout << "зачёт";
						cout.width(63 - 9 - session.subject[session_num][subject_num].length() - 3 - 6);
					}
					else {
						cout << session.mark[session_num][subject_num];
						cout.width(63 - 10 - session.subject[session_num][subject_num].length() - 3 - 1);
					}
					cout << right << "|\n";

				}
				// пустая запись (закончились)
				else { break; }
			}
		}
		// нет данных о сессиях
		else {
			cout << "нет данных";
			cout.width(63 - 20);
			cout << right << "|\n";
		}
	}
	line;
	cout << "\n\n";
}


// запись данных (одной записи) в файл
void Student::writeIntoFile(Fio fio_, BirthDate birth_date_, AdmissionYear admission_year_, Faculty faculty_,
						   Department department_, Group group_, StudentBookNumber studentbook_number_,
						   Sex sex_, Session session_) {
	ofstream file("StudentsData.txt", ios_base::app);
	// TODO: обрабатывать эту ошибку
	if (!file.is_open()) {
		cout << "Файл не открыт!";
		_getch();
		return;
	}
	file << fio_.surname << "\n" << fio_.name << "\n" << fio_.patronymic << "\n";
	file << birth_date_.day << "\n" << birth_date_.month << "\n" << birth_date_.year << "\n";
	file << admission_year_.admission_year << "\n";
	file << faculty_.faculty << "\n";
	file << department_.department << "\n";
	file << group_.group << "\n";
	file << studentbook_number_.student_book_number << "\n";
	file << sex_.sex << "\n";
	// выглядит сложно, но этот мега-цикл проходит по всем сессиям
	for (int session_num = 0; session_num < 9; session_num++) {
		// тут определятся, есть ли вообще в сессии записи
		int subject_count;
		for (int i = 0; i < 10; i++) {
			if (session_.is_empty[session_num][i]) {
				subject_count = i;
			}
		}
		if (subject_count) {
			file << session_num << "\n";
			// ну и наконец, проходимся в непустой(!) сессии по непустым(!) записям и записываем в файл
			for (int i = 0; i < subject_count; i++) {
				file << session_.subject[session_num][i] << ":" << session_.mark[session_num][i] << "\n";
			}
		}
	}
	file << end_record << "\n";
	file.close();
}


// чтение данных (одной записи) из файла
void Student::readFromFile(int requirement_number) {
	int student_number = 0, session_num;
	string buffer;
	int f_line = 0;
	ifstream file("StudentsData.txt", ios_base::out);
	if (!file.is_open()) {
		cout << "Файл не открыт!\n";
		return;
	}
	else {
		while (getline(file, buffer, '\n')) {
			// в файл записываются неиницализированные значения. этот блок просто не читает их
			// костыли? ну а что поделать. так и живём		||		кроме шуток, я 2 дня пытался пофиксить эту ошибку, поэтому даже такое решение меня устраивает
			if (buffer[0] == ':' && buffer[1] == '-') {}
			else if (student_number == requirement_number && buffer != end_record) {
				switch (f_line) {
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
				// тут был геймплей отладчика на 2000 лет
				default:
					// означает, что мы попали на строку, которая определяет номер сессии
					if (buffer.length() == 1) { session_num = atoi(buffer.c_str()); }
					else {
						int subject_num = getEmptySessionNumber(session_num);
						bool was_colon = false;
						for (char letter : buffer) {
							if (letter == ':') { was_colon = true; }
							else if (!was_colon) { session.subject[session_num][subject_num] += letter; }
							else {
								session.mark[session_num][subject_num] = int(letter) - int('0');
								session.is_empty[session_num][subject_num] = false;
							}
						}
					}
					break;
				}
				f_line++;
			}
			else if (buffer == end_record) {
				student_number++;
				f_line = 0;
			}
		}
		file.close();
	}
}


// удаление студента
int Student::deleteStudent(Student* student, int student_count) {
	int number;
	if (student_count == 0) {
		cout << "Пока не кого отчислять :(\n";
	}
	else {
		while (true) {
			cout << "Введите порядковый номер (на рукаве) студента: ";
			cin >> number;
			if (checkForValue(1, number, student_count)) {
				number--;
				break;
			}
		}
		system("cls");

		// очищаем файл перед записью всех "сдвинутых" значений
		ofstream file("StudentsData.txt", ios_base::trunc);
		file.close();
		for (int i = 0; i < student_count; i++) {
			if (i != number) {
				writeIntoFile(student[i].fio, student[i].birth_date, student[i].admission_year, student[i].faculty, student[i].department, student[i].group, student[i].studentbook_number, student[i].sex, student[i].session);
			}
		}
		cout << "Данные успешно обновлены!\n";
	}
	cout << "Для продолжения нажмите любую клавишу...";
	_getch();
	system("cls");
	return number;
}


// изменение данных студента
void Student::editStudent(Student* student, int student_count) {
	if (student_count == 0) { cout << "Тут что-то пусто. Для начала, добавьте студентов\n"; }
	else {
		int requred_student, parameter;
		while (true) {
			cout << "Введите порядковый номер (на рукаве) студента, данные которого хотите изменить: ";
			requred_student = getDigit("Введите порядковый номер (на рукаве) студента, данные которого хотите изменить: ");
			cout << "\n";
			if (checkForValue(1, requred_student, student_count)) {
				break;
			}
		}
		// уменьшаем на 1, потому что работаем с индексами
		requred_student--;
		system("cls");

		while (true) {
			cout << "Теперь введите номер параметра, который хотите изменить.\nПодсказка:\n1-фамилия\n2-имя\n3-отчество\n4-дата рождения\n5-год поступления\n6-факультет\n7-кафедра\n8-группа\n9-номер зачётной книжки\n10-пол\n11-данные о сессии\n\nВаш выбор: ";
			parameter = getDigit("Теперь введите номер параметра, который хотите изменить.\nПодсказка:\n1-фамилия\n2-имя\n3-отчество\n4-дата рождения\n5-год поступления\n6-факультет\n7-кафедра\n8-группа\n9-номер зачётной книжки\n10-пол\n11-данные о сессии\n\nВаш выбор: ");
			cout << "\n";
			if (checkForValue(1, parameter, 11)) {
				break;
			}
		}
		system("cls");

		switch (parameter) {
		case 1:
			student[requred_student].getSurname();
			break;
		case 2:
			student[requred_student].getName();
			break;
		case 3:
			student[requred_student].getBirthDate();
			break;
		case 5:
			student[requred_student].getAdmissionYear();
			break;
		case 6:
			student[requred_student].getFaculty();
			break;
		case 7:
			student[requred_student].getDepartment();
			break;
		case 8:
			student[requred_student].getGroup();
			break;
		case 9:
			student[requred_student].getStudentbookNumber();
			break;
		case 10:
			student[requred_student].getSex();
			break;
		case 11:
			student[requred_student].editStudentSession(requred_student);
			break;
		default:
			cout << "Произошла непредвиденная ошибка!";
		}

		// очищаем файл перед записью всех "сдвинутых" значений
		ofstream file("StudentsData.txt", ios_base::trunc);
		file.close();
		for (int i = 0; i < student_count; i++) {
			writeIntoFile(student[i].fio, student[i].birth_date, student[i].admission_year, student[i].faculty, student[i].department, student[i].group, student[i].studentbook_number, student[i].sex, student[i].session);
		}
		cout << "Данные успешно обновлены!\n";
	}
	cout << "Для продолжения нажмите любую клавишу...";
	_getch();
	system("cls");
}


// изменение сессии студента и удаление
void Student::editStudentSession(int required_student) {
	int choose, session_num, subject_num, num_subj_in_session, new_mark;
	string new_subject;
	printStudent(required_student);
	cout << "Введите:\n\"1\", чтобы добавить новую запись\n\"2\", чтобы изменить существующую запись\n\"3\", чтобы удалить существующую запись\n\nВаш выбор : ";
	while (true) {
		choose = getDigit("Введите:\n\"1\", чтобы добавить новую запись\n\"2\", чтобы изменить существующую запись\n\"3\", чтобы удалить существующую запись\n\nВаш выбор : ");
		cout << "\n";
		if (checkForValue(1, choose, 3)) {
			break;
		}
	}
	system("cls");

	// добавить новую запись
	if (choose == 1) {
		getSession();
	}

	else if (choose == 2) {
		// получаем номер сессии
		printStudent(required_student);
		cout << "Введите номер сессии, данные которой вы хотите изменить: ";
		while (true) {
			session_num = getDigit("Введите номер сессии, данные которой вы хотите изменить: ");
			cout << "\n";
			if (checkForValue(1, session_num, 9)) {
				num_subj_in_session = getEmptySessionNumber(session_num - 1);
				if (num_subj_in_session == 0) { cout << "В этой сессии нет предметов для изменения. Воспользуйтесь функцией добавления новой записи!"; }
				else { break; }
			}
		}
		system("cls");

		// получаем нормер предмета
		printStudent(required_student);
		cout << "Теперь введите номер предмета, данные которого хотите изменить: ";
		while (true) {
			subject_num = getDigit("Теперь введите номер предмета, данные которого хотите изменить: ");
			cout << "\n";
			if (checkForValue(1, subject_num, num_subj_in_session)) {
				break;
			}
		}
		system("cls");

		// получаем новое название предмета
		cout << "Введите название предмета: ";
		cin >> new_subject;

		// получаем  новую оценку
		cout << "Теперь введите оценку для предмета.\n0 - незачёт\n1 - зачёт\n2 - неудовлетворительно\n3 - удовлетворительно\n4 - хорошо\n5 - отлично\n\nВаш выбор : ";
		while (true) {
			new_mark = getDigit("Теперь введите оценку для предмета.\n0-незачёт\n1-зачёт\n2-неудовлетворительно\n3-удовлетворительно\n4-хорошо\n5-отлично\n\nВаш выбор: ");
			cout << "\n";
			if (checkForValue(0, new_mark, 5)) {
				break;
			}
		}

		// заменяем значения в элементе класса
		session.subject[session_num - 1][subject_num - 1] = new_subject;
		session.mark[session_num - 1][subject_num - 1] = new_mark;
	}

	// удалить существующую запись
	else {
		deleteSession(required_student);
	}
}

void Student::deleteSession(int required_student) {
	int session_num, subject_num, num_subj_in_session;
	printStudent(required_student);
	cout << "Введите номер сессии, данные которой вы хотите удалить: ";
	while (true) {
		session_num = getDigit("Введите номер сессии, данные которой вы хотите удалить: ");
		cout << "\n";
		if (checkForValue(1, session_num, 9)) {
			num_subj_in_session = getEmptySessionNumber(session_num - 1);
			if (num_subj_in_session == 0) { cout << "В этой сессии нет предметов для удаления. Воспользуйтесь функцией добавления новой записи!"; }
			else { break; }
		}
	}
	system("cls");

	printStudent(required_student);
	cout << "Теперь введите номер предмета, данные которого хотите удалить: ";
	while (true) {
		subject_num = getDigit("Теперь введите номер предмета, данные которого хотите удалить: ");
		cout << "\n";
		if (checkForValue(1, subject_num, num_subj_in_session)) {
			break;
		}
	}
	system("cls");


	if (!session.is_empty[session_num - 1][subject_num]) {
		while (!session.is_empty[session_num - 1][subject_num]) {
			session.subject[session_num - 1][subject_num - 1] = session.subject[session_num - 1][subject_num];
			session.mark[session_num - 1][subject_num - 1] = session.mark[session_num - 1][subject_num];
			session.is_empty[session_num - 1][subject_num - 1] = session.is_empty[session_num - 1][subject_num];
			subject_num++;
		}
	}
	session.subject[session_num - 1][subject_num - 1] = "";
	session.mark[session_num - 1][subject_num - 1] = -1;
	session.is_empty[session_num - 1][subject_num - 1] = true;
}