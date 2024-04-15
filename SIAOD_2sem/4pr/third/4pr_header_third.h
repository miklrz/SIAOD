#pragma once
#include <vector>

struct Point
{
	double x, y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point() {}
};

struct Figure {
	unsigned int n = 0;
	std::vector<Point> x;
	Figure(int n1) {
		n = n1;
		x.resize(n1);
	}
};

double polygonArea(Figure* polygon);
bool isPolygonInside(Figure* outer, Figure* inner);
void inputFigure(Figure* polygon);
void outputFigure(Figure* polygon);