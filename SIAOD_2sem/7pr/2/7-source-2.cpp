#include "7-header-2.h"

int main() {
	setlocale(LC_ALL, "rus");
	LinkedList lst;
	int choice;
	do {
		cout << "Список операций:\n1. Создать результаты экзамена\n2. Вывести список\n3. Вставить новый узел\n0. Выйти из программы\nВыберите операцию: ";

		cin >> choice;
		switch (choice) {
		case(1):
			int count; cout << "Введите количество зачеток: "; cin >> count;
			createList(&lst, count);
			break;
		case(2):
			printList(&lst);
			break;
		case(3):
			Node* node = new Node;
			cout << "Введите номер зачетной книжки нового узла: "; cin >> node->keyNumber;
			cout << "Введите группу нового узла: "; cin >> node->group;
			cout << "Введите дисциплину нового узла: "; cin >> node->subject;
			cout << "Введите оценку нового узла: "; cin >> node->grade;
			insertBefore(&lst, node);
			break;
		}
	} while (choice != 0);
}