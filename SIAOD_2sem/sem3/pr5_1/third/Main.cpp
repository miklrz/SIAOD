#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;


void createFile() { // функция создания файла
	const long n = 1000000; // начало диапазона
	const long n_max = 9999999; // конец диапазона
	const int len = 10000; // количество элементов в диапазоне
	long* array = new long[len]; // динамическое выделение памяти для массива чисел

	for (long i = 0; i < len; i++) { // заполнение массива 
		array[i] = n + i; 
	}

	srand(time(NULL)); // Инициализация генератора случайных чисел текущим временем

	for (long i = 0; i < len; i++) { // Перемешивание массива с помощью случайных перестановок
		swap(array[i], array[rand() % len]);
	}

	ofstream fout; // Создание объекта для записи в файл
	fout.open("qwe.txt"); // Открытие файла для записи

	if (fout.is_open()) { // Запись в файл, если удалось его открыть
		for (int i = 0; i < len; i++) {
			cout << i;
			fout << array[i] << endl;
		}
	}
	else {
		cout << "error";
	}
	fout.close(); // Закрытие файла
	delete[] array; // освобождение памяти
}

int main() {
	//createFile();

	const int n = 10000000 / 8; // Определение количества байт для хранения данных
	int num; // Переменная для хранения чисел из файла
	auto start = chrono::high_resolution_clock::now(); // время начала выполнения программы

	unsigned char mask = 1; 
	vector <unsigned char> arr(n);

	string file = "qwe.txt"; 
	ifstream fin; 
	fin.open(file);

	if (fin.is_open()) { // чтение из файла если удалось его открыть
		fin >> num;
		arr[num / 8] |= (mask << num % 8); // установка соответствующего бита в массиве
	}

	fin.close();
	auto end = chrono::high_resolution_clock::now(); // время конца выполнения программы

	ofstream fout; // Создание потока для записи в файл
	fout.open(file);  // Открытие файла для записи
	if (fout.is_open()) { // Запись в файл, если его удалось открыть
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 8; j++) {
				if ((arr[i] & 1) == 1)
					fout << 8 * i + j << endl;  // Запись позиции установленного бита в файл
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