#include "Header.h" 

int main() {
	setlocale(LC_ALL, "rus");

	string textFilename = "text.txt";
	string binaryFilename = "binary.bin";

	int fileLen = 10000;

	createTextFile(textFilename, fileLen);

	vector<IndexEntry> index_table;

	createBinaryFile(textFilename, binaryFilename, index_table);

	sort(index_table.begin(), index_table.end()); // ���������

	string phoneNumberKey; cout << "������� ����� �������� ��� ������: "; cin >> phoneNumberKey;
	auto start = chrono::high_resolution_clock::now();

	streampos offset = binarySearch(index_table, phoneNumberKey);

	if (offset != -1) {
		PhoneNumberOwner foundOwner = readPhoneOwner(binaryFilename, offset);
		cout << "������ �������� ��������: " << foundOwner.phoneNumber << ", " << foundOwner.address << endl;
	}
	else {
		cout << "�������� ������ ��������: " << phoneNumberKey << " �� ������" << endl;
	}

	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;
	cout << "����� ������ " << duration.count() << " ��" << endl;
	return 0;
}