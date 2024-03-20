#include <iostream>
#include <math.h>
#include "2pr.h"
using namespace std;

bool isPrime(int n) {
	for (int i = 2; i < int(sqrt(n) + 1); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void inputArr(typeX* arr) {
	cout << "Введите длину массива: "; cin >> arr->n;
	for (int i = 0; i < arr->n; ++i) {
		cout << "Введите "<< i <<" значение массива : ";
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

void putItem(typeX* arr) {
	cout << "Введите элемент для вставки: ";
	int num; cin >> num;
	int temp = -1;
	int _ = arr->n-1;
	for (int i = 0; i < arr->n; ++i) {
		if (isPrime(arr->x[i])) {
			cout << "\n" << i << "\n";
			temp = arr->x[i + 1];
			arr->x[i + 1] = num;
			_ = i + 2;
			arr->n++;
			break;
		}
	}
	for (int i = _; i < arr->n -1; ++i) {
		arr->x[i] = temp;
		temp = arr->x[i+1];
	}
}