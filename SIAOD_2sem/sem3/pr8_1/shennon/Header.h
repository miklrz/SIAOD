#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

// ��������� ��� �������� ���������� � ��������
struct Symbol {
    char character;
    int frequency;
    string code;
};

// ��������� ��� ���������� �������� �� �������
bool compare(Symbol a, Symbol b) {
    return a.frequency > b.frequency;
}

// ������� ��� ���������� ����� �������-����
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

// ������� ��� ������ ������
void compress(const string& input, const string& output) {
    // ������� ������� ��������
    map<char, int> freq;
    for (char ch : input) {
        freq[ch]++;
    }

    vector<Symbol> symbols;
    for (const auto& entry : freq) {
        symbols.push_back(Symbol{ entry.first, entry.second, "" });
    }

    // ��������� ������� �� �������
    sort(symbols.begin(), symbols.end(), compare);

    // ������ ���� �������-����
    vector<Symbol> codes;
    buildShannonFanoCodes(symbols, codes);

    // ������� ������� ����� ��� ��������
    map<char, string> codeTable;
    for (const auto& symbol : codes) {
        codeTable[symbol.character] = symbol.code;
    }

    // ������� �����
    string compressedText = "";
    for (char ch : input) {
        compressedText += codeTable[ch];
    }

    // ������ ������� ������ � ����
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

// ������� ��� �������������� ������
string decompress(const string& input) {
    ifstream inFile(input, ios::binary);
    string compressedText = "";
    char byte;
    while (inFile.get(byte)) {
        bitset<8> bits(byte);
        compressedText += bits.to_string();
    }

    inFile.close();

    // �������������� ������������ �����
    return compressedText;
}

// ������� ��� ���������� �������� ������
double calculateCompressionRatio(const string& originalText, const string& compressedFile) {
    // ��������� ������ ��������� ������ � �����
    int originalSize = originalText.size() * 8; // ������ ������ - 1 ����, �.�. 8 ���

    // ������ ������ �����
    ifstream inFile(compressedFile, ios::binary | ios::ate);
    int compressedSize = inFile.tellg() * 8; // ��������� ������ ���� ��� 8 ���
    inFile.close();

    // ��������� ������� ������
    double compressionRatio = ((double)(originalSize - compressedSize) / originalSize) * 100;
    return compressionRatio;
}
