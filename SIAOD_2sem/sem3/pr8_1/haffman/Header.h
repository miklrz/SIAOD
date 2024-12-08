#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>

using namespace std;

// Структура для хранения данных символов в дереве
struct Node {
    char character;
    int frequency;
    Node* left;
    Node* right;

    Node(char c, int freq) : character(c), frequency(freq), left(nullptr), right(nullptr) {}

    // Для приоритетной очереди (сортировка по частоте)
    bool operator>(const Node& other) const {
        return frequency > other.frequency;
    }
};

// Рекурсивная функция для генерации кодов
void generateCodes(Node* root, const string& code, map<char, string>& codes) {
    if (!root) return;

    // Если это лист (символ)
    if (!root->left && !root->right) {
        codes[root->character] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Кодирование
string encode(const string& text, map<char, string>& codes) {
    string encodedText = "";
    for (char c : text) {
        encodedText += codes[c];
    }
    return encodedText;
}

// Декодирование
string decode(const string& encodedText, Node* root) {
    string decodedText = "";
    Node* current = root;

    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        }
        else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedText += current->character;
            current = root;
        }
    }

    return decodedText;
}