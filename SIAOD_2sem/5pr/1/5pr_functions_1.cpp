#include <iostream>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

struct str_nt {
	char sentence[100];
};

void input_string(str_nt* str) {
	cout << "������� ���� ������: ";
	cin.getline(str->sentence, sizeof(str->sentence));
}

void output_string(str_nt* str) {
	cout << "���� ������: ";
	printf("%s", str->sentence);
	cout << endl;
}

void allocation_token