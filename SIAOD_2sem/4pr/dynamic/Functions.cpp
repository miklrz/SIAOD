#include <iostream>
#include "Header.h"
using namespace std;

void inputMatrix(typeX* matrix) {
	cout << "n: "; cin >> matrix->n;
	cout << "m: "; cin >> matrix->m;
	for (int i = 0; i < matrix->n; ++i) {
		for (int j = 0; j < matrix->m; ++j) {
			cout << i << " " << j << " элемент матрицы: ";
			cin >> matrix->x[i][j];
		}
	}
}