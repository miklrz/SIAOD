#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    string text = "Аржанов Михаил Андреевич";

    // Подсчет частоты символов
    map<char, int> frequencyMap;
    for (char c : text) {
        frequencyMap[c]++;
    }

    // Создание приоритетной очереди для Хаффмана
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (const auto& entry : frequencyMap) {
        pq.push(Node(entry.first, entry.second));
    }

    // Построение дерева Хаффмана
    while (pq.size() > 1) {
        Node* left = new Node(pq.top()); pq.pop();
        Node* right = new Node(pq.top()); pq.pop();

        Node* merged = new Node('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(*merged);
    }

    // Корень дерева
    Node* root = new Node(pq.top()); pq.pop();

    // Генерация кодов
    map<char, string> codes;
    generateCodes(root, "", codes);

    // Кодирование
    string encodedText = encode(text, codes);
    cout << "Закодированное сообщение (Хаффман): " << encodedText << endl;

    // Декодирование
    string decodedText = decode(encodedText, root);
    cout << "Декодированное сообщение (Хаффман): " << decodedText << endl;

    return 0;
}
