#include "7-header-2.h"

int main() {
	setlocale(LC_ALL, "rus");
	LinkedList lst;
	int choice;
	do {
		cout << "������ ��������:\n1. ������� ���������� ��������\n2. ������� ������\n3. �������� ����� ����\n0. ����� �� ���������\n�������� ��������: ";

		cin >> choice;
		switch (choice) {
		case(1):
			int count; cout << "������� ���������� �������: "; cin >> count;
			createList(&lst, count);
			break;
		case(2):
			printList(&lst);
			break;
		case(3):
			Node* node = new Node;
			cout << "������� ����� �������� ������ ������ ����: "; cin >> node->keyNumber;
			cout << "������� ������ ������ ����: "; cin >> node->group;
			cout << "������� ���������� ������ ����: "; cin >> node->subject;
			cout << "������� ������ ������ ����: "; cin >> node->grade;
			insertBefore(&lst, node);
			break;
		}
	} while (choice != 0);
}