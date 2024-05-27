#include "5_header_2.h"

int main() {
	setlocale(LC_ALL, "rus");
	string str;
	input_string(str);
	int choice = 1;
	while (choice != 0) {
		cout << "Выберите номер задачи:\n1. Вывести строку\n2. Вывести слова\n3. " <<
			"Вывести подстроку\n4. Удалить подстроку\n5. Удалить повторяющиеся слова\n6. Сформировать массив чисел\n0. Выйти из программы\nВаш выбор: "; cin >> choice;
		switch (choice) {
		case(1):
			output_string(str);
			break;
		case(2):
			output_words(str);
			break;
		case(3):
			output_substr(str);
			break;
		case(4):
			cin.ignore();
			int start, length;
			cout << "Введите индекс начала удаляемой подстроки: "; cin >> start;
			cout << "Введите длину удаляемой подстроки: "; cin >> length;
			remove_substr(str, start,length);
		case(5):
			delete_same_words(str);
			break;
		case(6):
			get_num_arr(str);
			break;
		case(0):
			cout << "Выход из программы!" << endl;
		}
	}
}