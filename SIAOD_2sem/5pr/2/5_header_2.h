#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#pragma warning(disable : 4996)

using namespace std;

void input_string(string& str);
void output_string(const string& str);
void output_words(string& str);
vector<string> words_vector(string& str);
void output_substr(const string& str);
void remove_substr(string& str, int start, int length);
void remove_word(string& str, string& word);
void delete_same_words(string& str);
int count_word(string& str, string& word);
void get_num_arr(string& str);