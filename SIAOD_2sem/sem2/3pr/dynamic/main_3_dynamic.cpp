#include "header_3_dynamic.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int choice;
	int n;
	cout << "������� ����� �������: "; cin >> n;
	typeX arr(n);
	typeX new_arr(0);
	inputArr(&arr);
	int num; cout << "������� ������� ��� �������: "; cin >> num;

	do {
		cout << "����\n1. ������� ������\n2. ����� ������� �������� �������, ����������� ������� ������\n";
		cout << "3. �������� ����� ������� � ������ � �������, ��������� �� ������ ������� ������ � �������\n4. ������� ������ ������� �������, ������� ������ 7\n";
		cout << "5. ������������ ����� ������ �� ������� ����� ��������� �������.\n6. ������� ����� ������ �� �����\n0. �����\n";
		cout << "�������� ��������: ";
		cin >> choice;
		switch (choice) {
		case(0):
			cout << "�� ����� �� ���������";
			break;
		case(1):
			getArr(&arr);
			break;
		case(2):
			cout << "������� �������� �������, ����������� ������� ������: " << findPrime(&arr) << endl;
			break;
		case(3):
			putItem(&arr, num);
			break;
		case(4):
			delSeven(&arr);
			break;
		case(5):
			createNewArr(arr, &new_arr);
			break;
		case(6):
			getArr(&new_arr);
			break;		
		}

	} while (choice != 0);
	return 0;
}