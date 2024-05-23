#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

struct str_nt {
	char sentence[100];
};

void input_string(str_nt* str);
void output_string(str_nt* str);
void allocation_token(str_nt* str);
void allocation_token(str_nt* str);
void allocation_word(str_nt* str);
void remove_word(str_nt* str, char rem[100]);