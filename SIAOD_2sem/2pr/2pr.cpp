#include <iostream>
#include <math.h>
#include <vector>
#include "2pr.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	
	typeX arr;
	int choice;

	inputArr(&arr);

	do {
		cout << "Меню\n1. Вывести массив\n2. Найти позицию элемента массива, являющегося простым числом\n";
		cout << "3. Вставить новый элемент в массив в позицию, следующую за первым простым числом в массиве\n4. Удалить каждый элемент массива, который кратен 7\n";
		cout << "0. Выйти\n";
		cout << "Выберите операцию: ";
		cin >> choice;
		switch (choice) {
		case(0):
			cout << "Вы вышли из программы";
			break;
		case(1):
			getArr(&arr);
			break;
		case(2):
			cout << "Позиция элемента массива, являющегося простым числом: " << findPrime(&arr) << endl;
		case(3):
			putItem(&arr);
		case(4):
			delSeven(&arr);
		}
	} while (choice != 0);
	return 0;
}	
