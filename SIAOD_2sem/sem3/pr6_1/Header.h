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

    // Первичная хеш-функция
    int hash1(int key) const {
        return key % capacity;
    }

    // Вторичная хеш-функция
    int hash2(int key) const {
        return 1 + (key % (capacity - 1));
    }

    // Расширение таблицы и рехеширование
    void rehash() {
        vector<Student> oldTable = table;
        capacity *= 2;  // Увеличиваем размер таблицы
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

    // Вставка студента в таблицу
    void insert(const Student& student) {
        if (size >= (capacity *3)/4 ){
            rehash();  // Расширение таблицы при превышении половины емкости
        }

        int index = hash1(student.id);
        int step = hash2(student.id);

        while (table[index].id != -1) {
            index = (index + step) % capacity;  // Двойное хеширование
        }

        table[index] = student;
        size++;
    }

    // Поиск студента по номеру зачетной книжки
    Student search(int id) const {
        int index = hash1(id);
        int step = hash2(id);

        while (table[index].id != -1) {
            if (table[index].id == id) {
                return table[index];
            }
            index = (index + step) % capacity;
        }

        return Student();  // Возвращаем пустого студента, если не найден
    }

    // Удаление студента по номеру зачетной книжки
    void remove(int id) {
        int index = hash1(id);
        int step = hash2(id);

        while (table[index].id != -1) {
            if (table[index].id == id) {
                table[index] = Student();  // Удаляем студента
                size--;
                return;
            }
            index = (index + step) % capacity;
        }

        cout << "Студент не найден!" << endl;
    }

    // Вывод содержимого таблицы
    void display() const {
        for (int i = 0; i < capacity; i++) {
            if (table[i].id != -1) {
                cout << "Индекс " << i << ": "
                    << "Номер зачетной книжки: " << table[i].id
                    << ", Номер группы: " << table[i].groupNumber
                    << ", ФИО: " << table[i].name << endl;
            }
        }
    }
};