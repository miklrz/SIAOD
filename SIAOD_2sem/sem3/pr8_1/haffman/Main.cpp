#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");
    string text = "������� ������ ���������";

    // ������� ������� ��������
    map<char, int> frequencyMap;
    for (char c : text) {
        frequencyMap[c]++;
    }

    // �������� ������������ ������� ��� ��������
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (const auto& entry : frequencyMap) {
        pq.push(Node(entry.first, entry.second));
    }

    // ���������� ������ ��������
    while (pq.size() > 1) {
        Node* left = new Node(pq.top()); pq.pop();
        Node* right = new Node(pq.top()); pq.pop();

        Node* merged = new Node('\0', left->frequency + right->frequency);
        merged->left = left;
        merged->right = right;

        pq.push(*merged);
    }

    // ������ ������
    Node* root = new Node(pq.top()); pq.pop();

    // ��������� �����
    map<char, string> codes;
    generateCodes(root, "", codes);

    // �����������
    string encodedText = encode(text, codes);
    cout << "�������������� ��������� (�������): " << encodedText << endl;

    // �������������
    string decodedText = decode(encodedText, root);
    cout << "�������������� ��������� (�������): " << decodedText << endl;

    return 0;
}
