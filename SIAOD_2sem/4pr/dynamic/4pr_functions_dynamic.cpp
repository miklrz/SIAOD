#include <iostream>
#include "4pr_header_dynamic.h"
using namespace std;

void inputMatrix(typeX* matrix) {
	cout << "n: "; cin >> matrix->n;
	cout << "m: "; cin >> matrix->m;
	for (int i = 0; i < matrix->n; ++i) {
		for (int j = 0; j < matrix->m; ++j) {
			cout << i << " " << j << " элемент матрицы: ";
			cin >> matrix->arr[i][j];
		}
	}
}

void printMatrix(typeX* matrix) {
	for (int i = 0; i < matrix->n; ++i) {
		for (int j = 0; j < matrix->m; ++j) {
			cout << matrix->arr[i][j] << " ";
		}
		cout << endl;
	}
}

void transposition(typeX* matrix) {
	typeX tempMatrix(matrix->m, matrix->n);
	for (int i = 0; i < matrix->m; ++i) {
		for (int j = 0; j < matrix->n; ++j) {
			tempMatrix.arr[i][j] = matrix->arr[j][i];
		}
	}
	matrix->n = tempMatrix.n;
	matrix->m = tempMatrix.m;
	matrix->arr = tempMatrix.arr;
}

