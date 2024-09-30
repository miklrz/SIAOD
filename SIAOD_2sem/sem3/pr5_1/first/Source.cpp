#include "Header.h"

unsigned int a(unsigned int x) { // 1.а ”становка 5 бита в 0
	unsigned int maska = 1; // 1 = 00000001 - 8-разр€дна€ маска
	x = x & (~ (maska << 4));  
	return x;
}

unsigned int b(unsigned int x) { // 1.б ”становка 7-го бита в 1
	unsigned int maska = 1; // 1 = 00000001 - 8-разр€дна€ маска
	x = x | (maska << 6); 
	return x;
}

int c() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int x = 25; 
	const int n = sizeof(int) * 8; // 32 - количество разр€дов в числе целого типа
	unsigned maska = (1 << n - 1); // 1 в старшем бите 32-разр€дной сетки
	cout << "Ќачальный вид маски: " << bitset<n>(maska) << endl;
	cout << "–езультат: ";
	for (int i = 1; i <= n; i++) { // 32 итерации
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1; // сдвиг на разр€д вправо
	}
	cout << endl;
	system("pause");
	return 0;
}