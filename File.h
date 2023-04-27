/*
Здесь происходит запись и чтение данных из файла
*/

#pragma once
#include <fstream>

using namespace std;



// костылии
int writeIntoFile(string surname_, string name_, string patronymic_, unsigned short birth_date_day_,
				  unsigned short birth_date_month_, unsigned short birth_date_year_, unsigned short admission_year_,
				  string faculty_, string department_, string group_, string studentbook_number_, string sex_) {
	ofstream file("StudentsData.txt", ios_base::app);
	// TODO: обрабатывать эту ошибку
	if (!file.is_open()) {
		cout << "Файл не открыт!";
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
	file.close();
}