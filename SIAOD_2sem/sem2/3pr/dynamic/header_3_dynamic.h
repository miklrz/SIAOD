#pragma once

using namespace std;
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int typeitem;

struct typeX {
	unsigned int n = 0;
	typeitem* x = nullptr;
	typeX(int n1) {
		n = n1;
		x = (typeitem*)malloc(n * sizeof(typeitem));
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
void createNewArr(typeX arr, typeX* new_arr);

