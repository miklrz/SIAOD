#include "5pr_header_1.h"


int main() {
	setlocale(LC_ALL, "rus");
	
	char* str = new char[100];
	char* substr = new char[100];
	input_string(str);
	input_string(substr);
	cout << count_word(str, substr);
}