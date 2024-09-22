#include "Header.h"

void a() {
	int n, num; cin >> n;
	unsigned char mask = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		mask |= (1 << num);
	}
	cout << "bitset: " << bitset<8>(mask) << endl;
	cout << "result: ";
	for (int i = 0; i < 8; i++) {
		if ((mask & 1) == 1) cout << i << " ";
		mask >>= 1;
	}
}

void b() {
	int n, num; cin >> n;
	unsigned long long mask, mask_ = 0;
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
		if ((mask & 1) == 1) cout << i << " ";
		mask_ >>= 1;
	}
}