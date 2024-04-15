#include <iostream>
#include <vector>
#include "4pr_header_third.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	cout << "¬ведите количество вершин первого многоугольника: ";
	int n1; cin >> n1;
	Figure polygon1(n1);
	inputFigure(&polygon1);

	cout << "¬ведите количество вершин второго многоугольника: ";
	int n2; cin >> n2;
	Figure polygon2(n2);
	inputFigure(&polygon2);
	
	outputFigure(&polygon1);
	outputFigure(&polygon2);

	return 0;
}