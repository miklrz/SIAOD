#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    string inputText = "Эне-бене, рики-таки, Буль-буль-буль, Караки-шмаки Эус-деус-краснодеус бац";
    string compressedFile = "compressed.txt";
    string decompressedFile = "decompressed.txt";

    // Сжимаем текст
    compress(inputText, compressedFile);

    // Восстанавливаем текст
    string decompressedText = decompress(compressedFile);

    // Выводим восстановленный текст
    cout << "Original Text: " << inputText << endl;
    cout << "Decompressed Text: " << decompressedText << endl;

    // Расчитываем процент сжатия
    double compressionRatio = calculateCompressionRatio(inputText, compressedFile);
    cout << "Compression Ratio: " << compressionRatio << "%" << endl;

    return 0;
}  