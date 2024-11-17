#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// ������������ ������ �����
enum Color { RED, BLACK };

// ���� ������
struct Node {
    char data;
    Color color;
    Node* left, * right, * parent;

    Node(char data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// ����� ������-������� ������
class RBTree {
private:
    Node* root;

    // ����� �������
    void rotateLeft(Node*& node);

    // ������ �������
    void rotateRight(Node*& node);

    // ������������ ����� �������
    void balanceInsert(Node*& node);

    // ����������� ������������ �����
    void inorderTraversal(Node* node, vector<char>& result) const;

    // ����������� ����� ����� ����
    int findPathLength(Node* node, char value, int length) const;

    // ����������� ���������� ����� � ���������� �����
    void calculateSumAndCount(Node* node, int& sum, int& count) const;

public:
    RBTree() : root(nullptr) {}

    // ������� ����
    void insert(char data);

    // ������������ �����
    vector<char> inorder() const;

    // ����� ����� ���� �� ����� �� ����
    int getPathLength(char value) const;

    // ����� ������� �������������� ���� �����
    double getAverage() const;
};