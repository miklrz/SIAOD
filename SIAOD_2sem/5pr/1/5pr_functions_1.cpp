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
	char* substring = new char[length + 1];
	memcpy(substring, str + start, length);
	substring[length] = '\0';
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

void remove_word(char* str, char* word) {
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);

	bool deleted = false;

	char* result = new char[strlen(str) + 1];
	result[0] = '\0';

	char* token = strtok(copy_str, " ,");
	bool first = true;
	while (token != NULL) {
		if (!deleted && strcmp(token, word) == 0) {
			deleted = true;
		}
		else {
			if (!first) {
				strcat(result, " ");
			}
			strcat(result, token);
			first = false;
		}
		token = strtok(NULL, " ,");
	}

	strcpy(str, result);
	delete[] copy_str;
	delete[] result;
}


int count_words(char* str) {
	int count = 1;
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	char* token = strtok(copy_str, ", ");
	while (token = strtok(NULL, ", ")) {
		count++;
	}
	delete[] copy_str;
	return count;
}

char** words_arr(char* str) {
	char** arr = new char* [strlen(str) + 1];
	int index = 0;
	char* copy_str = new char[strlen(str) + 1];
	strcpy(copy_str, str);
	char* token = strtok(copy_str, " ,");
	while (token != NULL) {
		arr[index] = new char[strlen(token) + 1];
		strcpy(arr[index], token);
		index++;
		token = strtok(NULL, " ,");
	}
	delete[] copy_str;
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
	delete[] arr;
	return word_count;
}

void delete_same_words(char* str) {
	char** arr = words_arr(str);
	int words_count = count_words(str);
	for (int i = 0; i < words_count; i++) {
		int word_count = count_word(str, arr[i]);
		while (word_count > 1) {
			remove_word(str, arr[i]);
			word_count--;
		}
	}
}

void create_num_arr(char* str) {
	int arr[100]{};
	int _ = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i])) {
			arr[_] = str[i];
			_++;
		}
	}
	cout << "Массив чисел: ";
	for (int i = 0; i < _; i++) {
		cout << arr[i] - 48 << " ";
	}
	cout << endl;
}