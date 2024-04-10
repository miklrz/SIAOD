#pragma once

typedef unsigned int typeitem;
const unsigned int N = 100;

struct typeX {
	unsigned int n;
	unsigned int m;
	typeitem x[N][N] = { {} };
};

void inputMatrix(typeX* matrix);
void printMatrix(typeX* matrix);
void transposition(typeX* matrix);
