#include "5pr_header_1.h"

void input_string(str_nt* str) {
	cout << "������� ���� ������: ";
	cin.getline(str->sentence, sizeof(str->sentence));
}

void output_string(str_nt* str) {
	cout << "���� ������: ";
	printf("%s", str->sentence);
	cout << endl;
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
	cout << "������� ������ ������� ������� ���������: ";
	cin >> start;
	cin.ignore();
	int length;
	cout << "������� ����� ������ ���������: ";
	cin >> length;
	cin.ignore();
	char substring[100];
	memcpy(substring, str->sentence + start - 1, length);
	cout << "���������� ���������: " << substring << endl;
}

void remove_word(str_nt* str, char rem[100]) {
	char* substr = strstr(str->sentence, rem);
	if (substr != NULL) {
		char* ost = substr + strlen(rem);
		strcpy(substr, ost);
	}
	cout << "���������� ������: " << str->sentence << endl;
}