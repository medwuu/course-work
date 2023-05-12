/*
Файл с дополнительными функциями
*/

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Functions.h"
#include "Crypto.h"

using namespace std;

// узнаём, сколько студентов в файле при запуске программы
int getAmountOfStudents() {
	string buffer;
	int count = 0;
	Decrypt();
	ifstream file("StudentsData.txt", ios_base::out);
	if (!file.is_open()) {
		cout << "Файл не открыт!\n";
		return 404;
	}
	while (getline(file, buffer, '\n')) {
		if (buffer == "=== END ===") {
			count++;
		}
	}
	file.close();
	Crypt();
	return count;
}

// проверяем, попадает ли введённое значение в нужный диапазон
bool checkForValue(int min, int value, int max) {
	if (min <= value && value <= max) {
		return true;
	}
	else {
		// звук ошибки windows
		cout << "\a";
		cout << "Введено неверное значение (" << value << ")! Введите число от " << min << " до " << max << "\n";
		cout << "Для продолжения нажмите любую клавишу...";
		_getch();
		system("cls");
		return false;
	}
}

// "умный" ввод только текста
string getAlpha(string whatToEnter) {
	string output = "";
	char letter = 0;
	while (letter != 13) {
		letter = _getch();
		// проверка на соответствие введённого символа большим или маленькими буквами английского, а затем русского алфавита
		if ((65 <= letter && letter <= 90) || (97 <= letter && letter <= 122) || (-200 <= letter && letter <= -1)) {
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

// "умный" ввод только цифр
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

// пузырьковая сортировка. используется для выполнения задания в task()
void bubbleSort(Student* student, int* &arr, int len)
{
	while (len--) {
		// менялись ли местами
		bool swapped = false;
		for (int i = 0; i < len; i++) {
			if (student[i].getMean() < student[i + 1].getMean()) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		// если уже всё отсортировано
		if (swapped == false)
			break;
	}
}

// выполнение 24 варианта
void task(Student* student) {
	// получаем год поступления, по которому будем сортировать
	int required_admission_year;
	cout << "Введите год поступления для сортировки: ";
	while (true) {
		required_admission_year = getDigit("Введите год поступления для сортировки: ");
		cout << "\n";
		if (checkForValue(1900, required_admission_year, 2022)) {
			break;
		}
	}
	system("cls");

	// создаём 2 динамических массива с индексами элементов, у которых год поступления совпадает или нет с тем, который ввёл пользователь
	int s_len = 0, us_len = 0, student_count = getAmountOfStudents();
	int* suitable = new int;
	int* unsuitable = new int;
	for (int i = 0; i < student_count; i++) {
		// записываем подходящих
		if (student[i].getAdmissionYear() == required_admission_year) {
			int* new_suitable = new int[s_len + 1];
			for (int j = 0; j < s_len; j++) { new_suitable[j] = suitable[j]; }
			new_suitable[s_len] = i;
			delete[] suitable;
			suitable = new_suitable;
			s_len++;
		}
		// а тут тех, кто не прошёл отбор ):
		else {
			int* new_unsuitable = new int[us_len + 1];
			for (int j = 0; j < us_len; j++) { new_unsuitable[j] = unsuitable[j]; }
			new_unsuitable[us_len] = i;
			delete[] unsuitable;
			unsuitable = new_unsuitable;
			us_len++;
		}
	}

	// сортируем оба массива по session.mean. массив меняется и в bubbleSort(), и здесь (потому что стоит "&" в принимаемых параметрах), поэтому bubbleSort возвращает void
	// решил сделать пузырьковую сортировку, потому что могу. вопросы?    ||    кроме шуток, такой способ лучше не использовать в реальных проектах, потому что он too slow
	bubbleSort(student, suitable, s_len);
	bubbleSort(student, unsuitable, us_len);
	
	// выводим отсортированный список студентов
	if (!s_len) { cout << "Нет студентов, поступивших в " << required_admission_year << " году!\n"; }
	else {
		cout << "Вот они: сверху вниз, студенты, поступившие в " << required_admission_year << " году:\n";
		for (int i = 0; i < s_len; i++) { student[suitable[i]].printStudent(i); }
	}
	cout << "\n";
	cout << "А вот студенты, поступившие в другие года:\n";
	for (int i = 0; i < us_len; i++) { student[unsuitable[i]].printStudent(i); }

	// очищаем динамические массивы и их указатели
	delete[] suitable; delete[] unsuitable;
	suitable = unsuitable = nullptr;

	cout << "Для продолжения нажмите любую клавишу . . .";
	_getch();
	system("cls");
}