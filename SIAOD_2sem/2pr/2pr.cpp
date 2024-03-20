#include <iostream>
#include <math.h>
#include <vector>
#include "2pr.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	typeX arr;
	int choice;	
	int num; 

	cout << "������� ������� ��� �������: "; cin >> num;
	inputArr(&arr);

	do {
		cout << "����\n1. ������� ������\n2. ����� ������� �������� �������, ����������� ������� ������\n";
		cout << "3. �������� ����� ������� � ������ � �������, ��������� �� ������ ������� ������ � �������\n4. ������� ������ ������� �������, ������� ������ 7\n";
		cout << "0. �����\n";
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
		default:
			cout << "�������� ������, ���������� ��� ���\n";
			break;
		}
	} while (choice != 0);
	return 0;
}	
