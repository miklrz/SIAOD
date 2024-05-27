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
char** words_arr(char* str);
int count_words(char* str);
int count_word(char* str, char* word);
void remove_word(char* str, char* word);
void delete_same_words(char* str);