﻿/*
Основной файл курсовой работы
*/

#include <iostream> // ввод-вывод
#include <Windows.h> // локализация ввода-вывода
#include <conio.h> // для _getch()

#include "Functions.h"
#include "Student.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	int student_count = getAmountOfStudents();

	// создаём динамический массив
	Student* student = new Student[student_count];

	initStudent(student, student_count);

	while (true) {
		int action = mainMenu();
		switch (action)	{
		case 1: {
			// создаём новый динамический массив, отличный от прошлого на +1
			Student * new_student = new Student[student_count + 1];
			// перекидываем значения из первого во второй
			for (int i = 0; i < student_count; i++) { new_student[i] = student[i]; }
			// добавляем новое в конец
			new_student[student_count].addStudent();
			// удаляем предидущий массив
			delete[] student;
			// заменяем указатель
			student = new_student;
			student_count++;
		}
		break;
		case 2:
			for (int i = 0; i < student_count; i++) {
				student[i].printStudent(i);
			}
			cout << "Для продолжения нажмите любую клавишу...";
			_getch();
			system("cls");
			break;
		case 3:
			student->editStudent(student, student_count);
			break;
		case 4: {
			// флаг, показывающий, был ли индекс элемента, который необходимо удалить
			bool flag = false;
			int num_to_delete = student->deleteStudent(student, student_count);
			// deleteStudent возвращает "-1", если нет людей для отчисления
			if (num_to_delete != -1) {
				Student* new_student = new Student[student_count - 1];
				for (int i = 0; i < student_count; i++) {
					if (i == num_to_delete) { flag = true; }
					else if (!flag) {
						new_student[i] = student[i];
					}
					else if (flag) {
						new_student[i - 1] = student[i];
					}
				}
				delete[] student;
				student = new_student;
				student_count--;
			}
		}
		break;
		case 5:
			task(student);
			break;
		case 6:
			cout << "Конец работы программы" << endl << endl;
			// эти строки не играют роли, но для better coding'а я следую правилу "написал new – освободи память"
			delete[] student;
			student = nullptr;
			return 0;
		// в идеале, этот блок никогда не должен срабатывать, потому что есть checkForValue()
		default:
			cout << "Произошла непредвиденная ошибка";
			return 404;
		}
	}
}