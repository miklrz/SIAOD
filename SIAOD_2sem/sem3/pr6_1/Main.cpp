#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");

    HashTable ht;

    // �������������� ������� ���������� �������
    ht.insert(Student(12345, 101, "Ivanov Ivan Ivanovich"));
    ht.insert(Student(12346, 102, "Petrov Petr Petrovich"));
    ht.insert(Student(12347, 103, "Sidorov Sidor Sidorovich"));
    ht.insert(Student(12348, 104, "Kuznetsova Anna Pavlovna"));
    ht.insert(Student(12349, 105, "Smirnova Maria Ivanovna"));

    cout << "��������� ������:\n";
    ht.display();

    int chose = 1;
    while (chose != 9) {
        cout << "1. �������� ����� ������\n2. ����� �� �����\n3. ��������\n4. �����\n9. ����� �� ���������\n��� �����: ";
        cin >> chose;
        switch (chose) {
        case(1): {
            cout << "������� ����� �������� ������: "; int id; cin >> id;
            cout << "������� ����� ������: "; int groupId; cin >> groupId;
            cout << "������� ���: "; string name; cin >> name;
            ht.insert(Student(id, groupId, name));
            break;
        }

        case(2): {
            cout << "������� ����� �������� ������: "; int searchId; cin >> searchId;
            Student found = ht.search(searchId);
            if (found.id != -1) {
                cout << "\n������ ������� � ������� �������� ������ " << searchId << ": " << found.name << endl;
            }
            else {
                cout << "\n������� � ������� �������� ������ " << searchId << " �� ������!" << endl;
            }
            break;
        }

        case(3): {
            cout << "������� ����� �������� ������: "; int id; cin >> id;
            cout << "\n�������� �������� � ������� �������� ������ " << id << "...\n";
            ht.remove(id);
            break;
        }

        case(4): {
            cout << "\n������:\n";
            ht.display();
            break;
        }

        case(9): {
            cout << "����� �� ���������..." << endl;
            break;
        }
        }
    }

    return 0;
}