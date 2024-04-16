#pragma once
#include <vector>
#include <string>
using namespace std;

struct Point
{
	double x, y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Point() {
		x = 0;
		y = 0;
	}
};

struct Figure {
	unsigned int n = 0;
	std::vector<Point> x;
	Figure(int n1) {
		n = n1;
		x.resize(n1);
	}
};

struct typeX {
	vector<vector<string>> mat;
	int size;
	typeX(int n) : mat(n, vector<string>(n, " ")) {
		size = n;
		for (int i = 0; i < mat.size(); ++i) {
			for (int j = 0; j < mat[i].size(); j++) {
				if (i == n / 2) { mat[i][j] = "--"; }
				if (j == n / 2) { mat[i][j] = "|"; }
			}
		}
	}

};

double polygonArea(Figure* polygon);
bool isPolygonInside(Figure* outer, Figure* inner);
void inputFigure(Figure* polygon);
void outputFigure(Figure* polygon);
void draw_points(typeX* matrix, Figure* polygon);
void output_matrix(typeX* matrix);