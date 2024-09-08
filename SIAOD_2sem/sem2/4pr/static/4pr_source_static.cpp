#include <iostream>
#include "4pr_header_static.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	typeX matrix;
	inputMatrix(&matrix);
	int choice;
	do {
		cout << "Перечень операций:\n1. Вывести матрицу\n2. Транспонировать матрицу\n3. Закончить выполнение программы\nВыберите операцию: ";
		cin >> choice;
		switch (choice) {
		case(1):
			cout << "Матрица: " << endl;
			printMatrix(&matrix);
			break;
		case(2):
			transposition(&matrix);
			break;
		case(3):
			cout << "Выход из программы!";
			break;
		}
	} while (choice != 3);
	return 0;
}

