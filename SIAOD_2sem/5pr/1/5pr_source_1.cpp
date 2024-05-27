#include "5pr_header_1.h"


int main() {
	setlocale(LC_ALL, "rus");
	
	char* str = new char[100];
	input_string(str);
	//output_string(str);
	//char* sub_str = new char[100];
	//input_string(sub_str);
	//output_string(sub_str);
	//delete_word(str, sub_str);
	delete_same_words(str);
	output_string(str);
}