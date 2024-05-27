#include "5_header_2.h"

void input_string(string& str) {
	cout << "Введите вашу строку: ";
	getline(cin, str);
}

void output_string(const string& str) {
	cout << "Ваша строка: " << str << endl;
}

void output_words(string& str) {
	string copy_str = str;
	char* token = strtok(const_cast<char*>(copy_str.c_str()), " ,");
	while (token != NULL) {
		cout << token << endl;
		token = strtok(NULL, " ,");
	}
}

vector<string> words_vector(string& str) {
	string copy_str = str;
	vector<string> words;
	char* token = strtok(const_cast<char*>(copy_str.c_str()), " ,");
	while (token != NULL) {
		words.push_back(token);
		token = strtok(NULL, " ,");
	}
	return words;
}

void output_substr(const string& str) {
	int start;
	cout << "Введите индекс первого символа подстроки: ";
	cin >> start;
	cin.ignore(256, '\n');
	int length;
	cout << "Введите длину нужной подстроки: ";
	cin >> length;
	cin.ignore(256, '\n');
	cout << str.substr(start, length) << endl;
}

void remove_substr(string& str, int start, int length) {
	str.erase(start, length);
}

void delete_same_words(string& str) {
	vector<string> words = words_vector(str);
	for (int i = 0; i < words.size(); i++) {
		int count = count_word(str, words[i]);
		while (count > 1) {
			remove_word(str, words[i]);
			count--;
		}
	}
}

void remove_word(string& str, string& word) {
	stringstream ss(str);
	string token;
	string result;
	bool deleted = false;

	while (getline(ss, token, ' ')) {
		if (!deleted && token == word) {
			deleted = true;
		}
		else {
			if (!result.empty()) {
				result += " ";
			}
			result += token;
		}
	}

	str = result;
}

int count_word(string& str, string& word) {
	vector<string> words = words_vector(str);
	int word_count = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == word) word_count++;
	}
	return word_count;
}

void get_num_arr(string& str) {
	vector<int> nums;
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str[i])) nums.push_back(str[i] - 48);
	}
	cout << "Ваш массив: ";
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}