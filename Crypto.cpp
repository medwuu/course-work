/*
Файл с функциями шифрования и дешифрования файла StudentsData.txt
*/

#include <iostream> // ввод-вывод
#include <string> // для операций со стринга́ми
#include <time.h> // для генерации случайного числа с зависимостью от времени
#include <fstream> // чтение-запись из/в файл

/*
!!!    для корректной работы именно вашей программы, замените "StudentsData.txt" (ниже) на название своей БД    !!!
 после проделанных действий программа при первом запуске выведет пару ошибок в консоль, а при дальнейших запусках не будет
 */
#define FILENAME "StudentsData.txt"

using namespace std;

// зашифровать файл
void Crypt() {
	// тут генерируется пароль для шифрования базы данных
	srand(time(NULL));
	char pass[65];
	for (int i = 0; i < 64; ++i) {
		switch (rand() % 3) {
		case 0:
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
			break;
		}
	}
	pass[64] = '\0';
	// шифруем базу данных с помощью сгенерированного пароля
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in ";
	command += FILENAME;
	command += " -out ";
	command += FILENAME;
	command += ".enc -pass pass:\"";
	command += pass;
	command += "\" -pbkdf2";
	system(command.c_str());
	// удаляем незашифрованный файл
	if (remove(FILENAME) != 0) {
		cout << "[ERROR] - deleting " << FILENAME << endl;
	}
	// открываем и записываем в key.txt сгенерированный ключ, которым шифровали базу данных
	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 65);
	file.close();
	// шифруем key.txt с помощью ключа "rsa.public"
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());
	// удаляем незашифрованный файл
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting key.txt" << endl;
	}
}

// расшифровать файл
void Decrypt() {
	// расшифровываем файл key.txt с помощью "rsa.private"
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());
	// удаляем зашифрованный файл
	if (remove("key.txt.enc") != 0) {
		cout << "[ERROR] - deleting key.txt.enc" << endl;
	}
	// открываем key.txt и считываем ключ для расшифровки базы данных
	char pass[65];
	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 65);
	file.close();
	pass[64] = '\0';
	// удаляем файл с ключом
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting key.txt" << endl;
	}
	// расшифровываем базу данных
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in ";
	command += FILENAME;
	command += ".enc -out ";
	command += FILENAME;
	command += " -pass pass:\"";
	command += pass;
	command += "\" -pbkdf2";
	system(command.c_str());
	// удаляем зашифрованную базу данных
	string to_delete = FILENAME;
	to_delete += ".enc";
	if (remove(to_delete.c_str()) != 0) {
		cout << "[ERROR] - deleting " << FILENAME << ".enc" << endl;
	}
}