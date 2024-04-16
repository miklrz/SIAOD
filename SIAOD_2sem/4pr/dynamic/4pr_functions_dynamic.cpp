#include <iostream>
#include "4pr_header_dynamic.h"
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
void printMatrix(typeX* matrix) {
	for (int i = 0; i < matrix->n; ++i) {
		for (int j = 0; j < matrix->m; ++j) {
			cout << matrix->x[i][j] << " ";
		}
		cout << endl;
	}
}

void transposition(typeX* matrix) {
	typeX tempMatrix(matrix->n, matrix->m);
	for (int i = 0; i < matrix->m; ++i) {
		for (int j = 0; j < matrix->n; ++j) {
			tempMatrix.x[i][j] = matrix->x[j][i];
		}
	}
	matrix->n = tempMatrix.n;
	matrix->m = tempMatrix.m;
	for (int i = 0; i < matrix->n; ++i) {
		for (int j = 0; j < matrix->m; ++j) {
			matrix->x[i][j] = tempMatrix.x[i][j];
		}
	}
}