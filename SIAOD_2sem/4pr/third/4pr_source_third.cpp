#include <iostream>
#include <vector>
#include <string>
#include "4pr_header_third.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	typeX matrix(50);

	cout << "Введите количество вершин первого многоугольника: ";
	int n1; cin >> n1;
	Figure polygon1(n1);
	inputFigure(&polygon1);

	cout << "Введите количество вершин второго многоугольника: ";
	int n2; cin >> n2;
	Figure polygon2(n2);
	inputFigure(&polygon2);

	draw_points(&matrix, &polygon1);
	draw_points(&matrix, &polygon2);

	output_matrix(&matrix);

	cout << "Точки первой фигуры: " << endl;
	outputFigure(&polygon1);
	cout << "Точки второй фигуры: " << endl;
	outputFigure(&polygon2);

	cout << "Площадь первой фигуры: " << polygonArea(&polygon1) << endl;
	cout << "Площадь второй фигуры: " << polygonArea(&polygon2) << endl;

	cout << "Первая фигура вложена во вторую: " << isPolygonInside(&polygon2, &polygon1)<<endl;
	cout << "Вторая фигура вложена в первую: " << isPolygonInside(&polygon1, &polygon2) << endl;

	return 0;
}