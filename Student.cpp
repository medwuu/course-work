/*
Файл с функциями класса Student
*/

#include <iostream> // ввод-вывод
#include <fstream> // чтение-запись из/в файл
#include <string> // для операций со стринга́ми
#include <conio.h> // для _getch()

#include "Functions.h"
#include "Student.h"
#include "Crypto.h"

using namespace std;

// обозначает конец записи в файле
string end_record = "=== END ===";

// конструктор по умолчанию. заполняем объект класса пустыми (или почти) значениями
Student::Student() {
	fio.surname = fio.name = fio.patronymic = faculty.faculty = department.department = group.group = studentbook_number.student_book_number = sex.sex = "";
	birth_date.day = birth_date.month = birth_date.year = admission_year.admission_year = -1;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			session.subject[i][j] = "";
			session.mark[i][j] = -1;
			session.is_empty[i][j] = true;
		}
		session.mean = -1;
	}
}

// эта и далее функции, начинающиеся с "set" – сеттеры. они присваивают значения private полям класса
void Student::setSurname() {
	string out;
	while (true) {
		cout << "Введите фамилию: ";
		out = getAlpha("Введите фамилию: ");
		system("cls");
		if (checkForValue(out, 20)) { break; }
	}
	fio.surname = out;
}

void Student::setName() {
	string out;
	while (true) {
		cout << "Введите имя: ";
		out = getAlpha("Введите имя: ");
		system("cls");
		if (checkForValue(out, 20)) { break; }
	}
	fio.name = out;
}

void Student::setPatronymic() {
	string out;
	while (true) {
		cout << "Введите отчество: ";
		out = getAlpha("Введите отчество: ");
		system("cls");
		if (checkForValue(out, 20)) { break; }
	}
	fio.patronymic = out;
}

void Student::setBirthDate() {
	int out_day;
	int out_month;
	int out_year;
	// проверка на вход инпута в допустимый диапазон
	while (true) {
		cout << "Введите дату рождения (число от 1 до 31): ";
		out_day = getDigit("Введите дату рождения (число от 1 до 31): ");
		system("cls");
		// пусть пока будет 31 день
		if (checkForValue(1, out_day, 31)) { break; }
	}

	while (true) {
		cout << "Введите месяц рождения (число от 1 до 12): ";
		out_month = getDigit("Введите месяц рождения (число от 1 до 12): ");
		system("cls");
		if (checkForValue(1, out_month, 12)) { break; }
	}

	while (true) {
		// в 13 лет нельзя ведь в ВУЗ поступить. по крайней мере, в МИРЭА (:
		cout << "Введите год рождения (число от 1900 до 2010): ";
		out_year = getDigit("Введите год рождения (число от 1900 до 2010): ");
		system("cls");
		if (checkForValue(1900, out_year, 2005)) { break; }
	}

	birth_date.day = out_day;
	birth_date.month = out_month;
	birth_date.year = out_year;
}

void Student::setAdmissionYear() {
	int out;
	while (true) {
		string set = "Введите год поступления (число от " + to_string(getBirthYear()) + " до 2022): ";
		cout << set;
		out = getDigit(set);
		system("cls");
		// младше 14 не поступают :<
		if (checkForValue(getBirthYear() + 13, out, 2022)) { break; }
	}
	admission_year.admission_year = out;
}

void Student::setFaculty() {
	string out;
	while (true) {
		cout << "Введите факультет (институт): ";
		out = getAlpha("Введите факультет (институт): ");
		system("cls");
		if (checkForValue(out, 60)) { break; }
	}
	faculty.faculty = out;
}

void Student::setDepartment() {
	string out;
	while (true) {
		cout << "Введите кафедру: ";
		cin >> out;
		system("cls");
		if (checkForValue(out, 60)) { break; }
	}
	department.department = out;
}

void Student::setGroup() {
	string out;
	while (true) {
		cout << "Введите группу: ";
		cin >> out;
		system("cls");
		if (checkForValue(out, 60)) { break; }
	}
	group.group = out;
}

void Student::setStudentbookNumber() {
	string out;
	while (true) {
		cout << "Введите номер зачётной книжки: ";
		cin >> out;
		system("cls");
		if (checkForValue(out, 60)) { break; }
	}
	studentbook_number.student_book_number = out;
}

void Student::setSex() {
	int out;
	while (true) {
		cout << "Введите пол (1 – мужской, 0 – женский): ";
		out = getDigit("Введите пол (1 – мужской, 0 – женский): ");
		if (checkForValue(0, out, 1)) {
			system("cls");
			if (out == 1) {
				sex.sex = "мужской";
				break;
			}
			else {
				sex.sex = "женский";
				break;
			}
		}
		system("cls");
	}
}

void Student::setSession() {
	int session_num, out_mark;
	string out_subject;
	while (true) {
		// ввод номера сессии
		cout << "Введите номер сессии (число от 1 до 9) или \"0\" чтобы пропустить: ";
		while (true) {
			session_num = getDigit("Введите номер сессии (число от 1 до 9) или \"0\" чтобы пропустить: ");
			if (checkForValue(0, session_num, 9)) { break; }
		}
		// пользователь вводит "0" – (больше) не хочет добавлять
		if (session_num == 0) { break; }
		// потому что индексы
		session_num--;
		system("cls");
		// ввод названия предмета
		cout << "Введите название предмета: ";
		cin.ignore();
		getline(cin, out_subject);
		system("cls");
		// ввод оценки или зачёт/незачёт
		while (true) {
			cout << "Теперь введите оценку для предмета:" << endl <<
				"0-незачёт" << endl <<
				"1-зачёт" << endl <<
				"2-неудовлетворительно" << endl <<
				"3-удовлетворительно" << endl <<
				"4-хорошо" << endl <<
				"5-отлично" << endl << endl <<
				"Ваш выбор: ";
			out_mark = getDigit("Теперь введите оценку для предмета:\n0-незачёт\n1-зачёт\n2-неудовлетворительно\n3-удовлетворительно\n4-хорошо\n5-отлично\n\nВаш выбор: ");
			if (checkForValue(0, out_mark, 5)) { break; }
		}
		cout << endl;
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
			cout << "Сессия успешно добавлена!" << endl << "Для продолжения нажмите любую клавишу. . .";
			_getch();
			system("cls");
		}
	}
}

// устанавливаем для каждой сессии средний балл (необходимо для выполнения 24 варианта)
void Student::setMean() {
	int sum = 0, total_subject_num = 0;
	for (int session_num = 0; session_num < 9; session_num++) {
		int subj_in_session = getEmptySessionNumber(session_num);
		if (subj_in_session) {
			for (int subject_num = 0; subject_num < subj_in_session; subject_num++) {
				// "незачёт" приравниваем к оценке "2"
				if (session.mark[session_num][subject_num] == 0) { sum += 2; }
				// "зачёт" приравниваем к оценке "5"
				else if (session.mark[session_num][subject_num] == 1) { sum += 5; }
				// для всех остальных оценок
				else { sum += session.mark[session_num][subject_num]; }
				total_subject_num++;
			}
		}
	}
	session.mean = float(sum) / total_subject_num;
}


// с "get" начинаются "геттеры" – функции, позволяющие получить данные из private полей класса
int Student::getBirthYear() {
	return birth_date.year;
}

int Student::getAdmissionYear() {
	return admission_year.admission_year;
}

float Student::getMean() {
	return session.mean;
}

// узнать, сколько предметов записано в одной сессии
int Student::getEmptySessionNumber(int session_num) {
	for (int i = 0; i < 10; i++) {
		if (session.is_empty[session_num][i]) { return i; }
	}
	return -1;
}


// ввод записи с клавиатуры
void Student::addStudent() {
	setSurname();
	setName();
	setPatronymic();
	setBirthDate();
	setAdmissionYear();
	setFaculty();
	setDepartment();
	setGroup();
	setStudentbookNumber();
	setSex();
	setSession();
	setMean();
	Decrypt();
	writeIntoFile(fio, birth_date, admission_year, faculty, department, group, studentbook_number, sex, session);
	Crypt();
	cout << "Данные успешно записаны в файл \"StudentsData.txt\"" << endl;
	cout << "Для продолжения нажмите любую клавишу. . .";
	_getch();
	system("cls");
}


// рисует визуальный разделитель в таблице
void line() {
	cout << "+";
	for (int _ = 0; _ < 101; _++) {
		if (_ == 35) { cout << "+"; }
		else { cout << "-"; }
	}
	cout << "+" << endl;
}


// компактный вывод студентов (ФИО, номер группы)
void Student::printCompact(int student_num) {
	cout << left << student_num + 1 << ". " << fio.surname << " " << fio.name << " " << fio.patronymic << " " << group.group << endl;
}

// вывод данных о студентах
void Student::printStudent(int student_num) {
	line();
	cout << left << "| " << student_num + 1;
	cout.width(30);
	cout << ".\t1. ФИО: ";
	cout << "|\t" << fio.surname << " " << fio.name << " " << fio.patronymic;
	cout.width(63 - fio.surname.length() - fio.name.length() - fio.patronymic.length() - 2);
	cout << right << "|" << endl;
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
	cout << right << "|" << endl;
	cout.width(30);
	cout << left << "|\t3. Год поступления: ";
	cout << "|\t" << admission_year.admission_year;
	cout.width(63 - 4);
	cout << right << "|" << endl;
	cout.width(30);
	cout << left << "|\t4. Факультет (институт): ";
	cout << "|\t" << faculty.faculty;
	cout.width(63 - faculty.faculty.length());
	cout << right << "|" << endl;
	cout.width(30);
	cout << left << "|\t5. Кафедра: ";
	cout << "|\t" << department.department;
	cout.width(63 - department.department.length());
	cout << right << "|" << endl;
	cout.width(30);
	cout << left << "|\t6. Группа: ";
	cout << "|\t" << group.group;
	cout.width(63 - group.group.length());
	cout << right << "|" << endl;
	cout.width(30);
	cout << left << "|\t7. Номер зачётной книжки: ";
	cout << "|\t" << studentbook_number.student_book_number;
	cout.width(63 - studentbook_number.student_book_number.length());
	cout << right << "|" << endl;
	cout.width(30);
	cout << left << "|\t8. Пол: ";
	cout << "|\t" << sex.sex;
	cout.width(63 - sex.sex.length());
	cout << right << "|" << endl;
	line();
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
					cout << right << "|" << endl;

				}
				// пустая запись (закончились)
				else { break; }
			}
		}
		// нет данных о сессиях
		else {
			cout << "нет данных";
			cout.width(63 - 20);
			cout << right << "|" << endl;
		}
	}
	line();
	cout << endl << endl;
}


// запись данных (одной записи) в файл
void Student::writeIntoFile(Fio fio_, BirthDate birth_date_, AdmissionYear admission_year_, Faculty faculty_,
						   Department department_, Group group_, StudentBookNumber studentbook_number_,
						   Sex sex_, Session session_) {
	ofstream file("StudentsData.txt", ios_base::app);
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
		cout << "Файл не открыт!" << endl;
		return;
	}
	else {
		while (getline(file, buffer, '\n')) {
			// в файл записываются неиницализированные значения. этот блок просто не читает их
			// костыли? ну а что поделать. так и живём		||		кроме шуток, я 2 дня пытался пофиксить эту ошибку, поэтому даже такое решение меня устраивает
			if (buffer[0] == ':' && buffer[1] == '-') { continue; }
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
					birth_date.day = stoi(buffer);
					break;
				case 4:
					birth_date.month = stoi(buffer);
					break;
				case 5:
					birth_date.year = stoi(buffer);
					break;
				case 6:
					admission_year.admission_year = stoi(buffer);
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
					if (buffer.length() == 1) { session_num = stoi(buffer); }
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
				setMean();
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
		number = -1;
		cout << "Пока не кого отчислять :(" << endl;
	}
	else {
		while (true) {
			// выводим компактно студентов для более лёгкой ориетации в программе
			for (int i = 0; i < student_count; i++) {
				student[i].printCompact(i);
			}
			cout << endl;
			cout << "Введите порядковый номер (на рукаве) студента: ";
			number = getDigit("Введите порядковый номер (на рукаве) студента: ");
			system("cls");
			if (checkForValue(1, number, student_count)) {
				number--;
				break;
			}
		}
		system("cls");

		cout << "Подождите, идёт запись данных в файл . . .";
		// очищаем файл перед записью всех "сдвинутых" значений
		Decrypt();
		ofstream file("StudentsData.txt", ios_base::trunc);
		file.close();
		for (int i = 0; i < student_count; i++) {
			if (i != number) {
				writeIntoFile(student[i].fio, student[i].birth_date, student[i].admission_year, student[i].faculty, student[i].department, student[i].group, student[i].studentbook_number, student[i].sex, student[i].session);
			}
		}
		Crypt();
		system("cls");
		cout << "Данные успешно обновлены!" << endl;
	}
	cout << "Для продолжения нажмите любую клавишу...";
	_getch();
	system("cls");
	return number;
}


// изменение данных студента
void Student::editStudent(Student* student, int student_count) {
	if (student_count == 0) { cout << "Тут что-то пусто. Для начала, добавьте студентов" << endl; }
	else {
		int requred_student, parameter;
		while (true) {
			for (int i = 0; i < student_count; i++) {
				student[i].printCompact(i);
			}
			cout << endl;
			cout << "Введите порядковый номер (на рукаве) студента, данные которого хотите изменить: ";
			requred_student = getDigit("Введите порядковый номер (на рукаве) студента, данные которого хотите изменить: ");
			if (checkForValue(1, requred_student, student_count)) {	break; }
		}
		// уменьшаем на 1, потому что работаем с индексами
		requred_student--;
		system("cls");

		while (true) {
			cout << "Теперь введите номер параметра, который хотите изменить.\nПодсказка:\n1-фамилия\n2-имя\n3-отчество\n4-дата рождения\n5-год поступления\n6-факультет\n7-кафедра\n8-группа\n9-номер зачётной книжки\n10-пол\n11-данные о сессии\n\nВаш выбор: ";
			parameter = getDigit("Теперь введите номер параметра, который хотите изменить.\nПодсказка:\n1-фамилия\n2-имя\n3-отчество\n4-дата рождения\n5-год поступления\n6-факультет\n7-кафедра\n8-группа\n9-номер зачётной книжки\n10-пол\n11-данные о сессии\n\nВаш выбор: ");
			if (checkForValue(1, parameter, 11)) { break; }
		}
		system("cls");

		switch (parameter) {
		case 1:
			student[requred_student].setSurname();
			break;
		case 2:
			student[requred_student].setName();
			break;
		case 3:
			student[requred_student].setPatronymic();
			break;
		case 4:
			student[requred_student].setBirthDate();
			break;
		case 5:
			student[requred_student].setAdmissionYear();
			break;
		case 6:
			student[requred_student].setFaculty();
			break;
		case 7:
			student[requred_student].setDepartment();
			break;
		case 8:
			student[requred_student].setGroup();
			break;
		case 9:
			student[requred_student].setStudentbookNumber();
			break;
		case 10:
			student[requred_student].setSex();
			break;
		case 11:
			student[requred_student].editStudentSession(requred_student);
			setMean();
			break;
		default:
			cout << "Произошла непредвиденная ошибка!";
		}

		cout << "Подождите, идёт запись данных в файл . . .";
		// очищаем файл перед записью всех "сдвинутых" значений
		Decrypt();
		ofstream file("StudentsData.txt", ios_base::trunc);
		file.close();
		for (int i = 0; i < student_count; i++) {
			writeIntoFile(student[i].fio, student[i].birth_date, student[i].admission_year, student[i].faculty, student[i].department, student[i].group, student[i].studentbook_number, student[i].sex, student[i].session);
		}
		Crypt();
		system("cls");
		cout << "Данные успешно обновлены!" << endl;
	}
	cout << "Для продолжения нажмите любую клавишу...";
	_getch();
	system("cls");
}


// изменение и переход к удалению сессии студента
void Student::editStudentSession(int required_student) {
	int choose, session_num, subject_num, num_subj_in_session, new_mark;
	string new_subject;
	printStudent(required_student);
	cout << "Введите:" << endl <<
		"\"1\", чтобы добавить новую запись" << endl <<
		"\"2\", чтобы изменить существующую запись" << endl <<
		"\"3\", чтобы удалить существующую запись" << endl << endl <<
		"Ваш выбор: ";
	while (true) {
		choose = getDigit("Введите:\n\"1\", чтобы добавить новую запись\n\"2\", чтобы изменить существующую запись\n\"3\", чтобы удалить существующую запись\n\nВаш выбор: ");
		if (checkForValue(1, choose, 3)) { break; }
	}
	system("cls");

	// добавить новую запись
	if (choose == 1) {
		setSession();
	}

	// изменить существующую запись
	else if (choose == 2) {
		// получаем номер сессии
		printStudent(required_student);
		cout << "Введите номер сессии, данные которой вы хотите изменить: ";
		while (true) {
			session_num = getDigit("Введите номер сессии, данные которой вы хотите изменить: ");
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
			if (checkForValue(1, subject_num, num_subj_in_session)) { break; }
		}
		system("cls");

		// получаем новое название предмета
		cout << "Введите название предмета: ";
		cin >> new_subject;

		// получаем  новую оценку
		cout << "Теперь введите оценку для предмета." << endl <<
			"0 - незачёт" << endl <<
			"1 - зачёт" << endl <<
			"2 - неудовлетворительно" << endl <<
			"3 - удовлетворительно" << endl <<
			"4 - хорошо" << endl <<
			"5 - отлично" << endl << endl <<
			"Ваш выбор : ";
		while (true) {
			new_mark = getDigit("Теперь введите оценку для предмета.\n0-незачёт\n1-зачёт\n2-неудовлетворительно\n3-удовлетворительно\n4-хорошо\n5-отлично\n\nВаш выбор: ");
			if (checkForValue(0, new_mark, 5)) { break;	}
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


// удаление сессии
void Student::deleteSession(int required_student) {
	int session_num, subject_num, num_subj_in_session;
	printStudent(required_student);
	cout << "Введите номер сессии, данные которой вы хотите удалить: ";
	while (true) {
		session_num = getDigit("Введите номер сессии, данные которой вы хотите удалить: ");
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
		if (checkForValue(1, subject_num, num_subj_in_session)) { break; }
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