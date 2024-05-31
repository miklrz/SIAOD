#include <iostream>
using namespace std;

void func(int arr[], int answ[], int n) {
	int sum_positive = 0;
	int count_negative = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) sum_positive += arr[i];
		else if (arr[i] < 0) count_negative++;
	}
	answ[0] = sum_positive;
	answ[1] = count_negative;
}

int main() {
	setlocale(LC_ALL, "rus");
	int arr[100]{};
	int answ[2]{};
	int n; cout << "Введите количество элементов в массиве: "; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	func(arr, answ, n);
	cout << "Сумма положительных чисел: " << answ[0] << endl;
	cout << "Количество отрицательных чисел: " << answ[1] << endl;
}