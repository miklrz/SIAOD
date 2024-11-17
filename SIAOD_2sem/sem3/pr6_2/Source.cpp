#include "Header.h"

// Функция для проверки, совпадают ли первая и последняя буквы
bool isValidWord(const std::string& word) {
    if (word.empty()) return false;
    char first = tolower(word.front());
    char last = tolower(word.back());
    return first == last;
}

// Функция для поиска самого длинного слова
std::string findLongestWord(const std::string& sentence) {
    std::istringstream stream(sentence);
    std::string word, longestWord;
    while (stream >> word) {
        // Убираем знаки пунктуации с конца
        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }
        if (isValidWord(word) && word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    return longestWord;
}

// Построение префикс-функции
std::vector<int> computePrefixFunction(const std::string& pattern) {
    int n = pattern.size();
    std::vector<int> prefix(n, 0);
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            ++j;
        }
        prefix[i] = j;
    }
    return prefix;
}

// Функция для поиска последнего вхождения
int findLastOccurrence(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return -1;

    std::vector<int> prefix = computePrefixFunction(pattern);
    int j = 0;
    int lastIndex = -1;

    for (int i = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == pattern.size()) {
            lastIndex = i - j + 1;
            j = prefix[j - 1];
        }
    }

    return lastIndex;
}