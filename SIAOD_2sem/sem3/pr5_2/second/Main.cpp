#include "Header.h" 

int main() {
	setlocale(LC_ALL, "rus");

	string textFilename = "text.txt";
	string binaryFilename = "binary.bin";

	int fileLen = 100;

	auto start = chrono::high_resolution_clock::now();
	createTextFile(textFilename, fileLen);
	createBinaryFile(textFilename, binaryFilename);
	auto end = chrono::high_resolution_clock::now();

	cout << "Данные записаны в бинарный файл для " << fileLen << " записей" << endl;
	chrono::duration<double, milli> duration = end - start;
	cout << "Время создания " << duration.count() << " мс" << endl;

	string randomPhoneNumber = getRandomPhoneNumber(textFilename, fileLen);
	cout << "Поиск человека с номером телефона: " << randomPhoneNumber << endl;

	start = chrono::high_resolution_clock::now();
	PhoneNumberOwner foundOwner = linearSearch(binaryFilename, randomPhoneNumber);
	end = chrono::high_resolution_clock::now();
	cout << "Время поиска " << duration.count() << " мс" << endl;

	if (!foundOwner.phoneNumber.empty()) {
		cout << "Найден владелец телефона: " << foundOwner.phoneNumber << " \nС адресом: " << foundOwner.address << endl;
	}
	else {
		cout << "Владелец телефона не найден";
	}

	duration = end - start;


	//auto start = chrono::high_resolution_clock::now();
	//createTextFile(textFilename, 100);
	//createBinaryFile(textFilename, binaryFilename);
	//auto end = chrono::high_resolution_clock::now();
	//int execTime = (end - start).count();
	//
	//cout << "Успешная запись в бинарный файл!\nTime: " << execTime << " millis";
}