#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");

    HashTable ht;

    // Автоматическая вставка нескольких записей
    ht.insert(Student(12345, 101, "Ivanov Ivan Ivanovich"));
    ht.insert(Student(12346, 102, "Petrov Petr Petrovich"));
    ht.insert(Student(12347, 103, "Sidorov Sidor Sidorovich"));
    ht.insert(Student(12348, 104, "Kuznetsova Anna Pavlovna"));
    ht.insert(Student(12349, 105, "Smirnova Maria Ivanovna"));

    cout << "Начальный массив:\n";
    ht.display();

    int chose = 1;
    while (chose != 9) {
        cout << "1. Вставить новые данные\n2. Поиск по ключу\n3. Удаление\n4. Вывод\n9. Выход из программы\nВаш выбор: ";
        cin >> chose;
        switch (chose) {
        case(1): {
            cout << "Введите номер зачетной книжки: "; int id; cin >> id;
            cout << "Введите номер группы: "; int groupId; cin >> groupId;
            cout << "Введите ФИО: "; string name; cin >> name;
            ht.insert(Student(id, groupId, name));
            break;
        }

        case(2): {
            cout << "Введите номер зачетной книжки: "; int searchId; cin >> searchId;
            Student found = ht.search(searchId);
            if (found.id != -1) {
                cout << "\nНайден студент с номером зачетной книжки " << searchId << ": " << found.name << endl;
            }
            else {
                cout << "\nСтудент с номером зачетной книжки " << searchId << " не найден!" << endl;
            }
            break;
        }

        case(3): {
            cout << "Введите номер зачетной книжки: "; int id; cin >> id;
            cout << "\nУдаление студента с номером зачетной книжки " << id << "...\n";
            ht.remove(id);
            break;
        }

        case(4): {
            cout << "\nМассив:\n";
            ht.display();
            break;
        }

        case(9): {
            cout << "Выход из программы..." << endl;
            break;
        }
        }
    }

    return 0;
}