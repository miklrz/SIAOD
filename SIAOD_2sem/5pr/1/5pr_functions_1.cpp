#include "5pr_header_1.h"

void input_string(str_nt* str) {
	cout << "Введите вашу строку: ";
	cin.getline(str->sentence, sizeof(str->sentence));
}

void output_string(str_nt* str) {
	cout << "Ваша строка: ";
	printf("%s", str->sentence);
	cout << endl;
}

bool remove_words(str_nt* str) {
	char** arr = new char* [10];
	char* copy_str = new char[strlen(str->sentence) + 1];
	strcpy(copy_str, str->sentence);
	char* token = strtok(copy_str, " ,");
	int _ = 0;
	while (token != NULL) {
		bool flag = false;
		for (int i = 0; i < _; i++) {
			if (strcmp(arr[i], token) == 0) {
				remove_word(token, sizeof(token))
			}
		}
		strcpy(arr[_++], token);
		token = strtok(NULL, " ,");
	}
	delete[] copy_str;
}

void allocation_token(str_nt* str) {
	char* copy_str = new char[strlen(str->sentence) + 1];
	strcpy(copy_str, str->sentence);
	char* token = strtok(copy_str, " ,");
	while (token != NULL) {
		cout << token << endl;
		token = strtok(NULL, " ,");
	}
	delete[] copy_str;
}

void allocation_word(str_nt* str) {
	int start;
	cout << "Введите индекс первого символа подстроки: ";
	cin >> start;
	cin.ignore();
	int length;
	cout << "Введите длину нужной подстроки: ";
	cin >> length;
	cin.ignore();
	char substring[100];
	memcpy(substring, str->sentence + start - 1, length);
	cout << "Выделенная подстрока: " << substring << endl;
}

void remove_word(char* str, char rem[100]) {
	char* substr = strstr(str, rem);
	if (substr != NULL) {
		char* ost = substr + strlen(rem);
		strcpy(substr, ost);
	}
	cout << "Измененная строка: " << str << endl;
}
