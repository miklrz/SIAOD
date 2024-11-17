#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");

    RBTree tree;
    int choice;
    char value;

    do {
        cout << "Меню:\n";
        cout << "1. Вставка элемента\n";
        cout << "2. Симметричный обход\n";
        cout << "3. Найти среднее арифметическое\n";
        cout << "4. Найти длину пути до узла\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите символ для вставки: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2: {
            vector<char> result = tree.inorder();
            cout << "Симметричный обход: ";
            for (char ch : result) cout << ch << ' ';
            cout << endl;
            break;
        }
        case 3:
            cout << "Среднее арифметическое: " << tree.getAverage() << endl;
            break;
        case 4:
            cout << "Введите символ для поиска пути: ";
            cin >> value;
            cout << "Длина пути: " << tree.getPathLength(value) << endl;
            break;
        case 0:
            cout << "Выход.\n";
            break;
        default:
            cout << "Некорректный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}