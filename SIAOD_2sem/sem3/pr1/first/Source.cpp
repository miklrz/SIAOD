#include "Header.h"

int a(int x) {
	unsigned char x = 255; //8-разрядное двоичное число 11111111 
	unsigned char maska = 1; //1=00000001 – 8-разрядная маска 
	x = x & (~ (maska<<4)); //результат x=239
	return x;
}

int b(int x, int bit) {
	unsigned int x = 255;
	unsigned int maska = 1;
	x = x & (~(maska << (bit-1)));
	return x;
}

int c() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int x = 25;
	const int n = sizeof(int) * 8;
	unsigned maska = (1 << n - 1);
	cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
	cout << "Результат: ";
	for (int i = 1; i <= n; i++) {
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1;
	}
	cout << endl;
	system("pause");
	return 0;
}