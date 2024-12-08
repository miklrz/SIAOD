#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

// Структура для хранения информации о символах
struct Symbol {
    char character;
    int frequency;
    string code;
};

// Сравнение для сортировки символов по частоте
bool compare(Symbol a, Symbol b) {
    return a.frequency > b.frequency;
}

// Функция для построения кодов Шеннона-Фано
void buildShannonFanoCodes(const vector<Symbol>& symbols, vector<Symbol>& codes, string code = "") {
    if (symbols.size() == 1) {
        codes.push_back(Symbol{ symbols[0].character, symbols[0].frequency, code });
        return;
    }

    int mid = symbols.size() / 2;
    int sumLeft = 0, sumRight = 0;

    for (int i = 0; i < mid; ++i) {
        sumLeft += symbols[i].frequency;
    }
    for (int i = mid; i < symbols.size(); ++i) {
        sumRight += symbols[i].frequency;
    }

    vector<Symbol> left(symbols.begin(), symbols.begin() + mid);
    vector<Symbol> right(symbols.begin() + mid, symbols.end());

    buildShannonFanoCodes(left, codes, code + "0");
    buildShannonFanoCodes(right, codes, code + "1");
}

// Функция для сжатия текста
void compress(const string& input, const string& output) {
    // Подсчет частоты символов
    map<char, int> freq;
    for (char ch : input) {
        freq[ch]++;
    }

    vector<Symbol> symbols;
    for (const auto& entry : freq) {
        symbols.push_back(Symbol{ entry.first, entry.second, "" });
    }

    // Сортируем символы по частоте
    sort(symbols.begin(), symbols.end(), compare);

    // Строим коды Шеннона-Фано
    vector<Symbol> codes;
    buildShannonFanoCodes(symbols, codes);

    // Создаем таблицу кодов для символов
    map<char, string> codeTable;
    for (const auto& symbol : codes) {
        codeTable[symbol.character] = symbol.code;
    }

    // Сжимаем текст
    string compressedText = "";
    for (char ch : input) {
        compressedText += codeTable[ch];
    }

    // Запись сжатого текста в файл
    ofstream outFile(output, ios::binary);
    bitset<8> bits;
    for (size_t i = 0; i < compressedText.size(); i++) {
        bits[i % 8] = compressedText[i] == '1' ? 1 : 0;
        if (i % 8 == 7 || i == compressedText.size() - 1) {
            outFile.put(bits.to_ulong());
            bits.reset();
        }
    }

    outFile.close();
}

// Функция для восстановления текста
string decompress(const string& input) {
    ifstream inFile(input, ios::binary);
    string compressedText = "";
    char byte;
    while (inFile.get(byte)) {
        bitset<8> bits(byte);
        compressedText += bits.to_string();
    }

    inFile.close();

    // Реконструируем оригинальный текст
    return compressedText;
}

// Функция для вычисления процента сжатия
double calculateCompressionRatio(const string& originalText, const string& compressedFile) {
    // Вычисляем размер исходного текста в битах
    int originalSize = originalText.size() * 8; // каждый символ - 1 байт, т.е. 8 бит

    // Читаем сжатый текст
    ifstream inFile(compressedFile, ios::binary | ios::ate);
    int compressedSize = inFile.tellg() * 8; // учитываем каждый байт как 8 бит
    inFile.close();

    // Вычисляем процент сжатия
    double compressionRatio = ((double)(originalSize - compressedSize) / originalSize) * 100;
    return compressionRatio;
}
