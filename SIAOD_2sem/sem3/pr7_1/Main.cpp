#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");

    RBTree tree;
    int choice;
    char value;

    do {
        cout << "����:\n";
        cout << "1. ������� ��������\n";
        cout << "2. ������������ �����\n";
        cout << "3. ����� ������� ��������������\n";
        cout << "4. ����� ����� ���� �� ����\n";
        cout << "0. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ������ ��� �������: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2: {
            vector<char> result = tree.inorder();
            cout << "������������ �����: ";
            for (char ch : result) cout << ch << ' ';
            cout << endl;
            break;
        }
        case 3:
            cout << "������� ��������������: " << tree.getAverage() << endl;
            break;
        case 4:
            cout << "������� ������ ��� ������ ����: ";
            cin >> value;
            cout << "����� ����: " << tree.getPathLength(value) << endl;
            break;
        case 0:
            cout << "�����.\n";
            break;
        default:
            cout << "������������ �����!\n";
        }
    } while (choice != 0);

    return 0;
}