#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    string inputText = "���-����, ����-����, ����-����-����, ������-����� ���-����-���������� ���";
    string compressedFile = "compressed.txt";
    string decompressedFile = "decompressed.txt";

    // ������� �����
    compress(inputText, compressedFile);

    // ��������������� �����
    string decompressedText = decompress(compressedFile);

    // ������� ��������������� �����
    cout << "Original Text: " << inputText << endl;
    cout << "Decompressed Text: " << decompressedText << endl;

    // ����������� ������� ������
    double compressionRatio = calculateCompressionRatio(inputText, compressedFile);
    cout << "Compression Ratio: " << compressionRatio << "%" << endl;

    return 0;
}  