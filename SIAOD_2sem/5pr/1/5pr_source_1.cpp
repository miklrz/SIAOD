#include "5pr_header_1.h"


int main() {
	setlocale(LC_ALL, "rus");
	char* str = new char[100];
	char* sub_str = new char[100];
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
			input_string(sub_str);
			remove_substr(str, sub_str);
		case(5):
			delete_same_words(str);
			break;
		case(6):
			create_num_arr(str);
			break;
		case(0):
			cout << "Выход из программы!" << endl;
		}
	}

}