#include "header_3_vec.h"
#include <iostream>

using namespace std;


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

bool isPrime(int n) {
	for (int i = 2; i < int(sqrt(n) + 1); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int findPrime(typeX* arr) {
	for (int i = 0; i < arr->n; ++i) {
		if (isPrime(arr->x[i])) return i;
	}
	return -1;
}

void putItem(typeX* arr, int num) {
	int index = findPrime(arr);
	arr->n++;
	arr->x.insert(arr->x.begin() + index + 1, num);
}

void delSeven(typeX* arr) {
	for (int i = 0; i < arr->n; ++i) {
		if (arr->x[i] % 7 == 0) {
			arr->x.erase(arr->x.begin() + i);
			--arr->n;
			i--;
		}
	}
}