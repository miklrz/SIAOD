#include "header_3_dynamic.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int choice;
	int n;
	cout << "Введите длину массива: "; cin >> n;
	typeX arr(n);
	typeX new_arr(0);
	inputArr(&arr);
	int num; cout << "Введите элемент для вставки: "; cin >> num;

	do {
		cout << "Меню\n1. Вывести массив\n2. Найти позицию элемента массива, являющегося простым числом\n";
		cout << "3. Вставить новый элемент в массив в позицию, следующую за первым простым числом в массиве\n4. Удалить каждый элемент массива, который кратен 7\n";
		cout << "5. Сформировать новый массив из простых чисел исходного массива.\n6. Вывести новый массив на экран\n0. Выйти\n";
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