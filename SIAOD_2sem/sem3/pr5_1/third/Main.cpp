#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;


void createFile() { // ������� �������� �����
	const long n = 1000000; // ������ ���������
	const long n_max = 9999999; // ����� ���������
	const int len = 10000; // ���������� ��������� � ���������
	long* array = new long[len]; // ������������ ��������� ������ ��� ������� �����

	for (long i = 0; i < len; i++) { // ���������� ������� 
		array[i] = n + i; 
	}

	srand(time(NULL)); // ������������� ���������� ��������� ����� ������� ��������

	for (long i = 0; i < len; i++) { // ������������� ������� � ������� ��������� ������������
		swap(array[i], array[rand() % len]);
	}

	ofstream fout; // �������� ������� ��� ������ � ����
	fout.open("qwe.txt"); // �������� ����� ��� ������

	if (fout.is_open()) { // ������ � ����, ���� ������� ��� �������
		for (int i = 0; i < len; i++) {
			cout << i;
			fout << array[i] << endl;
		}
	}
	else {
		cout << "error";
	}
	fout.close(); // �������� �����
	delete[] array; // ������������ ������
}

int main() {
	//createFile();

	const int n = 10000000 / 8; // ����������� ���������� ���� ��� �������� ������
	int num; // ���������� ��� �������� ����� �� �����
	auto start = chrono::high_resolution_clock::now(); // ����� ������ ���������� ���������

	unsigned char mask = 1; 
	vector <unsigned char> arr(n);

	string file = "qwe.txt"; 
	ifstream fin; 
	fin.open(file);

	if (fin.is_open()) { // ������ �� ����� ���� ������� ��� �������
		fin >> num;
		arr[num / 8] |= (mask << num % 8); // ��������� ���������������� ���� � �������
	}

	fin.close();
	auto end = chrono::high_resolution_clock::now(); // ����� ����� ���������� ���������

	ofstream fout; // �������� ������ ��� ������ � ����
	fout.open(file);  // �������� ����� ��� ������
	if (fout.is_open()) { // ������ � ����, ���� ��� ������� �������
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 8; j++) {
				if ((arr[i] & 1) == 1)
					fout << 8 * i + j << endl;  // ������ ������� �������������� ���� � ����
				arr[i] >>= 1;
			}
		}
	}

	fout.close(); 
	chrono::duration<double, milli> duration = end - start;
	arr.shrink_to_fit();
	cout << arr.capacity() << " b\n";
	cout << arr.capacity() / 1024 << " kb\n";
	cout << arr.capacity() / (1024*1024) << " mb\n";
	cout << "time: " << duration.count() << "milliseconds";
}