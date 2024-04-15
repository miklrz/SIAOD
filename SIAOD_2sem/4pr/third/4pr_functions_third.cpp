#include "4pr_header_third.h"
#include <iostream>

using namespace std;

void inputFigure(Figure* polygon) {
	for (int i = 0; i < polygon->n; ++i) {
		double x,  y; 
		cin >> x >> y;
		polygon->x.push_back(Point(x, y));
	}
}

void outputFigure(Figure* polygon) {
	for (int i = 0; i < polygon->n; ++i) {
		cout << i << ": x: " << polygon->x[i].x << " y: " << polygon->x[i].y << endl;
	}
}

double polygonArea(Figure* polygon) {
	int n = polygon->x.size();
	double area = 0.0;
	for (int i = 0; i < n; ++i) {
		area += polygon->x[i].x * polygon->x[(i + 1) % n].y - polygon->x[(i + 1) % n].x * polygon->x[i].y;
	}
	return abs(area) / 2.0;
}

bool isPolygonInside(Figure* outer, Figure* inner) {
	for (Point point : inner->x) {
		bool inside = false;
		for (int i = 0, j = outer->x.size() - 1; i < outer->x.size(); j = i++) {
			if ((outer->x[i].y > point.y) != (outer->x[j].y > point.y) &&
				point.x < (outer->x[j].x - outer->x[i].x) * (point.y - outer->x[i].y) / (outer->x[j].y - outer->x[i].y) + outer->x[i].x) {
				inside = !inside;
			}
		}
		if (!inside) return false;
	}
	return true;
}