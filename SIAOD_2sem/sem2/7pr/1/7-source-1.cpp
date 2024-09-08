#include "7-header-1.h"

int main() {
	setlocale(LC_ALL, "rus");
	LinkedList L1;
	LinkedList L2;
	LinkedList L;
	int choice;
	do {
		cout << "Список операций:\n1. Создать списки L1 и L2\n2. Вывести списки\n3. Вставить новый узел в L1\n4. Вставить новый узел в L2\n5. Создать список L из L1 и L2\n6. Удалить из L1 все узлы в четных позициях\n7. Вставить суммы чисел в L2\n0. Выйти из программы\nВыберите операцию: ";

		cin >> choice;
		switch (choice) {
		case(1):
			cout << "Введите размер списка L1: "; int count1; cin >> count1;
			createList(&L1, count1);
			cout << "Введите размер списка L2: "; int count2; cin >> count2;
			createList(&L2, count2);
			break;
		case(2):
			cout << "Список L1:\n";
			printList(&L1);
			cout << "Список L2:\n";
			printList(&L2);
			cout << "Список L:\n";
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