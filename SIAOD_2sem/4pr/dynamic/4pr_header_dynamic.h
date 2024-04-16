#pragma once

typedef unsigned int typeitem;
const unsigned int N = 100;

struct typeX {
	unsigned int n;
	unsigned int m;
	typeitem** x;
	typeX(int rows, int cols) {
		n = rows;
		m = cols;
		x = new typeitem * [n];
		for (int i = 0; i < n; ++i) {
			x[i] = new typeitem[m];
		}
	}
};

void inputMatrix(typeX* matrix);
