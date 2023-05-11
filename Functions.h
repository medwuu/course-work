/*
Файл с прототипами функций из Functions.cpp
*/

#pragma once

#include "Student.h"

int getAmountOfStudents();

bool checkForValue(int min, int value, int max);

std::string getAlpha(std::string whatToEnter);

int getDigit(std::string whatToEnter);

void task(Student* student);