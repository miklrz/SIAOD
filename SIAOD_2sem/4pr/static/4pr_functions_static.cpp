#include <iostream>
#include "4pr_header_static.h"
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
	typeX tempMatrix;
	tempMatrix.n = matrix->m;
	tempMatrix.m = matrix->n;
	for (int i = 0; i < matrix->n; ++i) {
		for (int j = 0; j < matrix->m; ++j) {
			tempMatrix.x[i][j] = matrix->x[j][i];	
		}
	}
	matrix->n = tempMatrix.n;
	matrix->m = tempMatrix.m;
	matrix = &tempMatrix;
}