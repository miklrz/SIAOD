#include "7-header-1.h"

int main() {
	setlocale(LC_ALL, "rus");
	LinkedList L1;
	LinkedList L2;
	LinkedList L;
	int choice;
	do {
		cout << "������ ��������:\n1. ������� ������ L1 � L2\n2. ������� ������\n3. �������� ����� ���� � L1\n4. �������� ����� ���� � L2\n5. ������� ������ L �� L1 � L2\n6. ������� �� L1 ��� ���� � ������ ��������\n7. �������� ����� ����� � L2\n0. ����� �� ���������\n�������� ��������: ";

		cin >> choice;
		switch (choice) {
		case(1):
			cout << "������� ������ ������ L1: "; int count1; cin >> count1;
			createList(&L1, count1);
			cout << "������� ������ ������ L2: "; int count2; cin >> count2;
			createList(&L2, count2);
			break;
		case(2):
			cout << "������ L1:\n";
			printList(&L1);
			cout << "������ L2:\n";
			printList(&L2);
			cout << "������ L:\n";
			printList(&L);
			break;
		case(3):
			addNode(&L1);
			break;
		case(4):
			addNode(&L2);
			break;
		case(5):
			createListFromTwo(&L, &L1, &L2);
			break;
		case(6):
			deleteEvenIndexes(&L1);
			break;
		case(7):
			insertSums(&L2);
			break;
		}
	} while (choice != 0);
}