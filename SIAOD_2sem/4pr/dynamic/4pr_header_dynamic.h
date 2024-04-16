#pragma once

typedef unsigned int typeitem;
const unsigned int N = 100;

struct typeX {
	unsigned int n;
	unsigned int m;
	typeitem** arr;
	typeX(int n, int m) {
		this->n = n;
		this->m = m;
		arr = new typeitem * [n];
		for (int i = 0; i < n; ++i) {
			arr[i] = new typeitem[m];
		}
	}
};

void inputMatrix(typeX* matrix);
void printMatrix(typeX* matrix);
void transposition(typeX* matrix);

