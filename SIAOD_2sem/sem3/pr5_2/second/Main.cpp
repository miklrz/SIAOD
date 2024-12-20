#include "Header.h" 

int main() {
	setlocale(LC_ALL, "rus");

	string textFilename = "text.txt";
	string binaryFilename = "binary.bin";

	int fileLenArr[]{100, 1000, 10000};
	for (int fileLen : fileLenArr) {

		auto start = chrono::high_resolution_clock::now();
		createTextFile(textFilename, fileLen);
		createBinaryFile(textFilename, binaryFilename);
		auto end = chrono::high_resolution_clock::now();

		cout << "������ �������� � �������� ���� ��� " << fileLen << " �������" << endl;
		chrono::duration<double, milli> duration = end - start;
		cout << "����� �������� " << duration.count() << " ��" << endl;

		string randomPhoneNumber = getRandomPhoneNumber(textFilename, fileLen);
		cout << "����� �������� � ������� ��������: " << randomPhoneNumber << endl;

		start = chrono::high_resolution_clock::now();
		PhoneNumberOwner foundOwner = linearSearch(binaryFilename, randomPhoneNumber);
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		cout << "����� ������ " << duration.count() << " ��" << endl;

		if (!foundOwner.phoneNumber.empty()) {
			cout << "������ �������� ��������: " << foundOwner.phoneNumber << " \n� �������: " << foundOwner.address << endl;
		}
		else {
			cout << "�������� �������� �� ������";
		}
		cout << endl;
	}
	//auto start = chrono::high_resolution_clock::now();
	//createTextFile(textFilename, 100);
	//createBinaryFile(textFilename, binaryFilename);
	//auto end = chrono::high_resolution_clock::now();
	//int execTime = (end - start).count();
	//
	//cout << "�������� ������ � �������� ����!\nTime: " << execTime << " millis";
}