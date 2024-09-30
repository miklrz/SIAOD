#include "Header.h"

unsigned int a(unsigned int x) { // 1.� ��������� 5 ���� � 0
	unsigned int maska = 1; // 1 = 00000001 - 8-��������� �����
	x = x & (~ (maska << 4));  
	return x;
}

unsigned int b(unsigned int x) { // 1.� ��������� 7-�� ���� � 1
	unsigned int maska = 1; // 1 = 00000001 - 8-��������� �����
	x = x | (maska << 6); 
	return x;
}

int c() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	unsigned int x = 25; 
	const int n = sizeof(int) * 8; // 32 - ���������� �������� � ����� ������ ����
	unsigned maska = (1 << n - 1); // 1 � ������� ���� 32-��������� �����
	cout << "��������� ��� �����: " << bitset<n>(maska) << endl;
	cout << "���������: ";
	for (int i = 1; i <= n; i++) { // 32 ��������
		cout << ((x & maska) >> (n - i));
		maska = maska >> 1; // ����� �� ������ ������
	}
	cout << endl;
	system("pause");
	return 0;
}