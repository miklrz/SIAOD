#include "Header.h"

void createTextFile(const string& filename, int len) {
	ofstream ofstr;
	ofstr.open(filename);
	if(ofstr.is_open()){
		set<string> phoneNumbers;
		srand(time(0));
		for (int i = 0; i < len; i++) {
			int random_number = 100000 + rand() % 900000;
			string phoneNumber = "+" + to_string(random_number);
			phoneNumbers.insert(phoneNumber);
			if (phoneNumbers.size() != i + 1) {
				i--; continue;
			}
			string adress = "Country" + to_string(i + 1) + " City" + to_string(i + 1) + " Street" + to_string(i + 1);
			ofstr << phoneNumber << " " << adress << endl;
		}
		ofstr.close();
	}
	else {
		cout << "error";
	}
}

void createBinaryFile(const string& textFilename, const string& binaryFilename) {
	ifstream ifstr(textFilename); // Открываем текстовый файл для чтения
	ofstream ofstr(binaryFilename, ios::binary); // Открываем бинарный файл для записи
	PhoneNumberOwner phoneNumberOwner; // Переменная для хранения данных

	if (ifstr.is_open() && ofstr.is_open()) {
		while (ifstr >> phoneNumberOwner.phoneNumber) { // Считываем номер телефона
			getline(ifstr, phoneNumberOwner.address);   // Считываем оставшуюся строку (адрес)

			size_t phone_len = phoneNumberOwner.phoneNumber.size();
			size_t address_len = phoneNumberOwner.address.size();

			ofstr.write(reinterpret_cast<const char*> (&phone_len), sizeof(phone_len));
			ofstr.write(phoneNumberOwner.phoneNumber.c_str(), phone_len);

			ofstr.write(reinterpret_cast<const char*> (&address_len), sizeof(address_len));
			ofstr.write(phoneNumberOwner.address.c_str(), address_len);
		}
		// Закрываем файлы после завершения работы
		ifstr.close();
		ofstr.close();
	}
	else {
		cout << "Error opening files" << endl;
	}
}

PhoneNumberOwner linearSearch(const string& binaryFilename, string phoneNumberKey) {
	ifstream ifstr(binaryFilename, ios::binary);
	if (ifstr.is_open()) {
		PhoneNumberOwner phoneNumberOwner;
		while (true) {
			size_t numberLength;
			if (!ifstr.read(reinterpret_cast<char*>(&numberLength), sizeof(numberLength))) {
				break; 
			}
			phoneNumberOwner.phoneNumber.resize(numberLength);
			ifstr.read(&phoneNumberOwner.phoneNumber[0], numberLength);

			size_t addressLength;
			ifstr.read(reinterpret_cast<char*>(&addressLength), sizeof(addressLength));
			phoneNumberOwner.address.resize(addressLength);
			ifstr.read(&phoneNumberOwner.address[0], addressLength);
			if (phoneNumberOwner.phoneNumber == phoneNumberKey) {
				ifstr.close(); 
				return phoneNumberOwner;
			}
		}
		ifstr.close();
	}
	else {
		cout << "error";
	}
	ifstr.close();
	return {};
}

// фукнция возвращает случайный номер телефона, имеющийся в файле
// нужна для того, чтобы всегда находился пользователь с данным номером
string getRandomPhoneNumber(const string& textFilename, int fileLen) { 
	ifstream infile(textFilename);

	if (!infile.is_open()) {
		cout << "Error opening file" << endl;
		return ""; 
	}
	vector<PhoneNumberOwner> phoneOwners;
	PhoneNumberOwner phoneNumberOwner;

	while (infile >> phoneNumberOwner.phoneNumber) {
		getline(infile, phoneNumberOwner.address); // Считываем оставшуюся часть строки (адрес)
		phoneOwners.push_back(phoneNumberOwner); // Добавляем в вектор
	}

	infile.close();

	if (phoneOwners.empty()) {
		cout << "No records found" << endl;
		return ""; // Возвращаем пустую строку, если записи не найдены
	}

	srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
	int randomIndex = rand() % phoneOwners.size(); // Генерация случайного индекса

	return phoneOwners[randomIndex].phoneNumber; // Возвращаем случайный номер телефона
}