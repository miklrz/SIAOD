#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id; 
    int groupNumber;
    string name;

    Student() : id(-1), groupNumber(-1), name("") {}
    Student(int _id, int _groupNumber, const string& _name)
        : id(_id), groupNumber(_groupNumber), name(_name) {}
};

class HashTable {
private:
    vector<Student> table;
    int capacity;
    int size;

    // ��������� ���-�������
    int hash1(int key) const {
        return key % capacity;
    }

    // ��������� ���-�������
    int hash2(int key) const {
        return 1 + (key % (capacity - 1));
    }

    // ���������� ������� � �������������
    void rehash() {
        vector<Student> oldTable = table;
        capacity *= 2;  // ����������� ������ �������
        table = vector<Student>(capacity);
        size = 0;

        for (const auto& student : oldTable) {
            if (student.id != -1) {
                insert(student);
            }
        }
    }

public:
    HashTable(int _capacity = 7) : capacity(_capacity), size(0) {
        table.resize(capacity);
    }

    // ������� �������� � �������
    void insert(const Student& student) {
        if (size >= (capacity *3)/4 ){
            rehash();  // ���������� ������� ��� ���������� �������� �������
        }

        int index = hash1(student.id);
        int step = hash2(student.id);

        while (table[index].id != -1) {
            index = (index + step) % capacity;  // ������� �����������
        }

        table[index] = student;
        size++;
    }

    // ����� �������� �� ������ �������� ������
    Student search(int id) const {
        int index = hash1(id);
        int step = hash2(id);

        while (table[index].id != -1) {
            if (table[index].id == id) {
                return table[index];
            }
            index = (index + step) % capacity;
        }

        return Student();  // ���������� ������� ��������, ���� �� ������
    }

    // �������� �������� �� ������ �������� ������
    void remove(int id) {
        int index = hash1(id);
        int step = hash2(id);

        while (table[index].id != -1) {
            if (table[index].id == id) {
                table[index] = Student();  // ������� ��������
                size--;
                return;
            }
            index = (index + step) % capacity;
        }

        cout << "������� �� ������!" << endl;
    }

    // ����� ����������� �������
    void display() const {
        for (int i = 0; i < capacity; i++) {
            if (table[i].id != -1) {
                cout << "������ " << i << ": "
                    << "����� �������� ������: " << table[i].id
                    << ", ����� ������: " << table[i].groupNumber
                    << ", ���: " << table[i].name << endl;
            }
        }
    }
};