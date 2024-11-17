#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Перечисление цветов узлов
enum Color { RED, BLACK };

// Узел дерева
struct Node {
    char data;
    Color color;
    Node* left, * right, * parent;

    Node(char data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Класс красно-чёрного дерева
class RBTree {
private:
    Node* root;

    // Левый поворот
    void rotateLeft(Node*& node);

    // Правый поворот
    void rotateRight(Node*& node);

    // Балансировка после вставки
    void balanceInsert(Node*& node);

    // Рекурсивный симметричный обход
    void inorderTraversal(Node* node, vector<char>& result) const;

    // Рекурсивный поиск длины пути
    int findPathLength(Node* node, char value, int length) const;

    // Рекурсивное вычисление суммы и количества узлов
    void calculateSumAndCount(Node* node, int& sum, int& count) const;

public:
    RBTree() : root(nullptr) {}

    // Вставка узла
    void insert(char data);

    // Симметричный обход
    vector<char> inorder() const;

    // Найти длину пути от корня до узла
    int getPathLength(char value) const;

    // Найти среднее арифметическое всех узлов
    double getAverage() const;
};