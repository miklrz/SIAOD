#include <iostream>
#include "4pr_header_static.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	typeX matrix;
	inputMatrix(&matrix);
	int choice;
	do {
		cout << "�������� ��������:\n1. ������� �������\n2. ��������������� �������\n3. ��������� ���������� ���������\n�������� ��������: ";
		cin >> choice;
		switch (choice) {
		case(1):
			cout << "�������: " << endl;
			printMatrix(&matrix);
			break;
		case(2):
			transposition(&matrix);
			break;
		case(3):
			cout << "����� �� ���������!";
			break;
		}
	} while (choice != 3);
	return 0;
}

