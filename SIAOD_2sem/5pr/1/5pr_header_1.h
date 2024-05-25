#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

void input_string(char* str);
void output_string(char* str);
void output_words(char* str);
void output_substr(char* str);
void remove_substr(char* str, char* substr);
int count_word(char* str, char* substr);