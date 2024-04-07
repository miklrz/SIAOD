#include "header_3_dynamic.h"
#include <iostream>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i < int(sqrt(n) + 1); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void inputArr(typeX* arr) {
	for (int i = 0; i < arr->n; ++i) {
		cout << "Введите " << i << " значение массива : ";
		cin >> arr->x[i];
	}
}

void getArr(typeX* arr) {
	cout << "Массив: ";
	for (int i = 0; i < arr->n; ++i) {
		cout << arr->x[i] << " ";
	}
	cout << "\n";
}

void putItem(typeX* arr, int num) {
	int index = findPrime(arr);
	inputNumber(arr, index + 1, num);
}

void delSeven(typeX* arr) {
	for (int i = 0; i < arr->n; ++i) {
		if (arr->x[i] % 7 == 0) {
			deleteNumber(arr, i);
			i--;
		}
	}
}
//----
void inputNumber(typeX* arr, int pos, int num) {
	arr->n++;
	typeitem* newPtr = (typeitem*)realloc(arr->x, (arr->n + 1) * sizeof(typeitem));
	if (newPtr != nullptr) {
		arr->x = newPtr;
	}
	else {
		cout << "NullPTR";
	}
	for (int i = arr->n - 1; i > pos; i--) {
		arr->x[i] = arr->x[i - 1];
	}
	arr->x[pos] = num;
}

void deleteNumber(typeX* arr, int pos) {
	for (int i = pos; i < arr->n; ++i) {
		arr->x[i] = arr->x[i + 1];
	}
	typeitem* newPtr = (typeitem*)realloc(arr->x, (arr->n - 1) * sizeof(typeitem));
	--arr->n;
	if (newPtr != nullptr) {
		arr->x = newPtr;
		cout << "1" << " ";
	}
	else {
		arr->x = nullptr;
	}
}

int findPrime(typeX* arr) {
	for (int i = 0; i < arr->n; ++i) {
		if (isPrime(arr->x[i])) return i;
	}
	return -1;
}
