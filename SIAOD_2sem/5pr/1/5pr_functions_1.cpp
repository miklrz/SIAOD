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

void allocation_token(str_nt* str) {
	char* copy_str = new char[strlen(str->sentence) + 1];
	strcpy(copy_str, str->sentence);
	char* token = strtok(copy_str, " ,");
	cout << token << endl;
	while (token = strtok(NULL," ,")) {
		cout << token << endl;
	}
	delete[] copy_str;
}

void allocation_word(str_nt* str) {
	int start;
	cout << "Введите индекс первого символа подстроки: ";
	cin >> start;
	cin.ignore(256, '\n');
	int length;
	cout << "Введите длину нужной подстроки: ";
	cin >> length;
	cin.ignore(256, '\n');
	char substring[100];
	memcpy(substring, str->sentence + start, length);
	cout << "Выделенная подстрока: " << substring << endl;
}

void remove_word(str_nt* str, char rem[100]) {
	char* substr = strstr(str->sentence, rem);
	if (substr != NULL) {
		char* ost = substr + strlen(rem);
		strcpy(substr, ost);
		cout << 1;
	}
	cout << "Измененная строка: " << str->sentence<< endl;
}

char** words_arr(str_nt* str) {
	char** arr = new char*[strlen(str->sentence + 1)];
	int index = 0;
	char* copy_str = new char[strlen(str->sentence) + 1];
	strcpy(copy_str, str->sentence);
	char* token = strtok(copy_str, ", ");
	arr[index] = token;
	index++;
	while (token = strtok(NULL, ", ")) {
		arr[index] = token;
		index++;
	}
	return arr;
}

bool unique_word(char** words_arr, char* word) {
	for (int i = 0; words_arr[i] != NULL; i++) {
		if (strcmp(words_arr[i], word) == 0) {
			return false;
		}
	}
	return true;
}

void delete_words(str_nt* str, char** arr) {

}