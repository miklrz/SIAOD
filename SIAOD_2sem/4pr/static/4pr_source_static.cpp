#include <iostream>
#include "4pr_header_static.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	typeX type;
	inputMatrix(&type);
	printMatrix(&type);
	transposition(&type);
	cout << type.n << " " << type.m << " " << endl;
	printMatrix(&type);
	return 0;
}