#include "5pr_header_1.h"

void input_string(char* str) {
	cout << "Введите вашу строку: ";
	cin.getline(str, 100);
}

void output_string(char* str) {
	cout << "Ваша строка: " << str << endl;
}

void output_words(char* str) {
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	char* token = strtok(copy_str, " ,");
	cout << token << endl;
	while (token = strtok(NULL, " ,")) {
		cout << token << endl;
	}
	delete[] copy_str;
}

void output_substr(char* str) {
	int start;
	cout << "Введите индекс первого символа подстроки: ";
	cin >> start;
	cin.ignore(256, '\n');
	int length;
	cout << "Введите длину нужной подстроки: ";
	cin >> length;
	cin.ignore(256, '\n');
	char substring[100];
	memcpy(substring, str + start, length);
	cout << "Выделенная подстрока: " << substring << endl;
}

void remove_substr(char* str, char* substr) {
	int len = strlen(str);
	int len_substr = strlen(substr);
	char* p = strstr(str, substr);
	if (p != NULL) {
		while (*p != '\0') {
			*p = *(p + len_substr);
			p++;
		}
		*p = '\0';
	}
}

int new_arr(char* str) {

}

int count_words(char* str) {
	int count = 1;
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	char* token = strtok(copy_str, ", ");
	while (token = strtok(NULL, ", ")) {
		count++;
	}
	return count;
}

char** words_arr(char* str) {
	char** arr = new char* [strlen(str + 1)];
	int index = 0;
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	char* token = strtok(copy_str, ", ");
	arr[index] = token;
	index++;
	while (token = strtok(NULL, ", ")) {
		arr[index] = token;
		index++;
	}
	return arr;
}

int count_word(char* str, char* word) {
	char** arr = words_arr(str);
	int words_count = count_words(str);
	int word_count = 0;
	for (int i = 0; i < words_count; i++) {
		if (strcmp(arr[i], word) == 0) {
			word_count++;
		}
	}
	return word_count;
}

void delete_word(char* str, char* word) {
	char** arr = words_arr(str);
	int words_count = count_words(str);
	for (int i = 0; i < words_count; i++) {

	}
}