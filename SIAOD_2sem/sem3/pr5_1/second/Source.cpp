#include "Header.h"

void a() { 
	int n, num; cin >> n; // n - количество чисел, num - следующее число набора
	unsigned char mask = 0; // 00000000
	for (int i = 0; i < n; i++) {
		cin >> num;
		mask |= (1 << num); // установка в 1 num-ого бита 
	}
	cout << "bitset: " << bitset<8>(mask) << endl; // вывод маски при помощи bitset
	cout << "result: ";
	for (int i = 0; i < 8; i++) { // вывод остортированного набора
		if ((mask & 1) == 1) cout << i << " "; 
		mask >>= 1;
	}
}

void b() {
	int n, num; cin >> n;
	unsigned long long mask, mask_ = 0; // mask_ добавлена чтобы избежать переполнения
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	}
	for (int i = 0; i < n; i++) {
		mask = 1;
		mask = (mask << arr[i]);
		mask_ |= mask;
	}
	cout << "bitset: " << bitset<64>(mask_) << endl;
	for (int i = 0; i < 64; i++) {
		if ((mask_ & 1) == 1) cout << i << " ";
		mask_ >>= 1;
	}
}

void c() {
	int n, num; cin >> n; // Переполнения не будет, следовательно переменная mask_ не нужна
	unsigned char mask = 1;
	cin >> n;
	vector<unsigned char> arr(8); // Вектор разбивается на 8 частей и в сумме могут быть использованы 64 бита. 
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num / 8] |= (mask << num % 8);
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((arr[i] & 1) == 1) {
				cout << 8 * i + j << " ";
			}
			arr[i] >>= 1;
		}
	}
}

