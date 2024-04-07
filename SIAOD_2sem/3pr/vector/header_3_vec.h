#pragma once

#include<vector>
using namespace std;

typedef unsigned int typeitem;

struct typeX {
	unsigned int n = 0;
	std::vector<typeitem> x;
	typeX(int n1) {
		n = n1;
		x.resize(n1);
	}
	typeX() { n = 0; }
};

bool isPrime(int n);
void inputArr(typeX* arr);
void getArr(typeX* arr);
void putItem(typeX* arr, int num);
void delSeven(typeX* arr);
void inputNumber(typeX* arr, int pos, int num);
void deleteNumber(typeX* arr, int pos);
int findPrime(typeX* arr);