#pragma once

typedef unsigned int typeitem;
const unsigned int N = 100;

struct typeX {
	unsigned int n = 0;
	typeitem x[N] = {};
};

bool isPrime(int n);
void inputArr(typeX* arr);
void getArr(typeX* arr);
void putItem(typeX* arr);
