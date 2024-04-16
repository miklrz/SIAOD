#include <iostream>
#include <vector>
#include <string>
#include "4pr_header_third.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	typeX matrix(50);

	cout << "������� ���������� ������ ������� ��������������: ";
	int n1; cin >> n1;
	Figure polygon1(n1);
	inputFigure(&polygon1);

	cout << "������� ���������� ������ ������� ��������������: ";
	int n2; cin >> n2;
	Figure polygon2(n2);
	inputFigure(&polygon2);

	draw_points(&matrix, &polygon1);
	draw_points(&matrix, &polygon2);

	output_matrix(&matrix);

	cout << "����� ������ ������: " << endl;
	outputFigure(&polygon1);
	cout << "����� ������ ������: " << endl;
	outputFigure(&polygon2);

	cout << "������� ������ ������: " << polygonArea(&polygon1) << endl;
	cout << "������� ������ ������: " << polygonArea(&polygon2) << endl;

	cout << "������ ������ ������� �� ������: " << isPolygonInside(&polygon2, &polygon1)<<endl;
	cout << "������ ������ ������� � ������: " << isPolygonInside(&polygon1, &polygon2) << endl;

	return 0;
}